#include "aword.h"
void ti(Args, long ray);
// clang-format off
//                                                 ττττ+11
//Navy                                             τ   +10
//Lime                                             τ    +9
//Maroon                                           τ    +8
//Fuchsia                                          τ    +7
//Olive                                            τ    +6
N(Yellow  ) { ti(τ + 11, α, β, ο, σ, τ + 6); }  // τ    +5
N(Purple  ) { ti(τ + 11, α, β, ο, σ, τ + 7); }  // τ    +4
N(Red     ) { ti(τ + 11, α, β, ο, σ, τ + 8); }  // τ    +3
N(Green   ) { ti(τ + 11, α, β, ο, σ, τ + 9); }  // τ    +2
N(Blue    ) { ti(τ + 11, α, β, ο, σ, τ +10); }  // τ    +1
                                                // ττττ ±0
N(Navy    ) { ti(τ - 11, α, β, ο, σ, τ -10); }  // τ    -1
N(Lime    ) { ti(τ - 11, α, β, ο, σ, τ - 9); }  // τ    -2
N(Maroon  ) { ti(τ - 11, α, β, ο, σ, τ - 8); }  // τ    -3
N(Fuchsia ) { ti(τ - 11, α, β, ο, σ, τ - 7); }  // τ    -4
N(Olive   ) { ti(τ - 11, α, β, ο, σ, τ - 6); }  // τ    -5
//Yellow                                           τ    -6
//Purple                                           τ    -7
//Red                                              τ    -8
//Green                                            τ    -9
//Blue                                             τ   -10
//                                                 ττττ-11
// assert width > 1
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
  N(Yellow##_call) { β[α] = (void*)τ, Yellow((long)β[τ  ], α+1,β,ο,σ); }   \
  N(Yellow##_ret ) {                  Yellow((long)β[α-1], α-1,β,ο,σ); }          
GEN(Yellow)GEN(Purple )GEN(Red   )GEN(Green)GEN(Blue)
GEN(Olive )GEN(Fuchsia)GEN(Maroon)GEN(Lime )GEN(Navy)
char *names[0x1000];
#ifdef NDEBUG
#define NAME(ο, zero) (void)0
#else
#define NAME(ο, zero) names[ο] = zero
#endif
// Focus on walk, walk with cpu, into the words, step by step to understand,
// and lay down perfect path, we have anything we need to do so, we have T
// The unit of composition. lets make perfect parser, perfect multitasking
// mechanism, perfect time machine, perfect i.e. lets understand pith of those
// things. time works inside out, time moves in time and time defines itself.
// it is recursive, some kind of perfect loop definig itself. well we have the
// loop we need to play, to experiment, to have fun and not worry.
//
//  tabos
//  α   β           ο               τ                σ
//  wwww............_____b__________m__________o_____
//  τ - text index                  o
//  α - stack advance               m 
//  β - base                        b
//  ο - pith                        .
//  σ - size                        w
N(grow) { ((n_t*)β)[α-1](τ, α-1, β, ο, σ); }
N(b   ) {
  T(Yellow, Purple, Red, Green, Blue, b, Blue, Green, Red, Purple, Yellow);
  Yellow(ο + 5, α, β, ο, σ);
}
N(m   ) {
  T(Yellow, Purple, Red, Green, Blue, m, Navy, Lime, Maroon, Fuchsia, Olive);
  grow(τ, α, β, ο, σ);
}
N(o   ) {
  T(Lime, Fuchsia, Maroon, Olive, Navy, o, 0, 0, 0, 0, 0);
  grow(τ, α, β, ο, σ);
}
N(toti   ) {
  T(Yellow_call, Purple_call, Red_call,  Green_call, Blue_call, β[--α], Navy, Lime, Maroon, Fuchsia, Olive);
  grow(τ, α, β, ο, σ);
}
void ti_init(Args);
#define B(...) (__VA_ARGS__, (void*)(ο + 5))
int main() {
  // TODO: define way to put stack for connecting branches into the pith with words.
  long τ = 0, α = 0;
  void *β[512];
  long ο = sizeof(β) / sizeof(*β), σ = ο;
  ti_init(τ, α, β, ο, σ);
  β[α++] = b;
  β[α++] = m;
//  β[α++] =
//  B(T(Olive, Fuchsia,Maroon,Lime, Navy,"tb",0,       0,        0,      0,         0),
//    T(Yellow,Purple, Red,   Green,Blue,"t1",Navy,    Lime,     Maroon, Fuchsia,   Olive),
//    T(Yellow,Purple, Red,   Green,Blue,"t2",Navy,    Lime,     Maroon, Fuchsia,   Olive),
//    T(Yellow,Purple, Red,   Green,Blue,"t3",Navy,    Lime,     Maroon, Fuchsia,   Olive),
//    T(0,     0,      0,     0,    0,   "tr",Blue_ret,Green_ret,Red_ret,Purple_ret,Yellow_ret));
//  β[α++] = toti;
  β[α++] = o;
  grow(τ, α, β, ο, σ);
  return 0;
}
