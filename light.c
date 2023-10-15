#define N(argo) void argo(void **τ, long α, long β, void **ο, char *σ, long ρ, long δ)
typedef N((*n_t));
#define P printf("%10s %10s %10s\n", (char*)τ[-2], rays[(ρ + 1) * δ + 4], __FUNCTION__), usleep(200000)

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Olive", "Maroon", "Lime", "Navy", 0, "Blue",  "Green",  "Red",  "Yellow"};
void ti(const char*n, long ρ, long δ);
N(go) { 
  ti(τ[-2], ρ, δ);
  ((n_t)τ[δ * 5])(τ + δ * 5, α, β, ο, σ, ρ, δ);
}
N(bro) {
  if (ρ == 3 || ρ == 2) P;
  else go(τ, 0, β, ο, σ, 3, 1);
}
N(o ) { go(τ, α, β, ο, σ, ρ, -1); }
N(tab ) { ti(τ[-2], ρ, δ); ((n_t *)ο[β])[ρ](ο[β + 1], α, β + 2, ο, σ, ρ, δ); }
typedef struct t_t {
  long   i;
  long   count;
  void **arms;
  char  *fruitful;
} t_t;
N(tab_switch) { ((n_t *)τ[-1])[(ρ + 1) * δ + 4](τ, α, β, ο, σ, ρ, δ); }
#define Connector(Yellow)                               \
  N(connect_##Yellow) {                                 \
    static n_t tab[] = {                                \
      connect_##Yellow##_Navy,                          \
      connect_##Yellow##_Lime,                          \
      connect_##Yellow##_Maroon,                        \
      connect_##Yellow##_Olive                          \
    };                                                  \
    t_t *c = τ[+1];                                     \
    ti(τ[-2], ρ, δ), (ο[--β] = τ), (ο[--β] = tab), \
    go(c->arms[c->i], α, β, ο, σ, ρ, δ);                \
  }
N(connect_Yellow_Navy  ) { go(τ, α, β, ο, σ, ρ, δ); }
N(connect_Yellow_Lime  ) {
  t_t *c = τ[+1];
  c->fruitful[c->i] = 1;
  go(τ, α, β, ο, σ, ρ, +1);
}
N(connect_Yellow_Maroon) {
  assert(δ < 0 && ρ == 2);
  t_t *c = τ[+1];
  char is_fruitful = c->fruitful[c->i];
  c->i = (c->i + 1) % c->count;
  if (is_fruitful) {
    go(τ, α, β, ο, σ, c->i == 0 ? 2 : 0, +1);
  } else if (c->i == 0) {
    if (1 < c->count) c->count--, go(τ, α, β, ο, σ, ρ, +1);
    else go(τ, α, β, ο, σ, ρ, δ);
  } else {
    c->count--;
    c->i--;
    for (long i      = c->i; i < c->count; i++)
      (c->arms[i]    = c->arms[i + 1]),
      (c->fruitful[i] = c->fruitful[i + 1]);
    go(τ, α, β, ο, σ, 0, δ);
  }
}
N(connect_Yellow_Olive) {
  t_t *c = τ[+1];
  c->fruitful[c->i] = 1;
  c->i = (c->i + 1) % c->count;
  go(τ, α, β, ο, σ, c->i == 0 ? 3 : 1, 1);
}
Connector(Yellow)
N(connect_Red_Navy  ) { go(τ, α, β, ο, σ, ρ, δ); }
N(connect_Red_Lime  ) { P; }
N(connect_Red_Maroon) { 
  t_t *c = τ[+1];
  c->i = (c->i + 1) % c->count;
  go(τ, α, β, ο, σ, c->i == 0 ? 2 : 0, 1);
}
N(connect_Red_Olive ) { P; }
Connector(Red)
N(connect_Green_Navy   ) { go(τ, α, β, ο, σ, ρ, δ); }
N(connect_Green_Lime   ) {
  t_t *c = τ[+1];
  c->fruitful[c->i] = 1;
  go(τ, α, β, ο, σ, ρ, +1);
}
N(connect_Green_Maroon ) { P; }
N(connect_Green_Olive  ) { P; }
Connector(Green)
N(connect_Blue_Navy   ) { go(τ, α, β, ο, σ, ρ, δ); }
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
  τ[-1]  = full_tab;
  τ[+0]  = tab_switch;
  t_t *c = τ[+1];
  char fruitful[c->count];
  for (long i = 0; i < c->count; i++) fruitful[i] = 0;
  c->fruitful = fruitful;
  if (ρ == 2) go(τ, α, β, ο, σ, 0, -1);
  else tab_switch(τ, α, β, ο, σ, ρ, δ);
}

