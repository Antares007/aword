#include "aword.h"
void ti_move(Args, N((*cb)));
void ti_around(Args, N((*cb)));
void ti_left(Args, N((*cb)));
N(m) {
  τ = τ + 11 * δ;
  N((*nar)) = τ[0];
  ti_move(τ, ρ, δ, nar);
}
N(mb) {
  τ = τ[5], τ[-5] = (void *)δ, ρ = 3, δ = 1;
  ti_left(τ, ρ, δ, m);
}
N(mc) { ti_left(τ[5], ρ == 3 ? 1 : ρ, (long)τ[-5], m); }
N(b) { ti_around(τ, ρ, -δ, m); }
N(o) { b(τ, ρ == 3 ? 1 : ρ == 1 ? 3 : ρ, δ); }

N(cb) {
  if (ρ == 1)
    b(τ, ρ, δ);
  else
    mc(τ, ρ, δ);
}
N(A) { m(τ, ρ, δ); }
N(B) { m(τ, ρ, δ); }
N(toti_pith) {
  if (ρ == 1 && δ == 1)
    mb(τ, ρ, δ);
  else
    m(τ, ρ, δ);
}
N(toti) {
  void *tot[] = {Ta(cb, τ), T(A), T(B), T(toti), T(o)};
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
