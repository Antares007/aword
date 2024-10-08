#include "sophis2.h"
N(ani);
N(bani);
N(gani);
S(bani_name ) { OB(ρ, ani), go_s(To); }
S(bani_w    ) { OB(ρ, bani), go_w(To); }
S(bani_tab  ) { OB(ρ, gani), go_e(To); }
N(bani) {
  is_a_book_of(
      [tword] = bani_w,
      [name ] = bani_name,
      [print] = bani_w,
      [put  ] = bani_w,
      [tab  ] = bani_tab,
      [dot  ] = bani_tab,
      [nop  ] = bani_w,
  )
}
