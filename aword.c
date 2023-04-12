#include "aword.h"
#include <stdio.h>
#include <unistd.h>
void ti(Args, long ray);
long tindex;
#define OS(tin, value)                                                         \
  (tindex = tin), (β[(tindex) + 512].v = #value), (β[tindex].v = value)
// clang-format off
//Purple                                           ττττ+9 0
//Blue                                             τ   +8-1
//Green                                            τ   +7-2
//Red                                              τ   +6-3
//Yellow                                           τ   +5-4
N(DarkYellow) { ti(τ - 9, α, β, ο, σ, τ - 5); } // τ   +4-5
N(DarkRed   ) { ti(τ - 9, α, β, ο, σ, τ - 6); } // τ   +3-6
N(DarkGreen ) { ti(τ - 9, α, β, ο, σ, τ - 7); } // τ   +2-7
N(DarkBlue  ) { ti(τ - 9, α, β, ο, σ, τ - 8); } // τ   +1-8
N(Purple    ) { ti(τ - 9, α, β, ο, σ, τ - 9); } // ττττ 0±9
N(Blue      ) { ti(τ + 9, α, β, ο, σ, τ + 8); } // τ   -1+8
N(Green     ) { ti(τ + 9, α, β, ο, σ, τ + 7); } // τ   -2+7
N(Red       ) { ti(τ + 9, α, β, ο, σ, τ + 6); } // τ   -3+6
N(Yellow    ) { ti(τ + 9, α, β, ο, σ, τ + 5); } // τ   -4+5
//DarkYellow                                       τ   -5+4
//DarkRed                                          τ   -6+3
//DarkGreen                                        τ   -7+2
//DarkBlue                                         τ   -8+1
//Purple                                           ττττ-9 0
// clang-format on
N(grow) { β[α - 1].c(τ, α - 1, β, ο, σ); }
#define TAB(Yellow, Red, Green, Blue, name, DarkBlue, DarkGreen, DarkRed,      \
            DarkYellow)                                                        \
  β[ο - 1].v = DarkYellow;                                                     \
  β[ο - 2].v = DarkRed;                                                        \
  β[ο - 3].v = DarkGreen;                                                      \
  β[ο - 4].v = DarkBlue;                                                       \
  β[τ = ο - 5].v = Purple, β[τ + 512].v = #name;                               \
  β[ο - 6].v = Blue;                                                           \
  β[ο - 7].v = Green;                                                          \
  β[ο - 8].v = Red;                                                            \
  β[ο - 9].v = Yellow;                                                         \
  ο -= 9
N(tab) {
  TAB(Yellow, Red, Green, Blue, //
      tab,                      //
      Blue, Green, Red, Yellow);
  Yellow(τ, α, β, ο, σ);
}
N(dot) {
  TAB(DarkGreen, DarkRed, DarkYellow, DarkBlue, //
      dot,                                      //
      0, 0, 0, 0);
  grow(τ, α, β, ο, σ);
}
N(word) {
  TAB(Yellow, Red, Green, Blue, //
      word,                     //
      DarkBlue, DarkGreen, DarkRed, DarkYellow);
  grow(τ, α, β, ο, σ);
}
N(toti) {
  TAB(Yellow, Red, Green, Blue, //
      toti,                     //
      Blue, Green, Red, dot);
  Yellow(τ, α, β, ο, σ);
}
N(and) {
  TAB(DarkGreen, Red, Yellow, Blue, //
      and,                          //
      DarkBlue, Green, DarkRed, DarkYellow);
  grow(τ, α, β, ο, σ);
}
void ti_init();
N(S) {
  OS(α++, tab);
  OS(α++, S);
  OS(α++, toti);
  OS(α++, word);
  OS(α++, toti);
  OS(α++, word);
  OS(α++, and);
  OS(α++, word);
  OS(α++, dot);
  grow(τ, α, β, ο, σ);
}
int main() {
  long τ = 0, α = 0;
  base_t β[1024];
  long ο = 512, σ = ο;
  OS(α++, S);
  ti_init(), grow(τ, α, β, ο, σ);
  return 0;
}
