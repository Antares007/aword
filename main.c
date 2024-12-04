#pragma GCC diagnostic ignored "-Wint-conversion"
#define N(args) void args(long*ο, long β, long α, long τ, long σ, long ρ, long δ)
#define EE ο, β, α, τ, σ, ρ, δ
typedef N((*n_t));

#define ob0(r)  ο[--ρ] = r,           \
                ο[--r] = ο[ο[ρ] + 3], \
                ο[--r] = ο[ο[ρ] + 2], \
                ο[--r] = ο[ο[ρ] + 1], \
                ο[--r] = ρ
#define ob1(r)  ο[--ρ] = r,           \
                ο[--r] = ο[ο[ρ] + 3], \
                ο[--r] = ο[ο[ρ] + 2], \
                ο[--r] = ρ,           \
                ο[--r] = ο[ο[ρ] + 0]
#define ob2(r)  ο[--ρ] = r,           \
                ο[--r] = ο[ο[ρ] + 3], \
                ο[--r] = ρ,           \
                ο[--r] = ο[ο[ρ] + 1], \
                ο[--r] = ο[ο[ρ] + 0]
#define ob3(r)  ο[--ρ] = r,           \
                ο[--r] = ρ,           \
                ο[--r] = ο[ο[ρ] + 2], \
                ο[--r] = ο[ο[ρ] + 1], \
                ο[--r] = ο[ο[ρ] + 0]
#define ΔRed    ο[β + 3]
#define ΔYellow ο[β + 2]
#define ΔGreen  ο[β + 1]
#define ΔBlue   ο[β + 0]

#define ΔMaroon ο[β + 3]
#define ΔOlive  ο[β + 2]
#define ΔLime   ο[β + 1]
#define ΔNavy   ο[β + 0]

N(Red   ) { n_t n = ο[ΔRed    + 1]; β = ο[ΔRed   ]; n(EE); }
N(Yellow) { n_t n = ο[ΔYellow + 1]; β = ο[ΔYellow]; n(EE); }

int main() {
  long ο[] = {};
  long α = 512;
  long ρ = 512;
  long τ = 512;
  long σ = 512;
  ο[--τ] = 4, ob1(σ), ο[--τ] = 3, ob1(σ);

}
N(gani_aword);
N(gani_tword);
N(gani_dot);
N(gani_print);
N(Yellow);
N(gani) {
  static n_t narg[6] = {
    [2] = gani_aword,
    [3] = gani_tword,
    [4] = gani_dot,
    [5] = gani_print,
    [0] = Yellow,
  };
  n_t n = narg[ο[ο[β + 2]]]; β = ο[ο[β + 2] - 1]; n(EE);
}
