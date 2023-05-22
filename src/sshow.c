#include "aradani.h"
#include "aword.h"
#include <stdio.h>
void print(aword) {
  if (r == 1 && d == -3)
    printf("%s", (char *)o[w + 1]);
  m(a, w, o, r, d);
}
#include <assert.h>
#define Tp(text) Ta(print, text)
void stop(aword) {
  if (r == 3 && d == 3)
    m(a, w, o, 1, -3);
  else
    m(a, w, o, r, d);
}
S(toti, {
  T(b) Tp("}") LastArm;
  T(b) Tp("{") RightArm;
});
S(toti2, {
  T(b) Tp(")") LastArm;
  T(b) Tp("(") RightArm;
});
// (({a}s)t)
// (({a}s)t)
// (({a}s)t)
int main() {
  long a = 512;
  void *memory[2 * a];
  void **o = memory + a;
  long r = 3, d = 3;
  o[0] = (void *)a;
  T(b)
  Ta(print, "a")
  T(toti)
  Ta(print, "s")
  T(toti2)
  Ta(print, "t")
  T(toti2)
  Ta(print, "\n")
  T(dot)
  m(a, a + 1, o, r, d);
  return 0;
}
