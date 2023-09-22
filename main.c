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
  return addr;
}
#include "aword.h"
#include <stdio.h>
#include <string.h>
n_t ls(const char *atext) {
  static void *list[1024][2];
  static long length = 0;
  //for (long i = 0; i < length; i++)
  //  if (strcmp(list[i][0], atext) == 0)
  //    return list[i][1];
  void *w = map_file(atext);
  list[length][0] = (void *)atext;
  list[length][1] = w;
  length++;
  return w;
}
N(Dot) { ((n_t *)o)[a - 1](t, a - 1, b, o, s); }
int main(int argc, const char **argv) {
  long a = 0;
  void *o[512];
  long b = sizeof(o) / sizeof(*o);

  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = ls;
  n_t w = W("b r o");
  (w + 16)(1, a, b, o, "");
}
