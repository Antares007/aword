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
  float dir;
  long ray;
  long delta;
  const char *text;
} step_t;
static step_t path[1024];
static long path_length = 0;
static float zoom = 4;
static Vector2 off = {};
extern char *names[];
void draw() {
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

    Vector2 uzero = {0, 0};
    Vector2 urayPos = {0, 0};
    const Vector2 text_dir = {1, 0};
    Camera2D camera = {
        .target = {0, 0},
        .rotation = 0,
        .zoom = zoom,
        .offset = {GetScreenWidth() / 2.f, GetScreenHeight() / 2.f}};
    camera.offset = Vector2Add(camera.offset, off);
    BeginMode2D(camera);
    for (long i = 0; i < path_length; i++) {
      step_t s = path[i];
      Color color = colors[s.ray + 5];
      Vector2 dir = Vector2Rotate(text_dir, s.dir);
      Vector2 odir = Vector2Rotate(dir, M_PI_2);
      Vector2 zero = Vector2Add(uzero, Vector2Scale(dir, 50 * s.delta));
      Vector2 rayPos = Vector2Add(zero, Vector2Scale(odir, s.ray * 5));
      DrawLineBezier(urayPos, rayPos, 2, color);
      DrawTextEx(font, s.text, rayPos, 10, 0, s.text[0] == 'o' ? RED : WHITE);
      uzero = zero;
      urayPos = rayPos;
    }
    EndMode2D();
    EndDrawing();
  }
}
static float dir_stack[1024] = {0};
static long dirs = 1;
void ti_left() {
  dir_stack[dirs] = dir_stack[dirs - 1] - M_PI_2;
  dirs++;
}
void ti_right() {
  dir_stack[dirs] = dir_stack[dirs - 1] + M_PI_2;
  dirs++;
}
void ti_ret() { dirs--; }
void ti(long t, long ray, long delta) {
  path[path_length++] = (step_t){
      .dir = dir_stack[dirs - 1],
      .delta = delta,
      .text = names[t],
      .ray = ray,
  };
  draw();
}
void ti_init(Args) {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1700, 900, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 45, 0, 0);
}
