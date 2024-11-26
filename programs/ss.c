#include "../sophis.h"
#include "../sisa.h"

N(gani);
N(term);
N(prn);
N(Ss) { Green(OS); }
S(s) { term(OS); }

N(programSs) {
  B D(Ss) T(prn) _;
  D(Ss) _;
  B O _;
  B T(s) D(Ss) D(Ss) O _;
  B T(s) D(Ss) D(Ss) O _;
  οCyan(Cyan, "ss", 2, 0), gani(OS);
}

