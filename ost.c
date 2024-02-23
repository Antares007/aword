#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <unistd.h>

int SetNonblocking(int fd) {
  int old_option = fcntl(fd, F_GETFL);
  int new_option = old_option | O_NONBLOCK;
  fcntl(fd, F_SETFL, new_option);
  return old_option;
}

int main(void) {
  char buffer[0x10000];
  int fd = epoll_create(5);

  struct epoll_event event;

  event.events = EPOLLIN | EPOLLET;
  event.data.fd = STDIN_FILENO;
  epoll_ctl(fd, EPOLL_CTL_ADD, STDIN_FILENO, &event);
  SetNonblocking(STDIN_FILENO);

  event.events = EPOLLOUT | EPOLLET;
  event.data.fd = STDOUT_FILENO;
  epoll_ctl(fd, EPOLL_CTL_ADD, STDOUT_FILENO, &event);
  SetNonblocking(STDOUT_FILENO);

  unsigned long c = 0;
  struct epoll_event events[10];
  for (;;) {
    // fprintf(stderr, "Going into epoll_wait\n");
    int num = epoll_wait(fd, events, 10, 0);
    if (num < 0) {
      printf("epoll failure!\n");
      break;
    }
    for (long i = 0; i < num; i++) {
      int fd = events[i].data.fd;
      if (fd == STDIN_FILENO)
        while (1) {
          long ret = read(0, buffer, sizeof(buffer));
          if (ret == 0) {
            printf("EOF\n");
            break;
          } else if (ret < 0) {
            if (errno == EAGAIN) {
              printf("EAGAIN\n");
              break;
            } else {
              printf("ERROR\n");
              exit(0);
            }
          } else {
            printf("%ld %ld\n", c, ret);
          }
        }
      else if (fd == STDOUT_FILENO)
        c++;
    }
  }
}
