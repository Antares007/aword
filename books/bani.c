// clang-format off
#include "../main.h"
N(cursor);
N(book_of_bani_s);
S(book_of_bani_e);
S(bani_tab      ) { οYellow(book_of_bani_s, τ, α, ω), οYellow(cursor);
                    book_of_bani_e(OS); }
N(stop);
N(book_of_gani_e);
N(Return);
N(search);
extern int strcmp(const char *, const char *);
S(check_lr      ) { (strcmp(o[α[2][1] + 1], o[τ + 1]) == 0 ? Yellow_Red : Maroon)(OS); }

S(goin          ) { οOlive(book_of_gani_e, τ), οMaroon(check_lr, "bani", τ), οOlive(Return);
                    οGreen(book_of_bani_s, τ), οBlue(stop), search(OS); }
N(reset_alfa);
S(bani_sword    ) { οYellow(goin, book_of_gani_e, Yellow),
                    οYellow(Yellow_NAO, α),
                    οYellow(reset_alfa),  Maroon(OS); }
N(book_of_bani_s) {
  τ += 1 << Σ;
  is_a_book_of(
    [tab  ] = bani_tab,
    [name ] = Yellow,
    [halt ] = Yellow,
  )
}
S(book_of_bani_e) {
  τ += 11;
  is_a_book_of(
    [tword] = bani_sword,
    [aword] = Yellow,
  )
}
