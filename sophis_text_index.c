#include "sophis.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>
#include <unistd.h>

// Constants
const int SCREEN_WIDTH = 100 * (1 << 7) / 11;
const int SCREEN_HEIGHT = 600;
const int CELL_WIDTH = 100;
const int CELL_HEIGHT = 30;
const int MAX_OPCODES = 512;

// Color Definitions
static const Color colors[] = {
    CLITERAL(Color){255, 0, 255, 255},   // Fuchsia
    CLITERAL(Color){128, 128, 0, 255},   // Olive
    CLITERAL(Color){128, 0, 0, 255},     // Maroon
    CLITERAL(Color){0, 255, 0, 255},     // Lime
    CLITERAL(Color){0, 0, 128, 255},     // Navy
    CLITERAL(Color){255, 255, 255, 255}, // White
    CLITERAL(Color){0, 0, 255, 255},     // Blue
    CLITERAL(Color){0, 128, 0, 255},     // Green
    CLITERAL(Color){255, 0, 0, 255},     // Red
    CLITERAL(Color){255, 255, 0, 255},   // Yellow
    CLITERAL(Color){128, 0, 128, 255},   // Purple
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
      if (opcode) {
        DrawRectangle(x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH - 5,
                      CELL_HEIGHT - 5, colors[colindex]);
        if (t == τ) {
          DrawRectangleLinesEx((Rectangle){x * CELL_WIDTH, y * CELL_HEIGHT,
                                           CELL_WIDTH - 5, CELL_HEIGHT - 5},
                               3, RED);
        }
        DrawTextEx(
            font,
            opcode == put ? TextFormat("%c", o[t + 1])
                          : TextFormat("%s", (opcode == tword || opcode == name
                                                  ? (char *)o[t + 1]
                                                  : snames[opcode])),
            (Vector2){x * CELL_WIDTH + 5, y * CELL_HEIGHT}, 25, 0, BLACK);
      }
    }
  }
  EndMode2D();
  EndDrawing();
}
#include <stdlib.h>
void sti_got(long *o) {
  o[τ - 5] = ρ;
  o[τ - 4] = δ;
  printf("%7s %4ld %4ld %s\n", rays[(ρ + 1) * δ + 5], τ, σ, snames[o[τ]]);
  long key;
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
    }
  } while (key != 'c');
}
void sti_init() {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Sophisticated text index");
  SetTargetFPS(0);
  font = LoadFontEx("NovaMono-Regular.ttf", 25, 0, 0);
}
