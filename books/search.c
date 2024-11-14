// clang-format off
#include "../main.h"
extern int strcmp(const char *, const char *);
S(match       ) { (strcmp(o[τ + 1], β[ρBlue][1]) ? Yellow_Gor : Yellow_God)(OS); }
S(book_of_rise);
N(rise        ) { οYellow(book_of_rise), Yellow_n(OS); }
S(rise_name   ) { οYellow(rise),
                  οYellow(Yellow_Or),
                  οYellow(match), Yellow(OS); }
S(book_of_rise) {
  is_a_book_of(
    [name ] = rise_name,
    [tab  ] = rise,
    [begin] = rise,
    [halt ] = Yellow_Gor,
  )
}
S(book_of_dive);
N(dive        ) { οYellow(book_of_dive), Yellow_s(OS);}
S(dive_name   ) { οYellow(dive),
                  οYellow(Yellow_Or),
                  οYellow(match), Yellow(OS); }
S(book_of_dive) {
  is_a_book_of(
    [name ] = dive_name,
    [tab  ] = dive,
    [begin] = dive,
    [halt ] = Yellow_Gor,
  )
}
