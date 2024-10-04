#include "main.h"
N(Go) __attribute__((noinline));

N(ti_debug);
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

N(end) { printf("the %s!\n", ν == 2 ? "not" : ν ? "and" : "or"); }
N(ani);
N(dive);
#include "sisa.h"
void ti_init(void);
int main(int argc, char **argv) {
  ti_init();
  long ram[0x10000];
  long *o = ram + sizeof(ram) / sizeof(*ram) / 2;
  long τ = 0;
  long σ = 0;
  long ρ = 3;
  long δ = 1;
  long ν = 2;
  long *begin = R(0, end);
  long **β = (long *[]){begin, begin, begin, begin};

  name("tab") nl;
  tab put("t") dot nl;
  tab put("a") dot nl;
  tab put("b") dot nl;
  name("main") nl;
  tab nop tword("tab") print dot nl;
  OB(0, Go, "main"), OB(3, ani), dive(OS);
}
