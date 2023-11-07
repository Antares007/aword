#define N(argo)                                                                \
  void argo(void **τ, long α, long β, void **ο, char *σ, long ρ, long δ)
typedef N((*n_t));
#define P (void)0
//#define P                                                                      \
//  printf("%2ld %2ld %10s %10s %10s\n", α, β, C->name, __FUNCTION__,            \
//         rays[(ρ + 1) * δ + 5]),                                               \
//      usleep(200000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};
typedef struct t_t {
  n_t *rays;
  unsigned long count;
  void ***arms;
  const char *name;
  unsigned long is_lr;
  n_t nar;
  unsigned long i;
  unsigned long fruitful;
  unsigned long trimed;
  void *data;
  long d;
} t_t;
#define Tab(nar, a) 0, 0, 0, (void *)#nar, 0, nar, 0, 0, 0, (void *)(a), 0
#define T(nar) Tab(nar, 0)
#define B(...) (5 + (void *[]){T(tab), __VA_ARGS__, T(o)})
#define C ((t_t *)&τ[-5])
#define ξ ((t_t *)ο[β+2])
#define GET_BIT(value, bit) ((value >> bit) & 1)
#define SET_BIT(value, bit) (value |= (1UL << bit))
#define CLS_BIT(value, bit) (value &= ~(1UL << bit))

#define Sword(n, s, ...)                                                       \
  N(n) {                                                                       \
    static void *rays[] = {__VA_ARGS__};                                       \
    assert(sizeof(rays) / sizeof(*rays) == 11);                                \
    (C->rays = (void *)rays), (C->nar = s)(τ, α, β, ο, σ, ρ, δ);               \
  }
#define Aword(n, ...) Sword(n, tab515_switch, __VA_ARGS__)
#define Atext(n, ...) Sword(n, bat515_switch, __VA_ARGS__)
// clang-format off

N(goTo          ) { P, ((n_t)τ[δ * 11])(τ + δ * 11, α, β, ο, σ, ρ, δ); }
N(bro           ) { if (ρ == 3 || ρ == 2) ; else goTo(τ, 0, β, ο, σ, 3, 1); }
N(o             ) { goTo(τ, α, β, ο, σ, ρ, -δ); }
N(tab           ) { goTo(ο[β], α, β + 3, ο, σ, ρ, (long)ο[β + 1]); }
N(tab515_switch ) { C->rays[(ρ + 1) * δ + 5](τ, α, β, ο, σ, ρ, δ); }
N(bat515_switch ) { (ο[--β] = C),
                    (ο[--β] = (void*)δ),
                    (ο[--β] = τ), goTo(((void**)C->rays[(ρ + 1) * δ + 5]) + 5, α, β, ο, σ, ρ, 1); }
N(totin         ) { void*pc = ξ;
                    (ο[--β] = pc),
                    (ο[--β] = (void*)δ),
                    (ο[--β] = τ), goTo(ξ->arms[ξ->i], α, β, ο, σ, ρ, δ); }
Aword(toti,         goTo, goTo, goTo, goTo, goTo, 0,
                    totin,totin,totin,totin,goTo)

int my_propeller(t_t*c) {
  long oi = c->i;
  while((c->i = (c->i + 1) % c->count) && GET_BIT(c->trimed, c->i));
  return !(oi < c->i);
}
N(Yellow_Lime   ) { SET_BIT(ξ->fruitful, ξ->i),        goTo(τ,α,β,ο,σ,ρ,δ); }
N(Yellow_Maroon ) { if (ξ->count == 1)                 goTo(τ,α,β,ο,σ,ρ,δ);
                    else if(GET_BIT(ξ->fruitful, ξ->i))goTo(τ,α,β,ο,σ,my_propeller(ξ)*2,δ);
                    else SET_BIT(ξ->trimed, ξ->i),     goTo(τ,α,β,ο,σ,my_propeller(ξ)*2,δ); }
N(Yellow_Olive  ) { SET_BIT(ξ->fruitful, ξ->i),        goTo(τ,α,β,ο,σ,my_propeller(ξ)*2+1,δ); }
N(Red_Maroon    ) {                                    goTo(τ,α,β,ο,σ,my_propeller(ξ)*2,δ); }
N(Green_Lime    ) { SET_BIT(ξ->fruitful, ξ->i),        goTo(τ,α,β,ο,σ,ρ,δ); }

Aword(a_Yellow,   goTo, goTo,         goTo,           goTo,         goTo, 0,
                  goTo, Yellow_Lime,  Yellow_Maroon,  Yellow_Olive, goTo)
Aword(a_Red,      goTo, goTo,         goTo,           goTo,         goTo, 0,
                  goTo, goTo,         Red_Maroon,     goTo,         goTo)
Aword(a_Green,    goTo, goTo,         goTo,           goTo,         goTo, 0,
                  goTo, Green_Lime,   goTo,           goTo,         goTo)


void*tab_o[]   = {T(tab),                    T(o)};
void*Blue[]    = {T(tab),T(toti),            T(o)};
void*Green[]   = {T(tab),T(toti),T(a_Green), T(o)};
void*Red[]     = {T(tab),T(toti),T(a_Red),   T(o)};
void*Yellow[]  = {T(tab),T(toti),T(a_Yellow),T(o)};
Atext(t_heart2, tab_o, tab_o, tab_o, tab_o, tab_o, 0,
                Blue,
                Green,
                Red,
                Yellow,
                tab_o)

N(t_heart3_open) { (C->nar = t_heart2)(τ, α, β, ο, σ, ρ, δ); }
Aword(t_heart3, goTo, goTo,          goTo, goTo,          goTo, 0,
                goTo, t_heart3_open, goTo, t_heart3_open, goTo)
#define D(name, ...)                                                           \
  N(name) {                                                                    \
    void **arms[] = {__VA_ARGS__};                                             \
    C->count = sizeof(arms) / sizeof(*arms);                                   \
    C->arms = arms;                                                            \
    (C->nar = t_heart3)(τ, α, β, ο, σ, ρ, δ);                                  \
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
  (C->rays = rays), (C->nar = tab515_switch)(τ, α, β, ο, σ, ρ, δ);
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
#define NAR(n) N(n) { printf("%s", __FUNCTION__); goTo(τ, α, β, ο, σ, ρ, δ); }
N(ln) { printf(".\n"); goTo(τ, α, β, ο, σ, ρ, δ); }
int main() {
  //void **τ = 5 + (void *[]) { T(bro), T(s_ba),    T(S),   T(print), T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(n123),    T(n123),T(n123),  T(print), T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(s_ss),    T(sS),  T(print), T(o) };
  void **τ = 5 + (void *[]) { T(bro), T(s_aaaaaa),T(A1),  T(print), T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(text), T(o) };
  long  α = 0;
  void *ο[512];
  long  β = sizeof(ο) / sizeof(*ο);
  goTo(τ, α, β, ο, "", 3, 1);
}
