// clang-format off
#include "../main.h"
S(book_of_bani);

S(book_of_bani_e) { οRed(book_of_bani), τ += 11, Red(OS); }
N(book_of_bani_s) { οRed(book_of_bani), τ += 1 << Σ, Red(OS); }

N(cursor);
S(bani_tab      ) { οYellow(book_of_bani_s, τ, α), οYellow(cursor);
                    book_of_bani_e(OS); }
N(stop);
N(book_of_gani_e);
N(Return);
N(search);
extern int strcmp(const char *, const char *);

S(check_lr      ) { (strcmp(o[α[2][1] + 1], o[τ + 1]) == 0 ? Yellow : Maroon)(OS); }

S(goin          ) { οOlive(book_of_gani_e, τ), οMaroon(check_lr, "bani"), οOlive(Return);
                    οGreen(book_of_bani_s, τ), οBlue(stop), search(OS); }

S(re_alfa_Green ) { α = β[1][1], Green(OS); }
N(re_alfa_Blue);
S(bani_sword    ) { οGreen(book_of_gani_e, α), οBlue(goin, α),      
                    οGreen(re_alfa_Green),     οBlue(re_alfa_Blue),  Maroon(OS); }

S(book_of_bani  ) {
  is_a_book_of(
    [tab  ] = bani_tab,
    [sword] = bani_sword,
    [name ] = Yellow,
    [halt ] = Yellow,
    [tword] = Yellow,
  )
}
