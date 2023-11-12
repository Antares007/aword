#define N(argo)                                                                \
  void argo(void **τ, long α, long β, void **ο, char *σ, long ρ, long δ)
typedef N((*n_t));
//#define P (void)0
#define P                                                                      \
  printf("%2ld %2ld %10s %10s %10s\n", α, β, C->name, __FUNCTION__,            \
         rays[(ρ + 1) * δ + 5]),                                               \
      usleep(200000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};
typedef struct t_t {
  n_t *rays;
  unsigned long count;
  void       ***arms;
  const char    *name;
  unsigned long i;
  n_t           nar;
  unsigned long is_lr;
  unsigned long fruitful;
  unsigned long trimed;
  void         *data;
  void         *data2;
} t_t;
#define Tab(nar, a, b)  (void *)#nar, 0, 0, (void *)(b), (void *)(a), nar, 0, 0, 0, 0, 0
#define Ta(nar, a)      Tab(nar, a, 0)
#define T(nar)          Tab(nar, 0, 0)
#define B(...)                                                                 \
  (void *[]) { __VA_ARGS__ }
#define C ((t_t *)&τ[-5])
#define OB(r) ((t_t *)&((void ***)ο)[β + (r)*2][-5])
#define GET_BIT(value, bit) ((value >> bit) & 1)
#define SET_BIT(value, bit) (value |= (1UL << bit))
#define CLS_BIT(value, bit) (value &= ~(1UL << bit))

#define sWord(n, s, ...)                                                            \
  N(n) {                                                                            \
    static void *rays[] = {__VA_ARGS__};                                            \
    (C->rays = (void *)rays);                                                       \
    if (ρ < 4) C->nar = s;                                                          \
    s(τ, α, β, ο, σ, ρ, δ);                                                         \
  }
#define aWord(n, ...) sWord(n, tab515_switch, __VA_ARGS__)
#define tWord(n, ...) sWord(n, bat515_switch, __VA_ARGS__)
#define cWord(n, ...)                                                                       \
  N(n) {                                                                                    \
    static void*s[] = {__VA_ARGS__};                                                        \
    if (δ == 1) ST, TR, (ο[--β] = (void*)δ), (ο[--β] = τ), goTo(s + 5, α, β, ο, σ, ρ, δ);   \
    else goTo(τ, α, β, ο, σ, ρ, δ);                                                         \
  }
// clang-format off

void ti_step(const char*name, long r, long d);
void ti_turn();
void ti_late_turn();
void ti_back();
//#define ST printf("%10s %3ld %3ld\n", C->name, ρ, δ)
//#define TR (void)0
//#define TL (void)0
//#define TB (void)0
#define ST ti_step(C->name, ρ, δ)
#define TR ti_turn()
#define TL ti_late_turn()
#define TB ti_back()
N(goTo          ) { ST, ((n_t)τ[δ * 11])(τ + δ * 11, α, β, ο, σ, ρ, δ); }
N(bro           ) { if (ρ == 3 || ρ == 2) ; else TB, goTo(τ, 0, β, ο, σ, 3, 1);
                    //                             TB, goTo(τ, 0, β, ο, σ, (ρ + 1) % 5, 1);
                  }
N(o             ) { TB,           goTo(τ, α, β, ο, σ, ρ, -δ); }
N(tab515_switch ) { C->rays[(ρ + 1) * δ + 5](τ, α, β, ο, σ, ρ, δ); }
N(tab           ) { ST, TL, goTo(ο[β], α, β + 2, ο, σ, ρ, (long)ο[β + 1]); }
N(bat515_switch ) { ST, TR,
                    (ο[--β] = (void*)δ),
                    (ο[--β] = τ),
                    goTo(((void**)C->rays[(ρ + 1) * δ + 5]) + 5, α, β, ο, σ, ρ, 1); }
N(totin         ) { ST, TR;
                    t_t*c = OB((long)C->data);
                    (ο[--β] = (void*)δ),
                    (ο[--β] = τ), goTo(c->arms[c->i] + 5, α, β, ο, σ, ρ, δ); }
aWord(toti,         goTo, goTo, goTo, goTo, goTo, 0,
                    totin,totin,totin,totin,totin)
N(nop           ) { assert(0); }
int my_propeller(t_t*c) {
  long oi = c->i;
  while((c->i = (c->i + 1) % c->count) && GET_BIT(c->trimed, c->i));
  return !(oi < c->i); }
