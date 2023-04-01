#include "aword.h"
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>
static Font font; 
N(text_index_hart) { ((w_t *)o)[a](o, t, a, r, i); }
N(text_index_index) {
  char text[70];
  snprintf(text, 70, "%s %ld %ld %ld", (char *)o[(t + i * 3) - 1], t + i * 3, r,
           i);
  float fontSize = 45;
  float spacing = 4;
  Color tint = YELLOW;
  static Vector2 position = {100, 200};
  Vector2 m = MeasureTextEx(font, text, fontSize, spacing);
  position.y += m.y * -i;
  while (GetCharPressed() != 'n') {
    if (WindowShouldClose())
      return;
    BeginDrawing();
    ClearBackground(DARKPURPLE);
    DrawText(TextFormat("%i", GetFPS()), 0, 0, 45, RED);
    DrawTextEx(font, text, position, fontSize, spacing, tint);
    EndDrawing();
  }
  ((w_t *)o)[a + 1](o, t, a, r, i);
}
N(text_index) {
  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(0);
  InitWindow(800, 600, "aword multitasking");
  font = LoadFont("NovaMono-Regular.ttf");
  o[--a] = text_index_index;
  o[t] = text_index_hart;
  text_index_hart(o, t, a, r, i);
  CloseWindow();
}
