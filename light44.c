#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#define N(argo)                                                                \
  void argo(long*ο, long β, long α, long τ, long σ, long ρ, long δ)
typedef N((*n_t));

const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};
#define P printf("%4ld %4ld %4ld %7s %s\n", α, β, σ, rays[(ρ + 1) * δ + 5], __FUNCTION__), usleep(2000)

#define oba     ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define srd                 σ, ρ, δ
#define Σ 2048
N(goTo    ) { ((n_t)ο[ρ*Σ + τ + δ*11])(oba, τ + δ*11, srd); }
N(δ_switch) { ((n_t)ο[ρ*Σ + τ + δ])(obatsrd); }

N(oa) { ((n_t)ο[α-1])(ο, β, α-1, τ, srd); }
#define Blue(σ)   (σ+0*Σ)
#define Green(σ)  (σ+1*Σ)
#define Red(σ)    (σ+2*Σ)
#define Yellow(σ) (σ+3*Σ)
#define Navy(σ)   (-Blue(σ))
#define Lime(σ)   (-Green(σ))
#define Maroon(σ) (-Red(σ))
#define Olive(σ)  (-Yellow(σ))
#define W(i,a,b,c,d)                                                        \
  ο[Blue(σ)+i] = a, ο[Green(σ)+i] = b, ο[Red(σ)+i] = c, ο[Yellow(σ)+i] = d, \
  ο[Navy(σ)+i] = a, ο[Lime(σ)+i] = b, ο[Maroon(σ)+i] = c, ο[Olive(σ)+i] = d
#define T(a) ο[α++] = a,
N(term) {
  const char*term = ο[--α];
  W(-1,0,0,0,0);
}
N(goTo_t5) { goTo(oba, ο[τ + 5], srd); }
N(goTo_ward) { goTo(oba, ο[τ - 5], σ, ο[τ - 4], δ); }
N(ward_goTo_t5) {
  long vt = ο[τ + 5];
  ο[vt - 5] = τ;
  ο[vt - 4] = ρ;
  goTo_t5(obatsrd);
}
N(propeller1_ward_goTo_t5) {
  long vt = ο[τ + 5];
  long charge = ο[τ + 4];
  ο[vt + 5] = τ;
  ward_goTo_t5(oba, τ, σ, ρ + charge, δ);
}
N(propeller2_ward_goTo_t5) {
  long vt = ο[τ + 5];
  ο[vt + 5] = ο[vt + 4], ward_goTo_t5(obatsrd);
}
N(type_propeller) {
  n_t propeller = ο[--α];
  ο[ σ + 5] = ο[β], 
  ο[+σ + 4] = -2, 
  ο[-σ + 4] = +2, 
  W(-1, goTo_t5,      goTo_t5,      goTo_t5,    goTo_t5),
  W(+0, δ_switch,     δ_switch,     δ_switch,   δ_switch),
  W(+1, ward_goTo_t5, ward_goTo_t5, propeller,  propeller), σ -= 11, oa(obatsrd);
}
N(semicolon) { T(propeller1_ward_goTo_t5) T(type_propeller) oa(obatsrd); }
N(dot      ) { T(propeller2_ward_goTo_t5) T(type_propeller) oa(obatsrd); }
//
//                    -τ        .        τ+ 
//
//           43210987654321 ο[+τ+5] = 12345678901234
// ο[-τ+5] = ☀ gfed ⚙ cba ☀     .     ☀ abc ⚙ defg ☀
//           │      │     │           │     │      │
//           │      │     └─   p 2   ─┘     │      │
//           │      └───────   p 1   ───────┘      │
//           └──────────────   p 2   ──────────────┘
N(finish_typing_variable) {
  ο[+τ + 4] = +σ;
  ο[+τ + 5] = +σ;
  W(-1, goTo_ward,  goTo_ward,  goTo_ward,  goTo_ward),
  W(+0, δ_switch,   δ_switch,   δ_switch,   δ_switch),
  W(+1, goTo_t5,    goTo_t5,    goTo_t5,    goTo_t5);
  ((n_t)ο[τ])(obatsrd);
}
N(start_typing_variable) {
  ο[-τ + 4] = -σ;
  ο[-τ + 5] = -σ;
  n_t transcription = ο[τ + 5];
  ο[--β] = τ,
  T(finish_typing_variable) T(dot) transcription(obatsrd);
}
N(var) {
  n_t transcription = ο[--α];
  ο[σ + 5] = transcription,
  W(+0, goTo, start_typing_variable, goTo, start_typing_variable), σ -= 11, oa(obatsrd);
}
N(begin) {}
N(end) {}
N(S) { 
  T("b") T(term) T(semicolon)
  T("a") T(term) T(semicolon)
  T("t") T(term) T(dot) oa(obatsrd);
}
N(n345) {
  T("3") T(term) T(semicolon)
  T("4") T(term) T(semicolon)
  T("5") T(term) T(dot) oa(obatsrd);
}
N(n123) {
  T("1") T(term) T(semicolon)
  T("2") T(term) T(semicolon)
  T("3") T(term) T(n345) T(var) T(dot) oa(obatsrd);
}
N(r) {
  T(n123) T(var) T(dot) oa(obatsrd);
}
int main() {
  long ram[4*Σ+1+Σ*4]; 
  long*ο = ram + 4*Σ;
  long β = 0; 
  long α = 0;
  long τ = 0;
  long σ = Σ;
  long ρ = 3;
  long δ = 1;
  ο[α++] = begin,
  ο[α++] = r,
  ο[α++] = var,
  ο[α++] = end,
  oa(obatsrd);
}
