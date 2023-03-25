#include "aword.h"
// clang-format off
N(ara) {
  if (White(==)) {
    if      (Red(==)    ) { Yellow(=); }
    else if (Yellow(==) ) { Black(=),   Green(=); }
    else if (Green(==)  ) { Yellow(=),  Black(=); }
  } else if (Green(==)  ) { White(=); }
  X;
}
N(da) {
  if (White(==)) {
    if      (Yellow(==) ) { Black(=), Green(=); }
    else if (Green(==)  ) { Yellow(=); }
  } else if (Green(==)  ) { White(=); }
  X;
}
N(an) {
  if (White(==)) {
    if      (Blue(==)   ) { Yellow(=); }
    else if (Yellow(==) ) { Black(=),   Green(=); }
    else if (Green(==)  ) { Yellow(=),  Black(=); }
  } else if (Green(==)  ) { White(=); }
  X;
}
N(b) { White(=), X; }
N(o) {
  if (Yellow(==)) {
    Green(=);
  } else if (Green(==)) {
    Yellow(=);
  }
  Black(=), X;
}
