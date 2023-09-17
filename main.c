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
  if (addr == MAP_FAILED)
    return 0;
  return addr;
}
#ifndef NDEBUG
#include <stdio.h>
#include <unistd.h>
#define L printf("%10s %4ld %4ld\n", __FUNCTION__, a, s), usleep(20000)
#define Λ L, printf("\n")
#else
#define L (void)0
#define Λ (void)0
#endif
#include "aword.h"
#include <stdio.h>
#include <stdlib.h>
void *ls_(const char *atext) {
  char file[777] = {0};
  char makecmd[777] = {0};
  if (777 == snprintf(file, 777, "abin/%s", atext))
    return 0;
  if (access(file, F_OK) == -1) {
    if (777 == snprintf(makecmd, 777, "cd abin&&cat %s > \"%s\"", atext, atext))
      return 0;
    if (system(makecmd))
      return 0;
  }
  return map_file(file);
}
#include <assert.h>
n_t ls(const char *atext) {
  n_t w = ls_(atext);
  assert(w);
  return w;
}
N(Maroon_end) { L; }
N(Olive_end) { L; }
N(Navy_end) { L; }
N(Dot) { ((n_t *)o)[a - 1](t, a - 1, b, o, s); }
int main(int argc, const char **argv) {
  long a = 0;
  void *o[512];
  long s = sizeof(o) / sizeof(*o);

  T(Maroon_end, Olive_end, Navy_end);

  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = ls;
  n_t w = W("b s o");
  (w + 16)(1, a, 0, o, s);
}
