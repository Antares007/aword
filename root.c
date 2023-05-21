#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
typedef void (*n_t)(void**ο, long σ, long α, long ρ);
static long load_aword(void*memory, char*aw_name);
void *map_file(const char *file_name);

static void *memory;
static long position = 0;
static n_t compose(char**names, long count) {
  n_t aw = memory + position;
  for(long i = 0; i < count; i++)
    printf("%s ",  names[i]), position += load_aword(memory + position, names[i]);
  printf("%ld\n", (void*)aw-memory);
  return aw;
}
int main(int argc, char**argv) {
  memory = map_file("../ram.ram");
  void*ο[512 + 512 + 512];
  long σ = 512;
  long α = 0;
  long ρ = 1024;
  ο[α++] = printf;
  ο[α++] = usleep;
  ο[α++] = compose;
  n_t w  = compose(argv+1, argc-1);
  printf("\ncompose done\n");
  (w + 16)(ο, σ, α, ρ);
  printf("\ninit done\n");
  w(ο, σ, α, ρ);
}


#include<assert.h>
static long load_aword(void*memory, char*aw_name) {
  FILE*f = fopen(aw_name, "r");
  assert(f);
  fseek(f, 0, SEEK_END);
  long size = ftell(f);
  fseek(f, 0, SEEK_SET);
  long r = fread(memory, 1, size, f);
  assert(size == r);
  fclose(f);
  return r;
}
//static int hash(char**names, long count) {
//  int h = 29;
//  for(long i = 0; i < count; i++) {
//    char *a = names[i];
//    while(*a) (h = 31 * h + *a), a++; 
//  }
//  return h;
//}
//static n_t compose_cache(char**names, long count) {
//  static int   keys[1024] = {};
//  static n_t   values[1024] = {};
//  static long  length      = 0;
//  int h = hash(names, count);
//  for(long i = 0; i < length; i++)
//    if (keys[i] == h)
//      return values[i];
//  n_t w = compose(names, count);
//  keys[length] = h, values[length] = w, length++;
//  return w;
//}
