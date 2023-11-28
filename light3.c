// clang-format off
#define N(argo) void argo(void **ο, long β, long α, void **τ, long σ, long ρ, long δ)
typedef N((*n_t));
//#define P (void)0
#define P printf("%ld %ld %7s %s\n", α, β, rays[(ρ + 1) * δ + 5], __FUNCTION__), usleep(20000)
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

N(ρδ_switch ) { ((n_t)τ[(ρ + 1) * δ])(ο, β, α, τ, σ, ρ, δ); }
N(δ_switch  ) { ((n_t)τ[          δ])(ο, β, α, τ, σ, ρ, δ); }

N(tab) { goTo(ο, β + 1, α, ο[β], srd); }
N(bat) { (ο[--α] = τ), tab(obatsrd); }
N(toti) {
  long*c = ((void***)ο)[β][5];
  void**a = (void*)(c + 2);
  (ο[--β] = τ), goTo(oba, a[c[0]], srd);
}
N(Yellow_Yellow ) {
  long*c = ((void***)ο)[β][5];
  goTo(oba, τ, σ, !(c[0] = (c[0] + 1) % c[1]) * 2 + 1, δ);
}
N(Yellow_Red ) {
  long*c = ((void***)ο)[β][5];
  goTo(oba, τ, σ, !(c[0] = (c[0] + 1) % c[1]) * 2, δ);
}
N(Yellow_Green  ) { goTo(obatsrd); }
N(Yellow_Blue   ) { goTo(obatsrd); }
N(Yellow) {
  τ[+4] = Yellow_Yellow;
  τ[+3] = Yellow_Red;
  τ[+2] = Yellow_Green;
  τ[+1] = Yellow_Blue;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
N(Red_Red ) {
  long*c = ((void***)ο)[β][5];
  goTo(oba, τ, σ, !(c[0] = (c[0] + 1) % c[1]) * 2, δ);
}
N(Red_Blue  ) { goTo(obatsrd); }
N(Red) {
  τ[+3] = Red_Red;
  τ[+1] = Red_Blue;
  ((n_t)(*τ = ρδ_switch))(obatsrd);
}
N(itot ) {  (ο[--β] = τ), goTo(ο, β, α + 1, ο[α], srd);}
N(goTo_δρ) { (ο[--β] = τ), goTo(oba, τ[(ρ + 1) * δ], srd); }
N(var) {
  τ[+4] = (void*[]) {T(tab), T(toti), T(Yellow), T(tab)} + 05;
  τ[+3] = (void*[]) {T(tab), T(toti), T(Red), T(tab)} + 05;
  τ[+2] = (void*[]) {T(tab), T(toti), T(tab)} + 05;
  τ[+1] = (void*[]) {T(tab), T(toti), T(tab)} + 05;

  τ[-1] = (void*[]) {T(tab), T(itot), T(tab)} + 27;
  τ[-2] = (void*[]) {T(tab), T(itot), T(tab)} + 27;
  τ[-3] = (void*[]) {T(tab), T(itot), T(tab)} + 27;
  τ[-4] = (void*[]) {T(tab), T(itot), T(tab)} + 27;
  ((n_t)(*τ = goTo_δρ))(obatsrd);
}

N(str_oa) { (ο[σ++] = τ[2]), goTo(obatsrd); }
N(str) {
  τ[-δ]     = goTo;
  τ[+δ]     = str_oa;
  ((n_t)(*τ = δ_switch))(obatsrd);
}
N(n0) { (τ[2] = "0"), str(obatsrd); }
N(n1) { (τ[2] = "1"), str(obatsrd); }
N(n2) { (τ[2] = "2"), str(obatsrd); }
N(n3) { (τ[2] = "3"), str(obatsrd); }
N(n4) { (τ[2] = "4"), str(obatsrd); }
N(n5) { (τ[2] = "5"), str(obatsrd); }
N(n6) { (τ[2] = "6"), str(obatsrd); }
N(n7) { (τ[2] = "7"), str(obatsrd); }
N(n8) { (τ[2] = "8"), str(obatsrd); }
N(n9) { (τ[2] = "9"), str(obatsrd); }
N(print   ) {
  if (σ) {
    printf("(");
    for (long i = 0; i < σ; i++)
      printf("%s", (char *)ο[i]);
    printf(")%s\n", rays[(ρ + 1) * δ + 5]);
    usleep(200000);
  }
  (σ = 0), goTo(obatsrd);
}
N(in) { goTo(oba, τ, τ[δ], ρ, δ); }

N(S) { 
  τ[5] = (void*[]){0,3, (void*[]){ T(tab), T(n1), T(bat) } + 5,
                        (void*[]){ T(tab), T(n2), T(bat) } + 5,
                        (void*[]){ T(tab), T(n3), T(bat) } + 5, };
  var(obatsrd);
}
int main() {
  void *ο[512];
  long β = sizeof(ο) / sizeof(*ο);
  long α = β / 4 * 3;
  void **τ = 5 + (void *[]) { T(bro), T(S), T(S), T(S), T(print), T(o) };
  long σ = 0;
  long ρ = 3;
  long δ = 1;

  goTo(ο, β, α, τ, σ, ρ, δ);
}
//N(terminal_parse) {
//  char*s = τ[2];
//  long i = 0;
//  while (s[i] && s[i] == σ[i]) i++;
//  if (s[i] == 0) (ο[α++] = s), goTo(oba, τ, σ + i, ρ, δ);
//  else                         goTo(oba, τ, σ, ρ - 1, δ);
//}
//N(terminal) {
//  τ[-δ]     = goTo;
//  τ[+δ]     = terminal_parse;
//  ((n_t)(*τ = δ_switch))(obatsrd);
//}
//N(ε) {P; (τ[2] = ""),  terminal(obatsrd); }
//N(s) {P; (τ[2] = "s"), terminal(obatsrd); }
//N(b) {P; (τ[2] = "b"), terminal(obatsrd); }
//N(a) {P; (τ[2] = "a"), terminal(obatsrd); }
//N(t) {P; (τ[2] = "t"), terminal(obatsrd); }
//N(plus) {P; (τ[2] = "+"), terminal(obatsrd); }
//N(mul ) {P; (τ[2] = "*"), terminal(obatsrd); }
//N(op  ) {P; (τ[2] = "("), terminal(obatsrd); }
//N(cp  ) {P; (τ[2] = ")"), terminal(obatsrd); }
