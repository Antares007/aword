// clang-format off
#include "../main.h"
extern int strcmp(const char *, const char *);
S(match     ) { (strcmp(o[τ + 1], β[0][1]) ? Gor : God)(OS); }
S(bo_rise   );
S(rise_pass ) { οRed(bo_rise), pass(OS); }
N(rise      ) { οRed(rise_pass), go_n(OS); }
S(rise_name ) { οRed(rise_pass), οRed(Or), οRed(match), Go(OS); }
S(bo_rise   ) {
  is_a_book_of(
    [name ] = rise_name,
    [tab  ] = rise_pass,
    [begin] = rise_pass,
    [halt ] = Gor,
  )
}
S(bo_dive   );
S(dive_pass ) { οGreen(bo_dive), pass(OS); }
N(dive      ) { οGreen(dive_pass), go_s(OS);}
S(dive_name ) { οGreen(dive_pass), οGreen(Or), οGreen(match), Go(OS); }
S(bo_dive   ) {
  is_a_book_of(
    [name ] = dive_name,
    [tab  ] = dive_pass,
    [begin] = dive_pass,
    [halt ] = Gor,
  )
}
