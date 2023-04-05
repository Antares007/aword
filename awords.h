#pragma once
// clang-format off
#ifndef bWords
#define OP(a, op, b) a.tin op - (b)
#define Push(s) --s.tin
#define Pull(s) s.tin++
#else
#define OP(a, op, b) a.tin op + (b)
#define Push(s) s.tin++
#define Pull(s) --s.tin
#endif
#define AW 8

#define D(n, ...)                                         \
  ({ nar_t arms[][20][2] = {__VA_ARGS__};                 \
    ο[OP(ω, +, AW - 1)].q = sizeof(arms) / sizeof(*arms); \
    ο[OP(ω, +, AW)].v = arms; })
// first Β is unicode greek Beta
#define Β(...) {__VA_ARGS__, o}}
#define B(...) {{__VA_ARGS__, o}, Β

#define T(ina, ...) ο[Push(α)].q=0, \
                    ο[Push(α)].q=0,ο[Push(α)].q=0,ο[Push(α)].q=0, \
                    ο[Push(α)].q=0,ο[Push(α)].q=0,ο[Push(α)].q=0,ο[Push(α)].q=0, \
                    ο[__VA_ARGS__ Push(α)].v=ina, \
                    ο[Push(α)].q=0,ο[Push(α)].q=0,ο[Push(α)].q=0,ο[Push(α)].q=0, \
                    ο[Push(α)].q=0,ο[Push(α)].q=0,ο[Push(α)].q=0, \
                    ο[Push(α)].q=0
#define N(argo) void argo(tin_v α, tin_v ω, struct txt_t *ο, ray_v ρ, dir_v δ, tin_v σ)
typedef struct ray_v { long ray; } ray_v;
typedef struct tin_v { long tin; } tin_v;
typedef struct dir_v { long dir; } dir_v;
typedef struct txt_t {
  union { long q; void *v; const char *cs; struct txt_t *t; tin_v w; N((*go)); };
} txt_t;
typedef N((*nar_t));
#define White   (dir_v){+1}
#define Black   (dir_v){-1}
#define Yellow  (ray_v){3}
#define Red     (ray_v){2}
#define Green   (ray_v){1}
#define Blue    (ray_v){0}
