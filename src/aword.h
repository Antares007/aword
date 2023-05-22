#pragma once
// clang-format off
#define aword long a, long w, void **o, long r, long d, long s
#define Tab(aw, _a, _b)                                                        \
  o[--a] = (void *)(_a), o[--a] = (aw), o[--a] = (void *)(_b),
#define Ta(aw, _a) Tab(aw, _a, #aw)
#define T(aw) Ta(aw, 0)
#define White(op) (d op -3)
#define Black(op) (d op 3)
#define Yellow(op) (r op 3)
#define Red(op) (r op 2)
#define Green(op) (r op 1)
#define Blue(op) (r op 0)
void m(aword);
void b(aword);
void dot(aword);

#define LastArm   o[--a] = (void *)-3,  o[L = --a] = left_arm,   o[--a] = (void *)w
#define LeftArm   o[--a] = (void *) 3,  o[L = --a] = left_arm,   o[--a] = (void *)R
#define RightArm  o[--a] = (void *) L,  o[R = --a] = right_arm,  o[--a] = (void *)w
#define S(name, ...)                                                           \
  void name(aword) {                                                           \
    long R, L;                                                                 \
    __VA_ARGS__                                                                \
    o[w - 1] = (void *)R;                                                      \
    o[w] = shiv;                                                               \
    shiv(a, w, o, r, d, s);                                                    \
  }
void left_arm(aword);
void right_arm(aword);
void shiv(aword);
