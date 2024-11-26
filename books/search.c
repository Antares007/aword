// clang-format off
#include "../sophis.h"
S(book_of_rise);
N(search      ) { τ = σ, book_of_rise(OS); }
S(rise_name   ) { (o[τ + 2] == o[βGreen[1] + 2] ? Green : book_of_rise)(OS); }
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
