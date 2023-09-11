#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
void *map_file(const char *file_name) {
  int fd = open(file_name, O_RDONLY);
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
#define L printf("%10s %4ld %4ld\n", __FUNCTION__, a, s), usleep(200000)
#define Λ L, printf("\n")
#else
#define L (void)0
#define Λ (void)0
#endif
#include "aword.h"
#include <stdio.h>
#include <stdlib.h>
void *ls_(const char *atext) {
  char str[777] = {0};
  if (777 == snprintf(str, 777, "cd abin&&cat %s > \"%s\"", atext, atext))
    return 0;
  if (system(str))
    return 0;
  snprintf(str, 777, "abin/%s", atext);
  return map_file(str);
}
#include <string.h>
N(ls) {
  const char *atext = o[--a];
  static void *store[1024][2];
  static long size = 0;
  for (long i = 0; i < size; i++)
    if (strcmp(store[i][0], atext) == 0)
      return (o[a++] = store[i][1]), ((n_t *)o)[s + 1](0, a, 0, o, s + 3);
  void *addr = ls_(atext);
  if (addr) {
    store[size][0] = (void *)atext;
    store[size][1] = addr;
    size++;
    o[a++] = addr;
    ((n_t *)o)[s + 1](0, a, 0, o, s + 3);
  } else {
    ((n_t *)o)[s + 0](0, a, 0, o, s + 3);
  }
}
N(Maroon_end) { L; }
N(Olive_end) { L; }
N(Navy_end) { L; }
N(Dot) { L, ((n_t *)o)[a - 1](0, a - 1, 0, o, s); }

N(stop    ) { L; }
N(space   ) { L; }
N(newline ) { L; }
N(dot     ) { L; }
N(name    ) { L; }
void Main(long a, void**o, long s) {
  const char *in =
      "Name as sentence\n"
      "First definition as sentence. Second definition as sentence.\n"
      "\n"
      "Name1\n"
      "Word1 word2 word3.\n";
  long len = 0;
  while (in[len]) {
    if (       ' '  == in[len]) { printf("\\s\n"); len++;
    } else if ('\n' == in[len]) { printf("\\n\n"); len++;
    } else if ('.'  == in[len]) { printf("\\.\n"); len++;
    } else {
      long start = len;
      while (in[len] != ' ' && in[len] != '\n' && in[len] != '.') { printf("%c", in[len++]); }
      printf(" %ld\n", len - start);
    }
  }
  printf("%ld", len);
}
int main(int argc, const char **argv) {
  long a = 0;
  void *o[512];
  long s = sizeof(o) / sizeof(*o);

  o[--s] = Maroon_end;
  o[--s] = Olive_end;
  o[--s] = Navy_end;

  Main(a, o, s);
  return 0;

  o[a++] = printf;
  o[a++] = usleep;
  o[--s] = Maroon_end;
  o[--s] = Dot;
  o[--s] = Navy_end;
  o[a++] = "b M M M M o";
  ls(0, a, 0, o, s);
}
