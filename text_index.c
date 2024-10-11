#include "main.h"
#include <raylib.h>
#include <raymath.h>

const long CELL_WIDTH = 90;
const long CELL_HEIGHT = 30;

static const Color oan_colors[][2] = {
    {(Color){000, 000, 255, 255}, WHITE}, // Blue
    {(Color){000, 128, 000, 255}, WHITE}, // Green
    {(Color){255, 000, 000, 255}, BLACK}, // Red
};
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
static int bside = 0;

static void DrawBetaStack(long *o, long **β, int ρ, long δ, float zoom, int x,
                          int y) {
  Camera2D k1 = {
      .target = {0, 0}, .rotation = ρ * 90, .zoom = zoom, .offset = {x, y}};
  BeginMode2D(k1);
  const float cell_height = 30;
  float font_size = 30;
  float spacing = 0;
  float top = 0;
  int color_index = (ρ + 1) * δ + 5;

  while (β) {
    long length = β[ρ][-2];
    float widths[length];
    float row_width = 0;
    for (long i = 0; i < length; i++)
      row_width += widths[i] =
          MeasureTextEx(font, β[ρ][i + length], font_size, spacing).x + 20;
    float left = -(row_width / 2.f);
    for (long i = 0; i < length; i++) {
      Rectangle rect = {left + 3, top, widths[i] - 6, cell_height};
      DrawRectangleRounded(rect, 0.6f, 10, colors[color_index][0]);
      const char *text = β[ρ][i + length];
      DrawTextEx(font, text, (Vector2){rect.x + 10, rect.y}, font_size, spacing,
                 colors[color_index][1]);
      left += widths[i];
    }
    top += cell_height + 3;
    β = β[ρ][-1];
  }
  EndMode2D();
}
static N(drawVMState) {
  ClearBackground(DARKGRAY);
  Camera2D camera = {
      .target = {0, 0}, .rotation = 0, .zoom = zoom, .offset = off};
  BeginMode2D(camera);
  for (long x = 0, y = 0, t = 512; t < σ;) {
    long color_index = (o[t - 1] + 1) * o[t - 2] + 5;
    long opcode = o[t];
    long selected = t == τ;
    long beta_height = 3;
    const char *txt = opcode == tword  ? TextFormat("T:%s", (char *)o[t + 1])
                      : opcode == name ? TextFormat("N:%s", (char *)o[t + 1])
                      : opcode == term ? TextFormat("'%s'", (char *)o[t + 1])
                      : opcode == put  ? TextFormat("\"%s\"", (char *)o[t + 1])
                                       : TextFormat("%s", sopcode_names[o[t]]);
    float fontSize = 20, spacing = 0;
    // Vector2 textsize = MeasureTextEx(font, txt, fontSize, spacing);
    Vector2 textsize = {50, 30};

    Rectangle rect = (Rectangle){x, y, textsize.x + 10, CELL_HEIGHT - 5};
    Color bgcolor = opcode == halt ? GRAY : colors[color_index][0];
    DrawRectangleRounded(rect, 0.2f, 10, bgcolor);
    if (selected)
      DrawRectangleRoundedLines(rect, 0.2f, 10, beta_height, oan_colors[ν][0]);

    DrawTextEx(font, txt, (Vector2){x + 3, y - 3}, fontSize, spacing,
               colors[color_index][1]);
    DrawTextEx(font, TextFormat("%10ld", t), (Vector2){x + 3, y + 12},
               fontSize / 1.5f, spacing, colors[color_index][1]);

    if (o[t] == nl)
      y += CELL_HEIGHT, x = 0, t = ((t >> Σ) + 1) << Σ;
    else
      x += textsize.x + 15, t += 11;
  }
  EndMode2D();

  float k_zoom = zoom / 1.5f;
  if (bside){
    β = α;
    δ = -δ;
  }
  DrawBetaStack(o, β, 0, δ, k_zoom, GetScreenWidth() / 2.f, 0);
  DrawBetaStack(o, β, 1, δ, k_zoom, GetScreenWidth(), GetScreenHeight() / 2.f);
  DrawBetaStack(o, β, 2, δ, k_zoom, GetScreenWidth() / 2.f, GetScreenHeight());
  DrawBetaStack(o, β, 3, δ, k_zoom, 0, GetScreenHeight() / 2.f);
  EndDrawing();
}
extern void exit(int __status) __THROW __attribute__((__noreturn__));
N(ti_debug) {
  o[τ - 1] = ρ;
  o[τ - 2] = δ;
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
    else if (key == 'b')
      bside = !bside;
    else if (key == 'c')
      semi_auto = 2;
    else if (key == 'C')
      semi_auto = !semi_auto;
  } while (key != 's' && !semi_auto);
}
void ti_init(void) {
  SetTraceLogLevel(LOG_ERROR);
  InitWindow(0, 0, "Sophisticated text index");
  SetWindowSize(GetScreenWidth() / 2, GetScreenHeight());
  SetWindowPosition(0, 0);
  SetTargetFPS(120);
  font = LoadFontEx("NovaMono-Regular.ttf", 135, 0, 0);
}
