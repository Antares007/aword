// clang-format off
#include "sophis.h"
#define Step(Name, Side, Nau, Ray, Capstone, Delta) \
  N(Name) { ρ = Side, δ = Delta, ν = Nau, sdb(OS);  \
            n_t nar = Capstone[Side][Ray];          \
            Capstone = Capstone[Side][-1], nar(OS); \
  }
#define Steps(Name, Side, Capstone, Delta)    \
  Step(Name,        Side, ν, 0, Capstone, +1) \
  Step(Name##_Red,  Side, 2, 0, Capstone, +1) \
  Step(Name##_Green,Side, 1, 0, Capstone, +1) \
  Step(Name##_Blue, Side, 0, 0, Capstone, +1) \
  Step(Name##_NAO,  Side, ν, ν, Capstone, +1)

Steps(Red,    3, β, +1)
Steps(Yellow, 2, β, +1)
Steps(Green,  1, β, +1)
Steps(Blue,   0, β, +1)

Steps(Maroon, 3, α, -1)
Steps(Olive,  2, α, -1)
Steps(Lime,   1, α, -1)
Steps(Navy,   0, α, -1)

Steps(Tomato, 3, ω, +1)
Steps(Gold,   2, ω, +1)
Steps(Teal,   1, ω, +1)
Steps(Cyan,   0, ω, +1)

extern const char *rays[];
N(zero      ) { printf("The %s(%s)!\n", rays[(ρ + 1) + 5], ν == 2 ? "not" : ν ? "and" : "or"); }
N(gani);

N(prn) { printf("Green()\n"), Green(OS); }
N(term) {
  const char *t = ο[τ + 2];
  const char *s = ωCyan[1];
  long length   = ωCyan[2];
  long pos      = ωCyan[3];
  if (pos < length && s[pos] == t[0])
    οCyan(Cyan, s, length, pos + 1), Green(OS);
  else
    Blue(OS);
}
N(dot_begin);
N(dot_simbol);
N(dot_terminal);
N(dot_end);
N(s) { dot_simbol(OS); }
N(b) { dot_terminal(OS); }
N(a) { dot_terminal(OS); }
N(t) { dot_terminal(OS); }
#include "sisa.h"
N(programS) {
  B T(dot_begin) D(s) T(dot_end) _;
  D(s) _;
  B T(b) O _;
  B D(s) T(a) O _;
  B D(s) T(t) O _;
  οCyan(Cyan, "bataata", 7, 0), gani(OS);
}
void ti_init(void);
N(programAB);
N(programExpr);
N(programSs);
N(program_isamntpwab);
int main(int argc, char **argv) { ti_init();
  long *cap = R(0, zero, 0);
  long ram[0x10000];
  long *ο = ram + sizeof(ram) / sizeof(*ram) / 2;
  long **β = (long *[]){cap, cap, cap, cap};
  long **α = (long *[]){cap, cap, cap, cap};
  long **ω = (long *[]){cap, cap, cap, cap};
  long τ;
  long σ = τ = 512;
  long ρ = 2;
  long δ = 1;
  long ν = 1;
  οOlive(Yellow), programS(OS);
}
