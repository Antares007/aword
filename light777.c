// clang-format off
#define N(argo) void argo(long*ο, long β, long α, long τ, long σ, long ρ, long δ)
typedef N((*n_t));

#ifndef NDEBUG
#define P printf("%ld %ld %ld %7s %s\n", σ, ρ, δ, rays[(ρ + 1) * δ + 5], __FUNCTION__), usleep(200000)
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
//  broadcast twelve
//  +1. +....1.....
//  +....1..... +1. 
//  -1+-1+
//  ₁₁....1..... ₁₁....1..... 
//  
//  |  |  |  |  |  |00|  |  |  |  |  |
N(goto_515) { ((n_t)ο[τ+δ*16])(ο, β, α, τ+δ*11, σ, ρ, δ); }
N(goto_a) { ((n_t)ο[τ+α-1])(ο, β, α-1, τ, σ, ρ, δ); }

N(semicoma) { }
N(o) { ο[σ] = 0; }

N(reverse_δ ) { P, goto_515(oba, τ, σ, ρ, -δ); }
N(cycle     ) { P; if(ρ<2) reverse_δ(obatsrd); }
N(begin     ) { P, ο[σ-5] = cycle, goto_515(oba, σ, σ - 11, 3, 1); }
N(end       ) { P, ο[σ+5] = reverse_δ, σ -= 11, goto_a(obatsrd); }

N(put_it) {P, ο[α++] = ο[τ], goto_515(obatsrd); }
N(put) {P, ο[σ-5] = goto_515, ο[σ] = ο[--α], ο[σ+5] = put_it, σ -= 11, goto_a(obatsrd); }

N(print_it) {P;
  if(α) {
    for(long i = 0; i < α; i++) printf("%s", (char*)ο[i]);
    printf("\n");
    α = 0;
    usleep(200000);
  }
  goto_515(obatsrd);
}
N(print) {P, ο[σ-5] = goto_515, ο[σ+5] = print_it, σ -= 11, goto_a(obatsrd); }

N(term_parse) {
  printf("%s\n", (char*)ο[τ+1]);
  goto_515(obatsrd);
}
N(var) { ο[σ] = 0; }
N(bat) {
  n_t var       = ο[β+3];
  n_t term      = ο[β+2];
  n_t semicoma  = ο[β+1];
  n_t dot       = ο[β];
  ο[α++]        = "b",  ο[α++] = term,  ο[α++] = semicoma,
  ο[α++]        = "a",  ο[α++] = term,  ο[α++] = semicoma,
  ο[α++]        = "t",  ο[α++] = term,  dot(obatsrd);
}
int main() {
  long ram[2048];
  long*ο = ram + 512;
  long β = 0;
  long α = 0;
  long τ = 0;
  long σ = 1536;
  long ρ = 4;
  long δ = 1;
  ο[α++] = begin,
  ο[α++] = "a", ο[α++] = put,
  ο[α++] = "n", ο[α++] = put,
  ο[α++] = "d", ο[α++] = put,
  ο[α++] = "r", ο[α++] = put,
  ο[α++] = "i", ο[α++] = put,
  ο[α++] = "a", ο[α++] = put,
  ο[α++] = print,
  ο[α++] = end, goto_a(obatsrd);
}
