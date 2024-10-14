#include "../main.h"

extern int strcmp(const char *, const char *);
S(match     ) { (strcmp(o[τ + 1], β[0][1]) ? Gor : God)(OS); }
N(rise      );
S(rise_n    ) { οRed(rise), go_Red(OS); }
S(rise_name ) { οRed(rise_n), οRed(Or), match(OS); }
N(rise      ) {
  is_a_book_of(
    [name ] = rise_name,
    [tab  ] = rise_n,
    [begin] = rise_n,
    [halt ] = Gor,
  )
}
N(dive      );
S(dive_s    ) { οGreen(dive), go_Green(OS); }
S(dive_name ) { οGreen(dive_s), οGreen(Or), match(OS); }
N(dive      ) {
  is_a_book_of(
    [name ] = dive_name,
    [tab  ] = dive_s,
    [begin] = dive_s,
    [halt ] = Gor,
  )
}
