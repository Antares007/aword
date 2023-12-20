#include <assert.h>
#include <stdio.h>
#include <unistd.h>

#define N(argo)                                                                \
  void argo(long*ο, long β, long α, long τ, long σ, long ρ, long δ)
typedef N((*n_t));

const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};
#define P printf("%4ld %4ld %4ld %4ld %7s %s\n", σ, α, β, (τ/Σ+1)*δ, rays[(ρ + 1) * δ + 5], __FUNCTION__), usleep(200000)

#define oba ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define srd σ, ρ, δ
#define Σ 2048
N(goTo      ) { ((n_t)ο[τ + Σ*ρ + 11*δ])(oba, τ + 11*δ, srd); }
N(o         );// { goTo(oba, τ, σ, ρ, -δ); }
N(δ_switch  ) { ((n_t)ο[τ + Σ*ρ + δ])(obatsrd); }

#define Blue(τ)   (τ)
#define Green(τ)  (Σ+Blue(τ))
#define Red(τ)    (Σ+Σ+Blue(τ))
#define Yellow(τ) (Σ+Σ+Σ+Blue(τ))
N(term_b) {}
N(term_a) { printf("%20s %7s\n", (char*)ο[τ+5], rays[(ρ + 1) * δ + 5]), usleep(200000), goTo(obatsrd); }
N(term) {
  ο[Yellow(σ)] = term_a, ο[Red(σ)] = term_a, ο[Green(σ)] = term_a, ο[Blue(σ)  ] = term_a, 
                                                                   ο[Blue(σ)+5] = ο[--α],
  σ -= 11;
  ((n_t)ο[α-1])(ο, β, α-1, τ, srd);
}
// .....S....
//      S[5] = G A D  ttt  A ⚙ G  ttt  A ⚙
//      t actionable text
//      G goTo_t5
//      A ward_arm
//      D door
//      1 propeller1
//      2 propeller2
//      
N(goTo_t5) { goTo(oba, ο[τ+5], srd); }
N(tab) { 
  ο[Yellow(σ)  ] = ο[Red(σ)  ] = ο[Green(σ)  ] = ο[Blue(σ)  ] = goTo_t5;
                                                 ο[Blue(σ)+5] = ο[β-5];
  σ -= 11;
  ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(goTo_ward) { goTo(oba, ο[τ-5], σ, ο[τ-4], δ); }
N(ward_arm_nar) { (ο[ο[τ+5] - 5] = τ), (ο[ο[τ+5] - 4] = ρ), goTo(obatsrd); }
N(ward_arm) { 
  ο[Yellow(σ)  ] = ο[Red(σ)  ] = ο[Green(σ)  ] = ο[Blue(σ)  ] = ward_arm_nar;
                                                 ο[Blue(σ)+5] = ο[β-5];
  σ -= 11;
  ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(close_door) { (ο[Red(τ)] = ο[Blue(τ)] = δ_switch), goTo(obatsrd); }
N(open_door ) { (ο[Red(τ)] = ο[Blue(τ)] = goTo), goTo(obatsrd); }
N(door) { 
  ο[Yellow(σ)-1] = close_door;ο[Red(σ)-1] = goTo;                        ο[Blue(σ)-1] = goTo;
  ο[Yellow(σ)  ] = δ_switch;  ο[Red(σ)  ] = δ_switch;ο[Green(σ)] = goTo; ο[Blue(σ)  ] = δ_switch;
  ο[Yellow(σ)+1] = open_door; ο[Red(σ)+1] = goTo_t5;                     ο[Blue(σ)+1] = goTo_t5;
                                                                         ο[Blue(σ)+5] = ο[β-5];
  σ -= 11;
  ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(next_arm) { ο[ο[τ+5]+5] = τ+11, goTo_t5(oba,τ,σ,ρ-2,δ); }
N(propeller1) {
  ο[Yellow(σ)] = next_arm,  ο[Red(σ)] = next_arm,  ο[Green(σ)] = goTo_t5, ο[Blue(σ)] = goTo_t5,
                                                                          ο[Blue(σ)+5] = ο[β-5],
  σ -= 11;
  ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(reset_arm) { ο[ο[τ+5]+5] = ο[ο[τ+5]+4], goTo_t5(obatsrd); }
N(propeller2) {
  ο[Yellow(σ)] = reset_arm, ο[Red(σ)] = reset_arm, ο[Green(σ)] = goTo_t5, ο[Blue(σ)] = goTo_t5,
                                                                          ο[Blue(σ)+5] = ο[β-5],
  σ -= 11;
  ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(o_next) { 
  ο[α++] = ward_arm;
  ο[α++] = propeller1;
  ο[α++] = tab;
  ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(o_last) { 
  ο[α++] = ward_arm;
  ο[α++] = propeller2;
  ο[β-4] = o_next;
  ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(o) { ((n_t)ο[β-4])(obatsrd); }
N(var_end) { 
  β -= 5;
  ο[Yellow(τ)+1] = goTo_t5,ο[Red(τ)+1] = goTo_t5, ο[Green(τ)+1] = goTo_t5,ο[Blue(τ)+1] = goTo_t5,     
  ο[τ+4] = ο[τ+5] = σ + 11;
  ((n_t)ο[τ])(obatsrd);
}
N(var);
N(var_start) { 
  ο[β++] = τ; ο[β++] = o_last; ο[β++] = var; ο[β++] = term; ο[β++] = o;
  ο[α++] = var_end; ο[α++] = tab; ο[α++] = ward_arm; ο[α++] = door;
  ((n_t)ο[Blue(τ+5)])(obatsrd);
}
N(var) { 
  ο[Yellow(σ)-1] = goTo_ward,ο[Red(σ)-1] = goTo_ward, ο[Green(σ)-1] = goTo_ward,ο[Blue(σ)-1] = goTo_ward,
  ο[Yellow(σ)  ] = δ_switch, ο[Red(σ)  ] = δ_switch,  ο[Green(σ)  ] = δ_switch, ο[Blue(σ)  ] = δ_switch,
  ο[Yellow(σ)+1] = var_start,ο[Red(σ)+1] = var_start, ο[Green(σ)+1] = var_start,ο[Blue(σ)+1] = var_start,
                                                                                ο[Blue(σ)+5] = ο[--α],
  σ -= 11;
  ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(S) { 
  n_t o = ο[β-1], term = ο[β-2], var = ο[β-3]; (void)var;
  ο[α++] = "b", ο[α++] = term, ο[α++] = o,
  ο[α++] = "a", ο[α++] = term, ο[α++] = o,
  ο[α++] = "t", ο[α++] = term, ο[α++] = o, ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(n345) { 
  n_t o = ο[β-1], term = ο[β-2], var = ο[β-3]; (void)var;
  ο[α++] = "3", ο[α++] = term, ο[α++] = o,
  ο[α++] = "4", ο[α++] = term, ο[α++] = o,
  ο[α++] = "5", ο[α++] = term, ο[α++] = o, ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(n123) { 
  n_t o = ο[β-1], term = ο[β-2], var = ο[β-3]; (void)var;
  ο[α++] = "1", ο[α++] = term, ο[α++] = o,
  ο[α++] = "2", ο[α++] = term, ο[α++] = o,
  ο[α++] = "3", ο[α++] = term, ο[α++] = n345, ο[α++] = var, ο[α++] = o, ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}

N(b) { goTo(obatsrd); }
N(a) { goTo(obatsrd); }
N(t) { goTo(obatsrd); }

N(dot_turn) { P; ο[β++] = ρ; goTo(oba, τ, σ, ρ, -δ); }
N(dot  ) {
  ο[Yellow(σ)] = dot_turn, ο[Red(σ)] = dot_turn,  ο[Green(σ)] = dot_turn, ο[Blue(σ)] = dot_turn,
  σ -= 11;
  ((n_t)ο[α-1])(ο, β, α - 1, τ, srd);
}
N(nop  ) { assert(0); }
N(aword) { P; long p = ο[--β]; if(p < 2) goTo(oba, τ, σ, ρ, -δ); }
N(tword) {
  ο[Yellow(σ)] = aword, ο[Red(σ)] = nop, ο[Green(σ)] = nop, ο[Blue(σ)] = nop,
  goTo(oba, σ, σ-11, ρ, δ);
}
int main() {
  long ο[Σ + Σ + Σ + Σ];
  long β = Σ; 
  long α = 0;
  long τ = 0;
  long σ = Σ;
  long ρ = 3;
  long δ = 1;
  *ο = Σ;
  ο[α++] = tword,
  ο[α++] = "before",ο[α++] = term,
  ο[α++] = n123,       ο[α++] = var,
  ο[α++] = n123,       ο[α++] = var,
  ο[α++] = n123,       ο[α++] = var,
  ο[α++] = "after", ο[α++] = term,
  ο[α++] = dot;
  ((n_t)ο[α-1])(ο, β, α-1, τ, srd);
}
