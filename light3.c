// clang-format off
#define N(argo) void argo(void **ο, long β, long α, void **τ, long σ, long ρ, long δ)
typedef N((*n_t));
//#define P (void)0
#define P printf("%ld %ld %ld %7s %s\n", σ, ρ, δ, rays[(ρ + 1) * δ + 5], __FUNCTION__), usleep(200)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};

#define Ta(nar, a)      0, 0, 0, 0, (a), nar, (a), 0, 0, 0, 0
#define T(nar)          Ta(nar, 0)
#define oba     ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define     srd             σ, ρ, δ

N(goTo      ) { ((n_t*)τ)[δ * 11](ο, β, α, ((void**)τ) + δ * 11, σ, ρ, δ); }

N(o         ) { goTo(ο, β, α, τ, σ, ρ, -δ); }
N(bro       ) { if (ρ < 2) o(ο, β, α, τ, σ, 3, δ); else P; }

N(δρ_switch ) { ((n_t)τ[(ρ + 1) * δ])(ο, β, α, τ, σ, ρ, δ); }
N(δ_switch  ) { ((n_t)τ[          δ])(ο, β, α, τ, σ, ρ, δ); }

N(tab) { goTo(ο, β + 1, α, ο[β], srd); }
N(bat) { (ο[--α] = τ), tab(obatsrd); }
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
  goTo(ο,β,α,τ,σ, !(oi < I)*2 + d, δ);
}
N(Red_Blue_propeller    ) { (ο[σ++] = (void*)0), propeller(obatsrd); }
N(Yellow_Green_propeller) { (ο[σ++] = (void*)1), propeller(obatsrd); }
N(Yellow_Green          ) { SET_BIT(Fruitful, I),         goTo(obatsrd); }
N(Yellow_Red            ) { if (Arms == 1)                goTo(obatsrd);
                            else if(GET_BIT(Fruitful, I)) Red_Blue_propeller(obatsrd);
                            else SET_BIT(Trimed, I),      Red_Blue_propeller(obatsrd); }
N(Yellow_Yellow         ) { SET_BIT(Fruitful, I),         Yellow_Green_propeller(obatsrd); }
N(Red_Red               ) {                               Red_Blue_propeller(obatsrd); }
N(Green_Green           ) { SET_BIT(Fruitful, I),         goTo(obatsrd); }

