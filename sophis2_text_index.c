#include "sophis2.h"
#include <raylib.h>
#include <raymath.h>

const long CELL_WIDTH = 90;
const long CELL_HEIGHT = 30;

static long d_ram[0x10000];
static long *d_o = d_ram + sizeof(d_ram) / sizeof(*d_ram) / 2;

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
Nar(NotAndOr);
static void DrawCell(long opcode, long colindex, long x, long y, long t,
                     long selected, long *o, long β, long ν) {
  Rectangle rect = (Rectangle){x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH - 5,
                               CELL_HEIGHT - 5};
  Color bgcolor = opcode == halt ? GRAY : colors[colindex][0];
  DrawRectangleRounded(rect, 0.2f, 10, bgcolor);
  if (selected)
    DrawRectangleRoundedLines(rect, 0.2f, 10, (1022 - β) * 2, RED);
  const char *txt = opcode == tword  ? TextFormat("T:%s", (char *)o[t + 1])
                    : opcode == name ? TextFormat("N:%s", (char *)o[t + 1])
                    : opcode == term ? TextFormat("'%s'", (char *)o[t + 1])
                    : opcode == put  ? TextFormat("\"%s\"", (char *)o[t + 1])
                                     : TextFormat("%s", sopcode_names[o[t]]);
  float fontSize = 25, spacing = 0;
  Vector2 pos = {x * CELL_WIDTH + 5, y * CELL_HEIGHT};
  if (selected && o[-β])
    DrawTextEx(font, TextFormat("%11s", o[-β]),
               Vector2Add(pos, (Vector2){0, 10}), fontSize / 1.5, spacing,
               colors[colindex][1]);
  DrawTextEx(font, txt, pos, fontSize / 1.5, spacing, colors[colindex][1]);
}
static Nar(drawVMState) {
  ClearBackground(DARKGRAY);
  Camera2D camera = {
      .target = {0, 0}, .rotation = 0, .zoom = zoom, .offset = off};
  BeginMode2D(camera);
  long x = 0, y = 0, t = 1024;
  while (t <= σ) {
    DrawCell(o[t], (d_o[t + 1] + 1) * d_o[t + 2] + 5, x, y, t, t == τ, o, β, ν);
    if (o[t] == nl)
      y++, x = 0, t = ((t >> Σ) + 1) << Σ;
    else
      x++, t += 11;
  }

  int beta_top = 1024 < (β + 10) ? 1024 : β + 10;
  Vector2 pos = {GetScreenWidth() / zoom - CELL_WIDTH - 5,
                 GetScreenHeight() / zoom - CELL_HEIGHT * (beta_top - β) - 5};
  for (long beta = β; beta < beta_top; beta++) {
    Rectangle rect = {pos.x, pos.y, CELL_WIDTH - 5, CELL_HEIGHT - 5};
    DrawRectangleRounded(rect, 0.2f, 10, LIGHTGRAY);
    DrawTextEx(font, TextFormat("%s", o[-beta]), pos, 20, 0, RED);
    pos.y += CELL_HEIGHT;
  }

  EndMode2D();
  EndDrawing();
}
extern void exit(int __status) __THROW __attribute__((__noreturn__));
Nar(sti_got) {
  d_o[τ + 1] = ρ;
  d_o[τ + 2] = δ;
  long key;
  static int semi_auto = 0;
  do {
    if (o[τ] == begin && semi_auto == 2)
      semi_auto = 0;
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      off = Vector2Add(off, GetMouseDelta());
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    key = GetCharPressed();
    drawVMState(OS);
    if (WindowShouldClose())
      CloseWindow(), exit(0);
    else if (key == 'c')
      semi_auto = 2;
    else if (key == 'C')
      semi_auto = !semi_auto;
  } while (key != 's' && !semi_auto);
}
void sti_init(void) {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(0, 0, "Sophisticated text index");
  SetWindowSize(GetScreenWidth() / 2, GetScreenHeight());
  SetWindowPosition(0, 0);
  SetTargetFPS(15);
  font = LoadFontEx("NovaMono-Regular.ttf", 135, 0, 0);
}
