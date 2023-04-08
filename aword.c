#include "aword.h"
#include <assert.h>
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>
N(r) { m(τ, ρ, δ); }
N(cb) {
  if (ρ == 1)
    m(τ, ρ, 1);
  else
    m(τ[5], ρ, (long)τ[-5]);
}
N(toti_pith) {
  if (ρ == 3 && δ == -1) {
    ((void **)τ[5])[5] = τ;
    ((long *)τ[5])[-5] = -1;
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
W(begin_drawing, 1, 1) {
  BeginDrawing();
  ClearBackground(BLACK);
  m(τ, ρ, δ);
}
W(end_drawing, 1, 1) {
  EndDrawing();
  if (WindowShouldClose())
    CloseWindow();
  else
    m(τ, ρ, δ);
}
W(seven, 1, 1) {
  DrawText("7", 100, 100, 45, RED);
  m(τ, ρ, δ);
}
int main() {
  InitWindow(1800, 1000, "aword");
  SetTargetFPS(60);
  void *text[] = {T(b),    T(begin_drawing), T(seven),
                  T(toti), T(end_drawing),   T(o)};
  m(text + 5, 3, 1);
}
