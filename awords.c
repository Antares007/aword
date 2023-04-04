#include "awords.h"
#include "aword_colors.h"
N(m) { ω += (AW + 1 + AW) * δ, ο[ω].go(α, ω, ο, ρ, δ, σ); }
N(b) {
  if (Green(==))
    m(α, ω, ο, ρ, White(=), σ);
  else
    m(α, ο[ω - 1].q, ο, ρ, ο[ω + 1].q, σ);
}
N(o) {
  m(α, ω, ο, Yellow(==) ? Green(=) : Green(==) ? Yellow(=) : ρ, Black(=), σ);
}
static N(toti_heart) {
  if (White(==)) {
    if (Yellow(==)) {
      m(α, ω, ο, Green(=), Black(=), σ);
    } else {
      long arm_index = ο[ω + AW].q;
      long left_arm = ο[ω - arm_index].q;
      m(α, left_arm, ο, (Green(==)) ? Yellow(=) : ρ, δ, σ);
    }
  } else if (Green(==)) {
    m(α, ω, ο, ρ, White(=), σ);
  } else {
    long arm_count = ο[ω - AW].q;
    long arm_index = ο[ω + AW].q;
    ο[ω + AW].q = (1 + arm_index % arm_count);
    long right_arm = ο[ω + arm_index].q;
    m(α, right_arm, ο, ρ, White(=), σ);
  }
}
N(toti) {
  long arm_index = 1;
  for (; arm_index < AW && ο[ω + arm_index].q; arm_index++) {
    long left_arm = ο[ω - arm_index].q;
    ο[left_arm - 1].q = ω, ο[left_arm + 1].q = 1;
    long right_arm = ο[ω + arm_index].q;
    ο[right_arm - 1].q = ω, ο[right_arm + 1].q = -1;
  }
  ο[ω + AW].q = 1;
  ο[ω - AW].q = arm_index - 1;
  ο[ω].v = toti_heart;
  toti_heart(α, ω, ο, ρ, δ, σ);
}
N(not ) {
  if (White(==)) {
    if (Yellow(==))
      Green(=), Black(=);
    else if (Green(==))
      Yellow(=), Black(=);
    else if (Red(==))
      Yellow(=);
  } else if (Green(==))
    White(=);
  m(α, ω, ο, ρ, δ, σ);
}
N(and) {
  if (White(==)) {
    if (Yellow(==))
      Green(=), Black(=);
    else if (Green(==))
      Yellow(=);
  } else if (Green(==))
    White(=);
  m(α, ω, ο, ρ, δ, σ);
}
N(orand) {
  if (White(==)) {
    if (Yellow(==))
      Green(=), Black(=);
    else if (Green(==))
      Yellow(=);
    else if (Blue(==))
      Yellow(=);
  } else if (Green(==))
    White(=);
  m(α, ω, ο, ρ, δ, σ);
}
N(or) {
  if (White(==)) {
    if (Yellow(==))
      Green(=), Black(=);
    else if (Green(==))
      Yellow(=), Black(=);
    else if (Blue(==))
      Yellow(=);
  } else if (Green(==))
    White(=);
  m(α, ω, ο, ρ, δ, σ);
}
