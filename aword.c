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
void gut_line_to(long δ, long ρ, const char *);
#include<stdio.h>
int gut_draw_frame();
static int stop=1;
#include<stdlib.h>
N(t) {
  if (gut_close_requested())
    return;
  gut_line_to(δ, ρ, ω[1].cs);
  int key = gut_draw_frame();
  if (key == 'd') stop = !stop;
  else if (key == 's') return;
  //if (δ != 1 || ρ != 1) return X;
  if (stop) printf("%2ld %ld  %3ld %3ld %3ld %s\n", δ, ρ, τ, α - 128, σ - 384, ω[1].cs);
  while(key !='n' && stop) {
    if (key == 's') return;
    else if (key == 'r') stop = !stop;
    key = gut_draw_frame();
  };
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

AWord(aw_match, {
  long len = ο[--α].q;
  const char*in = ο[--α].cs;
  long pos = ο[--α].q;
  if (pos<len && in[pos] == ω[1].cs[0]) {
    ο[α++].q  = pos+1;
    ο[α++].cs = in;
    ο[α++].q  = len;
  } else {
    ο[α++].q  = pos;
    ο[α++].cs = in;
    ο[α++].q  = len;
    Blue(=);
  }
});
#define Match(value)  {.q=0},{.c=aw_match},{.cs=value}, {.q=0},{.c=t},{.cs=value},
AName(aw_string, ο[α++].cs = ω[1].cs, ο[α++].q = strlen(ω[1].cs));
#define String(value) {.q=0},{.c=aw_string},{.cs=value}, {.q=0},{.c=t},{.cs=value},
AName(aw_long, ο[α++].q = ω[1].q);
#define Long(value)   {.q=0},{.c=aw_long},{.q=value}, {.q=0},{.c=t},{.cs="aw_long"},
AWord(go_Red, Red(=))
AWord(go_Blue, Blue(=))
AWord(pause, getchar())
AWord(printα, printf("%ld\n", α))
AWord(tab, ο[τ++].q = α)
AWord(untab, α = ο[--τ].q)

                    NNSD3(S)
 (T(D)T(D)T(D)T(D))         (T(A)T(A)T(A)T(A))
 (T(E)T(E)T(E)T(E))         (T(B)T(B)T(B)T(B))
 (T(F)T(F)T(F)T(F))         (T(C)T(C)T(C)T(C))
;

text_t *ω = (text_t[]){
  T(b)
  T(A)
  T(A)
  T(A)
  T(S)
  T(B)
  T(B)
  T(B)
  T(o)
} + 1;
int main(int argc, char **argv) {
  text_t ο[128 * 4];
  long τ = 0, α = 128, β = 256, ρ = 3, δ = 1, σ = 384;
  gut_init(200, 200, // screen(w,h)
           4,   4,   // pixel(w,h)
           100, 10,  // base(x,y)
           0, 1,     // direction(x,y)
           0         // fps
           ),
      X, gut_clear();
  return 0;
}
//AName(one,    ο[α++].q = 1)
//AName(seven,  ο[α++].q = 7)
//AWord(add,    long sum = 0; while (128 < α) sum += ο[--α].q; ο[α++].q = sum)
//AWord(print,  for (long i = 128; i < α; i++)
//                printf("%ld ", ο[i].q);
//              printf("\nα:%ld\n", α);
//              α = 128)
//text_t *ω =   Text(
//              b,
//              one, one, one, add, one, da, print,
//              da, add, one, one, one, da, print,
//              da, seven, print,
//              o);
