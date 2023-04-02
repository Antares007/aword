// clang-format off
#define Ta(nar, a) 0, nar, (void *)a,
#define T(nar) 0, nar, 0,
#define B(...) ((void *[]){__VA_ARGS__} - 2)
#define O(tari) void tari(void **t, long r, long i)
#define N(argo, ...) O(argo) { if (r == 1 && i == -1) __VA_ARGS__;else m(t, r, i); }
#define V(asil, ...) O(asil) { if (r == 1 && i ==  1) __VA_ARGS__;else m(t, r, i); }
typedef O((*t_t));
static O(m) { ((t_t*)t)[i * 3](t + i * 3, r, i); }
static O(b) { m(t, r, 1); }
static O(o) { m(t, r == 3 ? 1 : r == 1 ? 3 : r, -1); }
static O(jump) { m(t + (long)t[1] * 3 * i, r, i); }
// clang-format on

#include <raylib.h>
#include <stdio.h>
#define P printf("%ld %2ld %s\n", r, i, __FUNCTION__)
static Font font;

V(begindrawing, BeginDrawing(), ClearBackground(BLACK), m(t, r, i));
V(enddrawing, EndDrawing(), m(t, r, i));
O(init) {
  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(0);
  InitWindow(1500, 900, "aword os");
  font = LoadFont("NovaMono-Regular.ttf");
  m(t, r, i);
}
V(the_end, CloseWindow())
V(fps,
  DrawTextEx(font, TextFormat("%d", GetFPS()), (Vector2){0, 0}, 25, 4, WHITE),
  m(t, r, i))
V(shouldclose, m(t, !!WindowShouldClose(), i))
V(getcharpressed, m(t, 0, i))
V(write_char, m(t, r, i))
O(not );
O(and);
O(orand);
O(or);
int main() {
  m(B(T(init) Ta(jump, 1)                    //
      T(b)                                   //
      T(begindrawing)                        //
      T(fps)                                 //
      T(and) T(getcharpressed) T(write_char) //
      T(orand) T(shouldclose) T(the_end) T(or) T(enddrawing) T(o)),
    3, 1);
  return 0;
}
// clang-format off
O(not) {
  if (i == 1) {
    if (r == 2) r = 3;
    else if (r == 3) r = 1, i = -1;
    else if (r == 1) r = 3, i = -1;
  } else if (r == 1) i = 1;
  m(t, r, i);
}
O(and) {
  if (i == 1) {
    if (r == 3) r = 1, i = -1;
    else if (r == 1) r = 3;
  } else if (r == 1) i = 1;
  m(t, r, i);
}
O(orand) {
  if (i == 1) {
    if (r == 0) r = 3;
    else if (r == 1) r = 3;
    else if (r == 3) r = 1, i = -1;
  } else if (r == 1) i = 1;
  m(t, r, i);
}
O(or) {
  if (i == 1) {
    if (r == 0) r = 3;
    else if (r == 3) r = 1, i = -1;
    else if (r == 1) r = 3, i = -1;
  } else if (r == 1) i = 1;
  m(t, r, i);
}
