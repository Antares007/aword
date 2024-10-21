// clang-format off
#include "../main.h"
N(dive);
N(rise);
S(cr                ) { τ = ((τ >> Σ) << Σ), Go(OS); }

S(nearch            ) { τ = β[1][1], οGreen(rise), οGreen(cr), Go(OS); }

S(search            ) { οGreen(go_e), οGreen(And), 
                        οGreen(pass),      οGreen(And),
                        οRed(go_s),    οRed(And),
                        οBlue(Go, o[τ + 1]),
                        οGreen(Go, τ), οGreen(nearch), οGreen(Or),
                        οYellow(dive), οYellow(cr), Go(OS); }
S(bo_ani            );
S(bo_ani_pass       ) { οYellow(bo_ani), pass(OS); }

S(ani_term          ) { const char *t = o[τ + 1];
                        const char *s = β[0][1];
                        long length = β[0][2]; long pos = β[0][3];
                        if (pos < length && s[pos] == t[0])
                          οRed(Go, o[τ + 1]), οBlue(Go, s, length, pos + 1), bo_ani_pass(OS);
                        else
                          Gor(OS); }

S(ani_put           ) { οRed(Go, o[τ + 1]), bo_ani_pass(OS); }

S(ani_print         ) { long **b = β;
                        printf("%7s(", ν == 2 ? "Red" : ν ? "Green" : "Blue");
                        while (b[3][-1])
                          printf("%s ", (char *)b[3][1]), b = b[3][-1];
                        printf(")\n");
                        bo_ani_pass(OS); }
#include<stdio.h>
#define Peek(β, ρ) ((long**)β[ρ][-1])

S(Next              ) { τ = β[2][1], α = β[2][2], God(OS); }
S(set_tau           ) { τ = β[2][1], Go(OS); }

N(ani               ) { οYellow(bo_ani_pass), go_e(OS); }
static long αι = 0;
S(bo_ani_pass_twist ) { οOlive(bo_ani_pass), οYellow(Twist), Go(OS); }
S(ani_tword         ) { οOlive(bo_ani_pass_twist), οOlive(Go, τ), οOlive(set_tau, o[τ + 1], αι++);

                        οYellow(bo_ani), οYellow(And), οYellow(search), Go(OS); }

S(ani_tab           ) { οYellow(bo_ani), οYellow(Go, τ + (1 << Σ), α, α[2][2]), οYellow(Next);
                        bo_ani_pass(OS); }

S(ani_dot           ) { οYellow(Twist), Go(OS); }
S(ani_name          ) { Go(OS); }
S(ani_halt          ) { Go(OS); }
S(ani_end           ) { Go(OS); }

S(bo_ani            ) {
  is_a_book_of(
      [tab  ] = ani_tab,
      [put  ] = ani_put,
      [term ] = ani_term,
      [nop  ] = bo_ani_pass,
      [print] = ani_print,
      [tword] = ani_tword,
      [dot  ] = ani_dot,
      [end  ] = ani_end,
      [name ] = ani_name,
      [halt ] = ani_halt,
  );
}
