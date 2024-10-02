#include "sophis2.h"
extern int strcmp(const char *, const char *);
S(match   ) { (strcmp(o[τ + 1], o[α - 1]) ? Gor : God)(To); }

N(sn);
S(sn_n    ) { B(sn), B(go_n), God(To); }
S(sn_name ) { B(sn_n), B(Or), B(match), God(To); }
N(sn) {
  is_a_book_of(
      [name ] = sn_name,
      [tab  ] = sn_n,
      [halt ] = Gor,
  )
}

N(ss);
S(ss_s    ) { B(ss), B(go_s), God(To); }
S(ss_name ) { B(ss_s), B(Or), B(match), God(To); }
N(ss) {
  is_a_book_of(
      [name ] = ss_name,
      [tab  ] = ss_s,
      [halt ] = Gor,
  )
}
