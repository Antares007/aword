#define N(argo) void argo(void **t, long a, long b, void **o, char *s, long r, long d)
typedef N((*n_t));

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Olive", "Maroon", "Lime", "Navy", 0, "Blue",  "Green",  "Red",  "Yellow"};
#define P printf("%10s %10s %10s\n", (char*)t[-2], rays[(r + 1) * d + 4], __FUNCTION__), usleep(200000)
void ti(const char*n, long r, long d);
N(go      ) { 
  ti(t[-2], r, d);
  ((n_t)t[d * 5])(t + d * 5, a, b, o, s, r, d);
}
N(bo_heart) {
  if (r == 3 || r == 2) P;
  else go(t, 0, b, o, t[1], 3, 1);
}
N(bo      ) {
  t[0] = bo_heart;
  t[1] = s;
  bo_heart(t, a, b, o, s, r, d);
}
N(dot ) { go(t, a, b, o, s, r, -1); }
N(tab ) { ti(t[-2], r, d); ((n_t *)o[b])[r](o[b + 1], a, b + 2, o, s, r, d); }
typedef struct t_t {
  long   i;
  long   count;
  void **arms;
  char  *fruitful;
} t_t;
N(tab_switch) { ((n_t *)t[-1])[(r + 1) * d + 4](t, a, b, o, s, r, d); }
#define Connector(Yellow)                               \
  N(connect_##Yellow) {                                 \
    static n_t tab[] = {                                \
      connect_##Yellow##_Navy,                          \
      connect_##Yellow##_Lime,                          \
      connect_##Yellow##_Maroon,                        \
      connect_##Yellow##_Olive                          \
    };                                                  \
    t_t *c = t[+1];                                     \
    ti(t[-2], r, d), (o[--b] = t), (o[--b] = tab), \
    go(c->arms[c->i], a, b, o, s, r, d);                \
  }

N(connect_Yellow_Navy  ) { go(t, a, b, o, s, r, d); }
N(connect_Yellow_Lime  ) {
  t_t *c = t[+1];
  c->fruitful[c->i] = 1;
  go(t, a, b, o, s, r, +1);
}
N(connect_Yellow_Maroon) {
  assert(d < 0 && r == 2);
  t_t *c = t[+1];
  char is_fruitful = c->fruitful[c->i];
  c->i = (c->i + 1) % c->count;
  if (is_fruitful) {
    go(t, a, b, o, s, c->i == 0 ? 2 : 0, +1);
  } else if (c->i == 0) {
    if (1 < c->count) c->count--, go(t, a, b, o, s, r, +1);
    else go(t, a, b, o, s, r, d);
  } else {
    c->count--;
    c->i--;
    for (long i      = c->i; i < c->count; i++)
      (c->arms[i]    = c->arms[i + 1]),
      (c->fruitful[i] = c->fruitful[i + 1]);
    go(t, a, b, o, s, 0, d);
  }
}
N(connect_Yellow_Olive) {
  t_t *c = t[+1];
  c->fruitful[c->i] = 1;
  c->i = (c->i + 1) % c->count;
  go(t, a, b, o, s, c->i == 0 ? 3 : 1, 1);
}
Connector(Yellow)
N(connect_Red_Navy  ) { go(t, a, b, o, s, r, d); }
N(connect_Red_Lime  ) { P; }
N(connect_Red_Maroon) { 
  t_t *c = t[+1];
  c->i = (c->i + 1) % c->count;
  go(t, a, b, o, s, c->i == 0 ? 2 : 0, 1);
}
N(connect_Red_Olive ) { P; }
Connector(Red)
N(connect_Green_Navy   ) { go(t, a, b, o, s, r, d); }
N(connect_Green_Lime   ) {
  t_t *c = t[+1];
  c->fruitful[c->i] = 1;
  go(t, a, b, o, s, r, +1);
}
N(connect_Green_Maroon ) { P; }
N(connect_Green_Olive  ) { P; }
Connector(Green)
N(connect_Blue_Navy   ) { go(t, a, b, o, s, r, d); }
N(connect_Blue_Lime   ) { P; }
N(connect_Blue_Maroon ) { P; }
N(connect_Blue_Olive  ) { P; }
Connector(Blue)
N(t_heart) {
  static n_t full_tab[] = {
      go, go, go, go,
      0,
      connect_Blue,
      connect_Green,
      connect_Red,
      connect_Yellow,
  };
  t[-1]  = full_tab;
  t[+0]  = tab_switch;
  t_t *c = t[+1];
  char fruitful[c->count];
  for (long i = 0; i < c->count; i++) fruitful[i] = 0;
  c->fruitful = fruitful;
  if (r == 2) go(t, a, b, o, s, 0, -1);
  else tab_switch(t, a, b, o, s, r, d);
}

