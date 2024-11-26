#include "../sophis.h"
#include "../sisa.h"
N(gani);
#undef T
N(term);
#define T(v) ο[σ] = 2, ο[σ + 1] = term,  ο[σ + 2] = v, σ += 11,
S(E) { Green(OS); }
N(programExpr) {
  B D(E) _;
  D(E) _;
  B D(E) T("+") D(E) O _;
  B D(E) T("-") D(E) O _;
  B D(E) T("*") D(E) O _;
  B D(E) T("/") D(E) O _;
  B T("(") D(E) T(")") O _;
  B T("2") O _;
  B T("3") O _;
  B T("8") O _;
  B T("9") O _;
  οCyan(Cyan, "(2+3)*(8+9)", 11, 0), gani(OS);
}

