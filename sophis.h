#pragma once
#pragma GCC diagnostic ignored "-Wint-conversion"

#define NAMES                                                                  \
  X(halt)                                                                      \
  X(begin)                                                                     \
  X(name)                                                                      \
  X(nl)                                                                        \
  X(nop)                                                                       \
  X(print)                                                                     \
  X(put)                                                                       \
  X(tab)                                                                       \
  X(aword)                                                                     \
  X(tword)                                                                     \
  X(rword)                                                                     \
  X(dot)                                                                       \
  X(end)                                                                       \
  X(bword)                                                                     \
  X(cword)                                                                     \
  X(dword)  \
  X(NOT)    \
  X(AND)    \
  X(OR)

#define X(n) n,
enum Names { NAMES Names_Count };
#undef X

#define X(n) #n,
static const char *sopcode_names[] = {NAMES};
#undef X

#define Σ 8
#define OS o, β, α, ω, τ, σ, ρ, δ, ν
#define SC long *o, long **β, long **α, long**ω, long τ, long σ, long ρ, long δ, long ν

#define N(argo) void argo(SC)
#define S(argo) static N(argo)
typedef N((*n_t));

extern int printf(const char *__restrict __format, ...);
#define P printf("%s\n", __func__)

#define FIRSTR(a, ...) #a
#define R(β, ...)                                                                                            \
  (long[]){__func__, FIRSTR(__VA_ARGS__), sizeof((long[]){__VA_ARGS__}) / sizeof(long), β, __VA_ARGS__} + 4

#define οTomato(...)  ω = (long *[]){ω[0],ω[1],ω[2],R(ω,__VA_ARGS__)}
#define οGold(...)    ω = (long *[]){ω[0],ω[1],R(ω,__VA_ARGS__),ω[3]}
#define οTeal(...)    ω = (long *[]){ω[0],R(ω,__VA_ARGS__),ω[2],ω[3]}
#define οCyan(...)    ω = (long *[]){R(ω,__VA_ARGS__),ω[1],ω[2],ω[3]}

#define οRed(...)     β = (long *[]){β[0],β[1],β[2],R(β,__VA_ARGS__)}
#define οYellow(...)  β = (long *[]){β[0],β[1],R(β,__VA_ARGS__),β[3]}
#define οGreen(...)   β = (long *[]){β[0],R(β,__VA_ARGS__),β[2],β[3]}
#define οBlue(...)    β = (long *[]){R(β,__VA_ARGS__),β[1],β[2],β[3]}

#define οNavy(...)    α = (long *[]){R(α,__VA_ARGS__),α[1],α[2],α[3]}
#define οLime(...)    α = (long *[]){α[0],R(α,__VA_ARGS__),α[2],α[3]}
#define οOlive(...)   α = (long *[]){α[0],α[1],R(α,__VA_ARGS__),α[3]}
#define οMaroon(...)  α = (long *[]){α[0],α[1],α[2],R(α,__VA_ARGS__)}

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
#define is_a_book_of(...)                                                     \
  static n_t nars[Names_Count] = {__VA_ARGS__};                               \
  if (nars[o[τ]]) nars[o[τ]](OS);                                             \
  else printf("%s[%s] is not implemented!\n", __func__, sopcode_names[o[τ]]);

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
