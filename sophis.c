// clang-format off
#include "sophis.h"
#include "colours_fly.h"

N(Red         ) { n_t narg = β[3][0]; β = β[3][-1]; sdb(OS), narg(OS); }
N(Yellow      ) { n_t narg = β[2][0]; β = β[2][-1]; sdb(OS), narg(OS); }
N(Green       ) { n_t narg = β[1][0]; β = β[1][-1]; sdb(OS), narg(OS); }
N(Blue        ) { n_t narg = β[0][0]; β = β[0][-1]; sdb(OS), narg(OS); }

N(Maroon      ) { n_t narg = α[3][0]; α = α[3][-1]; sdb(OS), narg(OS); }
N(Olive       ) { n_t narg = α[2][0]; α = α[2][-1]; sdb(OS), narg(OS); }
N(Lime        ) { n_t narg = α[1][0]; α = α[1][-1]; sdb(OS), narg(OS); }
N(Navy        ) { n_t narg = α[0][0]; α = α[0][-1]; sdb(OS), narg(OS); }

N(Red_Red     ) { ν = 2, Red(OS); }
N(Red_Green   ) { ν = 1, Red(OS); }
N(Red_Blue    ) { ν = 0, Red(OS); }
N(Red_aradani ) { n_t narg = β[3][ν]; β = β[3][-1]; sdb(OS), narg(OS); }

extern const char *rays[];
N(zero) { printf("The %s end!\n", rays[(ρ + 1) + 5]); }

#define b    ο[σ] = 1,                σ += 11,
#define T(v) ο[σ] = 2, ο[σ + 1] = v,  σ += 11,
#define D(v) ο[σ] = 3, ο[σ + 1] = #v, σ += 11,
#define O    ο[σ] = 4,                σ += 11,
#define _    σ = ((σ >> Σ) + 1) << Σ
N(gani);
// S
// b.
// S a.
// S t.
N(programS) {
  b D(S) _;
  D(S) _;
  b T("b") O _;
  b D(S) T("a") O _;
  b D(S) T("t") O _;
  οBlue(Blue, "bataata", 7, 0), gani(OS);
}
N(program_isamntpwab) {
  b D(s) _;
  D(s) _;               //  s
  b D(np) D(vp) O _;    //      ::= np vp
  b D(s) D(pp) O _;     //        | s pp
  D(np) _;              //  np
  b D(noun) O _;        //      ::= noun
  b D(det) D(noun) O _; //        | det noun
  b D(np) D(pp) O _;    //        | np pp
  D(pp) _;              //  pp
  b D(prep) D(np) O _;  //      ::= prep np
  D(vp) _;              //  vp
  b D(verb) D(np) O _;  //      ::= verb np
  D(det) _;             //  det
  b T("a") O _;         //      ::= ’a’
  b T("t") O _;         //        | ’t’
  D(noun) _;            //  noun
  b T("i") O _;         //      ::= ’i’
  b T("m") O _;         //        | ’m’
  b T("p") O _;         //        | ’p’
  b T("b") O _;         //        | ’b’
  D(verb) _;            //  verb
  b T("s") O _;         //      ::= ’s’
  D(prep) _;            //  prep
  b T("n") O _;         //      ::= ’n’
  b T("w") O _;         //        | ’w’
  οBlue(Blue, "isamntpwab", 10, 0), gani(OS);
}
void ti_init(void);
int main(int argc, char **argv) {
  ti_init();
  long *cap = R(0, zero, 0);
  long ram[0x10000];
  long *ο = ram + sizeof(ram) / sizeof(*ram) / 2;
  long **β = (long *[]){cap, cap, cap, cap};
  long **α = (long *[]){cap, cap, cap, cap};
  long **ω = (long *[]){cap, cap, cap, cap};
  long τ;
  long σ = τ = 512;
  long ρ = 2;
  long δ = 1;
  long ν = 1;
  programS(OS);
}

