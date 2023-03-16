#include <math.h>
#include <raylib.h>
#include <stdint.h>
#include <unistd.h>
#define SW 150
#define SH 150
#define PW 8
#define PH 8
static int speed = 20000;
void wait() { usleep(speed); }
static int side = 0;
void gut_rotate(long δ) { side = side + δ; }
void draw_line(int x1, int y1, int x2, int y2, uint32_t pixel,
               uint32_t pattern);
void init_gut() {
  SetTraceLogLevel(LOG_WARNING);
  InitWindow(SW * PW, SH * PH, "actionable word show");
  SetTargetFPS(0);
}
static void draw();
void gut_line_to(long ρ, long δ) {
  static int curr_ρ = 0, δ_sum = 0;
  static uint32_t colors[] = {
      0xFF777700, 0xFF770000, 0xFF007700, 0xFF007777, 0xFF000077, 0,
      0xFF0000FF, 0xFF00FFFF, 0xFF00FF00, 0xFFFF0000, 0xFFFFFF00,
  };
  int last_δ_sum = δ_sum;
  int last_curr_ρ = curr_ρ;
  //  draw_line(last_δ_sum, -16, last_δ_sum, +16, colors[ρ + 4], 0xFFFFFFFF);
  draw_line(last_δ_sum, last_curr_ρ, δ_sum = δ_sum + δ * 14, curr_ρ = ρ * 4,
            colors[ρ + 5], 0xFFFFFFFF);
  draw();
}
void clear_gut() { CloseWindow(); }

static uint32_t screen[SW * SH] = {};
static void draw() {
  BeginDrawing();
  ClearBackground((Color){.a = 0xff, .r = 0xff, .g = 0xff, .b = 0xff});
  int key = GetCharPressed();
  if (key == 'v')
    speed = 0;
  else if (key == 'x')
    speed = 20000;

  if (key == 'c')
    for (long i = 0; i < SW * SH; i++)
      screen[i] = 0xFFffffff;
  else
    for (long i = 0; i < SW * SH; i++)
      if (screen[i])
        DrawRectangle((i % SW) * PW, i / SW * PH, PW, PH, *(Color *)&screen[i]);
  DrawText(TextFormat("fps: %i", GetFPS()), 0, 0, 45, RED);
  EndDrawing();
}
void draw_pixel(int in_x, int in_y, uint32_t p) {
  int out_x, out_y;
  out_x = in_x * cosf(side * M_PI_2) + in_y * sinf(side * M_PI_2) + 0.5f;
  out_y = in_x * -sinf(side * M_PI_2) + in_y * cosf(side * M_PI_2) + 0.5f;
  screen[SW / 2 + out_x + SW * (SH / 2 - 14 + out_y)] = p;
}
static void swap(int *a, int *b) {
  int t = *b;
  *b = *a, *a = t;
}
static int abs(int a) { return a < 0 ? a * -1 : a; }
#define rol() ((pattern = (pattern << 1) | (pattern >> 31)) & 1)
void draw_pixel(int x, int y, uint32_t p);
void draw_line(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t p,
               uint32_t pattern) {
  /*  OneLoneCoder Pixel Game Engine v1.17
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
