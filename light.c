#define N(argo)                                                                \
  void argo(void **τ, long α, long β, void **ο, char *σ, long ρ, long δ)
typedef N((*n_t));
#define P                                                                      \
  printf("%10s %10s %10s\n", (char *)τ[-2], rays[(ρ + 1) * δ + 4],             \
         __FUNCTION__),                                                        \
      usleep(20000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Olive", "Maroon", "Lime", "Navy",  0,
                      "Blue",  "Green",  "Red",  "Yellow"};
void ti(const char *n, long ρ, long δ);
// clang-format off
N(goTo) { ti(τ[-2], ρ, δ), ((n_t)τ[δ * 5])(τ + δ * 5, α, β, ο, σ, ρ, δ); }
N(bro ) { if (ρ == 3 || ρ == 2) P; else goTo(τ, 0, β, ο, σ, 3, 1); }
N(o   ) { goTo(τ, α, β, ο, σ, ρ, -1); }
N(tab) { ti(τ[-2], ρ, δ); ((n_t *)ο[β])[ρ](ο[β + 1], α, β + 2, ο, σ, ρ, δ); }
typedef struct t_t {
  long i;
  long count;
  void **arms;
  char *fruitful;
} t_t;
N(tab_switch) { ((n_t *)τ[-1])[(ρ + 1) * δ + 4](τ, α, β, ο, σ, ρ, δ); }
#define Connector(Yellow)                                                      \
  N(t_##Yellow##_heart) {                                                      \
    static n_t tab[] = {Yellow##_Navy, Yellow##_Lime, Yellow##_Maroon,         \
                        Yellow##_Olive};                                       \
    t_t *c = τ[+1];                                                            \
    ti(τ[-2], ρ, δ), (ο[--β] = τ), (ο[--β] = tab),                             \
        goTo(c->arms[c->i], α, β, ο, σ, ρ, δ);                                 \
  }
N(Yellow_Navy   ) { goTo(τ, α, β, ο, σ, ρ, 1); }
N(Yellow_Lime   ) { t_t *c = τ[+1];
                    c->fruitful[c->i] = 1;
                    goTo(τ, α, β, ο, σ, ρ, 1); }
N(Yellow_Maroon ) { t_t *c = τ[+1];
                    if(c->fruitful[c->i]) {
                      goTo(τ, α, β, ο, σ, !(c->i = (c->i + 1) % c->count) * 2, 1);
                    } else if (c->count == 1) {
                      goTo(τ, α, β, ο, σ, ρ, -1);
                    } else {
                      c->count--;
                      for (long i       = c->i; i < c->count; i++)
                        (c->arms[i]     = c->arms[i + 1]),
                        (c->fruitful[i] = c->fruitful[i + 1]);
                      // printf("trimed %ld %ld ", c->i, c->count), P;
                      if (c->i == c->count)
                        (c->i = 0), goTo(τ, α, β, ο, σ, 2, 1);
                      else
                        goTo(τ, α, β, ο, σ, 0, 1);
                    }
                  }
N(Yellow_Olive  ) { t_t *c = τ[+1];
                    c->fruitful[c->i] = 1;
                    goTo(τ, α, β, ο, σ, !(c->i = (c->i + 1) % c->count) * 2 + 1, 1); }
N(Red_Navy      ) { goTo(τ, α, β, ο, σ, ρ, 1); }
N(Red_Lime      ) { P; }
N(Red_Maroon    ) { t_t *c = τ[+1];
                    goTo(τ, α, β, ο, σ, !(c->i = (c->i + 1) % c->count) * 2, 1); }
N(Red_Olive     ) { P; }
N(Green_Navy    ) { goTo(τ, α, β, ο, σ, ρ, 1); }
N(Green_Lime    ) { t_t *c = τ[+1];
                    c->fruitful[c->i] = 1;
                    goTo(τ, α, β, ο, σ, ρ, 1); }
N(Green_Maroon  ) { P; }
N(Green_Olive   ) { P; }
N(Blue_Navy     ) { goTo(τ, α, β, ο, σ, ρ, 1); }
N(Blue_Lime     ) { P; }
N(Blue_Maroon   ) { P; }
N(Blue_Olive    ) { P; }
Connector(Yellow) Connector(Red) Connector(Green) Connector(Blue)
N(t_heart) {
  if (ρ == 2 || ρ == 0) goTo(τ, α, β, ο, σ, ρ, δ);
  else {
    static n_t full_tab[] = {
        goTo, goTo, goTo, goTo, 0,
        t_Blue_heart, t_Green_heart, t_Red_heart, t_Yellow_heart,
    };
    τ[-1]  = full_tab;
    τ[+0]  = tab_switch;
    tab_switch(τ, α, β, ο, σ, ρ, δ);
  }
}
N(Yellow_Green_term) {
  char*s = τ[1];
  long i = 0;
  while (s[i] && s[i] == σ[i]) i++;
  if (s[i] == 0) (ο[α++] = s), goTo(τ, α, β, ο, σ + i, ρ, δ);
  else                         goTo(τ, α, β, ο, σ, ρ - 1, δ);
}
N(term) { 
  static n_t tab[] = {
    goTo,               // Olive
    goTo,               // Maroon
    goTo,               // Lime
    goTo,               // Navy
    goTo,               // 0
    goTo,               // Blue
    Yellow_Green_term,  // Green                                                          
    goTo,               // Red
    Yellow_Green_term,  // Yellow                                                          
  }; 
  τ[-1] = tab;
  τ[ 0] = tab_switch;
  tab_switch(τ, α, β, ο, σ, ρ, δ);
};
N(print ) {
  if (δ == 1 && ρ != 0) {
    printf("(");
    for (long i = 0; i < α; i++)
      printf("%s", (char*)ο[i]);
    (α = 0), printf(")%s\n", rays[(ρ + 1) * δ + 4]);
  }
  goTo(τ, α, β, ο, σ, ρ, δ);
}
#define T(nar) #nar, 0, nar, 0, 0
#define B(...) (2 + (void*[]) {T(tab), __VA_ARGS__, T(o)})
#define D(name, ...)                                        \
  N(name) {                                                 \
    void*arms[] = { __VA_ARGS__ };                          \
    char fruitful[sizeof(arms) / sizeof(*arms)] = {};       \
    τ[1]        = &(t_t) {                                  \
      .i        = 0,                                        \
      .count    = sizeof(arms) / sizeof(*arms),             \
      .arms     = arms,                                     \
      .fruitful = fruitful };                               \
    t_heart(τ, α, β, ο, σ, ρ, δ);                           \
  }
N(n0) { if (δ == 1) ο[α++] = "0"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(n1) { if (δ == 1) ο[α++] = "1"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(n2) { if (δ == 1) ο[α++] = "2"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(n3) { if (δ == 1) ο[α++] = "3"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(n4) { if (δ == 1) ο[α++] = "4"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(n5) { if (δ == 1) ο[α++] = "5"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(a) { τ[+1] = "a"; term(τ, α, β, ο, σ, ρ, δ); }
N(b) { τ[+1] = "b"; term(τ, α, β, ο, σ, ρ, δ); }
N(s) { τ[+1] = "s"; term(τ, α, β, ο, σ, ρ, δ); }
D(n345,
  B(T(n3)),
  B(T(n4)),
  B(T(n5)))
D(n123,
  B(T(n1)),
  B(T(n2)),
  B(T(n3)))
N(ε) { goTo(τ, α, β, ο, σ, ρ, δ); }
D(ab,
  B(T(ε)),
  B(T(a)),
  B(T(b)),
)
D(abS,  B(T(ab), T(ab), T(ab)))
void ti_init();
void ti_step(const char*, long, long);
void ti(const char*n, long ρ, long δ) {
  // printf("%10s %10s\n", n, rays[(ρ + 1) * δ + 4]);
  ti_step(n, ρ, δ);
}
N(s_ss) { goTo(τ, α, β, ο, "ss", ρ, δ); }
N(s_ba) { goTo(τ, α, β, ο, "ba", ρ, δ); }
D(sS,
  B(T(n1), T(s), T(sS), T(sS)),
  B(T(n1), T(s), T(sS), T(sS)),
  B(T(n0), T(ε)),
)
D(S, B(T(b)), B(T(S), T(a)))
int main() {
  void **text = 2 + (void *[]) { T(bro), T(s_ba), T(S), T(print), T(o) };
  long  α = 0;
  void *ο[512];
  long  β = sizeof(ο) / sizeof(*ο);
  ti_init();
  goTo(text, α, β, ο, "", 3, 1);
}
