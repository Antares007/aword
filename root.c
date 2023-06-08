#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
typedef void (*n_t)(long a, void**o, long s);
static long load_aword(void*memory, char*aw_name);
void *map_file(const char *file_name);
int main(int argc, char**argv) {
  long  t   = 0;
  long  a   = 0;
  n_t   b   = map_file("ram.ram");
  void *o     [512];
  long  s   = sizeof(o) / sizeof(*o);

  assert(b);

  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = load_aword;
  o[a++] = (void*)1;

  o[--s] = (void*)1;

  t += load_aword(b + t, "b");
  for(long i = 1; i < argc; i++)
    t += load_aword(b + t, argv[i]);
  t += load_aword(b + t, "o");
  (b + 16)(a, o, s);
  o[--s] = (void*)1;
  b(a, o, s);
}
static long load_aword_(void*memory, char*aw_name) {
  char str[707];
  snprintf(str, 707, "abin/%s", aw_name);
  FILE*f = fopen(str, "r");
  assert(f);
  fseek(f, 0, SEEK_END);
  long size = ftell(f);
  fseek(f, 0, SEEK_SET);
  long r = fread(memory, 1, size, f);
  assert(size == r);
  fclose(f);
  return r;
}
static long load_aword(void*memory, char*asentence) {
  const char *b = asentence;
  char aword[707];
  long t = 0;
  while(*asentence) {
    if (*asentence == ' ') {
      snprintf(aword, asentence - b + 1, "%s", b);
      t += load_aword_(memory+t, aword);
      b = ++asentence;
    } else ++asentence;
  }
  snprintf(aword, asentence - b + 1, "%s", b);
  t += load_aword_(memory+t, aword);
  return t;
}
