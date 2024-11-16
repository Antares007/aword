// clang-format off
#include "main.h"
N(sdb       );
N(Yellow    ) __attribute__((noinline));
N(Red       ) __attribute__((noinline));
N(Green     ) __attribute__((noinline));
N(Blue      ) __attribute__((noinline));

N(Red       ) { ρ = 3, δ = +1, sdb(OS), ((n_t *)β[ρRed   ])[0](o, β[ρRed   ][-1], α, τ, σ, ρ, δ, ν); }
N(Yellow    ) { ρ = 2, δ = +1, sdb(OS), ((n_t *)β[ρYellow])[0](o, β[ρYellow][-1], α, τ, σ, ρ, δ, ν); }
N(Green     ) { ρ = 1, δ = +1, sdb(OS), ((n_t *)β[ρGreen ])[0](o, β[ρGreen ][-1], α, τ, σ, ρ, δ, ν); }
N(Blue      ) { ρ = 0, δ = +1, sdb(OS), ((n_t *)β[ρBlue  ])[0](o, β[ρBlue  ][-1], α, τ, σ, ρ, δ, ν); }

N(Maroon    ) { ρ = 3, δ = -1, sdb(OS), ((n_t *)α[ρRed   ])[0](o, β, α[ρRed   ][-1], τ, σ, ρ, δ, ν); }
N(Olive     ) { ρ = 2, δ = -1, sdb(OS), ((n_t *)α[ρYellow])[0](o, β, α[ρYellow][-1], τ, σ, ρ, δ, ν); }
N(Lime      ) { ρ = 1, δ = -1, sdb(OS), ((n_t *)α[ρGreen ])[0](o, β, α[ρGreen ][-1], τ, σ, ρ, δ, ν); }
N(Navy      ) { ρ = 0, δ = -1, sdb(OS), ((n_t *)α[ρBlue  ])[0](o, β, α[ρBlue  ][-1], τ, σ, ρ, δ, ν); }

N(Olive_Gor ) { ν = 0, Olive(OS); }
N(Olive_God ) { ν = 1, Olive(OS); }
N(Green_God ) { ν = 1, Green(OS); }
N(  Red_Gor ) { ν = 0,   Red(OS); }
N(  Red_God ) { ν = 1,   Red(OS); }

N(Yellow_Gor) { ν = 0, Yellow(OS); }
N(Yellow_God) { ν = 1, Yellow(OS); }
N(Yellow_Got) { ν = 2, Yellow(OS); }
N(Yellow_NAO) { ((n_t *)β[ρYellow])[ν](o, β[ρYellow][-1], α, τ, σ, ρ, δ, ν); }

N(Yellow_n  ) { τ -= 1 << Σ, Yellow(OS); }
N(Yellow_e  ) { τ += 11,     Yellow(OS); }
N(Yellow_s  ) { τ += 1 << Σ, Yellow(OS); }
N(Yellow_w  ) { τ -= 11,     Yellow(OS); }

N(Green_n   ) { τ -= 1 << Σ, Green(OS); }
N(Green_e   ) { τ += 11,     Green(OS); }
N(Green_s   ) { τ += 1 << Σ, Green(OS); }
N(Green_w   ) { τ -= 11,     Green(OS); }

N(Red_n     ) { τ -= 1 << Σ, Red(OS); }
N(Red_e     ) { τ += 11,     Red(OS); }
N(Red_s     ) { τ += 1 << Σ, Red(OS); }
N(Red_w     ) { τ -= 11,     Red(OS); }

N(Blue_n    ) { τ -= 1 << Σ, Blue(OS); }
N(Blue_e    ) { τ += 11,     Blue(OS); }
N(Blue_s    ) { τ += 1 << Σ, Blue(OS); }
N(Blue_w    ) { τ -= 11,     Blue(OS); }

