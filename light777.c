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

N(goto_515) { ((n_t)ο[τ + δ * 16])(ο, β, α, τ + δ * 11, σ, ρ, δ); }
N(goto_a  ) { ((n_t)ο[α - 1])(ο, β, α - 1, τ, σ, ρ, δ); }

N(begin_it) { if(ο[β++] < 2) P, goto_515(oba, τ, σ, 3, -δ); }
N(begin   ) { ο[σ - 5] = begin_it, goto_515(oba, σ, σ - 11, 3, 1); }
N(end_it  ) { P, ο[--β] = ρ, goto_515(oba, τ, σ, ρ, -δ); }
N(end     ) { ο[σ + 5] = end_it, σ -= 11, goto_a(obatsrd); }

//
//             b
//             |
//        g__wsg__wsg____wog
//             |
//             g__wsg__wsg____wog
//             |
//             |
//             |
//  g___g____wsg__wsg__wog
//      |      |
//     wsg     |
//      |      |
//     wog     |
//             e
//

N(term_bk) {
  P;
  goto_515(obatsrd);
}
N(put_it);
N(term_it_Yellow) {
  put_it(obatsrd);
  //P;
  //if(ο[α-1] < ο[α-2] && ((char**)ο)[τ][0] == ((char**)ο)[α-3][ο[α-1]])
  //  ο[α-1]++, goto_515(obatsrd);
  //else {
  //}
}
N(ρ_switch) { ((n_t)ο[τ + (ρ + 1) * δ])(obatsrd); }
N(term) {
  ο[σ - 5] = term_bk;
  ο[σ] = ο[--α];
  ο[σ + 1] = term_it_Yellow,
  ο[σ + 2] = term_it_Yellow,
  ο[σ + 3] = term_it_Yellow,
  ο[σ + 4] = term_it_Yellow,
  ο[σ + 5] = ρ_switch;
  σ -= 11, goto_a(obatsrd);
}
N(shift_it) { P, ο[ο[τ]] = τ + 11, goto_515(oba, τ, σ, ρ - 2, δ); }
N(shift   ) {
  ο[σ - 5] = goto_515,
  ο[σ] = τ,
  ο[σ + 1] = ο[σ + 2] = goto_515, ο[σ + 3] = ο[σ + 4] = shift_it, ο[σ + 5] = ρ_switch;
  σ -= 11, goto_a(obatsrd);
}

N(goto_it ) { P, goto_515(oba, ο[τ], srd); }
N(goTo    ) { ο[σ - 5] = goto_it,  ο[σ] = τ, ο[σ + 5] = goto_it; σ -= 11, goto_a(obatsrd); }

N(ward_it ) { ο[ο[τ] - 1] = τ + 11, ο[ο[τ] - 2] = ρ, goto_515(obatsrd); }
N(ward    ) { 
  ο[σ - 5] = ρ_switch,
  ο[σ - 4] = goto_515,
  ο[σ - 3] = goto_515,
  ο[σ - 2] = goto_515,
  ο[σ - 1] = goto_515,
  ο[σ] = τ, ο[σ + 5] = ward_it; σ -= 11, goto_a(obatsrd);
}

N(reset_it) { P, ο[ο[τ]] = ο[ο[τ] + 1], goto_515(obatsrd); }
N(reset   ) {
  ο[σ - 5] = goto_515;
  ο[σ] = τ;
  ο[σ + 1] = ο[σ + 2] = goto_515, ο[σ + 3] = ο[σ + 4] = reset_it, ο[σ + 5] = ρ_switch;
  σ -= 11, goto_a(obatsrd);
}

N(semicoma) {
  ο[α++] = ward;
  ο[α++] = shift;
  ο[α++] = goTo;
  goto_a(obatsrd);
}
N(dot     ) {
  ο[α++] = ward;
  ο[α++] = reset;
  ο[α++] = goTo;
  goto_a(obatsrd);
}

N(end_tran) {
  ο[τ] = ο[τ + 1] = σ + 11, ο[τ + 5] = goto_it, goto_it(obatsrd);
}
N(run_tran) {
  n_t transcript = ο[τ];
  ο[α++] = end_tran;
  ο[α++] = goTo;
  transcript(obatsrd);
}
N(goto_ward) { P; goto_515(oba, ο[τ - 1], σ, ο[τ - 2], δ); }
N(var) {
  n_t transcript = ο[--α];
  ο[σ - 5] = goto_ward, ο[σ] = transcript, ο[σ + 5] = run_tran, σ -= 11, goto_a(obatsrd);
}

N(S) { P; }

N(put_it  ) { P, ο[α++] = ο[τ], goto_515(obatsrd); }
N(put     ) { ο[σ - 5] = goto_515, ο[σ] = ο[--α], ο[σ + 5] = put_it, σ -= 11, goto_a(obatsrd); }

N(print_it) {
  P;
  if (α) {
    for (long i = 0; i < α; i++)
      printf("%s", (char *)ο[i]);
    printf("\n");
    α = 0;
    usleep(20000);
  }
  goto_515(obatsrd);
}
N(print) { ο[σ - 5] = goto_515, ο[σ + 5] = print_it, σ -= 11, goto_a(obatsrd); }
N(bat) {
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
int main() {
  long ram[2048];
  long *ο = ram + 512, β = 0, α = 0, τ = 0, σ = 1536, ρ = 4, δ = 1;

  ο[α++] = begin;
  //  ο[α++] = "baaa";  ο[α++] = put;
  ο[α++] = bat;     ο[α++] = var;
  ο[α++] = bat;     ο[α++] = var;
  ο[α++] = bat;     ο[α++] = var;

  ο[α++] = print;
  ο[α++] = end;
  goto_a(obatsrd);
}
// how we plan to grow language?
// we need to put growing ring around pith.
// what is the pith?
//
// we have
// 505 - fully closed words
// aradani - fully closed with import/export dynamic linking
// 515 - using native arrays allocated on stac
// 515 - double sides of execution
// 515 - kalachackra double sides of execution
//
// 
