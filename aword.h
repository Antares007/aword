#pragma once
#define W(name, r, d)                                                          \
  N(name##_pith);                                                              \
  N(name) {                                                                    \
    τ[+4] = go, τ[+3] = go, τ[+2] = go, τ[+1] = go;                            \
    τ[0] = aradani_pith;                                                       \
    τ[-1] = go, τ[-2] = go, τ[-3] = go, τ[-4] = go;                            \
    τ[(r + 1) * d] = name##_pith;                                              \
    aradani_pith(τ, ρ, ι);                                                     \
  }                                                                            \
  N(name##_pith)
#define N(arg) void arg(Args)
#define Args void**ο, void **τ, long α, long ρ, long ι
#define Ta(in, a) 0, 0, 0, 0, 0, in, 0, 0, 0, #in, (void *)a
#define T(ina) Ta(ina, 0)

N(m);
N(b);
N(o);
