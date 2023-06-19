#include <errno.h>
#include <fcntl.h>
#include <netinet/if_ether.h> // for ethernet header
#include <netinet/in.h>
#include <netinet/ip.h> // for ip header
#include <stdio.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_EVENTS 10
int setnonblocking(long fd) {
  // F_GETFL  Value of file status flags and access modes. The return value is not negative.
  int flags = fcntl(fd, F_GETFL, 0);
  if (flags < 0) return flags;
  flags |= O_NONBLOCK;
  // F_SETFL  Value other than -1.
  return fcntl(fd, F_SETFL, flags);
}

void data_process(unsigned char *buffer, int buflen);

#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <stdio.h>

//#include <linux/if_ether.h>
//#include <arpa/inet.h> // to avoid warning at inet_ntoa
//
//void print_ip_header(struct iphdr *ip) {
//  printf("IP Header\n");
//  printf("----------------------------\n");
//  printf("Version: %u\n", ip->version);
//  printf("Internet Header Length: %u bytes\n", ip->ihl * 4);
//  printf("Type of Service: %u\n", ip->tos);
//  printf("Total Length: %u bytes\n", ntohs(ip->tot_len));
//  printf("Identification: %u\n", ntohs(ip->id));
//  printf("Flags: 0x%02X\n", (ntohs(ip->frag_off) >> 13) & 0x07);
//  printf("Fragment Offset: %u\n", (ntohs(ip->frag_off) & 0x1FFF) * 8);
//  printf("Time to Live: %u\n", ip->ttl);
//  printf("Protocol: %u\n", ip->protocol);
//  printf("Header Checksum: 0x%04X\n", ntohs(ip->check));
//  printf("Source IP Address: %s\n", inet_ntoa(*(struct in_addr*)&ip->saddr));
//  printf("Destination IP Address: %s\n", inet_ntoa(*(struct in_addr *)&ip->daddr));
//  printf("----------------------------\n");
//}
void print_tcp_header(struct tcphdr *tcp) {
  printf("TCP Header\n");
  printf("----------------------------\n");
  printf("Source Port: %u\n", ntohs(tcp->source));
  printf("Destination Port: %u\n", ntohs(tcp->dest));
  printf("Sequence Number: %u\n", ntohl(tcp->seq));
  printf("Acknowledgment Number: %u\n", ntohl(tcp->ack_seq));
  printf("Data Offset: %u bytes\n", tcp->doff * 4);
  printf("Flags: 0x%02X\n", tcp->th_flags);
  printf("Window Size: %u\n", ntohs(tcp->window));
  printf("Checksum: 0x%04X\n", ntohs(tcp->check));
  printf("Urgent Pointer: %u\n", ntohs(tcp->urg_ptr));
  printf("----------------------------\n");
}

void print_udp_header(struct udphdr *udp) {
  printf("UDP Header\n");
  printf("----------------------------\n");
  printf("Source Port: %u\n", ntohs(udp->source));
  printf("Destination Port: %u\n", ntohs(udp->dest));
  printf("Length: %u bytes\n", ntohs(udp->len));
  printf("Checksum: 0x%04X\n", ntohs(udp->check));
  printf("----------------------------\n");
}

void process_packet(unsigned char *buffer, int packet_size) {
  struct ip *ip = (struct ip *)buffer;

  if (ip->ip_p == IPPROTO_TCP) {
    printf("Packet is a TCP packet.\n");

    struct tcphdr *tcp = (struct tcphdr *)(buffer + ip->ip_hl * 4);
    print_tcp_header(tcp);

    // Additional processing for TCP packet
    // ...

  } else if (ip->ip_p == IPPROTO_UDP) {
    printf("Packet is a UDP packet.\n");

    struct udphdr *udp = (struct udphdr *)(buffer + ip->ip_hl * 4);
    print_udp_header(udp);

    // Additional processing for UDP packet
    // ...

  } else {
    printf("Packet is neither a TCP nor UDP packet.\n");
  }
}

int main() {
  int epollfd;
  if ((epollfd = epoll_create1(0)) == -1)
    perror("epoll_create1"), exit(EXIT_FAILURE);

  int sock_r = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
  if (sock_r < 0) {
    printf("error in socket\n");
    return -1;
  }
  // STDIN_FILENO
  struct epoll_event ev = {.events = EPOLLIN, .data.fd = sock_r};
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
            process_packet(buffer + sizeof(struct ethhdr),
                           buflen - sizeof(struct ethhdr));
}
//  void print_eth_header(struct ethhdr *eth) {
//    printf("Ethernet Header\n");
//    printf("----------------------------\n");
//    printf("Destination MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
//            eth->h_dest[0], eth->h_dest[1], eth->h_dest[2],
//            eth->h_dest[3], eth->h_dest[4], eth->h_dest[5]);
//    printf("Source MAC: %02X:%02X:%02X:%02X:%02X:%02X\n",
//            eth->h_source[0], eth->h_source[1], eth->h_source[2],
//            eth->h_source[3], eth->h_source[4], eth->h_source[5]);
//    printf("EtherType: 0x%04X\n", ntohs(eth->h_proto));
//    printf("----------------------------\n");
//  }
//  #include <netinet/udp.h> // Include the necessary header file
//  void print_udp_header(struct udphdr *udp) {
//    printf("UDP Header\n");
//    printf("----------------------------\n");
//    printf("Source Port: %u\n", ntohs(udp->source));
//    printf("Destination Port: %u\n", ntohs(udp->dest));
//    printf("Length: %u bytes\n", ntohs(udp->len));
//    printf("Checksum: 0x%04X\n", ntohs(udp->check));
//    printf("----------------------------\n");
//  }
//  void data_process(unsigned char *buffer, int buflen) {
//    struct ethhdr *eth = (struct ethhdr *)(buffer);
//    struct iphdr *ip = (struct iphdr *)(buffer + sizeof(struct ethhdr));
//    struct udphdr *udp = (struct udphdr *)(buffer + sizeof(struct
//    ethhdr)); if(ip->protocol == 17) {
//      print_eth_header(eth);
//      print_udp_header(udp);
//    }
//  }
//  
/*
 The primary objective is to prioritize words as the main method of
 communication. Instead of exchanging information through fragmented
 streams, the aim is to convey it through complete sentences. However,
 if it becomes necessary to transmit fragmented streams, words can be
 used to indicate that intention. For example, to prepare the listeners
 to receive such fragmented streams.

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
