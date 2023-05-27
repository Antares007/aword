#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
N(m);
N(b) {
  if(d[0]) {
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
  if (Yellow(==)) (s+=3), m(a, o[s-1].q, o, r, d, s);
  else if(Green(==))  White(=), m(a, w, o, r, d, s);
  else (s+=3), (o[s].q = o[s-3].q), (o[s+1].q = o[s-2].q), m(a, o[s-1].q, o, r, d, s);
}
N(var_heart) {
  if (Green(==) && White(==)) {
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
N(a_t) { if (Green(==) && White(==)) { if (d[0] == 'a') d++; else Blue(=); } m(a, w, o, r, d, s); }
N(b_t) { if (Green(==) && White(==)) { if (d[0] == 'b') d++; else Blue(=); } m(a, w, o, r, d, s); }
N(c_t) { if (Green(==) && White(==)) { if (d[0] == 'c') d++; else Blue(=); } m(a, w, o, r, d, s); }
N(S) {
  long p0     = (a + 2);  T(tab),       T(b_t), T(dot);
  long p1     = (a + 2);  T(tab), T(S), T(a_t), T(dot);
  long p2     = (a + 2);  T(tab), T(S), T(c_t), T(dot);
  o[w - 1].v  = (long[]){3, 0, p0, p1, p2} + 5/2;
  o[w].c      = var_heart;
  var_heart(a, w, o, r, d, s);
}
N(ba) { if (Green(==) && Black(==)) d = "bca"; m(a, w, o, r, d, s); }
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
