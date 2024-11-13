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
N(ani               ) { long ray = R(β, book_of_ani); β = (long *[]) { β[0],  ray,  ray, ray }, go_e(OS); }

S(stop              ) {}
S(match             ) { const char *t = o[τ + 1];
                        const char *s = β[0][1];
                        long length = β[0][2]; long pos = β[0][3];
                        if (pos < length && s[pos] == t[0])
                          οMaroon(stop), οGreen(Go, o[τ+1]), οBlue(Go, s, length, pos + 1), ani(OS);
                        else
                          Gor(OS);
                      }

S(ani_tword         ) { οYellow(match), Go(OS); }

S(ani_put           ) { οBlue(Go, o[τ + 1]), ani(OS); }

S(ani_print         ) { long **b = β;
                        printf("%7s(", ν == 2 ? "Red" : ν ? "Green" : "Blue");
                        while (b[1][-1])
                          printf("%s ", (char *)b[1][1]), b = b[1][-1];
                        printf(")\n");
                        ani(OS); }

extern int strcmp(const char *, const char *);
extern int getchar (void);

S(check_lr          ) { if(strcmp(o[β[2][1]+1], o[τ + 1]) == 0) o[τ + 2] = 1; else
                        Go(OS); }

S(set_tau           ) { τ = β[2][1], Go(OS); }

S(ani_twist         ) { οOlive(ani), οRed(stop), οYellow(Twist), Go(OS); }
S(Next              ) { τ = β[2][1], α = β[2][2], God(OS); }
S(ani_sword         ) { Go( o, α, β, τ, σ, 3, -δ, ν);
                        if(o[τ + 2]) return Gor(OS);

                        οOlive(ani_twist, τ), οMaroon(check_lr), οOlive(set_tau);
                        οYellow(book_of_ani), οYellow(And), οYellow(search), Go(OS); }

S(ani_tab           ) { οYellow(book_of_ani, τ + (1 << Σ), α), οYellow(Next);
                        ani(OS); }

S(ani_dot           ) { οYellow(Twist), Go(OS); }
S(ani_name          ) { Go(OS); }
S(ani_halt          ) { Go(OS); }
S(ani_end           ) { Go(OS); }

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
