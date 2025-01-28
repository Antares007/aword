#include "sophis.h"
#include <raylib.h>
#include <raymath.h>
const long CELL_WIDTH = 90;
const long CELL_HEIGHT = 30;
static const Color oan_colors[][2];
const char *rays[];
static const Color colors[][2];
static Font font;
static float zoom = 2;
static Vector2 off = {300, 200};
static int bside = 0;
static int raw = 0;
static int auto_center = 1;
static int full_duplex = 1;
static int going_to = 0;
static int skip_until = -1;
static int skip_this_word = 0;
static unsigned char opacity = 91;
static int stops[127];
static const char **stringify_ray(long *ray);
static void DrawBetaStack(long *ο, long **β, int ρ, int selected, long δ,
                          float zoom, int r, int x, int y) {
  Camera2D k1 = {
      .target = {0, 0}, .rotation = r, .zoom = zoom, .offset = {x, y}};
  BeginMode2D(k1);
  const float cell_height = 30;
  float font_size = 30;
  float spacing = 0;
  float top = 0;
  float max_width = 0;
  int color_index = (ρ + 1) * δ + 5;

  while (β) {
    float widths[20];
    float row_width = 0;
    const char **lables = stringify_ray(β[ρ]);
    for (long i = 0; i < β[ρ][-2]; i++)
      row_width += widths[i] =
          MeasureTextEx(font, lables[i], font_size, spacing).x + 20;
    if (max_width < row_width)
      max_width = row_width;
    float left = -(row_width / 2.f);
    for (long i = 0; i < β[ρ][-2]; i++) {
      Rectangle rect = {left + 3, top, widths[i] - 6, cell_height};
      DrawRectangleRounded(rect, 0.6f, 10, colors[color_index][0]);
      DrawTextEx(font, lables[i], (Vector2){rect.x + 10, rect.y}, font_size,
                 spacing, colors[color_index][1]);
      left += widths[i];
    }
    top += cell_height + 3;
    β = β[ρ][-1];
  }
  if (selected)
    DrawRectangleRoundedLinesEx(
        (Rectangle){-max_width / 2.f, -3, max_width, top + 3}, 0.1f, 10, 3,
        colors[color_index][0]);
  EndMode2D();
}
void drawStacks(long *ο, long **β, long ρ, long δ) {
  float k_zoom = zoom / 1.5f;
  float sw = GetScreenWidth();
  float sh = GetScreenHeight();
  float hw = sw / 2.f;
  float hh = sh / 2.f;
  DrawBetaStack(ο, β, 3, ρ == 3, δ, k_zoom, 0, hw, 10);
  DrawBetaStack(ο, β, 0, ρ == 0, δ, k_zoom, 90, sw - 10, hh);
  DrawBetaStack(ο, β, 1, ρ == 1, δ, k_zoom, 180, hw, sh - 10);
  DrawBetaStack(ο, β, 2, ρ == 2, δ, k_zoom, 270, 10, hh);
}
void drawEightStacks(long *ο, long **β, long **α, long ρ, long δ) {
  float k_zoom = zoom / 1.5f;
  float sw = GetScreenWidth();
  float sh = GetScreenHeight();
  float hw = sw / 2.f;
  float hh = sh / 2.f;
  hw -= 100 * zoom;
  hh -= 100 * zoom;
  DrawBetaStack(ο, β, 3, δ == +1 && ρ == 3, +1, k_zoom, 0, hw, 10);
  DrawBetaStack(ο, β, 0, δ == +1 && ρ == 0, +1, k_zoom, 90, sw - 10, hh);
  DrawBetaStack(ο, β, 1, δ == +1 && ρ == 1, +1, k_zoom, 180, hw, sh - 10);
  DrawBetaStack(ο, β, 2, δ == +1 && ρ == 2, +1, k_zoom, 270, 10, hh);
  hw += 200 * zoom;
  hh += 200 * zoom;
  DrawBetaStack(ο, α, 3, δ == -1 && ρ == 3, -1, k_zoom, 0, hw, 10);
  DrawBetaStack(ο, α, 0, δ == -1 && ρ == 0, -1, k_zoom, 90, sw - 10, hh);
  DrawBetaStack(ο, α, 1, δ == -1 && ρ == 1, -1, k_zoom, 180, hw, sh - 10);
  DrawBetaStack(ο, α, 2, δ == -1 && ρ == 2, -1, k_zoom, 270, 10, hh);
}
static void DrawGoToTable();
static void DrawBackGround();
static void drawVMState(long *ο, long **β, long **α, long τ, long σ, long ρ,
                        long δ, long ν) {
  ClearBackground(DARKGRAY);
  DrawBackGround();

  Camera2D camera = {
      .target = {0, 0}, .rotation = 0, .zoom = zoom, .offset = off};
  BeginMode2D(camera);
  long text_width = 0, y = 0;
  for (long x = 0, t = 512; t < σ;) {
    long color_index = (ο[t - 1] + 1) * ο[t - 2] + 5;
    long opcode = ο[t];
    long selected = t == τ;
    const char *txt = opcode == 1   ? TextFormat("1")
                      : opcode == 2 ? TextFormat("2 \"%s\"", (char *)ο[t + 1])
                      : opcode == 3 ? TextFormat("3 \"%s\"", (char *)ο[t + 1])
                      : opcode == 4 ? TextFormat("4")
                      : opcode == 5 ? TextFormat("5")
                                    : TextFormat("%ld", ο[t]);
    float fontSize = 20, spacing = 0;
    Vector2 textsize = MeasureTextEx(font, txt, fontSize, spacing);
    if (textsize.x < 20)
      textsize.x = 20;

    Rectangle rect = (Rectangle){x, y, textsize.x + 10, CELL_HEIGHT - 5};
    Color bgcolor = opcode == 0 ? GRAY : colors[color_index][0];
    DrawRectangleRounded(rect, 0.2f, 10, bgcolor);
    if (selected)
      DrawRectangleRoundedLinesEx(rect, 0.2f, 10, 5, oan_colors[ν][0]);
    DrawTextEx(font, txt, (Vector2){x + 3, y - 3}, fontSize, spacing,
               colors[color_index][1]);
    if (raw)
      DrawTextEx(font, TextFormat("%ld", t), (Vector2){x + 3, y + 12},
                 fontSize / 1.5f, spacing, colors[color_index][1]);
    long this_cell_width = textsize.x + 15;
    if (ο[t] == 0)
      y += CELL_HEIGHT,
          (text_width = text_width < (x + this_cell_width) ? x + this_cell_width
                                                           : text_width),
          x = 0, t = ((t >> Σ) + 1) << Σ;
    else
      x += this_cell_width, t += 11;
  }
  long text_height = y;
  if (auto_center) {
    off.x = GetScreenWidth() / 2.f - text_width * zoom / 2.f;
    off.y = GetScreenHeight() / 2.f - text_height * zoom / 2.f;
  }
  EndMode2D();
  if (full_duplex)
    drawEightStacks(ο, β, α, ρ, δ);
  else {
    if (bside)
      δ = -δ;
    if (δ == +1)
      drawStacks(ο, β, ρ, δ);
    else
      drawStacks(ο, α, ρ, δ);
  }
  if (going_to)
    DrawGoToTable();

  EndDrawing();
}
extern void exit(int __status) __THROW __attribute__((__noreturn__));
static const char *backgroundImages[] = {
    "background_2000.png", "background_2048.png", "background_2049.png"};
