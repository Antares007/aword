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

#define one       ο[σ] = 1,               σ += 11,
#define two(a)    ο[σ] = 2, ο[σ + 1] = a, σ += 11,
#define three(a)  ο[σ] = 3, ο[σ + 1] = a, σ += 11,
#define four      ο[σ] = 4,               σ += 11,
#define five      ο[σ] = 5,               σ += 11,
#define align                             σ  = ((σ>>Σ)+1)<<Σ
N(gani);
N(programS) {
  one three("S") five align;
  three("S") align;
  one two("b") four align;
  one three("S") two("a") four align;
  one three("S") two("t") four align;
  οBlue(Blue, 20), gani(OS);
}
N(programAB) {
  one three("A") ο[σ]=5,σ+=11, align;
  three("A") align;
  one two("b") four align;
  one three("B") two("a") four align;
  three("B") align;
  one two("y") four align;
  one three("A") two("b") four align;
  οBlue(Blue, 20), gani(OS);
}
N(program_isamntpwab) {
  one three("s") ο[σ]=5,σ+=11, align;
  three("s") align;
  one three("np") three("vp") four align;
  one three("s") three("pp") four align;
  three("np") align;
  one three("noun") four align;
  one three("det") three("noun") four align;
  one three("np") three("pp") four align;
  three("pp") align;
  one three("prep") three("np") four align;
  three("vp") align;
  one three("verb") three("np") four align;
  three("det") align;
  one two("a") four align;
  one two("t") four align;
  three("noun") align;
  one two("i") four align;
  one two("m") four align;
  one two("p") four align;
  one two("b") four align;
  three("verb") align;
  one two("s") four align;
  three("prep") align;
  one two("n") four align;
  one two("w") four align;
  οBlue(Blue, 35), gani(OS);
}
N(programSexpression) {
  one three("S") ο[σ]=5, σ+=11, align;
  three("S") align;
  one three("S") two("+") three("S") four align;
  one three("S") two("-") three("S") four align;
  one three("S") two("*") three("S") four align;
  one three("S") two("/") three("S") four align;
  one two("(") three("S") two(")") four align;
  one three("N") four align;
  three("N") align;
  one two("2") four align;
  one two("3") four align;
  οBlue(Blue, 10), gani(OS);
}
void ti_init(void);
int main(int argc, char **argv) {
  ti_init();
  long *cap = R(0, zero, 0);
  long ram[0x10000];
  long *ο = ram + sizeof(ram) / sizeof(*ram) / 2;
  long **β = (long *[]){cap, cap, cap, cap};
  long **α = β;
  long **ω = α;
  long τ;
  long σ = τ = 512;
  long ρ = 2;
  long δ = 1;
  long ν = 1;
  programAB(OS);
}

