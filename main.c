#include <stdio.h>
#include <unistd.h>
#define P printf("%5s %s\n", (char *)b[t].v, __FUNCTION__), usleep(200000)
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
N(Yellow    ) { P, b[t + 5].c(b, a, t + 9, o); }
N(Red       ) { P, b[t + 6].c(b, a, t + 9, o); }
N(Green     ) { P, b[t + 7].c(b, a, t + 9, o); }
N(Blue      ) { P, b[t + 8].c(b, a, t + 9, o); }
N(DarkBlue  ) { P, b[t - 8].c(b, a, t - 9, o); }
N(DarkGreen ) { P, b[t - 7].c(b, a, t - 9, o); }
N(DarkRed   ) { P, b[t - 6].c(b, a, t - 9, o); }
N(DarkYellow) { P, b[t - 5].c(b, a, t - 9, o); }
N(grow      ) { b[a - 1].c(b, a - 1, t, o); }
N(s) {
  b[--o].v = Yellow, b[o].v = Yellow, b[o].v = Yellow;
  b[--o].v = Red,    b[o].v = Red,    b[o].v = Red;
  b[--o].v = Green,  b[o].v = Green,  b[o].v = Green;
  b[--o].v = Blue,   b[o].v = Blue,   b[o].v = Blue;
  b[t=--o].v = "s";
  b[--o].v = Blue,   b[o].v = Blue,   b[o].v = Blue;
  b[--o].v = Green,  b[o].v = Green,  b[o].v = Green;
  b[--o].v = Red,    b[o].v = Red,    b[o].v = Red;
  b[--o].v = Yellow, b[o].v = Yellow, b[o].v = Yellow;
  Yellow(b, a, t, o);
}
N(d) {
  b[--o].v = "d";
  b[--o].v = DarkBlue;
  b[--o].v = DarkYellow;
  b[--o].v = DarkRed;
  b[--o].v = DarkGreen;
  grow(b, a, t, o);
}
N(sd) {
  b[--o].v = d;
  b[--o].v = Red;
  b[--o].v = Green;
  b[--o].v = Blue;
  b[t = --o].v = "sd";
  b[--o].v = Blue;
  b[--o].v = Green;
  b[--o].v = Red;
  b[--o].v = Yellow;
  Yellow(b, a, t, o);
}
N(wor) {
  b[--o].v = DarkYellow;
  b[--o].v = DarkRed;
  b[--o].v = DarkGreen;
  b[--o].v = DarkBlue;
  b[--o].v = "wor";
  b[--o].v = Blue;
  b[--o].v = Green;
  b[--o].v = Red;
  b[--o].v = Yellow;
  grow(b, a, t, o);
}
N(love_Green_heart) {
  b[a++].v = s;
  b[a++].v = d;
  grow(b, a, t, o);
}
N(love) {
  b[--o].v = DarkYellow;
  b[--o].v = DarkRed;
  b[--o].v = DarkGreen;
  b[--o].v = DarkBlue;
  b[--o].v = "love";
  b[--o].v = Blue;
  b[--o].v = love_Green_heart;
  b[--o].v = Red;
  b[--o].v = Yellow;
  grow(b, a, t, o);
}
int main() {
  long t;
  base_t b[1024];
  long a = 0, o = sizeof(b) / sizeof(*b);
  b[a++].v = s;
  b[a++].v = wor;
  b[a++].v = sd;
  b[a++].v = love;
  b[a++].v = d;
  grow(b, a, t, o);
  return 0;
}
