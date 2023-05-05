#pragma once
// clang-format off
#define N(argo) void   argo(void**o, long a, long s)
typedef         void (*n_t)(void**o, long a, long s);
typedef          n_t (*c_t)(const char *text);

#define G(Olive)                                                               \
  N(Olive##_nar) __attribute__((noinline));                                    \
  N(Olive      ) { asm("nop" : : "a"(o + a + s)); };                           \
  N(Olive##_ray) __attribute__((section(".text." #Olive "_ray")));             \
  N(Olive##_ray) { Olive##_nar(o, a, s); }                                     \
  N(Olive##_nar)
#define Δ(Olive) N(Olive) __attribute__((section(".text." #Olive)))            \
                          __attribute__((noinline));
Δ(Yellow);Δ(Purple); Δ(Red);   Δ(Green);Δ(Blue);
Δ(Olive); Δ(Fuchsia);Δ(Maroon);Δ(Lime); Δ(Navy);
#undef Δ
#define P                                                                      \
  ((void (*)(const char *, ...))o[0])("%s %s\n", __FILE__, __FUNCTION__),      \
      ((void (*)(long))o[1])(200000)
