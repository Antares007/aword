// clang-format off
#include "../main.h"
extern int strcmp(const char *, const char *);
S(match         ) { (strcmp(o[τ + 1], β[ρBlue][1]) ? Yellow_Gor : Yellow_God)(OS); }
S(book_of_rise);
N(book_of_rise_n) { οYellow(book_of_rise), τ -= 1 << Σ, Yellow(OS); }
S(rise_name     ) { οYellow(book_of_rise_n, Yellow, Yellow),
                    οYellow(Yellow_NAO), match(OS); }
S(book_of_rise  ) {
  is_a_book_of(
    [name ] = rise_name,
    [tab  ] = book_of_rise_n,
    [begin] = book_of_rise_n,
    [halt ] = Yellow_Gor,
  )
}
S(book_of_dive);
N(book_of_dive_n) { οYellow(book_of_dive), τ += 1 << Σ, Yellow(OS); }
S(dive_name     ) { οYellow(book_of_dive_n, Yellow, Yellow),
                    οYellow(Yellow_NAO), match(OS); }
S(book_of_dive  ) {
  is_a_book_of(
    [name ] = dive_name,
    [tab  ] = book_of_dive_n,
    [begin] = book_of_dive_n,
    [halt ] = Yellow_Gor,
  )
}
