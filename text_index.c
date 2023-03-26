#include "aword.h"
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct aword {
  Vector2 d;
  Color color;
  const char *name;
} aword;
static aword awords[0x1000] = {
    {.d = {.x = 0, .y = 1}, .color = YELLOW, .name = "b"}};
static int length = 1;

static void draw_aword(Vector2 *pos, aword *aw, int step) {
  Font font = GetFontDefault();
  float fontSize = 10 + step * 4;
  float spacing = 10;
  Vector2 m = MeasureTextEx(font, aw->name, fontSize, spacing);
  DrawRectangle(pos->x - 10, pos->y - 10, m.x + 20, m.y + 20, aw->color);
  DrawTextPro(font, aw->name, *pos, (Vector2){0, 0}, 0, fontSize, spacing,
              BLACK);
  pos->x += m.x * aw->d.x + 25 * aw->d.x;
  pos->y += m.y * aw->d.y + 25 * aw->d.y;
}
static void draw() {
  BeginDrawing();
  ClearBackground(BLACK);
  Vector2 pos = {GetScreenWidth() / 2.f, GetScreenHeight() / 8.f};
  for (long i = 1; i < length; i++) {
    draw_aword(&pos, &awords[i], i);
  }
  EndDrawing();
}
#include <assert.h>
N(text_index) {
  int dstep = δ / 3;
  aword *last = &awords[length - 1 * dstep];
  aword *this = &awords[length];
  this->name = ω[1].cs;
  static Color colors[] = {
      (Color){.a = 0xFF, .b = 0x00, .g = 0x77, .r = 0x77}, // DarkYellow
      (Color){.a = 0xFF, .b = 0x00, .g = 0x00, .r = 0x77}, // DarkRed
      (Color){.a = 0xFF, .b = 0x00, .g = 0x77, .r = 0x00}, // DarkGreen
      (Color){.a = 0xFF, .b = 0x77, .g = 0x00, .r = 0x00}, // DarkBlue
      (Color){.a = 0xFF, .b = 0x00, .g = 0x00, .r = 0x00}, // Black
      (Color){.a = 0xFF, .b = 0xFF, .g = 0x00, .r = 0x00}, // Blue
      (Color){.a = 0xFF, .b = 0x00, .g = 0xFF, .r = 0x00}, // Green
      (Color){.a = 0xFF, .b = 0x00, .g = 0x00, .r = 0xFF}, // Red
      (Color){.a = 0xFF, .b = 0x00, .g = 0xFF, .r = 0xFF}, // Yellow
  };
  this->color = colors[4 + (ρ + 1) * dstep];
  if (ω[-1].v == right_arm) {
    this->d.x = last->d.y * dstep;
    this->d.y = last->d.x * dstep * -1;
  } else if (ω[-1].v == left_arm || ω[-1].v == last_arm) {
    this->d.x = last->d.y * dstep * -1;
    this->d.y = last->d.x * dstep;
  } else {
    this->d = last->d;
  }
  length += dstep;
  if (WindowShouldClose())
    CloseWindow();
  else
    draw(), X;
}
void text_index_init() {
  SetTraceLogLevel(LOG_WARNING);
  InitWindow(GetScreenHeight(), GetScreenHeight(), "actionable word show");
  SetTargetFPS(79);
}
