void not(aword) {
  if (White(==)) {
    if (Red(==)) m(a, w, o, Yellow(=), d);
    else if (Yellow(==)) m(a, w, o, Green(=), Black(=));
    else if (Green(==)) m(a, w, o, Yellow(=), Black(=));
  } else if (Green(==)) m(a, w, o, r, White(=));
}
void and (aword) {
  if (White(==)) {
    if (Yellow(==))
      m(a, w, o, Green(=), Black(=));
    else if (Green(==))
      m(a, w, o, Yellow(=), d);
  } else if (Green(==))
    m(a, w, o, r, White(=));
}
void or (aword) {
  if (White(==)) {
    if (Blue(==))
      m(a, w, o, Yellow(=), d);
    else if (Yellow(==))
      m(a, w, o, Green(=), Black(=));
    else if (Green(==))
      m(a, w, o, Yellow(=), Black(=));
  } else if (Green(==))
    m(a, w, o, r, White(=));
}
