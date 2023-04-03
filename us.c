#include "awords.h"
N(term) {}
N(finalize);
N(restate);
N(fixerr);
N(print);
N(input);
N(orelse) {
  ω[-1] = B(), ω[+1] = B(T(finalize) T(or) T(restate) T(not ) T(fixerr));
}
N(S);
N(C) {
  ω[-1] = B(T(orelse)), ω[+1] = B(Ta(term, "α") T(S));
  ω[-2] = B(T(orelse)), ω[+2] = B(T(S) Ta(term, "ο"));
  toti(α, ω, ο, ρ, δ, σ);
}
N(S) {
  ω[-1] = B(T(orelse)), ω[+1] = B(Ta(term, "b"));
  ω[-2] = B(T(orelse)), ω[+2] = B(T(C) Ta(term, "α"));
  toti(α, ω, ο, ρ, δ, σ);
}
N(Show) {
  ω[-1] = B(T(print)), ω[+1] = B(Ta(input, "abao") T(C));
  ω[-2] = B(T(print)), ω[+2] = B(Ta(input, "baaa") T(S));
  toti(α, ω, ο, ρ, δ, σ);
}
