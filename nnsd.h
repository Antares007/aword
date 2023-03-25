#pragma once
#include "aword.h"
// clang-format off
#define NNSD_T(name, i) {.q = i},               {.c = name},    {.q = 0},
#define NNSD_R(n, i)    {.f = -3.1416 / n * i}, {.c = rotate},  {.f = +3.1416 / n * i}, \
                        {.q = 0},               {.c = nnsd_arm},{.q = 488},
#define NNSD_ARM(name, i, n, a, ...) (text_t[]){ \
    NNSD_T(name, i) NNSD_R(n,a) __VA_ARGS__ T(o)} + 1,

#define NNSD47(...) NNSD_ARM(rm, 7, 5, +1, __VA_ARGS__) }
#define NNSD46(...) NNSD_ARM(bm, 6, 5, -1, __VA_ARGS__) NNSD47
#define NNSD45(...) NNSD_ARM(rm, 5, 5, +2, __VA_ARGS__) NNSD46
#define NNSD44(...) NNSD_ARM(lm, 4, 5, -2, __VA_ARGS__) NNSD45
#define NNSD43(...) NNSD_ARM(rm, 3, 5, +3, __VA_ARGS__) NNSD44
#define NNSD42(...) NNSD_ARM(lm, 2, 5, -3, __VA_ARGS__) NNSD43
#define NNSD41(...) NNSD_ARM(rm, 1, 5, +4, __VA_ARGS__) NNSD42
#define NNSD40(...) NNSD_ARM(lm, 0, 5, -4, __VA_ARGS__) NNSD41
#define NNSD4(name)                                                            \
  NNSDBody(name, 4) static text_t *name##_hands[4*2] = {NNSD40

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
/* right arm will pop Shiva from stack,
   which was pushed there by Shiva when flow camein to her from above, and
   he will push his own index and will go down on shiva. */
static N(rm) {
  long index = ω[-1].q;
  if (Yellow(==)) White(=), ω = ο[--σ].t, ο[σ++].q = index, X;
  else            White(=), X;
}
/* left arm will pop Right arm from
  stack which was pushed there by shiva when flow was going up. */
static N(lm) {
  if (Yellow(==)) White(=), ω = ο[--σ].t, X;
  else            White(=), X;
}
/* last left arm will drop right arm from stack
   then will pop Shiva from the stack and will go up on Shiva */
static N(bm) {
  if (Yellow(==)) Black(=), --σ, ω = ο[--σ].t, X;
  else            White(=), X;
}
#define NNSDBody(name, hands)                                                  \
  static text_t *name##_hands[hands * 2];                                      \
  N(name) {                                                                    \
    if(ο[σ-1].t == ω && ω[-2].q == 488) {                                      \
      return (void)printf("found left recursion %lx\n", ω[-2].q);              \
    } else if (White(==)) {                                                    \
      if (Green(==)) {                                                         \
        Yellow(=);                                                             \
        ο[σ++].t = ω;                                                          \
        ω = name##_hands[1], White(=), X;                                      \
      } else {                                                                 \
        if (Yellow(==))                                                        \
          Green(=);                                                            \
        Black(=), X;                                                           \
      }                                                                        \
    } else if (Yellow(==)) {                                                   \
      long hand = ο[--σ].q;                                                    \
      ο[σ++].t = ω;                                                            \
      ο[σ++].t = name##_hands[hand + 2];                                       \
      ω = name##_hands[hand - 1], White(=), X;                                 \
    } else                                                                     \
      White(=), X;                                                             \
    (void)lm;                                                                  \
  }
