// clang-format off
#include "../main.h"
N(book_of_dive_n);
N(book_of_rise_n);
S(nearch        ) { τ = β[ρGreen][1], book_of_rise_n(OS); }
N(search        ) { οBlue(nearch), book_of_dive_n(OS); }

S(book_of_ani);
N(book_of_ani_e ) { οYellow(book_of_ani), τ += 11,     Yellow(OS); }
N(book_of_ani_s ) { οYellow(book_of_ani), τ += 1 << Σ, Yellow(OS); }
N(ani           ) { book_of_ani_e(OS); }

N(gani_tword);

extern int strcmp(const char *, const char *);
extern int getchar(void);

N(cursor        ) { τ = β[ρYellow][1],
                    α = β[ρYellow][2], Yellow_God(OS); }

N(re_alfa       ) { α = β[2][1], Yellow(OS); }

S(check_lr      ) { (strcmp(o[α[0][1] + 1], o[τ + 1]) == 0 ? Yellow_God : Maroon)(OS); }

S(on_name       ) { οNavy(Navy, τ), οMaroon(check_lr), book_of_ani_s(OS); }

N(Return        ) { τ = α[ρYellow][1], Olive(OS); }

N(stop          ) { P; } 
N(book_of_gani_e);
S(goin_sword    ) { οOlive( book_of_gani_e, τ), οOlive(Return);

                    οGreen(on_name, τ), οBlue(stop), search(OS); }

S(ani_sword     ) { οYellow(goin_sword, Yellow, Yellow),
                    οYellow(Yellow_NAO, α),
                    οYellow(re_alfa), Maroon(OS); }

S(ani_tab       ) { οYellow(book_of_ani_s, τ, α), οYellow(cursor);
                    book_of_ani_e(OS); }
S(book_of_ani   ) {
  is_a_book_of(
    [tab  ] = ani_tab,
    [tword] = gani_tword,
    [sword] = ani_sword,
    [name ] = Yellow,
    [halt ] = Yellow,
  )
}
