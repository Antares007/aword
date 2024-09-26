#include "sophis2.h"
extern int strcmp(const char *, const char *);
S(match) { (strcmp(o[τ + 1], o[α - 1]) ? Gor : God)(OS); }

Nar(sn);
S(sn_n) { O(sn), O(go_n), Go(OS); }
S(sn_name) { O(sn_n), O(Or), O(match), Go(OS); }
Nar(sn) {
  static n_t sopcodes[] = {
      [name ] = sn_name,
      [tab  ] = sn_n,
      [halt ] = Gor,
  };
  sopcodes[o[τ]](OS);
}

Nar(ss);
S(ss_s) { O(ss), O(go_s), Go(OS); }
S(ss_name) { O(ss_s), O(Or), O(match), Go(OS); }
Nar(ss) {
  static n_t sopcodes[] = {
      [name ] = ss_name,
      [tab  ] = ss_s,
      [halt ] = Gor,
  };
  sopcodes[o[τ]](OS);
}
