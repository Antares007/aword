#pragma once
// clang-format off
#include "aword.h"
#define R(Olive)                                                               \
  N(Olive      ) { asm("nop" : : "a"(t + a + b + (long)o + (long)s)); };       \
  N(Olive##_ray)
#define TI(Olive, Name, t, a, b, o, s, Cont)                                   \
    ((void(**)(void*))o)[1](&(void*[]){(void*)Olive,                           \
                                       (void*)Name,                            \
                                       (void*)t, (void*)a, (void*)b,           \
                                       (void*)o, (void*)s,                     \
                                       (void*)Cont});
#define G(Olive)                                                               \
  N(Olive##_nar) __attribute__((noinline));                                    \
  N(Olive##_tin) __attribute__((noinline));                                    \
  N(Olive##_tin) { TI(#Olive, __FILE__, t, a, b, o, s, Olive##_nar); }         \
  R(Olive) { Olive##_tin(t,a,b,o,s); }                                         \
  N(Olive##_nar)

#define Δ(Olive)                                                               \
  N(Olive##_ray) __attribute__((section(".text." #Olive "_ray")));             \
  N(Olive) __attribute__((section(".text." #Olive))) __attribute__((noinline));

Δ(Yellow);Δ(Purple); Δ(Red);   Δ(Green);Δ(Blue);
Δ(Olive); Δ(Fuchsia);Δ(Maroon);Δ(Lime); Δ(Navy);
#undef Δ
