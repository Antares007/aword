// clang-format off
#include "sophis2.h"
static char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  "White",
                       "Blue",    "Green", "Red",    "Yellow", "Purple"};
Nar(sti_got);
S(sdb) {
#ifndef NDEBUG
  printf("%7s %7s %9s %2ld %3ld %3ld %3ld\n", rays[(ρ + 1) * δ + 5],
         sopcode_names[o[τ]], (char *)o[-β[ρ]], α, β[ρ], τ, σ),
      sti_got(OS);
#endif
}
Nar(Go      ) { sdb(OS), ((n_t*)o)[β[ρ]++](OS); }
Nar(G1      ) { β[ρ]++, Go(OS); }
Nar(G2      ) { β[ρ]++, G1(OS); }
Nar(G3      ) { β[ρ]++, G2(OS); }
Nar(Got     ) { ν = 2, Go(OS); }
Nar(God     ) { ν = 1, Go(OS); }
Nar(Gor     ) { ν = 0, Go(OS); }
Nar(NotAndOr) { n_t narg = o[β[ρ] + ν]; β[ρ] += 3, narg(OS); }
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

S(done) { P, printf("the %s!\n", ν ? ν == 2 ? "not" : "and" : "or"); }

Nar(twist);
Nar(ss);
Nar(Go_Blue     ) { ρ = 0, Go(OS); }
Nar(Go_Green    ) { ρ = 1, Go(OS); }
Nar(Go_Red      ) { ρ = 2, Go(OS); }
Nar(Go_Yellow   ) { ρ = 3, Go(OS); }

Nar(Push_Blue   ) { long v = o[β[ρ]++]; o[--β[0]] = v, Go(OS); }
Nar(Push_Green  ) { long v = o[β[ρ]++]; o[--β[1]] = v, Go(OS); }
Nar(Push_Red    ) { long v = o[β[ρ]++]; o[--β[2]] = v, Go(OS); }
Nar(Push_Yellow ) { long v = o[β[ρ]++]; o[--β[3]] = v, Go(OS); }

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
Nar(programPropeller) {
  OB(0, done);
  OB(1, Go_Blue);
  OB(2, Go_Green);
  OB(3, Go_Red);

  Go_Yellow(OS);
}
Nar(programS) {
  begin     T("S")    print     dot       nl;
  N("S")    nl;
  tab       put("b")  dot       nl;
  tab       T("S")    put("a")  dot       nl;
  tab       T("S")    put("t")  dot       nl;
  B(done), twist(OS);
}
Nar(programAB) {
  begin     T("A")    print     dot       nl;
  N("A")    nl;
  tab       put("o")  dot       nl;
  tab       T("B")    put("a")  dot       nl;
  N("B")    nl;
  tab       put("y")  dot       nl;
  tab       T("A")    put("b")  dot       nl;
  B(done), twist(OS);
}
void sti_init(void);
int main(int argc, char**argv) {
#ifndef NDEBUG
  sti_init();
#endif
  long ram[0x10000];
  long *o = ram + sizeof(ram) / sizeof(*ram) / 2;
  long β[4] = { 2 << Σ, 3 << Σ, 5 << Σ, 4 << Σ };
  long α = 0, τ, σ = τ = 5 << Σ, ρ = 3, δ = 1, ν = 1;
  programTritab(OS);
}
