#include "awords.h"
// N(term) {}
// N(finalize);
// N(restate);
// N(fixerr);
// N(print);
// N(input);
// N(orelse) {
//   ο[ω + 1].q = B();
//   ο[ω - 1].q = B(T(finalize) T(or) T(restate) T(not ) T(fixerr));
// }
// N(S);
// N(C) {
//   ο[ω - 1].q = B(Ta(term, "α") T(S)); ο[ω + 1].q = B(T(orelse));
//   ο[ω - 2].q = B(T(S) Ta(term, "ο")); ο[ω + 2].q = B(T(orelse));
//   toti(α, ω, ο, ρ, δ, σ);
// }
// N(S) {
//   ο[ω - 1].q = B(Ta(term, "b"));      ο[ω + 1].q = B(T(orelse));
//   ο[ω - 2].q = B(T(C) Ta(term, "α")); ο[ω + 2].q = B(T(orelse));
//   toti(α, ω, ο, ρ, δ, σ);
// }
// N(Show) {
//   ο[ω - 1].q = B(Ta(input, "abao") T(C)); ο[ω + 1].q = B(T(print));
//   ο[ω - 2].q = B(Ta(input, "baaa") T(S)); ο[ω + 2].q = B(T(print));
//   toti(α, ω, ο, ρ, δ, σ);
// }
#include <stdio.h>
#include <unistd.h>
N(print) {
  if (ρ == 3 && δ == 1)
    printf("%s", ο[ω + AW].cs), usleep(20000);
  m(α, ω, ο, ρ, δ, σ);
}
N(sword2) {
  D(B(T(b) Ta(print, "(") T(o)), //
    B(T(b) Ta(print, ")") T(o)));
  D(B(T(b) Ta(print, "[") T(o)), //
    B(T(b) Ta(print, "]") T(o)));
  toti(α, ω, ο, ρ, δ, σ);
}
N(sword1) {
  D(B(T(b) Ta(print, "{") T(o)), //
    B(T(b) Ta(print, "}") T(o)));
  toti(α, ω, ο, ρ, δ, σ);
}
int main() {
  long α, ω;
  text_t ο[α = 1024];
  long ρ = 3, δ = 1, σ = 0;
  ω = B(T(b)                 //
        Ta(print, "\nS -> ") //
        T(sword1)            //
        Ta(print, "M1")      //
        T(sword2)            //
        Ta(print, "M2")      //
        T(o));
  ο[ω - 1].q = ω;
  ο[ω + 1].q = 1;
  BConnect(ω, ω, 1);
  m(α, ω, ο, ρ, δ, σ);
}
