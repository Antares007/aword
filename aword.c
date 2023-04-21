#include "aword.h"
#include "text_index.h"
#include "P.h"
char *names[0x1000];
// clang-format off
//                                                                   ττττ-13
//                                                                   τ   -12
//Navy                                                               τ   -11
//Lime                                                               τ   -10
//Maroon                                                             τ    -9
//Fuchsia                                                            τ    -8
//Olive                                                              τ    -7
N(Yellow  ) { ti(τ+13,+5,+1),((n_t*)ο)[τ+ 7](τ+13, α, β, ο, σ); } // τ    -6
N(Purple  ) { ti(τ+13,+4,+1),((n_t*)ο)[τ+ 8](τ+13, α, β, ο, σ); } // τ    -5
N(Red     ) { ti(τ+13,+3,+1),((n_t*)ο)[τ+ 9](τ+13, α, β, ο, σ); } // τ    -4
N(Green   ) { ti(τ+13,+2,+1),((n_t*)ο)[τ+10](τ+13, α, β, ο, σ); } // τ    -3
N(Blue    ) { ti(τ+13,+1,+1),((n_t*)ο)[τ+11](τ+13, α, β, ο, σ); } // τ    -2
//                                                                   τ    -1
//                                                                   ττττ ±0
//                                                                   τ    +1
N(Navy    ) { ti(τ-13,-1,-1),((n_t*)ο)[τ-11](τ-13, α, β, ο, σ); } // τ    +2
N(Lime    ) { ti(τ-13,-2,-1),((n_t*)ο)[τ-10](τ-13, α, β, ο, σ); } // τ    +3
N(Maroon  ) { ti(τ-13,-3,-1),((n_t*)ο)[τ- 9](τ-13, α, β, ο, σ); } // τ    +4
N(Fuchsia ) { ti(τ-13,-4,-1),((n_t*)ο)[τ- 8](τ-13, α, β, ο, σ); } // τ    +5
N(Olive   ) { ti(τ-13,-5,-1),((n_t*)ο)[τ- 7](τ-13, α, β, ο, σ); } // τ    +6
//Yellow                                                             τ    +7
//Purple                                                             τ    +8
//Red                                                                τ    +9
//Green                                                              τ   +10
//Blue                                                               τ   +11
//                                                                   τ   +12
//                                                                   ττττ+13
// assert width > 1
//
#define T(Yellow,Purple,Red,Green,Blue, left, zero, right, Navy, Lime, Maroon, Fuchsia, Olive)\
  ο[--β] = Olive,                                                                             \
  ο[--β] = Fuchsia,                                                                           \
  ο[--β] = Maroon,                                                                            \
  ο[--β] = Lime,                                                                              \
  ο[--β] = Navy,                                                                              \
  ο[--β] = (void*)right,NAME(β, #right),                                                      \
  ο[--β] = (void*)zero, NAME(β, #zero),                                                       \
  ο[--β] = (void*)left, NAME(β, #left),                                                       \
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
   lets understand pith of those things. time works inside out,
   time moves in time and time defines itself. it is recursive,
   some kind of perfect loop definig itself. well we have the
   loop we need to play, to experiment, to have fun and not worry.
  
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
N(show) {
  pith_t*p = (pith_t*)(ο+α);
  (void)p->Yellow;
}
#define To          T(Lime,   Fuchsia,Maroon, Olive,      Navy,   "o", "o", "o",  0,    0,            0,      0,       0)
#define Tm          T(Yellow, Purple, Red,    Green,      Blue,   "m", "m", "m",  Navy, Lime,         Maroon, Fuchsia, Olive)
#define T_Green_ret T(0,      0,      0,      0,          0,      "b", "b", "b",  Blue, Green,        Red,    Purple,  Green_ret)
#define T_Lime_ret  T(0,      0,      0,      0,          0,      "b", "b", "b",  Blue, Green,        Red,    Purple,  Lime_ret)
#define TDB(L, R)   T(Yellow, Purple, Red,    Yellow_left,Blue,   L,   "B",  R,   Navy, Yellow_right, Maroon, Fuchsia, Olive)
#define Tb          T(Yellow, Purple, Red,    Green,      Blue,   "b", "b", "b",  Blue, Green,        Red,    Purple,  Yellow)
#define Tnot        T(Lime,   Purple, Yellow, Olive,      Blue,   "N", "O", "T",  Navy, Green,        Maroon, Fuchsia, Olive)
#define Tand        T(Lime,   Purple, Red,    Yellow,     Blue,   "A", "N", "D",  Navy, Green,        Maroon, Fuchsia, Olive)
#define Tor         T(Lime,   Purple, Red,    Olive,      Yellow, " ", "O", "R",  Navy, Green,        Maroon, Fuchsia, Olive)
#define Torand      T(Lime,   Purple, Red,    Yellow,     Yellow, "O", "R", "A",  Navy, Green,        Maroon, Fuchsia, Olive)
int main() {
  long α = 512, β = α;
  void *ο[α + β];
  long σ = α;

  To, Tm, Tand, Tm, T_Green_ret;
  long L = β + 6;

  To, Tm, Tand, Tm, T_Lime_ret;
  long R = β + 6;

  ti_init(β + 6, α, β, ο, σ);
  To, Tm, Tand, Tm, TDB(L, R), Tm, Tand, Tm, Tand, Tm, Tb;
  Yellow(β + 6, α, β, ο, σ); //not
  return 0;
}
