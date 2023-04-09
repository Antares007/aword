#include "aword.h"
#include <assert.h>
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>
static Font font;
typedef struct step_t {
  void **prev_t;
  void **t;
  long r;
  long d;
} step_t;
N(cb);
N(toti_pith);
void turn_left(Camera2D *c, Vector2 *v) {
  c->rotation += 90;
  int x = v->x;
  v->x = v->y;
  v->y = x * -1;
}
void move(Camera2D *c, Vector2 *v) {
  c->offset.x += v->x * 100;
  c->offset.y += v->y * 100;
}
N(m) {
  static step_t steps[1024];
  static long step = 0;
  step %= sizeof(steps) / sizeof(*steps);
  steps[step].prev_t = τ;
  steps[step].t = (τ += 11 * δ);
  steps[step].r = ρ;
  steps[step].d = δ;
  step++;

  while (GetCharPressed() != 'n') {
    BeginDrawing();
    ClearBackground(BLACK);
    Camera2D camera = {
        .target = (Vector2){0, 0},
        .rotation = 180.0f,
        .zoom = 1.f,
        .offset = (Vector2){900, 500},
    };
    Vector2 dir = {-1, 0};
    for (long i = 0; i < step; i++) {
      void **curr_t = steps[i].t;
      void **prev_t = steps[i].prev_t;
      char *text = curr_t[0] == toti_pith ? "pith"
                   : curr_t[0] == cb      ? "cb"
                                          : (char *)steps[i].t[5];
      if (curr_t[0] == o) {
        move(&camera, &dir);
        turn_left(&camera, &dir);
        turn_left(&camera, &dir);
      } else if (curr_t[0] == b) {
        move(&camera, &dir);
        turn_left(&camera, &dir);
        turn_left(&camera, &dir);
      } else if (curr_t[0] == cb) {
        move(&camera, &dir);
        turn_left(&camera, &dir);
        if (steps[i].r == 1)
          turn_left(&camera, &dir);
      } else if (curr_t[0] == toti_pith) {
        move(&camera, &dir);
        if (steps[i].r == 1 && steps[i].d == 1)
          turn_left(&camera, &dir);
      } else
        move(&camera, &dir);

      BeginMode2D(camera);
      DrawRectangleLines(-49, -49, 98, 98, WHITE);
      DrawTextEx(font, text, (Vector2){-49, -49}, 45, 4, WHITE);
      DrawRectangle(0, -49, 49, 20, WHITE);

      DrawTextEx(font, TextFormat("%ld",i), (Vector2){0, -49}, 20, 4, BLACK);
      EndMode2D();
    }
    EndDrawing();
  }
  ((N((**)))τ)[0](τ, ρ, δ);
}
void ti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(1800, 1000, "aword");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 90, 0, 0);
}
