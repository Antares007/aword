#include "../sophis.h"
#include "../sisa.h"
N(dot_simbol);
S(E) { dot_simbol(OS); }
N(dot_terminal);
#define Ts(v) ο[σ] = 2, ο[σ + 1] = dot_terminal,  ο[σ + 2] = v, σ += 11,
N(dot_begin);
N(dot_end);
N(gani);
N(programExpr) {
  B T(dot_begin) D(E) T(dot_end) _;
  D(E) _;
  B D(E) Ts("+") D(E) O _;
  B D(E) Ts("-") D(E) O _;
  B D(E) Ts("*") D(E) O _;
  B D(E) Ts("/") D(E) O _;
  B Ts("(") D(E) Ts(")") O _;
  B Ts("2") O _;
  B Ts("3") O _;
  B Ts("8") O _;
  B Ts("9") O _;
  οCyan(Cyan, "2+3*8+9", 7, 0), gani(OS);
}

