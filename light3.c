// clang-format off
#define N(argo) void argo(void **ο, long β, long α, void **τ, char *σ, long ρ, long δ)
typedef N((*n_t));
//#define P (void)0
#define P printf("%7s %s\n", rays[(ρ + 1) * δ + 5], __FUNCTION__), usleep(20000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};

#define Tab(nar, a, b)  0, 0, 0, (b), (a), nar, (a), (b), 0, 0, 0
#define Ta(nar, a)      Tab(nar, a, 0)
#define T(nar)          Tab(nar, 0, 0)
#define oba     ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define     srd             σ, ρ, δ

N(goTo      ) { ((n_t*)τ)[δ * 11](ο, β, α, ((void**)τ) + δ * 11, σ, ρ, δ); }

N(o         ) { goTo(ο, β, α, τ, σ, ρ, -δ); }
N(bro       ) { if (ρ < 2) goTo(ο, β, α, τ, σ, 3, 1); else P; }

N(ρδ_switch ) { ((n_t)τ[(ρ + 1) * δ])(ο, β, α, τ, σ, ρ, δ); }
N(δ_switch  ) { ((n_t)τ[          δ])(ο, β, α, τ, σ, ρ, δ); }
N(terminal_parse) {
  char*s = τ[2];
  long i = 0;
  while (s[i] && s[i] == σ[i]) i++;
  if (s[i] == 0) (ο[α++] = s), goTo(oba, τ, σ + i, ρ, δ);
  else                         goTo(oba, τ, σ, ρ - 1, δ);
}
N(terminal) {
  τ[-δ]     = goTo;
  τ[+δ]     = terminal_parse;
  ((n_t)(*τ = δ_switch))(obatsrd);
}
N(ε) {P; (τ[2] =  ""), terminal(obatsrd); }
N(s) {P; (τ[2] = "s"), terminal(obatsrd); }
N(b) {P; (τ[2] = "b"), terminal(obatsrd); }
N(a) {P; (τ[2] = "a"), terminal(obatsrd); }
N(str_oa) {P; (ο[α++] = τ[2]), goTo(obatsrd); }
N(str) {
  τ[-δ]     = goTo;
  τ[+δ]     = str_oa;
  ((n_t)(*τ = δ_switch))(obatsrd);
}
N(n1) { (τ[2] = "1"), str(obatsrd); }
N(n2) { (τ[2] = "2"), str(obatsrd); }
N(n3) { (τ[2] = "3"), str(obatsrd); }
N(n4) { (τ[2] = "4"), str(obatsrd); }
N(n5) { (τ[2] = "5"), str(obatsrd); }

N(tab) {P; goTo(ο, β + 1, α, ο[β], srd); }
N(ρmod2δ_switch) { ((n_t)τ[(ρ % 2 + 1) * δ])(obatsrd); }
N(t_word_change) { (τ[δ] = τ[3 * δ]), (*τ = δ_switch), ((n_t)*τ)(obatsrd); }
N(t_word) {
  τ[-3 * δ] = ο[--α];
  τ[-2 * δ] = goTo;
  τ[-1 * δ] = goTo;
  *τ        = ρmod2δ_switch;
  τ[+1 * δ] = goTo;
  τ[+2 * δ] = t_word_change;
  τ[+3 * δ] = ο[--α];
  ((n_t)*τ)(obatsrd);
}
N(sS);
N(sS_left) { P;
  τ[-1] = (void*[]) { T(o), T(tab) } + 16;
  ((n_t)(*τ = ο[α]))(obatsrd);
}
N(sS_right) { P;
  τ[+2] = (void*[]) { T(tab), T(ε), T(o) } +  5;
  τ[+1] = (void*[]) { T(tab), T(s), T(sS), T(sS), T(o) } +  5;
  ((n_t)(*τ = ο[α]))(obatsrd);
}
N(ln) {P;}
N(rn) {P;}
N(sS) { P;
  ο[α++] = ln;
  ο[α++] = rn;
  (τ[-5] = sS_left), (τ[+5] = sS_right), t_word(obatsrd);
}

N(S       ) { P;
  τ[-5] = (void*[]) { 0, (void*)1, (void*[]) { T(o), T(a), T(tab) } + 27, };
  τ[+5] = (void*[]) { 0, (void*)1, (void*[]) { T(tab), T(b), T(o) } +  5, };
  t_word(obatsrd);
}
N(print    ) {
  if (α) {
    printf("(");
    for (long i = 0; i < α; i++)
      printf("%s", (char *)ο[i]);
    printf(")%s\n", rays[(ρ + 1) * δ + 5]);
    usleep(200000);
  }
  (α = 0), goTo(obatsrd);
}
N(in) { goTo(oba, τ, τ[δ], ρ, δ); }
int main() {
  void **τ = 5 + (void *[]) { T(bro), Ta(in, "ss"), T(sS), T(print), T(o) };
  long α = 0, ρ = 3, δ = 1;
  void *ο[512];
  long β = sizeof(ο) / sizeof(*ο);
  goTo(ο, β, α, τ, "", ρ, δ);
}
