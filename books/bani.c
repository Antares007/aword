// clang-format off
#include "../main.h"
S(book_of_bani);

S(book_of_bani_e) { τ += 11, sdb(OS), book_of_bani(OS); }
N(book_of_bani_s) { τ += 1 << Σ, sdb(OS), book_of_bani(OS); }

N(cursor);
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

S(book_of_bani  ) {
  is_a_book_of(
    [tab  ] = bani_tab,
    [tword] = bani_sword,
    [name ] = Yellow,
    [halt ] = Yellow,
    [aword] = Yellow,
  )
}
