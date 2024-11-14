// clang-format off
#include "../main.h"
N(dive);
N(rise);
S(nearch            ) { τ = β[ρYellow][1], οYellow(rise), Yellow(OS); }

N(search            ) { οYellow(Yellow, τ = (τ >> Σ) << Σ),
                        οYellow(nearch),
                        οYellow(Yellow_Or),
                        οYellow(dive), Yellow(OS); }

S(book_of_ani       );
S(ani_e             ) { οYellow(book_of_ani), Yellow_e(OS); }
N(ani               ) { οMaroon(Yellow_Gor), ani_e(OS); }


S(match             ) { const char *t = o[τ + 1];
                        const char *s = β[ρBlue][1];
                        long length   = β[ρBlue][2];
                        long pos      = β[ρBlue][3];
                        if (pos < length && s[pos] == t[0])
                          οMaroon(Yellow_Gor),
                          οBlue(  Yellow, s, length, pos + 1), ani_e(OS);
                        else
                          Yellow_Gor(OS);
                      }

S(ani_put           ) { οBlue(Blue, o[τ + 1]), ani_e(OS); }

S(ani_print         ) { long **b = β;
                        printf("%7s(", ν == 2 ? "Red" : ν ? "Green" : "Blue");
                        while (b[ρBlue][-1])
                          printf("%s ", (char *)b[ρBlue][1]), b = b[ρBlue][-1];
                        printf(")\n");
                        ani_e(OS); }

extern int strcmp(const char *, const char *);
extern int getchar (void);

S(set_tau       ) { τ = α[ρYellow][1], Olive(OS); }


S(cursor        ) { τ = β[ρYellow][1],
                    α = β[ρYellow][2], Yellow_God(OS); }

S(goin_tab      ) { οNavy(Navy, τ),
                    οYellow(book_of_ani),
                    οYellow(Yellow_s), Yellow(OS); }

S(restore_alfa  ) { α = β[2][1], Yellow(OS); }

S(ani_from_right) { οMaroon(Yellow_Gor), ani_e(OS); }

S(check_lr      ) { if(strcmp(o[α[2][1] + 1], o[τ + 1]) == 0) Yellow_God(OS); else Maroon(OS); }

S(goin_sword    ) { οOlive(ani_from_right, τ),
                    οMaroon(check_lr),
                    οOlive(set_tau);

                    οYellow(goin_tab),
                    οYellow(Yellow_And),
                    οBlue(  Blue, o[τ + 1]),
                    οYellow(search), Yellow_God(OS); }

S(ani_sword     ) { οYellow(goin_sword),
                    οYellow(Yellow_Or, α),
                    οYellow(restore_alfa), Maroon(OS); }

S(ani_tword     ) { οYellow(match), Yellow(OS); }

S(ani_tab       ) { οYellow(book_of_ani, τ + (1 << Σ), α),
                    οYellow(cursor);
                    ani_e(OS); }
N(book_of_bani);
S(ani_dot       ) { οYellow(book_of_bani, α[0][1] + (1 << Σ), α), οYellow(cursor), Olive(OS); }

S(book_of_ani   ) {
  is_a_book_of(
    [tab  ] = ani_tab,
    [put  ] = ani_put,
    [tword] = ani_tword,
    [nop  ] = ani_e,
    [print] = ani_print,
    [sword] = ani_sword,
    [dot  ] = ani_dot,
    [end  ] = Yellow,
    [name ] = Yellow,
    [halt ] = Yellow,
  );
}
