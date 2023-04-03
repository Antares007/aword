#include "awords.h"
N(m) { ((t_t *)ω)[δ * (2 * AW + 1)](α, ω + δ * (2 * AW + 1), ο, ρ, δ, σ); }
N(b) {
  if (Green(==))
    m(α, ω, ο, ρ, White(=), σ);
  else
    m(α, ω[-1], ο, ρ, (long)ω[+1], σ);
}
N(o) {
  m(α, ω, ο, Yellow(==) ? Green(=) : Green(==) ? Yellow(=) : ρ, Black(=), σ);
}
static N(toti_heart) {
  if (White(==)) {
    if (Yellow(==)) {
      m(α, ω, ο, Green(=), Black(=), σ);
    } else {
      long arm_index = (long)ω[+AW];
      void **left_arm = ω[-arm_index];
      m(α, left_arm, ο, (Green(==)) ? Yellow(=) : ρ, δ, σ);
    }
  } else if (Green(==)) {
    m(α, ω, ο, ρ, White(=), σ);
  } else {
    long arm_count = (long)ω[-AW];
    long arm_index = (long)ω[+AW];
    ω[+AW] = (void *)(1 + arm_index % arm_count);
    void **right_arm = ω[+arm_index];
    m(α, right_arm, ο, ρ, White(=), σ);
  }
}
N(toti) {
  long arm_index = 1;
  for (; arm_index < AW && ω[arm_index]; arm_index++) {
    void **left_arm = ω[-arm_index];
    left_arm[-1] = ω, left_arm[+1] = (void *)1;
    void **right_arm = ω[+arm_index];
    right_arm[-1] = ω, right_arm[+1] = (void *)-1;
  }
  ω[+AW] = (void *)1;
  ω[-AW] = (void *)(arm_index - 1);
  *ω = toti_heart;
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
  M(ρ);
}
N(and) {
  if (White(==)) {
    if (Yellow(==))
      Green(=), Black(=);
    else if (Green(==))
      Yellow(=);
  } else if (Green(==))
    White(=);
  M(ρ);
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
  M(ρ);
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
  M(ρ);
}
