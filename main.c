#define N(argo) void argo(void **o, long t, long a, long r, long i)
#define Tab(n, a, b) o[--t] = a, o[--t] = (void *)n, o[--t] = b,
#define Ta(n, a) Tab(n, a, 0)
#define T(n) Ta(n, 0)
#include <stdio.h>
#include <unistd.h>
#define P printf("%p %5ld %2ld %s\n", o, t, i, __FUNCTION__), usleep(100000)
typedef N((*w_t));

N(m) { ((w_t *)o)[t + i * 3](o, t + i * 3, a, r, i); }
N(jump) { m(o, t + ((long)o[t + i] + 5) * i, a, r, i); }
N(skip) { jump(o, t, a, r, i); }

N(b) { m(o, t, a, r, -1); }
N(ti) { P, m(o, t, a, r, i); }
N(dot) { m(o, t, a, r, +1); }

N(print) { printf("%s", (char *)o[t + 1]), m(o, t, a, r, i); }
N(A) { m(o, t, a, r, i); }
N(barkcore) {}
N(bark) {
  long ti = t;
  o[t] = barkcore;
  t = a;
  T(b) T(A) T(dot) barkcore(o, ti, t, r, i);
}
int main() {
  void *o[1024];
  long t = sizeof(o) / sizeof(*o);
  T(b)
  T(ti)
  // T(ti)
  //  DB(T(b) T(ti) T(dot))     (T(b) T(ti) T(dot))
  Ta(print, "hey\n") T(dot)
  m(o, t + 1, t, 5, 1);
  return 0;
}
