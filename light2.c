// clang-format off
#define N(argo) void argo(void **τ, long α, long β, void **ο, char *σ, long ρ, long δ)
typedef N((*n_t));
#define P (void)0
//#define P printf("%10s %10s\n", __FUNCTION__, rays[(ρ + 1) * δ + 5]), usleep(20000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};

#define Tab(nar, a, b)  0, 0, 0, (b), (a), nar, (a), (b), 0, 0, 0
#define Ta(nar, a)      Tab(nar, a, 0)
#define T(nar)          Tab(nar, 0, 0)

#define goTo(τ, α, β, ο, σ, ρ, δ) ((n_t*)τ)[δ * 11](((void**)τ) + δ * 11, α, β, ο, σ, ρ, δ)
N(o         ) { goTo(τ, α, β, ο, σ, ρ, -δ); }
N(b         ) { if (ρ < 2) goTo(τ, α, β, ο, σ, 3, 1); else P; }

N(ρδ_switch ) { ((n_t)τ[(ρ + 1) * δ])(τ, α, β, ο, σ, ρ, δ); }

int twist(long*τ, long δ) {
  long io = τ[6*δ];
  τ[6*δ] = (τ[6*δ] + 1) % τ[7*δ];
  return !(io < τ[6*δ]);
}
N(Yellow_Olive    ) {P; goTo(τ, α, β, ο, σ, twist((long*)τ, δ) * 2 + 1, δ); }
N(Yellow_Maroon   ) {P; goTo(τ, α, β, ο, σ, twist((long*)τ, δ) * 2, δ); }
N(Yellow_Lime     ) {P; goTo(τ, α, β, ο, σ, ρ, δ); }
N(Yellow_Navy     ) {P; goTo(τ, α, β, ο, σ, ρ, δ); }
N(Red_Olive       ) {P; assert(0); }
N(Red_Maroon      ) {P; goTo(τ, α, β, ο, σ, twist((long*)τ, δ) * 2, δ); }
N(Red_Lime        ) {P; assert(0); }
N(Red_Navy        ) {P; goTo(τ, α, β, ο, σ, ρ, δ); }
N(Green_Olive     ) {P; assert(0); }
N(Green_Maroon    ) {P; assert(0); }
N(Green_Lime      ) {P; goTo(τ, α, β, ο, σ, ρ, δ); }
N(Green_Navy      ) {P; goTo(τ, α, β, ο, σ, ρ, δ); }
N(Blue_Olive      ) {P; assert(0); }
N(Blue_Maroon     ) {P; assert(0); }
N(Blue_Lime       ) {P; assert(0); }
N(Blue_Navy       ) {P; goTo(τ, α, β, ο, σ, ρ, δ); }
N(propeller_Yellow) {P;
  τ[(22+1)*δ] = Yellow_Navy;
  τ[(22+2)*δ] = Yellow_Lime;
  τ[(22+3)*δ] = Yellow_Maroon;
  τ[(22+4)*δ] = Yellow_Olive;
  goTo(τ, α, β, ο, σ, ρ, δ);
}
N(propeller_Red   ) {P;
  τ[(22+1)*δ] = Red_Navy;
  τ[(22+2)*δ] = Red_Lime;
  τ[(22+3)*δ] = Red_Maroon;
  τ[(22+4)*δ] = Red_Olive;
  goTo(τ, α, β, ο, σ, ρ, δ);
}
N(propeller_Green ) {P;
  τ[(22+1)*δ] = Green_Navy;
  τ[(22+2)*δ] = Green_Lime;
  τ[(22+3)*δ] = Green_Maroon;
  τ[(22+4)*δ] = Green_Olive;
  goTo(τ, α, β, ο, σ, ρ, δ);
}
N(propeller_Blue  ) {P;
  τ[(22+1)*δ] = Blue_Navy;
  τ[(22+2)*δ] = Blue_Lime;
  τ[(22+3)*δ] = Blue_Maroon;
  τ[(22+4)*δ] = Blue_Olive;
  goTo(τ, α, β, ο, σ, ρ, δ);
}
N(propeller       ) {P;
  τ[(22-4)*δ] = propeller_Yellow;
  τ[(22-3)*δ] = propeller_Red;
  τ[(22-2)*δ] = propeller_Green;
  τ[(22-1)*δ] = propeller_Blue;
  τ[(22-0)*δ] = ρδ_switch;
  τ[    0 *δ] = ρδ_switch;
  τ[    1 *δ] = propeller_Blue;
  τ[    2 *δ] = propeller_Green;
  τ[    3 *δ] = propeller_Red;
  τ[    4 *δ] = propeller_Yellow;
  ((n_t)τ[+0])(τ, α, β, ο, σ, ρ, δ);
}
N(i7_switch       ) {P; goTo(τ[δ + (long)τ[17 * δ] * δ], α, β, ο, σ, ρ, δ); }
N(tab             ) {P; goTo(τ[δ], α, β, ο, σ, ρ, δ); }
N(S               ) {P;
  void *atext[] = { Ta(tab, τ), T(propeller), T(τ[δ]), T(propeller), Ta(tab, τ) };
  τ[-1] = atext + sizeof(atext) / sizeof(*atext) - 6;
  τ[+0] = tab;
  τ[+1] = atext + 5;
  ((n_t)τ[+0])(τ, α, β, ο, σ, ρ, δ);
}
N(c) { (ο[α++] = τ[δ]), goTo(τ, α, β, ο, σ, ρ, δ); }
N(N_arms) {P;
  τ[-18]  = 3;
  τ[ -3]  = (void*[]){Ta(tab, τ), Ta(c,"a"), Ta(tab, τ)} + 3 * 11 - 6;
  τ[ -2]  = (void*[]){Ta(tab, τ), Ta(c,"b"), Ta(tab, τ)} + 3 * 11 - 6;
  τ[ -1]  = (void*[]){Ta(tab, τ), Ta(c,"c"), Ta(tab, τ)} + 3 * 11 - 6;
  τ[  0]  = i7_switch;
  τ[ +1]  = (void*[]){Ta(tab, τ), Ta(c,"1"), Ta(tab, τ)} + 5;
  τ[ +2]  = (void*[]){Ta(tab, τ), Ta(c,"2"), Ta(tab, τ)} + 5;
  τ[ +3]  = (void*[]){Ta(tab, τ), Ta(c,"3"), Ta(tab, τ)} + 5;
  τ[+18]  = 3;
  ((n_t)τ[+0])(τ, α, β, ο, σ, ρ, δ);
}
#define LEN(...) (sizeof((void *[]){__VA_ARGS__}) / sizeof(void *))
#define ARM(op, off, ...)                                                      \
  (τ[op++((long *)τ)[op 18]] =                                                 \
       (void *[]){Ta(tab, τ), __VA_ARGS__, Ta(tab, τ)} + off)
