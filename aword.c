#pragma GCC diagnostic ignored "-Wint-conversion"
#define N(argo) void argo(long *ο, long β, long α, long τ, long σ, long ρ, long δ)
#define aContext ο, β, α, τ, σ, ρ, δ
typedef N((*n_t));
#include <stdio.h>
N(goTo    ) {                 τ += 11, ((n_t)ο[τ])(aContext); }
N(ret     ) {                     τ = ο[β++], goTo(aContext); }
N(call    ) {      ο[--β] = τ, τ += ο[τ + 5], goTo(aContext); }
N(halt    ) {}
N(print   ) { printf("%s", (char *)ο[τ + 5]), goTo(aContext); }
int main( ) {
  long β = 1024;
  long ο[β * 5] = {};
  long α = 0;
  long τ = β;
  long σ = τ;
  long ρ = 3;
  long δ = 1;

  ο[σ] = call,  ο[σ + 5] = 44,            σ += 11;
  ο[σ] = call,  ο[σ + 5] = 55,            σ += 11;
  ο[σ] = call,  ο[σ + 5] = 66,            σ += 11;
  ο[σ] = print, ο[σ + 5] = ".\n",         σ += 11;
  ο[σ] = halt,                            σ += 11;
  ο[σ] = print, ο[σ + 5] = "actionable",  σ += 11;
  ο[σ] = ret,                             σ += 11;
  ο[σ] = print, ο[σ + 5] = " ",           σ += 11;
  ο[σ] = ret,                             σ += 11;
  ο[σ] = print, ο[σ + 5] = "word",        σ += 11;
  ο[σ] = ret,                             σ += 11;

  τ -= 11, goTo(aContext);

  return 0;
}

