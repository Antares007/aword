#include "sophis2.h"
Nar(twist);
Nar(ss);
Nar(sn);
S(cr) { τ = ((τ >> Σ) << Σ), Go(OS); }
S(nearch) { τ = o[β++], O(sn), O(cr), Go(OS); }
S(search) {
  o[α++] = o[τ + 1];
  O(drop_α);
                  O(τ);
  O(G1),  O(G1),  O(nearch), O(NotAndOr);
          O(ss),
          O(cr),
          Go(OS);
}
S(sta) { τ = o[β++], Go(OS); }
S(twist_tword) {
          O(twist),             O(And);
          O(go_e),              O(And);
                      O(τ);
  O(G1),  O(G1),      O(sta),   O(NotAndOr);
          O(twist),             O(And);
          O(search);
  Go(OS);   
}
S(twist_s ) { O(twist), O(go_s), O(cr), Go(OS); }
S(twist_e ) { O(twist), O(go_e), Go(OS); }
Nar(twist) {
  static n_t sopcodes[] = {
    [name ] = twist_e,
    [tab  ] = twist_e,
    [print] = twist_e,
    [put  ] = twist_e,
    [nl   ] = twist_s,
    [tword] = twist_tword,
    [dot  ] = Gor,
  };
  sopcodes[o[τ]](OS);
}
