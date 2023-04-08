#include "awords.h"
#include <raylib.h>
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
N(begindrawing_pith) {
  if (ρ.ray == 1 && δ.dir == 1)
    BeginDrawing(), ClearBackground(BLACK);
  go(α, ω, ο, ρ, δ, σ);
}
N(begindrawing) {
  P;
  α.win -= 4, ο[--α.win].go = begindrawing_pith, α.win -= 4;
  --σ.win, ο[σ.win].go(α, ω, ο, ρ, δ, σ);
};
N(enddrawing_pith) {
  if (ρ.ray == 1 && δ.dir == 1)
    EndDrawing();
  go(α, ω, ο, ρ, δ, σ);
};
N(enddrawing) {
  P;
  α.win -= 4, ο[--α.win].go = enddrawing_pith, α.win -= 4;
  --σ.win, ο[σ.win].go(α, ω, ο, ρ, δ, σ);
};
N(fps_pith) {
  if (ρ.ray == 1 && δ.dir == 1)
    DrawTextEx(font, TextFormat("%d", GetFPS()), (Vector2){0, 0}, 25, 4, WHITE);
  go(α, ω, ο, ρ, δ, σ);
}
N(fps) {
  P;
  α.win -= 4, ο[--α.win].go = fps_pith, α.win -= 4;
  --σ.win, ο[σ.win].go(α, ω, ο, ρ, δ, σ);
};

N(the_end) {
  if (ρ.ray != 1 || δ.dir != 1)
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
#include <assert.h>
N(m_pith) { P, go(α, ω, ο, ρ, δ, σ); }
N(m) { P,
  α.win -= 4, ο[--α.win].v = m_pith, α.win -= 4;
  ο[--σ.win].go(α, ω, ο, ρ, δ, σ); }
N(branch_pith) { P; }
N(branch) {
  α.win -= 4, ο[ω.win = --α.win].v = branch_pith, α.win -= 4;
  ο[σ.win++].v = b;
  ο[σ.win++].v = m;
  ο[σ.win++].v = o;
  ο[--σ.win].go(α, ω, ο, ρ, δ, σ);
}
int main() {
  win_v α = {1024}, ω;
  txt_t β[α.win + 1 + α.win];
  txt_t *ο = β + α.win;
  //  α.win = 0 - α.win;
  ray_v ρ = {3};
  dir_v δ = {-1};
  win_v σ = {0};
  ο[σ.win++].v = b;
  ο[σ.win++].v = branch;
  // ο[σ.win++].v = begindrawing;
  // ο[σ.win++].v = fps;
  // ο[σ.win++].v = print;
  // ο[σ.win++].v = orand;
  // ο[σ.win++].v = shouldclose;
  // ο[σ.win++].v = the_end;
  // ο[σ.win++].v = or;
  // ο[σ.win++].v = enddrawing;
  ο[σ.win++].v = o;
  //  SetTraceLogLevel(LOG_ERROR);
  //  SetTargetFPS(60);
  //  InitWindow(1500, 900, "aword os");
  //  font = LoadFont("NovaMono-Regular.ttf");

  --σ.win, ο[σ.win].go(α, ω, ο, ρ, δ, σ);

  //  CloseWindow();
  return 0;
}
