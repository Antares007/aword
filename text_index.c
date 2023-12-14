#include "aword.h"
#include <assert.h>
#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <unistd.h>

static Font font;
static Color colors[] = {
    ['F'] = {255, 000, 255, 255}, // Fuchsia
    ['O'] = {128, 128, 000, 255}, // Olive
    ['L'] = {000, 255, 000, 255}, // Lime
    ['M'] = {128, 000, 000, 255}, // Maroon
    ['N'] = {000, 000, 128, 255}, // Navy
    ['B'] = {000, 000, 255, 255}, // Blue
    ['R'] = {255, 000, 000, 255}, // Red
    ['G'] = {000, 128, 000, 255}, // Green
    ['Y'] = {255, 255, 000, 255}, // Yellow
    ['P'] = {128, 000, 128, 255}, // Purple
};
static char directions[] = {
    ['F'] = -1, // Fuchsia
    ['O'] = -1, // Olive
    ['L'] = -1, // Lime
    ['M'] = -1, // Maroon
    ['N'] = -1, // Navy
    ['B'] = +1, // Blue
    ['R'] = +1, // Red
    ['G'] = +1, // Green
    ['Y'] = +1, // Yellow
    ['P'] = +1, // Purple
};
float zoom = 1;
Vector2 off = {0, 0};
typedef struct step_t {
  const char *color, *name;
  //long t, a, b;
  //void **o;
  //const char *s;
  //n_t cont;
  long angle;
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
const char *format_name(const char *name) {
  long len = strlen(name);
  static char fname[100];
  strcpy(fname, name);
  fname[len - 2] = '\0';
  if (fname[0] == 'a' && fname[1] == 'w' && fname[2] == '_')
    return fname + 3;
  return fname;
}
#include <stdlib.h>
void draw(step_t *steps, long count) {
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

    Vector2 zero = {2 * GetScreenWidth() / 8.f, 3 * GetScreenHeight() / 8.f};
    Vector2 dir = {0, -1};
    for (long i = 0; i < count; i++) {
      step_t *s = &steps[i];
      if (strcmp(s->name, "b.c") == 0)
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(),
                      (Color){.a = 150, .r = -1, .g = -1, .b = -1});
      Vector2 ns = {90, 50}; // MeasureTextEx(font, format_name(s->name), 35,
                             // 1);
      if (s->angle == +1) (dir = Vector2Rotate(dir, M_PI_2 * s->angle));

      float step_size = ((long)dir.x ? ns.x : ns.y) * directions[(int)s->color[0]];
      // Lerp(step_size, step_size*2, (float)at/height)
      zero = Vector2Add(zero,    Vector2Scale(dir, zoom * step_size));

      if (s->angle == -1) (dir = Vector2Rotate(dir, M_PI_2 * s->angle));

      Camera2D camera = {.target = {0, 0},
                         .rotation = 0,
                         .zoom = zoom ,//* Lerp(1, 2, (float)at / height),
                         .offset = Vector2Add(off, zero)};
      BeginMode2D(camera);
      Color bgcolor = LerpGradient(calc_color(s), 0.5, (float)i / count);
      Color fgcolor = (Color) {.a=255, .r = 255 - bgcolor.r, .g = 255 - bgcolor.g, .b = 255 - bgcolor.b };
      DrawRectangle(-ns.x / 2, -ns.y / 2, ns.x, ns.y,
                    bgcolor);
      DrawRectangleLines(-ns.x / 2, -ns.y / 2, ns.x, ns.y, BLACK);
      DrawTextEx(font, format_name(s->name), (Vector2){-ns.x / 2, -ns.y / 2},
                 35, 1, fgcolor);
      EndMode2D();
    }
    EndDrawing();
    // if(semi_auto && (steps[count-1]->color[0] == 'B' ||
    // steps[count-1]->color[0] == 'N' ||
    //                  steps[count-1]->color[0] == 'R' ||
    //                  steps[count-1]->color[0] == 'M')) semi_auto = 0;
    key = GetCharPressed();
    if (key == 'c')
      semi_auto = !semi_auto;
    if (key == 's')
      skip_color = steps[count - 1].color[0];
    if (WindowShouldClose())
      exit(0);
  } while (key != 'n' && !semi_auto
           //&& count && skip_color &&
           //steps[count - 1].color[0] != skip_color &&
           //steps[count - 1].color[0] != 'P' &&
           //steps[count - 1].color[0] != 'F'
  );
}
#include <string.h>
void ti(char*color, char*name, long angle) {
  printf("%10s %10s %ld\n", color, name, angle), usleep(20000);
//  static step_t steps[2048];
//  static long count = 0;
//  steps[count].color = color;
//  steps[count].name = name;
//  steps[count].angle = angle;
//  count++;
//  draw(steps, count);
}
void ti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1500, 800, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("../NovaMono-Regular.ttf", 35, 0, 0);
}
