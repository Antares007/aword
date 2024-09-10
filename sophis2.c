#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Winitializer-overrides"

#include "sophis2.h"

#include <stdio.h>
#define P printf("%s\n", __func__)

Nar(sti_got);
static char*rays[] = {"Fuchsia", "Olive", "Maroon", "Lime", "Navy", "White", "Blue", "Green", "Red", "Yellow", "Purple"};
S(dbg) {
  printf("%10s %7s %7s %2ld %3ld %3ld %3ld\n", (char*)βοοκ, rays[(ρ+1)*δ+5], sopcode_names[text[τ].sc], α, β, τ, σ), sti_got(OS); }

S(Got) { n_t s = next[2]; next += 3, s(OS); }
S(God) { n_t s = next[1]; next += 3, s(OS); }
S(Gor) { n_t s = next[0]; next += 3, s(OS); }

Nar(go_n)  { τ = ((τ >> 4) - 1) << 4, δ = -1, dbg(OS), God(OS); }
Nar(go_e)  { τ = τ + 1,               δ = +1, dbg(OS), God(OS); }
Nar(go_s)  { τ = ((τ >> 4) + 1) << 4, δ = +1, dbg(OS), God(OS); }
Nar(go_w)  { τ = τ - 1,               δ = -1, dbg(OS), God(OS); }

Nar(grow);
S(grow_   ) { text[σ].sc = text[τ].sc,                        σ++,  AND(grow), go_e(OS); }
S(grow_a  ) { text[σ].sc = text[τ].sc, text[σ].a = text[τ].a, σ++,  AND(grow), go_e(OS); }
S(grow_nl ) { text[σ].sc = nl,                                σ = ((σ >> 4) + 1) << 4,
              text[σ].sc = end,                                     AND(grow), go_s(OS); }
aBook(grow,
    [name]  = God,
    [end]   = God,
    [nl]    = grow_nl,
    [tword] = grow_a,
    [put]   = grow_a,
    [term]  = grow_a,
    [tab]   = grow_,
    [nop]   = grow_,
    [print] = grow_,
    [dot]   = grow_,
)
extern int strcmp (const char*, const char*);
S(search_n);
S(search_n_next ) { AND(search_n), go_n(OS); }
S(search_n_name ) { if(strcmp(text[τ].a, o[α-1]) == 0) α--, God(OS);
                    else search_n_next(OS); }
aBook(search_n,
    [end]   = search_n_next,
    [tab]   = search_n_next,
    [name]  = search_n_name,
    [begin] = Gor,
)
Nar(search_s);
S(search_s_next ) { AND(search_s), go_s(OS); }
S(search_s_name ) { if(strcmp(text[τ].a, o[α-1]) == 0) α--, God(OS);
                    else search_s_next(OS); }
aBook(search_s,
    [tword] = search_s_next,
    [tab]   = search_s_next,
    [name]  = search_s_name,
    [end]   = Gor,
)
S(wist); S(twist); S(spin);
S(spin_tab) { if (text[τ].d == 2)             AND(spin), go_s(OS);
              else text[τ].d = 1, τ = o[β++], AND(twist), go_e(OS); }
S(spin_end) { τ = text[o[β]].c, ρ += 2,       AND(spin), go_s(OS); }
aBook(spin,
    [tab] = spin_tab,
    [end] = spin_end,
    [name] = spin_end,
)

S(wist_begin      ) { if (ρ < 2) ρ = 3, AND(twist), go_e(OS); }
S(wist_w          ) { AND(wist), go_w(OS); }
S(wist_tab_Blue   ) { τ = o[β++], AND(twist), go_e(OS); }
S(wist_tab_Green  ) { text[τ].e = 1,
                      τ = o[β++], AND(twist), go_e(OS); }
S(wist_tab_Red    ) { text[τ].d = (text[τ].e ? 0 : 2), ρ -= 2, AND(spin), go_s(OS); }
S(wist_tab_Yellow ) { text[τ].e = 1,
                      text[τ].d = 0, ρ -= 2, AND(spin), go_s(OS); }
S(wist_tab        ) { static n_t rays[] = { wist_tab_Blue,wist_tab_Green,
                                            wist_tab_Red, wist_tab_Yellow, };
                      rays[ρ](OS); }
aBook(wist,
    [dot]   = wist_w,
    [put]   = wist_w,
    [term]  = wist_w,
    [print] = wist_w,
    [tword] = wist_w,
    [nop]   = wist_w,
    [tab]   = wist_tab,
    [begin] = wist_begin,
    )
