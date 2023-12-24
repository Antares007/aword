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
N(goTo) { ((n_t)ο[τ + Σ*ρ + 11*δ])(oba, τ + 11*δ, srd); }
N(δ_switch) { ((n_t)ο[τ + Σ*ρ + δ])(obatsrd); }
// 
//                   τ
//          β ο   α  σ+0Σ       σ+1Σ       σ+2Σ       σ+3Σ
//  ........tt ttt....... .......... .......... ..........
//                   Blue      Green        Red     Yellow
//
#define Blue(τ)   (τ)
#define Green(τ)  (Σ+Blue(τ))
#define Red(τ)    (Σ+Σ+Blue(τ))
#define Yellow(τ) (Σ+Σ+Σ+Blue(τ))
N(term_b) {
  char str[20];
  snprintf(str, 20, "%7s(%s)", (char*)rays[(ρ + 1) * δ + 5], (char*)ο[τ+5]);
  ο[α++] = str, ρ = ο[τ-4], goTo(obatsrd);
}
N(term_a) {
  const char*s = ο[--α];
  const char*t = ο[τ+5];
  if(*s == *t) ο[τ-4] = ρ, ο[α++] = s + 1, goTo(obatsrd);
  else ο[τ-4] = ρ, ο[α++] = s, goTo(oba, τ, σ, ρ - 1, δ);
}
N(oa) { ((n_t)ο[α-1])(ο, β, α-1, τ, srd); }
N(type_ok) { oa(oba, τ, σ-11, ρ, δ); }
N(type_error) { goTo(oba, τ, σ, ρ-1, -δ); }
N(type) { static n_t tab[] = {type_error, type_ok}; tab[0 < σ - 11](obatsrd); }
N(term) {
  ο[Blue(σ)-1] = term_b,   ο[Green(σ)-1] = term_b,   ο[Red(σ)-1] = term_b,   ο[Yellow(σ)-1] = term_b,
  ο[Blue(σ)  ] = δ_switch, ο[Green(σ)  ] = δ_switch, ο[Red(σ)  ] = δ_switch, ο[Yellow(σ)  ] = δ_switch,
  ο[Blue(σ)+1] = goTo,     ο[Green(σ)+1] = term_a,   ο[Red(σ)+1] = goTo,     ο[Yellow(σ)+1] = term_a,
  ο[Blue(σ)+5] = ο[--α], type(obatsrd);
}
N(goTo_t5) { goTo(oba, ο[τ+5], srd); }
N(tab) { 
  ο[Blue(σ)  ] = ο[Green(σ)] = ο[Red(σ)] = ο[Yellow(σ)] = goTo_t5,
  ο[Blue(σ)+5] = ο[β+4], type(obatsrd);
}
N(goTo_ward) { goTo(oba, ο[τ-5], σ, ο[τ-4], δ); }
N(ward_arm_nar) { (ο[ο[τ+5] - 5] = τ), (ο[ο[τ+5] - 4] = ρ), goTo(obatsrd); }
N(ward_arm) { 
  ο[Blue(σ)  ] = ο[Green(σ)] = ο[Red(σ)] = ο[Yellow(σ)] = ward_arm_nar;
  ο[Blue(σ)+5] = ο[β+4], type(obatsrd);
}
N(next_arm) { ο[ο[τ+5]+5] = τ+11, goTo_t5(oba,τ,σ,ρ-2,δ); }
N(propeller1) {
  ο[Blue(σ)] = ο[Green(σ)] = goTo_t5, ο[Red(σ)] = ο[Yellow(σ)] = next_arm,
  ο[Blue(σ)+5] = ο[β+4], type(obatsrd);
}
N(reset_arm) { ο[ο[τ+5]+5] = ο[ο[τ+5]+4], goTo_t5(obatsrd); }
N(propeller2) {
  ο[Blue(σ)] = ο[Green(σ)] = goTo_t5, ο[Red(σ)] = ο[Yellow(σ)] = reset_arm,
  ο[Blue(σ)+5] = ο[β+4], type(obatsrd);
}
N(o_next) { ο[α++] = ward_arm, ο[α++] = propeller1, ο[α++] = tab, oa(obatsrd); }
N(o_last) { ο[α++] = ward_arm, ο[α++] = propeller2, oa(obatsrd); }
N(var_end) { 
  β += 5,
  ο[Blue(τ)+1] = ο[Green(τ)+1] = ο[Red(τ)+1] = ο[Yellow(τ)+1] = goTo_t5,     
  ο[τ+4] = ο[τ+5] = σ + 11, ((n_t)ο[τ])(obatsrd);
}
N(var);
N(var_start) { 
  ο[--β] = τ;
  ο[--β] = var;
  ο[--β] = term;
  ο[--β] = o_next;
  ο[--β] = o_last;
  ο[α++] = var_end, ο[α++] = tab, ((n_t)ο[Blue(τ + 5)])(obatsrd);
}
N(var) { 
  ο[Blue(σ)-1] = ο[Red(σ)-1] = ο[Green(σ)-1] = ο[Yellow(σ)-1] = goTo_ward,
  ο[Blue(σ)  ] = ο[Red(σ)  ] = ο[Green(σ)  ] = ο[Yellow(σ)  ] = δ_switch,
  ο[Blue(σ)+1] = ο[Red(σ)+1] = ο[Green(σ)+1] = ο[Yellow(σ)+1] = var_start,
  ο[Blue(σ)+5] = ο[--α], type(obatsrd);
}
N(nop) { P, assert(0); }
N(aword) { if(ο[β++] < 2) goTo(oba, τ, σ, ρ, -δ); }
N(ob) { ο[--β] = ρ, goTo(oba, τ, σ, ρ, -δ); }
N(b) { ο[Blue(σ)] = ο[Red(σ)] = ο[Green(σ)] = nop, ο[Yellow(σ)] = aword, goTo(oba, σ, σ-11, ρ, δ); }
N(o) { ο[Blue(σ)] = ο[Red(σ)] = ο[Green(σ)] = ο[Yellow(σ)] = ob, type(obatsrd); }
N(print_it) {
  if(α) {
    for(long i = 0; i < α; i++) printf("%s", (char*)ο[i]);
    printf("\n");
    α = 0;
    usleep(2000);
  }
  goTo(obatsrd);
}
N(print) { ο[Blue(σ)] = ο[Red(σ)] = ο[Green(σ)] = ο[Yellow(σ)] = print_it, type(obatsrd); }
N(str_push) { ο[α++] = ο[τ+5], goTo(obatsrd); }
N(str) {
  ο[Blue(σ)-1] = ο[Red(σ)-1] = ο[Green(σ)-1] = ο[Yellow(σ)-1] = goTo,
  ο[Blue(σ)  ] = ο[Red(σ)  ] = ο[Green(σ)  ] = ο[Yellow(σ)  ] = δ_switch,
  ο[Blue(σ)+1] = ο[Red(σ)+1] = ο[Green(σ)+1] = ο[Yellow(σ)+1] = str_push,
  ο[Blue(σ)+5] = ο[--α], type(obatsrd);
}
N(lbl_print) { printf("%4ld %4ld %4ld %7s %s %s\n", α, β, σ, rays[(ρ + 1) * δ + 5], __FUNCTION__, (char*)ο[τ+5]), usleep(2000), goTo(obatsrd); }
N(lbl) {
  ο[Blue(σ)-1] = ο[Red(σ)-1] = ο[Green(σ)-1] = ο[Yellow(σ)-1] = goTo,
  ο[Blue(σ)  ] = ο[Red(σ)  ] = ο[Green(σ)  ] = ο[Yellow(σ)  ] = δ_switch,
  ο[Blue(σ)+1] = ο[Red(σ)+1] = ο[Green(σ)+1] = ο[Yellow(σ)+1] = lbl_print,
  ο[Blue(σ)+5] = ο[--α], type(obatsrd);
}
N(α0_set) { α = 0, goTo(obatsrd); }
N(α0) { ο[Blue(σ)  ] = ο[Red(σ)] = ο[Green(σ)] = ο[Yellow(σ)] = α0_set, type(obatsrd); }

