// clang-format off
#define Ta(nar, a) 0, nar, (void *)a,
#define T(nar) 0, nar, 0,
#define B(...) ((void *[]){__VA_ARGS__})
#define O(tari) void tari(void **t, long r, long i)
#define N(argo, ...) O(argo) { if (r == 1 && i == -1) __VA_ARGS__;else M(r); }
#define V(asil, ...) O(asil) { if (r == 1 && i ==  1) __VA_ARGS__;else M(r); }
#define R(t) m(t - 2, 3, 1)
#define M(r) m(t, r, i)
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

V(begindrawing, BeginDrawing(), ClearBackground(BLACK), M(r));
V(enddrawing, EndDrawing(), M(r));
O(init) {
  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(0);
  InitWindow(1500, 900, "aword os");
  font = LoadFont("NovaMono-Regular.ttf");
  M(r);
}
V(the_end, CloseWindow())
V(fps,
  DrawTextEx(font, TextFormat("%d", GetFPS()), (Vector2){0, 0}, 25, 4, WHITE),
  M(r))
V(shouldclose, M(!!WindowShouldClose()))
V(getcharpressed, ({
    int key = GetCharPressed();
    M(0);
  }))
V(write_char, M(r))
O(not );
O(and);
O(orand);
O(or);
int main() {
  R(B(T(init) Ta(jump, 1)                    //
      T(b)                                   //
      T(begindrawing)                        //
      T(fps)                                 //
      T(and) T(getcharpressed) T(write_char) //
      T(orand) T(shouldclose) T(the_end) T(or) T(enddrawing) T(o)));
  return 0;
}
// clang-format off
O(not) {
  if (i == 1) {
    if (r == 2) r = 3;
    else if (r == 3) r = 1, i = -1;
    else if (r == 1) r = 3, i = -1;
  } else if (r == 1) i = 1;
  M(r);
}
O(and) {
  if (i == 1) {
    if (r == 3) r = 1, i = -1;
    else if (r == 1) r = 3;
  } else if (r == 1) i = 1;
  M(r);
}
O(orand) {
  if (i == 1) {
    if (r == 0) r = 3;
    else if (r == 1) r = 3;
    else if (r == 3) r = 1, i = -1;
  } else if (r == 1) i = 1;
  M(r);
}
O(or) {
  if (i == 1) {
    if (r == 0) r = 3;
    else if (r == 3) r = 1, i = -1;
    else if (r == 1) r = 3, i = -1;
  } else if (r == 1) i = 1;
  M(r);
}
