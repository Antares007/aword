#include "sophis2.h"
#include <raylib.h>
#include <raymath.h>

const long CELL_WIDTH = 90;
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

static void DrawKannal(long *o, long beta, long color_index) {
  int beta_top = ((beta >> Σ) + 1) << Σ;
  const float cell_height = CELL_HEIGHT;
  float cell_offset = cell_height + 3;
  Vector2 pos = {0, -cell_offset * (beta_top - beta)};
  int size = 30;
  int spacing = 0;

  for (; beta < beta_top; beta++) {
    const char *text = (const char *)o[-beta];
    Vector2 text_size = MeasureTextEx(font, text, size, spacing);

    float half_text_width = text_size.x / 2.f;
    Rectangle rect = {-half_text_width - 10, pos.y, text_size.x + 20,
                      cell_height};
    DrawRectangleRounded(rect, 0.6f, 10, colors[color_index][0]);
    DrawTextEx(font, text, Vector2Add(pos, (Vector2){-half_text_width, 0}),
               size, spacing, colors[color_index][1]);

    pos.y += cell_offset;
  }
}

static void DrawBetaStack(long *o, long *beta, int rho, long delta, float zoom,
                          int x, int y) {
  Camera2D k1 = {
      .target = {0, 0}, .rotation = rho * 90, .zoom = zoom, .offset = {x, y}};
  BeginMode2D(k1);
  DrawKannal(o, beta[rho], (rho + 1) * delta + 5);
  EndMode2D();
}
static N(drawVMState) {
  ClearBackground(DARKGRAY);
  Camera2D camera = {
      .target = {0, 0}, .rotation = 0, .zoom = zoom, .offset = off};
  BeginMode2D(camera);
  for (long x = 0, y = 0, t = 6 << Σ; t < σ;) {
    long color_index = (o[-t - 1] + 1) * o[-t - 2] + 5;
    long opcode = o[α++] = o[t];
    long selected = t == τ;
    long beta_height = ((((β[ρ] >> Σ) + 1) << Σ) - β[ρ]) * 2;
    const char *txt = opcode == tword ? TextFormat("tword:%s", (char *)o[t + 1])
                      : opcode == name ? TextFormat("name:%s", (char *)o[t + 1])
                      : opcode == term ? TextFormat("'%s'", (char *)o[t + 1])
                      : opcode == put  ? TextFormat("\"%s\"", (char *)o[t + 1])
                                       : TextFormat("%s", sopcode_names[o[t]]);
    float fontSize = 25, spacing = 0;
    Vector2 textsize = MeasureTextEx(font, txt, fontSize, spacing);

    Rectangle rect = (Rectangle){x, y, textsize.x + 10, CELL_HEIGHT - 5};
    Color bgcolor = opcode == halt ? GRAY : colors[color_index][0];
    DrawRectangleRounded(rect, 0.2f, 10, bgcolor);
    if (selected)
      DrawRectangleRoundedLines(rect, 0.2f, 10, beta_height, RED);
    Vector2 pos = {x + 5, y};
    DrawTextEx(font, txt, pos, fontSize, spacing, colors[color_index][1]);

    if (o[t] == nl)
      y += CELL_HEIGHT, x = 0, t = ((t >> Σ) + 1) << Σ;
    else
      x += textsize.x + 15, t += 11;
  }
  EndMode2D();

  float k_zoom = zoom / 1.5f;
  DrawBetaStack(o, β, 0, δ, k_zoom, GetScreenWidth() / 2.f, GetScreenHeight());
  DrawBetaStack(o, β, 1, δ, k_zoom, 0, GetScreenHeight() / 2.f);
  DrawBetaStack(o, β, 2, δ, k_zoom, GetScreenWidth() / 2.f, 0);
  DrawBetaStack(o, β, 3, δ, k_zoom, GetScreenWidth(), GetScreenHeight() / 2.f);
  EndDrawing();
}
extern void exit(int __status) __THROW __attribute__((__noreturn__));
N(sti_got) {
  o[-(τ + 1)] = ρ;
  o[-(τ + 2)] = δ;
  long key;
  static int semi_auto = 0;
  do {
    if (o[τ] == nl && semi_auto == 2)
      semi_auto = 0;
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      off = Vector2Add(off, GetMouseDelta());
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    key = GetCharPressed();
    drawVMState(To);
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
  SetTargetFPS(120);
  font = LoadFontEx("NovaMono-Regular.ttf", 135, 0, 0);
}
