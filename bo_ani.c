#include "sophis2.h"
N(ani);
N(bani);

S(ani_e ) { OB(ρ, ani), go_e(To); }
S(ani_nl) { OB(ρ, bani), go_w(To); }

N(ss); N(sn);
S(cr          ) { τ = ((τ >> Σ) << Σ), God(To); }
S(nearch      ) { τ = o[β[ρ]++],  OB(ρ, sn),
                                  OB(ρ, cr), God(To); }
S(search      ) { o[α++] = o[τ + 1];
                  OB(ρ, drop_alfa),
                  OB(ρ, τ), OB(ρ, nearch), OB(ρ, Or1),
                  OB(ρ, ss),OB(ρ, cr), God(To); }
S(sta         ) { τ = o[β[ρ]++], God(To); }
S(ani_tword   ) { OB(ρ, ani),           OB(ρ, And);
                  OB(ρ, go_e),          OB(ρ, And);
                  OB(ρ, τ), OB(ρ, sta), OB(ρ, And1);
                  OB(ρ, ani),           OB(ρ, And);
                  OB(ρ, search),
                  God(To); }
N(ani) {
  is_a_book_of(
      [tword] = ani_tword,
      [dot  ] = ani_nl,
      [name ] = ani_e,
      [nl   ] = ani_nl,
      [print] = ani_e,
      [put  ] = ani_e,
      [tab  ] = ani_e,
      [nop  ] = ani_e,
  )
}
