#define N(argo) void argo(void **o, long t, long a, long r, long i)
#define Ta(n, a) o[--t] = a, o[--t] = (void *)n, o[--t] = #n,
#define T(n) Ta(n, 0)
#include <stdio.h>
#include <unistd.h>
#define P printf("%p %5ld %2ld %s\n", o, t, i, __FUNCTION__), usleep(100000)
typedef N((*w_t));

N(m) {
  if (r == 4)
    ((w_t *)o)[0](o, t, a, r, i);
  else
    ((w_t *)o)[t + i * 3](o, t + i * 3, a, r, i);
}
N(jump) { m(o, t + ((long)o[t + i] + 5) * i, a, r, i); }
N(skip) { jump(o, t, a, r, i); }

N(b) { m(o, t, a, r, -1); }
N(ti) { m(o, t, a, r, i); }
N(dot) {
  if (r < 4)
    m(o, t, a, r, +1);
}

N(print) { printf("%s", (char *)o[t + 1]), m(o, t, a, r, i); }
N(A) { m(o, t, a, r, i); }
N(barkcore) {}
N(bark) {
  long ti = t;
  o[t] = barkcore;
  t = a;
  for (long i = 0; i < (long)o[t + 1]; i++)
    ;
  T(b) T(A) T(dot) barkcore(o, ti, t, r, i);
}
// focus on text index
// what information we have to stop and continue execution
#define B(...) 0
N(dump) {
  printf("name: %s\n", (char *)o[t - 1]);
  ((w_t *)o)[t + i * 3](o, t + i * 3, a, r, i);
}
int main() {
  void *o[1024];
  long t = sizeof(o) / sizeof(*o);
  T(b)
  Ta(ti, B(T(b))) T(ti)
      // DB(T(b) T(ti) T(dot))     (T(b) T(ti) T(dot))
      Ta(print, "hey\n") T(dot)((void)0);
  o[0] = dump;
  m(o, t + 1, t, 4, 1);
  return 0;
}
