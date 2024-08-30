#include "sophis.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <unistd.h>

const int SCREEN_WIDTH = 100 * (1 << 7) / 11;
const int SCREEN_HEIGHT = 600;
const int CELL_WIDTH = 100;
const int CELL_HEIGHT = 30;
const int MAX_OPCODES = 512;

static const Color colors[][2] = {
    {(Color){255, 000, 255, 255}, BLACK}, // Fuchsia
    {(Color){128, 128, 000, 255}, BLACK}, // Olive
    {(Color){128, 000, 000, 255}, WHITE}, // Maroon
    {(Color){000, 255, 000, 255}, BLACK}, // Lime
    {(Color){000, 000, 128, 255}, WHITE}, // Navy
    {(Color){255, 255, 255, 255}, BLACK}, // White
    {(Color){000, 000, 255, 255}, WHITE}, // Blue
    {(Color){000, 128, 000, 255}, WHITE}, // Green
    {(Color){255, 000, 000, 255}, BLACK}, // Red
    {(Color){255, 255, 000, 255}, BLACK}, // Yellow
    {(Color){128, 000, 128, 255}, WHITE}, // Purple
};

static Font font;
static float zoom = 1.5;
static Vector2 off = {10, -140};

static void drawVMState(long *o) {
  ClearBackground(RAYWHITE);
  Camera2D camera = {
      .target = {0, 0}, .rotation = 0, .zoom = zoom, .offset = off};
  BeginMode2D(camera);
  const long cols = (1 << 7) / 11;
  long rows = 1 + ((σ + 5) / (1 << 7));
  for (long y = 0; y < rows; y++) {
    for (long x = 0; x < cols; x++) {
      long t = x * 11 + y * (1 << 7);
      if (t < MAX_OPCODES)
        continue;
      long opcode = o[t];
      long colindex = (o[t - 5] + 1) * o[t - 4] + 5;
      Rectangle rect = (Rectangle){x * CELL_WIDTH, y * CELL_HEIGHT,
                                   CELL_WIDTH - 5, CELL_HEIGHT - 5};
      if (opcode) {
        DrawRectangleRounded(rect, 10, 10, colors[colindex][0]);
        if (t == τ) {
          DrawRectangleRoundedLines(rect, 10, 10, 3, RED);
        }
        DrawTextEx(font,
                   opcode == put     ? TextFormat("\"%s\"", (char *)o[t + 1])
                   : opcode == tword ? TextFormat("T:%s", (char *)o[t + 1])
                   : opcode == name  ? TextFormat("N:%s", (char *)o[t + 1])
                   : opcode == term  ? TextFormat("%s<", (char *)o[t + 1])
                                     : TextFormat("%s", snames[opcode]),
                   (Vector2){x * CELL_WIDTH + 5, y * CELL_HEIGHT}, 25, 0,
                   colors[colindex][1]);
      }
    }
  }
  EndMode2D();
  EndDrawing();
}
#include <stdlib.h>
static int semi_auto = 0;
void sti_got(long *o) {
  o[τ - 5] = ρ;
  o[τ - 4] = δ;
  printf("%7s %2ld %3ld %4ld %4ld %s\n", rays[(ρ + 1) * δ + 5], α, β, τ, σ,
         snames[o[τ]]);
  long key;
  if (τ == 512 && ρ >= 2)
    semi_auto = 0;
  do {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      off = Vector2Add(off, GetMouseDelta());
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    key = GetCharPressed();
    drawVMState(o);
    if (WindowShouldClose()) {
      CloseWindow();
      exit(0);
    } else if (key == 'c')
      semi_auto = !semi_auto;
  } while (key != 's' && !semi_auto);
}
void sti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sophisticated text index");
  SetTargetFPS(60);
  font = LoadFontEx("NovaMono-Regular.ttf", 25, 0, 0);
}
