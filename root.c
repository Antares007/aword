#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
typedef void (*n_t)(long a, void**o, long s);
static void load_aword(long a, void**o, long s, const char*aw_name);
void *map_file(const char *file_name);
long t;
n_t  b;
int main(int argc, char**argv) {
       t = 0;
  long a = 0;
       b = map_file("ram.ram");
  void*o   [512];
  long s = sizeof(o) / sizeof(*o);

  assert(b);

  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = load_aword;
  o[a++] = (void*)1;

  load_aword(a, o, s, "b show o");
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
static n_t load_aword_core(const char *asentence) {
  const char *start = asentence;
  char aword[707];
  n_t aw = b + t;
  while(*asentence) {
    if (*asentence == ' ') {
      snprintf(aword, asentence - start + 1, "%s", start);
      t += load_aword_(b + t, aword);
      start  = ++asentence;
    } else ++asentence;
  }
  snprintf(aword, asentence - start + 1, "%s", start);
  t += load_aword_(b + t, aword);
  return aw;
}
static int hash(const char*a) {
  int h = 29;
  while(*a) (h = 31 * h + *a), a++; 
  return h;
}
static void load_aword(long a, void**o, long s, const char*asentence) {
  static int   keys[1024] = {};
  static n_t   values[1024] = {};
  static long  length      = 0;
  int h = hash(asentence);
  for(long i = 0; i < length; i++)
    if (keys[i] == h)
      return values[i](a, o, s);
  n_t w = load_aword_core(asentence);
  keys[length] = h, values[length] = w, length++;
  (w+16)(a, o, s);
  w(a, o, s);
}
