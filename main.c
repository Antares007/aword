#include <assert.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
void *map_file(const char *file) {
  int fd = open(file, O_RDONLY);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return 0;
  char *addr = mmap((void *)0x0000070700000000, sb.st_size,
                    PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE, fd, 0);
  close(fd);
  assert(addr != MAP_FAILED);
  ((long*)addr)[1] = sb.st_size;
  return addr;
}
#include "aword.h"
#include <stdio.h>
#include <string.h>
void ti(void*);
void ti_init();
int main(int argc, const char **argv) {
  long a = 0;
  void*o[512];
  long b = sizeof(o) / sizeof(*o);
  o[a++] = printf;
  o[a++] = ti;
  o[a++] = map_file;
  o[a++] = usleep;
  o[a++] = munmap;
//  ti_init();
  n_t w = Bark("b r o");
  (w)(0, a, b, o, "");
}
