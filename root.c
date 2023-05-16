#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
static void *map_file(const char *file_name) {
  int fd = open(file_name, O_RDONLY);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return 0;
  char *loaded_at_addr =
      mmap((void *)0x0000770000000000, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  if (loaded_at_addr == MAP_FAILED)
    return 0;
  return loaded_at_addr;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
typedef void (*n_t)(long a, void**o, long s);

static long load_aword(void*memory, char*aw_name) {
  FILE*f = fopen(aw_name, "r");
  fseek(f, 0, SEEK_END);
  long s = ftell(f);
  fseek(f, 0, SEEK_SET);
  long r = fread(memory, 1, s, f);
  fclose(f);
  return r;
}
static void *memory;
static long position = 0;
static n_t compose(char**t, long s) {
  n_t aw = memory + position;
  for(long i = 0; i < s; i++)
    printf("%s ",  t[i]), position += load_aword(memory + position, t[i]);
  printf("%ld\n", (void*)aw-memory);
  return aw;
}
static int hash(char**t, long s) {
  int h = 29;
  for(long i = 0; i < s; i++) {
    char *a = t[i];
    while(*a) (h = 31 * h + *a), a++; 
  }
  return h;
}
static n_t compose_cache(char**t, long s) {
  static int   hashs[1024] = {};
  static n_t   awords[1024] = {};
  static long  length      = 0;
  int h = hash(t, s);
  for(long i = 0; i < length; i++)
    if (hashs[i] == h)
      return awords[i];
  n_t w = compose(t, s);
  hashs[length] = h, awords[length] = w, length++;
  return w;
}
void Gor(long a, void**o, long s) {
}
#define L __LINE__
#define EN(Tail, Name, Value, Head)
EN(Gor,
  "print",      printf,         L)EN(L,
  "usleep",     usleep,         L)EN(L,
  "compose",    compose_cache,  L)
int main(int argc, char**argv) {
  memory = map_file("../ram.ram");
  void*o[1024];
  long a = 0;
  long s = 1024;
  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = compose_cache;
  n_t w  = compose_cache(argv+1, argc-1);
  (w + 16)(a, o, s);
  w(a, o, s);
}
// 
