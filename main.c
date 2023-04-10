#include <stdio.h>
#include <unistd.h>
#define P printf("%5s %s\n", (char *)ο[τ].v, __FUNCTION__), usleep(100000)
#define N(argo) void argo(long τ, long α, long β, struct base_t *ο, long σ)
//    τ
// bnnna....owwww
//
//          ατ
//      ___.wwb.wwb
// ονννσ
//      ___.wwb.wwb
//
typedef struct base_t {
  union {
    long q;
    void *v;
    N((*c));
  };
} base_t;
typedef N((*n_t));
// clang-format off
N(Yellow    ) { P, ο[τ + 5].c(τ + 9, α, β, ο, σ); }
N(Red       ) { P, ο[τ + 6].c(τ + 9, α, β, ο, σ); }
N(Green     ) { P, ο[τ + 7].c(τ + 9, α, β, ο, σ); }
N(Blue      ) { P, ο[τ + 8].c(τ + 9, α, β, ο, σ); }
N(DarkBlue  ) { P, ο[τ - 8].c(τ - 9, α, β, ο, σ); }
N(DarkGreen ) { P, ο[τ - 7].c(τ - 9, α, β, ο, σ); }
N(DarkRed   ) { P, ο[τ - 6].c(τ - 9, α, β, ο, σ); }
N(DarkYellow) { P, ο[τ - 5].c(τ - 9, α, β, ο, σ); }
N(grow      ) { ο[σ - 1].c(τ, α, β, ο, σ - 1); }
N(tab) {
  ο[β*0+--α].v = Yellow, ο[β*1+α].v = Yellow, ο[β*2+α].v = Yellow;
  ο[β*0+--α].v = Red,    ο[β*1+α].v = Red,    ο[β*2+α].v = Red;
  ο[β*0+--α].v = Green,  ο[β*1+α].v = Green,  ο[β*2+α].v = Green;
  ο[β*0+--α].v = Blue,   ο[β*1+α].v = Blue,   ο[β*2+α].v = Blue;
  ο[τ=β*0+--α].v = "tab0";
  ο[  β*1+--α].v = "tab1";
  ο[  β*2+--α].v = "tab2";
  ο[β*0+--α].v = Blue,   ο[β*1+α].v = Blue,   ο[β*2+α].v = Blue;
  ο[β*0+--α].v = Green,  ο[β*1+α].v = Green,  ο[β*2+α].v = Green;
  ο[β*0+--α].v = Red,    ο[β*1+α].v = Red,    ο[β*2+α].v = Red;
  ο[β*0+--α].v = Yellow, ο[β*1+α].v = Yellow, ο[β*2+α].v = Yellow;
  Yellow(τ, α, β, ο, σ);
}
N(dot) {
  ο[--α].v = "dot";
  ο[--α].v = DarkBlue;
  ο[--α].v = DarkYellow;
  ο[--α].v = DarkRed;
  ο[--α].v = DarkGreen;
  grow(τ, α, β, ο, σ);
}
N(toti) {
  ο[--α].v = dot;
  ο[--α].v = Red;
  ο[--α].v = Green;
  ο[--α].v = Blue;
  ο[τ = --α].v = "toti";
  ο[--α].v = Blue;
  ο[--α].v = Green;
  ο[--α].v = Red;
  ο[--α].v = Yellow;
  Yellow(τ, α, β, ο, σ);
}
N(word) {
  ο[--α].v = DarkYellow;
  ο[--α].v = DarkRed;
  ο[--α].v = DarkGreen;
  ο[--α].v = DarkBlue;
  ο[--α].v = "word";
  ο[--α].v = Blue;
  ο[--α].v = Green;
  ο[--α].v = Red;
  ο[--α].v = Yellow;
  grow(τ, α, β, ο, σ);
}
int main() {
  long τ, σ = 0;
  base_t ο[1024];
  long α = sizeof(ο) / sizeof(*ο), β = 0;
  ο[σ++].v = tab;
  ο[σ++].v = word;
  ο[σ++].v = toti;
  ο[σ++].v = word;
  ο[σ++].v = dot;
  grow(τ, α, β, ο, σ);
  return 0;
}
