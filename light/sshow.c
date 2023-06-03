#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
// clang-format off
N(m);
N(b) {
  if (Yellow(==)) printf("[%s]\n", s);
  o[0].q = 1;
  m(a, w, o, r, White(=), s);
}
N(dot) {
  m(a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, Black(=), s);
}
N(id) { m(a, w, o, r, d, s); }
#define Log printf("%ld%2ld %s\n", r, d, __FUNCTION__)
#define B(...)                                                                 \
  (o[w + o[base + 1].q++].q = a + 2), T(tab), __VA_ARGS__, T(dot)
#define D(ef, ...)                                                             \
  N(ef) {                                                                      \
    long this     = w;                                                         \
    long base     = a; a += 4;                                                 \
    w             = a; a += 7;                                                 \
    o[base + 0].q = 0;                                                         \
    o[base + 1].q = 0;                                                         \
    __VA_ARGS__;                                                               \
    o[base + 2].f = 3.1416 / (o[base + 1].q + 1);                              \
    o[this - 1].q = base;                                                      \
    o[this    ].c = def_heart;                                                \
    def_heart(a, this, o, r, d, s);                                           \
  }
void turn(float);
// akauri kodis kompozica chirs, mkharshic minda igive ra gavaketot?
// ragaca sxvac unda vcadot.
// mutacia kmnis problemas. movipikrot brunvis sxva gadackveta. 
// otkhi mkhare pirveli meore mesame meotkhe erti ori sami otkhi trialleeeebsss
// triiiaaleeeeebbbsss bedis borbaliiii trialeeeebbbsss ...
// akhali protokoli davatrialot.
// tabos
//

N(def_heart) {
  long b        = o[w - 1].q;
  if (Green(==) && White(==) && o[b + 1].q) {
    long  t     = o[b + 4 + o[b].q].q;
    float theta = o[b + 2].f * (o[b].q + 1);
    turn(-theta);

    o[b].q      = o[b].q + o[0].q;
    o[0].q      = o[b].q / o[b + 1].q;
    o[b].q      = o[b].q - o[0].q * o[b + 1].q;

    o[t - 1].f  = theta;
    o[t + 1].q  = w;
    m(a, t, o, Yellow(=), White(=), s);
  } else
    m(a, w, o, r, d, s);
}
N(tab) {
  long t = o[w + 1].q;
  if (Yellow(==)) turn(o[w - 1].f), m(a, t, o, Green(=), White(=), s);
  else m(a, w, o, r,         White(=), s);
}
N(t_term) { if (Green(==) && White(==)) { if (s[0] == 't') s++; else Blue(=); } m(a, w, o, r, d, s); }
N(a_term) { if (Green(==) && White(==)) { if (s[0] == 'a') s++; else Blue(=); } m(a, w, o, r, d, s); }
N(b_term) { if (Green(==) && White(==)) { if (s[0] == 'b') s++; else Blue(=); } m(a, w, o, r, d, s); }
N(s_term) { if (Green(==) && White(==)) { if (s[0] == 's') s++; else Blue(=); } m(a, w, o, r, d, s); }
N(noun) {
  if (Green(==) && Black(==))
    s = o[w + 1].cs;
  m(a, w, o, r, d, s);
}
N(prints) { if (Green(==) && White(==)) printf("%s", o[w+1].cs); m(a, w, o, r, d, s); }
D(sS,
  B(T(s_term), T(sS), T(sS)),
  B(T(id))
);
D(S,
  B(T(a_term)),
  B(T(t_term)),
  B(T(s_term)),
  B(T(b_term))
);
N(show1) {
  w = a + 2;  T(b), Ta(noun, "ssss"), T(S), T(dot);
  m(a, w, o, r, d, s);
}
#define CAT_(a,b) a##b
#define CAT(a,b) CAT_(a,b)
#define L CAT(test_,__LINE__)
#define Test(Tail, Assert, Head)  \
  N(Head) {                       \
    if(Yellow(==)) {              \
      Assert;                     \
    }                             \
    if(Tail != 0) {               \
      o[w].c = Tail;              \
      m(a,w,o,r,White(==),s);     \
    }                             \
  }
                                    Test(0,
assert(s[0] == 'a'),              L)Test(L, 
assert(s[0] == 'b'),              L)Test(L,
assert(s[0] == 'b'),  test1_assert1)

N(show) { w = a + 2; T(test1_assert1), Ta(noun, "baaa"), T(S), T(dot); m(a,w,o,r,d,s); }

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
  show(a,w,o,Yellow(=), White(=),s);
  return 0;
} // 126rjFzgBncP4xU7o137uMxjscicA8Wg4J
