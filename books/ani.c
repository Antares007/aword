// clang-format off
#include "../main.h"
N(book_of_dive_n);
N(book_of_rise_n);
S(nearch        ) { τ = β[ρGreen][1], book_of_rise_n(OS); }
N(search        ) { οBlue(nearch), book_of_dive_n(OS); }

S(book_of_ani);
N(sdb);
N(book_of_ani_e ) { τ += 11, sdb(OS), book_of_ani(OS); }
N(book_of_ani_s ) { τ += 1 << Σ, sdb(OS), book_of_ani(OS); }
N(ani           ) { book_of_ani_e(OS); }

N(gani_tword);

extern int strcmp(const char *, const char *);
extern int getchar(void);
N(cursor        ) { τ = β[ρYellow][1],
                    α = β[ρYellow][2],
                    ω = β[ρYellow][3], Yellow_Green(OS); }

N(reset_alfa    ) { α = β[2][1], Yellow(OS); }

S(check_lr      ) { (strcmp(o[α[0][1] + 1], o[τ + 1]) == 0 ? Yellow_Green : Maroon)(OS); }

S(on_name       ) { οNavy(Navy, τ), οMaroon(check_lr, "ani", τ), book_of_ani_s(OS); }

N(Return        ) { τ = α[ρYellow][1], Olive(OS); }

N(stop          ) { P; } 
N(book_of_gani_e);
S(goin_sword    ) { οOlive(book_of_gani_e, τ), οOlive(Return);
                    οGreen(on_name, τ), οBlue(stop), search(OS); }

S(ani_sword     ) { οYellow(goin_sword, Yellow, Yellow),
                    οYellow(Yellow_NAO, α),
                    οYellow(reset_alfa), Maroon(OS); }

S(ani_tab       ) { οYellow(book_of_ani_s, τ, α, ω), οYellow(cursor);
                    book_of_ani_e(OS); }
S(book_of_ani   ) {
  is_a_book_of(
    [tab  ] = ani_tab,
    [aword] = gani_tword,
    [tword] = ani_sword,
    [name ] = Yellow,
    [halt ] = Yellow,
  )
}
