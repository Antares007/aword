// clang-format off
#include "../main.h"
N(dive);
N(rise);
S(nearch            ) { τ = β[2][1], οYellow(rise), Go(OS); }
S(search            ) { οBlue(Go, o[τ + 1]),
                        οYellow(go_s), οYellow(And),
                        οYellow(Go, τ = ((τ >> Σ) << Σ)), οYellow(nearch), οYellow(Or),
                        οYellow(dive), Go(OS); }

S(book_of_ani       );
N(ani               ) { οYellow(book_of_ani), go_e(OS); }

S(ani_term          ) { const char *t = o[τ + 1];
                        const char *s = β[0][1];
                        long length = β[0][2]; long pos = β[0][3];
                        if (pos < length && s[pos] == t[0])
                          οBlue(Go, s, length, pos + 1), ani(OS);
                        else
                          Gor(OS);
                      }

S(ani_put           ) { οGreen(Go, o[τ + 1]), ani(OS); }

S(ani_print         ) { long **b = β;
                        printf("%7s(", ν == 2 ? "Red" : ν ? "Green" : "Blue");
                        while (b[1][-1])
                          printf("%s ", (char *)b[1][1]), b = b[1][-1];
                        printf(")\n");
                        ani(OS); }
#include <stdio.h>
#include <string.h>
S(set_tau           ) {
  long**u_name = β[2][2];
  long**c_name = α;
  
  if (strcmp(c_name[3][1], u_name[3][1]) == 0 &&
      c_name[3]     < u_name[3] &&
      ((long***)c_name)[3][-1][0] == ((long***)u_name)[3][-1][0])
    getchar();
  τ = β[2][1], Go(OS);
}
S(ani_twist         ) { οOlive(ani), οYellow(Twist), Go(OS); }
S(Next              ) { τ = β[2][1], α = β[2][2], God(OS); }

S(ani_tword         ) { οRed(Go, o[τ + 1]);
                        οOlive(ani_twist), οOlive(Go, τ, β), οOlive(set_tau);
                        οYellow(book_of_ani), οYellow(And), οYellow(search), Go(OS); }

S(ani_tab           ) { οYellow(book_of_ani), οYellow(Go, τ + (1 << Σ), α), οYellow(Next);
                        ani(OS); }

S(ani_dot           ) { οYellow(Twist), Go(OS); }
S(ani_name          ) { Go(OS); }
S(ani_halt          ) { Go(OS); }
S(ani_end           ) { Go(OS); }

S(book_of_ani       ) {
  is_a_book_of(
    [tab  ] = ani_tab,
    [put  ] = ani_put,
    [term ] = ani_term,
    [nop  ] = ani,
    [print] = ani_print,
    [tword] = ani_tword,
    [dot  ] = ani_dot,
    [end  ] = ani_end,
    [name ] = ani_name,
    [halt ] = ani_halt,
  );
}
