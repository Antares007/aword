#include "../main.h"

extern int strcmp(const char *, const char *);
S(match) { (strcmp(o[τ + 1], β[0][1]) ? Gor : God)(OS); }

N(rise);
N(rise){is_a_book_of()}

N(dive);
S(dive_s) { OB(3, dive), OB(3, go_s), God(OS); }
S(dive_name) {
  OB(3, dive_s, Go, Go), OB(3, NotAndOr);
  OB(3, match), God(OS);
}
N(dive) {
  is_a_book_of([name] = dive_name, //
               [tab] = dive_s,     //
  )
}


