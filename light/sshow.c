#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
// clang-format off
N(m);
N(b) {
  White(=), m(a, w, o, r, d, s);
}
N(dot) {
  if      (Yellow(==)) Green(=);
  else if (Green(==))  Yellow(=);
  Black(=), m(a, w, o, r, d, s);
}
N(id) { m(a, w, o, r, d, s); }
#define Log printf("%ld%2ld %s\n", o[s+1].q, o[s+0].q, __FUNCTION__)
#define B(...)
#define D(ef, ...)                                                             \
  N(ef) {}
void turn(float);
N(tab) { }
N(t_term) { if (Green(==) && White(==)) { } m(a, w, o, r, d, s); }
N(a_term) { if (Green(==) && White(==)) { } m(a, w, o, r, d, s); }
N(b_term) { if (Green(==) && White(==)) { } m(a, w, o, r, d, s); }
N(s_term) { if (Green(==) && White(==)) { } m(a, w, o, r, d, s); }
N(noun) {
  if (Green(==) && Black(==))
    ;
  m(a, w, o, r, d, s);
}
D(sS,
  B(T(s_term), T(sS), T(sS)),
  B(T(id))
);
D(S,
  B(T(b_term)),
  B(T(S), T(a_term))
);
N(show) {
  w = a + 2;  T(b), T(id), T(dot);
  m(a, w, o, r, d, s);
}
void text_index_init();
int main() {
  long a = 0;
  long w = 0;
  o_t  o[2048];
  long r = 0;
  long d = 0;
  long s = sizeof(o) / sizeof(*o);
  text_index_init();
  o[--s].q = 1; // rvalue
  o[--s].q = 3; // Yellow(=) ray
  o[--s].q = 5; // Direction White(=)
  show(a, w, o, r, d, s);
  return 0;
}
