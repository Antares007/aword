#include <math.h>
#include <raylib.h>
#include <stdint.h>
#include <unistd.h>
#define SW 400
#define SH 250
#define PW 4
#define PH 4
#define BGColor GOLD

static int base[] = {SW / 2, SH / 8}, point[] = {SW / 2, SH / 8},
           direction[] = {0, 1};
int gut_close_requested() { return WindowShouldClose(); }
// only 90⁰ rotations δ = -1 | 1
void gut_rotate(long δ) {
  int dx = direction[0];
  direction[0] = direction[1] * δ * -1;
  direction[1] = dx * δ;
}
static void draw_line(int x1, int y1, int x2, int y2, uint32_t pixel,
                      uint32_t pattern);
static void draw_frame();
// main procedure to drawing guts
void gut_line_to(long ρ, long δ) {
  ρ = (4 - ρ) * δ;
  base[0] += direction[0] * δ * 16;
  base[1] += direction[1] * δ * 16;
  int x1 = point[0];
  int y1 = point[1];
  point[0] = base[0] + 4 * ρ * direction[1];
  point[1] = base[1] + 4 * ρ * direction[0] * -1;
  static uint32_t colors[] = {
      0xFF000077, 0xFF007777, 0xFF007700, 0xFF770000, 0,
      0xFFFF0000, 0xFF00FF00, 0xFF00FFFF, 0xFF0000FF,
  };
  draw_line(x1, y1, point[0], point[1], colors[4 + ρ], -1);
  draw_frame();
}
void gut_init(long fps) {
  SetTraceLogLevel(LOG_WARNING);
  InitWindow(SW * PW, SH * PH, "actionable word show");
  SetTargetFPS(fps);
}
void gut_clear() { CloseWindow(); }
static uint32_t screen[SW * SH] = {};
static void clear_screen() {
  for (long i = 0; i < SW * SH; i++)
    screen[i] = *(uint32_t *)&BGColor;
}
static void render_screen() {
  for (long i = 0; i < SW * SH; i++)
    if (screen[i])
      DrawRectangle((i % SW) * PW, i / SW * PH, PW, PH, *(Color *)&screen[i]);
}
static void draw_frame() {
  BeginDrawing();
  ClearBackground(BGColor);

  if (GetCharPressed() == 'c')
    clear_screen();
  else
    render_screen();
  DrawText(TextFormat("fps: %i", GetFPS()), 0, 0, 45, RED);
  EndDrawing();
}
static void draw_pixel(int x, int y, uint32_t p) { screen[x + SW * y] = p; }
static void swap(int *a, int *b) {
  int t = *b;
  *b = *a, *a = t;
}
static int abs(int a) { return a < 0 ? a * -1 : a; }
#define rol() ((pattern = (pattern << 1) | (pattern >> 31)) & 1)
static void draw_line(int32_t x1, int32_t y1, int32_t x2, int32_t y2,
                      uint32_t p, uint32_t pattern) {
  /*  this algorithm for drawing lines was ported from
      OneLoneCoder Pixel Game Engine v1.17
      "Like the command prompt console one, but not..." - javidx9 */
  int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;
  dx = x2 - x1;
  dy = y2 - y1;

  // straight lines idea by gurkanctn
  if (dx == 0) // Line is vertical
  {
    if (y2 < y1)
      swap(&y1, &y2);
    for (y = y1; y <= y2; y++)
      if (rol())
        draw_pixel(x1, y, p);
    return;
  }

  if (dy == 0) // Line is horizontal
  {
    if (x2 < x1)
      swap(&x1, &x2);
    for (x = x1; x <= x2; x++)
      if (rol())
        draw_pixel(x, y1, p);
    return;
  }

  // Line is Funk-aye
  dx1 = abs(dx);
  dy1 = abs(dy);
  px = 2 * dy1 - dx1;
  py = 2 * dx1 - dy1;
  if (dy1 <= dx1) {
    if (dx >= 0) {
      x = x1;
      y = y1;
      xe = x2;
    } else {
      x = x2;
      y = y2;
      xe = x1;
    }

    if (rol())
      draw_pixel(x, y, p);

    for (i = 0; x < xe; i++) {
      x = x + 1;
      if (px < 0)
        px = px + 2 * dy1;
      else {
        if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
          y = y + 1;
        else
          y = y - 1;
        px = px + 2 * (dy1 - dx1);
      }
      if (rol())
        draw_pixel(x, y, p);
    }
  } else {
    if (dy >= 0) {
      x = x1;
      y = y1;
      ye = y2;
    } else {
      x = x2;
      y = y2;
      ye = y1;
    }

    if (rol())
      draw_pixel(x, y, p);

    for (i = 0; y < ye; i++) {
      y = y + 1;
      if (py <= 0)
        py = py + 2 * dx1;
      else {
        if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
          x = x + 1;
        else
          x = x - 1;
        py = py + 2 * (dx1 - dy1);
      }
      if (rol())
        draw_pixel(x, y, p);
    }
  }
}
