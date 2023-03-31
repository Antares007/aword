#define N(argo) void argo(void **o, long t, long a, long r, long i)
typedef N((*w_t));
// clang-format off
#define White(op) (i op -1)
#define Purple(op)(i op  1)
#define Yellow(op)(r op  3)
#define Red(op)   (r op  2)
#define Green(op) (r op  1)
#define Blue(op)  (r op  0)
static N(m) { ((w_t*)o)[t + i * 3](o, t + i * 3, a, r, i); }
N(not) {
  if (White(==)) {
    if (Red(==))        m(o, t, a, Yellow(=), i);
    else if (Yellow(==))m(o, t, a, Green(=),  Purple(=));
    else if (Green(==)) m(o, t, a, Yellow(=), Purple(=));
    else                m(o, t, a, r,         i);
  } else if (Green(==)) m(o, t, a, r,         White(=));
  else                  m(o, t, a, r,         i);
}
N(and) {
  if (White(==)) {
    if (Yellow(==))     m(o, t, a, Green(=),  Purple(=));
    else if (Green(==)) m(o, t, a, Yellow(=), i);
    else                m(o, t, a, r,         i);
  } else if (Green(==)) m(o, t, a, r,         White(=));
  else                  m(o, t, a, r,         i);
}
N(or) {
  if (White(==)) {
    if (Blue(==))       m(o, t, a, Yellow(=), i);
    else if (Yellow(==))m(o, t, a, Green(=),  Purple(=));
    else if (Green(==)) m(o, t, a, Yellow(=), Purple(=));
    else                m(o, t, a, r,         i);
  } else if (Green(==)) m(o, t, a, r,         White(=));
  else                  m(o, t, a, r,         i);
}
