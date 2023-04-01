#include "aword.h"
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>
static Font font;

static long v[100][4];
static long v_i = 0;
N(text_index_hart) {
  if (i == 1 && r == 3)
    v_i = 0;
  ((w_t *)o)[a](o, t, a, r, i);
}
N(text_index_index) {
  static Color ray_colors[] = {
      PURPLE, // Purple
      YELLOW, // Yellow
      RED,    // Red
      GREEN,  // Green
      BLUE,   // Blue
      BLACK,
      DARKBLUE, // Dark Blue
      LIME,     // Lime
      MAROON,   // Maroon
      GOLD,     // Gold
      MAGENTA,  // Magenta
  };
  float fontSize = 25;
  float spacing = 4;
  static Vector2 position = {100, 300};
  const long WW = 100;
  position.x += WW * -i;
  long ti = (t + i * 3) - 1;
  long ray = (r + 1) * i + 5;
  v[v_i][0] = position.x;
  v[v_i][1] = position.y;
  v[v_i][2] = ti;
  v[v_i][3] = ray;
  v_i = (v_i + 1) % 100;

  while (GetCharPressed() != 'n') {
    if (WindowShouldClose())
      return;
    BeginDrawing();
    ClearBackground(DARKPURPLE);
    DrawText(TextFormat("%i", GetFPS()), 0, 0, 45, RED);
    char text[70];
    const char *texts[] = {"A", "b", "W", "x", "y"};
    for (long i = 0; i < 5; i++) {
      Vector2 m = MeasureTextEx(font, texts[i], 25, 4);
      snprintf(text, 70, "%f %f", m.x, m.y);
      DrawText(text, 10, i*50, 45, BLACK);
    }
    for (long i = 0; i < v_i; i++) {
      snprintf(text, 70, "%7s", (char *)o[v[i][2]]);
      DrawRectangle(v[i][0], v[i][1] + (v[i][3] - 5) * 20, WW-2, 30,
                    ray_colors[v[i][3]]);
      DrawTextEx(font, text, (Vector2){v[i][0], v[i][1] + (v[i][3] - 5) * 20},
                 fontSize, spacing, BLACK);
    }
    EndDrawing();
  }
  ((w_t *)o)[a + 1](o, t, a, r, i);
}
N(tndx) {
  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(0);
  InitWindow(1500, 600, "aword multitasking");
  font = LoadFont("NovaMono-Regular.ttf");
  o[--a] = text_index_index;
  o[t] = text_index_hart;
  text_index_hart(o, t, a, r, i);
  CloseWindow();
}
