// clang-format off
#include "sophis2.h"
static char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  "White",
                       "Blue",    "Green", "Red",    "Yellow", "Purple"};
Nar(sti_got);
S(sdb) {
#ifndef NDEBUG
  printf("%7s %7s %9s %2ld %3ld %3ld %3ld\n", rays[(ρ + 1) * δ + 5],
         sopcode_names[o[τ]], (char *)o[-β[ρ]], α, β[ρ], τ, σ),
      sti_got(To);
#endif
}
Nar(Go      ) { sdb(To), ((n_t*)o)[β[ρ]++](To); }
Nar(G1      ) { β[ρ]++, Go(To); }
Nar(G2      ) { β[ρ]++, G1(To); }
Nar(G3      ) { β[ρ]++, G2(To); }
Nar(Got     ) { ν = 2, Go(To); }
Nar(God     ) { ν = 1, Go(To); }
Nar(Gor     ) { ν = 0, Go(To); }
Nar(NotAndOr) { n_t narg = o[β[ρ] + ν]; β[ρ] += 3, narg(To); }
Nar(Not     ) { static n_t nars[] = {G1, G1, Go}; nars[ν](To); }
Nar(And     ) { static n_t nars[] = {G1, Go, G1}; nars[ν](To); }
Nar(Or      ) { static n_t nars[] = {Go, G1, G1}; nars[ν](To); }
Nar(And1    ) { static n_t nars[] = {G2, Go, G2}; nars[ν](To); }
Nar(Or1     ) { static n_t nars[] = {Go, G2, G2}; nars[ν](To); }

Nar(go_ns   ) { τ = τ + (δ << Σ), Go(To); }
Nar(go_we   ) { τ = τ + 11 * δ, Go(To); }
Nar(go_n    ) { δ = -1, go_ns(To); }
Nar(go_e    ) { δ = +1, go_we(To); }
Nar(go_s    ) { δ = +1, go_ns(To); }
Nar(go_w    ) { δ = -1, go_we(To); }

Nar(drop_alfa) { α--, God(To); }

S(done) { P, printf("the %s!\n", ν ? ν == 2 ? "not" : "and" : "or"); }

Nar(twist);
Nar(ss);
Nar(Go_Blue     ) { ρ = 0, Go(To); }
Nar(Go_Green    ) { ρ = 1, Go(To); }
Nar(Go_Red      ) { ρ = 2, Go(To); }
Nar(Go_Yellow   ) { ρ = 3, Go(To); }

Nar(Push_Blue   ) { long v = o[β[ρ]++]; o[--β[0]] = v, Go(To); }
Nar(Push_Green  ) { long v = o[β[ρ]++]; o[--β[1]] = v, Go(To); }
Nar(Push_Red    ) { long v = o[β[ρ]++]; o[--β[2]] = v, Go(To); }
Nar(Push_Yellow ) { long v = o[β[ρ]++]; o[--β[3]] = v, Go(To); }

Nar(ani);
#include "sisa.h"
Nar(programAraDaNi) {
  N("ani") nl;
  tab put("t") put("a") put("b") print dot put("1") put("2") put("3") print dot nl;
  tab put("3") put("4") put("5") print dot nl;
  OB(0, done),
  OB(1, done),
  OB(2, done),
  OB(3, done), OB(3, ani);

  o[α++] = "ani", ss(To);
}

Nar(programTritab) {
  N("ttt")  nl;
  tab       T("tab")  T("tab")  T("tab")  dot       nl;
  N("main") nl;
  tab       T("ttt")  print     dot       nl;
  N("tab")  nl;
  tab       put("t")  dot       nl;
  tab       put("a")  dot       nl;
  tab       put("b")  dot       nl;

  OB(0,done), OB(1,done), OB(2,done), OB(3,done);
  OB(3,twist), B(And);

  o[α++] = "main", ss(To);
}
Nar(programPropeller) {
  OB(0, done);
  OB(1, Go_Blue);
  OB(2, Go_Green);
  OB(3, Go_Red);

  Go_Yellow(To);
}
Nar(programS) {
  begin     T("S")    print     dot       nl;
  N("S")    nl;
  tab       put("b")  dot       nl;
  tab       T("S")    put("a")  dot       nl;
  tab       T("S")    put("t")  dot       nl;
  B(done), twist(To);
}
Nar(programAB) {
  begin     T("A")    print     dot       nl;
  N("A")    nl;
  tab       put("o")  dot       nl;
  tab       T("B")    put("a")  dot       nl;
  N("B")    nl;
  tab       put("y")  dot       nl;
  tab       T("A")    put("b")  dot       nl;
  B(done), twist(To);
}
void sti_init(void);
int main(int argc, char**argv) {
#ifndef NDEBUG
  sti_init();
#endif
  long ram[0x10000];
  long *o = ram + sizeof(ram) / sizeof(*ram) / 2;
  long β[4] = { 3 << Σ, 4 << Σ, 6 << Σ, 5 << Σ };
  long α = 0, τ, σ = τ = 6 << Σ, ρ = 3, δ = 1, ν = 1;
  //programTritab(To);
  programAraDaNi(To);
}
