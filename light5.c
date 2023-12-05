// clang-format off
#define N(argo) void argo(void **ο, long β, long α, void **τ, long σ, long ρ, long δ)
typedef N((*n_t));

const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};

#define T5(nar, a)      (a), 0, 0, 0, 0, nar, 0, 0, 0, 0, (a)
#define T(nar)          T5(nar, 0)
#define LEN(...) (sizeof((void*[]){__VA_ARGS__}) / sizeof(void*))
#define B(...) ((void*[]) {                   \
  T(o),__VA_ARGS__,T(Larm),T(tab),T(Rarm), __VA_ARGS__, T(o)  \
} + 27 + LEN(__VA_ARGS__))

#define oba     ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define     srd             σ, ρ, δ

#define P printf("%3ld %7s_%s %s\n", σ, rays[(ρ/2 + 1) * δ + 5],            \
                                        (ρ % 2 ? "B" : "A"), __FUNCTION__), \
                                        usleep(200000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

N(goTo    ) {  ((n_t*)τ)[δ * 11](oba, ((void**)τ) + δ * 11, srd); }
N(o       ) {P;goTo(ο, β, α, τ, σ, ρ, -δ); }
N(bro     ) {P;if ((ρ / 2) < 2) o(ο, β, α, τ, σ, 6 + !(ρ % 2), δ); else P;  }
N(tab     ) {  goTo(ο, β + 1, α, ο[β], srd); }

N(δ_switch) { ((n_t)τ[δ])(obatsrd); }
N(δρ_switch ) { ((n_t)τ[(ρ/2 + 1) * δ])(obatsrd); }
#define GET_BIT(value, bit) ((value >> bit) & 1)
#define SET_BIT(value, bit) (value |= (1UL << bit))

#define OB ((unsigned long***)ο)[β][5]
#define Fruitful OB[3]
#define Trimed   OB[4]
#define Arms     OB[2]
#define I        OB[ρ % 2]
N(propeller) {
  long oi = I;
  while((I = (I + 1) % Arms) && GET_BIT(Trimed, I));
  long d = (long)ο[--σ];
  goTo(ο,β,α,τ,σ, !(oi < I) * 4 + d + ρ % 2, δ);
}
N(Red_Blue_propeller    ) { (ο[σ++] = (void*)0),          propeller(obatsrd); }
N(Yellow_Green_propeller) { (ο[σ++] = (void*)2),          propeller(obatsrd); }
N(Yellow_Green          ) { SET_BIT(Fruitful, I),         goTo(obatsrd); }
N(Yellow_Red            ) { if (Arms == 1)                goTo(obatsrd);
                            else if(GET_BIT(Fruitful, I)) Red_Blue_propeller(obatsrd);
                            else SET_BIT(Trimed, I),      Red_Blue_propeller(obatsrd); }
N(Yellow_Yellow         ) { SET_BIT(Fruitful, I),         Yellow_Green_propeller(obatsrd); }
N(Red_Red               ) {                               Red_Blue_propeller(obatsrd); }
N(Green_Green           ) { SET_BIT(Fruitful, I),         goTo(obatsrd); }
N(Yellow) {
  τ[+4*δ] = Yellow_Yellow;
  τ[+3*δ] = Yellow_Red;
  τ[+2*δ] = Yellow_Green;
  τ[+1*δ] = goTo;
  τ[-4*δ] = τ[-3*δ] = τ[-2*δ] = τ[-1*δ] = goTo;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(nop) { assert(0); }
N(Red   ) {
  τ[+4*δ] = nop;
  τ[+3*δ] = Red_Red;
  τ[+2*δ] = nop;
  τ[+1*δ] = goTo;
  τ[-4*δ] = τ[-3*δ] = τ[-2*δ] = τ[-1*δ] = goTo;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(Green ) {
  τ[+4*δ] = nop;
  τ[+3*δ] = nop;
  τ[+2*δ] = Green_Green;
  τ[+1*δ] = goTo;
  τ[-4*δ] = τ[-3*δ] = τ[-2*δ] = τ[-1*δ] = goTo;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(n_Yellow) { goTo(obatsrd); } N(p_Yellow) { goTo(obatsrd); }
N(n_Red   ) { goTo(obatsrd); } N(p_Red   ) { goTo(obatsrd); }
N(n_Green ) { goTo(obatsrd); } N(p_Green ) { goTo(obatsrd); }
N(n_Blue  ) { goTo(obatsrd); } N(p_Blue  ) { goTo(obatsrd); }
N(true_var) {
  long*conf   = τ[5];
  void***arms = (void*)(conf + 5);
  static void*a_Yellow[] = {T(o), T(n_Yellow), T(Yellow), T(tab), T(Yellow), T(p_Yellow), T(o)};
  static void*a_Red   [] = {T(o), T(n_Red),    T(Red),    T(tab), T(Red),    T(p_Red),    T(o)};
  static void*a_Green [] = {T(o), T(n_Green),  T(Green),  T(tab), T(Green),  T(p_Green),  T(o)};
  static void*a_Blue  [] = {T(o), T(n_Blue),              T(tab),            T(p_Blue),   T(o)};
  static void*texts   [] = {a_Blue  + 16, a_Green + 38, a_Red + 38, a_Yellow + 38};
  (ο[--β] = τ),
    (ο[--β] = texts[ρ / 2]),
      goTo(oba, arms[conf[ρ % 2]], srd);
}
N(var) {
  static n_t nars[8]  = {
    goTo,      // 0 -1 +1
    true_var,  // 1 -1 +1
    true_var,  // 0 +1 +1
    goTo       // 1 +1 +1
  };
  nars[ρ % 2 + δ + 1](obatsrd);
}
#define D(S, ...)                                                     \
  N(S) {                                                              \
    τ[5] = (void*[]) {0,0,(void*)LEN(__VA_ARGS__),0,0, __VA_ARGS__};  \
    ((n_t)(*τ = var))(obatsrd);                                       \
  }
#include<string.h>
N(in_a) {
  ο[σ++] = (void*)(strlen(τ[5]) - 1);
  ο[σ++] = τ[5];
  ο[σ++] = 0;
  goTo(obatsrd);
}
N(in) {
  τ[-δ] = goTo;
  τ[+δ] = in_a;
  ((n_t)(*τ = δ_switch))(obatsrd);
}
N(term_A  ) { 
  char*s = ο[σ - 2];
  long c = (long)τ[5];
  long*p = (long*)(ο + σ - 2);
  printf("%s %ld %c\n", s, p[δ], (char)c);
  if (s[p[δ]] == c) (p[δ] += δ), goTo(obatsrd);
  else goTo(oba, τ, σ, ρ - 2, δ);
}
N(term    ) {
  τ[-4*δ] = goTo; τ[-3*δ] = goTo; τ[-2*δ] = goTo; τ[-1*δ] = goTo;
  τ[+1*δ] = goTo;
  τ[+2*δ] = term_A;
  τ[+3*δ] = goTo;
  τ[+4*δ] = term_A;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(b) { τ[5] = (void*)'b'; term(obatsrd); }
N(a) { τ[5] = (void*)'a'; term(obatsrd); }
N(t) { τ[5] = (void*)'t'; term(obatsrd); }
N(s) { τ[5] = (void*)'s'; term(obatsrd); }
N(print_a) {
  printf("%s_%s P_(", rays[(ρ/2 + 1) * δ + 5], (ρ % 2 ? "B" : "A"));
  for (long i = 0; i < σ; i++)
    if ((long)ο[i]<100) printf("%ld", (long)ο[i]);
    else printf("%s", (char *)ο[i]);
  printf(")\n");
  goTo(obatsrd);
}
N(print) {
  τ[-δ] = print_a;
  τ[+δ] = goTo;
  ((n_t)(*τ = δ_switch))(obatsrd);
}
N(str_a) { (ο[σ++] = τ[5]), goTo(obatsrd); }
N(str  ) { (τ[-δ] = goTo), (τ[+δ] = str_a), ((n_t)(*τ = δ_switch))(obatsrd);  }
N(n1   ) { (τ[5] = "1"), str(obatsrd); }
N(n2   ) { (τ[5] = "2"), str(obatsrd); }
N(n3   ) { (τ[5] = "3"), str(obatsrd); }
N(n4   ) { (τ[5] = "4"), str(obatsrd); }
N(n5   ) { (τ[5] = "5"), str(obatsrd); }

N(Larm) { P; goTo(obatsrd); }
N(Rarm) { P; goTo(obatsrd); }

//D(S, B(T(n1)), B(T(n2)))
D(n345,
  B(T(n3)),
  B(T(n4)),
  B(T(n5)),
)
D(n123,
  B(T(n1)),
  B(T(n2)),
  B(T(n3), T(n345)),
)
D(S,
  B(T(b)),
  B(T(t)),
  B(T(b)),
  //B(T(S), T(a)),
)
N(rs) { σ = 0, goTo(obatsrd); }
N(id) { P, goTo(obatsrd); }
int main() {
  void *ο[512] = {};
  long  β = sizeof(ο) / sizeof(*ο), α = 0;
  void**τ = 5 + (void*[]) {
    T(bro),
    T(rs), T5(in, "bat"), T(print), T(S), T(id), T(S),
    T(o)
  };
  long  σ = 0, ρ = 3*2, δ = 1;
  goTo(obatsrd);
}