N(n0  ) { if (δ == 1) ο[α++] = (void*)'0'; go(τ, α, β, ο, σ, ρ, δ); }
N(n1  ) { if (δ == 1) ο[α++] = (void*)'1'; go(τ, α, β, ο, σ, ρ, δ); }
N(n2  ) { if (δ == 1) ο[α++] = (void*)'2'; go(τ, α, β, ο, σ, ρ, δ); }
N(n3  ) { if (δ == 1) ο[α++] = (void*)'3'; go(τ, α, β, ο, σ, ρ, δ); }
N(n4  ) { if (δ == 1) ο[α++] = (void*)'4'; go(τ, α, β, ο, σ, ρ, δ); }
N(n5  ) { if (δ == 1) ο[α++] = (void*)'5'; go(τ, α, β, ο, σ, ρ, δ); }

N(Yellow_Green_term) {
  if (*σ == *(char*)τ[1])
    (ο[α++] = (void*)(long)*σ),
      go(τ, α, β, ο, σ + 1, ρ, δ);
  else go(τ, α, β, ο, σ, ρ - 1, -1);
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
  τ[-1] = tab;
  τ[ 0] = tab_switch;
  tab_switch(τ, α, β, ο, σ, ρ, δ);
};
N(a) { τ[+1] = "a"; term(τ, α, β, ο, σ, ρ, δ); }
N(b) { τ[+1] = "b"; term(τ, α, β, ο, σ, ρ, δ); }
N(s) { τ[+1] = "s"; term(τ, α, β, ο, σ, ρ, δ); }
N(p_chars ) {
  if (δ == 1) {
    printf("%s(", rays[(ρ + 1) * δ + 4]);
    for (long i = 0; i < α; i++)
      printf("%c", (char)(long)ο[i]);
    (α = 0), printf(")\n");
  }
  go(τ, α, β, ο, σ, ρ, δ);
}
#define T(nar) #nar, 0, nar, 0, 0
#define B(...) (2 + (void*[]) {T(tab), __VA_ARGS__, T(o)})
#define D(name, ...)                                        \
  N(name) {                                                 \
    void*arms[] = { __VA_ARGS__ };                          \
    τ[1] = &(t_t) {                                         \
      .i = 0,                                               \
      .count = sizeof(arms) / sizeof(*arms),                \
      .arms = arms };                                       \
    t_heart(τ, α, β, ο, σ, ρ, δ);                           \
  }

D(n345,
  B(T(n3)),
  B(T(n4)),
  B(T(n5)))
D(n123,
  B(T(n1)),
  B(T(n2)),
  B(T(n3)))
N(ε) { go(τ, α, β, ο, σ, ρ, δ); }
D(sS,
  B(T(n0), T(ε)),
  B(T(n1), T(s), T(sS), T(sS)),
  B(T(n2), T(s), T(sS), T(sS)))
D(εab,
  B(T(ε)),
  B(T(a)),
  B(T(b)))
D(abS, B(T(εab), T(εab), T(εab)))
void ti_init(); void ti_step(const char*, long, long); void ti(const char*n, long ρ, long δ) {
  ti_step(n, ρ, δ);
}
N(s_ss) { go(τ, α, β, ο, "ss", ρ, δ); }
int main() {
  void **text = 2 + (void *[]){ T(bro), T(s_ss), T(sS), T(p_chars), T(o) };
  long  α = 0;
  void *ο[512];
  long  β = sizeof(ο) / sizeof(*ο);
  ti_init();
  go(text, α, β, ο, "", 3, 1);
}
