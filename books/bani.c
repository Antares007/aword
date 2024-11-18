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

S(lr_check      ) { (strcmp(o[α[2][1] + 1], o[τ + 1]) == 0 ? Yellow_Got : Maroon)(OS); }

S(goin          ) { οOlive( book_of_gani_e, τ),
                    οMaroon(lr_check),
                    οOlive( Return),

                    οYellow(stop, book_of_bani_s, stop),
                    οYellow(Yellow_NAO),
                    οBlue(  Blue, o[τ + 1]), search(OS); }
N(re_alfa);
S(bani_sword    ) { οYellow(goin, book_of_gani_e, Yellow),
                    οYellow(Yellow_NAO, α),
                    οYellow(re_alfa), Maroon(OS); }
S(book_of_bani  ) {
  is_a_book_of(
    [tab  ] = bani_tab,
    [sword] = bani_sword,
    [name ] = Yellow,
    [halt ] = Yellow,
    [tword] = Yellow,
  )
}
