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
#define Σ 512
#define TAB(Yellow, Purple, Red, Green, Blue, name, Navy, Lime, Maroon, Fuchsia, Olive) \
  ο[β+α++] = Yellow,                                                                    \
  ο[β+α++] = Purple,                                                                    \
  ο[β+α++] = Red,                                                                       \
  ο[β+α++] = Green,                                                                     \
  ο[β+α++] = Blue,                                                                      \
  ο[β+(τ=α++)]=name,                                                                    \
  ο[β+α++] = Navy,                                                                      \
  ο[β+α++] = Lime,                                                                      \
  ο[β+α++] = Maroon,                                                                    \
  ο[β+α++] = Fuchsia,                                                                   \
  ο[β+α++] = Olive
#define ST      TAB(Yellow, Purple,   Red,    Green,  Blue, "S",  Blue, Green,Red,    Yellow,  Purple)
#define WORD(v) TAB(Yellow, Purple,   Red,    Green,  Blue, #v,   Navy, Lime, Maroon, Fuchsia, Olive)
#define AND     TAB(Lime,   Purple,   Red,    Yellow, Blue, "and",Navy, Green,Maroon, Fuchsia, Olive)
#define DOT     TAB(Lime,   Fuchsia,  Maroon, Olive,  Navy, "dot",0,    0,    0,      0,       0)
N(grow) { ((n_t *)ο)[σ](τ, α, β, ο, σ + 1); }
// clang-format off
N(T) {
  TAB(Yellow,Purple, Red,   Green,Blue,"bT",Blue,Green,Red,   Yellow, grow);
  TAB(Yellow,Purple, Red,   Green,Blue,"mT",Navy,Lime, Maroon,Fuchsia,Olive);
  TAB(Lime,  Fuchsia,Maroon,Olive,Navy,"oT",0,   0,    0,     0,      0);
  Fuchsia(τ, α, β, ο, σ);
}
N(S) {
  TAB(Yellow,Purple, Red,   Green,Blue,"bS",Blue,Green,Red,   Yellow, grow);
  TAB(Yellow,Purple, Red,   Green,Blue,"mS",Navy,Lime, Maroon,Fuchsia,Olive);
  TAB(Lime,  Fuchsia,Maroon,Olive,Navy,"oS",0,   0,    0,     0,      0);
  Fuchsia(τ, α, β, ο, σ);
}
N(A) {
  TAB(Yellow,Purple, Red,   Green,Blue,"bA",Blue,Green,Red,   Yellow, grow);
  TAB(Yellow,Purple, Red,   Green,Blue,"mA",Navy,Lime, Maroon,Fuchsia,Olive);
  TAB(Lime,  Fuchsia,Maroon,Olive,Navy,"oA",0,   0,    0,     0,      0);
  Fuchsia(τ, α, β, ο, σ);
}
// clang-format on
void ti_init(Args);
void ti_close();
#define ALIGN(O, A) (((unsigned long)(((O) + ((A)-1)) / (A))) * (A))
N(stop) {}
int main() {
  long τ = 0, α = 0, β = Σ;
  void *ο[Σ];
  long σ = Σ;
  ti_init(τ, α, β, ο, σ);
  ο[--σ] = stop;
  ο[--σ] = A;
  ο[--σ] = S;
  grow(τ, α, β, ο, σ);
  ti_close();
  return 0;
}
/*Code point ↔ UTF-8 conversion
    First     Last
    code      code
    point	    point	    Byte 1	  Byte 2	  Byte 3
   Byte 4 U+0000    U+007F	  0xxxxxxx U+0080    U+07FF	  110xxxxx
   10xxxxxx U+0800    U+FFFF	  1110xxxx	10xxxxxx	10xxxxxx
    U+10000[b]U+10FFFF	11111xxx	10xxxxxx	10xxxxxx	10xxxxxx
 */
