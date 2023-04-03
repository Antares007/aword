#pragma once
// clang-format off
#define White(op)   δ op 1
#define Black(op)   δ op -1
#define Yellow(op)  ρ op 3
#define Red(op)     ρ op 2
#define Green(op)   ρ op 1
#define Blue(op)    ρ op 0

#define Ta(nar, var)  0, 0, 0, 0, 0, 0, 0, 0, nar, \
                      0, 0, 0, 0, 0, 0, 0, (void*)var,
#define T(nar)        0, 0, 0, 0, 0, 0, 0, 0, nar, \
                      0, 0, 0, 0, 0, 0, 0, #nar,
#define AW 8
#define B(...)                                                                 \
  (({                                                                          \
     void *text[] = {__VA_ARGS__};                                             \
     long i = sizeof(text) / sizeof(void *);                                   \
     while (i)                                                                 \
       ο[--α] = text[--i];                                                     \
   }),                                                                         \
   ο + α + AW)
#define N(argo) void argo(long α, void **ω, void**ο, long ρ, long δ, long σ)
#define M(ρ) m(α, ω, ο, ρ, δ, σ)
// clang-format on
typedef N((*t_t));
N(m);N(b);N(o);N(toti);N(not);N(and);N(or);N(orand);
