#include "../sophis.h"
#include "../sisa.h"
N(gani);
S(np) { Green(OS); }
S(vp) { Green(OS); }
S(pp) { Green(OS); }
S(det) { Green(OS); }
S(noun) { Green(OS); }
S(verb) { Green(OS); }
S(prep) { Green(OS); }
N(term);
S(i) { term(OS); }
S(s) { if(ο[τ] == 3) Green(OS); else term(OS); }
S(a) { term(OS); }
S(m) { term(OS); }
S(n) { term(OS); }
S(t) { term(OS); }
S(p) { term(OS); }
S(w) { term(OS); }
S(b) { term(OS); }
N(prn);
N(program_isamntpwab) {
  B D(s) T(prn) _;
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

