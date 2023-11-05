#define N(argo)                                                                \
  void argo(void **τ, long α, long β, void **ο, char *σ, long ρ, long δ)
typedef N((*n_t));
#define P (void)0
//#define P                                                                      \
//  printf("%2ld %2ld %2ld %2ld %10s %10s %10s\n", α, β, ρ, δ, C->name,    \
//         __FUNCTION__, rays[(ρ + 1) * δ + 5])
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};
// clang-format off
typedef struct t_t {
  n_t*rays;
  unsigned long count;
  void ***arms;
  const char*name;
  unsigned long is_lr;
  n_t nar;
  unsigned long i;
  unsigned long fruitful;
  unsigned long trimed;
  void*data;
  void*data2;
} t_t;
#define Tab(nar,a,b) 0, 0, 0, #nar, 0, nar, 0, 0, 0, (a), (b)
#define C ((t_t*)&τ[-5])
#define GET_BIT(value, bit) ((value >> bit) & 1)
#define SET_BIT(value, bit) (value |= (1UL << bit))   

N(goTo          ) { P, ((n_t)τ[δ * 11])(τ + δ * 11, α, β, ο, σ, ρ, δ); }
N(bro           ) { if (ρ == 3 || ρ == 2) ; else goTo(τ, 0, β, ο, σ, 3, 1); }
N(o             ) { goTo(τ, α, β, ο, σ, ρ, -1); }
N(tab           ) { ((n_t)ο[β + ρ])(C->data, α, β + 5, ο, σ, ρ, 1); }
N(tab505_switch ) { C->rays[(ρ + 1) * δ + 5](τ, α, β, ο, σ, ρ, δ); }

int my_propeller(t_t*c) {
  long oi = c->i;
  while((c->i = (c->i + 1) % c->count) && GET_BIT(c->trimed, c->i));
  return oi < c->i;
}
N(Yellow_Lime   ) { SET_BIT(C->fruitful, C->i),     goTo(τ, α, β, ο, σ, ρ, δ); }
N(Yellow_Maroon ) { if (GET_BIT(C->fruitful, C->i)) goTo(τ, α, β, ο, σ, !my_propeller(C) * 2, δ);
                    else if (C->count == 1)         goTo(τ, α, β, ο, σ, ρ, δ);
                    else SET_BIT(C->trimed, C->i),  goTo(τ, α, β, ο, σ, !my_propeller(C) * 2, δ); }
