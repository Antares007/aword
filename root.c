#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef void (*n_t)(void **o, long s, long a);
static void load_aword(void **o, long s, long a, const char *aw_name);
void *map_file(const char *file_name);
long t;
n_t  b;
int main(int argc, char **argv) {
       t = 0;
  long a = 0;
       b = map_file("ram.ram");
  void*o[512];
  long s = sizeof(o) / sizeof(*o);

  assert(b);

  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = load_aword;
  o[a++] = (void *)1;

  load_aword(o, s, a, "b show o");
}
static long load_aword__(void *memory, char *aw_name) {
  char str[707];
  snprintf(str, 707, "abin/%s", aw_name);
  FILE *f = fopen(str, "r");
  assert(f);
  fseek(f, 0, SEEK_END);
  long size = ftell(f);
  fseek(f, 0, SEEK_SET);
  long r = fread(memory, 1, size, f);
  assert(size == r);
  fclose(f);
  return r;
}
static void ti0(void**o, long s, long a) { n_t nar = o[s++];n_t Yellow = o[s++]; printf("%ld\n", ((long*)(Yellow+0x230))[11]); nar(o, s, a); }
static void ti1(void**o, long s, long a) { n_t nar = o[s++];n_t Yellow = o[s++]; printf("%ld\n", ((long*)(Yellow+0x230))[11]); nar(o, s, a); }
static void ti2(void**o, long s, long a) { n_t nar = o[s++];n_t Yellow = o[s++]; printf("%ld\n", ((long*)(Yellow+0x230))[11]); nar(o, s, a); }
static void ti3(void**o, long s, long a) { n_t nar = o[s++];n_t Yellow = o[s++]; printf("%ld\n", ((long*)(Yellow+0x230))[11]); nar(o, s, a); }
static void ti4(void**o, long s, long a) { n_t nar = o[s++];n_t Yellow = o[s++]; printf("%ld\n", ((long*)(Yellow+0x230))[11]); nar(o, s, a); }
static void ti5(void**o, long s, long a) { n_t nar = o[s++];n_t Yellow = o[s++]; printf("%ld\n", ((long*)(Yellow+0x230))[11]); nar(o, s, a); }
static void ti6(void**o, long s, long a) { n_t nar = o[s++];n_t Yellow = o[s++]; printf("%ld\n", ((long*)(Yellow+0x230))[11]); nar(o, s, a); }
static void ti7(void**o, long s, long a) { n_t nar = o[s++];n_t Yellow = o[s++]; printf("%ld\n", ((long*)(Yellow+0x230))[11]); nar(o, s, a); }
static void ti8(void**o, long s, long a) { n_t nar = o[s++];n_t Yellow = o[s++]; printf("%ld\n", ((long*)(Yellow+0x230))[11]); nar(o, s, a); }
static void ti9(void**o, long s, long a) { n_t nar = o[s++];n_t Yellow = o[s++]; printf("%ld\n", ((long*)(Yellow+0x230))[11]); nar(o, s, a); }
static long load_aword_(void *memory, char *aw_name) {
  long t    = load_aword__(memory, aw_name);
  long size = t;
  void**jmps= memory + t + 0x230;
  t        += load_aword__(memory + t, "T");
  jmps[0]   = ti0;jmps[1]=ti1;jmps[2]=ti2;jmps[3]=ti3;jmps[4]=ti4;
  jmps[5]   = ti5;jmps[6]=ti6;jmps[7]=ti7;jmps[8]=ti8;jmps[9]=ti9;
  jmps[10]  = "aw_name";
  jmps[11]  = (void*)size;
  return t;
}
static n_t load_aword_core(const char *asentence) {
  const char *start = asentence;
  char aword[707];
  n_t aw = b + t;
  t += load_aword_(b + t, "tab");
  while (*asentence) {
    if (*asentence == ' ') {
      snprintf(aword, asentence - start + 1, "%s", start);
      t += load_aword_(b + t, aword);
      start = ++asentence;
    } else    ++asentence;
  }
  snprintf(aword, asentence - start + 1, "%s", start);
  t += load_aword_(b + t, aword);
  t += load_aword_(b + t, "o");
  return aw;
}
static int hash(const char *a) {
  int h = 29;
  while (*a)
    (h = 31 * h + *a), a++;
  return h;
}
static void load_aword(void **o, long s, long a, const char *asentence) {
  static int keys[1024] = {};
  static n_t values[1024] = {};
  static long length = 0;
  int h = hash(asentence);
  for (long i = 0; i < length; i++)
    if (keys[i] == h)
      return values[i](o, s, a);
  n_t w = load_aword_core(asentence);
  keys[length] = h, values[length] = w, length++;
  (w + 16)(o, s, a);
  w(o, s, a);
}
