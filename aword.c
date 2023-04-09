#include "aword.h"
void ti_move(Args, N((*nar)));
void ti_turn_left(Args, N((*nar)));
N(m) {
  τ = τ + 11 * δ;
  ti_move(τ, ρ, δ, τ[0]);
}
N(mb) {
  τ = τ[5], τ[-5] = (void *)δ, ρ = 3, δ = 1;
  m(τ, ρ, δ);
}
N(mc) { m(τ[5], ρ == 3 ? 1 : ρ, (long)τ[-5]); }
N(b) { m(τ, ρ, -δ); }
N(o) { b(τ, ρ == 3 ? 1 : ρ == 1 ? 3 : ρ, δ); }

N(cb) {
  if (ρ == 1)
    b(τ, ρ, δ);
  else
    ti_turn_left(τ, ρ, δ, mc);
}
N(A) { m(τ, ρ, δ); }
N(B) { m(τ, ρ, δ); }
N(toti_pith) {
  if (ρ == 1 && δ == 1)
    ti_turn_left(τ, ρ, δ, mb);
  else
    m(τ, ρ, δ);
}
N(and);
N(go_Red);
N(toti) {
  void *tot[] = {Ta(cb, τ), T(A), T(B),T(A),T(and), T(B),T(A), T(B), T(o)};
  *τ = toti_pith;
  τ[5] = tot + 5;
  toti_pith(τ, ρ, δ);
}
void ti_init();
N(M) { m(τ, ρ, δ); }
int main() {
  ti_init();
  void *text[] = {T(b),  T(m), T(o)};
  m(text + 5, 3, 1);
}
