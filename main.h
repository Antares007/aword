#pragma once
#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Winitializer-overrides"

#define NAMES                                                                  \
  X(halt)                                                                      \
  X(dot)                                                                       \
  X(name)                                                                      \
  X(nl)                                                                        \
  X(nop)                                                                       \
  X(print)                                                                     \
  X(put)                                                                       \
  X(tab)                                                                       \
  X(term)                                                                      \
  X(tword)

#define X(n) n,
enum Names { NAMES };
#undef X

#define X(n) #n,
static const char *sopcode_names[] = {NAMES};
#undef X

#define Σ 8
#define OS o, β, τ, σ, ρ, δ, ν
#define N(argo)                                                                \
  void argo(long *o, long **β, long τ, long σ, long ρ, long δ, long ν)
#define S(argo) static N(argo)
typedef N((*n_t));

#include "evalmap.h"
#define TOSTR(a) #a,
#define MAPTOSTR(...) EVAL8(MAP(TOSTR, __VA_ARGS__))
#define LEN(...) sizeof((long[]){__VA_ARGS__}) / sizeof(long)

extern int printf(const char *__restrict __format, ...);
#define P printf("%s\n", __func__)

#define R(β, ...)                                                              \
  (long[]){LEN(__VA_ARGS__), β, __VA_ARGS__, MAPTOSTR(__VA_ARGS__)} + 2

#define OB(ρ, ...)                                                             \
  β = (long *[]) { β[0], β[1], β[2], β[3], [ρ] = R(β, __VA_ARGS__) }

#define is_a_book_of(...)                                                      \
  static n_t nars[] = {__VA_ARGS__};                                           \
  if (o[τ] < sizeof(nars) / sizeof(*nars) && nars[o[τ]])                       \
    nars[o[τ]](OS);                                                            \
  else                                                                         \
    printf("%s[%s] is not implemented!\n", __func__, sopcode_names[o[τ]]);

N(Go);
N(Got);
N(God);
N(Gor);
N(NotAndOr);
N(go_n);
N(go_e);
N(go_s);
N(go_w);