#define L(...) ARM(-, LEN(__VA_ARGS__) + 16, __VA_ARGS__)
#define R(...) ARM(+, 5, __VA_ARGS__)
#define B(...) L(__VA_ARGS__), R
#define D(n, ...)                                                              \
  N(n) {                                                                       \
    P;                                                                         \
    __VA_ARGS__;                                                               \
    τ[0] = i7_switch;                                                          \
    ((n_t)τ[+0])(τ, α, β, ο, σ, ρ, δ);                                         \
  }
D(c3_arms,        B(Ta(c, "3"))       (Ta(c, "c")))
D(e5_arms,        B(Ta(c, "5"))       (Ta(c, "e")))
D(c3e5_arms,      B(Ta(S, e5_arms))   (Ta(S, c3_arms)))

D(x6_arms,        B(Ta(c, "6"))       (Ta(c, "x")))
D(y7_arms,        B(Ta(c, "7"))       (Ta(c, "y")))
D(x6y7_arms,      B(Ta(S, y7_arms))   (Ta(S, x6_arms)))

D(c3e5x6y7_arms,  B(Ta(S, x6y7_arms)) (Ta(S, c3e5_arms)))
D(S_arms,         B(Ta(c, "a"))(Ta(c, "c")),
                  B(Ta(c, "b"))(Ta(c, "d")))
N(print) {
  if (α) {
    printf("(");
    for (long i = 0; i < α; i++)
      printf("%s", (char *)ο[i]);
    printf(")%s\n", rays[(ρ + 1) * δ + 5]);
    usleep(200000);
  }
  goTo(τ, 0, β, ο, σ, ρ, δ);
}
int main() {
  void **τ = 5 + (void *[]){T(b), T(print), Ta(S, S_arms), T(o)};
  long α = 0;
  void *ο[512];
  long β = sizeof(ο) / sizeof(*ο);
  goTo(τ, α, β, ο, "", 3, 1);
}
