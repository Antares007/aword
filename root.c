#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
typedef void (*n_t)(long t, long a, void*b, void**o, long s);
static long load_aword(void*b,char*aw_name);
void *map_file(const char *file_name);
int main(int argc, char**argv) {
  long t = 0;
  long a = 0;
  n_t  b = map_file("ram.ram");
  void*o   [512];
  long s = sizeof(o) / sizeof(*o);

  assert(b);

  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = load_aword;
  o[a++] = (void*)1;

  t += load_aword(b + t, "b");
  for(long i = 1; i < argc; i++)
    t += load_aword(b + t, argv[i]);
  t += load_aword(b + t, "o");
  (b + 16)(t, a, b, o, s);
  b((long)o[a], a, b, o, s);
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
static long load_aword(void *b, char *asentence) {
  const char *start = asentence;
  char aword[707];
  long t = 0;
  while(*asentence) {
    if (*asentence == ' ') {
      snprintf(aword, asentence - start + 1, "%s", start);
      t += load_aword_(b + t, aword);
      start  = ++asentence;
    } else ++asentence;
  }
  snprintf(aword, asentence - start + 1, "%s", start);
  t += load_aword_(b + t, aword);
  return t;
}
