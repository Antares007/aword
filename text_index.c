#include "aword.h"
#include <assert.h>
#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>

static Font font;
static Color colors[] = {
    {255, 255, 0, 255}, // Yellow
    {128, 0, 128, 255}, // Purple
    {255, 0, 0, 255},   // Red
    {0, 128, 0, 255},   // Green
    {0, 0, 255, 255},   // Blue
    {0, 0, 0, 255},     // Black
    {0, 0, 128, 255},   // Navy
    {0, 255, 0, 255},   // Lime
    {128, 0, 0, 255},   // Maroon
    {255, 0, 255, 255}, // Fuchsia
    {128, 128, 0, 255}  // Olive

};
static base_t *o;
static long tabs[1024][2];
static long tc = 0;
static float zoom = 4;
static float off = 0;
static void draw() {
  int key = GetCharPressed();
  while (key != 'n') {
    key = GetCharPressed();
    if (key == 'c')
      tc = 0;
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      off += GetMouseDelta().x;
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    BeginDrawing();
    ClearBackground(WHITE);
    Camera2D camera = {.target = {0 + off, 0}, .rotation = 0, .zoom = zoom};
    camera.offset = (Vector2){GetScreenWidth() / 2.f, GetScreenHeight() / 2.f};
    BeginMode2D(camera);
    Vector2 startPos = {0, 0};
    for (long i = 0; i < tc; i++) {
      Vector2 endPos = {tabs[i][0] * 5, tabs[i][1] * 5};
      DrawTextEx(font, o[tabs[i][0]].v, endPos, 10, 0, colors[tabs[i][1] + 5]);
      DrawLineBezier(startPos, endPos, 2, colors[tabs[i][1] + 5]);
      startPos = endPos;
    }
    EndMode2D();
    EndDrawing();
  }
}
void ti(Args, long ray) {
  tabs[tc][0] = τ;
  tabs[tc][1] = ray - τ;
  tc++;
  draw(), ο[ray].c(τ, α, β, ο, σ);
}
void ti_init(Args) {
  o = ο;
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1800, 600, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 45, 0, 0);
}
