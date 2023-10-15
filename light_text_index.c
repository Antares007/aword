#include <assert.h>
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <unistd.h>
#include "light.h"

static Font font;
float zoom = 1;
Vector2 off = {0, 0};
typedef struct step_t {
  const char*name;
  long r;
  long d;
} step_t;
static Color colors[] = {
  {128, 128, 000, 255}, // Olive
  {128, 000, 000, 255}, // Maroon
  {000, 255, 000, 255}, // Lime
  {000, 000, 128, 255}, // Navy
  {000, 000, 000, 255}, // Black
  {000, 000, 255, 255}, // Blue
  {000, 128, 000, 255}, // Green
  {255, 000, 000, 255}, // Red
  {255, 255, 000, 255}, // Yellow
};
#include <string.h>
#include <stdlib.h>
void draw(step_t *steps, long count) {
  int key = 0;
  static int semi_auto = 0;
  do {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      off = Vector2Add(off, GetMouseDelta());
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    BeginDrawing();
    ClearBackground(WHITE);

    Vector2 zero = {2 * GetScreenWidth() / 8.f, 3 * GetScreenHeight() / 8.f};
    Vector2 dir = {0, -1};
    long si = 0;
    for (long i = si; i < count; i++) {
      step_t *s = &steps[i];
      if (strcmp(s->name, "bo") == 0) {
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(),
                      (Color){.a = 150, .r = -1, .g = -1, .b = -1});
        si = i;
      }
      Vector2 ns = {90, 50};
      Camera2D camera = {.target = {0, 0},
                         .rotation = 0,
                         .zoom = zoom,
                         .offset = Vector2Add(off, zero)};
      BeginMode2D(camera);
      Color bgcolor = colors[(s->r + 1) * s->d + 4];
      Color fgcolor = BLACK;
      DrawRectangle(-ns.x / 2, -ns.y / 2, ns.x, ns.y, bgcolor);
      DrawRectangleLines(-ns.x / 2, -ns.y / 2, ns.x, ns.y, BLACK);
      DrawTextEx(font, s->name, (Vector2){-ns.x / 2, -ns.y / 2}, 35, 1, fgcolor);
      EndMode2D();
      if (i < count-1 && strcmp(steps[i + 1].name, "tab") == 0 && s->d == 1) 
        dir = Vector2Rotate(dir, M_PI_2 * s->d);
      float step_size = ((long)dir.x ? ns.x : ns.y) * s->d;
      zero = Vector2Add(zero, Vector2Scale(dir, zoom * step_size));
      if (strcmp(steps[i].name, "tab") == 0 && s->d == -1) 
        dir = Vector2Rotate(dir, M_PI_2 * s->d);
    }
    EndDrawing();
    key = GetCharPressed();
    if (key == 'c')           semi_auto = !semi_auto;
    if (WindowShouldClose())  exit(0);
  } while (key != 'n' && !semi_auto);
}
#include <string.h>
void ti_step(const char*name, long r, long d) {
  static step_t steps[2048];
  static long count = 0;
  steps[count].name = name;
  steps[count].r = r;
  steps[count].d = d;
  count++;
  draw(steps, count);
}
void ti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1500, 800, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 35, 0, 0);
}
