#include <stdio.h>
#include <unistd.h>
#define P printf("%5s %s\n", (char *)ο[τ].v, __FUNCTION__), usleep(100000)
#define N(argo) void argo(long τ, long σ, long β, struct base_t *ο, long α)
typedef struct base_t {
  union {
    long q;
    void *v;
    N((*c));
  };
} base_t;
typedef N((*n_t));
// clang-format off
//      τ            α         
//   β₀ . ω ω b .w w b          |
//   β₁ . ω ω b .w w b     σ    |
// ο                       . n b|
//   β₂ . ω ω b .w w b          |
//   β₃ . ω ω b .w w b          |
//Purple                                               ττττ-9 0
//Blue                                                 τ   -8+1
//Green                                                τ   -7+2
//Red                                                  τ   -6+3
//Yellow                                               τ   -5+4
N(DarkYellow) { P, ο[τ + 5].c(τ + 9, σ, β, ο, α); } // τ   -4+5
N(DarkRed   ) { P, ο[τ + 6].c(τ + 9, σ, β, ο, α); } // τ   -3+6
N(DarkGreen ) { P, ο[τ + 7].c(τ + 9, σ, β, ο, α); } // τ   -2+7
N(DarkBlue  ) { P, ο[τ + 8].c(τ + 9, σ, β, ο, α); } // τ   -1+8
N(Purple    ) { P, ο[τ + 9].c(τ + 9, σ, β, ο, α); } // ττττ 0+9-
N(Blue      ) { P, ο[τ - 8].c(τ - 9, σ, β, ο, α); } // τ   +1 8-
N(Green     ) { P, ο[τ - 7].c(τ - 9, σ, β, ο, α); } // τ   +2 7-
N(Red       ) { P, ο[τ - 6].c(τ - 9, σ, β, ο, α); } // τ   +3 6-
N(Yellow    ) { P, ο[τ - 5].c(τ - 9, σ, β, ο, α); } // τ   +4 5-
//DarkYellow                                           τ   +5 4-
//DarkRed                                              τ   +6 3-
//DarkGreen                                            τ   +7 2-
//DarkBlue                                             τ   +8 1-
//Purple                                               ττττ+9 0 
N(grow      ) { ο[α].c(τ, σ, β, ο, α + 1); }
N(tab) {
  ο[β*0+σ++].v = Yellow;
  ο[β*0+σ++].v = Red;
  ο[β*0+σ++].v = Green;
  ο[β*0+σ++].v = Blue;
  ο[τ=β*0+σ++].v = "tab0"; ο[  β*1+σ++].v = "tab1"; ο[  β*2+σ++].v = "tab2";
  ο[β*0+σ++].v = Blue;
  ο[β*0+σ++].v = Green;
  ο[β*0+σ++].v = Red;
  ο[β*0+σ++].v = Yellow;
  Yellow(τ, σ, β, ο, α);
}
N(dot) {
  ο[σ++].v =0, ο[σ++].v =0, ο[σ++].v =0, ο[σ++].v =0;
  ο[σ++].v = "dot";
  ο[σ++].v = DarkBlue;
  ο[σ++].v = DarkYellow;
  ο[σ++].v = DarkRed;
  ο[σ++].v = DarkGreen;
  grow(τ, σ, β, ο, α);
}
N(toti) {
  ο[σ++].v = dot;
  ο[σ++].v = Red;
  ο[σ++].v = Green;
  ο[σ++].v = Blue;
  ο[τ = σ++].v = "toti";
  ο[σ++].v = Blue;
  ο[σ++].v = Green;
  ο[σ++].v = Red;
  ο[σ++].v = Yellow;
  Yellow(τ, σ, β, ο, α);
}
N(word) {
  ο[σ++].v = DarkYellow;
  ο[σ++].v = DarkRed;
  ο[σ++].v = DarkGreen;
  ο[σ++].v = DarkBlue;
  ο[σ++].v = "word";
  ο[σ++].v = Blue;
  ο[σ++].v = Green;
  ο[σ++].v = Red;
  ο[σ++].v = Yellow;
  grow(τ, σ, β, ο, α);
}
int main() {
  base_t ο[1024];
  long σ = 0, τ=0, α = sizeof(ο)/sizeof(*ο), β=0;
  ο[--α].v = tab;
  ο[--α].v = word;
  ο[--α].v = toti;
  ο[--α].v = word;
  ο[--α].v = dot;
  grow(τ, σ, β, ο, α);
  return 0;
}
