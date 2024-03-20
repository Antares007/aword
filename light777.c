// clang-format off
#define N(argo)                                                                \
  void argo(long *ο, long β, long α, long τ, long σ, long ρ, long δ)
typedef N((*n_t));

#ifndef NDEBUG
#define P                                                                      \
  printf("%4ld %4ld %4ld %7s %s\n", α, β, τ, rays[(ρ + 1) * δ + 5],            \
         __FUNCTION__),                                                        \
      usleep(20000)
#else
#define P (void)0
#endif

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};
#define oba     ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define     srd             σ, ρ, δ

N(goTo) { ((n_t)ο[τ + δ * 16])(ο, β, α, τ + δ * 11, σ, ρ, δ); }
N(yoTo) { goTo(ο, β, α, τ, σ, ρ, δ); }

N(define) {}
N(t_term) {}
N(t_dot) {}
N(t_var    ) {
  ο[σ+5] = 0,      ο[σ] = 0,     ο[σ-5] = 0,     σ -= 11, goTo(obatsrd);
  ο[σ+5] = 0,      ο[σ] = 0,     ο[σ-5] = 0,     σ -= 11, goTo(obatsrd);
  ο[σ+5] = 0,      ο[σ] = 0,     ο[σ-5] = 0,     σ -= 11, goTo(obatsrd);
}
N(notdef) { assert(0); }
N(play_ground ) {
                                 ο[α-5] = notdef,α += 11,

  ο[α+5] = goTo,   ο[α] = "tab", ο[α-5] = define,α += 11,
  ο[α+5] = t_term, ο[α] = "t",   ο[α-5] = goTo,  α += 11,
  ο[α+5] = t_dot,                ο[α-5] = goTo,  α += 11,
  ο[α+5] = t_term, ο[α] = "a",   ο[α-5] = goTo,  α += 11,
  ο[α+5] = t_dot,                ο[α-5] = goTo,  α += 11,
  ο[α+5] = t_term, ο[α] = "b",   ο[α-5] = goTo,  α += 11,
  ο[α+5] = t_dot,                ο[α-5] = goTo,  α += 11,
                                    
  ο[α+5] = goTo,   ο[α] = "S",   ο[α-5] = define,α += 11,
  ο[α+5] = t_term, ο[α] = "b",   ο[α-5] = goTo,  α += 11,
  ο[α+5] = t_dot,                ο[α-5] = goTo,  α += 11,
  ο[α+5] = t_var,  ο[α] = "S",   ο[α-5] = goTo,  α += 11,
  ο[α+5] = t_dot,                ο[α-5] = goTo,  α += 11,
  ο[α+5] = t_term, ο[α] = "a",   ο[α-5] = goTo,  α += 11,
  ο[α+5] = t_dot,                ο[α-5] = goTo,  α += 11,

  ο[σ+5] = yoTo,                                 σ -= 11,
                                 ο[σ-5] = yoTo,  σ -= 11,
//  goTo(oba, σ, σ - 11, 3, 1);
}
int main() {
  long ram[2048];
  long *ο = ram + 512, β = 0, α = 0, τ = 0, σ = 1536, ρ = 4, δ = 1;
  play_ground(obatsrd);
}
