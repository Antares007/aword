#include "sophis2.h"
N(twist);
N(ss);
N(sn);
S(cr          ) { τ = ((τ >> Σ) << Σ), God(To); }
S(nearch      ) { τ = o[β[ρ]++], B(sn), B(cr), God(To); }
S(search      ) { o[α++] = o[τ + 1];
                  B(drop_alfa), B(τ), B(nearch), B(Or1), B(ss), B(cr), God(To); }
S(sta         ) { τ = o[β[ρ]++], God(To); }
S(twist_tword ) { B(twist),     B(And);
                  B(go_e),      B(And);
                  B(τ), B(sta), B(And1);
                  B(twist),     B(And);
                  B(search),    God(To); }
S(twist_s     ) { B(twist), B(go_s), B(cr), God(To); }
S(twist_e     ) { B(twist), B(go_e), God(To); }
N(twist) {
  is_a_book_of(
      [name ] = twist_e,
      [tab  ] = twist_e,
      [print] = twist_e,
      [put  ] = twist_e,
      [nl   ] = twist_s,
      [tword] = twist_tword,
      [dot  ] = God,
  )
}
