// clang-format off
#define N(argo) void argo(void **ο, long β, long α, void **τ, long σ, long ρ, long δ)
typedef N((*n_t));

const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};

#define T5(nar, a)      (a), 0, 0, 0, 0,  nar, 0, 0, 0, 0, (a)
#define T(nar)          T5(nar, 0)

#define LEN(...) (sizeof((void*[]){__VA_ARGS__}) / sizeof(void*))
#define B(...) ((void*[]) {                      \
  T(o),__VA_ARGS__, T(tab), __VA_ARGS__,T(o)     \
} + 11 + 5 + LEN(__VA_ARGS__))

#define oba     ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define     srd             σ, ρ, δ

#define P printf("%3ld %7s %s\n", σ, rays[(ρ + 1) * δ + 5], __FUNCTION__), usleep(200000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

N(goTo    ) {  ((n_t*)τ)[α + δ * 11](ο, β, α + δ * 11, τ, srd); }
N(o       ) {P;goTo(oba, τ, σ, ρ, -δ); }
N(bro     ) {P;if (ρ < 2) goTo(oba, τ, 0, 3, δ); else printf("the end!\n");  }
N(tab     ) {  goTo(ο, β + 1, α, ο[β], srd); }

N(δ_switch) { ((n_t)τ[δ])(obatsrd); }
N(ρδ_switch ) { ((n_t)τ[(ρ + 1) * δ])(obatsrd); }

N(ti_a) { printf("%10s ", (char*)τ[5]), P, goTo(obatsrd); }
N(ti_b) { printf("%10s ", (char*)τ[17]), P, goTo(obatsrd); }
N(ti  ) { (τ[-δ] = ti_b), (τ[+δ] = ti_a), ((n_t)(*τ = δ_switch))(obatsrd); }

#define GET_BIT(value, bit) ((value >> bit) & 1)
#define SET_BIT(value, bit) (value |= (1UL << bit))

#define OB ((unsigned long***)ο)[β][5]
#define Fruitful OB[2]
#define Trimed   OB[3]
#define Arms     OB[1]
#define I        OB[0]
N(propeller) {
  long oi = I;
  while((I = (I + 1) % Arms) && GET_BIT(Trimed, I));
  long d = (long)ο[--σ];
  goTo(oba,τ,σ, !(oi < I) * 2 + d, δ);
}
N(Red_Blue_propeller    ) { (ο[σ++] = (void*)0),          propeller(obatsrd); }
N(Yellow_Green_propeller) { (ο[σ++] = (void*)1),          propeller(obatsrd); }
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
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
N(nop) { assert(0); }
N(Red   ) {
  τ[+4*δ] = nop;
  τ[+3*δ] = Red_Red;
  τ[+2*δ] = nop;
  τ[+1*δ] = goTo;
  τ[-4*δ] = τ[-3*δ] = τ[-2*δ] = τ[-1*δ] = goTo;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
N(Green ) {
  τ[+4*δ] = nop;
  τ[+3*δ] = nop;
  τ[+2*δ] = Green_Green;
  τ[+1*δ] = goTo;
  τ[-4*δ] = τ[-3*δ] = τ[-2*δ] = τ[-1*δ] = goTo;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
N(true_var) {
  long*conf   = τ[5];
  void***arms = (void*)(conf + 4);
 
  static void*a_Yellow[] = {T(o), T(Yellow), T(tab), T(Yellow), T(o)};
  static void*a_Red   [] = {T(o), T(Red),    T(tab), T(Red),    T(o)};
  static void*a_Green [] = {T(o), T(Green),  T(tab), T(Green),  T(o)};
  static void*a_Blue  [] = {T(o),            T(tab),            T(o)};
  static void*a_texts [] = {a_Blue   + 11 + 5,
                            a_Green  + 11 + 11 + 5,
                            a_Red    + 11 + 11 + 5,
                            a_Yellow + 11 + 11 + 5};
  (ο[--β] = τ), (ο[--β] = a_texts[ρ]), goTo(oba, arms[conf[0]], srd);
}
N(open_var) {
  τ[-4*δ] = τ[-3*δ] = τ[-2*δ] = τ[-1*δ] = goTo;
  τ[+1*δ] = true_var;
  τ[+2*δ] = true_var;
  τ[+3*δ] = true_var;
  τ[+4*δ] = true_var;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
N(var) {
  τ[-4*δ] = τ[-3*δ] = τ[-2*δ] = τ[-1*δ] = goTo;
  τ[+1*δ] = goTo;
  τ[+2*δ] = open_var;
  τ[+3*δ] = goTo;
  τ[+4*δ] = open_var;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
#define D(S, ...)                                                     \
  N(S) {                                                              \
    τ[5] = (void*[]) {0,(void*)LEN(__VA_ARGS__),0,0, __VA_ARGS__};    \
    var(obatsrd);                                                     \
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
  if (s[p[δ]] == c) (p[δ] += δ), goTo(obatsrd);
  else goTo(oba, τ, σ, ρ - 2, δ);
}
N(term    ) {
  τ[-4*δ] = τ[-3*δ] = τ[-2*δ] = τ[-1*δ] = goTo;
  τ[+1*δ] = goTo;
  τ[+2*δ] = term_A;
  τ[+3*δ] = goTo;
  τ[+4*δ] = term_A;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
N(b) { (τ[5] = (void*)'b'), term(obatsrd); }
N(a) { (τ[5] = (void*)'a'), term(obatsrd); }
N(t) { (τ[5] = (void*)'t'), term(obatsrd); }
N(s) { (τ[5] = (void*)'s'), term(obatsrd); }
N(print_a) {
  printf("%7s P_(", rays[(ρ + 1) * δ + 5]);
  for (long i = 0; i < σ; i++)
    if ((long)ο[i] < 100) printf("%ld", (long)ο[i]);
    else printf("%s", (char *)ο[i]);
  printf(")\n");
  goTo(obatsrd);
}
N(print) { (τ[-δ] = goTo), (τ[+δ] = print_a), ((n_t)(*τ = δ_switch))(obatsrd); }
N(str_a) { (ο[σ++] = τ[5]), goTo(obatsrd); }
N(str  ) { (τ[-δ] = goTo), (τ[+δ] = str_a), ((n_t)(*τ = δ_switch))(obatsrd);  }
N(n1   ) { (τ[5] = "1"), str(obatsrd); }
N(n2   ) { (τ[5] = "2"), str(obatsrd); }
N(n3   ) { (τ[5] = "3"), str(obatsrd); }
N(n4   ) { (τ[5] = "4"), str(obatsrd); }
N(n5   ) { (τ[5] = "5"), str(obatsrd); }


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
N(ld) { P; goTo(obatsrd); }
N(rd) { P; goTo(oba, τ, σ, 1, δ); }
D(V,
  B(T(b), T(a), T(t)),
  B(T(b), T(a), T(t)),
)
int main() {
  void *ο[512] = {};
  long  β      = sizeof(ο) / sizeof(*ο), α = 0;
  void *text[] = {
              T(o),
            T(print),
          T(V),
        T5(in, "bat"),
      T(bro),
        T5(in, "bat"),
          T(V),
            T(print),
              T(o)
  };
  void**τ      = text + sizeof(text) / sizeof(*text) / 2;
  long  σ      = 0, ρ = 3, δ = 1;
  goTo(obatsrd);
}
