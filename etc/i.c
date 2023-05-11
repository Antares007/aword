#include <math.h>
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

Vector2 find_crossing_point(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3);
int main() {
  float zoom = 4.f;
  Vector2 off = {0, 0};
  InitWindow(1000, 800, "complex");
  while (!WindowShouldClose()) {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      off = Vector2Add(off, GetMouseDelta());
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    BeginDrawing();
    ClearBackground(BLUE);
    Camera2D c = {.zoom = zoom,
                  .offset = {GetScreenWidth() / 2.f, GetScreenHeight() / 2.f}};
    c.offset = Vector2Add(c.offset, off);
    BeginMode2D(c);
    Vector2 p0 = {0, 0};
    Vector2 p1 = {20, 5};
    Vector2 p2 = {100, 0};
    Vector2 p3 = {0, 100};
    DrawLineV(p0, p1, WHITE);
    DrawLineV(p2, p3, WHITE);
    float px, py;
    Vector2 p = find_crossing_point(p0, p1, p2, p3);
    DrawCircleV(p, 5, WHITE);
    Vector2 center = {0, 0};
    int numPoints = 1;
    for (int radius = 30; radius < 100; radius += 10)
      for (float i = -PI; i < PI; i += PI / 4) {
        // float theta = ((float)i / numPoints) * 2 * PI;
        Vector2 point = {center.x + radius * cos(i),
                         center.y + radius * sin(i)};
        // DrawText(TextFormat("%f", point.x), point.x, point.y, 5, RED);
        DrawPixelV(point, WHITE);
      }

    EndMode2D();
    EndDrawing();
  }
  return 0;
}
Vector2 find_crossing_point(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3) {
  float m1 = (p1.y - p0.y) / (p1.x - p0.x);
  float b1 = p0.y - m1 * p0.x;
  float m2 = (p3.y - p2.y) / (p3.x - p2.x);
  float b2 = p2.y - m2 * p2.x;
  float cross_x = (b2 - b1) / (m1 - m2);
  float cross_y = m1 * cross_x + b1;
  return (Vector2){cross_x, cross_y};
}
