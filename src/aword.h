#pragma once
// clang-format off
#define aword long a, long w, void **o, long r, long d, long s
#define Tab(aw, _a, _b)                                                        \
  o[a++] = (void *)(_a), o[a++] = (aw), o[a++] = (void *)(_b),
#define Ta(aw, _a) Tab(aw, _a, #aw)
#define T(aw) Ta(aw, 0)
#define White(op) (d op +3)
#define Black(op) (d op -3)
#define Yellow(op) (r op 3)
#define Red(op) (r op 2)
#define Green(op) (r op 1)
#define Blue(op) (r op 0)
void m(aword);
void b(aword);
void dot(aword);
typedef void (*aword_t)(aword);