extern const char *rays[];
N(zero      ) { printf("The %s(%s)!\n", rays[(ρ + 1) + 5], ν == 2 ? "not" : ν ? "and" : "or"); }
N(gani_e    );
N(dive      );
#define begin     o[σ] = begin,               σ += 11,
#define Sword(v)  o[σ] = sword, o[σ + 1] = v, σ += 11,
#define name(v)   o[σ] = name,  o[σ + 1] = v, σ += 11,
#define put(v)    o[σ] = put,   o[σ + 1] = v, σ += 11,
#define Tword(v)  o[σ] = tword, o[σ + 1] = v, σ += 11,
#define print     o[σ] = print,               σ += 11,
#define tab       o[σ] = tab,                 σ += 11,
#define nop       o[σ] = nop,                 σ += 11,
#define dot       o[σ] = dot,                 σ += 11,
#define end       o[σ] = end,                 σ += 11,
#define nl        o[σ] = nl,                  σ = ((σ >> Σ) + 1) << Σ
N(program123) {
  begin Sword("123456789") end nl;
  name("789") nl;
    tab put("7") dot nl;
    tab put("8") dot nl;
    tab put("9") dot nl;
  name("123456789") nl;
    tab Sword("123") Sword("456") Sword("789") dot nl;
  name("123") nl;
    tab put("1") dot nl;
    tab put("2") dot nl;
    tab put("3") dot nl;
  name("456") nl;
    tab put("4") dot nl;
    tab put("5") dot nl;
    tab put("6") dot nl;
  gani_e(OS);
}
N(programTritab) {
  begin Sword("triTAB") print nop end nl;
  name("triTAB") nl;
    tab Sword("TAB") Sword("TAB") Sword("TAB") dot nl;
  name("TAB") nl;
    tab Tword("T") dot nl;
    tab Tword("A") dot nl;
    tab Tword("B") dot nl;
  οBlue(Blue, "TAB", 3, 0), gani_e(OS);
}
N(programS) {
  begin Sword("S") end nl;
  name("s") nl;
    tab Sword("S") Sword("S") dot nl;
  name("S") nl;
    tab Tword("b") dot nl;
    tab Sword("S") Tword("a") dot nl;
    tab Sword("S") Tword("t") dot nl;
  οBlue(Blue, "bat", 3, 0), gani_e(OS);
}
N(programSs) {
  begin Sword("Ss") end nl;
  name("Ss") nl;
    tab dot nl;
    tab Tword("s") Sword("Ss") Sword("Ss") dot nl;
    tab Tword("s") Sword("Ss") Sword("Ss") dot nl;
  οBlue(Blue, "ss", 2, 0), gani_e(OS);
}
N(programAB) {
  begin Sword("A") end nl;
  name("A") nl;
    tab Tword("o") dot nl;
    tab Sword("B") Tword("a") dot nl;
  name("B") nl;
    tab Tword("y") dot nl;
    tab Sword("A") Tword("b") dot nl;
  οBlue(Blue, "obaaa", 5, 0), gani_e(OS);
}
N(program_aText) {
  begin put("t") put("a") put("b") print end nl;
  gani_e(OS);
}
N(program_isamntpwab) {
  begin Sword("s") end nl;
  name("s") nl;                             //  s
    tab Sword("np") Sword("vp") dot nl;     //      ::= np vp
    tab Sword("s") Sword("pp") dot nl;      //        | s pp
  name("np") nl;                            //  np
    tab Sword("noun") dot nl;               //      ::= noun
    tab Sword("det") Sword("noun") dot nl;  //        | det noun
    tab Sword("np") Sword("pp") dot nl;     //        | np pp
  name("pp") nl;                            //  pp
    tab Sword("prep") Sword("np") dot nl;   //      ::= prep np
  name("vp") nl;                            //  vp
    tab Sword("verb") Sword("np") dot nl;   //      ::= verb np
  name("det") nl;                           //  det
    tab Tword("a") dot nl;                  //      ::= ’a’
    tab Tword("t") dot nl;                  //        | ’t’
  name("noun") nl;                          //  noun
    tab Tword("i") dot nl;                  //      ::= ’i’
    tab Tword("m") dot nl;                  //        | ’m’
    tab Tword("p") dot nl;                  //        | ’p’
    tab Tword("b") dot nl;                  //        | ’b’
  name("verb") nl;                          //  verb
    tab Tword("s") dot nl;                  //      ::= ’s’
  name("prep") nl;                          //  prep
    tab Tword("n") dot nl;                  //      ::= ’n’
    tab Tword("w") dot nl;                  //        | ’w’

  οBlue(Blue, "isamntpwab", 10, 0), gani_e(OS);
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
  program_isamntpwab(OS);
}
