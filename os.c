#include "awords.h"
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>
N(go);
N(go_Green);
N(go_Blue);
N(o);
N(toti);
N(b);
N(and);
N(orand);
N(or);

static Font font;
N(begindrawing) {
  if (ρ.ray == 1 && δ.dir == 1)
    BeginDrawing(), ClearBackground(BLACK);
  go(α, ω, ο, ρ, δ, σ);
};
N(enddrawing) {
  if (ρ.ray == 1 && δ.dir == 1)
    EndDrawing();
  go(α, ω, ο, ρ, δ, σ);
};
N(the_end) {
  if (ρ.ray != 1 || δ.dir != 1)
    go(α, ω, ο, ρ, δ, σ);
}
N(fps) {
  if (ρ.ray == 1 && δ.dir == 1)
    DrawTextEx(font, TextFormat("%d", GetFPS()), (Vector2){0, 0}, 25, 4, WHITE);
  go(α, ω, ο, ρ, δ, σ);
}
N(shouldclose) {
  if (ρ.ray == 1 && δ.dir == 1)
    go(α, ω, ο, (ray_v){!!WindowShouldClose()}, δ, σ);
  else
    go(α, ω, ο, ρ, δ, σ);
}
N(getcharpressed) {
  if (ρ.ray == 1 && δ.dir == 1) {
    long key = GetCharPressed();
    if (key)
      P_Yellow(ω).q = key;
    if (P_Yellow(ω).q) {
      ο[Push(σ)] = P_Yellow(ω);
      go_Green(α, ω, ο, ρ, δ, σ);
    } else
      go_Blue(α, ω, ο, ρ, δ, σ);
  } else
    go(α, ω, ο, ρ, δ, σ);
}
N(write_char) {
  if (ρ.ray == 1 && δ.dir == 1)
    DrawTextEx(font, TextFormat("%ld", ο[Pull(σ)]), (Vector2){200, 100}, 45, 4,
               WHITE);
  go(α, ω, ο, ρ, δ, σ);
}
N(left) {
  DrawText("left", 200, 0, 45, YELLOW);
  go(α, ω, ο, ρ, δ, σ);
}
N(right) {
  DrawText("right", 400, 0, 45, RED);
  go(α, ω, ο, ρ, δ, σ);
}
N(print) {
  DrawText("heyy", 200, 200, 45, RED);
  go(α, ω, ο, ρ, δ, σ);
}
N(id1) { DrawText("Right", 300, 400, 45, RED), go(α, ω, ο, ρ, δ, σ); }
N(id2) { DrawText("Left", 400, 400, 45, YELLOW), go(α, ω, ο, ρ, δ, σ); }
N(us) {
  nar_t *arms[] = {(nar_t[]){id1, o}, (nar_t[]){id2, o}};
  P_Blue(ω).v = arms;
  P_DarkBlue(ω).q = sizeof(arms) / sizeof(*arms);
  toti(α, ω, ο, ρ, δ, σ);
}
#include <assert.h>
int main() {
  win_v α = {1024}, ω;
  txt_t β[α.win + 1 + α.win];
  txt_t *ο = β + α.win;
//  α.win = 0 - α.win;
  ray_v ρ = {3};
  dir_v δ = {1};
  win_v σ = {0};
  ω = Twin(b);
  T(begindrawing);
  assert(ο[Plus(ω, 0)].v == b);
  assert(ο[Plus(ω, 1 + 4 + 4)].v == begindrawing);
  T(fps), T(print);
  T(and), T(us);
  T(orand), T(shouldclose), T(the_end), T(or), T(enddrawing);
  T(o);

  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(60);
  InitWindow(1500, 900, "aword os");
  font = LoadFont("NovaMono-Regular.ttf");
  go(α, ω, ο, ρ, δ, σ);
  CloseWindow();
  return 0;
}
