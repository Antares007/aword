#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <errno.h>

#define BUFSIZE 2048

// Function to create and configure the TUN/TAP device
int tun_alloc(char *dev, int flags) {
    struct ifreq ifr;
    int fd, err;

    if ((fd = open("/dev/net/tun", O_RDWR)) < 0) {
        perror("Opening /dev/net/tun");
        return fd;
    }

    memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_flags = flags;

    if (*dev) {
        strncpy(ifr.ifr_name, dev, IFNAMSIZ - 1);
    }

    if ((err = ioctl(fd, TUNSETIFF, (void *)&ifr)) < 0) {
        perror("ioctl(TUNSETIFF)");
        close(fd);
        return err;
    }

    strcpy(dev, ifr.ifr_name);
    return fd;
}
#include <arpa/inet.h>
#include <stdint.h>
int main(int argc, char *argv[]) {
    char dev[IFNAMSIZ] = "tun0"; // Default device name
    int tun_fd;
    char buffer[BUFSIZE];
    int nread;

    // Allocate TUN device
    tun_fd = tun_alloc(dev, IFF_TUN);
    if (tun_fd < 0) {
        fprintf(stderr, "Error allocating TUN/TAP device\n");
        return 1;
    }

    printf("TUN device %s allocated\n", dev);

    while (1) {
        // Read packets from the TUN device
        nread = read(tun_fd, buffer, BUFSIZE);
        if (nread < 0) {
            perror("Reading from TUN device");
            close(tun_fd);
            return 1;
        }
  
        uint16_t flags = ntohs(((uint16_t*)buffer)[0]);
        uint16_t proto = ntohs(((uint16_t*)buffer)[1]);
        if (proto != 0x800) continue;
        printf("Read %d bytes from device %s\n", nread, dev);
        printf("flags:%04x proto:%04x\n", flags, proto);
        // Print packet content in hexadecimal
        for (int i = 0; i < nread; i++) {
            printf("%02x ", (unsigned char)buffer[i]);
            if ((i + 1) % 16 == 0) {
                printf("\n");
            }
        }
        printf("\n");
    }

    close(tun_fd);
    return 0;
}

