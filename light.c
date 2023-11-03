#define N(argo)                                                                \
  void argo(void **τ, long α, long β, void **ο, char *σ, long ρ, long δ)
typedef N((*n_t));
#define P (void)0
//#define P                                                                      \
//  printf("%2ld %2ld %2ld %2ld %10s %10s %10s\n", α, β, ρ, δ, (char *)τ[-2],    \
//         __FUNCTION__, rays[(ρ + 1) * δ + 5]),                                 \
//      usleep(2000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};
// clang-format off
N(goTo) { P, ((n_t)τ[δ * 5])(τ + δ * 5, α, β, ο, σ, ρ, δ); }

N(bro ) { if (ρ == 3 || ρ == 2) ; else goTo(τ, 0, β, ο, σ, 3, 1); }
N(o   ) { goTo(τ, α, β, ο, σ, ρ, -1); }
N(tab ) { ((n_t)ο[β + ρ])(τ[2], α, β + 5, ο, σ, ρ, δ); }
typedef struct t_t {
  long i;
  long count;
  void ***arms;
  char *fruitful;
  char *trimed;
  char *is_lr;
} t_t;
N(tab4o4_switch) { ((n_t *)τ[-1])[(ρ + 1) * δ + 4](τ, α, β, ο, σ, ρ, δ); }
N(tab5o5_switch) { ((n_t *)τ[-1])[(ρ + 1) * δ + 5](τ, α, β, ο, σ, ρ, δ); }

N(t_connector) {
  t_t *c = τ[+1];
  goTo(c->arms[c->i], α, β, ο, σ, ρ, δ);
}
int propeller(t_t*c) {
  long oi = c->i;
  while((c->i = (c->i + 1) % c->count) && c->trimed[c->i]);
  return oi < c->i;
}
N(Yellow_Navy   ) { goTo(τ, α, β, ο, σ, ρ, 1); }
N(Yellow_Lime   ) { t_t *c = τ[+1];
                    (c->fruitful[c->i] = 1), goTo(τ, α, β, ο, σ, ρ, 1); }
N(Yellow_Maroon ) { t_t *c = τ[+1];
                    if (c->fruitful[c->i])        goTo(τ, α, β, ο, σ, !propeller(c) * 2, 1);
                    else if (c->count == 1)       goTo(τ, α, β, ο, σ, ρ, 1);
                    else (c->fruitful[c->i] = 1), goTo(τ, α, β, ο, σ, !propeller(c) * 2, 1); }
N(Yellow_Olive  ) { t_t *c = τ[+1];
                    (c->fruitful[c->i] = 1),      goTo(τ, α, β, ο, σ, !propeller(c) * 2 + 1, 1); }
N(Red_Navy      ) { goTo(τ, α, β, ο, σ, ρ, 1); }
N(Red_Lime      ) { P; }
N(Red_Maroon    ) { t_t *c = τ[+1];               goTo(τ, α, β, ο, σ, !propeller(c) * 2, 1); }
N(Red_Olive     ) { P; }
N(Green_Navy    ) { goTo(τ, α, β, ο, σ, ρ, 1); }
N(Green_Lime    ) { t_t *c = τ[+1];
                    (c->fruitful[c->i] = 1),      goTo(τ, α, β, ο, σ, ρ, 1); }
