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
  Vector2 pos;
  Vector2 dir;
  char *text;
  long ρ;
  long ι;
} step_t;
Vector2 pos = {0, 0};
Vector2 dir = {1, 0};
step_t steps[1024] = {};
long sc = 0;

void draw();
void ti_turn_left(Args, N((*cb))) {
  int x = dir.x;
  dir.x = dir.y * ι;
  dir.y = x * -1 * ι;
  cb(ο, τ, α, ρ, ι);
}
N(toti_pith);
N(cb);
void ti_move(Args, N((*callback))) {
  steps[sc].dir = dir;
  steps[sc].pos.x = (pos.x += dir.x * ι);
  steps[sc].pos.y = (pos.y += dir.y * ι);
  steps[sc].ρ = ρ;
  steps[sc].ι = ι;
  steps[sc].text = τ[0] == cb ? "cb" : τ[-5];
  sc++;
  draw();
  callback(ο, τ, α, ρ, ι);
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
static float zoom = 4;
void draw() {
  while (GetCharPressed() != 'n') {
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    BeginDrawing();
    ClearBackground(BLACK);
    Camera2D camera = {.target = {0, 0}, .rotation = 0, .zoom = zoom};
    camera.offset = (Vector2){GetScreenWidth() / 2.f, GetScreenHeight() / 2.f};
    BeginMode2D(camera);
    Vector2 s_pos = {0, 0};
    for (long i = 0; i < sc; i++) {
      step_t s = steps[i];
      int ry = (s.ρ + 1) * s.ι;
      Vector2 n_pos = {s.pos.x * 50 + s.dir.y * ry * 10,
                       s.pos.y * 50 + s.dir.x * -1 * ry * 10};
      DrawLineBezier(s_pos, n_pos, 2, colors[ry + 4]);
      DrawText(TextFormat("%s", s.text), n_pos.x, n_pos.y, 8,
               BLUE);
      s_pos = n_pos;
    }
    EndMode2D();
    EndDrawing();
  }
}

void ti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1800, 1000, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 35, 0, 0);
}
