#include "aword.h"
#include "P.h"
// clang-format off
//                                                                  ττττ+11
//Navy                                                              τ   +10
//Lime                                                              τ    +9
//Maroon                                                            τ    +8
//Fuchsia                                                           τ    +7
//Olive                                                             τ    +6
N(Yellow  ) { P(Yellow ),((n_t*)ο)[τ + 6](τ + 11, α, β, ο, σ); } // τ    +5
N(Purple  ) { P(Purple ),((n_t*)ο)[τ + 7](τ + 11, α, β, ο, σ); } // τ    +4
N(Red     ) { P(Red    ),((n_t*)ο)[τ + 8](τ + 11, α, β, ο, σ); } // τ    +3
N(Green   ) { P(Green  ),((n_t*)ο)[τ + 9](τ + 11, α, β, ο, σ); } // τ    +2
N(Blue    ) { P(Blue   ),((n_t*)ο)[τ +10](τ + 11, α, β, ο, σ); } // τ    +1
                                                              // ττττ ±0
N(Navy    ) { P(Navy   ),((n_t*)ο)[τ -10](τ - 11, α, β, ο, σ); } // τ    -1
N(Lime    ) { P(Lime   ),((n_t*)ο)[τ - 9](τ - 11, α, β, ο, σ); } // τ    -2
N(Maroon  ) { P(Maroon ),((n_t*)ο)[τ - 8](τ - 11, α, β, ο, σ); } // τ    -3
N(Fuchsia ) { P(Fuchsia),((n_t*)ο)[τ - 7](τ - 11, α, β, ο, σ); } // τ    -4
N(Olive   ) { P(Olive  ),((n_t*)ο)[τ - 6](τ - 11, α, β, ο, σ); } // τ    -5
//Yellow                                                            τ    -6
//Purple                                                            τ    -7
//Red                                                               τ    -8
//Green                                                             τ    -9
//Blue                                                              τ   -10
//                                                                  ττττ-11
// assert width > 1
//
#define T(Yellow,Purple,Red,Green,Blue, zero, Navy, Lime, Maroon, Fuchsia, Olive) \
  ο[--β] = Olive,                                                                 \
  ο[--β] = Fuchsia,                                                               \
  ο[--β] = Maroon,                                                                \
  ο[--β] = Lime,                                                                  \
  ο[--β] = Navy,                                                                  \
  ο[--β] = (void*)zero, NAME(β, #zero),                                           \
  ο[--β] = Blue,                                                                  \
  ο[--β] = Green,                                                                 \
  ο[--β] = Red,                                                                   \
  ο[--β] = Purple,                                                                \
  ο[--β] = Yellow
#define GEN(Yellow)                                                               \
  N(Yellow##_goto) {                 P(goto),Yellow((long)ο[τ]+τ,α,β,ο,σ); }    \
  N(Yellow##_call) { ο[σ] = (void*)τ,P(call),Yellow((long)ο[τ  ],α,β,ο,σ+1); }    \
  N(Yellow##_ret ) {                 P(ret ),Yellow((long)ο[σ-1],α,β,ο,σ-1); }          
GEN(Yellow)GEN(Purple )GEN(Red   )GEN(Green)GEN(Blue)
GEN(Olive )GEN(Fuchsia)GEN(Maroon)GEN(Lime )GEN(Navy)
// Focus on walk, walk with cpu, into the words, walk step by step,
// walk to understand, and lay down perfect path, we have anything we need
// to do so, we have T The unit of composition. lets make perfect parser,
// perfect multitasking mechanism, perfect time machine, perfect i.e.
// lets understand pith of those things. time works inside out,
// time moves in time and time defines itself. it is recursive,
// some kind of perfect loop definig itself. well we have the
// loop we need to play, to experiment, to have fun and not worry.
//
//  α  β                                   ο   σ 
//  ωωω₅₄₃₂₁s₁₂₃₄₅₅₄₃₂₁m₁₂₃₄₅₅₄₃₂₁d₁₂₃₄₅ωωω0www
//                     |
//                     |
//                     |
void ti_init(Args);

int main() {
  // TODO: define way to put stack for connecting branches into the pith with words.
  long α = 512, β = α;
  void *ο[α + β];
  long σ = α;

  T(Lime,  Fuchsia,Maroon,Olive,Navy,"Co",0,    0,    0,      0,           0);
  T(Yellow,Purple, Red,   Green,Blue,"Cm",Navy, Lime, Maroon, Fuchsia, Olive);
  T(0,     0,      0,     0,    0,   "Cb",Blue, Green,Red,    Purple,  Green_ret);
  long C = β + 5;

  //ti_init(τ, α, β, ο, σ);
  
  T(Lime,   Fuchsia, Maroon, Olive,      Navy, "o",  0,    0,     0,      0,       0);
  T(Yellow, Purple,  Red,    Green,      Blue, "m",  Navy, Lime,  Maroon, Fuchsia, Olive);
  T(Yellow, Purple,  Red,    Green_call, Blue,  C,   Navy, Lime,  Maroon, Fuchsia, Olive);
  T(Yellow, Purple,  Red,    Green,      Blue, "b",  Blue, Green, Red,    Purple,  Yellow);
  Yellow(β + 5, α, β, ο, σ);
  return 0;
}
/* 
  _____awww.wwws_____
  _____awww.wwws_____ */
