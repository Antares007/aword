#define aword char *t, long a, long w, struct o_t *o, long r, long d, long s
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
#define Log printf("%s %ld %ld\n", __FUNCTION__, r, d), usleep(30000)
N(m) { Log, ((aword_t *)o)[w + d](t, a, w + d, o, r, d, s); }
N(b) { Log, m(t, a, w, o, r, +3, s); }
N(dot) { Log, m(t, a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, -3, s); }
N(A) { Log, m(t, a, w, o, r, d, s); }
N(B) { Log, m(t, a, w, o, r, d, s); }
N(C) { Log, m(t, a, w, o, r, d, s); }
N(D) { Log, m(t, a, w, o, r, d, s); }

N(print) {
  if (r == 1 && d == +3)
    printf("%s", o[w + 1].cs);
  m(t, a, w, o, r, d, s);
}
N(tab) { Log, m(t, a, o[s].q, o, r, o[s + 1].q, s + 2); }
N(toti_heart) {
  Log;
  if (r == 1) {
    printf("wtf\n");
    o[--s].q = d;
    o[--s].q = w;
    m(t, a, o[w - 1].q, o, r, 3, s);
  } else
    m(t, a, w, o, r, d, s);
}
N(toti) {
  Log;
  o[w - 1].q = (a + 1);
  o[w].c = toti_heart;
  T(tab), T(C), T(dot);
  toti_heart(t, a, w, o, r, d, s);
}
N(term) {
  Log;
  m(t, a, w, o, r, d, s);
}
N(var_heart) {
  long *ps = o[w - 1].v;
  for (long i = 0; i < ps[-1]; i++) {
  }
}
N(S) {
  Log;
  long p1 = (a + 1);
  T(tab), Ta(term, "b"), T(dot);
  long p2 = (a + 1);
  T(tab), T(S), Ta(term, "a"), T(dot);
  o[w - 1].v = ((long[]){2, p1, p2} + 1);
  o[w].c = var_heart;
  var_heart(t, a, w, o, r, d, s);
}
// (({a}s)t)
int main() {
  long a = 0;
  o_t o[512];
  long r = 3, d = 3, s = 512;
  long w = a + 1;
  char *t = "baaaa";
  T(b), T(A), T(toti), T(B), T(toti), T(D), T(dot), m(t, a, w, o, r, d, s);
  return 0;
}
