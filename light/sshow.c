#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
N(m);
N(b) { White(=), m(a, w, o, 1, d, s); }
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
  if (Yellow(==)) m(a, o[s + 2].q, o, r, d, s + 3);
  else  White(=), m(a, w, o, r, d, s);
}
N(var_heart) {
  if (Green(==) && Black(==)) {
    o[--s].q    = w;
    o[--s].q    = 3; // Yellow
    o[--s].q    = 5;
    long *ds    = o[w - 1].v;
    long count  = ds[-2];
    long index  = ds[-1];
    ds[-1]     += r;
    long r      = ds[-1] / count;
    ds[-1]      = ds[-1] - r * count;
    m(a, ds[index], o, r, d, s);
  } else
    m(a, w, o, r, d, s);
}
N(S) {
  long p0 = (a + 2); T(tab), T(tina),  T(dot);
  long p1 = (a + 2); T(tab), T(kargi), T(dot);
  long p2 = (a + 2); T(tab), T(gogoa), T(dot);
  o[w - 1].v = (long[]){3, 0, p0, p1, p2} + 5/2;
  o[w].c = var_heart;
  var_heart(a, w, o, r, d, s);
}
void text_index_init();
int main() {
  long a = 0;
  long w = 0;
  o_t  o[2048];
  long r = 1;
  long d = 0;
  long s = sizeof(o) / sizeof(*o) - 2;
  Yellow(=);
  White(=);
  text_index_init();
  w = a + TW / 2;
  T(b), T(S), T(dot);
  m(a, w, o, r, d, s);
  return 0;
}
