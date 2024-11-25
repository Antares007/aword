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
N(programSs) {
  begin tword("Ss") print end nl;
  name("Ss") nl;
    tab dot nl;
    tab aword("s") tword("Ss") tword("Ss") dot nl;
    tab aword("s") tword("Ss") tword("Ss") dot nl;
  οBlue(Blue, "ss", 2, 0), book_of_gani_e(OS);
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
  οOlive(Yellow), programSs(OS);
}
