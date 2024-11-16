// clang-format off
#include "../main.h"
S(book_of_bani);

S(bani_e      ) { οRed(book_of_bani), Red_e(OS); }

N(bani_s      ) { οRed(book_of_bani), Red_s(OS); }

N(cursor);
S(bani_tab    ) { οYellow(bani_s, τ, α), οYellow(cursor);
                  bani_e(OS); }
N(stop);
N(gani_e);
N(Return);
N(search);
extern int strcmp(const char *, const char *);

S(lr_check    ) { (strcmp(o[α[2][1] + 1], o[τ + 1]) == 0 ? Yellow_Got : Maroon)(OS); }

S(goin        ) { οOlive( gani_e, τ),
                  οMaroon(lr_check),
                  οOlive( Return),

                  οYellow(stop, bani_s, stop),
                  οYellow(Yellow_NAO),
                  οBlue(  Blue, o[τ + 1]), search(OS); }
N(re_alfa);
S(bani_sword  ) { οYellow(goin, gani_e, Yellow),
                  οYellow(Yellow_NAO, α),
                  οYellow(re_alfa), Maroon(OS); }

S(book_of_bani) {
  is_a_book_of(
    [tab  ] = bani_tab,
    [sword] = bani_sword,
    [name ] = Yellow,
    [halt ] = Yellow,
    [tword] = Yellow,
  )
}
