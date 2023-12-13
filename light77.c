#define P                                                                      \
  printf("%4ld %7s %s\n", τ, rays[(ρ + 1) * δ + 5], __FUNCTION__), usleep(200000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#define N(argo)                                                                \
  void argo(void **ο, long β, long α, long τ, long σ, long ρ, long δ)
typedef N((*n_t));

const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};

#define Tab(n, a, b)                                                           \
  (ο[-σ - 5] = ο[+σ - 5] = a), (ο[-σ] = ο[+σ] = n),                            \
      (ο[-σ + 5] = ο[+σ + 5] = b), σ += 11

#define T(nar) Tab(nar, 0, 0)

#define oba ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define srd σ, ρ, δ

N(goTo) { ((n_t)ο[τ + 11 * δ])(oba, τ + 11 * δ, srd); }
N(o) { goTo(oba, τ, σ, ρ, -δ); }
N(bword) {
  if (1 || ρ < 2)
    goTo(oba, τ, σ, 3, δ);
  else
    P;
}
N(tab);// { goTo(ο, β + 1, α, (long)ο[β], σ, ρ, δ); }

N(δ_switch) { ((n_t)ο[τ + δ])(obatsrd); }
N(ρδ_switch) { ((n_t)ο[τ + (ρ + 1) * δ])(obatsrd); }

#define ID(id)                                                                 \
  N(id##_heart);                                                               \
  N(id) {                                                                      \
    τ[-1 * δ] = goTo;                                                          \
    τ[+1 * δ] = id##_heart;                                                    \
    ((n_t)(*τ = δ_switch))(obatsrd);                                           \
  }                                                                            \
  N(id##_heart)
N(propeller ) {P; goTo(obatsrd); }
N(door      ) { ; goTo(obatsrd); }
N(b         ) {P; goTo(obatsrd); }
N(a         ) {P; goTo(obatsrd); }
N(id1       ) {P; goTo(obatsrd); }
N(id2       ) {P; goTo(obatsrd); }
N(id3       ) {P; goTo(obatsrd); }
N(toti      ) {//P;
  long *c = (void*)&ο[(long)ο[τ + 5]];
  long *a = c + 4;
  goTo(oba, a[c[0]] * δ, srd);
}
N(true_var) {//P;
  ο[τ - 1 * δ] = goTo;
  ο[τ + 1 * δ] = toti;
  ((n_t)(ο[τ] = δ_switch))(obatsrd);
}
N(var) {//P;
  long ob     = ο[--α];
  long arms   = ob - β;
  ο[--β]      = 0;
  ο[--β]      = 0;
  ο[--β]      = arms;
  ο[--β]      = 0;
  ο[+τ+5]     = β;
  ο[-τ+5]     = β;
  ((n_t)(ο[-τ] = ο[+τ] = true_var))(obatsrd);
}
N(tab) { goTo(oba, ο[τ+5], srd); }
N(S) {//P;
  ο[α++] = β;
  (ο[--β] = σ), (ο[-σ] = ο[+σ] = tab), (ο[-σ * δ + 5] = +τ), (ο[+σ * δ + 5] = -τ), (σ += 11),
                T(door), T(b), T(o);
  var(obatsrd);
}
N(S2) {//P;
  ο[α++] = β;
  (ο[--β] = σ), (ο[-σ] = ο[+σ] = tab), (ο[-σ * δ + 5] = +τ), (ο[+σ * δ + 5] = -τ), (σ += 11),
                T(door), T(a), T(o);
  var(obatsrd);
}
int main() {
  const long size = 512;
  void*ram[size + 1 + size];
  void**ο = ram + size;
  long  β = +size; 
  long  α = -size;
  long  τ = 0;
  long  σ = 0;
  long  ρ = 3;
  long  δ = 1;
  T(bword), T(id1), T(S), T(id2), T(S2), T(id3),  T(o);
  goTo(obatsrd);
}
