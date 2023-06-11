#include "aword.h"
#include <raylib.h>
#include <raymath.h>
Vector2 off;
float zoom = 1.5;
typedef struct step_t {
  const char *text, *s;
  Vector2 zero, dir;
  Color color;
  long ray, r, w;
} step_t;
step_t path[4096];
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
static int debug = 1;
void draw() {
  int key;
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
    Camera2D camera = {
        .target = {0, 0},
        .rotation = 0,
        .zoom = zoom,  
        .offset = {GetScreenWidth() / 20.f, GetScreenHeight() / 2.f}};
    camera.offset = Vector2Add(camera.offset, off);
    Vector2 uraypos = {0, 0};
    BeginMode2D(camera);
    for (long i = 0; i < length; i++) {
      float fontSize = 20;
      const char *text = TextFormat("%s %s", path[i].text, path[i].s);
      Vector2 raypos = Vector2Add(
          path[i].zero,
          Vector2Scale(Vector2Rotate(path[i].dir, 1.5707), path[i].ray * -8));
      DrawTextPro(font, text, path[i].zero, (Vector2){0, 0}, 0, fontSize, 0,
                  path[i].color);
      DrawLineEx(uraypos, raypos, 2, path[i].color);
      DrawRectangle(300, -300, 300, 40, WHITE);
      text = TextFormat("%3ld %3ld %s %10s", path[i].w, path[i].r, path[i].text, path[i].s);

      Vector2 m = MeasureTextEx(font, text, fontSize * 2, 0);
      m.x+=100;
      Vector2 labelPos = (Vector2){300, -300};
      DrawRectangleV(labelPos, m, WHITE);
      DrawTextEx(font, text, labelPos, fontSize * 2, 0, BLACK);
      uraypos = raypos;
    }
    EndMode2D();
    EndDrawing();
    key = GetCharPressed();
    if (key == 'n')
      debug = true;
    else if (key == 's')
      debug = false;
    else if (key == 'c')
      length = 0;
  } while (debug && key != 'n');
}

static Vector2 zero = {0, 0}, dir = {1, 0};
void turn(float angle) { dir = Vector2Rotate(dir, angle); }
#include<stdio.h>
N(m) {
  long ray = (o[s + 1].q + 1) * o[s + 0].q / TW + 4;
  path[length].w = w;
  path[length].text = o[w - 2].cs;
  path[length].s = o[a-1].cs;
  path[length].zero = zero;
  path[length].dir = dir;
  path[length].ray = ray;
  path[length].color = colors[ray];
  path[length].r = r;
  length++;
  zero = Vector2Add(zero, Vector2Scale(dir, o[s].q * 20));
  draw();
  o[w + o[s].q].c(a, w + o[s].q, o, r, d, s);
}
void text_index_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1900, 900, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 45, 0, 0);
}