N(Yellow_Lime   ) { SET_BIT(OB(0)->fruitful, OB(0)->i),         goTo(τ,α,β,ο,σ,ρ,δ); }
N(Yellow_Maroon ) { if (OB(0)->count == 1)                      goTo(τ,α,β,ο,σ,ρ,δ);
                    else if(GET_BIT(OB(0)->fruitful, OB(0)->i)) goTo(τ,α,β,ο,σ,my_propeller(OB(0))*2,δ);
                    else SET_BIT(OB(0)->trimed, OB(0)->i),      goTo(τ,α,β,ο,σ,my_propeller(OB(0))*2,δ); }
N(Yellow_Olive  ) { SET_BIT(OB(0)->fruitful, OB(0)->i),         goTo(τ,α,β,ο,σ,my_propeller(OB(0))*2+1,δ); }
N(Red_Maroon    ) {                                             goTo(τ,α,β,ο,σ,my_propeller(OB(0))*2,δ); }
N(Green_Lime    ) { SET_BIT(OB(0)->fruitful, OB(0)->i),         goTo(τ,α,β,ο,σ,ρ,δ); }
aWord(a_Yellow,   goTo, goTo,         goTo,           goTo,         goTo, 0,
                  goTo, Yellow_Lime,  Yellow_Maroon,  Yellow_Olive, goTo)
aWord(a_Red,      goTo, goTo,         goTo,           goTo,         goTo, 0,
                  goTo, goTo,         Red_Maroon,     goTo,         goTo)
aWord(a_Green,    goTo, goTo,         goTo,           goTo,         goTo, 0,
                  goTo, Green_Lime,   goTo,           goTo,         goTo)

void*tab_o[]  = { T(tab),                            T(o) };

void*Blue[]   = { T(tab),               T(o) };
void*Green[]  = { T(tab),               T(o) };
void*Red[]    = { T(tab),               T(o) };
void*Yellow[] = { T(tab),               T(o) };
void*Purple[] = { T(tab),               T(o) };
tWord(t_heart,    tab_o,  tab_o,    tab_o,  tab_o,    tab_o, 0,
                  Blue,   Green,    Red,    Yellow,   Purple)

N(t_init_for_all_Fuchsia     ) {
  OB(1)->i++;
  if (OB(1)->i < OB(1)->count) TB, (ο[α] = 0), goTo(τ, α, β, ο, σ, ρ, -δ);
  else 
    (OB(1)->i = 0), goTo(τ, α, β, ο, σ, (long)C->data, δ);
}
N(t_init_for_all_Yellow_Green) {
  C->data  = (void*)ρ;
  ο[α + 1] = (void*)OB(1)->name;
  goTo(τ, α, β, ο, σ, 4, δ);
}
aWord(for_all_t_init, t_init_for_all_Fuchsia, nop, nop, nop, nop, 0,
                      nop, t_init_for_all_Yellow_Green,
                      nop, t_init_for_all_Yellow_Green,
                      nop)
#include<string.h>
N(conf_tword_t_init_Purple) {
  if (strcmp(ο[α + 1], OB(1)->name) == 0 && ο[α] == 0)
    ;
  goTo(τ, α, β, ο, σ, ρ, δ);
}
aWord(conf_tword_t_init,  goTo, goTo, goTo, goTo, goTo, 0,
                          goTo, goTo, goTo, goTo, conf_tword_t_init_Purple)

N(finish_t_init     ) { (OB(0)->nar = goTo)(τ, α, β, ο, σ, ρ, δ); }
void*t_init_Olive_Lime[]   = { T(tab), T(finish_t_init),                      T(o) };
void*t_init_Yellow_Green[] = { T(tab), T(for_all_t_init),    Tab(toti, 1, 0), T(o) };
void*t_init_Purple[]       = { T(tab), T(conf_tword_t_init), Tab(toti, 1, 0), T(o) };
tWord(t_init,  tab_o, t_init_Olive_Lime,    tab_o, t_init_Olive_Lime,   tab_o,        0,
               tab_o, t_init_Yellow_Green,  tab_o, t_init_Yellow_Green, t_init_Purple)
N(id  ) { goTo(τ, α, β, ο, σ, ρ, δ); }
//cWord(t_init_heart, T(tab), T(t_init), T(t_heart), T(o))

