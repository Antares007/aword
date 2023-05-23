#define White(op) (d op + 3)
#define Black(op) (d op - 3)
#define Yellow(op) (r op 3)
#define Red(op) (r op 2)
#define Green(op) (r op 1)
#define Blue(op) (r op 0)
#define aword long t, long a, long w, struct o_t *o, long r, long d, long s
#define N(argo) void argo(aword)
#define T(aw) a++, o[a++].c = aw, a++
#define Ta(aw, arg) a++, o[a++].c = aw, o[a++].v = (void *)arg
typedef struct o_t {
  union {
    void *v;
    long q;
    N((*c));
    struct o_t *o;
    char *cs;
  };
} o_t;
typedef N((*aword_t));
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#define Log printf("%s", __FUNCTION__), usleep(30000)
N(m) { ((aword_t *)o)[w + d](t, a, w + d, o, r, d, s); }
N(b) { (o[0].q = 1), m(t, a, w, o, r, +3, s); }
N(dot) { m(t, a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, -3, s); }
N(A) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }
N(B) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }
N(O) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }
N(_0) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }
N(_1) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }
N(_2) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }
N(_3) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }
N(_4) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }
N(_5) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }
N(_6) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }
N(_7) { if (Green(==) && White(==)) Log; m(t, a, w, o, r, d, s); }

N(print) {
  if (r == 1 && d == +3)
    printf("%s", o[w + 1].cs);
  m(t, a, w, o, r, d, s);
}
N(tab);
N(term) {
  Log;
  if (Green(==) && White(==) && o[t - 1].cs[0] == o[w + 1].cs[0])
    o[t - 1].cs++, m(t, a, w, o, r, d, s);
  else
    m(t, a, w, o, r, d, s);
}
N(tab) {
  if (Yellow(==))
    m(t, a, o[s + 0].q, o, o[s + 2].q, o[s + 1].q, s + 3);
  else
    m(t, a, w, o, r, +3, s);
}
N(var_heart) {
  if (Green(==) && Black(==)) {
    o[--s].q = r;
    o[--s].q = d;
    o[--s].q = w;
    long *ps = o[w - 1].v;
    long count = ps[-2];
    long index = ps[-1];
    ps[-1] += o[0].q;
    long was_last_index = ps[-1] / count;
    o[0].q = was_last_index;
    ps[-1] = ps[-1] - was_last_index * count;
    m(t, a, ps[index], o, 3, 3, s);
  } else
    m(t, a, w, o, r, d, s);
}
N(S) {
  Log;
  long p0 = (a + 1);
  T(tab), T(_0), T(dot);
  long p1 = (a + 1);
  T(tab), T(_1), T(dot);
  long p2 = (a + 1);
  T(tab), T(_2), T(dot);
  long p3 = (a + 1);
  T(tab), T(_3), T(dot);
  long p4 = (a + 1);
  T(tab), T(_4), T(dot);
  long p5 = (a + 1);
  T(tab), T(_5), T(dot);
  long p6 = (a + 1);
  T(tab), T(_6), T(dot);
  long p7 = (a + 1);
  T(tab), T(_7), T(dot);
  o[w - 1].v = (long[]){8, 0, p0, p1, p2, p3, p4, p5, p6, p7} + 2;
  o[w].c = var_heart;
  var_heart(t, a, w, o, r, d, s);
}
N(noun) {
  if (r == 1 && d == -3)
    o[t++].v = o[w + 1].v;
  m(t, a, w, o, r, d, s);
}
N(print_s) {
  if (r == 1 && d == +3)
    printf("%s\n", o[--t].cs);
  m(t, a, w, o, r, d, s);
}
int main() {
  long a = 0;
  o_t o[512];
  o[a++].q = 1;
  long r = 3, d = 3, s = 512;
  long w = a + 1;
  long t = 256;
  T(b), Ta(noun, " baaa"), T(S), T(S), T(S), T(S), T(print_s), T(dot),
      m(t, a, w, o, r, d, s);
  return 0;
}
