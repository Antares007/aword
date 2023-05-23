#define aword long a, long w, void **o, long r, long d, long s
#define N(argo) void argo(aword)
#define T(aw) a++, o[a++] = aw, a++
typedef N((*aword_t));
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#define Log printf("%s %ld %ld\n", __FUNCTION__, r, d), usleep(30000)
N(m  ) { Log, ((aword_t*)o)[w + d](a, w + d, o, r, d, s); }
N(b  ) { Log, m(a, w, o, r, +3, s); }
N(dot) { Log, m(a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, -3, s); }
N(A  ) { Log, m(a, w, o, r, d, s); }
N(B  ) { Log, m(a, w, o, r, d, s); }
N(C  ) { Log, m(a, w, o, r, d, s); }
N(D  ) { Log, m(a, w, o, r, d, s); }

N(print) {
  if (r == 1 && d == +3)
    printf("%s", (char *)o[w + 1]);
  m(a, w, o, r, d, s);
}
N(tab) { Log, m(a, (long)o[s - 1], o, r, (long)o[s - 2], s - 2); }
N(toti_heart) {
  Log;
  if (r == 1) {
    printf("wtf\n");
    o[s++] = (void *)d;
    o[s++] = (void *)w;
    m(a, (long)o[w - 1], o, r, 3, s);
  } else
    m(a, w, o, r, d, s);
}
N(toti) {
  Log;
  o[w - 1] = (void *)(a + 1);
  o[w] = toti_heart;
  T(tab),T(C),T(dot);
  toti_heart(a, w, o, r, d, s);
}
// (({a}s)t)
int main() {
  long a = 0;
  void *o[512];
  long r = 3, d = 3, s = 256;
  long w = a + 1;

  T(b),T(A),T(toti),T(B),T(toti),T(D),T(dot),m(a, w, o, r, d, s);
  return 0;
}
