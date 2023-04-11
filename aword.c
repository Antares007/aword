#include "aword.h"
#include <stdio.h>
#include <unistd.h>
void ti(Args, long ray);
long tindex;
#define OS(tin, value)                                                         \
  (tindex = tin), (β[(tindex) + 512].v = #value), (β[tindex].v = value)
// clang-format off
//Purple                                           ττττ-9 0
//DarkBlue                                         τ   -8+1
//DarkGreen                                        τ   -7+2
//DarkRed                                          τ   -6+3
//DarkYellow                                       τ   -5+4
N(Yellow    ) { ti(τ + 9, α, β, ο, σ, τ + 5); } // τ   -4+5
N(Red       ) { ti(τ + 9, α, β, ο, σ, τ + 6); } // τ   -3+6
N(Green     ) { ti(τ + 9, α, β, ο, σ, τ + 7); } // τ   -2+7
N(Blue      ) { ti(τ + 9, α, β, ο, σ, τ + 8); } // τ   -1+8
N(Purple    ) { ti(τ + 9, α, β, ο, σ, τ + 9); } // ττττ 0±9
N(DarkBlue  ) { ti(τ - 9, α, β, ο, σ, τ - 8); } // τ   +1-8
N(DarkGreen ) { ti(τ - 9, α, β, ο, σ, τ - 7); } // τ   +2-7
N(DarkRed   ) { ti(τ - 9, α, β, ο, σ, τ - 6); } // τ   +3-6
N(DarkYellow) { ti(τ - 9, α, β, ο, σ, τ - 5); } // τ   +4-5
//Yellow                                           τ   +5-4
//Red                                              τ   +6-3
//Green                                            τ   +7-2
//Blue                                             τ   +8-1
//Purple                                           ττττ+9 0 
N(grow      ) { β[α - 1].c(τ, α - 1, β, ο, σ); }
#define TAB(name, A4,A3,A2,A1,T,B1,B2,B3,B4)          \
  OS(--ο, A4), OS(--ο, A3), OS(--ο, A2), OS(--ο, A1), \
  OS(τ=--ο, T),                                       \
  OS(--ο, B1), OS(--ο, B2), OS(--ο, B3), OS(--ο, B4), β[512+τ].v = #name
N(tab) {
  TAB(tab,
      Yellow,
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
      DarkGreen
      );
  grow(τ, α, β, ο, σ);
}
N(toti) {
  TAB(toti,
      dot,
      Red,
      Green,
      Blue,
      Purple,
      DarkBlue,
      DarkYellow,
      DarkRed,
      DarkGreen
      );
  Yellow(τ, α, β, ο, σ);
}
N(and) {
  TAB(and, 
      DarkYellow,
      DarkRed,
      Green,
      DarkBlue,
      Purple,
      Blue,
      Yellow,
      Red,
      DarkGreen);
  grow(τ, α, β, ο, σ);
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
      Yellow
      );
  grow(τ, α, β, ο, σ);
}
void ti_init();
int main() {
  long τ = 0, α = 0;
  base_t β[1024];
  long ο = 512, σ = ο;
  OS(α++, tab);
  OS(α++, word);
  OS(α++, toti);
  OS(α++, word);
  OS(α++, toti);
  OS(α++, word);
  OS(α++, word);
  OS(α++, dot);
  ti_init(), grow(τ, α, β, ο, σ);
  return 0;
}