N(n0  ) { if (d == 1) o[a++] = (void*)'0'; go(t, a, b, o, s, r, d); }
N(n1  ) { if (d == 1) o[a++] = (void*)'1'; go(t, a, b, o, s, r, d); }
N(n2  ) { if (d == 1) o[a++] = (void*)'2'; go(t, a, b, o, s, r, d); }
N(n3  ) { if (d == 1) o[a++] = (void*)'3'; go(t, a, b, o, s, r, d); }
N(n4  ) { if (d == 1) o[a++] = (void*)'4'; go(t, a, b, o, s, r, d); }
N(n5  ) { if (d == 1) o[a++] = (void*)'5'; go(t, a, b, o, s, r, d); }

N(Yellow_Green_term) {
  if (*s == *(char*)t[1])
    (o[a++] = (void*)(long)*s),
      go(t, a, b, o, s + 1, r, d);
  else go(t, a, b, o, s, r - 1, -1);
}
N(term  ) { 
  static n_t tab[] = {
    go,                 // Olive
    go,                 // Maroon
    go,                 // Lime
    go,                 // Navy
    go,                 // 0
    go,                 // Blue
    Yellow_Green_term,  // Green                                                          
    go,                 // Red
    Yellow_Green_term,  // Yellow                                                          
  }; 
  t[-1] = tab;
  t[ 0] = tab_switch;
  tab_switch(t, a, b, o, s, r, d);
};
N(at  ) { t[+1] = "a"; term(t, a, b, o, s, r, d); }
N(bt  ) { t[+1] = "b"; term(t, a, b, o, s, r, d); }
N(st  ) { t[+1] = "s"; term(t, a, b, o, s, r, d); }
N(p_chars ) {
  if (d == 1) {
    printf("%s(", rays[(r + 1) * d + 4]);
    for (long i = 0; i < a; i++)
      printf("%c", (char)(long)o[i]);
    (a = 0), printf(")\n");
  }
  go(t, a, b, o, s, r, d);
}
#define T(nar) #nar, 0, nar, 0, 0
#define B(...) (2 + (void*[]) {T(tab), __VA_ARGS__, T(dot)})
#define D(name, ...)                                        \
  N(name) {                                                 \
    void*arms[] = { __VA_ARGS__ };                          \
    t[1] = &(t_t) {                                         \
      .i = 0,                                               \
      .count = sizeof(arms) / sizeof(*arms),                \
      .arms = arms };                                       \
    t_heart(t, a, b, o, s, r, d);                           \
  }

D(n345,
  B(T(n3)),
  B(T(n4)),
  B(T(n5)))
D(n123,
  B(T(n1)),
  B(T(n2)),
  B(T(n3)))
N(ε) { go(t, a, b, o, s, r, d); }
D(sS,
  B(T(n0), T(ε)),
  B(T(n1), T(st), T(sS), T(sS)),
  B(T(n2), T(st), T(sS), T(sS)))
D(εab,
  B(T(ε)),
  B(T(at)),
  B(T(bt)))
D(abS, B(T(εab), T(εab), T(εab)))
void ti_init();
void ti_step(const char*, long, long);
void ti(const char*n, long r, long d) {
  //ti_step(n, r, d);
}
int main() {
  void **text = 2 + (void *[]){ T(bo), T(sS), T(p_chars), T(dot) };
  long  a = 0;
  void *o[512];
  long  b = sizeof(o) / sizeof(*o);
  ti_init();
  go(text, a, b, o, "ss", 3, 1);
}
