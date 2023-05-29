#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
// clang-format off
N(m   );
N(b   ) {               m(a, w, o, r, White(=), s); }
N(bo  ) { (o[0].q = 1), m(a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, Black(=), s); }
N(dot ) {               m(a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, Black(=), s); }
N(id  ) { m(a, w, o, r, d, s); }
#define B(ark, ...)                                                            \
  (o[ark + o[ark + 6].q++].q = a + 2), T(tab), __VA_ARGS__, T(dot);
#define D(ef, ...)                                                             \
  N(ef) {                                                                      \
    long Olive    = (a     );                                                  \
    long Maroon   = (a += 7);                                                  \
    long Lime     = (a += 7);                                                  \
    long Navy     = (a += 7);                                                  \
                    (a += 7);                                                  \
    long Blue     = (a += 7);                                                  \
    long Green    = (a += 7);                                                  \
    long Red      = (a += 7);                                                  \
    long Yellow   = (a += 7);                                                  \
    o[Olive +5].q = 0, o[Olive +6].q = 0;                                      \
    o[Maroon+5].q = 0, o[Maroon+6].q = 0;                                      \
    o[Lime  +5].q = 0, o[Lime  +6].q = 0;                                      \
    o[Navy  +5].q = 0, o[Navy  +6].q = 0;                                      \
    o[Blue  +5].q = 0, o[Blue  +6].q = 0;                                      \
    o[Green +5].q = 0, o[Green +6].q = 0;                                      \
    o[Red   +5].q = 0, o[Red   +6].q = 0;                                      \
    o[Yellow+5].q = 0, o[Yellow+6].q = 0;                                      \
    __VA_ARGS__;                                                               \
    o[w - 1].q    = Olive;                                                     \
    o[w].c        = def_heart;                                                 \
    def_heart(a, w, o, r, d, s);                                               \
  }
void turn(float);
N(def_heart) {
  long Olive = o[w - 1].q + ((r + 1) * d / TW + 4) * 7;
  long count = o[Olive + 6].q;
  if (count) {
    long index      = o[Olive + 5].q;
    float theta     = (3.1416 / 5) * (index + 1) * d / TW;
    turn(-theta);

    long bti        = o[Olive + index].q;
    o[Olive + 5].q += o[0].q;
    o[0].q          = o[Olive + 5].q / o[Olive + 6].q;
    o[Olive + 5].q  = o[Olive + 5].q - o[0].q * o[Olive + 6].q;
    o[bti+1].q      = w;
    o[bti-1].v2.x   = r;
    o[bti-1].v2.y   = d;
    o[bti-2].v2.x   = theta;
    m(a, bti, o, Yellow(=), White(=), s);
  } else
    m(a, w, o, r, d, s);
}
N(tab) {
  if (Yellow(==))
    turn(o[w - 2].v2.x), m(a, o[w + 1].q, o, o[w - 1].v2.x, o[w - 1].v2.y, s);
  else
    m(a, w, o, r, White(=), s);
}
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
  B(Green, T(b_term))
  B(Green, T(S), T(a_term))
);
N(show) {
  w=a+2;   T(b),T(baaa),T(S),T(dot);
  m(a,w,o,r,d,s);
}
D(E,    B(Lime,  T(id),Ta(prints, "A")) B(Green, T(id), Ta(prints, "a")) //
        B(Lime,  T(id),Ta(prints, "B")) B(Green, T(id), Ta(prints, "b")) //
        B(Lime,  T(id),Ta(prints, "C")) B(Green, T(id), Ta(prints, "c")) //
);D(F,  B(Lime,  T(id),Ta(prints, "U")) B(Green, T(id), Ta(prints, "u")) //
        B(Lime,  T(id),Ta(prints, "V")) B(Green, T(id), Ta(prints, "v")) //
  
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
    T(E),
   // T(F),
    Ta(prints,"\n"), T(bo); m(a, w, o, Yellow(=), White(=), s);
  return 0;
} // 126rjFzgBncP4xU7o137uMxjscicA8Wg4J
