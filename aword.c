#include "aword.h"
#include <stdio.h>
#include <unistd.h>
void ti(Args, long ray);
// clang-format off
//                                               ττττ-11
//Navy                                           τ   -10
//Lime                                           τ    -9
//Maroon                                         τ    -8
//Fuchsia                                        τ    -7
//Olive                                          τ    -6
N(Yellow  ) { ti(τ +11, α, β, ο, σ, τ + 6); } // τ    -5
N(Purple  ) { ti(τ +11, α, β, ο, σ, τ + 7); } // τ    -4
N(Red     ) { ti(τ +11, α, β, ο, σ, τ + 8); } // τ    -3
N(Green   ) { ti(τ +11, α, β, ο, σ, τ + 9); } // τ    -2
N(Blue    ) { ti(τ +11, α, β, ο, σ, τ +10); } // τ    -1
                                              // ττττ ±0
N(Navy    ) { ti(τ -11, α, β, ο, σ, τ -10); } // τ    +1
N(Lime    ) { ti(τ -11, α, β, ο, σ, τ - 9); } // τ    +2
N(Maroon  ) { ti(τ -11, α, β, ο, σ, τ - 8); } // τ    +3
N(Fuchsia ) { ti(τ -11, α, β, ο, σ, τ - 7); } // τ    +4
N(Olive   ) { ti(τ -11, α, β, ο, σ, τ - 6); } // τ    +5
//Yellow                                         τ    +6
//Purple                                         τ    +7
//Red                                            τ    +8
//Green                                          τ    +9
//Blue                                           τ   +10
//                                               ττττ+11
// assert width > 1
#define TAB(Yellow, Purple, Red, Green, Blue, name, Navy, Lime, Maroon, Fuchsia, Olive) \
  ο[α] = Yellow,  ο[α] = Yellow,  ο[α] = Yellow,  ο[α] = Yellow,  ο[α++] = Yellow,                                                                    \
  ο[α] = Purple,  ο[α] = Purple,  ο[α] = Purple,  ο[α] = Purple,  ο[α++] = Purple,                                                                    \
  ο[α] = Red,     ο[α] = Red,     ο[α] = Red,     ο[α] = Red,     ο[α++] = Red,                                                                       \
  ο[α] = Green,   ο[α] = Green,   ο[α] = Green,   ο[α] = Green,   ο[α++] = Green,                                                                     \
  ο[α] = Blue,    ο[α] = Blue,    ο[α] = Blue,    ο[α] = Blue,    ο[α++] = Blue,                                                                      \
  ο[τ=α]=name,    ο[τ=α]=name,    ο[τ=α]=name,    ο[τ=α]=name,    ο[τ=α++]=name,                                                                  \
  ο[α] = Navy,    ο[α] = Navy,    ο[α] = Navy,    ο[α] = Navy,    ο[α++] = Navy,                                                                      \
  ο[α] = Lime,    ο[α] = Lime,    ο[α] = Lime,    ο[α] = Lime,    ο[α++] = Lime,                                                                      \
  ο[α] = Maroon,  ο[α] = Maroon,  ο[α] = Maroon,  ο[α] = Maroon,  ο[α++] = Maroon,                                                                    \
  ο[α] = Fuchsia, ο[α] = Fuchsia, ο[α] = Fuchsia, ο[α] = Fuchsia, ο[α++] = Fuchsia,                                                                   \
  ο[α] = Olive,   ο[α] = Olive,   ο[α] = Olive,   ο[α] = Olive,   ο[α++] = Olive
#define ST      TAB(Yellow, Purple,   Red,    Green,  Blue, "S",  Blue, Green,Red,    Yellow,  Purple)
#define WORD(v) TAB(Yellow, Purple,   Red,    Green,  Blue, #v,   Navy, Lime, Maroon, Fuchsia, Olive)
#define AND     TAB(Lime,   Purple,   Red,    Yellow, Blue, "and",Navy, Green,Maroon, Fuchsia, Olive)
#define DOT     TAB(Lime,   Fuchsia,  Maroon, Olive,  Navy, "dot",0,    0,    0,      0,       0)
void ti_init(Args);
#define ALIGN(O, A) (((unsigned long)(((O) + ((A) - 1)) / (A))) * (A))
// bnnnbooobooo
// booo
int main() {
  long τ = 0, α = 0, β = 1024;
  void* ο[β], *σ = 0;
  ti_init(τ, α, β, ο, σ);
  ST;
  WORD("love");
  AND;
  WORD("live");
  DOT;
  Fuchsia(τ, α, β, ο, σ);
  return 0;
}
