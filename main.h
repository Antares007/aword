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
  X(rword)                                                                     \
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
#define R(β, ...)                                                                                            \
  (long[]){__func__, FIRSTR(__VA_ARGS__), sizeof((long[]){__VA_ARGS__}) / sizeof(long), β, __VA_ARGS__} + 4

#define οRed(...)     β = (long *[]){β[0],β[1],β[2],R(β,__VA_ARGS__)}
#define οYellow(...)  β = (long *[]){β[0],β[1],R(β,__VA_ARGS__),β[3]}
#define οGreen(...)   β = (long *[]){β[0],R(β,__VA_ARGS__),β[2],β[3]}
#define οBlue(...)    β = (long *[]){R(β,__VA_ARGS__),β[1],β[2],β[3]}
#define οNavy(...)    α = (long *[]){R(α,__VA_ARGS__),α[1],α[2],α[3]}
#define οLime(...)    α = (long *[]){α[0],R(α,__VA_ARGS__),α[2],α[3]}
#define οOlive(...)   α = (long *[]){α[0],α[1],R(α,__VA_ARGS__),α[3]}
#define οMaroon(...)  α = (long *[]){α[0],α[1],α[2],R(α,__VA_ARGS__)}

#define ρRed    3
#define ρYellow 2
#define ρGreen  1
#define ρBlue   0

N(sdb);
#define is_a_book_of(...)                                                      \
  static n_t nars[Names_Count] = {__VA_ARGS__};                                \
  if (nars[o[τ]]) sdb(OS), nars[o[τ]](OS);                                     \
  else printf("%s[%s] is not implemented!\n", __func__, sopcode_names[o[τ]]);

N(Red   );
N(Yellow);
N(Green );
N(Blue  );
N(Navy  );
N(Lime  );
N(Olive );
N(Maroon);

N(Yellow_Got);
N(Yellow_God);
N(Yellow_Gor);
N(Yellow_NAO);
