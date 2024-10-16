// clang-format off
#include "main.h"
N(sdb       );
N(Go        ) __attribute__((noinline));
N(pass      ) __attribute__((noinline));
N(Go        ) { sdb(OS), ((n_t *)β[ρ])[0](o, β[ρ][-1], α, τ, σ, ρ, δ, ν); }
N(G1        ) { Go(o, β[ρ][-1], α, τ, σ, ρ, δ, ν); }
N(Gor       ) { ν = 0, Go(OS); }
N(God       ) { ν = 1, Go(OS); }
N(Got       ) { ν = 2, Go(OS); }
N(NotAndOr  ) { ((n_t *)β[ρ])[ν](o, β[ρ][-1], α, τ, σ, ρ, δ, ν); }
N(Not       ) { static n_t nars[] = {G1, G1, Go}; nars[ν](OS); }
N(And       ) { static n_t nars[] = {G1, Go, G1}; nars[ν](OS); }
N(Or        ) { static n_t nars[] = {Go, G1, G1}; nars[ν](OS); }
N(Twist     ) { Go(o, α, β, τ, σ, ρ, -δ, ν); }
N(pass      ) { static long ss[] = {-11,+(1 << Σ),+11,-(1 << Σ)}; τ += ss[ρ], Go(OS); }
N(go_Red    ) { ρ = 3,  Go(OS); }
N(go_Yellow ) { ρ = 2,  Go(OS); }
N(go_Green  ) { ρ = 1,  Go(OS); }
N(go_Blue   ) { ρ = 0,  Go(OS); }
extern const char *rays[];
N(done      ) { printf("the %s(%s)!\n", rays[(ρ + 1) + 5], ν == 2 ? "not" : ν ? "and" : "or"); }
N(ani       );
N(dive      );
#define begin     o[σ] = begin,               σ += 11,
#define tword(v)  o[σ] = tword, o[σ + 1] = v, σ += 11,
#define name(v)   o[σ] = name,  o[σ + 1] = v, σ += 11,
#define put(v)    o[σ] = put,   o[σ + 1] = v, σ += 11,
#define term(v)   o[σ] = term,  o[σ + 1] = v, σ += 11,
#define print     o[σ] = print,               σ += 11,
#define tab       o[σ] = tab,                 σ += 11,
#define nop       o[σ] = nop,                 σ += 11,
#define dot       o[σ] = dot,                 σ += 11,
#define end       o[σ] = end,                 σ += 11,
#define nl        o[σ] = nl,                  σ = ((σ >> Σ) + 1) << Σ
N(program123) {
  begin tword("123456789") print nop end nl;
  name("789") nl;
    tab put("7") dot nl;
    tab put("8") dot nl;
    tab put("9") dot nl;
  name("123456789") nl;
    tab tword("123") tword("456") tword("789") dot nl;
  name("123") nl;
    tab put("1") dot nl;
    tab put("2") dot nl;
    tab put("3") dot nl;
  name("456") nl;
    tab put("4") dot nl;
    tab put("5") dot nl;
    tab put("6") dot nl;
  ani(OS);
}
N(programTritab) {
  begin tword("triTAB") print nop end nl;
  name("triTAB") nl;
    tab tword("TAB") tword("TAB") tword("TAB") dot nl;
  name("TAB") nl;
    tab term("T") dot nl;
    tab term("A") dot nl;
    tab term("B") dot nl;
  οBlue(Go, "TAB", 3, 0), ani(OS);
}
N(programS) {
  begin tword("S") print nop end nl;
  name("S") nl;
    tab term("b") dot nl;
    tab tword("S") term("a") nop dot nl;
    tab tword("S") term("t") nop dot nl;
  οBlue(Go, "baaat", 5, 0), ani(OS);
}
N(programSs) {
  begin tword("Ss") print nop end nl;
  name("Ss") nl;
    tab put("0") dot nl;
    tab put("1") term("s") tword("Ss")  tword("Ss") dot nl;
  οBlue(Go, "ss", 2, 0), ani(OS);
}
void ti_init(void);
int main(int argc, char **argv) {
  ti_init();
  long *root = R(0, done);
  long *boot = R(0, done);
  long ram[0x10000];
  long *o = ram + sizeof(ram) / sizeof(*ram) / 2;
  long **β = (long *[]){root, root, root, root};
  long **α = (long *[]){boot, boot, boot, boot};
  long τ;
  long σ = τ = 512;
  long ρ = 3;
  long δ = 1;
  long ν = 1;
  programS(OS);
}
