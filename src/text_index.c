#include "aword.h"
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>
// clang-format off
#include <assert.h>
static void stop        (aword) {
}
static void move        (aword) {
  getchar();
  ((void (**)(long, long, void *, long, long))o)[w + d](a, w + d, o, r, d);
}
void text_index(aword) {
  (o-512)[w+1] = (void*)r, (o-512)[w] = move, (o-512)[w-1] = (void*)d;
  if (Yellow(!=) || Black(!=)) {
    BeginDrawing();
    ClearBackground(BLACK);
    o[w] = stop,
    move(a, w, o-512, r, d, s);
    o[w] = move,
    EndDrawing();
  }
  ((void (**)(long, long, void *, long, long))
  o)[w + d](a, w + d, o, r, d);
}

void text_index_init() {
  SetTraceLogLevel(LOG_WARNING);
  InitWindow(800, 600, "actionable word show");
  SetTargetFPS(0);
}
// static Color colors[] = {
//     (Color){.a = 0xFF, .b = 0x00, .g = 0x77, .r = 0x77}, // DarkYellow
//     (Color){.a = 0xFF, .b = 0x00, .g = 0x00, .r = 0x77}, // DarkRed
//     (Color){.a = 0xFF, .b = 0x00, .g = 0x77, .r = 0x00}, // DarkGreen
//     (Color){.a = 0xFF, .b = 0x77, .g = 0x00, .r = 0x00}, // DarkBlue
//     (Color){.a = 0xFF, .b = 0x00, .g = 0x00, .r = 0x00}, // Black
//     (Color){.a = 0xFF, .b = 0xFF, .g = 0x00, .r = 0x00}, // Blue
//     (Color){.a = 0xFF, .b = 0x00, .g = 0xFF, .r = 0x00}, // Green
//     (Color){.a = 0xFF, .b = 0x00, .g = 0x00, .r = 0xFF}, // Red
//     (Color){.a = 0xFF, .b = 0x00, .g = 0xFF, .r = 0xFF}, // Yellow
// };
//int key = GetCharPressed();
//while (key != 'n' && Yellow(!=) || Black(!=)) {
//  key = GetCharPressed();
//  if (key == 's') return;
//}
