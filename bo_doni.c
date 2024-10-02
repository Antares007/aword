#include "sophis2.h"
N(doni);
S(doni_w) { OB(ρ, doni), go_w(To); }

N(doni) {
  Book_of(              //
      [dot] = doni_w,   //
      [print] = doni_w, //
      [put] = doni_w,   //
  )
}
