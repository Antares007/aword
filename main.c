// clang-format off
#include "main.h"
N(sdb       );
N(Yellow    ) __attribute__((noinline));
N(Red       ) __attribute__((noinline));
N(Green     ) __attribute__((noinline));
N(Blue      ) __attribute__((noinline));

N(Yellow    ) { sdb(OS), ((n_t *)β[ρYellow])[0](o, β[ρYellow][-1], α, τ, σ, ρ, δ, ν); }
N(Red       ) { sdb(OS), ((n_t *)β[ρRed   ])[0](o, β[ρRed   ][-1], α, τ, σ, ρ, δ, ν); }
N(Green     ) { sdb(OS), ((n_t *)β[ρGreen ])[0](o, β[ρGreen ][-1], α, τ, σ, ρ, δ, ν); }
N(Blue      ) { sdb(OS), ((n_t *)β[ρBlue  ])[0](o, β[ρBlue  ][-1], α, τ, σ, ρ, δ, ν); }

N(Yellow_G1 ) { Yellow(o, β[ρYellow][-1], α, τ, σ, ρ, δ, ν); }
N(Yellow_G2 ) { Yellow_G1(o, β[ρYellow][-1], α, τ, σ, ρ, δ, ν); }
N(Yellow_Gor) { ν = 0, Yellow(OS); }
N(Yellow_God) { ν = 1, Yellow(OS); }
N(Yellow_Got) { ν = 2, Yellow(OS); }
N(Yellow_NAO) { ((n_t *)β[ρYellow])[ν](o, β[ρYellow][-1], α, τ, σ, ρ, δ, ν); }
N(Yellow_Not) { static n_t nars[] = {Yellow_G1, Yellow_G1, Yellow}; nars[ν](OS); }
N(Yellow_And) { static n_t nars[] = {Yellow_G1, Yellow, Yellow_G1}; nars[ν](OS); }
N(Yellow_Or ) { static n_t nars[] = {Yellow, Yellow_G1, Yellow_G1}; nars[ν](OS); }
N(Twist     ) { Yellow(o, α, β, τ, σ, ρ, -δ, ν); }

N(Yellow_n  ) { τ -= 1 << Σ, Yellow(OS); }
N(Yellow_e  ) { τ += 11,     Yellow(OS); }
N(Yellow_s  ) { τ += 1 << Σ, Yellow(OS); }
N(Yellow_w  ) { τ -= 11,     Yellow(OS); }
extern const char *rays[];
N(zero      ) { printf("The %s(%s)!\n", rays[(ρ % 4 + 1) + 5], ν == 2 ? "not" : ν ? "and" : "or"); }
N(ani       );
N(dive      );
#define begin     o[σ] = begin,               σ += 11,
#define sword(v)  o[σ] = sword, o[σ + 1] = v, σ += 11,
#define name(v)   o[σ] = name,  o[σ + 1] = v, σ += 11,
#define put(v)    o[σ] = put,   o[σ + 1] = v, σ += 11,
#define tword(v)  o[σ] = tword, o[σ + 1] = v, σ += 11,
#define print     o[σ] = print,               σ += 11,
#define tab       o[σ] = tab,                 σ += 11,
#define nop       o[σ] = nop,                 σ += 11,
#define dot       o[σ] = dot,                 σ += 11,
#define end       o[σ] = end,                 σ += 11,
#define nl        o[σ] = nl,                  σ = ((σ >> Σ) + 1) << Σ
N(program123) {
  begin sword("123456789") print nop end nl;
  name("789") nl;
    tab put("7") dot nl;
    tab put("8") dot nl;
    tab put("9") dot nl;
  name("123456789") nl;
    tab sword("123") sword("456") sword("789") dot nl;
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
  begin sword("triTAB") print nop end nl;
  name("triTAB") nl;
    tab sword("TAB") sword("TAB") sword("TAB") dot nl;
  name("TAB") nl;
    tab tword("T") dot nl;
    tab tword("A") dot nl;
    tab tword("B") dot nl;
  oB(ρBlue, Yellow, "TAB", 3, 0), ani(OS);
}
N(programS) {
  begin sword("S") print nop end nl;
  name("S") nl;
    tab tword("b") dot nl;
    tab sword("S") tword("a") dot nl;
    tab sword("S") tword("t") dot nl;
  oB(ρBlue, Yellow, "baaat", 5, 0), ani(OS);
}
N(programSs) {
  begin sword("Ss") print nop end nl;
  name("Ss") nl;
    tab dot nl;
    tab tword("s") sword("Ss") sword("Ss") dot nl;
    tab tword("s") sword("Ss") sword("Ss") dot nl;
    oB(ρBlue, Yellow, "ss", 2, 0), ani(OS);
}
N(programAB) {
  begin sword("A") print nop end nl;
  name("A") nl;
    tab put("o") dot nl;
    tab sword("B") put("a") dot nl;
  name("B") nl;
    tab put("y") dot nl;
    tab sword("A") put("b") dot nl;
  oB(ρBlue, Yellow, "", 0, 0), ani(OS);
}
N(program_aText) {
  begin put("t") put("a") put("b") print end nl;
  ani(OS);
}
void ti_init(void);
int main(int argc, char **argv) {
  ti_init();
  long *root = R(0, zero, 0);
  long *boot = R(0, zero, 0);
  long ram[0x10000];
  long *o = ram + sizeof(ram) / sizeof(*ram) / 2;
  long **β = (long *[]){root, root, root, root};
  long **α = (long *[]){boot, boot, boot, boot};
  long τ;
  long σ = τ = 512;
  long ρ = 2;
  long δ = 1;
  long ν = 1;

  programSs(OS);
}
