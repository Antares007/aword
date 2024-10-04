#include "../main.h"

extern int strcmp(const char *, const char *);
S(match) { (strcmp(o[τ + 1], β[0][1]) ? Gor : God)(OS); }

N(rise);
S(rise_n) { οYellow(rise), go_n(OS); }
S(rise_name) {
  οYellow(rise_n, Go, Go), οYellow(NotAndOr);
  match(OS);
}
N(rise){is_a_book_of(   //
    [name] = rise_name, //
    [tab ] = rise_n,     //
    [halt] = Gor,       //
    )}

N(dive);
S(dive_s) { οYellow(dive), go_s(OS); }
S(dive_name) {
  οYellow(dive_s, Go, Go), οYellow(NotAndOr);
  match(OS);
}
N(dive) {
  is_a_book_of(           //
      [name] = dive_name, //
      [tab ] = dive_s,     //
      [halt] = Gor,       //
  )
}
