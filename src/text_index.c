#include "aword.h"
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct step_t {
  Vector2 d;
  Color color;
  const char *name;
} step_t;
static step_t awords[0x1000] = {
    {.d = {.x = 0, .y = 1}, .color = YELLOW, .name = "b"}};
static int length = 1;

static void draw_aword(Vector2 *pos, step_t *aw, int step) {
  Font font = GetFontDefault();
  float fontSize = 20 + step * 2;
  float spacing = 10;
  Vector2 m = MeasureTextEx(font, aw->name, fontSize, spacing);
  DrawRectangle(pos->x - 10, pos->y - 10, m.x + 20, m.y + 20, aw->color);
  DrawTextPro(font, aw->name, *pos, (Vector2){0, 0}, 0, fontSize, spacing,
              BLACK);
  pos->x += m.x * aw->d.x + 25 * aw->d.x;
  pos->y += m.y * aw->d.y + 25 * aw->d.y;
}
// static Vector2 pos = {400, 300}, dir = {0, 1};
// static Color ray = WHITE;
// static char *title = "b";

static void draw() {
  BeginDrawing();
  ClearBackground(BLACK);
  EndDrawing();
}
#include <assert.h>
static void turn_left(aword) { printf("%s\n", __FUNCTION__); }
static void turn_right(aword) { printf("%s\n", __FUNCTION__); }
static void turn_around(aword) {
  turn_right(a, w, o, r, d);
  turn_right(a, w, o, r, d);
}
static void move_forward(aword) {
  printf("%s %s\n", __FUNCTION__, (char *)o[w - 1]);
}
static void update(aword) {
  if      (dot        == o[w])  turn_around(a, w, o, r, d);
  else if (b          == o[w]);  
  else if (left_arm   == o[w]);  
  else if (s          == o[w]);  
  else if (right_arm  == o[w])  turn_left(a, w, o, r, d);
  else                          move_forward(a, w, o, r, d);
}
// void*root[];
void text_index(aword) {
  update(a, w, o, r, d);
  int key = GetCharPressed();
  while (key != 'n') {
    key = GetCharPressed();
    if (key == 's')
      return;
    draw();
  }
  ((void (**)(long, long, void *, long, long))o)[w + d](a, w + d, o, r, d);
}
void text_index_init() {
  SetTraceLogLevel(LOG_WARNING);
  InitWindow(800, 600, "actionable word show");
  SetTargetFPS(0);
}
// static Color colors[] = {
//     (Color){.a = 0xFF, .b = 0x00, .g = 0x77, .r = 0x77}, // DarkYellow
//     (Color){.a = 0xFF, .b = 0x00, .g = 0x00, .r = 0x77}, // DarkRed
//     (Color){.a = 0xFF, .b = 0x00, .g = 0x77, .r = 0x00}, // DarkGreen
//     (Color){.a = 0xFF, .b = 0x77, .g = 0x00, .r = 0x00}, // DarkBlue
//     (Color){.a = 0xFF, .b = 0x00, .g = 0x00, .r = 0x00}, // Black
//     (Color){.a = 0xFF, .b = 0xFF, .g = 0x00, .r = 0x00}, // Blue
//     (Color){.a = 0xFF, .b = 0x00, .g = 0xFF, .r = 0x00}, // Green
//     (Color){.a = 0xFF, .b = 0x00, .g = 0x00, .r = 0xFF}, // Red
//     (Color){.a = 0xFF, .b = 0x00, .g = 0xFF, .r = 0xFF}, // Yellow
// };
