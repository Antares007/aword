#define N(argo) void argo(void **o, long t, long a, long r, long i)
typedef N((*w_t));
// clang-format off
#define White(op) (i op -1)
#define Black(op) (i op  1)
#define Yellow(op)(r op  3)
#define Red(op)   (r op  2)
#define Green(op) (r op  1)
#define Blue(op)  (r op  0)
N(not) {
  if (White(==)) {
    if (Red(==))        Yellow(=);
    else if (Yellow(==))Green(=),  Black(=);
    else if (Green(==)) Yellow(=), Black(=);
  } else if (Green(==)) White(=);
  ((w_t*)o)[a](o, t, a, r, i);
}
N(and) {
  if (White(==)) {
    if (Yellow(==))     Green(=),  Black(=);
    else if (Green(==)) Yellow(=);
  } else if (Green(==)) White(=);
  ((w_t*)o)[a](o, t, a, r, i);
}
N(or) {
  if (White(==)) {
    if (Blue(==))       Yellow(=);
    else if (Yellow(==))Green(=),  Black(=);
    else if (Green(==)) Yellow(=), Black(=);
  } else if (Green(==)) White(=);
  ((w_t*)o)[a](o, t, a, r, i);
}
