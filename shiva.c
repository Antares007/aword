#include "aword.h"
N(right_arm) {
  White(=);
  if (Yellow(==)) {
    t_t *shiva = ο[--σ].t;
    W(shiva), X;
  } else
    X;
}
N(left_arm) {
  White(=);
  if (Yellow(==)) {
    t_t *shiva = ο[--σ].t;
    long arm_index = ο[--σ].q;
    long right_arm_index = arm_index + 1;
    ο[σ++].q = right_arm_index;
    ο[σ++].v = shiva;
    t_t *right_arm = shiva[1].t[right_arm_index].t;
    W(right_arm), X;
  } else
    X;
}
N(last_arm) {
  if (Yellow(==)) {
    t_t *shiva = ο[--σ].t;
    long invalid_arm_index = ο[--σ].q;
    (void)invalid_arm_index;
    Black(=), W(shiva), X;
  } else
    White(=), X;
}
N(shiva) {
  if (White(==)) {
    if (Green(==)) {
      const long right_arm_index = 0;
      t_t *right_arm = ω[1].t[right_arm_index].t;
      ο[σ++].q = right_arm_index;
      ο[σ++].t = ω;
      Yellow(=), W(right_arm), X;
    } else {
      if (Yellow(==))
        Green(=);
      Black(=), X;
    }
  } else if (Yellow(==)) {
    long right_arm_index = ο[--σ].q;
    long left_arm_index = right_arm_index + 1;
    t_t *left_arm = ω[1].t[left_arm_index].t;
    ο[σ++].q = left_arm_index;
    ο[σ++].t = ω;
    W(left_arm), White(=), X;
  } else {
    White(=), X;
  }
}
