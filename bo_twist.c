#include "sophis2.h"
Nar(twist);
Nar(ss);
Nar(sn);
S(cr) { τ = ((τ >> Σ) << Σ), God(OS); }
S(nearch) { τ = o[β++], O(sn), O(cr), God(OS); }
S(search) {
  o[α++] = o[τ + 1];
  O(drop_alfa);
  O(τ);
  O(G1), O(G1), O(nearch), O(NotAndOr);
  O(ss), O(cr), God(OS);
}
S(sta) { τ = o[β++], God(OS); }

S(starTwist) {
  long tau = o[β++];
              O(twist);
              O(go_e);
              O(tau);
  O(G1),      O(G1),        O(sta), O(NotAndOr);
  O(twist), God(OS);
}
S(twist_tword) {
              O(τ);
  O(G1),      O(starTwist), O(G1),  O(NotAndOr);
  O(search),  God(OS);
}

S(twist_s) { O(twist), O(go_s), O(cr), God(OS); }
S(twist_e) { O(twist), O(go_e), God(OS); }
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
