#pragma once
#define N(argo) void argo(void **o, long a)
#define G(Olive)                                                               \
  N(Olive##_nar) __attribute__((noinline));                                    \
  N(Olive) { asm("nop" : : "a"(o + a)); };                                     \
  N(Olive##_ray) __attribute__((section(".text." #Olive "_ray")));             \
  N(Olive##_ray) { Olive##_nar(o, a); }                                        \
  N(Olive##_nar)
#define Δ(Olive)                                                               \
  N(Olive) __attribute__((section(".text." #Olive))) __attribute__((noinline));
Δ(Yellow);
Δ(Purple);
Δ(Red);
Δ(Green);
Δ(Blue);
Δ(Navy);
Δ(Lime);
Δ(Maroon);
Δ(Fuchsia);
Δ(Olive);
#undef Δ
typedef void (*n_t)(void**o, long a);
#define P                                                                      \
  ((void (*)(const char *, ...))o[0])("%s %s\n", __FILE__, __FUNCTION__),      \
      ((void (*)(long))o[1])(200000)
