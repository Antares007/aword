#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_EVENTS 10
int setnonblocking(long fd) {
  // F_GETFL  Value of file status flags and access modes.
  //          The return value is not negative.
  int flags = fcntl(fd, F_GETFL, 0);
  if (flags < 0)
    return flags;
  flags |= O_NONBLOCK;
  // F_SETFL  Value other than -1.
  return fcntl(fd, F_SETFL, flags);
}

int main() {
  int epollfd;
  if ((epollfd = epoll_create1(0)) == -1)
    perror("epoll_create1"), exit(EXIT_FAILURE);

  struct epoll_event ev = {.events = EPOLLIN, .data.fd = STDIN_FILENO};
  if (setnonblocking(ev.data.fd) == -1)
    perror("cant set O_NONBLOCK"), exit(EXIT_FAILURE);

  if (epoll_ctl(epollfd, EPOLL_CTL_ADD, ev.data.fd, &ev) == -1)
    perror("epoll_ctl: listen_sock"), exit(EXIT_FAILURE);

  unsigned char buffer[65536];
  struct epoll_event events[MAX_EVENTS];
  for (int nfds;;)
    if ((nfds = epoll_wait(epollfd, events, MAX_EVENTS, 0)) == -1)
      perror("epoll_wait"), exit(EXIT_FAILURE);
    else
      for (long n = 0; n < nfds; ++n)
        for (long buflen;;)
          if ((buflen = read(events[n].data.fd, buffer, sizeof(buffer))) < 0)
            if (errno == EAGAIN || errno == EWOULDBLOCK)
              break;
            else
              perror("read"), exit(EXIT_FAILURE);
          else
            printf("%ld\n", buflen);
}
