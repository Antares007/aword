#include <math.h>
#include <raylib.h>
#include <stdint.h>
#include <unistd.h>
static int screen_width;
static int screen_height;
static int pixel_width;
static int pixel_height;
#define BGColor BLACK

static float base[2], point[2], direction[2] = {0, 1};
int gut_close_requested() { return WindowShouldClose(); }
// only 90⁰ rotations δ = -1 | 1
void gut_rotate(float theta) {
  float x = direction[0];
  float y = direction[1];
  direction[0] = x * cosf(theta) + y * sinf(theta);
  direction[1] = x * -sinf(theta) + y * cosf(theta);
}
float texts_positions[1024][2];
uint32_t texts_colors[1024];
const char *texts_content[1024];
long texts_length = 0;
static void draw_line(int x1, int y1, int x2, int y2, uint32_t pixel,
                      uint32_t pattern);
int gut_draw_frame();
// main procedure to drawing guts
#include "aword.h"
void gut_line_to(long δ, long ρ, const char *text) {
  static uint32_t colors[] = {
      0xFF000000, 0xFF007777, 0xFF000077, 0xFF007700, 0xFF770000, 0,
      0xFFFF0000, 0xFF00FF00, 0xFF0000FF, 0xFF00FFFF, 0XFFFFFFFF,
  };
  int y = (1 + ρ) * δ;
  uint32_t color = colors[y + 5];
  base[0] += direction[0] * (float)δ * 16.f;
  base[1] += direction[1] * (float)δ * 16.f;
  if (δ == 1)
    texts_content[texts_length] = text, texts_colors[texts_length] = color,
    texts_positions[texts_length][0] = base[0],
    texts_positions[texts_length][1] = base[1], texts_length++;
  else
    texts_length--;
  float x1 = point[0];
  float y1 = point[1];
  point[0] = base[0] + 4.f * (float)y * direction[1];
  point[1] = base[1] + 4.f * (float)y * direction[0] * -1.f;
  draw_line(x1, y1, point[0], point[1], color, -1);
}
static uint32_t *screen;
static void clear_screen() {
  for (long i = 0; i < screen_width * screen_height; i++)
    screen[i] = 0;
}
#include <stdlib.h>
void gut_init(int _screenwidth, int _screenheight, int _pixelwidth,
              int _pixelheight, int basex, int basey, int dx, int dy,
              long fps) {
  screen_width = _screenwidth;
  screen_height = _screenheight;
  pixel_width = _pixelwidth;
  pixel_height = _pixelheight;
  base[0] = point[0] = basex;
  base[1] = point[1] = basey;
  direction[0] = dx;
  direction[1] = dy;
  SetTraceLogLevel(LOG_WARNING);
  InitWindow(screen_width * pixel_width, screen_height * pixel_height,
             "actionable word show");
  SetTargetFPS(fps);
  screen = malloc(screen_width * screen_height * sizeof(*screen));
  clear_screen();
}
void gut_clear() {
  CloseWindow();
  free(screen);
}
static void render_screen() {
  for (long i = 0; i < screen_width * screen_height; i++)
    if (screen[i])
      DrawRectangle((i % screen_width) * pixel_width,
                    i / screen_width * pixel_height, pixel_width, pixel_height,
                    *(Color *)&screen[i]);
  for (long i = 0; i < texts_length; i++)
    DrawText(texts_content[i], texts_positions[i][0] * pixel_width,
             texts_positions[i][1] * pixel_height, 45 * pixel_width * 1 / 8.f,
             *(Color *)&texts_colors[i]);
}
int gut_draw_frame() {
  if (gut_close_requested())
    return 's';
  BeginDrawing();
  ClearBackground(BGColor);
  int key = GetCharPressed();
  if (key == 'c')
    clear_screen();
  else
    render_screen();
  DrawText(TextFormat("fps: %i", GetFPS()), 0, 0, 45, RED);
  EndDrawing();
  return key;
}
static void draw_pixel(int x, int y, uint32_t p) {
  screen[x + screen_width * y] = p;
}
static void swap(int *a, int *b) {
  int t = *b;
  *b = *a, *a = t;
}
// static int abs(int a) { return a < 0 ? a * -1 : a; }
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
