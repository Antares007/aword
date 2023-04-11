#include "aword.h"
#include <assert.h>
#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>

static Font font;
static Color colors[] = {
    YELLOW,   // Yellow
    RED,      // Red
    LIME,     // Lime
    BLUE,     // Blue
    PURPLE,   // Black
    DARKBLUE, // Dark Blue
    GREEN,    // Green
    MAROON,   // Maroon
    GOLD,     // Gold
};
typedef struct tabos_t {
  long t, a;
  const char **b;
  long o, s, r;
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
    const float tab_width = 2;
    Camera2D camera = {.target = {tabos[tabs - 1].s * tab_width, 0},
                       .rotation = 0,
                       .zoom = zoom};
    camera.offset = (Vector2){GetScreenWidth() , GetScreenHeight() / 2.f};
    BeginMode2D(camera);
    DrawLine(0, 0, camera.target.x, 0, BLACK);
    Vector2 startPos = {0, 0};
    Vector2 startControlPos = startPos;

    for (long i = 0; i < tabs; i++) {
      tabos_t tab = tabos[i];
      for (long ti = tab.o + 4; ti < tab.s; ti += 9) {
        Vector2 endPos = {tab.t * tab_width, tab.r * tab_width};

        float thick = 2;
        Color color = colors[tab.r + 4];

        DrawLineBezier(startPos, endPos, thick, color);
        startPos = endPos;
        DrawLine(ti * tab_width, -30, ti * tab_width, 30, BLACK);
        DrawTextPro(font, tab.b[ti], (Vector2){ti * tab_width, 0},
                    (Vector2){0, 0}, -90, 10, 2, BLACK);
      }
    }
    EndMode2D();
    EndDrawing();
  }
}
void ti(Args, long ray) {
  tabos[tabs].t = τ;
  tabos[tabs].a = α;
  tabos[tabs].b = (void *)&β[512];
  tabos[tabs].o = ο;
  tabos[tabs].s = σ;
  tabos[tabs].r = ray - τ;
  tabs++;
  draw(), β[ray].c(τ, α, β, ο, σ);
}
void ti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1800, 600, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 45, 0, 0);
}
