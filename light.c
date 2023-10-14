#define N(argo) void argo(void **t, long a, long b, void **o, char *s, long r, long d)
typedef N((*n_t));

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#define W(nar) #nar, 0, nar, 0, 0, #nar, 0, ti, 0, 0
const char *rays[] = {"Olive", "Maroon", "Lime", "Navy", 0, "Blue",  "Green",  "Red",  "Yellow"};
N(go ) {
  // printf("%10s %10s\n", (char*)t[-2], rays[(r + 1) * d + 4]), usleep(200000);
  ((n_t)t[d * 5])(t + d * 5, a, b, o, s, r, d);
}
N(ti ) { go(t, a, b, o, s, r,  d); }
N(fwd) { go(t, a, b, o, s, r, +1); }
N(bo ) { 
  if(r == 3) return;
  go(t, a, b, o, s, r == 1 ? 3 : r, +1); }
N(dot) { go(t, a, b, o, s, r, -1); }
N(ln ) {
  if (d == 1) {
    for (long i = 0; i < a; i++)
      printf("%s", (char*)o[i]);
    (a = 0), printf("\n");
  }
  go(t, a, b, o, s, r, d);
}


N(tab ) { ((n_t *)o[b])[r](o[b + 1], a, b + 2, o, s, r, d); }
typedef struct t_t {
  long i;
  long count;
  void **arms;
} t_t;
N(connect_Green_Navy   ) { printf("%s %s\n", __FUNCTION__, rays[(r + 1) * d + 4]); }
N(connect_Green_Lime   ) { go(t, a, b, o, s, 1, 1); }
N(connect_Green_Maroon ) { printf("%s %s\n", __FUNCTION__, rays[(r + 1) * d + 4]); }
N(connect_Green_Olive  ) { printf("%s %s\n", __FUNCTION__, rays[(r + 1) * d + 4]); }
N(tw_Green             ) {
  static n_t tab[] = {
    connect_Green_Navy,
    connect_Green_Lime,
    connect_Green_Maroon,
    connect_Green_Olive
  };
  t_t *c = t[+1]; (o[--b] = t), (o[--b] = tab), go(c->arms[c->i], a, b, o, s, r, d);
}
N(connect_Yellow_Navy  ) { printf("%s %s\n", __FUNCTION__, rays[(r + 1) * d + 4]); }
N(connect_Yellow_Lime  ) { go(t, a, b, o, s, 1, 1); }
N(connect_Yellow_Maroon) { printf("%s %s\n", __FUNCTION__, rays[(r + 1) * d + 4]); }
N(connect_Yellow_Olive ) {
  t_t *c = t[+1];
  c->i = (c->i + 1) % c->count;
  go(t, a, b, o, s, c->i == 0 ? 3 : 1, 1);
}
N(tw_Yellow) {
  static n_t tab[] = {
    connect_Yellow_Navy,
    connect_Yellow_Lime,
    connect_Yellow_Maroon,
    connect_Yellow_Olive
  };
  t_t *c = t[+1];
  (o[--b] = t), (o[--b] = tab), go(c->arms[c->i], a, b, o, s, r, d);
}
N(tw_heart) {
  ((n_t *)t[-1])[(r + 1) * d + 4](t, a, b, o, s, r, d);
}
N(Olive_stop  ) { go(t, a, b, o, s, r, d); }
N(Maroon_stop ) { printf("%s %s\n", __FUNCTION__, rays[(r + 1) * d + 4]); }
N(Lime_stop   ) { go(t, a, b, o, s, r, d); }
N(Navy_stop   ) { printf("%s %s\n", __FUNCTION__, rays[(r + 1) * d + 4]); }
N(Blue_stop   ) { printf("%s %s\n", __FUNCTION__, rays[(r + 1) * d + 4]); }
N(Red_stop    ) { printf("%s %s\n", __FUNCTION__, rays[(r + 1) * d + 4]); }

#define S(...) 2 + (void *[]){W(tab), __VA_ARGS__, W(dot)}
#define T(name, ...)                                                        \
  N(name) {                                                                 \
    static n_t full_tab[] = {                                               \
        Olive_stop,                                                         \
        Maroon_stop,                                                        \
        Lime_stop,                                                          \
        Navy_stop,                                                          \
        0,                                                                  \
        Blue_stop,                                                          \
        tw_Green,                                                           \
        Red_stop,                                                           \
        tw_Yellow,                                                          \
    };                                                                      \
    t[-1] = full_tab;                                                       \
    t[+0] = tw_heart;                                                       \
    t[+1] = &(t_t){ .i = 0,                                                 \
                    .count = sizeof((void *[]){__VA_ARGS__})/sizeof(void*), \
                    .arms = (void *[]){__VA_ARGS__}};                       \
    tw_heart(t, a, b, o, s, r, d);                                          \
  }

N(n1  ) { if (d == 1) o[a++] = "1"; go(t, a, b, o, s, r, d); }
N(n2  ) { if (d == 1) o[a++] = "2"; go(t, a, b, o, s, r, d); }
N(n3  ) { if (d == 1) o[a++] = "3"; go(t, a, b, o, s, r, d); }
N(n4  ) { if (d == 1) o[a++] = "4"; go(t, a, b, o, s, r, d); }
N(n5  ) { if (d == 1) o[a++] = "5"; go(t, a, b, o, s, r, d); }

T(n345,
  S(W(n3)),
  S(W(n4)),
  S(W(n5))) 
T(n123,
  S(W(n1)),
  S(W(n2)),
  S(W(n3), W(n345))) 

void ti_init();
int main() {
  void **text = 2 + (void *[]){W(bo), W(n123), W(n123), W(n123), W(ln), W(dot)};
  long a = 0;
  void *o[512];
  long b = sizeof(o) / sizeof(*o);
  go(text, a, b, o, "", 3, 1);
}
