#include "../sophis.h"
#include "../sisa.h"
N(dot_simbol);
S(ab) { dot_simbol(OS); }
S(bo) { dot_simbol(OS); }
N(gani);

N(dot_terminal);
S(a) { dot_terminal(OS); }
S(b) { dot_terminal(OS); }
S(o) { dot_terminal(OS); }
S(y) { dot_terminal(OS); }
N(dot_begin);
N(dot_end);
N(programAB) {
  B T(dot_begin) D(ab) T(dot_end) _;

  D(ab) _;
  B T(o) O _;
  B D(bo) T(a) O _;

  D(bo) _;
  B T(y) O _;
  B D(ab) T(b) O _;

  οCyan(Cyan, "obababa", 7, 0), gani(OS);
}

