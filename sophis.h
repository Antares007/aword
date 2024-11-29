#pragma once
#pragma GCC diagnostic ignored "-Wint-conversion"

#define Σ 8
#define OS ο, β, α, ω, τ, σ, ρ, δ, ν
#define SC long *ο, long **β, long **α, long**ω, long τ, long σ, long ρ, long δ, long ν

#define N(argo) void argo(SC)
#define S(argo) static N(argo)
typedef N((*n_t));

extern int printf(const char *__restrict __format, ...);
#define P printf("%s\n", __func__)

N(sdb);

N(Red);       N(Red_Red);       N(Red_Green);       N(Red_Blue);        N(Red_aradani);
N(Yellow);
N(Green);
N(Blue);

N(Maroon);
N(Olive);
N(Lime);
N(Navy);

N(IndianRed); N(IndianRed_Red); N(IndianRed_Green); N(IndianRed_Blue);  N(IndianRed_aradani);
N(Gold);
N(Teal);
N(Cyan);


