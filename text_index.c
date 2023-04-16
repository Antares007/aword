#include "aword.h"
#include <assert.h>
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <unistd.h>

static Font font;
static Color colors[] = {
    {255, 255, 000, 255}, // Yellow
    {128, 000, 128, 255}, // Purple
    {255, 000, 000, 255}, // Red
    {000, 128, 000, 255}, // Green
    {000, 000, 255, 255}, // Blue
    {000, 000, 000, 255}, // Black
    {000, 000, 128, 255}, // Navy
    {000, 255, 000, 255}, // Lime
    {128, 000, 000, 255}, // Maroon
    {255, 000, 255, 255}, // Fuchsia
    {128, 128, 000, 255}  // Olive

};
static long tabs[1024][3];
static long tc = 0;
static float zoom = 1;
static Vector2 off = {};
static Vector2 getTabPos(long i) {
  Vector2 endPos = {tabs[i][0] * 5, tabs[i][1] * 5};
  return endPos;
}
static void drAW(long t, long r) {
  DrawRectangleLines(-10, -10, 20, 20, BLACK);
}
extern char*names[];
static void draw() {
  int key = GetCharPressed();
  while (key != 'n') {
    key = GetCharPressed();
    if (key == 'c')
      tc = 0;
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
        .target = getTabPos(tc - 1),
        .rotation = 0,
        .zoom = zoom,
        .offset = (Vector2){GetScreenWidth() / 2.f, GetScreenHeight() / 2.f}};
    camera.offset = Vector2Add(camera.offset, off);
    Vector2 startPos = {0, 0};
    for (long i = 0; i < tc; i++) {
      BeginMode2D(camera);
      Vector2 endPos = {tabs[i][0] * 5, tabs[i][1] * 5};
      DrawLineBezier(startPos, endPos, 2, colors[tabs[i][1] + 5]);
      startPos = endPos;
      float fontSize = 20;
      const char *text = names[tabs[i][0]];
//      Vector2 m = MeasureTextEx(font, text, fontSize, 0);
//      Vector2 border = {4, 4};
//      DrawRectangleV(Vector2Subtract(endPos, border),
//                     Vector2Add(m, Vector2Scale(border, 2)),
//                     colors[tabs[i][1] + 5]);

      DrawTextEx(font, text, (Vector2){endPos.x,40}, fontSize, 0, WHITE);
      EndMode2D();
    }
    EndDrawing();
  }
}
void ti(Args, long ray) {
  tabs[tc][0] = τ;
  tabs[tc][1] = ray - τ;
  tc++;
  //((n_t*)σ)[ray](τ, α, β, ο, σ);
  draw();
  ((n_t*)ο)[ray](τ, α, β, ο, σ, δ);

}
void ti_stop(Args) {
  draw();
  printf("stop\n");
}
void ti_init(Args) {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1800, 400, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 45, 0, 0);
}
