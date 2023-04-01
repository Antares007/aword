#include "aword.h"
#include <stdio.h>
#include <unistd.h>
// #define P printf("%p %5ld %2ld %s\n", o, t, i, __FUNCTION__), usleep(100000)
N(jump) { ((w_t *)o)[a](o, t + ((long)o[t + i] + 5) * i, a, r, i); }
N(skip) { jump(o, t, a, r, i); }

N(b) { ((w_t *)o)[a](o, t, a, r, -1); }
N(ti) { ((w_t *)o)[a](o, t, a, r, i); }
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
int main() {
  void *o[1024];
  long t = sizeof(o) / sizeof(*o);
  T(b)
  T(ti)
  T(ti)
  T(text_index)
  T(dot)
  o[--t] = m;
  m(o, t + 2, t, 4, 1);
  return 0;
}
