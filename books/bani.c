// clang-format off
#include "../sophis.h"
N(cursor);
N(book_of_bani_s);
S(book_of_bani_e);
S(bani_tab      ) { οYellow(book_of_bani_s, τ, α, ω), οYellow(cursor);
                    book_of_bani_e(OS); }

N(stop);
N(book_of_gani_e);
N(Return);
N(search);
S(check_lr      ) { (o[αOlive[1] + 2] == o[τ + 2] ? Yellow_Red : Maroon)(OS); }
S(goin          ) { οOlive(book_of_gani_e, τ), οMaroon(check_lr, "bani", τ), οOlive(Return);
                    οGreen(book_of_bani_s, τ), οBlue(stop), search(OS); }
N(reset_alfa);
S(bani_tword    ) { οYellow(goin, book_of_gani_e, Yellow),
                    οYellow(Yellow_NAO, α),
                    οYellow(reset_alfa),  Maroon(OS); }
N(book_of_bani_s) {
  τ += 1 << Σ;
  ρ = 3, δ = +1, sdb(OS);
  is_a_book_of(
    [tab  ] = bani_tab,
    [name ] = Yellow,
    [halt ] = Yellow,
  )
}
S(book_of_bani_e) {
  τ += 11;
  ρ = 3, δ = +1, sdb(OS);
  is_a_book_of(
    [tword] = bani_tword,
    [aword] = Yellow,
    [dot  ] = Yellow,
  )
}
