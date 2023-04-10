#include <stdio.h>
#include <unistd.h>
#define P printf("%5s %s\n", (char *)b[t].v, __FUNCTION__), usleep(200000)
#define N(argo) void argo(long t, struct base_t *b, long a, long o)
typedef struct base_t {
  union {
    long q;
    void *v;
    N((*c));
  };
} base_t;
typedef N((*n_t));
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
#define MC(Yellow, Red, Green, Blue)                                           \
  b[--o].v = Yellow;                                                           \
  b[--o].v = Red;                                                              \
  b[--o].v = Green;                                                            \
  b[--o].v = Blue
N(s) {
  MC(Yellow, Red, Green, Blue);
  b[t = --o].v = "s";
  MC(Blue, Green, Red, Yellow);
  b[o].c(t, b, a, o);
}
N(d) {
  b[--o].v = "d";
  MC(DarkBlue, DarkYellow, DarkRed, DarkGreen);
  b[a - 1].c(t, b, a - 1, o);
}
N(so) {
  MC(d, d, d, d);
  b[t = --o].v = "so";
  MC(Blue, Green, Red, Yellow);
  b[o].c(t, b, a, o);
}
N(LOVE) {
  MC(DarkYellow, DarkRed, DarkGreen, DarkBlue);
  b[--o].v = "LOVE";
  MC(Blue, Green, Red, Yellow);
  b[a - 1].c(t, b, a - 1, o);
}
N(love) {
  MC(DarkYellow, DarkRed, DarkGreen, DarkBlue);
  b[--o].v = "love";
  MC(Blue, Green, Red, Yellow);
  b[a - 1].c(t, b, a - 1, o);
}
int main() {
  long t;
  base_t b[1024];
  long a = 0, o = sizeof(b) / sizeof(*b);
  b[a++].v = s;
  b[a++].v = love;
  b[a++].v = so;
  b[a++].v = LOVE;
  d(t, b, a, o);
  return 0;
}
