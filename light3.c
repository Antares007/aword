// clang-format off
#define N(argo) void argo(void **ο, long β, long α, void **τ, char *σ, long ρ, long δ)
typedef N((*n_t));
//#define P (void)0
#define P printf("%10s %10s\n", __FUNCTION__, rays[(ρ + 1) * δ + 5]), usleep(20000)
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
N(id        ) { goTo(ο, β, α, τ, σ, ρ, δ); };
N(ρδ_switch ) { ((n_t)τ[(ρ + 1) * δ])(ο, β, α, τ, σ, ρ, δ); }
N( δ_switch ) { ((n_t)τ[          δ])(ο, β, α, τ, σ, ρ, δ); }

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
N(goTo_5δ) { goTo(oba, τ[5*δ], srd); }
N(b) { (τ[2] = "b"), terminal(obatsrd); }
N(a) { (τ[2] = "a"), terminal(obatsrd); }

N(propeller) {
}
N(i5_switch) {
  goTo(oba, τ[5 * δ], srd);
}
N(tab   ) {P; goTo(ο, β + 1, α, ο[β], srd); }
N(Blue  ) {P;}
N(Green ) {P; goTo(obatsrd); }
N(Red   ) {P;}
N(Yellow) {P;
  long*c = ((void***)ο)[β][5 * δ];
  goTo(oba, τ, σ, !(c[0] = (ρ + 1) % c[1]) * 2 + 1, δ);
}
N(variable_heart) {P;
  static void*p[] = { T(tab),
                      0, Yellow, Red, Green, Blue,
                      ρδ_switch,
                      Blue, Green, Red, Yellow, 0,
                      T(tab) };
  static void*ends[] = { p + 27, 0, p + 5};
  static void**pends = ends + 1;
  long *rc = τ[+5 * δ]; void***ra = (void*)&rc[2];
  long *lc = τ[-5 * δ]; void***la = (void*)&lc[2];
  ο[--β]   = τ;
  ο[--β]   = pends[δ];
  ο[--β]   = la[lc[0]];
  goTo(oba,  ra[rc[0]], srd);
}

N(open_variable ) {P;
  *τ        = δ_switch;
  τ[+1 * δ] = variable_heart;
  ((n_t)τ[+δ])(obatsrd);
}
N(oc_switch     ) {P; ((n_t)τ[((ρ / 2) * 2 - 1) * δ])(ο, β, α, τ, σ, ρ, δ); }
N(variable      ) {P;
  τ[-1 * δ] = goTo;
  *τ        = oc_switch;
  τ[+1 * δ] = open_variable;
  ((n_t)*τ)(obatsrd);
}
N(S             ) {P;
  τ[-5] = (void*[]) { 0, 1, (void*[]) { T(o), T(a), T(tab) } + 27  };
  τ[+5] = (void*[]) { 0, 1, (void*[]) { T(tab), T(b), T(o) } +  5  };
  variable(obatsrd);
}
N(C) {
  //  static void*arm1[] = { T(tab), T(b), T(o) };
  //  static void*arm2[] = { T(o), T(a), T(tab) };
}
N(print) {
  if (α) {
    printf("(");
    for (long i = 0; i < α; i++)
      printf("%s", (char *)ο[i]);
    printf(")%s\n", rays[(ρ + 1) * δ + 5]);
    usleep(200000);
  }
  (α = 0), goTo(obatsrd);
}
N(str) { (ο[α++] = τ[δ]), goTo(obatsrd); }
N(in) { goTo(oba, τ, τ[δ], ρ, δ); }
int main() {
  void **τ = 5 + (void *[]) { T(bro), Ta(in, "baaa"), T(S), T(print), T(o) };
  long α = 0, ρ = 3, δ = 1;
  void *ο[512];
  long β = sizeof(ο) / sizeof(*ο);
  goTo(ο, β, α, τ, "", ρ, δ);
}
