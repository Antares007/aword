#include "../main.h"

extern int strcmp(const char *, const char *);
S(match     ) { (strcmp(o[τ + 1], β[1][1]) ? Gor : God)(OS); }
N(rise      );
S(rise_n    ) { οYellow(rise), go_n(OS); }
S(rise_name ) { οYellow(rise_n), οYellow(Or), match(OS); }
N(rise      ){
  is_a_book_of(
    [name ] = rise_name,
    [tab  ] = rise_n,
    [begin] = rise_n,
    [halt ] = Gor,
  )
}
N(dive      );
S(dive_s    ) { οYellow(dive), go_s(OS); }
S(dive_name ) { οYellow(dive_s), οYellow(Or), match(OS); }
N(dive      ) {
  is_a_book_of(
    [name ] = dive_name,
    [tab  ] = dive_s,
    [begin] = dive_s,
    [halt ] = Gor,
  )
}
