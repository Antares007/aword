#pragma once
#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Winitializer-overrides"
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wmathematical-notation-identifier-extension"

#define Nar(go) void go(long *o, long β, long α, long τ, long σ, long ρ, long δ, long ν)
typedef Nar((*n_t));
#define S(go) static Nar(go)
#define OS o, β, α, τ, σ, ρ, δ, ν
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
  X(end)                                                                       \
  X(nop)

#define X(n) n,
enum Names { NAMES };
#undef X
#define X(n) #n,
static const char *sopcode_names[] = {NAMES};
#undef X
extern int printf(const char *, ...);
extern long lastbookid;
#define Book_of_(twist, ...)                                                   \
  Nar(twist) {                                                                 \
    static n_t sopcodes[] = {__VA_ARGS__};                                     \
    static const char *name = #twist;                                          \
    if (lastbookid != (long)name)                                              \
      printf("Book of %s(%s)\n", name, sopcode_names[o[τ]]),                   \
          lastbookid = (long)name;                                             \
    sopcodes[o[τ]](OS);                                                        \
  }
#define P printf("%s\n", __func__)
#define O(v) (o[-(--β)] = #v), (o[β] = v)

Nar(Go);
Nar(G1);
Nar(G2);
Nar(Got);
Nar(God);
Nar(Gor);
Nar(NotAndOr);
Nar(Not);Nar(And);Nar(Or);
Nar(go_ns);
Nar(go_we);
Nar(go_n);
Nar(go_e);
Nar(go_s);
Nar(go_w);
Nar(drop_α);