static long texture_index = 0;
static Texture2D textures[sizeof(backgroundImages) / sizeof(*backgroundImages)];
static void ti_debug(long *ο, long **β, long **α, long τ, long σ, long ρ,
                     long δ, long ν) {
  ο[τ - 1] = ρ;
  ο[τ - 2] = δ;
  long key;
  static int semi_auto = 0;
  do {
    if (!auto_center && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
      off = Vector2Add(off, GetMouseDelta());
    int wheelMove = GetMouseWheelMove();
    if (wheelMove > 0)
      zoom += 0.1;
    else if (wheelMove < 0)
      zoom -= 0.1;
    key = GetCharPressed();
    drawVMState(ο, β, α, τ, σ, ρ, δ, ν);

    if (WindowShouldClose())
      CloseWindow(), exit(0);

    if (key == '`')
      texture_index =
          (texture_index + 1) % (sizeof(textures) / sizeof(*textures));

    else if (key == 'g')
      going_to = 1;
    else if (going_to && key < (sizeof(stops) / sizeof(*stops)) && stops[key])
      going_to = 0, skip_until = stops[key];
    else if (skip_until == ο[τ])
      skip_until = -1;
    else if (going_to && key)
      going_to = 0;

    else if (key == 'n')
      skip_this_word = τ;
    else if (skip_this_word && skip_this_word != τ)
      skip_this_word = 0;

    else if (key == 'f')
      full_duplex = !full_duplex;
    else if (key == 'a')
      auto_center = !auto_center;
    else if (key == 'b')
      bside = !bside;
    else if (key == 'r')
      raw = !raw;
    else if (key == 'c' && skip_until != -1)
      skip_until = -1;
    else if (key == 'c')
      semi_auto = !semi_auto;
    else if (key == '=')
      opacity += 10;
    else if (key == '-')
      opacity -= 10;
  } while (key != 's' && semi_auto == 0 && skip_until == -1 &&
           skip_this_word == 0);
}
void ti_init(void) {
  SetTraceLogLevel(LOG_ERROR);
  SetConfigFlags(FLAG_WINDOW_RESIZABLE); 
  InitWindow(0, 0, "Sophisticated text index");
  SetWindowSize(GetScreenWidth(), GetScreenHeight());
  SetWindowPosition(0, 0);
  SetTargetFPS(0);
  font = LoadFontEx("NovaMono-Regular.ttf", 135, 0, 0);
}
void sdb(long *ο, long **β, long **α, long **ω, long τ, long σ, long ρ, long δ,
         long ν) {
#ifndef NDEBUG
  //  printf("%5s %7s %ld \n", rays[6 + ν], rays[(ρ + 1) * δ + 5], ο[τ]);
  ti_debug(ο, β, α, τ, σ, ρ, δ, ν);
#endif
}
static const Color oan_colors[][2] = {
    {(Color){000, 000, 255, 255}, WHITE}, // Blue
    {(Color){000, 255, 000, 255}, WHITE}, // Green
    {(Color){255, 000, 000, 255}, WHITE}, // Red
};
static const Color colors[][2] = {
    {(Color){255, 000, 255, 255}, BLACK}, // Fuchsia
    {(Color){128, 000, 000, 255}, WHITE}, // Maroon
    {(Color){128, 128, 000, 255}, WHITE}, // Olive
    {(Color){000, 255, 000, 255}, BLACK}, // Lime
    {(Color){000, 000, 128, 255}, WHITE}, // Navy
    {(Color){255, 255, 255, 255}, BLACK}, // White
    {(Color){000, 000, 255, 255}, WHITE}, // Blue
    {(Color){000, 128, 000, 255}, WHITE}, // Green
    {(Color){255, 255, 000, 255}, BLACK}, // Yellow
    {(Color){255, 000, 000, 255}, WHITE}, // Red
    {(Color){128, 000, 128, 255}, WHITE}, // Purple
};
const char *rays[] = {"Fuchsia", "Maroon", "Olive",  "Lime", "Navy",  "White",
                      "Blue",    "Green",  "Yellow", "Red",  "Purple"};
static int stops[127] = {
    ['b'] = 1,
    ['a'] = 2,
    ['t'] = 3,
    ['o'] = 4,
    ['s'] = 5,
};
static void DrawGoToTable() {
  long top = 0;
  const long font_size = 35;
  for (long i = 0; i < sizeof(stops) / sizeof(*stops); i++) {
    if (stops[i] == 0)
      continue;
    Rectangle rect = {0, top, 6 * font_size, font_size + 5};
    DrawRectangleRounded(rect, 0.1f, 10, WHITE);
    DrawTextEx(font, TextFormat("%c - %ld", i, stops[i]),
               (Vector2){rect.x + 10, rect.y}, font_size, 0, BLACK);
    top += font_size + 5;
  }
}
static void LoadBackgroundImage();
static void DrawBackGround() {
  if (textures[texture_index].id == 0)
    LoadBackgroundImage();
  Rectangle sourceRect = {0.0f, 0.0f, (float)textures[texture_index].width,
                          (float)textures[texture_index].height};
  Rectangle destRect = {0.0f, 0.0f, GetScreenWidth(), GetScreenHeight()};
  Vector2 origin = {0.0f, 0.0f};
  DrawTexturePro(textures[texture_index], sourceRect, destRect, origin, 0.0f,
                 WHITE);
  DrawRectangleRec(destRect, (Color){.a = opacity});
}
static void LoadBackgroundImage() {
  Image image = LoadImage(backgroundImages[texture_index]);
  if (image.data == 0) {
    printf("Failed to load image!\n");
    return exit(0); // Exit with an error code
  }
  textures[texture_index] = LoadTextureFromImage(image);
  UnloadImage(image);
}
int isValidLenghtCString(const char *str, long lenght) {
  int i = 0;
  if (str == 0)
    return false;
  while (str[i] != '\0') {
    if (lenght < i || str[i] < ' ' || '~' < str[i])
      return false;
    i++;
  }
  return true;
}
#include <stdio.h>
static const char **stringify_ray(long *ray) {
  static char b[10][100];
  static const char *lables[10] = {};
  lables[0] = (char *)ray[-3];
  for (long i = 1; i < ray[-2]; i++)
    lables[i] = ray[i] < 0x100000 ? (snprintf(b[i], 100, "%ld", ray[i]), b[i])
                : isValidLenghtCString(ray[i], 99)
                    ? (snprintf(b[i], 100, "%s", (char *)ray[i]), b[i])
                    : "*";
  return lables;
}
