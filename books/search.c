// clang-format off
#include "../sophis.h"
S(rise);
N(search    ) { τ = σ, rise(OS); }
S(rise_name ) { (o[τ + 2] == o[βGreen[1] + 2] ? Green : rise)(OS); }
S(rise      ) { τ -= 1 << Σ; ρ = 0, δ = -1, sdb(OS);
  is_a_book_of(
    [name ] = rise_name,
    [tab  ] = rise,
    [begin] = rise,
    [halt ] = Blue,
  )
}