N(Yellow_Olive  ) { SET_BIT(C->fruitful, C->i),     goTo(τ, α, β, ο, σ, !my_propeller(C) * 2 + 1, δ); }
N(Red_Maroon    ) {                                 goTo(τ, α, β, ο, σ, !my_propeller(C) * 2, δ); }
N(Green_Lime    ) { SET_BIT(C->fruitful, C->i),     goTo(τ, α, β, ο, σ, ρ, δ); }
N(nop) { printf("nop\n"); }
N(t_Yellow_heart) {
  (ο[--β] = nop), (ο[--β] = Yellow_Olive),  (ο[--β] = Yellow_Maroon), (ο[--β] = Yellow_Lime), (ο[--β] = goTo),
  goTo(C->arms[C->i], α, β, ο, σ, ρ, δ);
}
N(t_Red_heart) {
  (ο[--β] = nop), (ο[--β] = nop),           (ο[--β] = Red_Maroon),    (ο[--β] = nop),         (ο[--β] = goTo),
  goTo(C->arms[C->i], α, β, ο, σ, ρ, δ);
}
N(t_Green_heart) {
  (ο[--β] = nop), (ο[--β] = nop),           (ο[--β] = nop),           (ο[--β] = Green_Lime),  (ο[--β] = goTo),
  goTo(C->arms[C->i], α, β, ο, σ, ρ, δ);
}
N(t_Blue_heart) {
  (ο[--β] = nop), (ο[--β] = nop),           (ο[--β] = nop),           (ο[--β] = nop),         (ο[--β] = goTo),
  goTo(C->arms[C->i], α, β, ο, σ, ρ, δ);
}
// clang-format on
N(t_heart) {
  if (ρ == 3 || ρ == 1) {
    static n_t rays[] = {
        goTo,         goTo,          goTo,        goTo,           goTo, 0,
        t_Blue_heart, t_Green_heart, t_Red_heart, t_Yellow_heart, goTo};
    (C->rays = rays), (C->nar = tab505_switch)(τ, α, β, ο, σ, ρ, δ);
  } else
    goTo(τ, α, β, ο, σ, ρ, δ);
}
N(t_left_hearted) {
  P;
  goTo(τ, α, β, ο, σ, ρ, δ);
}
N(t_right_heart) {
  static n_t rays[] = {};
  (C->rays = rays), (C->nar = tab505_switch)(τ, α, β, ο, σ, ρ, δ);
}
N(t_left_heart) {
  static n_t rays[] = {};
  (C->rays = rays), (C->nar = tab505_switch)(τ, α, β, ο, σ, ρ, δ);
}
N(t_double_heart) {
  // clang-format off
  void **text = (2 + (void *[]){τ, 0, 0,  "tab", 0, tab,           0, 0, 0, 0, 0,
                                0, 0, 0, "beta", 0, t_right_heart, 0, 0, 0, 0, 0,
                                0, 0, 0, "alfa", 0, t_left_heart,  0, 0, 0, 0, 0,
                                0, 0, 0,    "o", 0, o});
  // clang-format on
  goTo(δ == 1 ? text : τ, α, β, ο, σ, ρ, δ);
}
N(forward) { goTo(τ, α, β, ο, σ, ρ, 1); }
#include <string.h>
N(init_arms_end) { (C->i = 0), (C->nar = C->data)(τ, α, β, ο, σ, ρ, δ); }
N(branch_continue_branching) {
  t_t *c = ο[α + 1];
  if (strcmp(c->name, C->name) == 0 && ο[α + 0] == 0) {
    C->nar = t_left_hearted;
    SET_BIT(c->is_lr, c->i);
    SET_BIT(C->is_lr, c->i);
    c->data = t_double_heart;
  }
  (ο[(β -= 5) + ρ] = forward), goTo(C->arms[0], α, β, ο, σ, ρ, δ);
}
N(init_goin_arm);
N(init_iplusplus) {
  C->i++;
  init_goin_arm(τ, α, β, ο, σ, ρ, δ);
}
N(init_goin_arm) {
  if (C->i < C->count)
    (ο[α + 0] = 0), (ο[(β -= 5) + 4] = init_iplusplus),
        goTo(C->arms[C->i], α, β, ο, σ, 4, 1);
  else
    ((n_t)ο[β + 2])(τ, α, β + 3, ο, σ, (long)ο[β + 1], (long)ο[β + 0]);
}
N(branch_initialization_start) {
  ο[α + 1] = C;
  C->data = t_heart;
  (ο[--β] = init_arms_end), (ο[--β] = (void *)ρ), (ο[--β] = (void *)δ),
      init_goin_arm(τ, α, β, ο, σ, ρ, δ);
}
N(t_show_heart) {
  static n_t rays[] = {goTo,
                       goTo,
                       goTo,
                       goTo,
                       goTo,
                       0,
                       goTo,
                       branch_initialization_start,
                       goTo,
                       branch_initialization_start,
                       branch_continue_branching};
  (C->rays = rays), (C->nar = tab505_switch)(τ, α, β, ο, σ, ρ, δ);
}
#define T(nar) Tab(nar, 0, 0)
#define B(...) (5 + (void *[]){Tab(tab, τ, 0), __VA_ARGS__, T(o)})
#define D(name, ...)                                                           \
  N(name) {                                                                    \
    void **arms[] = {__VA_ARGS__};                                             \
    C->count = sizeof(arms) / sizeof(*arms);                                   \
    C->arms = arms;                                                            \
    (C->nar = t_show_heart)(τ, α, β, ο, σ, ρ, δ);                              \
  }
// clang-format off
N(Yellow_Green_term) {
  char*s = C->data;
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
  static n_t rays[] = {
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
  (C->rays = rays), (C->nar = tab505_switch)(τ, α, β, ο, σ, ρ, δ);
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
N(a) { C->data = "a"; term(τ, α, β, ο, σ, ρ, δ); }
N(aa){ C->data = "aa";term(τ, α, β, ο, σ, ρ, δ); }
N(b) { C->data = "b"; term(τ, α, β, ο, σ, ρ, δ); }
N(s) { C->data = "s"; term(τ, α, β, ο, σ, ρ, δ); }
N(ε) { C->data = "";  term(τ, α, β, ο, σ, ρ, δ); }
D(n345,
  B(T(n3)),
  B(T(n4)),
  B(T(n5)))
D(n123,
  B(T(n1)),
  B(T(n2)),
  B(T(n3), T(n345)))
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
  //void **τ = 5 + (void *[]) { T(bro), T(s_ba), T(S), T(print), T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(s_ba), T(n123), T(n123), T(n123), T(print), T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(s_ss), T(sS), T(print), T(o) };
  void **τ = 5 + (void *[]) { T(bro), T(s_aaaaaa), T(A1), T(print), T(o) };
  long  α = 0;
  void *ο[512];
  long  β = sizeof(ο) / sizeof(*ο);
  goTo(τ, α, β, ο, "", 3, 1);
}
