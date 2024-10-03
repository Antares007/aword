#include "sophis2.h"
extern int strcmp(const char *, const char *);
S(match   ) { (strcmp(o[τ + 1], o[α - 1]) ? Gor : God)(To); }

N(rise);
S(rise_n    ) { B(rise), B(go_n), God(To); }
S(rise_name ) { B(rise_n), B(Or), B(match), God(To); }
N(rise) {
  is_a_book_of(
      [name ] = rise_name,
      [tab  ] = rise_n,
      [halt ] = Gor,
  )
}

N(dive);
S(dive_s    ) { B(dive), B(go_s), God(To); }
S(dive_name ) { B(dive_s), B(Or), B(match), God(To); }
N(dive) {
  is_a_book_of(
      [name ] = dive_name,
      [tab  ] = dive_s,
      [halt ] = Gor,
  )
}
