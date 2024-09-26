// clang-format off
#include "sophis2.h"
long lastbookid;
static char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  "White",
                       "Blue",    "Green", "Red",    "Yellow", "Purple"};
Nar(sti_got );
S(sdb       ) {
#ifdef NDEBUG
  printf("%7s %7s %2ld %3ld %3ld %3ld\n", rays[(ρ + 1) * δ + 5], sopcode_names[o[τ]], α, β, τ, σ), sti_got(OS);
#endif
}
Nar(Go      ) {sdb(OS),
     ((n_t *)o)[β](o, β + 1, α, τ, σ, ρ, δ, ν); }
Nar(G1      ) { Go(o, β + 1, α, τ, σ, ρ, δ, ν); }
Nar(G2      ) { G1(o, β + 1, α, τ, σ, ρ, δ, ν); }
Nar(Got     ) { Go(o, β,     α, τ, σ, ρ, δ, 2); }
Nar(God     ) { Go(o, β,     α, τ, σ, ρ, δ, 1); }
Nar(Gor     ) { Go(o, β,     α, τ, σ, ρ, δ, 0); }
Nar(NotAndOr) { n_t narg = o[β + ν]; β += 3, narg(OS); }
Nar(And     ) { static n_t nars[] = {G1, Go, G1}; nars[ν](OS); }

Nar(go_ns   ) { τ = τ + (δ << Σ), Go(OS); }
Nar(go_we   ) { τ = τ + 11 * δ,   Go(OS); }
Nar(go_n    ) { δ = -1, go_ns(OS); }
Nar(go_e    ) { δ = +1, go_we(OS); }
Nar(go_s    ) { δ = +1, go_ns(OS); }
Nar(go_w    ) { δ = -1, go_we(OS); }

Nar(drop_α  ) { α--, Go(OS); }

S(done      ) { printf("the %s!\n", ν ? ν == 2 ? "not" : "and" : "or"); }
#include<string.h>
Nar(walk);
extern int strcmp (const char *, const char *);
S(walk_match) { (strcmp(o[τ+1], o[α-1]) ? Gor : God)(OS); }
S(found) {P; Go(OS);}
S(notfound) {P; Go(OS);}
S(walk_name) {
  O(Go), O(found), O(notfound), O(NotAndOr);
  O(walk_match), O(And);
  Go(OS);
}
Book_of_(walk,
    [name] = walk_name,
)
Nar(twist);
#include "sisa.h"
Nar(programTritab) {
  N("main") nl;
  tab       T("tab")  print     dot       nl;
  N("ttt")  nl;
  tab       T("tab")  T("tab")  T("tab")  dot       nl;
  N("tab")  nl;
  tab       put("t")  dot       nl;
  tab       put("a")  dot       nl;
  tab       put("b")  dot       nl;
  o[--β] = done, 
    o[α++] = "main", walk(OS);
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
  long β, α, τ, σ, ρ, δ, ν;
  α = 0, β = τ = σ = 1024, ρ = 3, δ = 1, ν = 1, programTritab(OS);
}

