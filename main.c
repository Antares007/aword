#include "main.h"
N(Go) __attribute__((noinline));

N(ti_debug);
#define Peek(β) ((long**)(β))[ρ][-1]
N(Go) {
      ((n_t *)β[ρ])[0](o, β[ρ][-1], α, τ, σ, ρ, δ, ν);
}
N(G1) { Go(o, β[ρ][-1], α, τ, σ, ρ, δ, ν); }
N(Gor) { ν = 0, Go(OS); }
N(God) { ν = 1, Go(OS); }
N(Got) { ν = 2, Go(OS); }
N(NotAndOr) { ((n_t *)β[ρ])[ν](o, β[ρ][-1], α, τ, σ, ρ, δ, ν); }
N(Not) { static n_t nars[] = {G1, G1, Go}; nars[ν](OS); }
N(Or ) { static n_t nars[] = {Go, G1, G1}; nars[ν](OS); }
N(And) { static n_t nars[] = {G1, Go, G1}; nars[ν](OS); }
N(Twist) { Go(o, α, β, τ, σ, ρ, -δ, ν); }


N(go_n) { τ -= 1 << Σ, Go(OS); }
N(go_e) { ti_debug(OS), τ += 11, Go(OS); }
N(go_s) { τ += 1 << Σ, Go(OS); }
N(go_w) { ti_debug(OS), τ -= 11, Go(OS); }

N(done) { printf("the %s!\n", ν == 2 ? "not" : ν ? "and" : "or"); }
N(bone) { printf("bhe %s!\n", ν == 2 ? "not" : ν ? "and" : "or"); }
N(ani);
N(dive);
#include "sisa.h"
void ti_init(void);
int main(int argc, char **argv) {
  ti_init();
  long *root = R(0, done);
  long *boot = R(0, bone);
  long ram[0x10000];
  long *o = ram + sizeof(ram) / sizeof(*ram) / 2;
  long **β = (long *[]){root, root, root, root};
  long **α = (long *[]){boot, boot, boot, boot};;
  long τ;
  long σ = τ = 512;
  long ρ = 3;
  long δ = 1;
  long ν = 1;

  begin tword("tritab") print end nl;

  name("tritab") nl;
    tab tword("tab") tword("tab") tword("tab") dot nl;

  name("tab") nl;
    tab put("b") dot nl;
    tab put("a") dot nl;
    tab put("t") dot nl;

  name("S") nl;
    tab put("b") dot nl; 
    tab tword("S") put("a") dot nl; 
    tab tword("S") put("t") dot nl; 

  οYellow(ani), Go(OS);
}
