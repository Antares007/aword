#define P printf("%4ld %3ld %7s %s\n", τ, σ, rays[(ρ + 1) * δ + 5], __FUNCTION__),\
          usleep(200000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#define N(argo) void argo(void **ο, long β, long α, long τ, long σ, long ρ, long δ)
typedef N((*n_t));

const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};

#define Tab(n, a, b)              \
  (ο[-σ-5] = ο[+σ-5] = a),        \
  (ο[-σ-0] = ο[+σ-0] = n),        \
  (ο[-σ-0] = ο[+σ-0] = δ_switch), \
  (ο[-σ-0] = ο[+σ-0] = n),        \
  (ο[-σ+5] = ο[+σ+5] = b), σ += 11
#define T(nar) Tab(nar, 0, 0)

#define oba     ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define     srd             σ, ρ, δ

N(goTo) { ((n_t)ο[τ + 11 * δ])(oba, τ + 11 * δ, srd); }
N(δ_switch) { ((n_t)ο[τ+δ])(obatsrd); }
N(o);
N(bro) { P; if (1 || ρ < 2) goTo(oba, 0, σ, 3, -δ); }
N(ρδ_switch) { ((n_t)ο[τ+(ρ+1)*δ])(obatsrd); }
N(tab) { goTo(ο, β + 1, α, (long)ο[β], σ, ρ, δ); }
#define ID(id)                          \
  N(id##_heart);                        \
  N(id) {                               \
    ο[τ-1*δ] = goTo;                    \
    ο[τ+1*δ] = id##_heart;              \
    ((n_t)(ο[τ] = δ_switch))(obatsrd);  \
  }                                     \
  N(id##_heart)
N(id1) {P; goTo(obatsrd); }
N(id2) {P; goTo(obatsrd); }
N(b  ) {P; goTo(obatsrd); }
N(a  ) {P; goTo(obatsrd); }
N(t  ) {P; goTo(obatsrd); }
N(s  ) {P; goTo(obatsrd); }
N(pith);// {P;goTo(oba, -τ, srd); }
N(bark);
//                  N(S) {
//                    T(pith),
//        T(o), T(b), T(tab),
//  T(o), T(a), T(S), T(tab),
//                    bark(obatsrd);
//                  }
                    N(S) {
                      T(pith),
                      T(tab), T(b), T(o),
                      T(tab), T(S), T(a), T(o),
                      bark(obatsrd);
                    }


#define GET_BIT(value, bit) ((value >> bit) & 1)
#define SET_BIT(value, bit) (value |= (1UL << bit))
N(pith_Green_Blue ) {
  long*c = ο[τ+5];
  long*arms = c+4;
  goTo(oba, ο[arms[c[0]]], σ, 3, δ);
}
N(pith_Yellow_Red) {
  long*c = ο[τ+5];
  long*arms = c+4;
  SET_BIT(c[3], c[0]);
  if (c[2] != c[3]) {
    while((c[0] = (c[0] + 1) % c[1]) && ((c[3] >> c[0]) & 1));
    pith_Green_Blue(oba, ο[arms[c[0]]], σ, 3, δ);
  }
}
N(bark) { (ο[α++] = τ), (ο[α] = 0), goTo(oba, -σ * δ, srd); }
N(ob  ) { goTo(oba, ο[τ + 5], srd); }
N(o   ) { (((long*)ο)[α]++), (ο[--β] = τ), (ο[τ] = ob), goTo(obatsrd); }
N(pith_Navy  ) {
  long arms_count = ο[--α];
  long st         = ο[--α];
  long arms       = β;
  for(long i      = arms; i < arms_count; i++) {
    long oτ       = ο[i];
    ο[oτ+5]       = -oτ;
  }
  ο[--β]          = 0;
  ο[--β]          = (1UL << arms_count) - 1;
  ο[--β]          = arms_count;
  ο[--β]          = 0;
  ο[st+5]         = β;
  pith_Green_Blue(obatsrd);
}
N(pith) { P;
  ο[τ-1] = pith_Navy;
  ο[τ+1] = pith_Green_Blue;
  ο[τ+2] = pith_Green_Blue;
  ο[τ+3] = pith_Yellow_Red;
  ο[τ+4] = pith_Yellow_Red;
  ((n_t)(ο[+τ] = ρδ_switch))(obatsrd);
}
int main() {
  const long size = 512;
  void*ram[size + 1 + size];
  void**ο = ram + size;
  long  β = +size; 
  long  α = -size;
  long  τ = +0;
  long  σ = +0;
  long  ρ = +3;
  long  δ = -1;
  T(pith),
    T(id1), T(id2), T(o),
    T(id1), T(id2), T(o),
    bark(obatsrd);
}
