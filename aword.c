#include "nnsd.h"
// clang-format off
N(ara) {
  if (White(==)) {
    if      (Red(==)    ) { Yellow(=); }
    else if (Yellow(==) ) { Black(=),   Green(=); }
    else if (Green(==)  ) { Yellow(=),  Black(=); }
  } else if (Green(==)  ) { White(=); }
  X;
}
N(da) {
  if (White(==)) {
    if      (Yellow(==) ) { Black(=), Green(=); }
    else if (Green(==)  ) { Yellow(=); }
  } else if (Green(==)  ) { White(=); }
  X;
}
N(an) {
  if (White(==)) {
    if      (Blue(==)   ) { Yellow(=); }
    else if (Yellow(==) ) { Black(=),   Green(=); }
    else if (Green(==)  ) { Yellow(=),  Black(=); }
  } else if (Green(==)  ) { White(=); }
  X;
}
// clang-format on
#include "evalmap.h"
#define TS(...) EVAL32(MAP(T, __VA_ARGS__))
#define Text(...) ((text_t[]){TS(__VA_ARGS__)} + 1)
void gut_rotate(float theta);
N(rotate) { gut_rotate(ω[δ].f), X; }
// clang-format off
int gut_close_requested();
void gut_line_to(long, long, const char *);
#include<stdio.h>
N(t) {
  if (gut_close_requested())
    return;
  gut_line_to(ρ, δ, ω[1].cs);
  X;
}
#define AWgoto(color)                                                          \
  N(goto_##color) {                                                            \
    if (Green(==))                                                             \
      White(=), color(=);                                                      \
    X;                                                                         \
  }
AWgoto(Blue) AWgoto(Red) AWgoto(Green) AWgoto(Yellow);
// clang-format off
// clang-format on
void gut_init(int screenwidth, int screenheight, int pixelwidth,
              int pixelheight, int basex, int basey, int dx, int dy, long fps);
void gut_clear();

#include <stdio.h>
// clang-format off
N(one) { if (Black(==) && Green(==)) ο[α++].q = 1; X; }
N(seven) { if (Black(==) && Green(==)) ο[α++].q = 7; X; }
N(add) {
  if (White(==) && Green(==)) {
    long sum = 0;
    while (128 < α)
      sum += ο[--α].q;
    ο[α++].q = sum;
  }
  X;
}
N(print) {
  if (White(==) && Green(==)) {
    for (long i = 128; i < α; i++)
      printf("%ld ", ο[i].q);
    printf("\nα:%ld\n", α);
    α = 128;
  }
  X;
}
N(b) { White(=), X; }
N(o) {
  if        (Yellow(==) ) { Green(=); }
  else if   (Green(==)  ) { Yellow(=); }
  Black(=), X;
}
N(id) { X; }
// clang-format off
N(A) {X;}
N(B) {X;}
N(C) {X;}
N(D) {X;}
N(E) {X;}
N(F) {X;}

#include<string.h>
#define AWord(name, ...) N(name) {if(White(==)&&Green(==)) {__VA_ARGS__;} X;}
#define AName(name, ...) N(name) {if(Black(==)&&Green(==)) {__VA_ARGS__;} X;}

N(aw_match) { if(White(==) && Green(==)) {
} X; }
#define Match(value)  {.q=0},{.c=aw_match},{.cs=value}, {.q=0},{.c=t},{.cs=value},

N(aw_string) { if(Black(==) && Green(==)) {
  ο[α++].cs = ω[1].cs, ο[α++].q = strlen(ω[1].cs);
} X; }
#define String(value) {.q=0},{.c=aw_string},{.cs=value}, {.q=0},{.c=t},{.cs=value},

N(aw_long) { if(Black(==) && Green(==)) {
  ο[α++].q = ω[1].q;
} X; }
#define Long(value)   {.q=0},{.c=aw_long},{.q=value}, {.q=0},{.c=t},{.cs="aw_long"},

N(debug) { printf("τ(%ld)α(%ld)β(%ld)σ(%ld)\n", τ, α, β, σ), X; }
N(tab) { if(White(==)&&Green(==)) ο[σ++].q = α; X;}
N(untab) { if(White(==)&&Green(==)) α = ο[--σ].q; X;}
AWord(go_Red, Red(=))
AWord(go_Blue, Blue(=))

NNSD(S)
//(TS(D,D,D,D))(TS(A,A,A,A))
(TS(E,E,ara, E,E))(TS(B,B, go_Red,B,B))
//(TS(F,F,F,F))(TS(C,C,C,C))
  ;
text_t *ω = (text_t[]){
  T(b)
  //String("bao") Long(0) T(tab)
  TS(A,B,C,D)
  T(S)
  TS(A,B,C,ara, D)
  T(o)
} + 1;
int main(int argc, char **argv) {
  text_t ο[128 * 4];
  long τ = 0, α = 128, β = 256, ρ = 3, δ = 1, σ = 384;
  gut_init(200, 200, // screen(w,h)
           4, 4,     // pixel(w,h)
           100, 2, // base(x,y)
           0, 1,     // direction(x,y)
           77         // fps
           ),
      X, gut_clear();
  return 0;
}
//text_t *ω = Text(b,
//                  one, one, one, add, one, da, print,
//                  da, add, one, one, one, da, print,
//                  da, seven, print,
//                  o);
// clang-format on
