#include "../sophis.h"
#include "../sisa.h"
N(dot_simbol);
S(np) { dot_simbol(OS); }
S(vp) { dot_simbol(OS); }
S(pp) { dot_simbol(OS); }
S(det) { dot_simbol(OS); }
S(noun) { dot_simbol(OS); }
S(verb) { dot_simbol(OS); }
S(prep) { dot_simbol(OS); }

N(dot_terminal);
S(i) { dot_terminal(OS); }
S(s) { if(ο[τ] == 3) dot_simbol(OS); else dot_terminal(OS); }
S(a) { dot_terminal(OS); }
S(m) { dot_terminal(OS); }
S(n) { dot_terminal(OS); }
S(t) { dot_terminal(OS); }
S(p) { dot_terminal(OS); }
S(w) { dot_terminal(OS); }
S(b) { dot_terminal(OS); }

N(dot_begin);
N(dot_end);
N(gani);
N(program_isamntpwab) {
  B T(dot_begin) D(s) T(dot_end) _;
  D(s) _;               //  s
  B D(np) D(vp) O _;    //      ::= np vp
  B D(s) D(pp) O _;     //        | s pp
  D(np) _;              //  np
  B D(noun) O _;        //      ::= noun
  B D(det) D(noun) O _; //        | det noun
  B D(np) D(pp) O _;    //        | np pp
  D(pp) _;              //  pp
  B D(prep) D(np) O _;  //      ::= prep np
  D(vp) _;              //  vp
  B D(verb) D(np) O _;  //      ::= verb np
  D(det) _;             //  det
  B T(a) O _;           //      ::= ’a’
  B T(t) O _;           //        | ’t’
  D(noun) _;            //  noun
  B T(i) O _;           //      ::= ’i’
  B T(m) O _;           //        | ’m’
  B T(p) O _;           //        | ’p’
  B T(b) O _;           //        | ’b’
  D(verb) _;            //  verb
  B T(s) O _;           //      ::= ’s’
  D(prep) _;            //  prep
  B T(n) O _;           //      ::= ’n’
  B T(w) O _;           //        | ’w’
  οCyan(Cyan, "isamntpwab", 10, 0), gani(OS);
}

