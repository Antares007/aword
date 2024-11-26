// clang-format off
#include "../sophis.h"
N(book_of_rise);
N(search);
N(book_of_ani_e);
N(book_of_ani_s);
extern int getchar(void);
N(reset_alfa    ) { α = βYellow[1], Yellow(OS); }

S(check_lr      ) { (o[αNavy[1] + 2] == o[τ + 2] ? Yellow_Green : Maroon)(OS); }

S(on_name       ) { οNavy(Navy, τ), οMaroon(check_lr, "ani", τ), book_of_ani_s(OS); }

N(Return        ) { τ = αOlive[1], Olive(OS); }
N(stop          ) { P; } 
N(book_of_gani_e);
S(goin_sword    ) { οOlive(book_of_gani_e, τ), οOlive(Return);
                    οGreen(on_name, τ), οBlue(stop), search(OS); }

S(ani_tword     ) { οYellow(goin_sword, Yellow, Yellow),
                    οYellow(Yellow_NAO, α),
                    οYellow(reset_alfa), Maroon(OS); }

N(cursor        ) { τ = βYellow[1],
                    α = βYellow[2],
                    ω = βYellow[3], Yellow_Green(OS); }

S(ani_tab       ) { οYellow(book_of_ani_s, τ, α, ω), οYellow(cursor);
                    book_of_ani_e(OS); }

N(gani_aword);
N(gani_dot);
N(book_of_ani_e ) {
  τ += 11;
  ρ = 2, δ = +1, sdb(OS);
  is_a_book_of(
    [aword] = gani_aword,
    [dot  ] = gani_dot,
    [tword] = ani_tword,
  )
}
N(book_of_ani_s ) {
  τ += 1 << Σ;
  ρ = 2, δ = +1, sdb(OS);
  is_a_book_of(
    [tab  ] = ani_tab,
    [name ] = Yellow,
    [halt ] = Yellow,
  )
}