N(S) { 
  ο[α++] = "b", ο[α++] = ο[β+2], ο[α++] = ο[β+1],
  ο[α++] = "a", ο[α++] = ο[β+2], ο[α++] = ο[β+1],
  ο[α++] = "t", ο[α++] = ο[β+2], ο[α++] = ο[β], oa(obatsrd);
}
N(n678) {
  ο[α++] = "6", ο[α++] = ο[β+2], ο[α++] = ο[β+1],
  ο[α++] = "7", ο[α++] = ο[β+2], ο[α++] = ο[β+1],
  ο[α++] = "8", ο[α++] = ο[β+2], ο[α++] = ο[β], oa(obatsrd);
}
N(n345) {
  ο[α++] = "3", ο[α++] = ο[β+2], ο[α++] = ο[β+1],
  ο[α++] = "4", ο[α++] = ο[β+2], ο[α++] = ο[β+1],
  ο[α++] = "5", ο[α++] = ο[β+2], ο[α++] = ο[β], oa(obatsrd);
}
N(n123) {
  ο[α++] = "1", ο[α++] = ο[β+2], ο[α++] = ο[β+1],
  ο[α++] = "2", ο[α++] = ο[β+2], ο[α++] = ο[β+1],
  ο[α++] = "3", ο[α++] = ο[β+2], ο[α++] = n345, ο[α++] = ο[β+3], ο[α++] = ο[β], oa(obatsrd);
}
N(r) {
  ο[α++] = "bat", ο[α++] = str,
  ο[α++] = S, ο[α++] = ο[β+3],
  ο[α++] = S, ο[α++] = ο[β+3],
  ο[α++] = S, ο[α++] = ο[β+3],
  ο[α++] = ο[β], oa(obatsrd);
}
int main() {
  long ram[Σ + Σ + Σ + Σ + Σ]; 
  long*ο = ram + Σ;
  long β = 0; 
  long α = 0;
  long τ = 0;
  long σ = Σ;
  long ρ = 3;
  long δ = 1;
  ο[α++] = b,
  ο[α++] = print,
  ο[α++] = "b", ο[α++] = lbl,
  ο[α++] = r,   ο[α++] = var,
  ο[α++] = "o", ο[α++] = lbl,
  ο[α++] = o,
  oa(obatsrd);
}
