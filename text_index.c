#include "aword.h"
#include <assert.h>
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>
Camera2D camera = {
    .target = (Vector2){0, 0},
    .rotation = 0.0f,
    .zoom = 1.f,
    .offset = (Vector2){900, 500},
};
Vector2 dir = {1, 0};
// W(begin_mode2d, 1, 1) { BeginMode2D(camera), m(τ, ρ, δ); }
// W(end_mode2d, 1, 1) { EndMode2D(), m(τ, ρ, δ); }
void camera_move(long δ) {
  BeginMode2D(camera);
  camera.offset.x += dir.x * 50 * δ;
  camera.offset.y += dir.y * 50 * δ;
}
void camera_turn_left() {
  float x = dir.x;
  dir.x = dir.y, dir.y = x * -1;
}
N(ti);
N(cb);
void draw(long depth, void **t, long d, long x, long y) {
  if (!depth)
    return;
  if (t[0] == ti)
    DrawText(t[5], x, y, 45, WHITE), x += 50 * d;
  else if (t[0] == b)
    d = -d, y += 50;
  else if (t[0] == o)
    d = -d, y -= 50;
  draw(depth - 1, t + 11 * d, d, x, y);
}
N(ti) {
  while (GetCharPressed() != 'n') {
    BeginDrawing();
    ClearBackground(BLACK);
    draw(100, τ, δ, 500, 500);
    EndDrawing();
  }
  m(τ, ρ, δ);
}
void ti_init() {
  InitWindow(1800, 1000, "aword");
  SetTargetFPS(60);
}
W(begin_drawing, 1, 1) {
  BeginDrawing();
  ClearBackground(BLACK);
  m(τ, ρ, δ);
}
W(end_drawing, 1, 1) {
  EndDrawing();
  if (WindowShouldClose())
    CloseWindow();
  else
    m(τ, ρ, δ);
}
W(seven, 1, 1) {
  DrawText("7", 100, 100, 45, RED);
  m(τ, ρ, δ);
}
