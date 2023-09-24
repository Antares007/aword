#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
// clang-format off
#define AWords                                \
  X(b,    {0,  0}, {0,  0}, {0,  0}, {0,  0}, \
          {0, -1}, {1, -1}, {2, -1}, {3, -1}) \
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
static Font font;
void draw_aword(const char *text, char exits[8][2]) {
  const int vspase = 5;
  const int width = 15;
  Vector2 spos = {-width, -vspase * 6};
  Vector2 dim = {width * 2, vspase * 11};
  DrawRectangle(spos.x, spos.y, dim.x, dim.y,
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
    float thick = vspase / 5.f;
    Color color = ray_colors[sr + 4];
    DrawLineBezierCubic(startPos, endPos, startControlPos, endControlPos, thick,
                        color);
    if (si == 1)
      DrawTriangle((Vector2){startPos.x - vspase / 2.f, startPos.y},
                   (Vector2){startPos.x, startPos.y + vspase / 2.f},
                   (Vector2){startPos.x, startPos.y - vspase / 2.f}, color);
    else
      DrawTriangle((Vector2){startPos.x, startPos.y - vspase / 2.f},
                   (Vector2){startPos.x, startPos.y + vspase / 2.f},
                   (Vector2){startPos.x + vspase / 2.f, startPos.y}, color);
  }
  DrawTextEx(font, text, spos, width * .8f, 0, BLACK);
}
void draw_awords(float zoom) {
  DrawText(TextFormat("%d", GetFPS()), 0, 0, 25, BLACK);
  long awi[] = {aw_b,     aw_aw, aw_and, aw_aw, aw_or, aw_aw,
                aw_orand, aw_aw, aw_not, aw_aw, aw_o};
  for (long i = 0; i < sizeof(awi) / sizeof(*awi); i++) {
    Camera2D camera = {0};
    camera.target = (Vector2){0, 0};
    camera.rotation = 0.0f;
    camera.zoom = zoom;
    camera.offset =
        (Vector2){100 + i * 31 * camera.zoom, GetScreenHeight() / 2.f};
    BeginMode2D(camera);
    draw_aword(aword_names[awi[i]], aword_rays[awi[i]]);
  }
}
void draw_vec2(Vector2 v, int x, int y) {
  DrawText(TextFormat("%f %f", v.x, v.y), x, y, 50, BLACK);
}
void draw_stairway(long length) {
  DrawText(TextFormat("%d", length), 0, 0, 25, BLACK);
  Vector2 zero = {6 * GetScreenWidth() / 8.f, 4 * GetScreenHeight() / 8.f};
  Vector2 direction = {1, 0};
  for (long i = 0; i < length; i++) {
    float max_turns = (float)length / 20;
    float cur_turn = (float)i / 20;

    if (i % 10 == 0)
      direction = Vector2Rotate(direction, M_PI_2);
    zero = Vector2Add(
        zero, Vector2Scale(direction, Lerp(60, 90, cur_turn / max_turns)));
    Camera2D camera = {0};
    camera.target = (Vector2){0, 0};
    camera.rotation = 0.0f;
    camera.zoom = Lerp(.9, 1, cur_turn / max_turns);
    camera.offset = zero;
    BeginMode2D(camera);
    Vector2 fs = MeasureTextEx(GetFontDefault(), TextFormat("%d", i), 25, 1);
    DrawRectangle(-5, -5, fs.x + 10, fs.y + 10, WHITE);
    DrawRectangleLines(-5, -5, fs.x + 10, fs.y + 10, BLACK);
    DrawTextEx(GetFontDefault(), TextFormat("%d", i), (Vector2){0, 0}, 25, 1,
               BLACK);
    EndMode2D();
  }
  draw_vec2(zero, 0, 30);
  draw_vec2(direction, 0, 60);
}
int main(void) {
  InitWindow(1000, 1000, "AWord Drawing");
  SetTargetFPS(0);
  font = LoadFont("NovaMono-Regular.ttf");
  float zoom = 4.0f;
  while (!WindowShouldClose()) {
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    BeginDrawing();
    ClearBackground(WHITE);
    draw_stairway(zoom * 10);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
