#include "../sophis.h"
#include "../sisa.h"

N(dot_simbol);
N(Ss) { dot_simbol(OS); }

N(dot_terminal);
S(s) { dot_terminal(OS); }

N(dot_epsilon);
S(epsilon) { dot_epsilon(OS); }

N(gani);
N(dot_begin);
N(dot_end);
N(programSs) {
  B T(dot_begin) D(Ss) T(dot_end) _;
  D(Ss) _;
  B T(epsilon) O _;
  B T(s) D(Ss) D(Ss) O _;
  B T(s) D(Ss) D(Ss) O _;
  οCyan(Cyan, "sss", 3, 0), gani(OS);
}