N(t_init_heart1) {
  τ[δ](τ, α, β, ο, σ, ρ, δ);
}
N(δ_switch) { ((n_t)τ[δ])(τ, α, β, ο, σ, ρ, δ); }
N(ρ_switch) { ((n_t)τ[ρ + 1])(τ, α, β, ο, σ, ρ, δ); }
N(t_init_heart) {
  void*ε[] = { Ta(tab, τ), T(o) };
  void*s[] = { Ta(tab, τ), T(t_init), T(t_heart), T(o) };
  τ[+1] = ε;
  τ[+2] = s;
  τ[+3] = ε;
  τ[+4] = s;
  τ[+5] = s;
  τ[+0] = ρ_switch;
}
aWord(t_closed, goTo, goTo,         goTo, goTo,         goTo, 0,
                goTo, t_init_heart, goTo, t_init_heart, t_init_heart)
#define D(name, ...)                                                      \
  N(name) {                                                               \
    void **arms[] = {__VA_ARGS__};                                        \
    C->count = sizeof(arms) / sizeof(*arms);                              \
    C->arms = arms;                                                       \
    (C->nar = t_closed)(τ, α, β, ο, σ, ρ, δ);                             \
  }
N(Yellow_Green_term) {
  char*s = C->data;
  long i = 0;
  while (s[i] && s[i] == σ[i]) i++;
  if (s[i] == 0) (ο[α++] = s), goTo(τ, α, β, ο, σ + i, ρ, δ);
  else                         goTo(τ, α, β, ο, σ, ρ - 1, δ);
}
N(Purple_term) { ((long*)ο)[α]++, goTo(τ, α, β, ο, σ, ρ, δ); }

// Fuchsia Olive Maroon Lime Navy 0
// Blue Green Red Yellow Purple
aWord(term, goTo, goTo,              goTo, goTo,              goTo, 0,
            goTo, Yellow_Green_term, goTo, Yellow_Green_term, Purple_term)
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
  B(T(tab), T(n3), T(o)),
  B(T(tab), T(n4), T(o)),
  B(T(tab), T(n5), T(o)))
D(n123,
  B(T(tab), T(n1), T(o)),
  B(T(tab), T(n2), T(o)),
  B(T(tab), T(n3), T(o)))
D(ab,
  B(T(tab), T(ε), T(o)),
  B(T(tab), T(a), T(o)),
  B(T(tab), T(b), T(o)),
)
D(abS,  B(T(tab), T(ab), T(ab), T(ab), T(o)))
N(s_ss) { goTo(τ, α, β, ο, "ss", ρ, δ); }
N(s_ba) { goTo(τ, α, β, ο, "ba", ρ, δ); }
N(s_aaaaaa) { goTo(τ, α, β, ο, "aaaaaa", ρ, δ); }
D(A2,B(T(tab), T(n3), T(ε), T(o)),
     B(T(tab), T(n4), T(aa),T(A2), T(o)),
     B(T(tab), T(n5), T(a), T(A2), T(o)))
D(A1,B(T(tab), T(n1), T(aa),T(A2), T(o)),
     B(T(tab), T(n2), T(a), T(A2), T(o)))
D(sS,
  B(T(tab), T(ε), T(o)),
  B(T(tab), T(s), T(sS), T(sS), T(o)),
  B(T(tab), T(s), T(sS), T(sS), T(o)),
)
D(S, B(T(tab), T(b), T(o)),
     B(T(tab), T(S), T(a), T(o)))
void ti_init();
void*bar0[] = {T(tab), T(n1), T(o)};
void*bar1[] = {T(tab), T(n3), T(o)};

tWord(cross_l,  bar0, bar0, bar0, bar0, bar0, 0,
                bar1, bar1, bar1, bar1, bar1) 

void*bar2[] = {T(tab), T(n2), T(cross_l), T(n4), T(o)};

tWord(cross,  bar2, bar2, bar2, bar2, bar2, 0,
              bar2, bar2, bar2, bar2, bar2) 
int main() {
  void **τ = 5 + (void *[]) { T(bro), T(s_ba), T(S), T(print), T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(n123),      T(n123),  T(n123),    T(print), T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(s_ss),      T(sS),    T(print),   T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(s_aaaaaa),  T(A1),    T(print),   T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(n1), T(n2), T(n3),    T(cross),   T(n3), T(n4), T(n5), T(o) };
  long  α = 0;
  void *ο[512];
  long  β = sizeof(ο) / sizeof(*ο);
  ti_init();
  goTo(τ, α, β, ο, "", 3, 1);
}
