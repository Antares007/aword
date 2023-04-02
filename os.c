// clang-format off
#define Ta(nar, val) 0, nar, (void *)val,
#define T(nar) 0, nar, 0,
#define B(...) ((void *[]){__VA_ARGS__})
#define O(tari) void tari(void**o, void **t, long a, long r, long i)
#define N(argo, ...) O(argo) { if (r == 1 && i == -1) __VA_ARGS__; else M(r); }
#define V(asil, ...) O(asil) { if (r == 1 && i ==  1) __VA_ARGS__; else M(r); }
#define R(t) m(o, t - 2, a, 3, 1)
#define M(r) m(o, t, a, r, i)
typedef O((*t_t));
static O(m) { ((t_t*)t)[i * 3](o, t + i * 3, a, r, i); }
static O(b) { m(o, t, a, r, 1); }
static O(dot) { m(o, t, a, r == 3 ? 1 : r == 1 ? 3 : r, -1); }
static O(jump) { m(o, t + (long)t[1] * 3 * i, a, r, i); }
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
N(getcharpressed, ({
    long key = GetCharPressed();
    if (key)
      t[1] = (void *)key;
    if (t[1]) {
      o[a++] = t[1];
      M(1);
    } else
      M(0);
  }))
V(write_char,
  DrawTextEx(font, TextFormat("%ld", o[--a]), (Vector2){100, 100}, 45, 4,
             WHITE),
  M(r))
O(not );
O(and);
O(orand);
O(or);
int main() {
  void *o[64];
  long a = 0;
  R(B(T(init) Ta(jump, 1)                    //
      T(b)                                   //
      T(begindrawing)                        //
      T(fps)                                 //
      T(and) T(getcharpressed) T(write_char) //
      T(orand) T(shouldclose) T(the_end) T(or) T(enddrawing) T(dot)));
  return 0;
}
// clang-format off
O(not) {
  if (i == 1) {
    if (r == 3) r = 1, i = -1;
    else if (r == 2) r = 3;
    else if (r == 1) r = 3, i = -1;
  } else if (r != 3) i = 1;
  M(r);
}
O(and) {
  if (i == 1) {
    if (r == 3) r = 1, i = -1, t[1] = (void*)a;
    else if (r == 0) a = (long)t[1];
    else if (r == 1) r = 3;
  } else if (r != 3) i = 1;
  M(r);
}
O(orand) {
  if (i == 1) {
    if (r == 3) r = 1, i = -1, t[1] = (void*)a;
    else if (r == 0) a = (long)t[1], r = 3;
    else if (r == 1) r = 3;
  } else if (r != 3) i = 1;
  M(r);
}
O(or) {
  if (i == 1) {
    if (r == 3) r = 1, i = -1, t[1] = (void*)a;
    else if (r == 0) a = (long)t[1], r = 3;
    else if (r == 1) r = 3, i = -1;
  } else if (r != 3) i = 1;
  M(r);
}
