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
/*  Focus on walk, walk with cpu, into the words, walk step by step,
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
  /* Input m_random, five, m_sub, and m_dot, plus bias. We don't have an easy way to write sentences. We found a typewriter called Underwood under a tree, so we need a way to type to write sentences. How do we define types? We can use a macro or a parser. Let's observe the fact that we're using a parser in any case; we're not writing binary code directly, but using a C language compiler to transform our writing into binary. Writing our own parser/interpreter is a good idea! We don't have a root model that includes roots. We have an actionable sentence, which is a group of actionable words continuously laid in memory, one after another. It begins with a special actionable word "b" for short and ends with a dot "o." We can load and store it simply with a copy operation. The good thing is that actionable words are wholly self-contained; they require their dependencies explicitly and only through gates. So when we load an actionable sentence in memory, we need to give it all its dependencies by calling a Purple ray, or we can have the idea of a pith, which will be a fixed parameter and will represent the outside world for the actionable sentence. The best way to start the execution of an actionable word will be just to start it. So we will take the pith as a parameter to access the outside world, i.e., roots. We have used the word "root" in our definition, so let's define it now. All we have is an actionable word that starts with "b" and ends with "o," so the root can be a mirrored representation of it. Another thing is that execution flows from "b" to "o" and from "o" to "b"; in other words, it is in a perfect loop. Let's say the actionable sentence is composed from "b" to "o," and the root from "o" to "b." Then we can follow the flow from "b" to "o" and go in root form "o" to "b," which will turn the flow back to "o," and it may never reach "o" and turn back to "b." So let it be "b" in the center. In this case, we can flow in from any end of this star of sentences. Let's start flowing from "o." We can't go towards "b" in the Fuchsia ray. We may meet another "o" in the way, so we can flow into it. This means we are going into another sentence, and we can push the text index to mark the fact that we skipped going into the sentence we left behind, or we can go in right away and then...
     T(Yellow, FC_const, Red, Green, Blue, "m", "m", "m", Navy, FC_forward, Maroon, Fuchsia, Olive);
  */
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
N(wheel) {
  T(Lime, Fuchsia, Maroon, Olive, Navy, "o", "o", "o", 0,    0,     0,   0,      0);
  T(0,    0,       0,      0,     0,    "b", "b", "b", Blue, Green, Red, Purple, Yellow);
}
N(branches);
int main() {
  long α = 512, β = α;
  void *ο[α + β];
  long σ = α;
  ti_init(β + 7, α, β, ο, σ);
  wheel(β + 7, α, β, ο, σ);
  branches(β + 7, α, β, ο, σ);
  return 0;
}
N(branches) {
  To, Tm, T_Green_ret; long L1 = β + 7;
  To, Tm, T_Lime_ret;  long R1 = β + 7;
  To, Tm, T_Green_ret; long L2 = β + 7;
  To, Tm, T_Lime_ret;  long R2 = β + 7;
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
}
