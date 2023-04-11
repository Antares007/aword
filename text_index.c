#include "aword.h"
#include <assert.h>
#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>

static Font font;
static Color colors[] = {
    GOLD,     // Gold
    MAROON,   // Maroon
    GREEN,    // Green
    DARKBLUE, // Dark Blue
    PURPLE,   // Black
    BLUE,     // Blue
    LIME,     // Lime
    RED,      // Red
    YELLOW,   // Yellow
};
typedef struct tabos_t {
  long t, a, b;
  const char **o;
  long s, r;
} tabos_t;
static tabos_t tabos[1024];
static long tabs = 0;
static float zoom = 4;
static void draw() {
  int key = GetCharPressed();
  while (key != 'n') {
    key = GetCharPressed();
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    BeginDrawing();
    ClearBackground(WHITE);
    Camera2D camera = {.target = {0, 0}, .rotation = 0, .zoom = zoom};
    camera.offset = (Vector2){GetScreenWidth() / 3.f, GetScreenHeight() / 2.f};
    BeginMode2D(camera);
    Vector2 startPos = {0, 0};
    for (long i = 0; i < tabs; i++) {
      tabos_t tab = tabos[i];
      for (long s = 4; s < tab.s; s += 9) {
        Vector2 pos = {s * 2, 0};
        Vector2 endPos = {tab.t * 2, tab.r * 4};
        DrawLineBezier(startPos, endPos, 2, colors[tab.r + 4]);
        startPos = endPos;
        DrawTextPro(font, tab.o[s], pos, (Vector2){0, 0}, -90, 10, 2, BLACK);
      }
    }
    EndMode2D();
    EndDrawing();
  }
}
void ti(Args, long ray) {
  tabos[tabs].t = τ;
  tabos[tabs].a = α;
  tabos[tabs].b = β;
  tabos[tabs].o = (void *)&ο[512];
  tabos[tabs].s = σ;
  tabos[tabs].r = ray - τ;
  tabs++;
  draw(), ο[ray].c(τ, α, β, ο, σ);
}
void ti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1800, 600, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 45, 0, 0);
}
