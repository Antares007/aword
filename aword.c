#include "aword.h"
#include "P.h"
#include "text_index.h"
char *names[0x1000];
// clang-format off
//                                                                   ττττ-15
//                                                                   τ   -14
//                                                                   τ   -13
//Navy                                                               τ   -12
//Lime                                                               τ   -11
//Maroon                                                             τ   -10
//Fuchsia                                                            τ    -9
//Olive                                                              τ    -8
N(Yellow  ) { ti(τ+15,+5,+1),((n_t*)ο)[τ+ 8](τ+15, α, β, ο, σ); } // τ    -7
N(Purple  ) { ti(τ+15,+4,+1),((n_t*)ο)[τ+ 9](τ+15, α, β, ο, σ); } // τ    -6
N(Red     ) { ti(τ+15,+3,+1),((n_t*)ο)[τ+10](τ+15, α, β, ο, σ); } // τ    -5
N(Green   ) { ti(τ+15,+2,+1),((n_t*)ο)[τ+11](τ+15, α, β, ο, σ); } // τ    -4
N(Blue    ) { ti(τ+15,+1,+1),((n_t*)ο)[τ+12](τ+15, α, β, ο, σ); } // τ    -3
//                                                                   τ    -2
//                                                                   τ    -1
//                                                                   ττττ ±0
//                                                                   τ    +1
//                                                                   τ    +2
N(Navy    ) { ti(τ-15,-1,-1),((n_t*)ο)[τ-12](τ-15, α, β, ο, σ); } // τ    +3
N(Lime    ) { ti(τ-15,-2,-1),((n_t*)ο)[τ-11](τ-15, α, β, ο, σ); } // τ    +4
N(Maroon  ) { ti(τ-15,-3,-1),((n_t*)ο)[τ-10](τ-15, α, β, ο, σ); } // τ    +5
N(Fuchsia ) { ti(τ-15,-4,-1),((n_t*)ο)[τ- 9](τ-15, α, β, ο, σ); } // τ    +6
N(Olive   ) { ti(τ-15,-5,-1),((n_t*)ο)[τ- 8](τ-15, α, β, ο, σ); } // τ    +7
//Yellow                                                             τ    +8
//Purple                                                             τ    +9
//Red                                                                τ   +10
//Green                                                              τ   +11
//Blue                                                               τ   +12
//                                                                   τ   +13
//                                                                   τ   +14
//                                                                   ττττ+15
// assert width > 1
//
#define T(Yellow,Purple,Red,Green,Blue, left, zero, right, Navy, Lime, Maroon, Fuchsia, Olive)\
  ο[--β] = Olive,                                                                             \
  ο[--β] = Fuchsia,                                                                           \
  ο[--β] = Maroon,                                                                            \
  ο[--β] = Lime,                                                                              \
  ο[--β] = Navy,                                                                              \
  ο[--β] = 0,                                                                                 \
  ο[--β] = (void*)right,NAME(β, #right),                                                      \
  ο[--β] = (void*)zero, NAME(β, #zero),                                                       \
  ο[--β] = (void*)left, NAME(β, #left),                                                       \
  ο[--β] = 0,                                                                                 \
  ο[--β] = Blue,                                                                              \
  ο[--β] = Green,                                                                             \
  ο[--β] = Red,                                                                               \
  ο[--β] = Purple,                                                                            \
  ο[--β] = Yellow
#define GEN(Yellow)                                                                  \
  N(Yellow##_goto)  {                              Yellow((long)ο[τ]+τ,α,β,ο,σ);   } \
  N(Yellow##_left)  { ο[σ++]=(void*)τ, ti_left(),  Yellow((long)ο[τ-1],α,β,ο,σ);   } \
  N(Yellow##_right) { ο[σ++]=(void*)τ, ti_right(), Yellow((long)ο[τ+1],α,β,ο,σ);   } \
  N(Yellow##_ret )  {                  ti_ret(),   Yellow((long)ο[σ-1],α,β,ο,σ-1); }
GEN(Yellow)GEN(Purple )GEN(Red   )GEN(Green)GEN(Blue)
GEN(Olive )GEN(Fuchsia)GEN(Maroon)GEN(Lime )GEN(Navy)
/* Focus on walk, walk with cpu, into the words, walk step by step,
   walk to understand, and lay down perfect path, we have anything we need
   to do so, we have T The unit of composition. lets make perfect parser,
   perfect multitasking mechanism, perfect time machine, perfect i.e.
   lets understand pith of those things. time works inside out, time moves
   in time and time defines itself. it is recursive, some kind of perfect
   loop defining itself. well we have the loop we need to play, to experiment,
   to have fun and not worry.
     α          σ
     ωωωωω0ωωωωω

    α  β                                   ο   σ 
    ωωω₅₄₃₂₁s₁₂₃₄₅₅₄₃₂₁m₁₂₃₄₅₅₄₃₂₁d₁₂₃₄₅ωωω0www
                       |
                       |
                       |                                                */
void ti_init(Args);
typedef struct pith_t {
  N((*Yellow));
} pith_t;
#define ALIGN(O, A) ((long)(((O) + ((A) - 1)) / (A))) * (A)
#include<time.h>
#include<stdlib.h>

N(FC_const) {
  long input_size  = (long)ο[τ-1];
  long output_size = (long)ο[τ+1];
  double weights[input_size][output_size];
  double bias[input_size][output_size];
  srand(time(NULL));
  for (int i = 0; i < input_size; i++)
    for (int j = 0; j < output_size; j++) {
      weights[i][j] = ((double)rand() / RAND_MAX) - 0.5;
      bias[1][j]    = ((double)rand() / RAND_MAX) - 0.5;
    }
  ο[τ - 2] = weights;
  ο[τ + 2] = bias;
  Purple(τ, α, β, ο, σ);
}
N(show) {
  // input m_random five m_sub and m_dot and plus bias
  //
  // T(Yellow, FC_const, Red, Green, Blue, "m", "m", "m", Navy, FC_forward, Maroon, Fuchsia, Olive);
}
#define To          T(Lime,   Fuchsia,Maroon, Olive,      Navy,   "o", "o", "o",  0,    0,            0,      0,       0)
#define Tm          T(Yellow, Purple, Red,    Green,      Blue,   "m", "m", "m",  Navy, Lime,         Maroon, Fuchsia, Olive)
#define T_Green_ret T(0,      0,      0,      0,          0,      "b", "b", "b",  Blue, Green,        Red,    Purple,  Green_ret)
#define T_Lime_ret  T(0,      0,      0,      0,          0,      "b", "b", "b",  Blue, Green,        Red,    Purple,  Lime_ret)
#define TDB(L, R)   T(Yellow, Purple, Red,    Yellow_left,Blue,    L,  "B",  R,   Navy, Yellow_right, Maroon, Fuchsia, Olive)
#define Tb          T(Yellow, Purple, Red,    Green,      Blue,   "b", "b", "b",  Blue, Green,        Red,    Purple,  Yellow)

#define Tnot        T(Lime,   Purple, Yellow, Olive,      Blue,   "N", "O", "T",  Navy, Green,        Maroon, Fuchsia, Olive)
#define Tand        T(Lime,   Purple, Red,    Yellow,     Blue,   "A", "N", "D",  Navy, Green,        Maroon, Fuchsia, Olive)
#define Tor         T(Lime,   Purple, Red,    Olive,      Yellow, " ", "O", "R",  Navy, Green,        Maroon, Fuchsia, Olive)
#define Torand      T(Lime,   Purple, Red,    Yellow,     Yellow, "O", "R", "A",  Navy, Green,        Maroon, Fuchsia, Olive)
int main() {
  long α = 512, β = α;
  void *ο[α + β];
  long σ = α;

  To, Tm, T_Green_ret; long L1 = β + 7;
  To, Tm, T_Lime_ret;  long R1 = β + 7;

  To, Tm, T_Green_ret; long L2 = β + 7;
  To, Tm, T_Lime_ret;  long R2 = β + 7;

  ti_init(β + 7, α, β, ο, σ);
                                                To,
                                                Tm,
  T(Yellow, Purple, Red, Yellow_left, Blue, L1, "B", R1, Navy, Yellow_right, Maroon, Fuchsia, Olive);
                                                Tm,
  T(Yellow, Purple, Red, Yellow_left, Blue, L1, "B", R1, Navy, Yellow_right, Maroon, Fuchsia, Olive);
                                                Tm,
  T(Yellow, Purple, Red, Yellow_left, Blue, L1, "B", R1, Navy, Yellow_right, Maroon, Fuchsia, Olive);
                                                Tm,
  T(Yellow, Purple, Red, Yellow_left, Blue, L2, "B", R2, Navy, Yellow_right, Maroon, Fuchsia, Olive);
                                                Tm,
                                                Tb;
  Yellow(β + 7, α, β, ο, σ); //not
  return 0;
}
