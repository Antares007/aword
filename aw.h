#pragma once
#define N(argo) void argo(void **o, long a)
#define G(Olive)                                                               \
  N(Olive)                                                                     \
  __attribute__((section(".text." #Olive))) __attribute__((noinline));         \
  N(Olive) { asm("nop" : : "a"(o + a)); };                                     \
  N(Olive##_nar) __attribute__((noinline));                                    \
  N(Olive##_ray) __attribute__((section(".text." #Olive "_ray")));             \
  N(Olive##_ray) { Olive##_nar(o, a); }                                        \
  N(Olive##_nar)
#define P                                                                      \
  ((void (*)(const char *, ...))o[0])("%s %s\n", __FILE__, __FUNCTION__),      \
      ((void (*)(long))o[1])(200000)
