#pragma once
#define τ regs[0]
#define α regs[1]
#define β regs[2]
#define σ regs[3]
#define ρ regs[4]
#define δ regs[5]

#define Nar(go) void go(long *o, member_t *T, long *regs, void**next)
#define S(go) static Nar(go)
#define OS o, T, regs, next

#define NAMES \
  X(halt)     \
  X(begin)    \
  X(put)      \
  X(print)    \
  X(dot)      \
  X(nl)       \
  X(name)     \
  X(tab)      \
  X(tword)    \
  X(end)      \
  X(nop)

#define X(n) n,
enum Names {NAMES};
#undef X
#define X(n) #n,
static const char*sopcode_names[] = {NAMES};
#undef X

typedef struct member_s { long sc, sc2, a, b, c, d, e; } member_t;
typedef Nar((*n_t));

#define OAN(O,A,N)  (*--next = (O),*--next = (A),*--next = (N))
#define AND(A)      (*--next = Gor,*--next = (A),*--next = Got)

#define aFillBook(n) n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n
#define aBook(N, ...)                                               \
  S(N##_s) { printf(#N "_%s(OS);\n", sopcode_names[T[τ].sc]); }    \
  static n_t N##_sopcodes[] = { aFillBook(N##_s), __VA_ARGS__ };                                                           \
  Nar(N) { N##_sopcodes[T[τ].sc](OS); }

