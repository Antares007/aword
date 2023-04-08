#include<raylib.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
long ident = 0;
#define P                                                                      \
  ({                                                                           \
    for (long i = 0; i < ident; i++)                                           \
      printf("  ");                                                            \
  }),                                                                          \
      printf("%ld %2ld %s\n", ρ, δ, __FUNCTION__), usleep(200000)
#define N(arg) void arg(Args)
#define Args void **τ, long ρ, long δ
#define T(ina) 0, 0, 0, 0, 0, ina, 0, 0, 0, 0, 0

N(m) { ((N((**)))τ)[11 * δ](τ + 11 * δ, ρ, δ); }
N(b) { m(τ, ρ, δ * -1); }
N(cb) {
  if (ρ == 1)
    m(τ, ρ, 1);
  else
    ident--, m(τ[5], ρ, (long)τ[-5]);
}
N(r) { P, m(τ, ρ, δ); }
N(o) { m(τ, ρ == 3 ? 1 : ρ == 1 ? 3 : ρ, δ * -1); }
N(toti_pith) {
  if (ρ == 3 && δ == -1) {
    ((void **)τ[5])[5] = τ;
    ((long *)τ[5])[-5] = -1;
    ident++;
    m(τ[5], ρ, 1);
  } else
    m(τ, ρ, δ);
}
N(toti) {
  void *tot[] = {T(cb), T(r), T(o)};
  *τ = toti_pith;
  τ[5] = tot + 5;
  toti_pith(τ, ρ, δ);
}
int main() {
  InitWindow(1800,1000, "aword");
  SetTargetFPS(60);
  //void *text[] = {T(b), T(toti), T(r), T(o)};
  //m(text + 5, 3, 1);
  while(!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    EndDrawing();
  }
  CloseWindow();
}
N(go_Yellow) /*    */ {}
N(go_Red) /*       */ {}
N(go_Green) /*     */ {}
N(go_Blue) /*      */ {}
N(go_DarkBlue) /*  */ {}
N(go_DarkGreen) /* */ {}
N(go_DarkRed) /*   */ {}
N(go_DarkYellow) /**/ {}
N(aradani_pith) {}
N(not) {
  τ[+1 + 3] = /*Yellow*/ go_DarkGreen;
  τ[+1 + 2] = /*Red   */ go_Yellow;
  τ[+1 + 1] = /*Green */ go_DarkYellow;
  τ[+1 + 0] = /*Blue  */ go_DarkBlue;
  τ[0] = aradani_pith;
  τ[-1 - 0] = /*DarkBlue  */ go_DarkBlue;
  τ[-2 - 1] = /*DarkGreen */ go_Green;
  τ[-3 - 2] = /*DarkRed   */ go_DarkRed;
  τ[-4 - 3] = /*DarkYellow*/ go_DarkYellow;
  aradani_pith(τ, ρ, δ);
}
N(and) {
  τ[+1 + 3] = /*Yellow*/ go_DarkGreen;
  τ[+1 + 2] = /*Red   */ go_Red;
  τ[+1 + 1] = /*Green */ go_Yellow;
  τ[+1 + 0] = /*Blue  */ go_Blue;
  τ[0] = aradani_pith;
  τ[-1 - 0] = /*DarkBlue  */ go_DarkBlue;
  τ[-2 - 1] = /*DarkGreen */ go_Green;
  τ[-3 - 2] = /*DarkRed   */ go_DarkRed;
  τ[-4 - 3] = /*DarkYellow*/ go_DarkYellow;
  aradani_pith(τ, ρ, δ);
}
N(or) {
  τ[+1 + 3] = /*Yellow*/ go_DarkGreen;
  τ[+1 + 2] = /*Red   */ go_Red;
  τ[+1 + 1] = /*Green */ go_DarkYellow;
  τ[+1 + 0] = /*Blue  */ go_Yellow;
  τ[0] = aradani_pith;
  τ[-1 - 0] = /*DarkBlue  */ go_DarkBlue;
  τ[-2 - 1] = /*DarkGreen */ go_Green;
  τ[-3 - 2] = /*DarkRed   */ go_DarkRed;
  τ[-4 - 3] = /*DarkYellow*/ go_DarkYellow;
  aradani_pith(τ, ρ, δ);
}
N(orand) {
  τ[+1 + 3] = /*Yellow*/ go_DarkGreen;
  τ[+1 + 2] = /*Red   */ go_Red;
  τ[+1 + 1] = /*Green */ go_Yellow;
  τ[+1 + 0] = /*Blue  */ go_Yellow;
  τ[0] = aradani_pith;
  τ[-1 - 0] = /*DarkBlue  */ go_DarkBlue;
  τ[-2 - 1] = /*DarkGreen */ go_Green;
  τ[-3 - 2] = /*DarkRed   */ go_DarkRed;
  τ[-4 - 3] = /*DarkYellow*/ go_DarkYellow;
  aradani_pith(τ, ρ, δ);
}
