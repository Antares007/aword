#include "awords.h"
N(term) {}
N(finalize);
N(restate);
N(fixerr);
N(print);
N(input);
N(orelse) {
  ο[ω + 1].q = B();
  ο[ω - 1].q = B(T(finalize) T(or) T(restate) T(not ) T(fixerr));
}
N(S);
N(C) {
  ο[ω - 1].q = B(Ta(term, "α") T(S)); ο[ω + 1].q = B(T(orelse));
  ο[ω - 2].q = B(T(S) Ta(term, "ο")); ο[ω + 2].q = B(T(orelse));
  toti(α, ω, ο, ρ, δ, σ);
}
N(S) {
  ο[ω - 1].q = B(Ta(term, "b"));      ο[ω + 1].q = B(T(orelse));
  ο[ω - 2].q = B(T(C) Ta(term, "α")); ο[ω + 2].q = B(T(orelse));
  toti(α, ω, ο, ρ, δ, σ);
}
N(Show) {
  ο[ω - 1].q = B(Ta(input, "abao") T(C)); ο[ω + 1].q = B(T(print));
  ο[ω - 2].q = B(Ta(input, "baaa") T(S)); ο[ω + 2].q = B(T(print));
  toti(α, ω, ο, ρ, δ, σ);
}
