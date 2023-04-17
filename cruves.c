#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
//............i+0............i+1............i+2............i+3............
Vector2 points[1024] = {};
int numPoints = 0;
Vector2 deCasteljau(Vector2 *points, int numPoints, float t) {
  if (numPoints == 1)
    return points[0];
  else {
    Vector2 newPoints[numPoints - 1];
    for (int i = 0; i < numPoints - 1; i++)
      newPoints[i] = Vector2Lerp(points[i], points[i + 1], t);
    return deCasteljau(newPoints, numPoints - 1, t);
  }
}
static long ts[1024];
static long tc = 0;
void ti(long t) {
  ts[tc++] = t;
}
int main() {
  InitWindow(800, 600, "Casteljau");
  SetTargetFPS(60);
  ti(0);
  while (!WindowShouldClose()) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
      points[numPoints++] = GetMousePosition();
    ClearBackground(WHITE);
    if (numPoints) {
      Vector2 prevPoint;
      for (float t = 0; t <= 1; t += 0.001) {
        Vector2 point = deCasteljau(points, numPoints, t);
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
