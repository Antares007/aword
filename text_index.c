#include "aword.h"
#include <assert.h>
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <unistd.h>

static Font font;
static Color colors[] = {
    {128, 128, 000, 255}, // Olive
    {255, 000, 255, 255}, // Fuchsia
    {128, 000, 000, 255}, // Maroon
    {000, 255, 000, 255}, // Lime
    {000, 000, 128, 255}, // Navy
    {000, 000, 000, 255}, // Black
    {000, 000, 255, 255}, // Blue
    {000, 128, 000, 255}, // Green
    {255, 000, 000, 255}, // Red
    {128, 000, 128, 255}, // Purple
    {255, 255, 000, 255}, // Yellow

};
typedef struct step_t {
  Vector2 enter, zero, exit;
  const char *text;
  Color color;
} step_t;
static step_t path[1024];
static long path_length = 0;
static float zoom = 2;
static Vector2 off = {};
extern char *names[];
static void draw() {
  int key = GetCharPressed();
  while (key != 'n') {
    key = GetCharPressed();
    if (key == 'c')
      path_length = 0;
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      off = Vector2Add(off, GetMouseDelta());
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    BeginDrawing();
    ClearBackground(BLACK);
    Camera2D camera = {
        .target = path[path_length - 1].zero,
        .rotation = 0,
        .zoom = zoom,
        .offset = {GetScreenWidth() / 2.f, GetScreenHeight() / 2.f}};
    camera.offset = Vector2Add(camera.offset, off);
    for (long i = 0; i < path_length; i++) {
      step_t *s = &path[i];
      BeginMode2D(camera);
      DrawLineBezierQuad(s->enter, s->exit, s->zero, 2, s->color);
      DrawTextEx(font, s->text, s->zero, 10, 0, WHITE);
      EndMode2D();
    }
    EndDrawing();
  }
}
#include <stdlib.h>
void ti(Args, long rτ) {
  const float width = 50;

  static Vector2 enter = {0, 0};
  static Vector2 zero = {0, 0};
  static Vector2 dir = {1, 0};
  static long lτ = 512;
  static long ldelta = 1;

  long ray = rτ - τ;
  long delta = 0 < ray ? -1 : 1;

  if (lτ - τ != 11 && lτ - τ != -11)
    dir = Vector2Rotate(dir, M_PI_2);
  else if (ldelta != delta)
    ldelta = delta, dir = Vector2Rotate(dir, M_PI);

  Vector2 exit =
      Vector2Add(Vector2Add(zero, Vector2Scale(dir, width / 2)),
                 Vector2Scale(Vector2Rotate(dir, M_PI_2), ray * width / 10));
  path[path_length++] = (step_t){.zero = zero,
                                 .enter = enter,
                                 .exit = exit,
                                 .text = names[τ],
                                 .color = colors[ray + 5]};
  lτ = τ;
  zero = Vector2Add(zero, Vector2Scale(dir, width));
  enter = exit;

  draw();
  ((n_t *)β)[rτ](τ, α, β, ο, σ);
}
void ti_init(Args) {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1700, 600, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 45, 0, 0);
}
