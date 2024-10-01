#pragma once
#pragma GCC diagnostic ignored "-Wint-conversion"
#define Nar(go)                                                                \
  void go(long *o, long *β, long α, long τ, long σ, long ρ, long δ, long ν)
typedef Nar((*n_t));
#define S(go) static Nar(go)
#define To o, β, α, τ, σ, ρ, δ, ν
#define Σ 8
#define NAMES                                                                  \
  X(halt)                                                                      \
  X(begin)                                                                     \
  X(put)                                                                       \
  X(term)                                                                      \
  X(print)                                                                     \
  X(dot)                                                                       \
  X(nl)                                                                        \
  X(name)                                                                      \
  X(tab)                                                                       \
  X(tword)                                                                     \
  X(nop)
#define X(n) n,
enum Names { NAMES };
#undef X
#define X(n) #n,
static const char *sopcode_names[] = {NAMES};
#undef X
extern int printf(const char *, ...);
#ifndef NDEBUG
#define P printf("%s\n", __func__)
#define OB(r, v) (o[--β[r]] = v), (o[-β[r]] = #v)
#define Book_of(...)                                                           \
  static n_t nars[] = {__VA_ARGS__};                                           \
  if (o[τ] < sizeof(nars) / sizeof(*nars) && nars[o[τ]])                       \
    nars[o[τ]](To);                                                            \
  else                                                                         \
    printf("%s[%s] is not implemented!\n", __func__, sopcode_names[o[τ]]);
#else
#define P (void)0
#define OB(r, v) (o[--β[r]] = v)
#define Book_of(...)                                                           \
  static n_t nars[] = {__VA_ARGS__};                                           \
  nars[o[τ]](To);
#endif
#define B(v) OB(ρ, v)
Nar(Go);
Nar(G1);
Nar(G2);
Nar(G3);
Nar(Got);
Nar(God);
Nar(Gor);
Nar(NotAndOr);
Nar(Not);
Nar(And);
Nar(Or);
Nar(And1);
Nar(Or1);
Nar(go_ns);
Nar(go_we);
Nar(go_n);
Nar(go_e);
Nar(go_s);
Nar(go_w);
Nar(drop_alfa);
