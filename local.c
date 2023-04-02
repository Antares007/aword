#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
char awords[][8][2][2] = {{
                              // b
                              {{3, 0}, {3, -1}},
                              {{2, 0}, {2, -1}},
                              {{1, 0}, {1, -1}},
                              {{0, 0}, {0, -1}},

                              {{0, 1}, {0, -1}},
                              {{1, 1}, {1, -1}},
                              {{2, 1}, {2, -1}},
                              {{3, 1}, {3, -1}},
                          },
                          {
                              // and
                              {{3, -1}, {1, +1}},
                              {{2, -1}, {2, -1}},
                              {{1, -1}, {3, -1}},
                              {{0, -1}, {0, -1}},

                              {{0, 1}, {0, -1}},
                              {{1, 1}, {1, -1}},
                              {{2, 1}, {2, -1}},
                              {{3, 1}, {3, +1}},
                          },
                          {
                              // aw
                              {{3, -1}, {3, -1}},
                              {{2, -1}, {2, -1}},
                              {{1, -1}, {1, -1}},
                              {{0, -1}, {0, -1}},

                              {{0, 1}, {0, 1}},
                              {{1, 1}, {1, 1}},
                              {{2, 1}, {2, 1}},
                              {{3, 1}, {3, 1}},
                          },
                          {
                              // or
                              {{3, -1}, {1, +1}},
                              {{2, -1}, {2, -1}},
                              {{1, -1}, {3, 1}},
                              {{0, -1}, {3, -1}},

                              {{0, 1}, {0, -1}},
                              {{1, 1}, {1, -1}},
                              {{2, 1}, {2, -1}},
                              {{3, 1}, {3, +1}},
                          },
                          {
                              // not
                              {{3, -1}, {1, +1}},
                              {{2, -1}, {3, -1}},
                              {{1, -1}, {3, 1}},
                              {{0, -1}, {0, -1}},

                              {{0, 1}, {0, -1}},
                              {{1, 1}, {1, -1}},
                              {{2, 1}, {2, -1}},
                              {{3, 1}, {3, +1}},
                          },
                          {
                              // o
                              {{3, -1}, {1, 1}},
                              {{2, -1}, {2, 1}},
                              {{1, -1}, {3, 1}},
                              {{0, -1}, {0, 1}},

                              {{0, 0}, {0, -1}},
                              {{1, 0}, {1, -1}},
                              {{2, 0}, {2, -1}},
                              {{3, 0}, {3, -1}},
                          }};

static Color ray_colors[] = {
    PURPLE, // Purple
    YELLOW, // Yellow
    RED,    // Red
    GREEN,  // Green
    BLUE,   // Blue
    BLACK,
    DARKBLUE, // Dark Blue
    LIME,     // Lime
    MAROON,   // Maroon
    GOLD,     // Gold
    MAGENTA,  // Magenta
};
void drawray(const char *text, char rays[8][2][2]) {
  const int vspase = 10;
  const int width = 20;
  DrawRectangle(-width, -vspase * 6, width * 2, vspase * 11,
                (Color){.r = 0x87, .g = 0xce, .b = 0xeb, .a = 0xff});
  for (long i = 0; i < 8; i++) {
    char sr = rays[i][0][0],
         si = rays[i][0][1]; // start ray and start direction
    char er = rays[i][1][0], ei = rays[i][1][1]; // end ray and end direction
    if (si == 0)
      continue;
    Vector2 startPos = {width * si, (sr + 1) * si * vspase};
    Vector2 startControlPos = {-(width / 14.f) * (sr + 1) * si,
                               (sr + 1) * vspase * si};
    Vector2 endPos = {-width * ei, (er + 1) * vspase * ei};
    Vector2 endControlPos = {(width / 14.f) * (er + 1) * ei,
                             (er + 1) * vspase * ei};
    float thick = 2;
    Color color = ray_colors[(sr + 1) * si + 5];
    DrawLineBezierCubic(startPos, endPos, startControlPos, endControlPos, thick,
                        color);
    if (si == 1)
      DrawTriangle((Vector2){startPos.x - vspase / 2.f, startPos.y},
                   (Vector2){startPos.x, startPos.y + 5},
                   (Vector2){startPos.x, startPos.y - 5}, color);
    else
      DrawTriangle((Vector2){startPos.x, startPos.y - 5},
                   (Vector2){startPos.x, startPos.y + 5},
                   (Vector2){startPos.x + vspase / 2.f, startPos.y}, color);
  }
  DrawText(text, -width + 5, -vspase * 6, 10, BLACK);
}
#define RAY(r, i) (((r) + 1) * (i))
void local(Vector2 offset, const char *title, char rays[8][2][2]) {
  // Set up camera for local coordinate system
  Camera2D camera = {0};
  camera.target = (Vector2){0, 0};
  camera.offset = offset;
  camera.rotation = 0.0f;
  camera.zoom = 3.0f;
  BeginMode2D(camera);
  drawray(title, rays);
  Matrix mat = MatrixIdentity();
  mat =
      MatrixMultiply(mat, MatrixTranslate(camera.offset.x, camera.offset.y, 0));
  mat = MatrixMultiply(mat, MatrixRotateZ(-camera.rotation * DEG2RAD));
  mat = MatrixMultiply(mat, MatrixScale(camera.zoom, camera.zoom, 1));
  Vector2 posLocal = (Vector2){0, 0};
  Vector2 posWorld = Vector2Transform(posLocal, mat);
  char text[70];
  snprintf(text, 70, "Position in world\ncoordinates:\n(%f, %f)\n", posWorld.x,
           posWorld.y);
  DrawText(text, 0, 50, 10, WHITE);
  EndMode2D();
}
int main(void) {
  // Initialize Raylib
  InitWindow(1500, 600, "2D Drawing");
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);
    void *awi[][2] = {
        {(void *)0, "b  "},  {(void *)2, "aw "}, {(void *)1, "and"},
        {(void *)2, "aw "},  {(void *)3, "or "}, {(void *)2, "aw "},
        {(void *)4, "not "}, {(void *)5, "o  "},
    };
    for (long i = 0; i < sizeof(awi) / sizeof(*awi); i++) {
      Camera2D camera = {0};
      camera.target = (Vector2){0, 0};
      camera.rotation = 0.0f;
      camera.zoom = 3.0f;
      camera.offset =
          (Vector2){100 + i * 40 * camera.zoom, GetScreenHeight() / 2.f};
      BeginMode2D(camera);
      drawray(awi[i][1], awords[(long)awi[i][0]]);
    }
    EndDrawing();
  }
  // Print position in world coordinates

  // Close window and exit
  CloseWindow();
  return 0;
}
