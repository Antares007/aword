#include "sophis2.h"
N(doni);
N(gani);
N(ani);
S(gani_e) { OB(ρ, gani), go_e(To); }
S(gani_dot) { OB(ρ, ani), go_e(To); }
S(gani_nl) { OB(ρ, doni), go_w(To); }
N(gani) {
  Book_of(              //
      [put] = gani_e,   //
      [print] = gani_e, //
      [dot] = gani_dot, //
      [nl] = gani_nl,   //
  );
}
