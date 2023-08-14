#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *map_file(const char *file_name);
long load_file(void *memory, const char *aw_name);
void monitor_init();
N(Maroon_end) { P; }
N(Olive_end ) { P; }
N(Navy_end  ) { P; }
N(TI) {
  long ray = (long)o[s++];
  const char* name = (char*)o[s++];
  n_t Yellow = (void*)o[s++];
  static const char*cnames[] = {  "Yellow", "Purple", "Red",    "Green",    "Blue",
                                  "Navy",   "Lime",   "Maroon", "Fuchsia",  "Olive" };
  Printf("%10s %2ld %ld %s\n", cnames[ray], a, s, name);
  Yellow(t, a, b, o, s);
}
N(T) {
  long wc = (long)o[--a];
  const char**atext = (void*)&o[a -= wc];
  for (long i = 0; i < wc; i++) {
    t += load_file(b + t, atext[i]);
    char** name = b + t + 0x2d0;
    n_t*  tip  = b + t + 0x2d8;
    t += load_file(b + t, "TI");
    *name = (void*)atext[i];
    *tip = TI;
  }
  o[a++] = b + t - 32;
  ((n_t*)o)[s + 1](t, a, b, o, s + 3);
}
N(dot) {
  ((n_t*)o)[a - 1](t, a - 1, b, o, s);
}
int main(int argc, const char **argv) {
  long t = 0;
  long a = 0;
  void*b = map_file("ram.ram");
  void*o[512];
  long s = sizeof(o) / sizeof(*o);

  assert(b);
  void*ob[] = {
    Navy_end,
    Olive_end,
    Maroon_end,
  };
  o[--s] = ob;
  o[--s] = Maroon_end;
  o[--s] = Olive_end;
  o[--s] = Navy_end;

  o[a++] = printf;
  o[a++] = usleep;
  o[a++] = T;

  o[a++] = "baaa";
  o[a++] = (void*)4;
  o[a++] = (void*)0;
  o[--s] = Maroon_end;
  o[--s] = dot;
  o[--s] = Navy_end;
  o[a++] = "b";
  o[a++] = "m";
  o[a++] = "o";
  o[a++] = (void*)3;
  T(t, a, b, o, s);
}
