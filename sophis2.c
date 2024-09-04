#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Winitializer-overrides"

#include "sophis2.h"

Nar(go_n) __attribute__((noinline));
Nar(go_e) __attribute__((noinline));
Nar(go_s) __attribute__((noinline));
Nar(go_w) __attribute__((noinline));

#include <stdio.h>
#define P printf("%s\n", __func__)

Nar(sti_got);

S(dbg) {
  printf("%7s %2ld %3ld %3ld\n", sopcode_names[T[τ].sc], α, τ, σ), sti_got(OS);
}
S(Got) { n_t s = *(next+2); next += 3, s(OS); }
S(God) { n_t s = *(next+1); next += 3, s(OS); }
S(Gor) { n_t s = *(next+0); next += 3, s(OS); }

Nar(go_n)  { τ = ((τ >> 4) - 1) << 4, δ = -1, dbg(OS), God(OS); }
Nar(go_e)  { τ = τ + 1,               δ = +1, dbg(OS), God(OS); }
Nar(go_s)  { τ = ((τ >> 4) + 1) << 4, δ = +1, dbg(OS), God(OS); }
Nar(go_w)  { τ = τ - 1,               δ = -1, dbg(OS), God(OS); }

#define aFillBook(n) n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n,n
#define aBook(N, ...)                                               \
  S(N##_s) { printf(#N "_%s(OS);\n", sopcode_names[T[τ].sc]); }    \
  static n_t N##_sopcodes[] = { aFillBook(N##_s), __VA_ARGS__ };                                                           \
  Nar(N) { N##_sopcodes[T[τ].sc](OS); }

Nar(grow);

#define AND(A) (*--next = Gor,*--next = (A),*--next = Got)
S(grow_name ) { if(o[β] == (long)grow_name) β++, God(OS);
                else T[σ].sc = name, T[σ].a = T[τ].a, σ++, o[α++] = σ,
                      o[--β] = grow_name, AND(grow), go_e(OS); }
S(grow_nl   ) { T[σ].sc = nl,                       σ = ((σ >> 4) + 1) << 4,
                                                         AND(grow), go_s(OS); }
S(grow_     ) { T[σ].sc = T[τ].sc,                  σ++, AND(grow), go_e(OS); }
S(grow_a    ) { T[σ].sc = T[τ].sc, T[σ].a = T[τ].a, σ++, AND(grow), go_e(OS); }


aBook(grow,
  [name]  = grow_name,
  [nl]    = grow_nl,
  [tab]   = grow_,
  [nop]   = grow_,
  [tword] = grow_a,
  [print] = grow_,
  [dot]   = grow_,
  [put]   = grow_)

Nar(search_s);
S(search_s_begin) { *--next = Gor, *--next = search_s, *--next = Got, go_s(OS); }
extern int strcmp (const char*, const char*);
S(search_sn_end ) { next++, Gor(OS); }
S(search_s_name ) { if(strcmp(T[τ].a, *next) == 0) next++, God(OS);
                    else search_s_begin(OS); }
aBook(search_s,
  [begin] = search_s_begin,
  [name] = search_s_name,
  [tab] = search_s_begin,
  [end] = search_sn_end)

S(search_n);
S(search_n_end  ) { *--next = Gor, *--next = search_n, *--next = Got, go_n(OS); }
S(search_n_name ) { if(strcmp(T[τ].a, *next) == 0) next++, God(OS);
                    else search_n_end(OS); }
aBook(search_n,
  [end] = search_n_end,
  [tab] = search_n_end,
  [name] = search_n_name,
  [begin] = search_sn_end)


#define begin     T[σ].sc = begin,              σ++,
#define tword(v)  T[σ].sc = tword, T[σ].a = v,  σ++,
#define put(v)    T[σ].sc = put,   T[σ].a = v,  σ++,
#define print     T[σ].sc = print,              σ++,
#define name(v)   T[σ].sc = name,  T[σ].a = v,  σ++,
#define tab       T[σ].sc = tab,                σ++,
#define dot       T[σ].sc = dot,                σ++,
#define nop       T[σ].sc = nop,                σ++,
#define nl        T[σ].sc = nl,                 σ = ((σ >> 4) + 1) << 4,
#define end       T[σ].sc = end,

static member_t members[1024];
static long ram[1024];
static void*nexts[1024];
S(not_done) {P;}
S(and_done) {P;}
S(or_done) {P;}
void sti_init();
int main() {
  sti_init();
  void**next = nexts + 1024;
  member_t *T = members + 512;
  long *o = ram + 512;
  long regs[10] = {};
  β = 512;
  ρ = 3;
  α = 0;

  begin nl

  name("start") nl
  tab nop tword("tritab") print dot nl

  name("tab") nl
  tab put("t") dot nl
  tab put("a") dot nl
  tab put("b") dot nl

  name("tritab") nl
  tab tword("tab") tword("tab") tword("tab") dot nl
  end

  *--next = not_done;
  *--next = and_done;
  *--next = or_done;
  *--next = Got;
  *--next = grow;
  *--next = Gor;
  *--next = "tab";
  search_s(OS);
}