N(Green_Maroon  ) { P; }
N(Green_Olive   ) { P; }
N(Blue_Navy     ) { goTo(τ, α, β, ο, σ, ρ, 1); }
N(Blue_Lime     ) { P; }
N(Blue_Maroon   ) { P; }
N(Blue_Olive    ) { P; }
N(nop) { printf("nop\n"); }
N(t_Yellow_heart) {
  (ο[--β] = nop),
  (ο[--β] = Yellow_Olive),
  (ο[--β] = Yellow_Maroon),
  (ο[--β] = Yellow_Lime),
  (ο[--β] = Yellow_Navy),
  t_connector(τ, α, β, ο, σ, ρ, δ);
}
N(t_Red_heart) {
  (ο[--β] = nop),
  (ο[--β] = Red_Olive),
  (ο[--β] = Red_Maroon),
  (ο[--β] = Red_Lime),
  (ο[--β] = Red_Navy),
  t_connector(τ, α, β, ο, σ, ρ, δ);
}
N(t_Green_heart) {
  (ο[--β] = nop),
  (ο[--β] = Green_Olive),
  (ο[--β] = Green_Maroon),
  (ο[--β] = Green_Lime),
  (ο[--β] = Green_Navy),
  t_connector(τ, α, β, ο, σ, ρ, δ);
}
N(t_Blue_heart) {
  (ο[--β] = nop),
  (ο[--β] = Blue_Olive),
  (ο[--β] = Blue_Maroon),
  (ο[--β] = Blue_Lime),
  (ο[--β] = Blue_Navy),
  t_connector(τ, α, β, ο, σ, ρ, δ);
}
// clang-format on
N(t_heart) {
  if (ρ == 3 || ρ == 1) {
    static n_t full_tab[] = {goTo,          goTo,        goTo,
                             goTo,          0,           t_Blue_heart,
                             t_Green_heart, t_Red_heart, t_Yellow_heart};
    τ[-1] = full_tab;
    τ[+0] = tab4o4_switch;
    tab4o4_switch(τ, α, β, ο, σ, ρ, δ);
  } else
    goTo(τ, α, β, ο, σ, ρ, δ);
}
N(t_left_hearted) {
  P;
  goTo(τ, α, β, ο, σ, ρ, δ);
}
N(t_cross_heart) {
  P;
  goTo(τ, α, β, ο, σ, ρ, δ);
}
N(forward) { goTo(τ, α, β, ο, σ, ρ, 1); }
#include <string.h>
N(init_arms_end) {
  t_t *c = τ[+1];
  c->i = 0;
  τ[0] = ο[α + 3];
  ((n_t)τ[0])(τ, α, β, ο, σ, ρ, δ);
}
N(Purple_t_show_heart) {
  t_t *c = τ[+1];
  if (strcmp(ο[α + 2], τ[-2]) == 0 && ο[α + 0] == 0) {
    τ[0] = t_left_hearted;
    t_t *pc = ο[α + 1];
    pc->is_lr[pc->i] = 1;
    c->is_lr = pc->is_lr;
    ο[α + 3] = t_cross_heart;
  }
  (ο[(β -= 5) + ρ] = forward), goTo(c->arms[0], α, β, ο, σ, ρ, δ);
}
N(init_goin_arm);
N(init_iplusplus) {
  t_t *c = τ[+1];
  c->i++;
  init_goin_arm(τ, α, β, ο, σ, ρ, δ);
}
N(init_goin_arm) {
  t_t *c = τ[+1];
  if (c->i < c->count) {
    c->is_lr[c->i] = 0;
    ο[α + 0] = 0;
    ο[α + 1] = c;
    (ο[(β -= 5) + 4] = init_iplusplus), goTo(c->arms[c->i], α, β, ο, σ, 4, 1);
  } else
    ((n_t)ο[β + 2])(τ, α, β + 3, ο, σ, (long)ο[β + 1], (long)ο[β + 0]);
}
N(Yellow_Green_t_show_heart) {
  t_t *c = τ[1];
  char is_lr[c->count];
  c->is_lr = is_lr;
  ο[α + 2] = τ[-2];
  ο[α + 3] = t_heart;
  (ο[--β] = init_arms_end), (ο[--β] = (void *)ρ), (ο[--β] = (void *)δ),
      init_goin_arm(τ, α, β, ο, σ, ρ, δ);
}
N(t_show_heart) {
  static n_t tab[] = {goTo,
                      goTo,
                      goTo,
                      goTo,
                      goTo,
                      0,
                      goTo,
                      Yellow_Green_t_show_heart,
                      goTo,
                      Yellow_Green_t_show_heart,
                      Purple_t_show_heart};
  τ[-1] = tab;
  τ[0] = tab5o5_switch;
  tab5o5_switch(τ, α, β, ο, σ, ρ, δ);
}
#define T(nar) #nar, 0, nar, 0, 0
#define B(...) (2 + (void *[]){"tab", 0, tab, 0, τ, __VA_ARGS__, "o", 0, o})
#define D(name, ...)                                                           \
  N(name) {                                                                    \
    void **arms[] = {__VA_ARGS__};                                             \
    char fruitful[sizeof(arms) / sizeof(*arms)] = {};                          \
    char trimed[sizeof(arms) / sizeof(*arms)] = {};                            \
    τ[1] = &(t_t){.i = 0,                                                      \
                  .count = sizeof(arms) / sizeof(*arms),                       \
                  .arms = arms,                                                \
                  .fruitful = fruitful,                                        \
                  .trimed = trimed};                                           \
    τ[0] = t_show_heart;                                                       \
    t_show_heart(τ, α, β, ο, σ, ρ, δ);                                         \
  }
