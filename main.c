// clang-format off
#include "main.h"
N(sdb       );
N(Yellow    ) __attribute__((noinline));
N(Red       ) __attribute__((noinline));
N(Green     ) __attribute__((noinline));
N(Blue      ) __attribute__((noinline));

N(Red       ) { sdb(OS), ((n_t *)β[ρRed   ])[0](o, β[ρRed   ][-1], α, τ, σ, 3, +1, ν); }
N(Yellow    ) { sdb(OS), ((n_t *)β[ρYellow])[0](o, β[ρYellow][-1], α, τ, σ, 2, +1, ν); }
N(Green     ) { sdb(OS), ((n_t *)β[ρGreen ])[0](o, β[ρGreen ][-1], α, τ, σ, 1, +1, ν); }
N(Blue      ) { sdb(OS), ((n_t *)β[ρBlue  ])[0](o, β[ρBlue  ][-1], α, τ, σ, 0, +1, ν); }

N(Maroon    ) { sdb(OS), ((n_t *)α[ρRed   ])[0](o, β, α[ρRed   ][-1], τ, σ, 3, -1, ν); }
N(Olive     ) { sdb(OS), ((n_t *)α[ρYellow])[0](o, β, α[ρYellow][-1], τ, σ, 2, -1, ν); }
N(Lime      ) { sdb(OS), ((n_t *)α[ρGreen ])[0](o, β, α[ρGreen ][-1], τ, σ, 1, -1, ν); }
N(Navy      ) { sdb(OS), ((n_t *)α[ρBlue  ])[0](o, β, α[ρBlue  ][-1], τ, σ, 0, -1, ν); }

N(Olive_Gor ) { ν = 0, Olive(OS); }
N(Olive_God ) { ν = 1, Olive(OS); }
N(Green_God ) { ν = 1, Green(OS); }
N(Red_God   ) { ν = 1, Red(OS); }

S(Yellow_G1 ) {    Yellow(o, β[ρYellow][-1], α, τ, σ, ρ, δ, ν); }
N(Yellow_Gor) { ν = 0, Yellow(OS); }
N(Yellow_God) { ν = 1, Yellow(OS); }
N(Yellow_Got) { ν = 2, Yellow(OS); }
N(Yellow_NAO) { ((n_t *)β[ρYellow])[ν](o, β[ρYellow][-1], α, τ, σ, ρ, δ, ν); }
N(Yellow_Not) { static n_t nars[] = {Yellow_G1, Yellow_G1, Yellow}; nars[ν](OS); }
N(Yellow_And) { static n_t nars[] = {Yellow_G1, Yellow, Yellow_G1}; nars[ν](OS); }
N(Yellow_Or ) { static n_t nars[] = {Yellow, Yellow_G1, Yellow_G1}; nars[ν](OS); }

N(Yellow_n  ) { τ -= 1 << Σ, Yellow(OS); }
N(Yellow_e  ) { τ += 11,     Yellow(OS); }
N(Yellow_s  ) { τ += 1 << Σ, Yellow(OS); }
N(Yellow_w  ) { τ -= 11,     Yellow(OS); }

N(Green_n   ) { τ -= 1 << Σ, Green(OS); }
N(Green_e   ) { τ += 11,     Green(OS); }
N(Green_s   ) { τ += 1 << Σ, Green(OS); }
N(Green_w   ) { τ -= 11,     Green(OS); }

N(Red_n   ) { τ -= 1 << Σ, Red(OS); }
N(Red_e   ) { τ += 11,     Red(OS); }
N(Red_s   ) { τ += 1 << Σ, Red(OS); }
N(Red_w   ) { τ -= 11,     Red(OS); }

extern const char *rays[];
N(zero      ) { printf("The %s(%s)!\n", rays[(ρ + 1) + 5], ν == 2 ? "not" : ν ? "and" : "or"); }
N(ani       );
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
  begin Sword("123456789") print nop end nl;
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
  ani(OS);
}
N(programTritab) {
  begin Sword("triTAB") print nop end nl;
  name("triTAB") nl;
    tab Sword("TAB") Sword("TAB") Sword("TAB") dot nl;
  name("TAB") nl;
    tab Tword("T") dot nl;
    tab Tword("A") dot nl;
    tab Tword("B") dot nl;
  οBlue(Blue, "TAB", 3, 0), ani(OS);
}
N(programS) {
  begin Sword("S") print nop end nl;
  name("S") nl;
    tab Tword("b") dot nl;
    tab Sword("S") Tword("a") dot nl;
    tab Sword("S") Tword("t") dot nl;
  οBlue(Blue, "batat", 5, 0), ani(OS);
}
N(programSs) {
  begin Sword("Ss") print nop end nl;
  name("Ss") nl;
    tab dot nl;
    tab Tword("s") Sword("Ss") Sword("Ss") dot nl;
    tab Tword("s") Sword("Ss") Sword("Ss") dot nl;
  οBlue(Blue, "ss", 2, 0), ani(OS);
}
N(programAB) {
  begin Sword("A") print nop end nl;
  name("A") nl;
    tab Tword("o") dot nl;
    tab Sword("B") Tword("a") dot nl;
  name("B") nl;
    tab Tword("y") dot nl;
    tab Sword("A") Tword("b") dot nl;
  οBlue(Blue, "oba", 3, 0), ani(OS);
}
N(program_aText) {
  begin put("t") put("a") put("b") print end nl;
  ani(OS);
}
N(program_bat) {
  begin Sword("s") print end nl;
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

  οBlue(Blue, "isamntpwab", 10, 0), ani(OS);
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
  programS(OS);
}
