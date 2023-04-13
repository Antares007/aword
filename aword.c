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
  ο[β+α+0] = Yellow,                                                                    \
  ο[β+α+1] = Purple,                                                                    \
  ο[β+α+2] = Red,                                                                       \
  ο[β+α+3] = Green,                                                                     \
  ο[β+α+4] = Blue,                                                                      \
  ο[β+(τ=α+5)]=name,                                                                  \
  ο[β+α+6] = Navy,                                                                      \
  ο[β+α+7] = Lime,                                                                      \
  ο[β+α+8] = Maroon,                                                                    \
  ο[β+α+9] = Fuchsia,                                                                   \
  ο[β+α+10] = Olive
#define ST      TAB(Yellow, Purple,   Red,    Green,  Blue, "S",  Blue, Green,Red,    Yellow,  Purple)
#define WORD(v) TAB(Yellow, Purple,   Red,    Green,  Blue, #v,   Navy, Lime, Maroon, Fuchsia, Olive)
#define AND     TAB(Lime,   Purple,   Red,    Yellow, Blue, "and",Navy, Green,Maroon, Fuchsia, Olive)
#define DOT     TAB(Lime,   Fuchsia,  Maroon, Olive,  Navy, "dot",0,    0,    0,      0,       0)

#define Tnxt TAB(Yellow, Purple, Stop, Stop, Stop, "nxt", Blue, Green, Red, nxt, Purple)
N(nxt) { ((n_t*)ο)[τ - 5](τ, α, β+Σ, ο, σ);}
#define Tcnt TAB(Lime, Yellowβ0,  Maroon, Olive,  Navy, "cnt", Stop, Stop, Stop, Stop, Stop)
N(Yellowβ0) { Yellow(τ, α, 0, ο, σ);}
#define Tend TAB(Yellow, Stop, Stop, Stop, Stop, "end", Blue, Green, Red, Stop, Purple)

#define Ttop TAB(Yellow, Stop, Stop, Stop, Stop, "top", Blue, Green, Red, Fuchsiaβ0, Purple)
N(Fuchsiaβ0) { Fuchsia(τ, α, 0, ο, σ);}

#define Tbot TAB(Lime,  Purple,  Maroon, Olive,  Navy, 0, Stop, Stop, Stop, bot, Stop)
N(bot) { β = (long)ο[τ]; ο[τ]=(void*)((β + 512) % 2048);Fuchsia(τ, α, β, ο, σ);}
N(Stop) {printf("stop\n");}
N(S) {
  β=0,Tnxt,         β=512,Tnxt,         β=1024,Tnxt,     β=1536,Tend,     α+=11;
  β=0,WORD(a),      β=512,WORD(b),      β=1024,WORD(c),  β=1536,WORD(d),  α+=11;
  β=0,Tbot,         β=512,Tcnt,         β=1024,Tcnt,     β=1536,Tcnt,     α+=11;
  β=0,Tnxt,         β=512,Tnxt,         β=1024,Tnxt,     β=1536,Ttop,     α+=11;
  β=0,WORD(A),      β=512,WORD(B),      β=1024,WORD(C),  β=1536,WORD(D),  α+=11;
  β=0,DOT,          β=512,DOT,          β=1024,DOT,      β=1536,DOT,      α+=11;
  β=0;
  Yellow(5, α, β, ο, σ);
}
N(term) {
  ST, α+=11;
  WORD("love"), α+=11;
  AND, α+=11;
  WORD("live"), α+=11;
  DOT, α+=11;
  Fuchsia(τ, α, β, ο, σ);
}
void ti_init(Args);
#define ALIGN(O, A) (((unsigned long)(((O) + ((A) - 1)) / (A))) * (A))
// ......b0......b1......b2......b3
//                         o
int main() {
  long τ = 0, α = 0, β = 512;
  void* ο[4 * Σ];
  long σ = 0;
  ti_init(τ, α, β, ο, σ);
  S(τ, α, β, ο, σ);
  //term(τ, α, β, ο, σ);
  return 0;
}
/*Code point ↔ UTF-8 conversion
    First     Last
    code      code
    point	    point	    Byte 1	  Byte 2	  Byte 3	  Byte 4
    U+0000    U+007F	  0xxxxxxx	
    U+0080    U+07FF	  110xxxxx	10xxxxxx	
    U+0800    U+FFFF	  1110xxxx	10xxxxxx	10xxxxxx	
    U+10000[b]U+10FFFF	11111xxx	10xxxxxx	10xxxxxx	10xxxxxx */