S(twist_begin         ) { AND(twist), go_e(OS); }
S(twist_nop           ) { AND(twist), go_e(OS); }
S(drop_alfa_Gor       ) { α--, Gor(OS); }
S(twist_tword_go_in   ) { o[--β] = τ, τ = text[τ].c, AND(twist), twist(OS); }
S(twist_tword_Gor     ) { τ = o[--α], σ = o[--α], Gor(OS); }
S(twist_tword_God     ) { τ = o[--α],
                          text[τ].c = o[--α],
                          text[text[τ].c + (1 << 4)].d = 1,
                          text[τ].sc2 = 1, AND(twist), twist(OS); }
S(twist_tword_init    ) { NAO(Got, twist_tword_God, twist_tword_Gor),
                          NAO(Got, grow_a,          drop_alfa_Gor  ),
                          NAO(Got, God,             search_n       ),
                          o[α++] = σ,
                          o[α++] = τ,
                          o[α++] = text[τ].a, search_s(OS); }
S(twist_tword_rho     ) { static n_t nars[] = {wist, twist_tword_init, wist, twist_tword_init};
                          nars[ρ](OS); }
S(twist_tword_switch  ) { static n_t nars[] = {twist_tword_rho, twist_tword_go_in};
                          nars[text[τ].sc2](OS); }
S(twist_e             ) { NAO(Got, twist, Gor), go_e(OS); }
S(twist_s             ) { NAO(Got, twist, Gor), go_s(OS); }
S(twist_tab           ) { NAO(Got, twist, Gor), (text[τ].d == 1 ? go_e : go_s)(OS); }
S(twist_put           ) { o[α++] = text[τ].a, twist_e(OS); }
S(twist_term_parse    ) { if (o[α-1] < o[α-2] && ((char*)o[α-3])[o[α-1]] == ((char*)text[τ].a)[0])
                            o[α-1]++;
                          else
                            ρ -= 1;
                          twist_e(OS); }
S(twist_term          ) { static n_t rays[] = { twist_e, twist_term_parse,
                                                twist_e, twist_term_parse, };
                          rays[ρ](OS); }
S(twist_print         ) { printf("%s[", rays[(ρ+1)*δ+5]);
                          for(long i=0; i<α; i++) 
                            if (o[i] < 10000) printf("%ld ", o[i]);
                            else printf("%s ", (char*)o[i]);
                          printf("]\n"), α = 0, twist_e(OS); }
aBook(twist, 
    [begin] = twist_begin,
    [nop]   = twist_nop,
    [tword] = twist_tword_switch,
    [name]  = twist_e,
    [nl]    = twist_s,
    [tab]   = twist_tab,
    [put]   = twist_put,
    [term]  = twist_term,
    [print] = twist_print,
    [dot]   = wist,
)

S(not_done) {P;}
S(and_done) {P;}
S(or_done ) {P;}

#include "sisa.h"
Nar(programTritab) {
  begin put("bat") put(3) put(0) tword("tritab") print dot nl

  name("tab") nl
  tab term("t") dot nl
  tab term("a") dot nl
  tab term("b") dot nl

  name("tritab") nl
  tab tword("tab") tword("tab") tword("tab") dot nl
  end

  NAO(not_done, and_done, or_done),
    twist(OS);
}
Nar(programS) {
  begin put("baa") put(3) put(0) tword("S") print dot nl

  name("S") nl
  tab term("b") dot nl
  tab tword("S") term("a") dot nl
  tab tword("S") term("t") dot nl

  NAO(not_done, and_done, or_done),
    twist(OS);
}
Nar(programAB) {
  begin nop tword("A") print dot nl

  name("A") nl
  tab put("o") dot nl
  tab tword("B") put("a") dot nl

  name("B") nl
  tab put("y") dot nl
  tab tword("A") put("b") dot nl

  NAO(not_done, and_done, or_done),
    twist(OS);
}
void sti_init();
int main() {
  sti_init();
  member_t    members[0x800] = {};
  long            ram[0x800];
  void         *nexts[0x800];
  void   **next = nexts   + sizeof(nexts)   / sizeof(*nexts)   / 2;
  member_t*text = members + sizeof(members) / sizeof(*members) / 2;
  long       *o = ram     + sizeof(ram)     / sizeof(*ram)     / 2;
  long regs[10] = {};
  β = sizeof(ram) / sizeof(*ram) / 2, ρ = 3, programAB(OS);
}
