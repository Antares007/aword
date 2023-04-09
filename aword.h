#pragma once
#define W(name, r, d)                                                          \
  N(name##_pith);                                                              \
  N(name) {                                                                    \
    τ[+4] = go, τ[+3] = go, τ[+2] = go, τ[+1] = go;                            \
    τ[0] = aradani_pith;                                                       \
    τ[-1] = go, τ[-2] = go, τ[-3] = go, τ[-4] = go;                            \
    τ[(r + 1) * d] = name##_pith;                                              \
    aradani_pith(τ, ρ, δ);                                                     \
  }                                                                            \
  N(name##_pith)
#define N(arg) void arg(Args)
#define Args void **τ, long ρ, long δ
#define Ta(in, a) 0, 0, 0, 0, 0, in, 0, 0, 0, 0, (void *)a
#define T(ina) Ta(ina, #ina)

N(m);
N(b);
N(o);
