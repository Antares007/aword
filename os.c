// clang-format off
#define T(nar) 0, 0, 0, 0, 0, 0, 0, 0, nar, \
               0, 0, 0, 0, 0, 0, 0, 0,
#define TAW 8 // T arm width
#define B(...) ((void *[]){__VA_ARGS__} + TAW)
#define O(tari) void tari(void**o, void **t, long a, long r, long i)
#define N(argo, ...) O(argo) { if (r == 1 && i == -1) __VA_ARGS__; else M(r); }
#define V(asil, ...) O(asil) { if (r == 1 && i ==  1) __VA_ARGS__; else M(r); }
#define M(r) m(o, t, a, r, i)
typedef O((*t_t));
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>
#define P printf("%ld %2ld %s\n", r, i, __FUNCTION__), usleep(100000)
static O(m) { ((t_t*)t)[i * (2*TAW+1)](o, t + i * (2*TAW+1), a, r, i); }
static O(dot) { m(o, t, a, r == 3 ? 1 : r == 1 ? 3 : r, -1); }
// clang-format on

static Font font;

V(begindrawing, BeginDrawing(), ClearBackground(BLACK), M(r));
V(enddrawing, EndDrawing(), M(r));
V(the_end, ({ return; }))
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
// clang-format off
static O(b) {
  if (r == 1) m(o, t, a, r, 1);
  else        m(o, t[-1], a, r, (long)t[1]);
}
O(toti_heart) {
  if (i == 1) {
    if (r == 3)       m(o, t, a, 1, -1);
    else              m(o, t[(long)t[TAW]], a, (r == 1) ? r = 3 : r, 1);
  } else if (r == 1)  m(o, t, a, r, 1);
  else {
    long arm_index = (long)t[TAW];
    t[TAW] = (void*)(1 + (((long)t[TAW]) % (long)t[-TAW]));
    m(o, t[-arm_index], a, r, 1);
  }
}
O(toti) {
  long arm_index = 1;
  for(; arm_index <= TAW && t[arm_index]; arm_index++) {
    void **R = t[+arm_index];
    R[-1] = t, R[+1] = (void *)+1;
    void **L = t[-arm_index];
    L[-1] = t, L[+1] = (void *)-1;
  }
  t[+TAW] = (void*)1;
  t[-TAW] = (void*)(arm_index - 1);
  *t = toti_heart;
  toti_heart(o, t, a, r, i);
}
O(left)   { P, M(r); }
O(right)  { P, M(r); }
O(left2)  { P, M(r); }
O(right2) { P, M(r); }
O(us) {
  t[-1] = B(T(b) T(left) T(dot));
  t[+1] = B(T(b) T(right) T(dot));
  t[-2] = B(T(b) T(left2) T(dot));
  t[+2] = B(T(b) T(right2) T(dot));
  toti(o, t, a, r, i);
}
int main() {
  void *o[64];
  long a = 0;
  void **t = B(T(b)                                   //
               T(begindrawing)                        //
               T(fps)                                 //
               T(us)                                  //
               T(and) T(getcharpressed) T(write_char) //
               T(orand) T(shouldclose) T(the_end) T(or) T(enddrawing) T(dot));
  t[-1] = t;
  t[ 1] = (void *)1;

  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(0);
  InitWindow(1500, 900, "aword os");
  font = LoadFont("NovaMono-Regular.ttf");
  m(o, t, a, 3, 1);
  CloseWindow();
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
