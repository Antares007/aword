#include "../sophis.h"
#include "../sisa.h"
S(ab) { Green(OS); }
S(bo) { Green(OS); }
N(gani);
N(prn);
N(term);
S(a) { term(OS); }
S(b) { term(OS); }
S(o) { term(OS); }
S(y) { term(OS); }
N(programAB) {
  B D(ab) T(prn) _;

  D(ab) _;
  B T(o) O _;
  B D(bo) T(a) O _;

  D(bo) _;
  B T(y) O _;
  B D(ab) T(b) O _;

  οCyan(Cyan, "oba", 3, 0), gani(OS);
}

