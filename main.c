#include "aword.h"
#include <stdio.h>
#include <unistd.h>
N(jump) { ((w_t *)o)[a](o, t + ((long)o[t + i] + 5) * i, a, r, i); }
N(skip) { jump(o, t, a, r, i); }

N(b) { ((w_t *)o)[a](o, t, a, r, -1); }
N(dot) {
  if (r == 3)
    r = 1;
  else if (r == 1)
    r = 3;
  ((w_t *)o)[a](o, t, a, r, 1);
}

N(print) { printf("%s", (char *)o[t + 1]), ((w_t *)o)[a](o, t, a, r, i); }
// focus on text index and multitasking
// make a promt
// what information we have to stop and continue execution
N(text_index);
N(m) { ((w_t *)o)[t + i * 3](o, t + i * 3, a, r, i); }
N(and);
N(or);
N(one) { ((w_t *)o)[a](o, t, a, r, i); }
N(add) { ((w_t *)o)[a](o, t, a, r, i); }
N(prn) { ((w_t *)o)[a](o, t, a, r, i); }
int main() {
  void *o[1024];
  long t = sizeof(o) / sizeof(*o);
  T(b) T(one) T(one) T(add) T(one) T(and) T(prn)
  T(text_index)
  T(dot)
  o[--t] = m;
  m(o, t + 2, t, 3, 1);
  return 0;
}
