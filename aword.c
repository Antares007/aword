#include "aword.h"
N(cb) {
  if (ρ == 1)
    m(τ, ρ, 1);
  else
    m(τ[5], ρ == 3 ? 1 : ρ, (long)τ[-5]);
}
N(A) { m(τ, ρ, δ); }
N(B) { m(τ, ρ, δ); }
N(toti_pith) {
  if (ρ == 1 && δ == 1) {
    ((void **)τ[5])[5] = τ;
    ((long *)τ[5])[-5] = 1;
    m(τ[5], ρ, 1);
  } else
    m(τ, ρ, δ);
}
N(toti) {
  void *tot[] = {T(cb), T(A), T(B), T(o)};
  *τ = toti_pith;
  τ[5] = tot + 5;
  toti_pith(τ, ρ, δ);
}
void ti_init();
N(M) { m(τ, ρ, δ); }
int main() {
  ti_init();
  void *text[] = {T(b), T(m), T(toti), T(M), T(o)};
  m(text + 5, 3, 1);
}
