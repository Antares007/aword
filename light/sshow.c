#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
// clang-format off
N(m);
#define Bark  o[w   +2].q
#define Count o[Bark+6].q
#define Index o[Bark+5].q
N(b  ) { White(=), m(a, w, o, r, d, s); }
N(dot) { if      (Yellow(==)) Green(=);
         else if (Green(==))  Yellow(=);
         Black(=), m(a, w, o, r, d, s); }
N(id) { m(a, w, o, r, d, s); }
#define B(...) (o[Bark + Count++].q = r + 2), Tab(tab, w, Bark), __VA_ARGS__, T(dot)
#define D(ef, ...)                                                             \
  N(ef) {                                                                      \
    Bark = r; r += 7;                                                          \
    __VA_ARGS__;                                                               \
     o[w-1].f = 3.1416 / (Count + 1);                                          \
    (o[w].c = def_heart)(a, w, o, r, d, s);                                    \
  }
void turn(float);
N(def_heart) { 
  if (Green(==) && White(==) && Count) {
    float theta   = o[w-1].f * (Index + 1);
    w             = o[Bark + Index].q;
    turn(theta);
    o[w - 1].f    = -theta;
    Index         = Index + o[s + 2].q;
    long srvalue  = Index / Count;
    Index         = Index - srvalue * Count;
    o[--s].q      = srvalue;
    o[--s].q      = 3; // Yellow
    o[--s].q      = 5; // White
  }
  m(a, w, o, r, d, s);
}
N(tab   ) {
  if (Yellow(==)) {
    (s += 3), turn(o[w-1].f),      m(a, o[w + 1].q, o, r, d, s);
  } else if (Blue(==)) {
    (s += 3), turn(o[w-1].f);
    if (Index + 1 < Count) def_heart(a, o[w + 1].q, o, r, d, s);
    else                 Black(=), m(a, o[w + 1].q, o, r, d, s);
  } else {
    White(=), m(a, w, o, r, d, s);
  }
}
N(t_term) {if(Green(==)&&White(==)){if(o[a-1].cs[0]=='t')o[a-1].cs++;else Blue(=);}m(a,w,o,r,d,s);}
N(a_term) {if(Green(==)&&White(==)){if(o[a-1].cs[0]=='a')o[a-1].cs++;else Blue(=);}m(a,w,o,r,d,s);}
N(b_term) {if(Green(==)&&White(==)){if(o[a-1].cs[0]=='b')o[a-1].cs++;else Blue(=);}m(a,w,o,r,d,s);}
N(s_term) {if(Green(==)&&White(==)){if(o[a-1].cs[0]=='s')o[a-1].cs++;else Blue(=);}m(a,w,o,r,d,s);}
N(noun  ) {
  if (Green(==) && Black(==))
    o[a++].v = o[w + 1].v;
  m(a, w, o, r, d, s);
}
D(sS,
  B(T(id)),
  B(T(s_term), T(sS), T(sS))
);
D(S,
  B(T(b_term)),
  B(T(S), T(a_term))
  //B(T(S), T(t_term))
);
N(show) {
  w = r + 2;  T(b), Ta(noun, "baaa"), T(S), T(dot);
  m(a, w, o, r, d, s);
}
void text_index_init();
int main() {
  long a    = 1024;
  long w    = 0;
  o_t  o[2048];
  long r    = 0;
  long d    = 0;
  long s    = sizeof(o) / sizeof(*o);
  text_index_init();
  o[--s].q  = 1; // RValue
  o[--s].q  = 3; // Yellow(=) Ray
  o[--s].q  = 5; // Direction White(=)
  show(a, w, o, r, d, s);
  return 0;
}
