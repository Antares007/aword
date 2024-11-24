// clang-format off
#include "../sophis.h"
N(book_of_rise);
N(search);
N(book_of_ani_e);
N(book_of_ani_s);
extern int strcmp(const char *, const char *);
extern int getchar(void);
N(cursor        ) { τ = β[ρYellow][1],
                    α = β[ρYellow][2],
                    ω = β[ρYellow][3], Yellow_Green(OS); }

N(reset_alfa    ) { α = β[2][1], Yellow(OS); }

S(check_lr      ) { (strcmp(o[α[0][1] + 1], o[τ + 1]) == 0
                    ? Yellow_Green
                    : Maroon)(OS); }

S(on_name       ) { οNavy(Navy, τ), οMaroon(check_lr, "ani", τ),
                    book_of_ani_s(OS); }

N(Return        ) { τ = α[ρYellow][1], Olive(OS); }
N(stop          ) { P; } 
N(book_of_gani_e);
S(goin_sword    ) { οOlive(book_of_gani_e, τ), οOlive(Return);
                    οGreen(on_name, τ), οBlue(stop), search(OS); }

S(ani_tword     ) { οYellow(goin_sword, Yellow, Yellow),
                    οYellow(Yellow_NAO, α),
                    οYellow(reset_alfa), Maroon(OS); }

S(ani_tab       ) { οYellow(book_of_ani_s, τ, α, ω), οYellow(cursor);
                    book_of_ani_e(OS); }

N(gani_aword);
N(book_of_ani_e ) {
  τ += 11;
  is_a_book_of(
    [aword] = gani_aword,
    [tword] = ani_tword,
  )
}
N(book_of_ani_s ) {
  τ += 1 << Σ;
  is_a_book_of(
    [tab  ] = ani_tab,
    [name ] = Yellow,
    [halt ] = Yellow,
  )
}
