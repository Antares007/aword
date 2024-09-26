#include "sophis2.h"
Nar(bo_grow);
Nar(twist);
S(twist_e) { O(twist), O(And), go_e(OS); }
S(cr) { τ = ((τ >> Σ) << Σ), Go(OS); }
S(twist_s) { O(twist), O(go_s), cr(OS); }
Nar(ss);
Nar(sn);
S(nearch) { τ = o[β++], O(sn), cr(OS); }
S(search) {
  o[α++] = o[τ + 1];
  O(drop_α);
  O(τ);
  O(G1), O(G1), O(nearch), O(NotAndOr);
  O(ss), cr(OS);
}
S(sta) { τ = o[β++], Go(OS); }
S(twist_tword) {
  O(twist), O(And);
  O(go_e), O(And);
  O(τ);
  O(G1), O(G1), O(sta), O(NotAndOr);
  O(twist), O(And), search(OS);
}
Book_of_(
    twist, [name] = twist_e, [nl] = twist_s, [tab] = twist_e, [print] = twist_e,
    [put] = twist_e, [tword] = twist_tword, [dot] = Gor, );
