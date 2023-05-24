#include "aword.h"
#include <raylib.h>
#include <raymath.h>
Vector2 off;
float zoom = 2;
o_t path[1024][3];
long length = 0;
Font font;
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
void draw() {
  int key = GetCharPressed();
  while (key != 'n') {
    key = GetCharPressed();
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
        .target = {0, 0},
        .rotation = 0,
        .zoom = zoom,
        .offset = {GetScreenWidth() / 2.f, GetScreenHeight() / 2.f}};
    camera.offset = Vector2Add(camera.offset, off);
    BeginMode2D(camera);
    Vector2 p_ray_pos = {0, 0};
    for(long i = 0; i < length; i++) {
      float fontSize = 25;
      long ray = path[i][2].q;
      const char* text = path[i][1].cs;
      Color color = colors[ray];
      Vector2 zero = {path[i][0].q*10, 0};
      Vector2 ray_pos = Vector2Add(zero, Vector2Scale((Vector2){0, 1}, ray*5));
      DrawTextPro(font, text, Vector2Add(zero, (Vector2){0, 50}), (Vector2){0,0}, 90, fontSize, 0, color);
      DrawLineBezier(p_ray_pos, ray_pos, 2, color);
      p_ray_pos = ray_pos;
    }
    EndMode2D();
    EndDrawing();
  }
}
N(m) {
  path[length][0].q = w;
  path[length][1].cs = o[w + 2].cs;
  path[length][2].q = (r + 1) * d/TW + 4;
  length++;
  draw();
  ((aword_t *)o)[w + d](t, a, w + d, o, r, d, s);
}
void text_index_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1700, 900, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 45, 0, 0);
}
