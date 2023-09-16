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
  long PC;                                                                     \
  long SC;                                                                     \
  long i;                                                                      \
  const char *sentences[7];                                                    \
  G(Purple) {                                                                  \
    char *ss[] = {__VA_ARGS__};                                                \
    PC = t;                                                                    \
    SC = sizeof(ss) / sizeof(*ss);                                             \
    i = 0;                                                                     \
    for (long j = 0; j < SC; j++)                                              \
      sentences[j] = ss[j];                                                    \
    Purple(SC, a, b, o, s);                                                    \
  }                                                                            \
  N(Olive_connect) { Green(t, a, b, o, s); }                                  \
  N(Navy_connect) { Blue(t, a, b, o, s); }                                     \
  N(switch_arm) {                                                              \
    o[--s] = (void *)t;                                                        \
    T(Red, Olive_connect, Navy_connect);                                       \
    T(Red, o[3], Red);                                                         \
    o[a++] = (void *)sentences[t];                                             \
    ((n_t *)o)[2](0, a, b, o, s);                                              \
  }                                                                            \
  G(Olive) {                                                                   \
    if (t == SC - 1)                                                           \
      Olive(i++ % PC, a, b, o, s);                                             \
    else /*Fuchsia*/                                                                      \
      switch_arm((t + 1) % SC, a, b, o, s);                                    \
  }                                                                            \
  G(Green) { switch_arm(0, a, b, o, s); }
