// clang-format off
#define N(argo) void argo(void **ο, long β, long α, void **τ, long σ, long ρ, long δ)
typedef N((*n_t));

const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};

#define T5(nar, a)      (a), 0, 0, 0, 0,  nar, 0, 0, 0, 0, (a)
#define T(nar)          T5(nar, 0)

#define LEN(...) (sizeof((void*[]){__VA_ARGS__}) / sizeof(void*))
#define B(...) ((void*[]) {                         \
  (void*)(11 + LEN(__VA_ARGS__)), tab, 0,0,0,0,0,   \
  __VA_ARGS__,                                      \
  0,0,0,0,0, tab                                    \
  } + 1)

#define oba     ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define     srd             σ, ρ, δ

//#define P (void)0
#define P printf("%3ld %7s %s\n", σ, rays[(ρ + 1) * δ + 5], __FUNCTION__),\
          usleep(20000)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

N(goTo    ) {  ((n_t*)τ)[δ * 11](oba, τ + δ * 11, srd); }
N(bo      ) {  if (ρ < 2) goTo(oba, τ, 0, 3, -δ); else printf("the end!\n"); }
N(tab     ) {  goTo(ο, β + 1, α, ο[β], srd); }

N(δ_switch) { ((n_t)τ[δ])(obatsrd); }
N(ρδ_switch ) { ((n_t)τ[(ρ + 1) * δ])(obatsrd); }

N(id      ) { P; goTo(obatsrd); }
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
  long r = !(oi < I) * 2 + d;
  goTo(oba,τ,σ,r,δ);
}
N(Red_Blue_propeller    ) { (ο[σ++] = (void*)0),          propeller(obatsrd); }
N(Yellow_Green_propeller) { (ο[σ++] = (void*)1),          propeller(obatsrd); }
N(Yellow_Green          ) { SET_BIT(Fruitful, I),         goTo(obatsrd); }
N(Yellow_Red            ) { // if (Arms == 1)                goTo(obatsrd);
                            // else if(GET_BIT(Fruitful, I)) Red_Blue_propeller(obatsrd);
                            // else SET_BIT(Trimed, I),      
                                                          Red_Blue_propeller(obatsrd); }
