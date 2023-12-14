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

#define T(nar) (ο[-σ] = ο[+σ] = nar), (σ += 11)

#define oba ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define srd σ, ρ, δ

N(goTo      ) { ((n_t)ο[τ + 11 * δ])(oba, τ + 11 * δ, srd); }
N(o         ) { goTo(oba, τ, σ, ρ, -δ); }
N(bword     ) { P; if (ρ < 2) goTo(oba, τ, σ, 3, δ); else P; }

N(δ_switch  ) { ((n_t)ο[τ + δ])(obatsrd); }
N(ρδ_switch ) { ((n_t)ο[τ + (ρ + 1) * δ])(obatsrd); }

#define ID(id)                                                                 \
  N(id##_heart);                                                               \
  N(id) {                                                                      \
    τ[-1 * δ] = goTo;                                                          \
    τ[+1 * δ] = id##_heart;                                                    \
    ((n_t)(*τ = δ_switch))(obatsrd);                                           \
  }                                                                            \
  N(id##_heart)
N(b         ) {P; goTo(obatsrd); }
N(a         ) {P; goTo(obatsrd); }
N(t         ) {P; goTo(obatsrd); }
N(id1       ) {P; goTo(obatsrd); }
N(id2       ) {P; goTo(obatsrd); }
N(id3       ) {P; goTo(obatsrd); }
N(toti      ) {//P;
  long *c = ο[τ + 5];
  long *a = c + 4;
  goTo(oba, a[c[0]] * δ, srd);
}
N(true_var) {P;
  ο[τ - 1 * δ]      = goTo;
  ο[τ + 1 * δ]      = toti;
  ((n_t)(ο[τ]       = δ_switch))(obatsrd);
}
N(var) {//P;
  long ob           = ο[--α];
  long arms         = ob - β;
  ο[--β]            = 0;
  ο[--β]            = 0;
  ο[--β]            = arms;
  ο[--β]            = 0;
  ο[-τ+5] = ο[+τ+5] = ο + β;
  ((n_t)(ο[-τ] = ο[+τ] = true_var))(obatsrd);
}
N(tab) { goTo(oba, ο[τ+5], σ, ρ, -δ); }


#define OB ((unsigned long**)ο)[(long)ο[τ+22*δ+5]+5]
#define Fruitful OB[3]
#define Trimed   OB[2]
#define Arms     OB[1]
#define I        OB[0]
N(propeller) {
  long oi = I;
  while((I = (I + 1) % Arms) && (Trimed >> I) & 1);
  long d = (long)ο[--α];
  goTo(oba,τ,σ, !(oi < I) * 2 + d, δ);
}
N(Red_Blue_propeller    ) { (ο[α++] = (void*)0),          propeller(obatsrd); }
N(Yellow_Green_propeller) {P; (ο[α++] = (void*)1),          propeller(obatsrd); }
N(Yellow_Green          ) { Fruitful |= (1UL << I),       goTo(obatsrd); }
N(Yellow_Red            ) { if (Arms == 1)                goTo(obatsrd);
                            else if ((Fruitful >> I) & 1) Red_Blue_propeller(obatsrd);
                            else Trimed |= (1UL << I),    Red_Blue_propeller(obatsrd); }
N(Yellow_Yellow         ) {P; Fruitful |= (1UL << I),       Yellow_Green_propeller(obatsrd); }
N(Red_Red               ) {                               Red_Blue_propeller(obatsrd); }
N(Green_Green           ) { Fruitful |= (1UL << I),       goTo(obatsrd); }
N(door_open) {
  ο[τ-4*δ] = goTo;
  ο[τ-3*δ] = goTo;
  ο[τ-1*δ] = goTo;
  goTo(obatsrd); 
}
N(door_close) {
  ο[τ-4*δ] = door_open;
  ο[τ-3*δ] = o;
  ο[τ-1*δ] = o;
  goTo(obatsrd); 
}
N(door) {
  ο[τ-4*δ] = door_close;
  ο[τ-3*δ] = goTo;
  ο[τ-2*δ] = goTo;
  ο[τ-1*δ] = goTo;
  ο[τ] = ρδ_switch;
  ο[τ+1*δ] = o;
  ο[τ+2*δ] = goTo;
  ο[τ+3*δ] = o;
  ο[τ+4*δ] = door_open;
  ((n_t)ο[τ])(obatsrd); 
}
N(nop) {assert(0);}
N(Blue_propeller) {P;
  ο[τ-1*δ] = goTo;
  ο[τ-2*δ] = nop;
  ο[τ-3*δ] = nop;
  ο[τ-4*δ] = nop;
  goTo(obatsrd);
}
N(Green_propeller) {P;
  ο[τ-1*δ] = goTo;
  ο[τ-2*δ] = Green_Green;
  ο[τ-3*δ] = nop;
  ο[τ-4*δ] = nop;
  goTo(obatsrd);
}
N(Red_propeller) {P;
  ο[τ-1*δ] = goTo;
  ο[τ-2*δ] = nop;
  ο[τ-3*δ] = Red_Red;
  ο[τ-4*δ] = nop;
  goTo(obatsrd);
}
N(Yellow_propeller) {P;
  ο[τ-1*δ] = goTo;
  ο[τ-2*δ] = Yellow_Green;
  ο[τ-3*δ] = Yellow_Red;
  ο[τ-4*δ] = Yellow_Yellow;
  goTo(obatsrd);
}

N(my_propeller) {P;
  ο[τ+1*δ] = Blue_propeller; 
  ο[τ+2*δ] = Green_propeller; 
  ο[τ+3*δ] = Red_propeller; 
  ο[τ+4*δ] = Yellow_propeller; 
  ((n_t)(ο[τ] = ρδ_switch))(obatsrd);
}
#define B(...)                                              \
  (ο[--β] = σ), (ο[-σ] = ο[+σ] = tab),                      \
                (ο[-σ * δ + 5] = -τ),                       \
                (ο[+σ * δ + 5] = +τ), (σ += 11),            \
                T(door), T(my_propeller), __VA_ARGS__, T(o)
#define D(S, ...)                                           \
  N(S) {                                                    \
    ο[α++] = β;                                             \
    __VA_ARGS__;                                            \
    var(obatsrd);                                           \
  }
D(S,  B(T(b)), B(T(a)), B(T(t)))
D(S2, B(T(a)))
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
  T(bword), T(id1), T(S), T(id2), T(o);
  goTo(obatsrd);
}
