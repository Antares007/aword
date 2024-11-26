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

N(prn) {
  long**b = ω;
  printf("Green(");
  while(b[3][-1])
    (b[3][1] < 1000 ? printf("%ld ", b[3][1]) : printf("%s", (char*)b[3][1])), b = b[3][-1];
  printf(")\n");
  Green(OS);
}
N(term) {
  const char *t = ο[τ + 2];
  const char *s = ωCyan[1];
  long length   = ωCyan[2];
  long pos      = ωCyan[3];
  if (pos < length && s[pos] == t[0])
    οTomato(Tomato, t), οCyan(Cyan, s, length, pos + 1), Green(OS);
  else
    Blue(OS);
}
N(s) { Green(OS); }
N(b) { term(OS); }
N(a) { term(OS); }
N(t) { term(OS); }
#include "sisa.h"
N(programS) {
  B D(s) T(prn) _;
  D(s) _;
  B T(b) O _;
  B D(s) T(a) O _;
  B D(s) T(t) O _;
  οCyan(Cyan, "bat", 3, 0), gani(OS);
}
void ti_init(void);
N(programAB);
N(programExpr);
N(programSs);
N(program_isamntpwab);
int main(int argc, char **argv) { ti_init();
  long *root = R(0, zero, 0);
  long *boot = R(0, zero, 0);
  long ram[0x10000];
  long *ο = ram + sizeof(ram) / sizeof(*ram) / 2;
  long **β = (long *[]){root, root, root, root};
  long **α = (long *[]){boot, boot, boot, boot};
  long **ω = (long *[]){boot, boot, boot, boot};
  long τ;
  long σ = τ = 512;
  long ρ = 2;
  long δ = 1;
  long ν = 1;
  οOlive(Yellow), program_isamntpwab(OS);
}
