#include "aword.h"
#include <assert.h>
#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>
static Font font;
Vector2 angle_dir(float angle) {
  float x = cosf((angle * M_PI) / 180);
  float y = sinf((angle * M_PI) / 180);
  float magnitude = sqrt(x * x + y * y);
  return (Vector2){x / magnitude, y / magnitude};
}
typedef struct step_t {
  float rotation;
  char *text;
  long ρ;
  long δ;
} step_t;

long rotation = 0;
step_t steps[1024] = {};
long sc = 0;

void draw();
void ti_move(Args, N((*cb))) {
  steps[sc].rotation = rotation;
  steps[sc].ρ = ρ;
  steps[sc].δ = δ;
  steps[sc].text = τ[4];
  sc++;
  draw();
  cb(τ, ρ, δ);
}
void ti_around(Args, N((*cb))) {
  rotation = rotation + 180;
  cb(τ, ρ, δ);
}
void ti_left(Args, N((*cb))) {
  rotation = rotation + 90;
  cb(τ, ρ, δ);
}
static Color colors[] = {
    GOLD,     // Gold
    MAROON,   // Maroon
    GREEN,    // Green
    DARKBLUE, // Dark Blue
    BLACK,    // Black
    BLUE,     // Blue
    LIME,     // Lime
    RED,      // Red
    YELLOW,   // Yellow
};
void draw() {
  while (GetCharPressed() != 'n') {
    BeginDrawing();
    ClearBackground(BLACK);
    Camera2D camera = {.target = {0, 0}, .rotation = 0, .zoom = 1};
    camera.offset = (Vector2){GetScreenWidth() / 2.f, GetScreenHeight() / 2.f};

    for (long i = 0; i < sc; i++) {
      camera.rotation = steps[i].rotation;
      Vector2 dir = angle_dir(camera.rotation);
      camera.offset.x += dir.x * 100;
      camera.offset.y += dir.y * 100;
      float size = 45;
      float spacing = 4;
      Vector2 m = MeasureTextEx(font, steps[i].text, size, spacing);
      BeginMode2D(camera);
      int ry = (steps[i].ρ + 1) * steps[i].δ + 4;
      Vector2 pos = {-m.x / 2.f, -50 + 10 * ry};
      //      DrawRectangleV(pos, m, WHITE);
      DrawTextEx(font, steps[i].text, pos, size, spacing, colors[ry]);
      EndMode2D();
    }
    EndDrawing();
  }
}

void ti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1800, 1000, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 35, 0, 0);
}
