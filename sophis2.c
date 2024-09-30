// clang-format off
#include "sophis2.h"
static char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  "White",
                       "Blue",    "Green", "Red",    "Yellow", "Purple"};
Nar(sti_got);
S(sdb) {
#ifdef NDEBUG
  printf("%7s %7s %9s %2ld %3ld %3ld %3ld\n", rays[(ρ + 1) * δ + 5],
         sopcode_names[o[τ]], (char *)o[-β], α, β, τ, σ),
      sti_got(OS);
#endif
}
Nar(Go      ) { sdb(OS);
                n_t nar = o[β];
                β++, nar(OS); }
Nar(G1      ) { β++, Go(OS); }
Nar(G2      ) { β++, G1(OS); }
Nar(G3      ) { β++, G2(OS); }
Nar(Got     ) { ν = 2, Go(OS); }
Nar(God     ) { ν = 1, Go(OS); }
Nar(Gor     ) { ν = 0, Go(OS); }
Nar(NotAndOr) { n_t narg = o[β + ν]; β += 3, narg(OS); }
Nar(Not     ) { static n_t nars[] = {G1, G1, Go}; nars[ν](OS); }
Nar(And     ) { static n_t nars[] = {G1, Go, G1}; nars[ν](OS); }
Nar(Or      ) { static n_t nars[] = {Go, G1, G1}; nars[ν](OS); }
Nar(And1    ) { static n_t nars[] = {G2, Go, G2}; nars[ν](OS); }
Nar(Or1     ) { static n_t nars[] = {Go, G2, G2}; nars[ν](OS); }

Nar(go_ns   ) { τ = τ + (δ << Σ), God(OS); }
Nar(go_we   ) { τ = τ + 11 * δ, God(OS); }
Nar(go_n    ) { δ = -1, go_ns(OS); }
Nar(go_e    ) { δ = +1, go_we(OS); }
Nar(go_s    ) { δ = +1, go_ns(OS); }
Nar(go_w    ) { δ = -1, go_we(OS); }

Nar(drop_alfa) { α--, God(OS); }

S(done) { printf("the %s!\n", ν ? ν == 2 ? "not" : "and" : "or"); }
S(sideb){ Go(OS); }
Nar(twist);
Nar(ss);
#include "sisa.h"
Nar(programTritab) {
  N("ttt")  nl;
  tab       T("tab")  T("tab")  T("tab")  dot       nl;
  N("main") nl;
  tab       T("ttt")  print     dot       nl;
  N("tab")  nl;
  tab       put("t")  dot       nl;
  tab       put("a")  dot       nl;
  tab       put("b")  dot       nl;

  B(done),
  B(twist), B(And);

  o[α++] = "main", ss(OS);
}
Nar(programS) {
  begin     T("S")    print     dot       nl;
  N("S")    nl;
  tab       put("b")  dot       nl;
  tab       T("S")    put("a")  dot       nl;
  tab       T("S")    put("t")  dot       nl;
  o[--β] = done, twist(OS);
}
Nar(programAB) {
  begin     T("A")    print     dot       nl;
  N("A")    nl;
  tab       put("o")  dot       nl;
  tab       T("B")    put("a")  dot       nl;
  N("B")    nl;
  tab       put("y")  dot       nl;
  tab       T("A")    put("b")  dot       nl;
  o[--β] = done, twist(OS);
}
void sti_init(void);
int main(int argc, char**argv) {
  sti_init();
  long ram[0x10000];
  long *o = ram + sizeof(ram) / sizeof(*ram) / 2;
  α = 0, β = τ = σ = 1024, ρ = 3, δ = 1, ν = 1, programTritab(OS);
}
