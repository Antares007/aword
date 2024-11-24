// clang-format off
#include "../sophis.h"
extern int strcmp(const char *, const char *);
S(book_of_rise);
N(search      ) { τ = σ, book_of_rise(OS); }
S(rise_name   ) { (strcmp(o[τ + 1], o[βGreen[1] + 1]) == 0
                  ? Green
                  : book_of_rise)(OS); }
S(book_of_rise) {
  τ -= 1 << Σ;
  ρ = 0, δ = -1, sdb(OS);
  is_a_book_of(
    [name ] = rise_name,
    [tab  ] = book_of_rise,
    [begin] = book_of_rise,
    [halt ] = Blue,
  )
}
