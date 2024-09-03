#include "sophis2.h"
#include <raylib.h>
#include <raymath.h>
#include <stdio.h>

const long SCREEN_WIDTH = 950;
const long SCREEN_HEIGHT = 600;
const long CELL_WIDTH = 70;
const long CELL_HEIGHT = 30;

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
static Vector2 off = {10, 10};

static Nar(drawVMState) {
  ClearBackground(RAYWHITE);
  Camera2D camera = {
      .target = {0, 0}, .rotation = 0, .zoom = zoom, .offset = off};
  BeginMode2D(camera);

  const long cols = (1 << 4);
  const long rows = 1 + (σ / (1 << 4));

  for (long x = 0; x < cols; x++) {
    for (long y = 0; y < rows; y++) {
      long t = x + y * (1 << 4);
      long opcode = text[t].sc;
      long colindex = 9;
      Rectangle rect = (Rectangle){x * CELL_WIDTH, y * CELL_HEIGHT,
                                   CELL_WIDTH - 5, CELL_HEIGHT - 5};
      DrawRectangleRounded(rect, 10, 10, colors[colindex][0]);
      if (opcode) {
        DrawRectangleRounded(rect, 10, 10, colors[colindex][0]);
        if (t == τ)
          DrawRectangleRoundedLines(rect, 10, 10, 3, RED);
        const char *txt = TextFormat("%s", text[t].name);
        float fontSize = 25, spacing = 0;
        Vector2 pos = {x * CELL_WIDTH + 5, y * CELL_HEIGHT};
        DrawTextEx(font, txt, pos, fontSize, spacing, colors[colindex][1]);
      }
    }
  }
  EndMode2D();
  EndDrawing();
}

extern void exit(int __status) __THROW __attribute__((__noreturn__));

Nar(sti_got) {
  long key;
  static int semi_auto = 0;
  do {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      off = Vector2Add(off, GetMouseDelta());
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    key = GetCharPressed();
    drawVMState(OS);
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
  SetTargetFPS(0);
  font = LoadFontEx("NovaMono-Regular.ttf", 25, 0, 0);
}
