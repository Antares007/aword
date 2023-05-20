#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
typedef void (*n_t)(long a, void**o, long s);
static long load_aword(void*memory, char*aw_name);
void *map_file(const char *file_name);

static void *memory;
static long position = 0;
static n_t compose(char**t, long s) {
  n_t aw = memory + position;
  for(long i = 0; i < s; i++)
    printf("%s ",  t[i]), position += load_aword(memory + position, t[i]);
  printf("%ld\n", (void*)aw-memory);
  return aw;
}
static int hash(char**t, long s);
static n_t compose_cache(char**t, long s);
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



static long load_aword(void*memory, char*aw_name) {
  FILE*f = fopen(aw_name, "r");
  fseek(f, 0, SEEK_END);
  long s = ftell(f);
  fseek(f, 0, SEEK_SET);
  long r = fread(memory, 1, s, f);
  fclose(f);
  return r;
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
  static int   keys[1024] = {};
  static n_t   values[1024] = {};
  static long  length      = 0;
  int h = hash(t, s);
  for(long i = 0; i < length; i++)
    if (keys[i] == h)
      return values[i];
  n_t w = compose(t, s);
  keys[length] = h, values[length] = w, length++;
  return w;
}
