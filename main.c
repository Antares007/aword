// clang-format off
#include "main.h"
N(sdb       );
N(Yellow    ) __attribute__((noinline));
N(Red       ) __attribute__((noinline));
N(Green     ) __attribute__((noinline));
N(Blue      ) __attribute__((noinline));

N(Red       ) { ρ = ρRed   , δ = +1, sdb(OS), ((n_t *)β[ρ])[0](o, β[ρ][-1], α, ω, τ, σ, ρ, δ, ν); }
N(Yellow    ) { ρ = ρYellow, δ = +1, sdb(OS), ((n_t *)β[ρ])[0](o, β[ρ][-1], α, ω, τ, σ, ρ, δ, ν); }
N(Green     ) { ρ = ρGreen , δ = +1, sdb(OS), ((n_t *)β[ρ])[0](o, β[ρ][-1], α, ω, τ, σ, ρ, δ, ν); }
N(Blue      ) { ρ = ρBlue  , δ = +1, sdb(OS), ((n_t *)β[ρ])[0](o, β[ρ][-1], α, ω, τ, σ, ρ, δ, ν); }
N(Navy      ) { ρ = ρBlue  , δ = -1, sdb(OS), ((n_t *)α[ρ])[0](o, β, α[ρ][-1], ω, τ, σ, ρ, δ, ν); }
N(Lime      ) { ρ = ρGreen , δ = -1, sdb(OS), ((n_t *)α[ρ])[0](o, β, α[ρ][-1], ω, τ, σ, ρ, δ, ν); }
N(Olive     ) { ρ = ρYellow, δ = -1, sdb(OS), ((n_t *)α[ρ])[0](o, β, α[ρ][-1], ω, τ, σ, ρ, δ, ν); }
N(Maroon    ) { ρ = ρRed   , δ = -1, sdb(OS), ((n_t *)α[ρ])[0](o, β, α[ρ][-1], ω, τ, σ, ρ, δ, ν); }

N(Yellow_Blue ) { ν = 0, Yellow(OS); }
N(Yellow_Green) { ν = 1, Yellow(OS); }
N(Yellow_Red  ) { ν = 2, Yellow(OS); }
N(Yellow_NAO  ) { ((n_t *)β[ρYellow ])[ν](o, β[ρYellow][-1], α, ω, τ, σ, ρ, δ, ν); }
N(Red_Blue    ) { ν = 0, Red(OS); }                              
N(Red_Green   ) { ν = 1, Red(OS); }                              
N(Red_Red     ) { ν = 2, Red(OS); }                              
N(Red_NAO     ) { ((n_t *)β[ρRed    ])[ν](o, β[ρRed   ][-1], α, ω, τ, σ, ρ, δ, ν); }
N(Green_Blue  ) { ν = 0, Green(OS); }                            
N(Green_Green ) { ν = 1, Green(OS); }                            
N(Green_Red   ) { ν = 2, Green(OS); }                            
N(Green_NAO   ) { ((n_t *)β[ρGreen  ])[ν](o, β[ρGreen ][-1], α, ω, τ, σ, ρ, δ, ν); }
N(Blue_Blue   ) { ν = 0, Blue(OS); }                             
N(Blue_Green  ) { ν = 1, Blue(OS); }                             
N(Blue_Red    ) { ν = 2, Blue(OS); }                             
N(Blue_NAO    ) { ((n_t *)β[ρBlue   ])[ν](o, β[ρBlue  ][-1], α, ω, τ, σ, ρ, δ, ν); }

