#pragma once
// clang-format off
#include "aword.h"
#define R(Olive)                                                               \
  N(Olive      ) { asm("nop" : : "a"(t + a + (long)b + (long)o + s)); };       \
  N(Olive##_ray)
#define G(Olive)                                                               \
  N(Olive##_nar) __attribute__((noinline));                                    \
  R(Olive) { Olive##_nar(t, a, b, o, s); }                                     \
  N(Olive##_nar)
#define Δ(Olive)                                                               \
  N(Olive##_ray) __attribute__((section(".text." #Olive "_ray")));             \
  N(Olive) __attribute__((section(".text." #Olive))) __attribute__((noinline));

Δ(Yellow);Δ(Purple); Δ(Red);   Δ(Green);Δ(Blue);
Δ(Olive); Δ(Fuchsia);Δ(Maroon);Δ(Lime); Δ(Navy);
#undef Δ
// clang-format on
#define Tword(...)                                                             \
  long SC;                                                                     \
  long arm;                                                                    \
  n_t atext[7];                                                                \
  G(Purple) { P;                                                                         \
    char *ss[] = {__VA_ARGS__};                                                \
    SC = sizeof(ss) / sizeof(*ss);                                             \
    arm = 0;                                                                   \
    for (long i = 0; i < SC; i++) {                                            \
      atext[i] = W(ss[i]);                                                     \
      (atext[i] + 16)(t, a, b, o, s);                                          \
    }                                                                          \
    Purple(t, a, b, o, s);                                                     \
  }                                                                            \
  N(Olive_connect) {                                                           \
    long narm = arm + t;                                                       \
    t = narm / SC;                                                             \
    arm = narm - t * SC;                                                       \
    Green(t, a, b, o, s);                                                      \
  }                                                                            \
  N(Navy_connect) {                                                            \
    Blue(t, a, b, o, s);                                                       \
  }                                                                            \
  G(Green) { P;                                                                   \
    o[--s] = Red;                                                              \
    o[--s] = Olive_connect;                                                    \
    o[--s] = Navy_connect;                                                     \
    atext[arm](t, a, b, o, s);                                                 \
  }
