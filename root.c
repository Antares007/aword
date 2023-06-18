#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
static N(T);
void *map_file(const char *file_name);
long load_file(void *memory, const char *aw_name);
void monitor_init();
N(Maroon_end) { P;}
N(Olive_end ) { P;}
N(Navy_end  ) { P;}
int main(int argc, const char **argv) {
  long t = 0;
  long a = 0;
  void*b = map_file("ram.ram");
  void*o[512];
  long s = sizeof(o) / sizeof(*o);

  assert(b);

  o[--s] = Maroon_end;
  o[--s] = Olive_end;
  o[--s] = Navy_end;

  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = T;
  o[a++] = (void *)1;

  o[a++] = "b";
  o[a++] = (void *)1;
  T(t, a, b, o, s);
}
static N(T) {
  long word_count = (long)o[--a];
  const char **asentence = (const char **)&o[a -= word_count];

  n_t aword = b + t;
  t += load_file(b + t, "tab");
  for (long i = 0; i < word_count; i++)
    t += load_file(b + t, asentence[i]);
  t += load_file(b + t, "o");
  (aword + 16)(t, a, b, o, s);
  aword(t, a, b, o, s);
}
