#include "awords.h"
#include <raylib.h>
static Font font;
N(begindrawing) {
  if (Green(==) && White(==))
    BeginDrawing(), ClearBackground(BLACK);
  M(ρ);
};
N(enddrawing) {
  if (Green(==) && White(==))
    EndDrawing();
  M(ρ);
};
N(the_end) {
  if (Green(!=) || White(!=))
    M(ρ);
}
N(fps) {
  if (Green(==) && White(==))
    DrawTextEx(font, TextFormat("%d", GetFPS()), (Vector2){0, 0}, 25, 4, WHITE);
  M(ρ);
}
N(shouldclose) {
  if (Green(==) && White(==))
    M(!!WindowShouldClose());
  else
    M(ρ);
}
N(getcharpressed) {
  if (Green(==) && Black(==))
    ({
      long key = GetCharPressed();
      if (key)
        ω[+1] = (void *)key;
      if (ω[+1]) {
        ο[σ++] = ω[+1];
        M(Green(=));
      } else
        M(Blue(=));
    });
  else
    M(ρ);
}
N(write_char) {
  if (Green(==) && White(==))
    DrawTextEx(font, TextFormat("%ld", ο[--σ]), (Vector2){200, 100}, 45, 4,
               WHITE),
        M(ρ);
  else
    M(ρ);
}
N(not );
N(and);
N(orand);
N(or);
N(left) {
  DrawText("left", 200, 0, 45, YELLOW);
  M(ρ);
}
N(right) {
  DrawText("right", 400, 0, 45, RED);
  M(ρ);
}
N(us) {
  ω[-1] = B(T(b) T(left) T(o)), ω[+1] = B(T(b) T(right) T(o));
  toti(α, ω, ο, ρ, δ, σ);
}
int main() {
  long α = 1024;
  void **ω, *ο[α];
  long ρ = 3, δ = 1, σ = 0;
  ω = B(T(b) T(begindrawing) T(fps) T(and) T(getcharpressed) T(write_char) T(us)
            T(orand) T(shouldclose) T(the_end) T(or) T(enddrawing) T(o));
  ω[-1] = ω, ω[+1] = (void *)1;
  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(60);
  InitWindow(1500, 900, "aword os");
  font = LoadFont("NovaMono-Regular.ttf");
  m(α, ω, ο, ρ, δ, σ);
  CloseWindow();
  return 0;
}
