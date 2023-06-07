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
/*

Where should we place the call to epoll_wait? How do we read data in a loop
until EAGAIN or in a pull call from the consumer stream?

The epoll_wait function checks if there is data to read and returns an answer.
If we don't read all of the data until EAGAIN, the epoll_wait function will
never tell us that there is still data to read. We can think of the epoll_wait
call as an interrupt handler for a device, such as a keyboard. In the interrupt
handler, we need to read all of the data from the device and store it in a
separate location for the consumer. If the data is flowing too quickly for us to
consume it, we need to apply backpressure to the device to slow down the data
transmission. If there is no more space to store the data, we may need to
discard it. For a keyboard, we can signal the user with a sound as backpressure,
telling them to "stop typing so fast."

To analyze our thinking, what is backpressure? In normal human-to-human
communication, we can identify moments when the listener may say "stop talking
too fast" or acknowledge with some reaction to request more data. Today, we need
to do something measurable and have a plan. Here are some tasks to consider:

Write a program to calculate mathematical expressions. The program should
consume input from stdin, parse expressions and calculate them incrementally.
Write a program that listens to stdin and parses text, then performs actions
accordingly. The goal is to make the program as efficient as possible.

   example:
    1+2*3<CR>
    7
    *7<CR>
    49
    -1<CR>
    48
   example:
    open window by 800x600. draw line from 0, 0 to 100, 100.
 */
