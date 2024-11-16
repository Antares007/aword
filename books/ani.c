// clang-format off
#include "../main.h"
N(dive);
N(rise);
S(nearch      ) { τ = β[ρYellow][1], rise(OS); }

N(search      ) { οYellow(Yellow, τ = (τ >> Σ) << Σ),
                  οYellow(nearch, Yellow, Yellow),
                  οYellow(Yellow_NAO), dive(OS); }

S(book_of_ani );
N(ani_e       ) { οYellow(book_of_ani), Yellow_e(OS); }
N(ani_s       ) { οYellow(book_of_ani), Yellow_s(OS); }
N(ani         ) { ani_e(OS); }

N(gani_tword);

extern int strcmp(const char *, const char *);
extern int getchar (void);

N(cursor      ) { τ = β[ρYellow][1],
                  α = β[ρYellow][2], Yellow_God(OS); }

N(re_alfa     ) { α = β[2][1], Yellow(OS); }

S(check_lr    ) { (strcmp(o[α[0][1] + 1], o[τ + 1]) == 0 ? Yellow_God : Maroon)(OS); }

S(on_name     ) { οNavy(Navy, τ), οMaroon(check_lr), ani_s(OS); }

N(Return      ) { τ = α[ρYellow][1], Olive(OS); }

N(stop        ) { P; } 
N(gani_e);
S(goin_sword  ) { οOlive( gani_e, τ), οOlive(Return);

                  οYellow(stop, on_name, stop),
                  οYellow(Yellow_NAO),
                  οBlue(  Blue, o[τ + 1]),
                  οYellow(search), Yellow_God(OS); }

S(ani_sword   ) { οYellow(goin_sword, Yellow, Yellow),
                  οYellow(Yellow_NAO, α),
                  οYellow(re_alfa), Maroon(OS); }

S(ani_tab     ) { οYellow(ani_s, τ, α), οYellow(cursor);
                  ani_e(OS); }
S(book_of_ani ) {
  is_a_book_of(
    [tab  ] = ani_tab,
    [tword] = gani_tword,
    [sword] = ani_sword,
    [name ] = Yellow,
    [halt ] = Yellow,
  );
}
