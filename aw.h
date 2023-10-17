#pragma once
// clang-format off
#include "aword.h"
#define R(Olive)                                                               \
  N(Olive      ) { asm("nop" : : "a"(t + a + b + (long)o + (long)s)); };       \
  N(Olive##_ray)
#define TI(Olive, Name, t, a, b, o, s, Angle)                                  \
//    ((void(**)(const char*,const char*,long,long,long,void**,const char*,long))o)[1](Olive,Name,t,a,b,o,s,Angle)
#define G(Olive)                                                               \
  N(Olive##_nar) __attribute__((noinline));                                    \
  N(Olive##_tin) __attribute__((noinline));                                    \
  N(Olive##_tin) { TI(#Olive, __FILE__, t, a, b, o, s, 0);                     \
                   Olive##_nar(t, a, b, o, s); }                               \
  R(Olive) { Olive##_tin(t,a,b,o,s); }                                         \
  N(Olive##_nar)

#define Δ(Olive)                                                               \
  N(Olive##_ray) __attribute__((section(".text." #Olive "_ray")));             \
  N(Olive) __attribute__((section(".text." #Olive))) __attribute__((noinline));

Δ(Yellow);Δ(Purple); Δ(Red);   Δ(Green);Δ(Blue);
Δ(Olive); Δ(Fuchsia);Δ(Maroon);Δ(Lime); Δ(Navy);
Δ(yellow);Δ(purple); Δ(red);   Δ(green);Δ(blue);
Δ(olive); Δ(fuchsia);Δ(maroon);Δ(lime); Δ(navy);
#undef Δ
