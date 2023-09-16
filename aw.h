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
  const char *sentences[7];                                                    \
  N(dot_Yellow) { (((n_t *)o)[a - 1] + 00)(0, a - 1, b, o, s); }               \
  N(dot_Purple) { (((n_t *)o)[a - 1] + 16)(0, a - 1, b, o, s); }               \
  N(connect_Fuchsia) {                                                         \
    Fuchsia(t, a, b, o, s);                                                    \
  }                                                                            \
  N(connect_Olive) {                                                           \
    if (SC == arm + 1) {                                                       \
      arm = 0;                                                                 \
      Yellow(t, a, b, o, s);                                                   \
    } else {                                                                   \
      arm++;                                                                   \
      Purple(t, a, b, o, s);                                                  \
    }                                                                          \
  }                                                                            \
  N(connect_Arm) {                                                             \
    n_t dot = o[--a];                                                          \
    o[--s] = connect_Fuchsia;                                                  \
    o[--s] = connect_Olive;                                                    \
    T(0, dot, 0);                                                              \
    o[a++] = sentences[arm];                                                   \
    ((n_t *)o)[2](t, a, b, o, s);                                              \
  }                                                                            \
  G(Yellow) {                                                                  \
    o[a++] = dot_Yellow;                                                       \
    connect_Arm(t, a, b, o, s);                                                \
  }                                                                            \
  G(Purple) {                                                                  \
    if (t == 1) {                                                              \
      const char *ss[] = {__VA_ARGS__};                                        \
      SC = sizeof(ss) / sizeof(*ss);                                           \
      arm = 0;                                                                 \
      for (long i = 0; i < SC; i++)                                            \
        sentences[i] = ss[i];                                                  \
      Purple(t, a, sentences, o, s);                                           \
    } else {                                                                   \
      o[a++] = dot_Purple;                                                     \
      connect_Arm(t, a, b, o, s);                                              \
    }                                                                          \
  }
/*

Yellow    0   Purple    0   Purple
Yellow    1   Yellow    0   Purple
Yellow    0   Purple    1   Purple
Yellow    1   Yellow    1   Yellow
          0             0


*/
