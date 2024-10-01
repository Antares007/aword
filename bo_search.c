#include "sophis2.h"
extern int strcmp(const char *, const char *);
S(match) { (strcmp(o[τ + 1], o[α - 1]) ? Gor : God)(To); }

Nar(sn);
S(sn_n) { B(sn), B(go_n), God(To); }
S(sn_name) { B(sn_n), B(Or), B(match), God(To); }
Nar(sn) {
  static n_t sopcodes[] = {
      [name] = sn_name,
      [tab] = sn_n,
      [halt] = Gor,
  };
  sopcodes[o[τ]](To);
}

Nar(ss);
S(ss_s) { B(ss), B(go_s), God(To); }
S(ss_name) { B(ss_s), B(Or), B(match), God(To); }
Nar(ss) {
  static n_t sopcodes[] = {
      [name] = ss_name,
      [tab] = ss_s,
      [halt] = Gor,
  };
  sopcodes[o[τ]](To);
}
