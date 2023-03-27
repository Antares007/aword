#include "aradani.h"
// clang-format off
void not (word) {
  if (White(==)) {
    if (Purple(==))       m(a, w, o, Yellow(=), d);
    else if (Yellow(==))  m(a, w, o, Green(=), Black(=));
    else if (Green(==))   m(a, w, o, Yellow(=), Black(=));
  } else if (Green(==))   m(a, w, o, r, White(=));
}
void and (word) {
  if (White(==)) {
    if (Yellow(==))     m(a, w, o, Green(=), Black(=));
    else if (Green(==)) m(a, w, o, Yellow(=), d);
  } else if (Green(==)) m(a, w, o, r, White(=));
}
void or (word) {
  if (White(==)) {
    if (Blue(==))       m(a, w, o, Yellow(=), d);
    else if (Yellow(==))m(a, w, o, Green(=), Black(=));
    else if (Green(==)) m(a, w, o, Yellow(=), Black(=));
  } else if (Green(==)) m(a, w, o, r, White(=));
}
