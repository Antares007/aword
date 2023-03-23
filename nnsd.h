#pragma once
#include "aword.h"
// clang-format off
#define NNSD_T(name, i) {.q = i},               {.c = name},    {.q = 0},
#define NNSD_R(n, i)    {.f = -3.1416 / n * i}, {.c = rotate},  {.f = +3.1416 / n * i},
#define NNSD_ARM(name, i, n, a, ...) (text_t[]){NNSD_T(name, i) NNSD_R(n,a) __VA_ARGS__ T(o)} + 1,

#define NNSD35(...) NNSD_ARM(rm, 5, 4, +1, __VA_ARGS__) }
#define NNSD34(...) NNSD_ARM(bm, 4, 4, -1, __VA_ARGS__) NNSD35
#define NNSD33(...) NNSD_ARM(rm, 3, 4, +2, __VA_ARGS__) NNSD34
#define NNSD32(...) NNSD_ARM(lm, 2, 4, -2, __VA_ARGS__) NNSD33
#define NNSD31(...) NNSD_ARM(rm, 1, 4, +3, __VA_ARGS__) NNSD32
#define NNSD30(...) NNSD_ARM(lm, 0, 4, -3, __VA_ARGS__) NNSD31
#define NNSD3(name)                                                            \
  NNSDBody(name, 3) static text_t *name##_hands[3*2] = {NNSD30

#define NNSD23(...) NNSD_ARM(rm, 3, 3, +1, __VA_ARGS__) }
#define NNSD22(...) NNSD_ARM(bm, 2, 3, -1, __VA_ARGS__) NNSD23
#define NNSD21(...) NNSD_ARM(rm, 1, 3, +2, __VA_ARGS__) NNSD22
#define NNSD20(...) NNSD_ARM(lm, 0, 3, -2, __VA_ARGS__) NNSD21
#define NNSD2(name)                                                            \
  NNSDBody(name, 2) static text_t *name##_hands[2*2] = {NNSD20

#define NNSD02(...) NNSD_ARM(rm, 1, 2, +1, __VA_ARGS__) }
#define NNSD01(...) NNSD_ARM(bm, 0, 2, -1, __VA_ARGS__) NNSD02
#define NNSD(name)                                                            \
  NNSDBody(name, 1) static text_t *name##_hands[1*2] = {NNSD01
// clang-format on
static N(rm) {
  if (Green(==))
    White(=), X;
  else {
    text_t *nω = ο[--σ].t;
    ο[σ++].q = ω[-1].q;
    White(=), ω = nω, X;
  }
}
static N(lm) {
  if (Green(==))
    White(=), X;
  else
    White(=), ω = ο[--σ].t, X;
}
static N(bm) {
  if (Green(==))
    White(=), X;
  else {
    Black(=);
    --σ;
    ω = ο[--σ].t;
    X;
  }
}
#define NNSDBody(name, hands)                                                  \
  static text_t *name##_hands[hands * 2];                                      \
  N(name) {                                                                    \
    if (White(==)) {                                                           \
      if (Yellow(==))                                                          \
        Black(=), Green(=), X;                                                 \
      else {                                                                   \
        if (Green(==))                                                         \
          Yellow(=);                                                           \
        ο[σ++].t = ω;                                                          \
        ω = name##_hands[1], White(=), X;                                      \
      }                                                                        \
    } else if (Green(==)) {                                                    \
      White(=), X;                                                             \
    } else {                                                                   \
      long hand = ο[--σ].q;                                                    \
      ο[σ++].t = ω;                                                            \
      ο[σ++].t = name##_hands[hand + 2];                                       \
      ω = name##_hands[hand - 1], White(=), X;                                 \
    }                                                                          \
    (void)lm;                                                                  \
  }
