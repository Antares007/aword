#include "aword.h"
#include "P.h"
N(grow) { ((n_t *)β)[α - 1](τ, α - 1, β, ο, σ); }
// clang-format off
//                                                                  ττττ+11
//Navy                                                              τ   +10
//Lime                                                              τ    +9
//Maroon                                                            τ    +8
//Fuchsia                                                           τ    +7
//Olive                                                             τ    +6
N(Yellow  ) { P(Yellow ),((n_t*)β)[τ + 6](τ + 11, α, β, ο, σ); } // τ    +5
N(Purple  ) { P(Purple ),((n_t*)β)[τ + 7](τ + 11, α, β, ο, σ); } // τ    +4
N(Red     ) { P(Red    ),((n_t*)β)[τ + 8](τ + 11, α, β, ο, σ); } // τ    +3
N(Green   ) { P(Green  ),((n_t*)β)[τ + 9](τ + 11, α, β, ο, σ); } // τ    +2
N(Blue    ) { P(Blue   ),((n_t*)β)[τ +10](τ + 11, α, β, ο, σ); } // τ    +1
                                                                 // ττττ ±0
N(Navy    ) { P(Navy   ),((n_t*)β)[τ -10](τ - 11, α, β, ο, σ); } // τ    -1
N(Lime    ) { P(Lime   ),((n_t*)β)[τ - 9](τ - 11, α, β, ο, σ); } // τ    -2
N(Maroon  ) { P(Maroon ),((n_t*)β)[τ - 8](τ - 11, α, β, ο, σ); } // τ    -3
N(Fuchsia ) { P(Fuchsia),((n_t*)β)[τ - 7](τ - 11, α, β, ο, σ); } // τ    -4
N(Olive   ) { P(Olive  ),((n_t*)β)[τ - 6](τ - 11, α, β, ο, σ); } // τ    -5
//Yellow                                                            τ    -6
//Purple                                                            τ    -7
//Red                                                               τ    -8
//Green                                                             τ    -9
//Blue                                                              τ   -10
//                                                                  ττττ-11
// assert width > 1
//
#define T(Yellow,Purple,Red,Green,Blue, zero, Navy, Lime, Maroon, Fuchsia, Olive) \
  β[--ο] = Olive,                                                                 \
  β[--ο] = Fuchsia,                                                               \
  β[--ο] = Maroon,                                                                \
  β[--ο] = Lime,                                                                  \
  β[--ο] = Navy,                                                                  \
  β[--ο] = (void*)zero, NAME(ο, #zero),                                           \
  β[--ο] = Blue,                                                                  \
  β[--ο] = Green,                                                                 \
  β[--ο] = Red,                                                                   \
  β[--ο] = Purple,                                                                \
  β[--ο] = Yellow
#define GEN(Yellow)                                                               \
  N(Yellow##_goto) {                 P(goto),Yellow((long)β[τ]+τ,α,  β,ο,σ); }    \
  N(Yellow##_call) { β[α] = (void*)τ,P(call),Yellow((long)β[τ  ],α+1,β,ο,σ); }    \
  N(Yellow##_ret ) {                 P(ret ),Yellow((long)β[α-1],α-1,β,ο,σ); }          
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
//  tabos
//  β   α           ο               τ                σ
//  wwww............_____b__________m__________o_____
//  τ - text index                  o
//  α - stack advance               m 
//  β - base                        b
//  ο - pith                        .
//  σ - size                        w
#define B(...) (({                                              \
  T(Lime,     Fuchsia,  Maroon,     Olive,       Navy,  "b_o",  \
    Navy_goto,Lime_goto,Maroon_goto,Fuchsia_goto,Olive_goto);   \
  long bτ = ο+5;                                                \
  __VA_ARGS__,                                                  \
  T(Yellow_goto,Purple_goto,Red_goto,Green_goto,Blue_goto,"b_b",\
    Blue,       Green,      Red,     Purple,    Yellow);        \
  β[bτ]    = (void*)((ο + 5) - bτ);                             \
  β[ο + 5] = (void*)(bτ - (ο + 5)); }), (void*)(ο + 5))
void ti_init(Args);
int main() {
  // TODO: define way to put stack for connecting branches into the pith with words.
  long τ = 0, α = 0;
  void *β[512];
  long ο = sizeof(β) / sizeof(*β), σ = ο;
  //ti_init(τ, α, β, ο, σ);
  T(Lime, Fuchsia, Maroon, Olive, Navy, "o", 0, 0, 0, 0, 0);
  long bark =(long)
    B(T(Yellow,Purple,Red,Green,Blue, "t1",Navy,    Lime, Maroon, Fuchsia,   Olive)
     //,T(Yellow,Purple,Red,Green,Blue, "tr",Blue_ret,Lime, Red_ret,Purple_ret,Yellow_ret)
      );
//  T(Yellow, Purple_call,Red_call,Green_call,Blue_call,bark,Navy,Lime,Maroon,Fuchsia,Olive);
  T(Yellow, Purple, Red, Green, Blue, "m", Navy, Lime, Maroon, Fuchsia, Olive);
  T(Yellow, Purple, Red, Green, Blue, "b", Blue, Green, Red, Purple, Yellow);
  Yellow(ο+5,α,β,ο,σ);
  return 0;
}
// _____awww.wwws_____
// _____awww.wwws_____
