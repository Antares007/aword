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

#define T(nar) (ο[-σ] = ο[+σ] = nar), (σ += 11), (ο[-σ] = ο[+σ] = 0)

#define oba ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define srd σ, ρ, δ

N(goTo      ) { ((n_t)ο[τ + 11 * δ])(oba, τ + 11 * δ, srd); }
N(o         );// { goTo(oba, τ, σ, ρ, -δ); }

N(δ_switch  ) { ((n_t)ο[τ + δ])(obatsrd); }
N(ρδ_switch ) { ((n_t)ο[τ + (ρ + 1) * δ])(obatsrd); }

#define OB ((unsigned long*)&ο[(long)ο[β]])
#define Arms     OB[-5]
#define I        OB[+5]
#define Fruitful ο[OB[I]+5]
#define Trimed   ο[OB[I]+4]
N(propeller) {
  long oi = I;
  while((I = (I + 1) % Arms) && ο[OB[I]+5]);
  long d = (long)ο[--α];
  goTo(oba,τ,σ, !(oi < I) * 2 + d, δ);
}
N(Red_Blue_propeller    ) { (ο[α++] = (void*)0),propeller(obatsrd); }
N(Yellow_Green_propeller) { (ο[α++] = (void*)1),propeller(obatsrd); }
N(Yellow_Green          ) { Fruitful = 1,       goTo(obatsrd); }
N(Yellow_Red            ) { if (Arms == 1)      goTo(obatsrd);
                            else if (Fruitful)  Red_Blue_propeller(obatsrd);
                            else Trimed = 1,    Red_Blue_propeller(obatsrd); }
N(Yellow_Yellow         ) { Fruitful = 1,       Yellow_Green_propeller(obatsrd); }
N(Red_Red               ) {                     Red_Blue_propeller(obatsrd); }
N(Green_Green           ) { Fruitful = 1,       goTo(obatsrd); }
N(nop) {assert(0);}
N(Blue) {
  ο[τ-4*δ] = goTo;
  ο[τ-3*δ] = goTo;
  ο[τ-2*δ] = goTo;
  ο[τ-1*δ] = goTo;
  ο[τ    ] = ρδ_switch;
  ο[τ+1*δ] = goTo;
  ο[τ+2*δ] = nop;
  ο[τ+3*δ] = nop;
  ο[τ+4*δ] = nop;
  ((n_t)ο[τ])(obatsrd);
}
N(Green) {
  ο[τ-4*δ] = goTo;
  ο[τ-3*δ] = goTo;
  ο[τ-2*δ] = goTo;
  ο[τ-1*δ] = goTo;
  ο[τ    ] = ρδ_switch;
  ο[τ+1*δ] = goTo;
  ο[τ+2*δ] = Green_Green;
  ο[τ+3*δ] = nop;
  ο[τ+4*δ] = nop;
  ((n_t)ο[τ])(obatsrd);
}
N(Red) {
  ο[τ-4*δ] = goTo;
  ο[τ-3*δ] = goTo;
  ο[τ-2*δ] = goTo;
  ο[τ-1*δ] = goTo;
  ο[τ    ] = ρδ_switch;
  ο[τ+1*δ] = goTo;
  ο[τ+2*δ] = nop;
  ο[τ+3*δ] = Red_Red;
  ο[τ+4*δ] = nop;
  ((n_t)ο[τ])(obatsrd);
}
N(Yellow) {
  ο[τ-4*δ] = goTo;
  ο[τ-3*δ] = goTo;
  ο[τ-2*δ] = goTo;
  ο[τ-1*δ] = goTo;
  ο[τ    ] = ρδ_switch;
  ο[τ+1*δ] = goTo;
  ο[τ+2*δ] = Yellow_Green;
  ο[τ+3*δ] = Yellow_Red;
  ο[τ+4*δ] = Yellow_Yellow;
  ((n_t)ο[τ])(obatsrd);
}
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
N(b         ) {P; goTo(obatsrd); }
N(a         ) {P; goTo(obatsrd); }
N(t         ) {P; goTo(obatsrd); }
N(s         ) {P; goTo(obatsrd); }
N(id1       ) {P; goTo(obatsrd); }
N(id2       ) {P; goTo(obatsrd); }
N(id3       ) {P; goTo(obatsrd); }
N(id4       ) {P; goTo(obatsrd); }
N(id5       ) {P; goTo(obatsrd); }
N(o_tab   ) { goTo(ο, β+1, α, ο[β], srd); }
N(o_b     ) { goTo(oba, τ, σ, ρ, -δ); }
N(o) {
  long st = ο[α-2];
  long ti = ο[α-3];
  assert(0 < ti);
  ο[-st+ti] = ο[+st+ti] = τ;
  ο[α-3] = (long)ο[α-3] - 1;

  ο[-τ+1] = ο[+τ-1] = o_tab;
  ο[-τ-1] = ο[+τ+1] = o_b;
  ο[-τ  ] = ο[+τ  ] = δ_switch;
  goTo(obatsrd);
}
N(var_toti) {
  ο[--β] = τ;
  ο[--β] = (long)ο[ρ+1] * -δ;
  goTo(oba, (long)ο[τ+(long)ο[τ+5]] * δ, srd);
}
N(var) {
  long sd = ο[--α];
  long st = ο[--α];
  long ti = ο[--α];
  assert(1 < ti);
  ο[-st+1 ] = ο[+st-1 ] = goTo;
  ο[-st-1 ] = ο[+st+1 ] = var_toti;
  ο[-st   ] = ο[+st   ] = δ_switch;
  ο[-st+ti] = ο[+st+ti] = τ;
  ο[-st+5 ] = ο[+st+5 ] = ti;
  ο[-st-5 ] = ο[+st-5 ] = 5 - ti;

  ο[-τ] = ο[τ] = o_tab;
  goTo(oba, st, σ, ρ, sd);
}
N(bark) {
  ο[α++] = 5;
  ο[α++] = τ;
  ο[α++] = δ;
  goTo(oba, σ, σ, ρ, -1);
}
N(S) {
  T(var), T(b), T(o),
          T(a), T(o),
          T(t), T(o), bark(obatsrd);
}
N(origin_pith) { P; if (ρ < 2) goTo(oba, τ, σ, 3, δ); }
N(origin) {
  long sd = ο[--α];
  long st = ο[--α];
  long i = ο[--α];
  assert(!i);
  ο[τ] = origin_pith;
  goTo(ο, β, α, st, σ, ρ, sd);
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
  T(origin),  T(S       ), T(o),
              T(id1), T(o),
              T(id2), T(o),
              T(id3), T(o),
              T(id4), T(o), bark(obatsrd);
}
