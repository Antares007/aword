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
  X(tword)                                                                     \
  X(sword)                                                                     \
  X(dot)                                                                       \
  X(end)

#define X(n) n,
enum Names { NAMES Names_Count };
#undef X

#define X(n) #n,
static const char *sopcode_names[] = {NAMES};
#undef X

#define Σ 8
#define OS o, β, α, τ, σ, ρ, δ, ν
#define N(argo)                                                                \
  void argo(long *o, long **β, long **α, long τ, long σ, long ρ, long δ, long ν)
#define S(argo) static N(argo)
typedef N((*n_t));

extern int printf(const char *__restrict __format, ...);
#define P printf("%s\n", __func__)

#define FIRSTR(a, ...) #a
#define R(β, ...)                                                              \
  (long[]){__func__, FIRSTR(__VA_ARGS__), sizeof((long[]){__VA_ARGS__}) / sizeof(long), β, __VA_ARGS__} + 4
#define oBR(β, ρ, ...) ({ long r = R(β, __VA_ARGS__); β = (long *[]){β[0],β[1],β[2],β[3]}, β[ρ] = r; })
#define oB(ρ, ...) oBR(β, ρ, __VA_ARGS__)
#define oA(ρ, ...) oBR(α, ρ, __VA_ARGS__)
#define ρRed    ((ρ + 3) % 4)
#define ρYellow ((ρ + 2) % 4)
#define ρGreen  ((ρ + 1) % 4)
#define ρBlue   ((ρ + 0) % 4)

#define οPeek(β, ρ)   ((long**)β[ρ][-1])

#define is_a_book_of(...)                                                      \
  static n_t nars[Names_Count] = {__VA_ARGS__};                                \
  if (nars[o[τ]]) nars[o[τ]](OS);                                              \
  else printf("%s[%s] is not implemented!\n", __func__, sopcode_names[o[τ]]);

N(Yellow);
N(Yellow_G1);
N(Yellow_G2);
N(Yellow_Got);
N(Yellow_God);
N(Yellow_Gor);
N(Yellow_NAO);
N(Yellow_Not); N(Yellow_And); N(Yellow_Or);
N(Yellow_n);
N(Yellow_e);
N(Yellow_s);
N(Yellow_w);
N(Twist);