N(Yellow) {
  τ[+4] = Yellow_Yellow;
  τ[+3] = Yellow_Red;
  τ[+2] = Yellow_Green;
  τ[+1] = goTo;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(nop) { assert(0); }
N(Red   ) {
  τ[+4] = nop;
  τ[+3] = Red_Red;
  τ[+2] = nop;
  τ[+1] = goTo;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(Green ) {
  τ[+4] = nop;
  τ[+3] = nop;
  τ[+2] = Green_Green;
  τ[+1] = goTo;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(toti) {
  long*c  = ((void***)ο)[β][5];
  void**a = (void*)(c + 4);
  (ο[--β] = τ), goTo(oba, a[c[0]], srd);
}
N(itot   ) { (ο[--β] = τ), goTo(ο, β, α + 1, ο[α], srd);   }
N(goTo_δρ) { (ο[--β] = τ), goTo(oba, τ[(ρ + 1) * δ], srd); }
N(bt ) { (ο[σ++] = "("), goTo(obatsrd); }
N(at) { (ο[σ++] = ")"),  goTo(obatsrd); }
N(var0) { 
  static void*a_Yellow[] = {T(tab), T(toti), T(Yellow),    T(tab)}; 
  static void*a_Red   [] = {T(tab), T(toti), T(Red),       T(tab)};
  static void*a_Green [] = {T(tab), T(toti), T(Green),     T(tab)};
  static void*a_Blue  [] = {T(tab), T(toti),               T(tab)};
  static void*a_back0 [] = {T(tab),        T(itot),        T(tab)};
  static void*a_back1 [] = {T(tab), T(bt), T(itot), T(at), T(tab)};
  τ[+4] = a_Yellow + 5;
  τ[+3] = a_Red    + 5;
  τ[+2] = a_Green  + 5;
  τ[+1] = a_Blue   + 5;

  τ[-1] = a_back0  + 27;
  τ[-2] = a_back1  + 49;
  τ[-3] = a_back0  + 27;
  τ[-4] = a_back1  + 49;
  ((n_t)(*τ = goTo_δρ))(obatsrd);
}
N(var) { 
  τ[-4] = goTo;
  τ[-3] = goTo;
  τ[-2] = goTo;
  τ[-1] = goTo;

  τ[+1] = goTo;
  τ[+2] = var0;
  τ[+3] = goTo;
  τ[+4] = var0;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(ε); N(s); N(b); N(a); N(t); N(plus); N(mul); N(op); N(cp);
N(n1); N(n2); N(n3); N(n4); N(n5); N(n6);
#define LEN(...) (sizeof((void*[]){__VA_ARGS__}) / sizeof(void*))
#define B(...) (5+(void*[]){T(tab), __VA_ARGS__, T(bat)})
#define D(S, ...)                                                       \
  N(S) {                                                                \
    τ[+5] = (void*[]){0,(void*)LEN(__VA_ARGS__),0,0, __VA_ARGS__};      \
    var(obatsrd);                                                       \
  }
D(n345, 
  B(T(n3)),
  B(T(n4)),
  B(T(n5)))
D(n123, 
  B(T(n1)),
  B(T(n2)),
  B(T(n3), T(n345)))
D(Tab, 
  B(T(t)),
  B(T(a)),
  B(T(b))
)
D(sS, B(T(n1), T(ε)              ),
      B(T(n2), T(s), T(sS), T(sS)),
      B(T(n3), T(s), T(sS), T(sS)),
)
N(S);
D(Sλ, B(T(n2), T(a), T(Sλ)),
      B(T(n3), T(t), T(Sλ)),
      B(T(n4)))
D(S,  B(T(n1), T(b), T(Sλ)))

N(E);
D(Eλ, B(T(n2),T(plus),T(E),       T(Eλ)),
      B(T(n3),T(mul), T(E),       T(Eλ)),
      B(T(n1)))
D(E,  B(T(n4),T(a),               T(Eλ)),
      B(T(n5),T(b),               T(Eλ)),
      B(T(n6),T(op),  T(E), T(cp),T(Eλ)))
N(in); N(print);

int main() {
  void *ο[512];
  long β = sizeof(ο) / sizeof(*ο);
  long α = β / 4 * 3;
  //void **τ = 5 + (void *[]) { T(bro), T(print), Ta(in,""), T(n123), T(n123), T(n123), T(print), T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(print), Ta(in, "bat"), T(Tab), T(Tab), T(Tab), T(print), T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(print), Ta(in,"ss"), T(sS), T(print), T(o) };
  void **τ = 5 + (void *[]) { T(bro), T(print), Ta(in,"baaaat"), T(S), T(print), T(o) };
  //void **τ = 5 + (void *[]) { T(bro), T(print), Ta(in,"(a+b)*a"), T(E), T(print), T(o) };
  long σ = 0;
  long ρ = 3;
  long δ = 1;

  goTo(ο, β, α, τ, σ, ρ, δ);
}
N(terminal_parse) {
  char*s1 = ο[--σ];
  char*s2 = τ[5];
  long i = 0;
  while (s2[i] && s2[i] == s1[i]) i++;
  if (s2[i] == 0) (ο[σ++] = s1 + i), goTo(oba, τ, σ, (long)(τ[-5] = (void*)ρ), δ);
  else            (ο[σ++] = s1),     goTo(oba, τ, σ, (long)(τ[-5] = (void*)ρ - 1), δ);
}
N(terminal_B_side ) { (ο[σ++] = τ[5]), goTo(obatsrd); }
N(terminal        ) {
  τ[-4*δ] = terminal_B_side;
  τ[-3*δ] = goTo;
  τ[-2*δ] = terminal_B_side;
  τ[-1*δ] = goTo;

  τ[+1*δ] = goTo;
  τ[+2*δ] = terminal_parse;
  τ[+3*δ] = goTo;
  τ[+4*δ] = terminal_parse;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(ε   ) { (τ[5] = ""),  terminal(obatsrd); }
N(s   ) { (τ[5] = "s"), terminal(obatsrd); }
N(b   ) { (τ[5] = "b"), terminal(obatsrd); }
N(a   ) { (τ[5] = "a"), terminal(obatsrd); }
N(t   ) { (τ[5] = "t"), terminal(obatsrd); }
N(plus) { (τ[5] = "+"), terminal(obatsrd); }
N(mul ) { (τ[5] = "*"), terminal(obatsrd); }
N(op  ) { (τ[5] = "("), terminal(obatsrd); }
N(cp  ) { (τ[5] = ")"), terminal(obatsrd); }
N(in_heart) { if(δ == 1) ο[σ++] = τ[2]; goTo(obatsrd); }
N(in) {
  τ[2]  = τ[1];
  τ[-δ] = goTo;
  τ[+δ] = in_heart;
  ((n_t)(*τ = δ_switch))(obatsrd);
}
N(str_oa) { void*d = ο[--σ]; (ο[σ++] = τ[2]),(ο[σ++] = d), goTo(obatsrd); }
N(str   ) { τ[-δ] = goTo; τ[+δ] = str_oa; ((n_t)(*τ = δ_switch))(obatsrd);  }
N(n1    ) { (τ[2] = "1"), str(obatsrd); }
N(n2    ) { (τ[2] = "2"), str(obatsrd); }
N(n3    ) { (τ[2] = "3"), str(obatsrd); }
N(n4    ) { (τ[2] = "4"), str(obatsrd); }
N(n5    ) { (τ[2] = "5"), str(obatsrd); }
N(n6    ) { (τ[2] = "6"), str(obatsrd); }
N(print_A   ) {
  if (σ && ρ % 2 == 1) {
    printf("%7s(", rays[(ρ + 1) * δ + 5]);
    for (long i = 0; i < σ; i++)
      printf("%s", (char *)ο[i]);
    printf(")\n");
  }
  (σ = 0), goTo(obatsrd);
}
N(print_B   ) {
  if (σ) {
    printf("%7s", rays[(ρ + 1) * δ + 5]);
    for (long i = --σ; -1 < i; i--)
      printf("%s", (char *)ο[i]);
    printf("\n");
    σ = 0; 
  }
  goTo(obatsrd);
}
N(print   ) { (τ[+1] = print_A), (τ[-1] = print_B), ((n_t)(*τ = δ_switch))(obatsrd); }
