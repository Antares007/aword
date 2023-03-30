#pragma once
#define N(argo) void argo(void **o, long a)
#define R(color)                                                               \
  N(color) __attribute__((section(".text." #color)));                          \
  N(color)
#define Ray(color)                                                             \
  N(color##ray) __attribute__((noinline));                                     \
  N(color) __attribute__((section(".text." #color)));                          \
  N(color) { color##ray(o, a); }                                               \
  N(color##ray)
#define S(color)                                                               \
  N(color)                                                                     \
  __attribute__((section(".text." #color))) __attribute__((noinline));         \
  N(color) { asm("nop" : : "a"(o + a)); }
// we dont link with other awords, so we can define linkable functions in header
S(Pink)
S(Olive) S(Maroon) S(Lime) S(Aqua) S(Blue) S(Green) S(Red) S(Yellow) S(Purple)
#undef S
void (*print)(char *, ...);
#define P print = o[0], print("S %s %s\n", __FILE__, __FUNCTION__),((void (**)(long))o)[1](200000)
