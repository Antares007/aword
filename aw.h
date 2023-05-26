#pragma once
// clang-format off
#define N(argo) void   argo(long a, void**o, long s)
typedef         void (*n_t)(long a, void**o, long s);
#define R(Olive)                                                               \
  N(Olive      ) { asm("nop" : : "a"(o + s + a)); };                           \
  N(Olive##_ray)
#define G(Olive)                                                               \
  N(Olive##_nar) __attribute__((noinline));                                    \
  R(Olive) { Olive##_nar(a, o, s); }                                           \
  N(Olive##_nar)
#define Δ(Olive)                                                               \
  N(Olive##_ray) __attribute__((section(".text." #Olive "_ray")));             \
  N(Olive) __attribute__((section(".text." #Olive))) __attribute__((noinline));

Δ(Yellow);Δ(Purple); Δ(Red);   Δ(Green);Δ(Blue);
Δ(Olive); Δ(Fuchsia);Δ(Maroon);Δ(Lime); Δ(Navy);
#undef Δ
#define P                                                                \
 ((void (*)(const char *, ...))o[0])("%s %s\n", __FILE__, __FUNCTION__), \
 ((void (*)(long))o[1])(200000)
