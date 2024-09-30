#include "sophis2.h"
Nar(twist);
Nar(ss);
Nar(sn);
S(cr) { τ = ((τ >> Σ) << Σ), God(OS); }
S(nearch) { τ = o[β[ρ]++], B(sn), B(cr), God(OS); }
S(search) {
  o[α++] = o[τ + 1];
  {
    long sentence[] = {drop_alfa, τ, nearch, Or1, ss, cr};
    long length = sizeof(sentence) / sizeof(*sentence);
    if ((β[ρ] - length) < ((β[ρ] >> Σ) << Σ))
      Got(OS);
    else {
      long b = β[ρ];
      for(long i = 0; i < length; i++) 
        o[--b] = sentence[i];
      β[ρ] = b;
      God(OS);
    }
  }
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
