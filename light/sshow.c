#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
// clang-format off
N(m   );
N(b   ) { (o[0].q = 1), m(a, w, o, r,                           White(=), s); }
N(dot ) {               m(a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, Black(=), s); }
N(id  ) {               m(a, w, o, r,                           d,        s); }
#define Log printf("%s\n", __FUNCTION__)
#define B_(...) __VA_ARGS__, T(dot)
#define B(...)                                                                 \
  (o[Green + o[base + 1].q  ].q = a + 2), T(tab), B_(__VA_ARGS__),             \
  (o[Lime  + o[base + 1].q++].q = a + 2), T(tba), B_
#define D(ef, ...)                                                             \
  N(ef) {                                                                  \
    long base     = a; a += 4;                                                 \
    long Green    = a; a += 7;                                                 \
    long Lime     = a; a += 7;                                                 \
    o[base + 0].q = 0;                                                         \
    o[base + 1].q = 0;                                                         \
    __VA_ARGS__;                                                               \
    o[base + 2].f = 3.1416 / (o[base + 1].q + 1);                              \
    o[w    - 1].q = base;                                                      \
    o[w       ].c = def_switch;                                                \
    def_switch(a, w, o, r, d, s);                                              \
  }
void turn(float);
N(def_Yellow) {
  long b    = o[w-1].q;
  o[b+3].q  = o[b].q + o[0].q;
  o[0  ].q  = o[b+3].q / o[b+1].q;
  o[b+3].q  = o[b+3].q - o[0].q * o[b+1].q;
  m(a, w, o, Yellow(=),  White(=), s);
}
N(def_Olive) {
  long b    = o[w-1].q;
  o[b].q    = o[b+3].q;
  m(a, w, o, r, d, s);
}
N(def_Green ) {
  long b      = o[w-1].q;
  if (o[b+1].q) {
    long bi   = o[b + 4 + 0 + o[b].q].q;
    float theta = o[b+2].f * (o[b].q+1);
    turn(-theta);
    o[bi+1].q = w;
    o[bi-1].f = theta;
    m(a, bi, o, Yellow(=), White(=), s);
  } else
    m(a, w, o, r, d, s);
}
N(def_Lime  ) { 
  long b      = o[w-1].q;
  if (o[b+1].q) {
    long bi   = o[b + 4 + 7 + o[b].q].q;
    float theta = o[b+2].f * (o[b].q+1);
    turn(theta);
    o[bi+1].q = w;
    o[bi-1].f = -theta;
    m(a, bi, o, Yellow(=), White(=), s);
  } else
    m(a, w, o, r, d, s);
}
N(def_switch) {
  static N((*rays[])) = { def_Olive, m, def_Lime, m, 0, m, def_Green, m, def_Yellow};
  rays[(r + 1) * d / TW + 4](a, w, o, r, d, s);
}
N(tab) {  if (Yellow(==)) turn(o[w-1].f), m(a, o[w+1].q, o, Green(=), White(=), s);
          else                            m(a, w,        o, r,        White(=), s); }
N(tba) {  if (Yellow(==)) turn(o[w-1].f), m(a, o[w+1].q, o, Green(=), Black(=), s);
          else                            m(a, w,        o, r,        White(=), s); }

N(t_term) { if (Green(==) && White(==)) { if (s[0] == 't') s++; else Blue(=); } m(a, w, o, r, d, s); }
N(a_term) { if (Green(==) && White(==)) { if (s[0] == 'a') s++; else Blue(=); } m(a, w, o, r, d, s); }
N(b_term) { if (Green(==) && White(==)) { if (s[0] == 'b') s++; else Blue(=); } m(a, w, o, r, d, s); }
N(baaa) {
  if (Green(==) && Black(==))
    s = "baaaa";
  m(a, w, o, r, d, s);
}
N(prints) { if(Green(==) && White(==)) printf("%s", o[w+1].cs); m(a,w,o,r,d,s); }
N(or);
D(S,
  B(T(b_term))(T(S), T(a_term))
);
N(show) {
  w=a+2;   T(b),T(baaa),T(S),T(dot);
  m(a,w,o,r,d,s);
}
D(E,      B(T(id),T(id),Ta(prints, "A"))(T(id),T(id),Ta(prints, "a")), //
          B(T(id),T(id),Ta(prints, "B"))(T(id),T(id),Ta(prints, "b")) //
);D(F,    B(T(id),T(id),Ta(prints, "U"))(T(id),T(id),Ta(prints, "u")), //
          B(T(id),T(id),Ta(prints, "V"))(T(id),T(id),Ta(prints, "v")), //
          B(T(id),T(id),Ta(prints, "X"))(T(id),T(id),Ta(prints, "x")), //
          B(T(id),T(id),Ta(prints, "Y"))(T(id),T(id),Ta(prints, "y")), //
          B(T(id),T(id),Ta(prints, "Z"))(T(id),T(id),Ta(prints, "z")) //
);
void text_index_init();
int main() {
  long a = 0;
  long w = 0;
  o_t  o[2048];
  long r;
  long d;
  const char *s = "";
  o[a++].q = 1;
  text_index_init();
//  show(a,w,o,Yellow(=), White(=),s);
  (w = a + TW / 2),
    T(b),
    T(E), T(id), T(id), T(id), T(id),
    T(E), T(id), T(id), T(id), T(id),
    T(E),
    Ta(prints,"\n"), T(dot); m(a, w, o, Yellow(=), White(=), s);
  return 0;
} // 126rjFzgBncP4xU7o137uMxjscicA8Wg4J
