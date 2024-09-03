#include "sophis2.h"

Nar(go_n) __attribute__((noinline));
Nar(go_e) __attribute__((noinline));
Nar(go_s) __attribute__((noinline));
Nar(go_w) __attribute__((noinline));

#include <stdio.h>
S(hlt) {}

S(beg_n) { go_s(OS); }
S(beg_w) { α = 0, go_e(OS); }

S(put_e) { o[α++] = text[τ].a, go_e(OS); }

S(print_e) {
  for (long i = 0; i < α; i++)
    printf("%ld", o[i]);
  printf("\n");
  go_e(OS);
}

S(dot_e) { go_w(OS); }
S(name_n) { go_n(OS); }
S(name_s) { go_s(OS); }
S(tab_n) { go_n(OS); }
S(tab_s) { go_s(OS); }
S(tab_w) {}
S(end_s) {}
// clang-format off
static Nar((*sopcodes[][4])) = {
    [halt]      = {hlt,     hlt,      hlt,    hlt},
    [begin]     = {beg_n,   0,        0,      beg_w},
    [put]       = {0,       put_e,    0,      go_w},
    [print]     = {0,       print_e,  0,      go_w},
    [dot]       = {0,       dot_e,    0,      0},
    [name]      = {name_n,  0,        name_s, 0},
    [tab]       = {tab_n,   0,        tab_s,  tab_w},
    [end]       = {0,       0,        end_s,  0},
};

Nar(sti_got);
S(dbg) { printf("%s\n", text[τ].name), sti_got(OS); }
Nar(go_n) { τ -= 1 << 4, dbg(OS), sopcodes[text[τ].sc][0](OS); }
Nar(go_e) { τ += 1,      dbg(OS), sopcodes[text[τ].sc][1](OS); }
Nar(go_s) { τ += 1 << 4, dbg(OS), sopcodes[text[τ].sc][2](OS); }
Nar(go_w) { τ -= 1,      dbg(OS), sopcodes[text[τ].sc][3](OS); }

#define begin text[σ].name = "begin",  text[σ].sc = begin,                  σ++,
#define put(v)    text[σ].name = "put",        text[σ].sc = put,        text[σ].a = v,  σ++,
#define print     text[σ].name = "print",      text[σ].sc = print,                      σ++,
#define name(v)   text[σ].name = "name",       text[σ].sc = name,       text[σ].a = v,  σ++,
#define tab       text[σ].name = "tab",        text[σ].sc = tab,                        σ++,
#define dot       text[σ].name = "dot",        text[σ].sc = dot,                        σ = ((σ >> 4) + 1) << 4,
#define end       text[σ].name = "end",        text[σ].sc = end,       

static member_t members[1024];
static long ram[1024];


void sti_init();
int main() {
  sti_init();
  member_t *text = members + 512;
  long *o = ram + 512;

  long regs[10] = {};

  begin put(1) put(2) print dot
  name(3)
  tab put(5) dot
  tab put(7) dot
  end
 // τ = σ;
  go_e(OS);
}
