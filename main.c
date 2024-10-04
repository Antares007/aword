#include "main.h"
N(ti_debug);
N(Go) __attribute__((noinline));

N(Go) { ti_debug(OS), ((n_t *)β[ρ])[0](o, β[ρ][-1], τ, σ, ρ, δ, ν); }
N(Gor) { ν = 0, Go(OS); }
N(God) { ν = 1, Go(OS); }
N(Got) { ν = 2, Go(OS); }
N(NotAndOr) { ((n_t *)β[ρ])[ν](o, β[ρ][-1], τ, σ, ρ, δ, ν); }

N(go_ns) { τ = τ + (δ << Σ), Go(OS); }
N(go_we) { τ = τ + 11 * δ, Go(OS); }
N(go_n) { δ = -1, go_ns(OS); }
N(go_e) { δ = +1, go_we(OS); }
N(go_s) { δ = +1, go_ns(OS); }
N(go_w) { δ = -1, go_we(OS); }

#include <stdio.h>
#define P printf("%s\n", __func__)
N(done) { printf("the %s!\n", ν == 2 ? "not" : ν ? "and" : "or"); }
N(A23) { printf("%s %s\n", ((char **)β[ρ])[1], ((char **)β[ρ])[2]), Go(OS); }
N(aaa) { P, Go(OS); }
N(sss) { P, Go(OS); }
N(ooo) { P, Go(OS); }
N(a) { P, Go(OS); }
N(s) { P, Go(OS); }
N(o) { P, Go(OS); }

N(ani);
N(ani) {
  is_a_book_of( //
                //
  );
}

extern int strcmp(const char *, const char *);
S(match   ) { (strcmp(o[τ + 1], β[0][1]) ? Gor : God)(OS); }

N(rise);
N(rise) {
  is_a_book_of(
  )
}

N(dive);
S(dive_s    ) { OB(3, dive), OB(3, go_s), God(OS); }
S(dive_name ) {
  OB(3, dive_s, Go, Go), OB(3, NotAndOr);
  OB(3, match), God(OS);
}
N(dive) {
  is_a_book_of(
    [name] = dive_name, //
    [tab] = dive_s, //
  )
}

#include "sisa.h"
void ti_init(void);
int main(int argc, char **argv) {
  ti_init();
  long *end = R(0, done);
  long ram[0x10000];
  long *o = ram + sizeof(ram) / sizeof(*ram) / 2;
  long **β = (long *[]){end, end, end, end};
  long τ = 0;
  long σ = 0;
  long ρ = 3;
  long δ = 1;
  long ν = 2;

  name("tab") nl;
  tab put("t") dot nl;
  tab put("a") dot nl;
  tab put("b") dot nl;
  name("main") nl;
  tab nop tword("tab") print dot nl;
  OB(3, ani),
  OB(0, Go, "main"), dive(OS);
}
