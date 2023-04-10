#include <stdio.h>
#include <unistd.h>
#define P printf("%5s %s\n", (char*)b[t].v, __FUNCTION__), usleep(200000)
#define N(argo) void argo(struct base_t *b, long a, long t, long o)
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
N(Yellow    ) { P, b[t + 5].c(b, a, t + 9, o); }
N(Red       ) { P, b[t + 6].c(b, a, t + 9, o); }
N(Green     ) { P, b[t + 7].c(b, a, t + 9, o); }
N(Blue      ) { P, b[t + 8].c(b, a, t + 9, o); }
// t                                       
N(DarkBlue  ) { P, b[t - 8].c(b, a, t - 9, o); }
N(DarkGreen ) { P, b[t - 7].c(b, a, t - 9, o); }
N(DarkRed   ) { P, b[t - 6].c(b, a, t - 9, o); }
N(DarkYellow) { P, b[t - 5].c(b, a, t - 9, o); }
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
  b[o].c(b, a, t, o);
}
N(d) {
  b[--o].v = "d";
  MC(DarkBlue, DarkYellow, DarkRed, DarkGreen);
  b[a - 1].c(b, a - 1, t, o);
}
N(sd) {
  MC(d, Red, Green, Blue);
  b[t = --o].v = "sd";
  MC(Blue, Green, Red, Yellow);
  b[o].c(b, a, t, o);
}
N(wor) {
  MC(DarkYellow, DarkRed, DarkGreen, DarkBlue);
  b[--o].v = "wor";
  MC(Blue, Green, Red, Yellow);
  b[a - 1].c(b, a - 1, t, o);
}
N(love) {
  MC(DarkYellow, DarkRed, DarkGreen, DarkBlue);
  b[--o].v = "love";
  MC(Blue, Green, Red, Yellow);
  b[a - 1].c(b, a - 1, t, o);
}
int main() {
  long t;
  base_t b[1024];
  long a = 0, o = sizeof(b) / sizeof(*b);
  b[a++].v = s;
  b[a++].v = wor;
  b[a++].v = sd;
  b[a++].v = love;
  d(b, a, t, o);
  return 0;
}
