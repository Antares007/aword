#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
N(m);
N(b) {
  if (d[0]) {
    if (Blue(==))
      Yellow(=);
    White(=), m(a, w, o, 1, d, s);
  }
}
N(dot) {
  if      (Yellow(==))  Green(=);
  else if (Green(==))   Yellow(=);
  Black(=), m(a, w, o, r, d, s);
}
N(tina ) { m(a, w, o, r, d, s); }
N(kargi) { m(a, w, o, r, d, s); }
N(gogoa) { m(a, w, o, r, d, s); }
N(id   ) { m(a, w, o, r, d, s); }
N(tab) {
  if (Green(==)) White(=), m(a, w, o, r, d, s);
  else {
    if (Yellow(==)) {
      m(a, o[s + 2].q, o, r, d, s + 4);
    } else if(Blue(==)) {
      r          = o[s + 4].q;
      if (r) 
        assert(0);
      else {
        char *d    = o[s + 3].cs;
        long wti   = o[s + 2].q;
        long *ds   = o[wti-1].v;
        long index = ds[-1];
        long count = ds[-2];
      }
    } else assert(0);
  }
}
---T--
   |
   T--
   |
#define V(erb, ...) N(erb) { if (Green(==) && White(==)) { __VA_ARGS__; } m(a, w, o, r, d, s); }
V(var_heart,
  long *ds    = o[w - 1].v;
  long count  = ds[-2];
  long index  = ds[-1];
  ds[-1]     += r;
  r           = ds[-1] / count;
  ds[-1]      = ds[-1] - r * count;
  o[--s].q    = r;
  o[--s].v    = (void*)d;
  o[--s].q    = w;
  o[--s].q    = 3; // Yellow
  o[--s].q    = 5;
  w = ds[index];
)
V(t_t, if (d[0] == 't') d++; else Blue(=);)
V(a_t, if (d[0] == 'a') d++; else Blue(=);)
V(b_t, if (d[0] == 'b') d++; else Blue(=);)
N(S) {
  long p0     = (a + 2);  T(tab), T(t_t),         T(dot);
  long p1     = (a + 2);  T(tab), T(S),  T(a_t),  T(dot);
  long p2     = (a + 2);  T(tab), T(S),  T(t_t),  T(dot);
  o[w - 1].v  = (long[]){2, 0, p0, p1, p2} + 5/2;
  o[w].c      = var_heart;
  var_heart(a, w, o, r, d, s);
}
N(ba) { if (Green(==) && Black(==)) d = "tat"; m(a, w, o, r, d, s); }
void text_index_init();
int main() {
  long a = 0;
  long w = 0;
  o_t  o[2048];
  long r = 1;
  void* d = "";
  long s = sizeof(o) / sizeof(*o) - 2;
  Yellow(=);
  White(=);
  text_index_init();
  w = a + TW / 2;
  T(b), T(ba), T(S), T(dot);
  m(a, w, o, r, d, s);
  return 0;
}
