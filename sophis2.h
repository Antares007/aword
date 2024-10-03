#pragma once
#pragma GCC diagnostic ignored "-Wint-conversion"
#define N(go)                                                                  \
  void go(long *o, long *β, long α, long τ, long σ, long ρ, long δ, long ν)
typedef N((*n_t));
#define S(go) static N(go)
#define To o, β, α, τ, σ, ρ, δ, ν
#define Σ 8
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
extern int printf(const char *, ...);
#ifndef NDEBUG
#define P printf("%s\n", __func__)
#define OB(r, v) (o[--β[r]] = v), (o[-β[r]] = #v)
#define is_a_book_of(...)                                                           \
  static n_t nars[] = {__VA_ARGS__};                                           \
  if (o[τ] < sizeof(nars) / sizeof(*nars) && nars[o[τ]])                       \
    nars[o[τ]](To);                                                            \
  else                                                                         \
    printf("%s[%s] is not implemented!\n", __func__, sopcode_names[o[τ]]);
#else
#define P (void)0
#define OB(r, v) (o[--β[r]] = v)
#define is_a_book_of(...)                                                           \
  static n_t nars[] = {__VA_ARGS__};                                           \
  nars[o[τ]](To);
#endif
#define B(v) OB(ρ, v)
N(Go);
N(G1);
N(G2);
N(G3);
N(Got);
N(God);
N(Gor);
N(NotAndOr);
N(Not);
N(And);
N(Or);
N(And1);
N(Or1);
N(go_ns);
N(go_we);
N(go_n);
N(go_e);
N(go_s);
N(go_w);
N(drop_alfa);