// clang-format off
N(Yellow_Green_term) {
  char*s = τ[1];
  long i = 0;
  while (s[i] && s[i] == σ[i]) i++;
  if (s[i] == 0) (ο[α++] = s), goTo(τ, α, β, ο, σ + i, ρ, δ);
  else                         goTo(τ, α, β, ο, σ, ρ - 1, δ);
}
N(Purple_term) {
  ((long*)ο)[α + 0]++;
  goTo(τ, α, β, ο, σ, ρ, δ);
}
N(term) {
  static n_t tab[] = {
    goTo,               // Fuchsia
    goTo,               // Olive
    goTo,               // Maroon
    goTo,               // Lime
    goTo,               // Navy
    goTo,               // 0
    goTo,               // Blue
    Yellow_Green_term,  // Green                                                          
    goTo,               // Red
    Yellow_Green_term,  // Yellow                                                          
    Purple_term,        // Purple
  }; 
  τ[-1] = tab;
  τ[ 0] = tab5o5_switch;
  tab5o5_switch(τ, α, β, ο, σ, ρ, δ);
};
N(print ) {
  if (δ == 1 && ρ != 0) {
    printf("(");
    for (long i = 0; i < α; i++)
      printf("%s", (char*)ο[i]);
    (α = 0), printf(")%s\n", rays[(ρ + 1) * δ + 5]);
  }
  goTo(τ, α, β, ο, σ, ρ, δ);
}
N(n0) { if (δ == 1 && ρ < 4) ο[α++] = "0"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(n1) { if (δ == 1 && ρ < 4) ο[α++] = "1"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(n2) { if (δ == 1 && ρ < 4) ο[α++] = "2"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(n3) { if (δ == 1 && ρ < 4) ο[α++] = "3"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(n4) { if (δ == 1 && ρ < 4) ο[α++] = "4"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(n5) { if (δ == 1 && ρ < 4) ο[α++] = "5"; goTo(τ, α, β, ο, σ, ρ, δ); }
N(a) { τ[+1] = "a"; term(τ, α, β, ο, σ, ρ, δ); }
N(aa){ τ[+1] = "aa";term(τ, α, β, ο, σ, ρ, δ); }
N(b) { τ[+1] = "b"; term(τ, α, β, ο, σ, ρ, δ); }
N(s) { τ[+1] = "s"; term(τ, α, β, ο, σ, ρ, δ); }
N(ε) { τ[+1] = "";  term(τ, α, β, ο, σ, ρ, δ); }
D(n345,
  B(T(n3)),
  B(T(n4)),
  B(T(n5)))
D(n123,
  B(T(n1)),
  B(T(n2)),
  B(T(n3)))
D(ab,
  B(T(ε)),
  B(T(a)),
  B(T(b)),
)
D(abS,  B(T(ab), T(ab), T(ab)))
N(s_ss) { goTo(τ, α, β, ο, "ss", ρ, δ); }
N(s_ba) { goTo(τ, α, β, ο, "ba", ρ, δ); }
N(s_aaaaaa) { goTo(τ, α, β, ο, "aaaaaa", ρ, δ); }
D(A2,B(T(n3), T(ε)),
     B(T(n4), T(aa),T(A2)),
     B(T(n5), T(a), T(A2)))
D(A1,B(T(n1), T(aa),T(A2)),
     B(T(n2), T(a), T(A2)))
D(sS,
  B(T(ε)),
  B(T(s), T(sS), T(sS)),
  B(T(s), T(sS), T(sS)),
)
D(S, B(T(b)),
     B(T(S), T(a)))
int main() {
  //void **τ = 2 + (void *[]) { T(bro), T(s_ba), T(S), T(print), T(o) };
  //void **τ = 2 + (void *[]) { T(bro), T(s_ba), T(n123), T(print), T(o) };
  //void **τ = 2 + (void *[]) { T(bro), T(s_ss), T(sS), T(print), T(o) };
  void **τ = 2 + (void *[]) { T(bro), T(s_aaaaaa), T(A1), T(print), T(o) };
  long  α = 0;
  void *ο[512];
  long  β = sizeof(ο) / sizeof(*ο);
  goTo(τ, α, β, ο, "", 3, 1);
}
