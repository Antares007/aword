#include "awords.h"
#include "aword_colors.h"
N(m) { ω = ω OP(+)(AW + 1 + AW) * δ, ο[ω].go(α, ω, ο, ρ, δ, σ); }
N(b) {
  if (Green(==))
    m(α, ω, ο, ρ, White, σ);
  else
    m(α, ο[ω OP(-) 1].q, ο, ρ, ο[ω OP(+) 1].q, σ);
}
N(o) {
  m(α, ω, ο, Yellow(==) ? Green(=) : Green(==) ? Yellow(=) : ρ, Black(=), σ);
}
static N(toti_heart) {
  if (White(==)) {
    if (Yellow(==)) {
      m(α, ω, ο, Green(=), Black(=), σ);
    } else {
      long i = ο[ω OP(-) AW].q;
      long ωl = ο[ω OP(-) i].q;
      m(α, ωl, ο, (Green(==)) ? Yellow(=) : ρ, δ, σ);
    }
  } else if (Green(==)) {
    m(α, ω, ο, ρ, White(=), σ);
  } else {
    long arms = ο[ω OP(+) AW].q;
    long i = ο[ω OP(-) AW].q;
    ο[ω OP(-) AW].q = (1 + i % arms);
    long ωr = ο[ω OP(+) i].q;
    m(α, ωr, ο, ρ, White(=), σ);
  }
}
N(toti) {
  long arms = ο[ω OP(+) AW].q;
  for (long i = 1; i < arms + 1; i++) {
    long ωl = ο[ω OP(-) i].q, ωr = ο[ω OP(+) i].q;
    BConnect(ωl, ω, 1);
    if (i == arms)
      BConnect(ωr, ω, -1);
    else {
      long ωlnext = ο[ω OP(-)(i + 1)].q;
      BConnect(ωr, ωlnext, 1);
    }
  }
  ο[ω OP(-) AW].q = 1;
  ο[ω].v = toti_heart;
  toti_heart(α, ω, ο, ρ, δ, σ);
}
