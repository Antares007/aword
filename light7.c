#define P printf("%7s %s\n", rays[(ρ + 1) * δ + 5], __FUNCTION__),\
          usleep(200000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#define N(argo) void argo(void**ο, long β, long α, void**τ, long σ, long ρ, long δ)
typedef N((*n_t));

const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};

#define Tab(n, a, b) (a), 0,0,0,0, n, 0,0,0,0, (b)
#define T(nar) Tab(nar, 0, 0)

#define oba     ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define     srd             σ, ρ, δ

N(goTo      ) { ((n_t)τ[11 * δ])(oba, τ + 11 * δ, srd); }
N(o         ) { goTo(oba, τ, σ, ρ, -δ); }
N(bword     ) { if(ρ < 2) goTo(oba, τ, σ, 3, -δ); }
N(tab       ) { goTo(ο, β + 1, α, (long)ο[β], σ, ρ, δ); }

N(δ_switch  ) { ((n_t)τ[δ])(obatsrd); }
N(ρδ_switch ) { ((n_t)τ[(ρ+1)*δ])(obatsrd); }

#define ID(id)                          \
  N(id##_heart);                        \
  N(id) {                               \
    τ[-1*δ] = goTo;                     \
    τ[+1*δ] = id##_heart;               \
    ((n_t)(*τ = δ_switch))(obatsrd);    \
  }                                     \
  N(id##_heart)

N(id1) { goTo(obatsrd); }
N(id2) { goTo(obatsrd); }
N(b  ) { goTo(obatsrd); }
N(a  ) { goTo(obatsrd); }
N(t  ) { goTo(obatsrd); }
N(s  ) { goTo(obatsrd); }

#define GET_BIT(value, bit) ((value >> bit) & 1)
#define SET_BIT(value, bit) (value |= (1UL << bit))
#define OB ((unsigned long**)ο)[β]
#define Fruitful OB[-5]
#define Trimed   OB[-4]
#define Arms     OB[-3]
#define I        OB[-2]
N(propeller) {
  long oi = I;
  while((I = (I + 1) % Arms) && GET_BIT(Trimed, I));
  long d = (long)ο[--α];
  long r = !(oi < I) * 2 + d;
  goTo(oba,τ,σ,r,δ);
}
N(Red_Blue_propeller    ) { (ο[α++] = (void*)0),          propeller(obatsrd); }
N(Yellow_Green_propeller) { (ο[α++] = (void*)1),          propeller(obatsrd); }
N(Yellow_Green          ) { Fruitful |= (1UL << I),       goTo(obatsrd); }
N(Yellow_Red            ) { if (Arms == 1)                goTo(obatsrd);
                            else if(GET_BIT(Fruitful, I)) Red_Blue_propeller(obatsrd);
                            else SET_BIT(Trimed, I),      Red_Blue_propeller(obatsrd); }
N(Yellow_Yellow         ) { SET_BIT(Fruitful, I),         Yellow_Green_propeller(obatsrd); }
N(Red_Red               ) {                               Red_Blue_propeller(obatsrd); }
N(Green_Green           ) { SET_BIT(Fruitful, I),         goTo(obatsrd); }
N(door    ) { goTo(obatsrd); }
N(Yellow  ) {
  τ[-4] = goTo; τ[-3] = goTo; τ[-2] = goTo; τ[-1] = goTo;
  τ[+1] = goTo;
  τ[+2] = Yellow_Green;
  τ[+3] = Yellow_Red;
  τ[+4] = Yellow_Yellow;
  ((n_t)(*τ = ρδ_switch))(obatsrd); 
}
N(nop) {assert(0);}
N(Red  ) {
  τ[-4] = goTo; τ[-3] = goTo; τ[-2] = goTo; τ[-1] = goTo;
  τ[+1] = goTo;
  τ[+2] = nop;
  τ[+3] = Red_Red;
  τ[+4] = nop;
  ((n_t)(*τ = ρδ_switch))(obatsrd); 
}
N(Green  ) {
  τ[-4] = goTo; τ[-3] = goTo; τ[-2] = goTo; τ[-1] = goTo;
  τ[+1] = goTo;
  τ[+2] = Green_Green;
  τ[+3] = nop;
  τ[+4] = nop;
  ((n_t)(*τ = ρδ_switch))(obatsrd); 
}
N(Blue  ) {
  τ[-4] = goTo; τ[-3] = goTo; τ[-2] = goTo; τ[-1] = goTo;
  τ[+1] = goTo;
  τ[+2] = nop;
  τ[+3] = nop;
  τ[+4] = nop;
  ((n_t)(*τ = ρδ_switch))(obatsrd); 
}

N(toti    ) {
  static void* a_Yellow  [] = {T(o), T(Yellow), T(tab) };
  static void* a_Red     [] = {T(o), T(Red),    T(tab) };
  static void* a_Green   [] = {T(o), T(Green),  T(tab) };
  static void* a_Blue    [] = {T(o), T(Blue),   T(tab) };
  static void**propellers[] = {a_Blue+27,a_Green+27,a_Red+27,a_Yellow+27};
  (ο[--β] = τ),
  (ο[--β] = propellers[ρ]),
  goTo(oba, τ[(long)τ[-2] + 2], srd);
}
N(true_var) {
  τ[-1] = goTo;
  τ[+1] = toti;
  ((n_t)(*τ = δ_switch))(obatsrd); 
}
N(S) {
  τ[-3] = 2;
  τ[-2] = 0;
  τ[+2] = 5 + (void*[]) {T(tab), T(door), T(b), T(o)};
  τ[+3] = 5 + (void*[]) {T(tab), T(door), T(S), T(a), T(o)};
  true_var(obatsrd);
}
N(n1   ) { if(δ==1) (ο[α++] = "1"); goTo(obatsrd); }
N(n2   ) { if(δ==1) (ο[α++] = "2"); goTo(obatsrd); }
N(n3   ) { if(δ==1) (ο[α++] = "3"); goTo(obatsrd); }
N(n4   ) { if(δ==1) (ο[α++] = "4"); goTo(obatsrd); }
N(n5   ) { if(δ==1) (ο[α++] = "5"); goTo(obatsrd); }
N(n345) {
  τ[-3] = 3; τ[-2] = 0;
  τ[+2] = 5 + (void*[]) {T(tab), T(door), T(n3), T(o)};
  τ[+3] = 5 + (void*[]) {T(tab), T(door), T(n4), T(o)};
  τ[+4] = 5 + (void*[]) {T(tab), T(door), T(n5), T(o)};
  true_var(obatsrd);
}
N(n123) {
  τ[-3] = 3; τ[-2] = 0;
  τ[+2] = 5 + (void*[]) {T(tab), T(door), T(n1), T(o)};
  τ[+3] = 5 + (void*[]) {T(tab), T(door), T(n2), T(o)};
  τ[+4] = 5 + (void*[]) {T(tab), T(door), T(n3), T(n345), T(o)};
  true_var(obatsrd);
}
N(print) {
  if(α) {
    printf("%7s P_(", rays[(ρ + 1) * δ + 5]);
    for (long i = 0; i < α; i++) printf("%s", (char *)ο[i]);
    printf(")\n");
    α = 0;
  }
  goTo(obatsrd);
}
int main() {
  void *ο[512];
  long  β = 512; 
  long  α = 0;
  void**τ = 5 + (void*[]){ T(bword), T(n123), T(n123), T(n123), T(print), T(o) };
  long  σ = 0;
  long  ρ = 3;
  long  δ = 1;
  goTo(obatsrd);
}