N(Yellow_Yellow         ) { SET_BIT(Fruitful, I),         Yellow_Green_propeller(obatsrd); }
N(Red_Red               ) {                               Red_Blue_propeller(obatsrd); }
N(Green_Green           ) { SET_BIT(Fruitful, I),         goTo(obatsrd); }
N(Yellow  ) {
  τ[-4] = τ[+4] = Yellow_Yellow;
  τ[-3] = τ[+3] = Yellow_Red;
  τ[-2] = τ[+2] = Yellow_Green;
  τ[-1] = τ[+1] = goTo;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
N(nop     ) { assert(0); }
N(Red     ) {
  τ[-4] = τ[+4] = nop;
  τ[-3] = τ[+3] = Red_Red;
  τ[-2] = τ[+2] = nop;
  τ[-1] = τ[+1] = goTo;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
N(Green   ) {
  τ[-4] = τ[+4] = nop;
  τ[-3] = τ[+3] = nop;
  τ[-2] = τ[+2] = Green_Green;
  τ[-1] = τ[+1] = goTo;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}

N(toti    ) {
  long   *c = ((void***)ο)[β][5];
  void ***a = (void*)(c + 4);
  void**arm = a[c[0]];
  long  off = (long)arm[δ];
  (ο[--β] = τ), goTo(oba, arm + off, srd);
}
N(goTo_ρδ ) { (ο[--β] = τ), goTo(oba, τ[(ρ + 1) * δ], srd); }
N(true_var     ) {
  static void*b_Yellow[] = {T(tab), T(Yellow), T(toti),   T(tab)};
  static void*b_Red   [] = {T(tab), T(Red),    T(toti),   T(tab)};
  static void*b_Green [] = {T(tab), T(Green),  T(toti),   T(tab)};
  static void*b_Blue  [] = {T(tab),                       T(tab)};
  static void*a_Blue  [] = {T(tab),                       T(tab)};
  static void*a_Green [] = {T(tab), T(toti),   T(Green),  T(tab)};
  static void*a_Red   [] = {T(tab), T(toti),   T(Red),    T(tab)};
  static void*a_Yellow[] = {T(tab), T(toti),   T(Yellow), T(tab)};
  τ[-4] = 38 + b_Yellow;
  τ[-3] = 38 + b_Red;
  τ[-2] = 38 + b_Green;
  τ[-1] = 16 + b_Blue;
  τ[+1] =  5 + a_Blue;
  τ[+2] =  5 + a_Green;
  τ[+3] =  5 + a_Red;
  τ[+4] =  5 + a_Yellow;
  ((n_t)(*τ = goTo_ρδ))(obatsrd);
}

N(var     ) {
  τ[-4] = τ[+4] = true_var;
  τ[-3] = τ[+3] = goTo;
  τ[-2] = τ[+2] = true_var;
  τ[-1] = τ[+1] = goTo;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}


#define D(S, ...)                                                     \
  N(S) {                                                              \
    τ[5] = (void*[]) {0,(void*)LEN(__VA_ARGS__),0,0, __VA_ARGS__};    \
    var(obatsrd);                                                     \
  }
#include<string.h>
N(in) {
  ο[σ++] = (void*)(strlen(τ[5]) - 1);
  ο[σ++] = τ[5];
  ο[σ++] = 0;
  goTo(obatsrd);
}
N(in_a) { (τ[-δ] = goTo), (τ[+δ] = in), ((n_t)(*τ = δ_switch))(obatsrd); }
N(in_b) { (τ[-δ] = in), (τ[+δ] = goTo), ((n_t)(*τ = δ_switch))(obatsrd); }
N(term_parse  ) { 
  char*s = ο[σ - 2];
  long c = (long)τ[5];
  long*r = (long*)(ο + σ - 2);
  if (s[r[δ]] == c) (r[δ] += δ), goTo(obatsrd);
  else goTo(oba, τ, σ, ρ - 1, δ);
}
N(term    ) {
  τ[-4] = τ[+4] = term_parse;
  τ[-3] = τ[+3] = goTo;
  τ[-2] = τ[+2] = term_parse;
  τ[-1] = τ[+1] = goTo;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
N(b) { (τ[5] = (void*)'b'), term(obatsrd); }
N(a) { (τ[5] = (void*)'a'), term(obatsrd); }
N(t) { (τ[5] = (void*)'t'), term(obatsrd); }
N(s) { (τ[5] = (void*)'s'), term(obatsrd); }
N(print) {
  if(σ) {
    printf("%7s P_(", rays[(ρ + 1) * δ + 5]);
    for (long i = 0; i < σ; i++)
      if ((long)ο[i] < 100) printf("%ld", (long)ο[i]);
      else printf("%s", (char *)ο[i]);
    printf(")\n");
  }
  goTo(obatsrd);
}
N(n1   ) { (ο[σ++] = "1"), goTo(obatsrd); }
N(n2   ) { (ο[σ++] = "2"), goTo(obatsrd); }
N(n3   ) { (ο[σ++] = "3"), goTo(obatsrd); }
N(n4   ) { (ο[σ++] = "4"), goTo(obatsrd); }
N(n5   ) { (ο[σ++] = "5"), goTo(obatsrd); }

N(sb   ) { (ο[σ++] = "b"), goTo(obatsrd); }
N(sa   ) { (ο[σ++] = "a"), goTo(obatsrd); }
N(st   ) { (ο[σ++] = "t"), goTo(obatsrd); }

N(goTo_Green) { goTo(oba,τ,σ,1,δ); }
D(n345, B(T(n3)),
        B(T(n4)),
        B(T(n5)))
D(n123, B(T(n1)),
        B(T(n2)),
        B(T(n3), T(n345)))
N(b1_) { P; goTo(obatsrd); }N(_b1) { P; goTo(obatsrd); }
N(a1_) { P; goTo(obatsrd); }N(_a1) { P; goTo(obatsrd); }
N(t1_) { P; goTo(obatsrd); }N(_t1) { P; goTo(obatsrd); }
N(b2_) { P; goTo(obatsrd); }N(_b2) { P; goTo(obatsrd); }
N(a2_) { P; goTo(obatsrd); }N(_a2) { P; goTo(obatsrd); }
N(t2_) { P; goTo(obatsrd); }N(_t2) { P; goTo(obatsrd); }
N(b3_) { P; goTo(obatsrd); }N(_b3) { P; goTo(obatsrd); }
N(a3_) { P; goTo(obatsrd); }N(_a3) { P; goTo(obatsrd); }
N(t3_) { P; goTo(obatsrd); }N(_t3) { P; goTo(obatsrd); }
N(bs) { P; goTo(obatsrd); }
N(as) { P; goTo(obatsrd); }

D(bat,
  B(T(sb)),
  B(T(sa)),
  B(T(st)),
)
D(bat_1,B(T(b1_), T(b), T(_b1)),
        B(T(a1_), T(a), T(_a1)),
        B(T(t1_), T(t), T(_t1)),)
D(bat_2,B(T(b2_), T(b), T(_b2)),
        B(T(a2_), T(a), T(_a2)),
        B(T(t2_), T(t), T(_t2)),)
D(bat_3,B(T(b3_), T(b), T(_b3)),
        B(T(a3_), T(a), T(_a3)),
        B(T(t3_), T(t), T(_t3)),)
D(S,
  B(T(b)),
  B(T(S), T(a)),
  B(T(S), T(t)),
)
int main() {
  void *ο[512] = {};
  long  β      = sizeof(ο) / sizeof(*ο), α = 0;
  void**τ      = 5 + (void*[]) {
    T(bo),
    T(print),
//    T5(in_a, "bat"),
    T(bat),
    T(bat),
    T(bat),
//    T5(in_b, "bat"),
    T(print),
    T(bo),
  };
  long  σ      = 0, ρ = 3, δ = 1;
  goTo(obatsrd);
}
