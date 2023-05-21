#pragma once
// clang-format off
#define N(argo) void   argo(void**ο, long σ, long α, long ρ)
typedef         void (*n_t)(void**ο, long σ, long α, long ρ);
typedef          n_t (*c_t)(const char **t, long s);
#define R(Olive)                                                               \
  N(Olive      ) { asm("nop" : : "a"(ο + σ + α + ρ)); };                       \
  N(Olive##_ray)
#define G(Olive)                                                               \
  N(Olive##_nar) __attribute__((noinline));                                    \
  R(Olive) { Olive##_nar(ο, σ, α, ρ); }                                        \
  N(Olive##_nar)
#define Δ(Olive)                                                               \
  N(Olive##_ray) __attribute__((section(".text." #Olive "_ray")));             \
  N(Olive) __attribute__((section(".text." #Olive))) __attribute__((noinline));

Δ(Yellow);Δ(Purple); Δ(Red);   Δ(Green);Δ(Blue);
Δ(Olive); Δ(Fuchsia);Δ(Maroon);Δ(Lime); Δ(Navy);
#undef Δ
#define P \
 ((void (*)(const char *, ...))ο[0])("%s %s\n", __FILE__, __FUNCTION__), \
 ((void (*)(long))ο[1])(200000)
