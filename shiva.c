#include "aword.h"
N(shiv_arm) {
  White(=);
  if (Yellow(==)) {
    t_t *shiva_or_right_arm = ο[--σ].t;
    W(shiva_or_right_arm), X;
  } else
    X;
}
N(last_arm) {
  if (Yellow(==)) {
    t_t *invalid_next_right_arm = ο[--σ].v;
    t_t *shiva = ο[--σ].t;
    long invalid_next_right_arm_index = ο[--σ].q;
    (void)invalid_next_right_arm, (void)invalid_next_right_arm_index;
    Black(=), W(shiva), X;
  } else
    White(=), X;
}

N(shiva) {
  if (White(==)) {
    if (Green(==)) {
      const long first_right_arm_index = 0;
      t_t *first_right_arm = ω[1].t[first_right_arm_index].t;
      ο[σ++].q = first_right_arm_index;
      ο[σ++].t = ω;
      Yellow(=), W(first_right_arm), X;
    } else {
      if (Yellow(==))
        Green(=);
      Black(=), X;
    }
  } else if (Yellow(==)) {
    long last_right_arm_index = ο[--σ].q;
    long next_right_arm_index = last_right_arm_index + 2;
    t_t *next_right_arm = ω[1].t[last_right_arm_index + 2].t;
    t_t *next_left_arm = ω[1].t[last_right_arm_index + 1].t;
    ο[σ++].q = next_right_arm_index;
    ο[σ++].t = ω;
    ο[σ++].t = next_right_arm;
    W(next_left_arm), White(=), X;
  } else {
    White(=), X;
  }
}
