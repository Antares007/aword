#include "aword.h"
void ti_move(Args, N((*nar)));
void ti_turn_left(Args, N((*nar)));
N(m) {
  τ = τ + 11 * ι;
  ti_move(ο, τ, α, ρ, ι, τ[0]);
}
N(mb) {
  τ = τ[5], τ[-5] = (void *)ι, ρ = 3, ι = 1;
  m(ο, τ, α, ρ, ι);
}
N(mc) { m(ο, τ[5], α, ρ == 3 ? 1 : ρ, (long)τ[-5]); }
N(b) { m(ο, τ, α, ρ, -ι); }
N(o) { b(ο, τ, α, ρ == 3 ? 1 : ρ == 1 ? 3 : ρ, ι); }

N(cb) {
  if (ρ == 1)
    b(ο, τ, α, ρ, ι);
  else
    ti_turn_left(ο, τ, α, ρ, ι, mc);
}
N(toti_pith) {
  if (ρ == 1 && ι == 1)
    ti_turn_left(ο, τ, α, ρ, ι, mb);
  else
    m(ο, τ, α, ρ, ι);
}
N(and);
N(go_Red);
N(M) { m(ο, τ, α, ρ, ι); }
W(one, 1, -1) {
  ο[α++] = (void *)1;
  M(ο, τ, α, ρ, ι);
}
W(plus, 1, 1) {
  long sum = 0;
  while (α)
    sum += (long)ο[--α];
  ο[α++] = (void *)sum;
  M(ο, τ, α, ρ, ι);
}
#include "stdio.h"
W(print, 1, 1) {
  long v = (long)ο[--α];
  printf("%ld\n", v);
  M(ο, τ, α, ρ, ι);
}
N(two) {
  void *tot[] = {Ta(cb, τ), T(one), T(one), T(plus), T(o)};
  *τ = toti_pith;
  τ[5] = tot + 5;
  toti_pith(ο, τ, α, ρ, ι);
}
N(four) {
  void *tot[] = {Ta(cb, τ), T(two), T(two), T(plus), T(o)};
  *τ = toti_pith;
  τ[5] = tot + 5;
  toti_pith(ο, τ, α, ρ, ι);
}
N(five) {
  void *tot[] = {Ta(cb, τ), T(plus), T(one), T(four), T(o)};
  *τ = toti_pith;
  τ[5] = tot + 5;
  toti_pith(ο, τ, α, ρ, ι);
}
void ti_init();
int main() {
  ti_init();
  void *ο[1024];
  long α = 0;
  void *text[] = {T(b), T(one), T(plus), T(one), T(one), T(one), T(and), T(print), T(o)};
  M(ο, text + 5, α, 3, 1);
}
