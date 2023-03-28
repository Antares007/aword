#pragma once
#include "aword.h"
#define LastArm o[--a] = (void *)-3, o[L = --a] = left_arm, o[--a] = (void *)w
#define LeftArm o[--a] = (void *)3, o[L = --a] = left_arm, o[--a] = (void *)R
#define RightArm o[--a] = (void *)L, o[R = --a] = right_arm, o[--a] = (void *)w
#define S(name, ...)                                                           \
  void name(long a, long w, void **o, long r, long d) {                        \
    long R, L;                                                                 \
    __VA_ARGS__                                                                \
    o[w - 1] = (void *)R;                                                      \
    o[w] = s;                                                                  \
    s(a, w, o, r, d);                                                          \
  }
void left_arm(word);
void right_arm(word);
void s(word);
