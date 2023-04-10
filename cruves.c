#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
Vector2 points[1024] = {};
int points_count = 0;
Vector2 deCasteljau(Vector2 *points, int numPoints, float t) {
  if (numPoints == 1) {
    return points[0];
  } else {
    Vector2 newPoints[numPoints - 1];
    for (int i = 0; i < numPoints - 1; i++) {
      newPoints[i] = Vector2Lerp(points[i], points[i + 1], t);
    }
    return deCasteljau(newPoints, numPoints - 1, t);
  }
}
int main() {
  InitWindow(800, 600, "Casteljau");
  while (!WindowShouldClose()) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
      points[points_count++] = GetMousePosition();
    ClearBackground(WHITE);
    if (points_count) {
      Vector2 prevPoint;
      for (float t = 0; t <= 1; t += 0.01) {
        Vector2 point = deCasteljau(points, points_count, t);
        if (t == 0) {
          DrawPixel((int)point.x, (int)point.y, RED);
        } else {
          DrawLineEx(prevPoint, point, 2, BLUE);
        }
        prevPoint = point;
      }
    }
    EndDrawing();
  }
  CloseWindow();
}
