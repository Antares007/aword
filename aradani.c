#include "aword.h"
void not(aword) {
  if (White(==)) {
    if (Red(==))          m(t, a, w, o, Yellow(=),  d,        s);
    else if (Yellow(==))  m(t, a, w, o, Green(=),   Black(=), s);
    else if (Green(==))   m(t, a, w, o, Yellow(=),  Black(=), s);
  } else if (Green(==))   m(t, a, w, o, r,          White(=), s);
  else                    m(t, a, w, o, r,          d,        s);
}
void and (aword) {
  if (White(==)) {
    if (Yellow(==))       m(t, a, w, o, Green(=),   Black(=), s);
    else if (Green(==))   m(t, a, w, o, Yellow(=),  d,        s);
  } else if (Green(==))   m(t, a, w, o, r,          White(=), s);
  else                    m(t, a, w, o, r,          d,        s);
}
void or (aword) {
  if (White(==)) {
    if (Blue(==))         m(t, a, w, o, Yellow(=),  d,        s);
    else if (Yellow(==))  m(t, a, w, o, Green(=),   Black(=), s);
    else if (Green(==))   m(t, a, w, o, Yellow(=),  Black(=), s);
  } else if (Green(==))   m(t, a, w, o, r,          White(=), s);
  else                    m(t, a, w, o, r,          d,        s);
}
