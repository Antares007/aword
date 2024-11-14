// clang-format off
#include "../main.h"
N(dive);
N(rise);
S(nearch            ) { τ = β[ρYellow][1], οYellow(rise), Yellow(OS); }

S(search            ) { οYellow(Yellow, τ = (τ >> Σ) << Σ),
                        οYellow(nearch),
                        οYellow(Yellow_Or),
                        οYellow(dive), Yellow(OS); }

S(book_of_ani       );
N(ani               ) { οYellow(book_of_ani), Yellow_e(OS); }


S(match             ) { const char *t = o[τ + 1];
                        const char *s = β[ρBlue][1];
                        long length   = β[ρBlue][2];
                        long pos      = β[ρBlue][3];
                        if (pos < length && s[pos] == t[0])
                          οMaroon(Yellow_Gor),
                          οRed(   Yellow, o[τ + 1]),
                          οBlue(  Yellow, s, length, pos + 1), ani(OS);
                        else
                          Yellow_Gor(OS);
                      }

S(ani_put           ) { οRed(Red, o[τ + 1]), ani(OS); }

S(ani_print         ) { long **b = β;
                        printf("%7s(", ν == 2 ? "Red" : ν ? "Green" : "Blue");
                        while (b[ρRed][-1])
                          printf("%s ", (char *)b[ρRed][1]), b = b[ρRed][-1];
                        printf(")\n");
                        ani(OS); }

extern int strcmp(const char *, const char *);
extern int getchar (void);

S(set_tau) { τ = α[ρYellow][1], Olive(OS); }


S(cursor            ) { τ = β[ρYellow][1],
                        α = β[ρYellow][2], Yellow_God(OS); }

S(marknameandgointab) { οNavy(Navy, τ),
                        οYellow(book_of_ani),
                        οYellow(Yellow_s), Yellow(OS); }

S(restore_alfa      ) { α = β[2][1], Yellow(OS); }

S(cont_from_right   ) { οMaroon(Yellow_Gor), ani(OS); }

S(check_lr          ) { if(strcmp(o[α[2][1] + 1], o[τ + 1]) == 0) Yellow_God(OS); else Maroon(OS); }

S(goin_sword        ) { οOlive(cont_from_right, τ),
                        οMaroon(check_lr),
                        οOlive(set_tau);

                        οYellow(marknameandgointab),
                        οYellow(Yellow_And),
                        οBlue(  Blue, o[τ + 1]),
                        οYellow(search), Yellow_God(OS); }

S(ani_sword         ) { οYellow(goin_sword),
                        οYellow(Yellow_Or, α),
                        οYellow(restore_alfa), Maroon(OS); }

S(ani_tword         ) { οYellow(match), Yellow(OS); }

S(ani_tab           ) { οYellow(book_of_ani, τ + (1 << Σ), α),
                        οYellow(cursor);
                        ani(OS); }
N(bani);
S(ani_dot           ) { οYellow(bani, α[0][1] + (1 << Σ), α), οYellow(cursor), Olive(OS); }

S(ani_name          ) { Yellow(OS); }
S(ani_halt          ) { Yellow(OS); }
S(ani_end           ) { Yellow(OS); }

S(book_of_ani       ) {
  is_a_book_of(
    [tab  ] = ani_tab,
    [put  ] = ani_put,
    [tword] = ani_tword,
    [nop  ] = ani,
    [print] = ani_print,
    [sword] = ani_sword,
    [dot  ] = ani_dot,
    [end  ] = ani_end,
    [name ] = ani_name,
    [halt ] = ani_halt,
  );
}
