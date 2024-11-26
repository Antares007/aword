#include "../sophis.h"
#include "../sisa.h"
N(gani);
S(s) { Green(OS); }
S(np) { Green(OS); }
S(vp) { Green(OS); }
S(pp) { Green(OS); }
S(noun) { Green(OS); }
S(verb) { Green(OS); }
S(prep) { Green(OS); }
N(program_isamntpwab) {
  begin tword(s) end nl;
  name(s) nl;                             //  s
    tab tword(np) tword(vp) dot nl;       //      ::= np vp
    tab tword(s) tword(pp) dot nl;        //        | s pp
  name(np) nl;                            //  np
    tab tword(noun) dot nl;               //      ::= noun
    tab tword("det") tword(noun) dot nl;  //        | det noun
    tab tword(np) tword(pp) dot nl;       //        | np pp
  name(pp) nl;                            //  pp
    tab tword(prep) tword(np) dot nl;     //      ::= prep np
  name(vp) nl;                            //  vp
    tab tword(verb) tword(np) dot nl;     //      ::= verb np
  name("det") nl;                         //  det
    tab aword("a") dot nl;                //      ::= ’a’
    tab aword("t") dot nl;                //        | ’t’
  name(noun) nl;                          //  noun
    tab aword("i") dot nl;                //      ::= ’i’
    tab aword("m") dot nl;                //        | ’m’
    tab aword("p") dot nl;                //        | ’p’
    tab aword("b") dot nl;                //        | ’b’
  name(verb) nl;                          //  verb
    tab aword("s") dot nl;                //      ::= ’s’
  name(prep) nl;                          //  prep
    tab aword("n") dot nl;                //      ::= ’n’
    tab aword("w") dot nl;                //        | ’w’
  οBlue(Blue, "isamntpwab", 10, 0), gani(OS);
}