extern const char *rays[];
N(zero      ) { printf("The %s(%s)!\n", rays[(ρ + 1) + 5], ν == 2 ? "not" : ν ? "and" : "or"); }
N(book_of_gani_e);
N(book_of_dive_n);
#define begin     o[σ] = begin,               σ += 11,
#define tword(v)  o[σ] = tword, o[σ + 1] = v, σ += 11,
#define name(v)   o[σ] = name,  o[σ + 1] = v, σ += 11,
#define Put(v)    o[σ] = put,   o[σ + 1] = v, σ += 11,
#define aword(v)  o[σ] = aword, o[σ + 1] = v, σ += 11,
#define Rword(v)  o[σ] = rword, o[σ + 1] = v, σ += 11,
#define print     o[σ] = print,               σ += 11,
#define tab       o[σ] = tab,                 σ += 11,
#define nop       o[σ] = nop,                 σ += 11,
#define dot       o[σ] = dot,                 σ += 11,
#define end       o[σ] = end,                 σ += 11,
#define nl        o[σ] = nl,                  σ = ((σ >> Σ) + 1) << Σ
N(programTritab) {
  begin tword("triTAB") print end nl;
  name("triTAB") nl;
    tab tword("TAB") tword("TAB") tword("TAB") dot nl;
  name("TAB") nl;
    tab aword("T") dot nl;
    tab aword("A") dot nl;
    tab aword("B") dot nl;
  οBlue(Blue, "TAB", 3, 0), book_of_gani_e(OS);
}
N(programS) {
  begin tword("S") print end nl;
  name("S") nl;
    tab aword("b") dot nl;
    tab tword("S") aword("a") dot nl;
    tab tword("S") aword("t") dot nl;
  οBlue(Blue, "bat", 3, 0), book_of_gani_e(OS);
}
N(programAB) {
  begin tword("A") print end nl;
  name("A") nl;
    tab aword("o") dot nl;
    tab tword("B") aword("a") dot nl;
  name("B") nl;
    tab aword("y") dot nl;
    tab tword("A") aword("b") dot nl;
  οBlue(Blue, "oba", 3, 0), book_of_gani_e(OS);
}
N(program_aText) {
  begin Put("t") Put("a") Put("b") print end nl;
  book_of_gani_e(OS);
}
N(program_isamntpwab) {
  begin tword("s") print end nl;
  name("s") nl;                             //  s
    tab tword("np") tword("vp") dot nl;     //      ::= np vp
    tab tword("s") tword("pp") dot nl;      //        | s pp
  name("np") nl;                            //  np
    tab tword("noun") dot nl;               //      ::= noun
    tab tword("det") tword("noun") dot nl;  //        | det noun
    tab tword("np") tword("pp") dot nl;     //        | np pp
  name("pp") nl;                            //  pp
    tab tword("prep") tword("np") dot nl;   //      ::= prep np
  name("vp") nl;                            //  vp
    tab tword("verb") tword("np") dot nl;   //      ::= verb np
  name("det") nl;                           //  det
    tab aword("a") dot nl;                  //      ::= ’a’
    tab aword("t") dot nl;                  //        | ’t’
  name("noun") nl;                          //  noun
    tab aword("i") dot nl;                  //      ::= ’i’
    tab aword("m") dot nl;                  //        | ’m’
    tab aword("p") dot nl;                  //        | ’p’
    tab aword("b") dot nl;                  //        | ’b’
  name("verb") nl;                          //  verb
    tab aword("s") dot nl;                  //      ::= ’s’
  name("prep") nl;                          //  prep
    tab aword("n") dot nl;                  //      ::= ’n’
    tab aword("w") dot nl;                  //        | ’w’
  οBlue(Blue, "isamntpwab", 10, 0), book_of_gani_e(OS);
}
N(plus  ) { long right = ω[3][0]; ω = ω[3][-1];
            long left = ω[3][0]; ω = ω[3][-1]; 
            οTomato(left + right), book_of_gani_e(OS); }
N(minus ) { long right = ω[3][0]; ω = ω[3][-1];
            long left = ω[3][0]; ω = ω[3][-1]; 
            οTomato(left - right), book_of_gani_e(OS); }
N(mul   ) { long right = ω[3][0]; ω = ω[3][-1];
            long left = ω[3][0]; ω = ω[3][-1]; 
            οTomato(left * right), book_of_gani_e(OS); }
N(div   ) { long right = ω[3][0]; ω = ω[3][-1];
            long left = ω[3][0]; ω = ω[3][-1]; 
            οTomato(left / right), book_of_gani_e(OS); }
N(programExpr) {
  begin tword("E") print end nl;
  name("E") nl;
    tab tword("E") aword("+") tword("E") Rword(plus) dot nl;
    tab tword("E") aword("-") tword("E") Rword(minus) dot nl;
    tab tword("E") aword("*") tword("E") Rword(mul) dot nl;
    tab tword("E") aword("/") tword("E") Rword(div) dot nl;
    tab aword("(") tword("E") aword(")") dot nl;
    tab aword("2") Put(2) dot nl;
    tab aword("3") Put(3) dot nl;
    tab aword("8") Put(8) dot nl;
    tab aword("9") Put(9) dot nl;
  οBlue(Blue, "(2+3)*(8+9)", 11, 0), book_of_gani_e(OS);
}
N(program123) {
  begin tword("programs") print end nl;
  name("programs") nl;
    tab aword("d") tword("d") dot nl;
    tab aword("E") tword("E") dot nl;

  name("d") nl;
    tab aword("1") dot aword("2") dot aword("3") dot tword("s") dot  nl;

  name("s") nl;
    tab aword("6") dot nl;
    tab aword("5") dot nl;

  name("E") nl;
    tab tword("E") aword("+") tword("E") Rword(plus) dot nl;
    tab tword("E") aword("-") tword("E") Rword(minus) dot nl;
    tab tword("E") aword("*") tword("E") Rword(mul) dot nl;
    tab tword("E") aword("/") tword("E") Rword(div) dot nl;
    tab aword("(") tword("E") aword(")") dot nl;
    tab aword("2") Put(2) dot nl;
    tab aword("3") Put(3) dot nl;
    tab aword("8") Put(8) dot nl;
    tab aword("9") Put(9) dot nl;

  οBlue(Blue, "2+3", 3, 0), book_of_gani_e(OS);
}
void ti_init(void);
int main(int argc, char **argv) { ti_init();
  long *root = R(0, zero, 0);
  long *boot = R(0, zero, 0);
  long ram[0x10000];
  long *o = ram + sizeof(ram) / sizeof(*ram) / 2;
  long **β = (long *[]){root, root, root, root};
  long **α = (long *[]){boot, boot, boot, boot};
  long **ω = (long *[]){boot, boot, boot, boot};
  long τ;
  long σ = τ = 512;
  long ρ = 2;
  long δ = 1;
  long ν = 1;
  οOlive(Yellow), programS(OS);
}
