#include "aword.h"
#include <stdio.h>
#include <unistd.h>
void ti(Args, long ray);
long tindex;
#define OS(tin, value)                                                         \
  (tindex = tin), (ο[(tindex) + 512].v = #value), (ο[tindex].v = value)
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
N(DarkYellow) { P, ti(τ + 9, α, β, ο, σ, τ + 5); } // τ   -4+5
N(DarkRed   ) { P, ti(τ + 9, α, β, ο, σ, τ + 6); } // τ   -3+6
N(DarkGreen ) { P, ti(τ + 9, α, β, ο, σ, τ + 7); } // τ   -2+7
N(DarkBlue  ) { P, ti(τ + 9, α, β, ο, σ, τ + 8); } // τ   -1+8
N(Purple    ) { P, ti(τ + 9, α, β, ο, σ, τ + 9); } // ττττ 0±9
N(Blue      ) { P, ti(τ - 9, α, β, ο, σ, τ - 8); } // τ   +1-8
N(Green     ) { P, ti(τ - 9, α, β, ο, σ, τ - 7); } // τ   +2-7
N(Red       ) { P, ti(τ - 9, α, β, ο, σ, τ - 6); } // τ   +3-6
N(Yellow    ) { P, ti(τ - 9, α, β, ο, σ, τ - 5); } // τ   +4-5
//DarkYellow                                           τ   +5-4
//DarkRed                                              τ   +6-3
//DarkGreen                                            τ   +7-2
//DarkBlue                                             τ   +8-1
//Purple                                               ττττ+9 0 
N(grow      ) { ο[α].c(τ, α + 1, β, ο, σ); }
#define TAB(name, A4,A3,A2,A1,T,B1,B2,B3,B4) \
  OS(σ++, A4), OS(σ++, A3), OS(σ++, A2), OS(σ++, A1),\
  OS(τ=σ++, T),\
  OS(σ++, B1), OS(σ++, B2), OS(σ++, B3), OS(σ++, B4), ο[512+τ].v = #name
N(tab) {
  TAB(tab,
      Yellow, Red,   Green, Blue,
      Purple,
      Blue,   Green, Red,   Yellow);
  Yellow(τ, α, β, ο, σ);
}
N(dot) {
  TAB(dot,
      0,
      0,
      0,
      0,
      Purple,
      DarkBlue,
      DarkYellow,
      DarkRed,
      DarkGreen);
  grow(τ, α, β, ο, σ);
}
N(toti) {
  TAB(toti,
      dot,
      Red,
      Green,
      Blue,
      Purple,
      Blue,
      Green,
      Red,
      Yellow);
  Yellow(τ, α, β, ο, σ);
}
N(word) {
  TAB(word,
      DarkYellow,
      DarkRed,
      DarkGreen,
      DarkBlue,
      Purple,
      Blue,
      Green,
      Red,
      Yellow);
  grow(τ, α, β, ο, σ);
}
void ti_init();
int main() {
  base_t ο[1024];
  long σ = 0, τ = 0, α = 512, β = 0;
  OS(--α, tab);
  OS(--α, word);
  OS(--α, toti);
  OS(--α, word);
  OS(--α, dot);
  ti_init(), grow(τ, α, β, ο, σ);
  return 0;
}
