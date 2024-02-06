#define N(argo)                                                                \
  void argo(long *ο, long β, long α, long τ, long σ, long ρ, long δ)
typedef N((*n_t));

#ifndef NDEBUG
#define P                                                                      \
  printf("%4ld %2ld %2ld %7s %s\n", α, ρ, δ, rays[(ρ + 1) * δ + 5],            \
         __FUNCTION__),                                                        \
      usleep(200000)
#else
#define P (void)0
#endif

#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};
#define oba ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define srd σ, ρ, δ

N(goto_515) { ((n_t)ο[τ + δ * 16])(ο, β, α, τ + δ * 11, σ, ρ, δ); }
N(goto_a) { ((n_t)ο[α - 1])(ο, β, α - 1, τ, σ, ρ, δ); }

N(reverse_δ) { goto_515(oba, τ, σ, ρ, -δ); }
N(cycle) { ρ = (ρ + 1) % 4, reverse_δ(obatsrd); }
N(begin) { ο[σ - 5] = cycle, goto_515(oba, σ, σ - 11, 3, 1); }
N(end) { ο[σ + 5] = reverse_δ, σ -= 11, goto_a(obatsrd); }

N(put_it) {
  P;
  ο[α++] = ο[τ];
  goto_515(obatsrd);
}
N(put) {
  P;
  ο[σ - 5] = goto_515;
  ο[σ] = ο[--α];
  ο[σ + 5] = put_it;
  σ -= 11, goto_a(obatsrd);
}

N(print_it) {
  P;
  if (α) {
    for (long i = 0; i < α; i++)
      printf("%s", (char *)ο[i]);
    printf("\n");
    α = 0;
    usleep(200000);
  }
  goto_515(obatsrd);
}
N(print) {
  P;
  ο[σ - 5] = goto_515;
  ο[σ + 5] = print_it;
  σ -= 11, goto_a(obatsrd);
}
//
//   (((₀)₁)₁)₂
//      0 1 1 2
//  ((((₀)₁)₁)¹)₂
//
//      0 11  10
//      ₀(₁₁ )₁₀
//      ₀(₁₁₁)¹₀
//      0 111 0
//
//      0 11 0
//      ₀(₁₁)₀
//      ₀(₁ )⁰
//      0 1  10
//
N(term_it) {
  P;
  goto_515(obatsrd);
}
N(term) {
  P;
  ο[σ - 5] = goto_515;
  ο[σ] = ο[--α];
  ο[σ + 5] = term_it;
  σ -= 11, goto_a(obatsrd);
}

N(semicoma_it) {
  P;
  ο[ο[τ]] = 0;
}
N(ρ_switch) { ((n_t)ο[τ + (ρ + 1) * δ])(obatsrd); }
N(semicoma) {
  P;
  ο[σ - 5] = goto_515;
  ο[σ] = ο[β];
  ο[σ + 1] = semicoma_it;
  ο[σ + 2] = semicoma_it;
  ο[σ + 3] = semicoma_it;
  ο[σ + 4] = semicoma_it;
  ο[σ + 5] = ρ_switch;
  σ -= 11, goto_a(obatsrd);
}

N(dot_it) {
  P;
  long v = ο[τ];
  ο[v] = 0;
}
N(dot) {
  P;
  ο[σ - 5] = goto_515;
  ο[σ] = τ;
  ο[σ + 1] = dot_it;
  ο[σ + 2] = dot_it;
  ο[σ + 3] = dot_it;
  ο[σ + 4] = dot_it;
  ο[σ + 5] = ρ_switch;
  σ -= 11, goto_a(obatsrd);
}
N(var_it) { P; }
N(finish_typing_var) {
  P;
  ο[σ] = 0;
  ο[τ] = σ;
  ο[τ + 5] = var_it;
  σ += 11, goto_515(obatsrd);
}
N(start_typing_var) {
  P;
  ο[α++] = finish_typing_var;
  ((n_t)ο[τ])(obatsrd);
}
N(var) {
  P;
  ο[σ - 5] = goto_515;
  ο[σ] = ο[--α];
  ο[σ + 5] = start_typing_var;
  σ -= 11, goto_a(obatsrd);
}

N(bat) {
  P;
  ο[α++] = "b";
  ο[α++] = term;
  ο[α++] = semicoma;
  ο[α++] = "a";
  ο[α++] = term;
  ο[α++] = semicoma;
  ο[α++] = "t";
  ο[α++] = term;
  ο[α++] = dot;
  goto_a(obatsrd);
}
N(id_Olive) { P, goto_515(obatsrd); }
N(id_Maroon) { P, goto_515(obatsrd); }
N(id_Lime) { P, goto_515(obatsrd); }
N(id_Navy) { P, goto_515(obatsrd); }
N(id_Blue) { P, goto_515(obatsrd); }
N(id_Green) { P, goto_515(obatsrd); }
N(id_Red) { P, goto_515(obatsrd); }
N(id_Yellow) { P, goto_515(obatsrd); }

N(id) {
  P;
  ο[σ - 5] = ρ_switch;
  ο[σ - 4] = id_Olive;
  ο[σ - 3] = id_Maroon;
  ο[σ - 2] = id_Lime;
  ο[σ - 1] = id_Navy;
  ο[σ + 1] = id_Blue;
  ο[σ + 2] = id_Green;
  ο[σ + 3] = id_Red;
  ο[σ + 4] = id_Yellow;
  ο[σ + 5] = ρ_switch;
  σ -= 11, goto_a(obatsrd);
}
N(S) { P; }

int main() {
  long ram[2048];
  long *ο = ram + 512, β = 0, α = 0, τ = 0, σ = 1536, ρ = 4, δ = 1;

  ο[α++] = begin;
  //  ο[α++] = "baaa";
  //  ο[α++] = put;
  //  ο[α++] = bat;
  //  ο[α++] = var;

  ο[α++] = id;
  //  ο[α++] = print;
  ο[α++] = end;
  goto_a(obatsrd);
}
// how we plan to grow language?
// we need to put growing ring around pith.
// what is the pith?
