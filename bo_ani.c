#include "sophis2.h"
N(ani);
N(bani);

S(ani_e ) { OB(ρ, ani), go_e(To); }
S(ani_nl) { OB(ρ, bani), go_w(To); }

N(ani) {
  is_a_book_of(
      [dot  ] = ani_nl,
      [name ] = ani_e,
      [nl   ] = ani_nl,
      [print] = ani_e,
      [put  ] = ani_e,
      [tab  ] = ani_e,
  )
}
