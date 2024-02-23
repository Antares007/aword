#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_EVENT_NUMBER 1024 // event
#define BUFFER_SIZE 10        // Buffer Size

/*Set file descriptor to non-congested*/
int SetNonblocking(int fd) {
  int old_option = fcntl(fd, F_GETFL);
  int new_option = old_option | O_NONBLOCK;
  fcntl(fd, F_SETFL, new_option);
  return old_option;
}
/*Register EPOLLIN on file descriptor FD into the epoll kernel event table
  indicated by epoll_fd, and the parameter enable_et specifies whether et mode
  is enabled for FD*/
void AddFd(int epoll_fd, int fd) {
  struct epoll_event event;
  event.data.fd = fd;
  event.events = EPOLLIN | EPOLLET; // Registering the fd is readable

  epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd,
            &event); // Register the fd with the epoll kernel event table
  SetNonblocking(fd);
}
/*ET Work mode features: efficient but potentially dangerous*/
void et_process(struct epoll_event *events, int number, int epoll_fd,
                int listen_fd) {
  char buf[BUFFER_SIZE];
  int i;
  for (i = 0; i < number; i++) {
    int sockfd = events[i].data.fd;
    if (sockfd == listen_fd) {
      struct sockaddr_in client_address;
      socklen_t client_addrlength = sizeof(client_address);
      int connfd = accept(listen_fd, (struct sockaddr *)&client_address,
                          &client_addrlength);
      AddFd(epoll_fd, connfd);
    } else if (events[i].events & EPOLLIN) {
      /* This code will not be triggered repeatedly, so we cycle through the
       * data to make sure that all the data in the socket read cache is read
       * out.This is how we eliminate the potential dangers of the ET model */
      printf("et mode: event trigger once!\n");
      while (1) {
        memset(buf, 0, BUFFER_SIZE);
        int ret = recv(sockfd, buf, BUFFER_SIZE - 1, 0);
        if (ret < 0) {
          /* For non-congested IO, the following condition is true to indicate
           * that the data has been read completely, after which epoll can
           * trigger the EPOLLIN event on sockfd again to drive the next read
           * operation */
          if (errno == EAGAIN || errno == EWOULDBLOCK) {
            printf("read later!\n");
            break;
          }
          close(sockfd);
          break;
        } else if (ret == 0) {
          close(sockfd);
        } else // Not finished, continue reading in a loop
        {
          printf("get %d bytes of content: %s\n", ret, buf);
        }
      }
    } else {
      printf("something unexpected happened!\n");
    }
  }
}

int main() {
  const char *ip = "127.0.0.1";
  int port = 7000;
  int ret = -1;
  struct sockaddr_in address;
  // bzero(&address, sizeof(address));
  address.sin_family = AF_INET;
  inet_pton(AF_INET, ip, &address.sin_addr);
  address.sin_port = htons(port);

  int listen_fd = socket(PF_INET, SOCK_STREAM, 0);
  if (listen_fd < 0) return printf("fail to create socket!\n"), -1;

  ret = bind(listen_fd, (struct sockaddr *)&address, sizeof(address));
  if (ret == -1) return printf("fail to bind socket!\n"), -1;

  ret = listen(listen_fd, 5);
  if (ret == -1) return printf("fail to listen socket!\n"), -1;

  struct epoll_event events[MAX_EVENT_NUMBER];
  int epoll_fd = epoll_create(5); // Event table size 5
  if (epoll_fd == -1) return printf("fail to create epoll!\n"), -1;

  AddFd(epoll_fd, listen_fd);

  while (1) {
    int ret = epoll_wait(epoll_fd, events, MAX_EVENT_NUMBER, -1);
    if (ret < 0) {
      printf("epoll failure!\n");
      break;
    }
    et_process(events, ret, epoll_fd, listen_fd);
  }
  close(listen_fd);
  return 0;
}
