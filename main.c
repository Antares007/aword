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
  if (access(makecmd, F_OK) == -1) {
    if (777 == snprintf(makecmd, 777, "cd abin&&cat %s > \"%s\"", atext, atext))
      return 0;
    if (system(makecmd))
      return 0;
  }
  return map_file(file);
}
#include <string.h>
N(ls) {
  const char *atext = o[--a];
  //static void *store[1024][2];
  //static long size = 0;
  //for (long i = 0; i < size; i++)
  //  if (strcmp(store[i][0], atext) == 0)
  //    return (o[a++] = store[i][1]), ((n_t *)o)[s + 1](t, a, b, o, s + 3);
  n_t addr = ls_(atext);
  if (addr) {
    (addr + 16)(1, a, b, o, s);
    //store[size][0] = (void *)atext;
    //store[size][1] = addr;
    //size++;
    o[a++] = addr;
    ((n_t *)o)[s + 1](t, a, b, o, s + 3);
  } else {
    ((n_t *)o)[s + 0](t, a, b, o, s + 3);
  }
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
  o[a++] = Dot;

  T(Maroon_end, Dot, Navy_end);
  o[a++] = "b m m2 o";
  ls(0, a, 0, o, s);
}
