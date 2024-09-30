#include "sophis2.h"
Nar(twist);
Nar(ss);
Nar(sn);
S(cr) { τ = ((τ >> Σ) << Σ), God(OS); }
S(nearch) { τ = o[β[ρ]++], B(sn), B(cr), God(OS); }
S(search) {
  o[α++] = o[τ + 1];
  B(drop_alfa), B(τ), B(nearch), B(Or1), B(ss), B(cr), God(OS);
}

S(sta) { τ = o[β[ρ]++], God(OS); }

S(twist_tword) {
  B(twist), B(And);
  B(go_e), B(And);
  B(τ), B(sta), B(And1);
  B(twist), B(And);
  B(search), God(OS);
}

S(twist_s) { B(twist), B(go_s), B(cr), God(OS); }
S(twist_e) { B(twist), B(go_e), God(OS); }
Nar(twist) {
  static n_t sopcodes[] = {
      [name] = twist_e, [tab] = twist_e, [print] = twist_e,
      [put] = twist_e,  [nl] = twist_s,  [tword] = twist_tword,
      [dot] = God,
  };
  sopcodes[o[τ]](OS);
}
