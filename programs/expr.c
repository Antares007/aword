#include "../sophis.h"
#include "../sisa.h"
N(gani);

N(plus  ) { long right = ω[3][0]; ω = ω[3][-1];
            long left = ω[3][0]; ω = ω[3][-1]; 
            οTomato(left + right), gani(OS); }
N(minus ) { long right = ω[3][0]; ω = ω[3][-1];
            long left = ω[3][0]; ω = ω[3][-1]; 
            οTomato(left - right), gani(OS); }
N(mul   ) { long right = ω[3][0]; ω = ω[3][-1];
            long left = ω[3][0]; ω = ω[3][-1]; 
            οTomato(left * right), gani(OS); }
N(div   ) { long right = ω[3][0]; ω = ω[3][-1];
            long left = ω[3][0]; ω = ω[3][-1]; 
            οTomato(left / right), gani(OS); }
S(E) { Green(OS); }
N(programExpr) {
  begin tword(E) print end nl;
  name(E) nl;
    tab tword(E) aword("+") tword(E) Rword(plus) dot nl;
    tab tword(E) aword("-") tword(E) Rword(minus) dot nl;
    tab tword(E) aword("*") tword(E) Rword(mul) dot nl;
    tab tword(E) aword("/") tword(E) Rword(div) dot nl;
    tab aword("(") tword(E) aword(")") dot nl;
    tab aword("2") Put(2) dot nl;
    tab aword("3") Put(3) dot nl;
    tab aword("8") Put(8) dot nl;
    tab aword("9") Put(9) dot nl;
  οBlue(Blue, "(2+3)*(8+9)", 11, 0), gani(OS);
}

