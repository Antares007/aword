// clang-format off
#include "../main.h"
extern int strcmp(const char *, const char *);
S(match         ) { (strcmp(o[τ + 1], o[β[ρGreen][1] + 1]) == 0 ? Green : Blue)(OS); }
S(book_of_rise);
N(book_of_rise_n) { τ = ((τ >> Σ) - 1) << Σ, sdb(OS), book_of_rise(OS); }
S(rise_name     ) { οBlue(book_of_rise_n), match(OS); }
S(book_of_rise  ) {
  is_a_book_of(
    [name ] = rise_name,
    [tab  ] = book_of_rise_n,
    [begin] = book_of_rise_n,
    [halt ] = Blue,
  )
}
S(book_of_dive);
N(book_of_dive_n) { τ = ((τ >> Σ) + 1) << Σ, sdb(OS), book_of_dive(OS); }
S(dive_name     ) { οBlue(book_of_dive_n), match(OS); }
S(book_of_dive  ) {
  is_a_book_of(
    [name ] = dive_name,
    [tab  ] = book_of_dive_n,
    [begin] = book_of_dive_n,
    [halt ] = Blue,
  )
}
