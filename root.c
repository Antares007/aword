#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
typedef void (*n_t)(void **o, long s, long a);
static void T(void **o, long s, long a);
void *map_file(const char *file_name);
long t;
n_t  b;
int main(int argc, const char **argv) {
       t = 0;
  long a = 0;
       b = map_file("ram.ram");
  void*o[512];
  long s = sizeof(o) / sizeof(*o);

  assert(b);

  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = T;
  o[a++] = (void *)1;
  n_t*aw = (n_t*)&o[a++];
  o[a++] = "b";
  o[a++] = "show";
  o[a++] = "o";
  o[a++] = (void*)3;
  o[a++] = aw;
  T(o, s, a);
}
static long T__(void *memory, const char *aw_name) {
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
static void ti0(void**o, long s, long a) { n_t nar=o[s++];void**d=(void*)o[s++]+0x230;printf("Olive   %20s %4ld\n",(char*)d[10], (long)d[11]), usleep(20000);nar(o, s, a); }
static void ti1(void**o, long s, long a) { n_t nar=o[s++];void**d=(void*)o[s++]+0x230;printf("Fuchsia %20s %4ld\n",(char*)d[10], (long)d[11]), usleep(20000);nar(o, s, a); }
static void ti2(void**o, long s, long a) { n_t nar=o[s++];void**d=(void*)o[s++]+0x230;printf("Maroon  %20s %4ld\n",(char*)d[10], (long)d[11]), usleep(20000);nar(o, s, a); }
static void ti3(void**o, long s, long a) { n_t nar=o[s++];void**d=(void*)o[s++]+0x230;printf("Lime    %20s %4ld\n",(char*)d[10], (long)d[11]), usleep(20000);nar(o, s, a); }
static void ti4(void**o, long s, long a) { n_t nar=o[s++];void**d=(void*)o[s++]+0x230;printf("Navy    %20s %4ld\n",(char*)d[10], (long)d[11]), usleep(20000);nar(o, s, a); }
static void ti5(void**o, long s, long a) { n_t nar=o[s++];void**d=(void*)o[s++]+0x230;printf("Blue    %20s %4ld\n",(char*)d[10], (long)d[11]), usleep(20000);nar(o, s, a); }
static void ti6(void**o, long s, long a) { n_t nar=o[s++];void**d=(void*)o[s++]+0x230;printf("Green   %20s %4ld\n",(char*)d[10], (long)d[11]), usleep(20000);nar(o, s, a); }
static void ti7(void**o, long s, long a) { n_t nar=o[s++];void**d=(void*)o[s++]+0x230;printf("Red     %20s %4ld\n",(char*)d[10], (long)d[11]), usleep(20000);nar(o, s, a); }
static void ti8(void**o, long s, long a) { n_t nar=o[s++];void**d=(void*)o[s++]+0x230;printf("Purple  %20s %4ld\n",(char*)d[10], (long)d[11]), usleep(20000);nar(o, s, a); }
static void ti9(void**o, long s, long a) { n_t nar=o[s++];void**d=(void*)o[s++]+0x230;printf("Yellow  %20s %4ld\n",(char*)d[10], (long)d[11]), usleep(20000);nar(o, s, a); }
static long T_(void *memory, const char *aw_name) {
  long t    = T__(memory, aw_name);
//  long size = t;
  void**jmps= memory + t + 0x230;
  t        += T__(memory + t, "T");
  jmps[0]   = ti0;jmps[1]=ti1;jmps[2]=ti2;jmps[3]=ti3;jmps[4]=ti4;
  jmps[5]   = ti5;jmps[6]=ti6;jmps[7]=ti7;jmps[8]=ti8;jmps[9]=ti9;
  jmps[10]  = (void*)aw_name;
  jmps[11]  = (void*)t;
  return t;
}
static n_t load_aword_core(const char **asentence, long count) {
  n_t aword = b + t;
  for(long i = 0; i < count; i++)
    t += T_(b + t, asentence[i]);
  return aword;
}
static int hash(const char **asentence, long count) {
  int h = 29;
  for(long i = 0; i < count; i++) {
    const char *a = asentence[i];
    printf("%s ", a);
    while (*a)
      (h = 31 * h + *a), a++;
  }
  printf("\n");
  return h;
}
static void T(void **o, long s, long a) {
  n_t* aword = (n_t*)o[--a];
  long count = (long)o[--a];
  const char**asentence = (const char**)&o[a -= count];

  static int keys[1024] = {};
  static n_t values[1024] = {};
  static long length = 0;

  int h = hash(asentence, count);
  for (long i = 0; i < length; i++)
    if (keys[i] == h)
      return (*aword = values[i]), ((n_t*)o)[a - 1](o, s, a - 1);
  *aword = load_aword_core(asentence, count);
  keys[length] = h, values[length] = *aword, length++;
  (*aword + 16)(o, s, a);
  ((n_t*)o)[a - 1](o, s, a - 1);
}
