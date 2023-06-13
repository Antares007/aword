#include "aword.h"
#include <raylib.h>
#include <raymath.h>

static Color colors[] = {
    {128, 128, 000, 255}, // 0 Olive
    {255, 000, 255, 255}, // 1 Fuchsia
    {128, 000, 000, 255}, // 2 Maroon
    {000, 255, 000, 255}, // 3 Lime
    {000, 000, 128, 255}, // 4 Navy
    {000, 000, 255, 255}, // 5 Blue
    {000, 128, 000, 255}, // 6 Green
    {255, 000, 000, 255}, // 7 Red
    {128, 000, 128, 255}, // 8 Purple
    {255, 255, 000, 255}, // 9 Yellow
};
static Font font;
static int debug = 1;
static float zoom = 1;
static Vector2 off = {0, 0};
static Color color;
static long size;
static const char *name;

static void draw() {
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
    BeginMode2D(camera);
    DrawText(TextFormat("%s %ld %d", name, size, GetFPS()), 0, 0, 20, color);
    EndMode2D();
    EndDrawing();
    key = GetCharPressed();
    if (key == 'n')
      debug = true;
    else if (key == 's')
      debug = false;
    else if (key == 'c')
      ; // length = 0;
  } while (debug && key != 'n');
}
void monitor_it(void **o, long s, long a) {
  color = colors[(long)o[s++]];
  size = (long)o[s++];
  name = o[s++];
  draw();
  ((n_t *)o)[s](o, s + 1, a);
}
void monitor_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(800, 600, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 45, 0, 0);
}
