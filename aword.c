#include "aword.h"
#include <stdio.h>
#include <unistd.h>
void ti(Args, long ray);
// clang-format off
//                                                  ττττ-11
//Blue                                              τ   -10
//Green                                             τ    -9
//Red                                               τ    -8
//Purple                                            τ    -7
//Yellow                                            τ    -6
N(Olive   ) { ti(τ +11, α, β, ο, σ, δ, τ + 6); } // τ    -5
N(Fuchsia ) { ti(τ +11, α, β, ο, σ, δ, τ + 7); } // τ    -4
N(Maroon  ) { ti(τ +11, α, β, ο, σ, δ, τ + 8); } // τ    -3
N(Lime    ) { ti(τ +11, α, β, ο, σ, δ, τ + 9); } // τ    -2
N(Navy    ) { ti(τ +11, α, β, ο, σ, δ, τ +10); } // τ    -1
//                                                  ττττ ±0
N(Blue    ) { ti(τ -11, α, β, ο, σ, δ, τ -10); } // τ    +1
N(Green   ) { ti(τ -11, α, β, ο, σ, δ, τ - 9); } // τ    +2
N(Red     ) { ti(τ -11, α, β, ο, σ, δ, τ - 8); } // τ    +3
N(Purple  ) { ti(τ -11, α, β, ο, σ, δ, τ - 7); } // τ    +4
N(Yellow  ) { ti(τ -11, α, β, ο, σ, δ, τ - 6); } // τ    +5
//Olive                                             τ    +6
//Fuchsia                                           τ    +7
//Maroon                                            τ    +8
//Lime                                              τ    +9
//Navy                                              τ   +10
//                                                  ττττ+11
// assert width > 1
#define T(Olive, Fuchsia, Maroon, Lime, Navy, zero, Blue, Green, Red, Purple,  \
          Yellow)                                                              \
  ο[α++] = Olive;                                                              \
  ο[α++] = Fuchsia;                                                            \
  ο[α++] = Maroon;                                                             \
  ο[α++] = Lime;                                                               \
  ο[α++] = Navy;                                                               \
  names[α] = #zero, ο[α++] = zero;                                             \
  ο[α++] = Blue;                                                               \
  ο[α++] = Green;                                                              \
  ο[α++] = Red;                                                                \
  ο[α++] = Purple;                                                             \
  ο[α++] = Yellow
char *names[0x1000];
N(ti_stop);
// focus on walk, walk with cpu, into the words, step by step to understand,
// and lay down perfect path, we have anything we need to do so, we have T
// The unit of composition.
void ti_init(Args);
int main() {
  long τ = 0, α = 0, β = 512;
  void *ο[4 * β];
  void **σ = ο + β;
  ti_init(τ, α, β, ο, σ, "abao");
  T(0, 0, 0, 0, 0,                        "o", Navy, Olive, Maroon, Fuchsia, Lime);
  T(Olive,  Fuchsia, Maroon, Lime,  Navy, "m", Blue, Green, Red,    Purple,  Yellow);
  T(Olive,  Fuchsia, Maroon, Lime,  Navy, "M", Blue, Green, Red,    Purple,  Yellow);
  T(Yellow, Purple,  Red,    Green, Blue, "b", Blue, Green, Red,    Purple,  Yellow);
  Yellow(α - 6, α - 6, β, ο, σ, "");
  return 0;
}
