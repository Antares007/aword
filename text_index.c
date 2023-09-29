#include "aword.h"
#include <assert.h>
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <unistd.h>

static Font font;
static Color colors[] = {
    ['O'] = {128, 128, 000, 255}, // Olive
    ['F'] = {255, 000, 255, 255}, // Fuchsia
    ['M'] = {128, 000, 000, 255}, // Maroon
    ['L'] = {000, 255, 000, 255}, // Lime
    ['N'] = {000, 000, 128, 255}, // Navy
    ['B'] = {000, 000, 255, 255}, // Blue
    ['G'] = {000, 128, 000, 255}, // Green
    ['R'] = {255, 000, 000, 255}, // Red
    ['P'] = {128, 000, 128, 255}, // Purple
    ['Y'] = {255, 255, 000, 255}, // Yellow
};
static char directions[] = {
    ['O'] = -1, // Olive
    ['F'] = -1, // Fuchsia
    ['M'] = -1, // Maroon
    ['L'] = -1, // Lime
    ['N'] = -1, // Navy
    ['B'] = +1, // Blue
    ['G'] = +1, // Green
    ['R'] = +1, // Red
    ['P'] = +1, // Purple
    ['Y'] = +1, // Yellow
};
float zoom = 0.7;
Vector2 off = {0, 0};
typedef struct step_t {
  const char *color, *name;
  long t, a, b;
  void **o;
  const char *s;
  n_t cont;
} step_t;
Color calc_color(step_t *s) { return colors[(int)s->color[0]]; }
#include <string.h>
Color LerpColor(Color a, Color b, float amount) {
  return (Color){
      .r = Lerp(a.r, b.r, amount),
      .g = Lerp(a.g, b.g, amount),
      .b = Lerp(a.b, b.b, amount),
      .a = Lerp(a.a, b.a, amount),
  };
}
Color LerpGradient(Color a, float point, float amount) {
  return LerpColor(LerpColor(a, BLACK, point), a, amount);
}
void draw(step_t **steps, long count) {
  int key = 0;
  static char skip_color = 'A';
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

    Vector2 zero = {1 * GetScreenWidth() / 8.f, 2 * GetScreenHeight() / 8.f};
    Vector2 dir = {0, -1};
    for (long i = 0; i < count; i++) {
      step_t *s = steps[i];
      if (strcmp("tab.c", s->name) == 0)
        dir = Vector2Rotate(dir, M_PI_2);
      Vector2 ns = MeasureTextEx(font, s->name, 35, 1);
      zero = Vector2Add(
          zero,
          Vector2Scale(
              dir, (long)dir.x
                       ? Lerp(ns.x * zoom, ns.x * zoom * 3, (float)i / count)
                       : Lerp(ns.y * zoom, ns.y * zoom * 3, (float)i / count)));
      Camera2D camera = {.target = {0, 0},
                         .rotation = 0,
                         .zoom = Lerp(1 * zoom, 2 * zoom, (float)i / count),
                         .offset = Vector2Add(off, zero)};

      BeginMode2D(camera);
      DrawRectangle(-ns.x / 2, -ns.y / 2, ns.x, ns.y,
                    LerpGradient(calc_color(s), 0.5, (float)i / count));
      DrawRectangleLines(-ns.x / 2, -ns.y / 2, ns.x, ns.y, BLACK);
      DrawTextEx(font, s->name, (Vector2){-ns.x / 2, -ns.y / 2}, 35, 1, WHITE);
      EndMode2D();
    }
    EndDrawing();
    if(semi_auto && (steps[count-1]->color[0] == 'B' || steps[count-1]->color[0] == 'N' ||
                     steps[count-1]->color[0] == 'R' || steps[count-1]->color[0] == 'M')) semi_auto = 0;
    key = GetCharPressed();
    if (key == 'c')
      semi_auto = !semi_auto;
    if (key == 's')
      skip_color = steps[count - 1]->color[0];
  } while (
      key != 'n' && !semi_auto && count
      // &&
      // skip_color &&
      // steps[count - 1]->color[0] != 'P' &&
      // steps[count - 1]->color[0] != 'F'
    );
}
#include <string.h>
void ti(step_t *d) {
  printf("%10s %3ld %3ld %10s %s\n", d->s, d->a, d->b, d->color, d->name);
  static step_t *steps[2048];
  static long count = 0;
  static long back_count = 0;
  int dir = directions[(int)d->color[0]];
  if (dir == 1) {
    count += back_count;
    back_count = 0;
    steps[count++] = d;
  } else {
    --back_count;
    assert(strcmp(steps[count + back_count]->name, d->name) == 0);
    steps[count + back_count] = d;
  }
  draw(steps, count);
  d->cont(d->t, d->a, d->b, d->o, d->s);
}
void ti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1500, 800, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("../NovaMono-Regular.ttf", 35, 0, 0);
}
