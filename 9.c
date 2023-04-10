#include <stdio.h>
#include <unistd.h>
#define P printf("%s\n", __FUNCTION__), usleep(200000)
#define N(argo) void argo(long t, struct base_t *b, long a, long o)
typedef struct base_t {
  union {
    long q;
    void *v;
    N((*c));
  };
} base_t;
typedef N((*n_t));
//
// tbao
// clang-format off
// b
N(Yellow    ) { P, b[t + 5].c(t + 9, b, a, o); }
N(Red       ) { P, b[t + 6].c(t + 9, b, a, o); }
N(Green     ) { P, b[t + 7].c(t + 9, b, a, o); }
N(Blue      ) { P, b[t + 8].c(t + 9, b, a, o); }
// t                                   
N(DarkBlue  ) { P, b[t - 8].c(t - 9, b, a, o); }
N(DarkGreen ) { P, b[t - 7].c(t - 9, b, a, o); }
N(DarkRed   ) { P, b[t - 6].c(t - 9, b, a, o); }
N(DarkYellow) { P, b[t - 5].c(t - 9, b, a, o); }
// o
// clang-format on

N(s) {
  b[--o].v /* DarkYellow */ = Yellow;
  b[--o].v /* DarkRed    */ = Red;
  b[--o].v /* DarkGreen  */ = Green;
  b[--o].v /* DarkBlue   */ = Blue;
  b[t = --o].v = 0;
  b[--o].v /* Blue       */ = Blue;
  b[--o].v /* Green      */ = Green;
  b[--o].v /* Red        */ = Red;
  b[--o].v /* Yellow     */ = Yellow;
  b[o].c(t, b, a, o);
  //  b[a - 1].c(t, b, a - 1, o);
}
N(d) {
  b[--o].v /* Blue       */ = DarkBlue;
  b[--o].v /* Green      */ = DarkYellow;
  b[--o].v /* Red        */ = DarkRed;
  b[--o].v /* Yellow     */ = DarkGreen;
  b[a - 1].c(t, b, a - 1, o);
}
int main() {
  long t;
  base_t b[1024];
  long a = 0, o = sizeof(b) / sizeof(*b);
  b[a++].v = s;
  d(t, b, a, o);
  return 0;
}
