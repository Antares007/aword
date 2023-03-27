#pragma once
#define word long a, long w, void **o, long r, long d
#define m(a, w, o, r, d)                                                       \
  ((void (**)(long, long, void *, long, long))o)[w + d](a, w + d, o, r, d)
#define Ta(aw, _a) o[--a] = (void *)_a, o[--a] = aw, o[--a] = 0,
#define T(aw) Ta(aw, 0)
#define LastArm o[--a] = (void *)-3, o[L = --a] = left_arm, o[--a] = (void *)w
#define LeftArm o[--a] = (void *)3, o[L = --a] = left_arm, o[--a] = (void *)R
#define RightArm o[--a] = (void *)L, o[R = --a] = right_arm, o[--a] = (void *)w
#define S(name, ...)                                                           \
  void name(long a, long w, void **o, long r, long d) {                        \
    long R, L;                                                                 \
    __VA_ARGS__                                                                \
    o[w - 1] = (void *)R;                                                      \
    o[w] = s;                                                                  \
    s(a, w, o, r, d);                                                          \
  }
void s(word);
void b(word);
void left_arm(word);
void right_arm(word);
static void dot(word) { m(a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, 3); }
