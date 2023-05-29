#include "aword.h"
#include <raylib.h>
#include <raymath.h>
Vector2 off;
float zoom = 1.5;
typedef struct step_t {
  const char *text, *s;
  Vector2 zero, dir;
  Color color;
  long ray;
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
static int debug = 0;
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
    ClearBackground(BLACK);
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
N(m) {
  long ray = (r + 1) * d / TW + 4;
  path[length].text = o[w + 2].cs;
  path[length].s = s;
  path[length].zero = zero;
  path[length].dir = dir;
  path[length].ray = ray;
  path[length].color = colors[ray];
  length++;
  zero = Vector2Add(zero, Vector2Scale(dir, d * 20));
  draw();
  o[w + d].c(a, w + d, o, r, d, s);
}
void text_index_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1900, 900, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 45, 0, 0);
}
