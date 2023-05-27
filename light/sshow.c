#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
N(m);
N(b) { m(a, w, o, r, White(=), s); }
N(dot) { m(a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, Black(=), s); }
N(tina) { m(a, w, o, r, d, s); }
N(kargi) { m(a, w, o, r, d, s); }
N(gogoa) { m(a, w, o, r, d, s); }
N(id) { m(a, w, o, r, d, s); }
#define V(erb, ...)                                                            \
  N(erb) {                                                                     \
    if (Green(==) && White(==)) {                                              \
      __VA_ARGS__;                                                             \
    }                                                                          \
    m(a, w, o, r, d, s);                                                       \
  }
#define B(ark, ...) (ark = a + 2), T(tab), __VA_ARGS__, T(dot);
#define D(ef, ...)                                                             \
  N(ef) {                                                                      \
    long Olive = 0, Maroon = 0, Lime = 0, Navy = 0, Blue = 0, Green = 0,       \
         Red = 0, Yellow = 0;                                                  \
    __VA_ARGS__;                                                               \
    o[w - 1].v = (long[]){                                                     \
        Olive, Maroon, Lime, Navy, 0, Blue, Green, Red, Yellow,                \
    };                                                                         \
    o[w].c = def_heart;                                                        \
    def_heart(a, w, o, r, d, s);                                               \
  }
N(def_heart) {
  long *defs = o[w - 1].v;
  long ray = defs[(r + 1) * d / TW + 4];
  if (ray) {
    o[--s].q = d;
    o[--s].q = r;
    o[--s].q = w;
    m(a, ray, o, Yellow(=), White(=), s);
  } else
    m(a, w, o, r, d, s);
}
N(tab) {
  if (Yellow(==))
    m(a, o[s + 0].q, o, o[s + 1].q, o[s + 2].q, s + 3);
  else
    m(a, w, o, r, White(=), s);
}

D(E,                 //
  B(Green, T(tina))  //
  B(Lime, T(kargi))  //
  B(Olive, T(gogoa)) //
);

void text_index_init();
int main() {
  long a = 0;
  long w = 0;
  o_t o[2048];
  long r;
  long d;
  long s = sizeof(o) / sizeof(*o);
  text_index_init();
  (w = a + TW / 2), T(b), T(id), T(E), T(id), T(dot);
  m(a, w, o, Yellow(=), White(=), s);
  return 0;
}
