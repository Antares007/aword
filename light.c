#define N(argo) void argo(void **t, long a, long b, void **o, char *s, long r, long d)
typedef N((*n_t));

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#define W(nar) #nar, 0, nar, 0, 0, #nar, 0, ti, 0, 0
const char *rays[] = {"Olive", "Maroon", "Lime", "Navy", 0, "Blue",  "Green",  "Red",  "Yellow"};
#define P printf("%10s %10s\n", (char*)t[-2], rays[(r + 1) * d + 4]), usleep(200000)
N(go ) {
  ((n_t)t[d * 5])(t + d * 5, a, b, o, s, r, d);
}
N(ti ) { go(t, a, b, o, s, r,  d); }
N(fwd) { go(t, a, b, o, s, r, +1); }
N(bo ) { 
  if (r == 3 || r == 2) P;
  else go(t, a, b, o, s, 3, 1);
}
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
N(full_heart) { ((n_t *)t[-1])[(r + 1) * d + 4](t, a, b, o, s, r, d); }
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
    t[+0] = full_heart;                                                       \
    t[+1] = &(t_t){ .i = 0,                                                 \
                    .count = sizeof((void *[]){__VA_ARGS__})/sizeof(void*), \
                    .arms = (void *[]){__VA_ARGS__}};                       \
    full_heart(t, a, b, o, s, r, d);                                          \
  }

N(n1  ) { if (d == 1) o[a++] = "1"; go(t, a, b, o, s, r, d); }
N(n2  ) { if (d == 1) o[a++] = "2"; go(t, a, b, o, s, r, d); }
N(n3  ) { if (d == 1) o[a++] = "3"; go(t, a, b, o, s, r, d); }
N(n4  ) { if (d == 1) o[a++] = "4"; go(t, a, b, o, s, r, d); }
N(n5  ) { if (d == 1) o[a++] = "5"; go(t, a, b, o, s, r, d); }

N(Yellow_term) {
  if (*s == *(char*)t[1]) (o[a++] = (void*)(long)*s), go(t, a, b, o, s + 1, r, d); // Yellow
  else go(t, a, b, o, s, 2, -1); // Maroon
}
N(Green_term) { 
  if (*s == *(char*)t[1]) (o[a++] = (void*)(long)*s), go(t, a, b, o, s + 1, r, d); // Green
  else go(t, a, b, o, s, 0, -1); // Navy
}
N(term  ) { 
  static n_t tab[] = {
    go,           // Olive
    go,           // Maroon
    go,           // Lime
    go,           // Navy
    go,           // 0
    go,           // Blue
    Green_term,   // Green                                                          
    go,           // Red
    Yellow_term,  // Yellow                                                          
  }; 
  t[-1] = tab;
  t[ 0] = full_heart;
  full_heart(t, a, b, o, s, r, d);
};
N(at  ) { t[0] = term; t[+1] = "a"; term(t, a, b, o, s, r, d); }
N(bt  ) { t[0] = term; t[+1] = "b"; term(t, a, b, o, s, r, d); }
N(p_chars ) {
  if (d == 1) {
    for (long i = 0; i < a; i++)
      printf("%c", (char)(long)o[i]);
    (a = 0), printf("\n");
  }
  go(t, a, b, o, s, r, d);
}

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
  void **text = 2 + (void *[]){W(bo),
    W(at),
    W(bt),
    //W(n123), W(n123), W(n123),
    W(p_chars),
    W(dot)};
  long a = 0;
  void *o[512];
  long b = sizeof(o) / sizeof(*o);
  go(text, a, b, o, "ab", 3, 1);
}
