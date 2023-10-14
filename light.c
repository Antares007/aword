#define N(argo)                                                                \
  void argo(void **t, long a, long b, void **o, char *s, long r, long d)
typedef N((*n_t));

#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#define P (void)0
//\
//  printf("%10s %10s\n", (const char *)t[-2], rays[(r + 1) * d + 4]),           \
//      usleep(200000)
#define T(nar) #nar, 0, nar, 0, 0
const char *rays[] = {"Olive", "Maroon", "Lime", "Navy",  0,
                      "Blue",  "Green",  "Red",  "Yellow"};
N(go) {
  P;
  ((n_t)t[d * 5])(t + d * 5, a, b, o, s, r, d);
}
N(fwd) { go(t, a, b, o, s, r, +1); }
N(bo) { go(t, a, b, o, s, r == 1 ? 3 : r, +1); }
N(dot) { go(t, a, b, o, s, r, -1); }
N(A) { if (d == 1) o[a++] = "a"; go(t, a, b, o, s, r, d); }
N(B) { if (d == 1) o[a++] = "b"; go(t, a, b, o, s, r, d); }
N(ln) {
  if (d == 1) {
    for (long i = 0; i < a; i++)
      printf("%s", (char *)o[i]);
    a = 0;
    printf("\n");
    usleep(20000);
  }
  go(t, a, b, o, s, r, d);
}
N(S) { P; }

N(tab) {
  P;
  ((n_t *)o[b])[r](o[b + 1], a, b + 2, o, s, r, d);
}

typedef struct t_t {
  long i;
  long count;
  void **arms;
} t_t;
N(tw_Yellow_Olive) {
  t_t *c = t[+1];
  c->i = (c->i + 1) % c->count;
  go(t, a, b, o, s, c->i == 0 ? 3 : 1, 1);
}
N(tw_Green) {
  static n_t tab[] = {
      S,   //
      fwd, //
      S,   //
      S,   //
  };
  t_t *c = t[+1];
  (o[--b] = t), (o[--b] = tab), go(c->arms[c->i], a, b, o, s, r, d);
}
N(tw_Yellow) {
  static n_t tab[] = {
      S,               //
      S,               //
      S,               //
      tw_Yellow_Olive, //
  };
  t_t *c = t[+1];
  (o[--b] = t), (o[--b] = tab), go(c->arms[c->i], a, b, o, s, r, d);
}
N(tw_heart) {
  P;
  ((n_t *)t[-1])[(r + 1) * d + 4](t, a, b, o, s, r, d);
}
N(tw) {
  static n_t full_tab[] = {
      go,        // Olive
      go,        // Lime
      go,        // Maroon
      go,        // Navy
      go,        // 0
      go,        // Blue
      tw_Green,  // Green
      go,        // Red
      tw_Yellow, // Yellow
  };
  t[-1] = full_tab;
  t[+0] = tw_heart;
  t[+1] = &(t_t){.i = 0,
                 .count = 2,
                 .arms = (void *[]){2 + (void *[]){T(tab), T(A), T(dot)},
                                    2 + (void *[]){T(tab), T(B), T(dot)}}};
  tw_heart(t, a, b, o, s, r, d);
}

int main() {
  void **text =
      2 + (void *[]){T(bo), T(tw), T(tw), T(tw),T(tw), T(tw), T(tw), T(tw), T(tw), T(ln), T(dot)};
  long a = 0;
  void *o[512];
  long b = sizeof(o) / sizeof(*o);
  go(text, a, b, o, "", 3, 1);
}
