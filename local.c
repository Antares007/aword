#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
// clang-format off
#define AWords                                \
  X(b,    {3, -1}, {2, -1}, {0,  0}, {0, -1}, \
          {0,  1}, {1, -1}, {2,  1}, {3,  1}) \
  X(and,  {1,  1}, {2, -1}, {3, -1}, {0, -1}, \
          {0,  1}, {1, -1}, {2,  1}, {3,  1}) \
  X(aw,   {3, -1}, {2, -1}, {1, -1}, {0, -1}, \
          {0,  1}, {1,  1}, {2,  1}, {3,  1}) \
  X(or,   {1,  1}, {2, -1}, {3,  1}, {3, -1}, \
          {0,  1}, {1, -1}, {2,  1}, {3,  1}) \
  X(not,  {1,  1}, {3, -1}, {3,  1}, {0, -1}, \
          {0,  1}, {1, -1}, {2,  1}, {3,  1}) \
  X(orand,{1,  1}, {2, -1}, {3, -1}, {3, -1}, \
          {0,  1}, {1, -1}, {2,  1}, {3,  1}) \
  X(o,    {1,  1}, {2,  1}, {3,  1}, {0,  1}, \
          {0,  0}, {0,  0}, {0,  0}, {0,  0})
// clang-format on
#define X(name, ...) {__VA_ARGS__},
char aword_rays[][8][2] = {AWords};
#undef X
#define X(name, ...) #name,
const char *aword_names[] = {AWords};
#undef X
#define X(name, ...) aw_##name,
enum { AWords };
#undef X

static Color ray_colors[] = {
    YELLOW, RED, GREEN, BLUE, BLACK, DARKBLUE, LIME, MAROON, GOLD,
};
void draw_aword(const char *text, char exits[8][2]) {
  const int vspase = 10;
  const int width = 20;
  DrawRectangle(-width, -vspase * 6, width * 2, vspase * 11,
                (Color){.r = 0x87, .g = 0xce, .b = 0xeb, .a = 0xff});
  static char entrances[8][2] = {{3, -1}, {2, -1}, {1, -1}, {0, -1},
                                 {0, 1},  {1, 1},  {2, 1},  {3, 1}};
  for (long i = 0; i < 8; i++) {
    char si = entrances[i][1],
         sr = (entrances[i][0] + 1) * si; // start ray and start direction
    char ei = exits[i][1],
         er = (exits[i][0] + 1) * ei; // end ray and end direction
    if (ei == 0)
      continue;
    Vector2 startPos = {width * si, sr * vspase};
    Vector2 startControlPos = {-(width / 14.f) * sr, sr * vspase};
    Vector2 endPos = {-width * ei, er * vspase};
    Vector2 endControlPos = {(width / 14.f) * er, er * vspase};
    float thick = 2;
    Color color = ray_colors[sr + 4];
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
int main(void) {
  InitWindow(1500, 600, "AWord Drawing");
  SetTargetFPS(0);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(WHITE);
    DrawText(TextFormat("%d", GetFPS()), 0, 0, 25, BLACK);
    long awi[] = {aw_b,     aw_aw, aw_and, aw_aw, aw_or, aw_aw,
                  aw_orand, aw_aw, aw_not, aw_aw, aw_o};
    for (long i = 0; i < sizeof(awi) / sizeof(*awi); i++) {
      Camera2D camera = {0};
      camera.target = (Vector2){0, 0};
      camera.rotation = 0.0f;
      camera.zoom = 3.0f;
      camera.offset =
          (Vector2){100 + i * 41 * camera.zoom, GetScreenHeight() / 2.f};
      BeginMode2D(camera);
      draw_aword(aword_names[awi[i]], aword_rays[awi[i]]);
    }
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
