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

#define FIRSTR(a, ...) #a
#define R(β, ...)                                                                                            \
  (long[]){__func__, FIRSTR(__VA_ARGS__), sizeof((long[]){__VA_ARGS__}) / sizeof(long), β, __VA_ARGS__} + 4

#define οb3(r, ...)   r = (long *[]){r[0],r[1],r[2],R(r,__VA_ARGS__)}
#define οb2(r, ...)   r = (long *[]){r[0],r[1],R(r,__VA_ARGS__),r[3]}
#define οb1(r, ...)   r = (long *[]){r[0],R(r,__VA_ARGS__),r[2],r[3]}
#define οb0(r, ...)   r = (long *[]){R(r,__VA_ARGS__),r[1],r[2],r[3]}
#define οRed(...)     οb3(β, __VA_ARGS__)
#define οYellow(...)  οb2(β, __VA_ARGS__)
#define οGreen(...)   οb1(β, __VA_ARGS__)
#define οBlue(...)    οb0(β, __VA_ARGS__)
#define οMaroon(...)  οb3(α, __VA_ARGS__)
#define οOlive(...)   οb2(α, __VA_ARGS__)
#define οLime(...)    οb1(α, __VA_ARGS__)
#define οNavy(...)    οb0(α, __VA_ARGS__)
#define οTomato(...)  οb3(ω, __VA_ARGS__)
#define οGold(...)    οb2(ω, __VA_ARGS__)
#define οTeal(...)    οb1(ω, __VA_ARGS__)
#define οCyan(...)    οb0(ω, __VA_ARGS__)
#define βRed    β[3]
#define βYellow β[2]
#define βGreen  β[1]
#define βBlue   β[0]
#define αMaroon α[3]
#define αOlive  α[2]
#define αLime   α[1]
#define αNavy   α[0]
#define ωTomato ω[3]
#define ωGold   ω[2]
#define ωTeal   ω[1]
#define ωCyan   ω[0]

N(sdb);

#define Protos(Name)  \
  N(Name);            \
  N(Name##_Red);      \
  N(Name##_Green);    \
  N(Name##_Blue);     \
  N(Name##_NAO)
Protos(Red);
Protos(Yellow);
Protos(Green);
Protos(Blue);
Protos(Maroon);
Protos(Olive);
Protos(Lime);
Protos(Navy);
Protos(Tomato);
Protos(Gold);
Protos(Teal);
Protos(Cyan);
#undef Protos
