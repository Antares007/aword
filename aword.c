#include <assert.h>
#include <raylib.h>
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
N(begin_drawing) {
  if (δ == 1) {
    BeginDrawing();
    ClearBackground(BLACK);
  }
  m(τ, ρ, δ);
}
N(end_drawing) {
  if (δ == 1) {
    EndDrawing();
    if (WindowShouldClose())
      CloseWindow();
    else
      m(τ, ρ, δ);
  } else
    m(τ, ρ, δ);
}
N(seven) {
  if (δ == 1) {
    DrawText("7", 100, 100, 45, RED);
  }
  m(τ, ρ, δ);
}
int main() {
  InitWindow(1800, 1000, "aword");
  SetTargetFPS(60);
  void *text[] = {T(b),    T(begin_drawing), T(seven),
                  T(toti), T(end_drawing),   T(o)};
  m(text + 5, 3, 1);
}
N(go_Yellow) /*    */ { m(τ, 3, +1); }
N(go_Red) /*       */ { m(τ, 2, +1); }
N(go_Green) /*     */ { m(τ, 1, +1); }
N(go_Blue) /*      */ { m(τ, 0, +1); }
N(go_DarkBlue) /*  */ { m(τ, 0, -1); }
N(go_DarkGreen) /* */ { m(τ, 1, -1); }
N(go_DarkRed) /*   */ { m(τ, 2, -1); }
N(go_DarkYellow) /**/ { m(τ, 3, -1); }
N(aradani_pith) {}
N(not ) {
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
