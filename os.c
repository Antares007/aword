#include "aword_colors.h"
#include "awords.h"
#include <raylib.h>
static Font font;
N(begindrawing) {
  if (Green(==) && White(==))
    BeginDrawing(), ClearBackground(BLACK);
  m(α, ω, ο, ρ, δ, σ);
};
N(enddrawing) {
  if (Green(==) && White(==))
    EndDrawing();
  m(α, ω, ο, ρ, δ, σ);
};
N(the_end) {
  if (Green(!=) || White(!=))
    m(α, ω, ο, ρ, δ, σ);
}
N(fps) {
  if (Green(==) && White(==))
    DrawTextEx(font, TextFormat("%d", GetFPS()), (Vector2){0, 0}, 25, 4, WHITE);
  m(α, ω, ο, ρ, δ, σ);
}
N(shouldclose) {
  if (Green(==) && White(==))
    m(α, ω, ο, !!WindowShouldClose(), δ, σ);
  else
    m(α, ω, ο, ρ, δ, σ);
}
N(getcharpressed) {
  if (Green(==) && Black(==)) {
    long key = GetCharPressed();
    if (key)
      ο[ω OP(+) 1].q = key;
    if (ο[ω OP(+) 1].q) {
      ο[σ++] = ο[ω OP(+) 1];
      m(α, ω, ο, Green(=), δ, σ);
    } else
      m(α, ω, ο, Blue(=), δ, σ);
  } else
    m(α, ω, ο, ρ, δ, σ);
}
N(write_char) {
  if (Green(==) && White(==))
    DrawTextEx(font, TextFormat("%ld", ο[--σ]), (Vector2){200, 100}, 45, 4,
               WHITE);
  m(α, ω, ο, ρ, δ, σ);
}
N(not );
N(and);
N(orand);
N(or);
N(left) {
  DrawText("left", 200, 0, 45, YELLOW);
  m(α, ω, ο, ρ, δ, σ);
}
N(right) {
  DrawText("right", 400, 0, 45, RED);
  m(α, ω, ο, ρ, δ, σ);
}
N(us) {
  D(B(T(b) T(left) T(o)), B(T(b) T(right) T(o)));
  toti(α, ω, ο, ρ, δ, σ);
}
int main() {
  long α = 1024, ω;
  text_t ο[α];
  long ρ = 3, δ = 1, σ = 0;
  ω = B(T(b)                                                   //
        T(begindrawing) T(fps)                                 //
        T(and) T(getcharpressed) T(write_char)                 //
        T(us)                                                  //
        T(orand) T(shouldclose) T(the_end) T(or) T(enddrawing) //
        T(o));
  ο[ω OP(-) 1].q = ω;
  ο[ω OP(+) 1].q = 1;
  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(60);
  InitWindow(1500, 900, "aword os");
  font = LoadFont("NovaMono-Regular.ttf");
  m(α, ω, ο, ρ, δ, σ);
  CloseWindow();
  return 0;
}
