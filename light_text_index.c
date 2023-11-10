#include "light.h"
#include <assert.h>
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <unistd.h>

static Font font;
float zoom = 1;
Vector2 off = {0, 0};
typedef struct step_t {
  const char *name;
  long r;
  long d;
  long height;
  Vector2 pos;
} step_t;
static Color colors[] = {
    {255, 000, 255, 255}, // Fuchsia
    {128, 128, 000, 255}, // Olive
    {128, 000, 000, 255}, // Maroon
    {000, 255, 000, 255}, // Lime
    {000, 000, 128, 255}, // Navy
    {000, 000, 000, 255}, // Black
    {000, 000, 255, 255}, // Blue
    {000, 128, 000, 255}, // Green
    {255, 000, 000, 255}, // Red
    {255, 255, 000, 255}, // Yellow
    {128, 000, 128, 255}, // Purple
};
static Vector2 dir = {0, -1};
;
static long height = 0, max_height = 1;
static long after_step_turns = 0, vdir = 1;
void ti_turn() { dir = Vector2Rotate(dir, M_PI_2); }
void ti_late_turn() { after_step_turns = 1, height += 2 * vdir, (vdir *= -1); }
void ti_back() { (after_step_turns = 2), height += 2 * vdir, (vdir *= -1); }
void draw(step_t *steps, long count);

void ti_step(const char *name, long r, long d) {
  //printf("%10s %3ld %3ld\n", name, r, d);
  static step_t steps[2048];
  static Vector2 pos = {0, 0};
  static long count = 0;
  max_height = max_height < height ? height : max_height;
  steps[count].name = name;
  steps[count].r = r;
  steps[count].d = d;
  steps[count].pos =
      (pos = Vector2Add(pos, Vector2Scale(dir, (long)dir.x ? 150 : 90)));
  steps[count].height = (height += vdir);
  count++;
  while (after_step_turns)
    (dir = Vector2Rotate(dir, M_PI_2)), after_step_turns--;
  draw(steps, count);
}
#include <stdlib.h>
#include <string.h>

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
    for (long i = 0; i < count; i++) {
      step_t *s = &steps[i];
      if (strcmp(s->name, "bro") == 0)
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(),
                      (Color){.a = 150, .r = -1, .g = -1, .b = -1});
      Vector2 ns = {90, 50};

      Camera2D camera = {.target = {0, 0},
                         .rotation = 0,
                         .zoom = zoom + Lerp(1, 2,
                                  (s->height < 0 ? s->height * -1 : s->height) /
                                      (float)max_height),
                         .offset = Vector2Add(Vector2Add(off, zero), s->pos)};
      BeginMode2D(camera);
      Color bgcolor = colors[(s->r + 1) * s->d + 5];
      Color fgcolor = BLACK;
      DrawRectangle(-ns.x / 2, -ns.y / 2, ns.x, ns.y, bgcolor);
      DrawRectangleLines(-ns.x / 2, -ns.y / 2, ns.x, ns.y, BLACK);
      DrawTextEx(font, s->name, (Vector2){-ns.x / 2, -ns.y / 2}, 35, 1,
                 fgcolor);
      DrawTextEx(font, TextFormat("%ld", s->height),
                 (Vector2){-ns.x / 2 + 5, -ns.y / 2 + 30}, 25, 1, fgcolor);
      EndMode2D();
    }
    EndDrawing();
    key = GetCharPressed();
    if (key == 'c')
      semi_auto = !semi_auto;
    if (WindowShouldClose())
      exit(0);
  } while (key != 'n' && !semi_auto);
}
#include <string.h>

void ti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1500, 800, "aword");
  SetTargetFPS(0);
  font = LoadFontEx("NovaMono-Regular.ttf", 35, 0, 0);
}
