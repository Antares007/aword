#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Winitializer-overrides"

#include "sophis2.h"

#include <stdio.h>
#define P printf("%s\n", __func__)

Nar(sti_got);
S(dbg) { printf("%7s %2ld %3ld %3ld\n", sopcode_names[T[τ].sc], α, τ, σ), sti_got(OS); }

S(Got) { n_t s = *(next+2); next += 3, s(OS); }
S(God) { n_t s = *(next+1); next += 3, s(OS); }
S(Gor) { n_t s = *(next+0); next += 3, s(OS); }

Nar(go_n)  { τ = ((τ >> 4) - 1) << 4, δ = -1, dbg(OS), God(OS); }
Nar(go_e)  { τ = τ + 1,               δ = +1, dbg(OS), God(OS); }
Nar(go_s)  { τ = ((τ >> 4) + 1) << 4, δ = +1, dbg(OS), God(OS); }
Nar(go_w)  { τ = τ - 1,               δ = -1, dbg(OS), God(OS); }

Nar(grow);

S(grow_name ) { if (o[β] == (long)grow_name) β++, God(OS);
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

extern int strcmp (const char*, const char*);
Nar(search_s);
S(search_s_begin) { AND(search_s), go_s(OS); }
S(search_s_name ) { if(strcmp(T[τ].a, o[α-1]) == 0) God(OS);
                    else search_s_begin(OS); }
aBook(search_s,
  [begin] = search_s_begin,
  [name] = search_s_name,
  [tab] = search_s_begin,
  [end] = Gor)

S(search_n);
S(search_n_end  ) { AND(search_n), go_n(OS); }
S(search_n_name ) { if(strcmp(T[τ].a, o[α-1]) == 0) God(OS);
                    else search_n_end(OS); }
aBook(search_n,
  [end] = search_n_end,
  [tab] = search_n_end,
  [name] = search_n_name,
  [begin] = Gor)

S(not_done) {P;}
S(and_done) {P;}
S(or_done) {P;}

S(program) {
  #include "sisa.h"
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

  OAN(or_done, and_done, not_done),
  AND(grow),
  o[α++] = "tab", search_s(OS);
}

static member_t members[1024];
static long ram[1024];
static void*nexts[1024];
void sti_init();
int main() {
  sti_init();
  void**next = nexts + 1024;
  member_t *T = members + 512;
  long *o = ram + 512;
  long regs[10] = {};
  β = 512, ρ = 3, α = 0, program(OS);
}
