#include "sophis2.h"
N(ani);
N(bani);

S(ani_e) { OB(ρ, ani), go_e(To); }
S(ani_nl) { OB(ρ, bani), go_w(To); }

N(ani) {
  Book_of(             //
      [name] = ani_e,  //
      [nl] = ani_nl,   //
      [tab] = ani_e,   //
      [put] = ani_e,   //
      [print] = ani_e, //
      [dot] = ani_nl,  //
  )
}
