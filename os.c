// clang-format off
#define White(op)   i op 1
#define Black(op)   i op -1
#define Yellow(op)  r op 3
#define Red(op)     r op 2
#define Green(op)   r op 1
#define Blue(op)    r op 0

#define Ta(nar, var)  0, 0, 0, 0, 0, 0, 0, 0, nar, \
                      0, 0, 0, 0, 0, 0, 0, (void*)var,
#define T(nar)        0, 0, 0, 0, 0, 0, 0, 0, nar, \
                      0, 0, 0, 0, 0, 0, 0, #nar,
#define AW 8
#define R +(long)
#define L -(long)
#define B(...)                                                                 \
  (({                                                                          \
     void *text[] = {__VA_ARGS__};                                             \
     long i = sizeof(text) / sizeof(void *);                                   \
     while (i)                                                                 \
       o[--a] = text[--i];                                                     \
   }),                                                                         \
   o + a + AW)
#define O(tari) void tari(void**o, void **t, long a, long r, long i, long s)
#define N(argo, ...) O(argo) { if (Green(==) && Black(==)) __VA_ARGS__; else M(r); }
#define V(asil, ...) O(asil) { if (Green(==) && White(==)) __VA_ARGS__; else M(r); }
#define M(r) m(o, t, a, r, i, s)
// clang-format on
typedef O((*t_t));
#include <raylib.h>
static Vector2 pos = {100, 450};
static Vector2 dir = {1, 0};
static void rotate() {
  int x = dir.x;
  dir.x = dir.y;
  dir.y = x * -1;
}
static O(m) {
  pos.x += 31 * dir.x * i;
  pos.y += 41 * dir.y * i;
  ((t_t *)t)[i * (2 * AW + 1)](o, t + i * (2 * AW + 1), a, r, i, s);
}
static O(b) {
  if (Green(==))
    m(o, t, a, r, White(=), s);
  else
    m(o, t[L 1], a, r, (long)t[R 1], s);
}
O(toti_heart) {
  if (White(==)) {
    if (Green(==)) {
      m(o, t, a, r, Black(=), s);
    } else {
      long arm_index = (long)t[+AW];
      void **left_arm = t[-arm_index];
      m(o, left_arm, a, (Green(==)) ? Yellow(=) : r, i, s);
    }
  } else if (Green(==)) {
    m(o, t, a, r, White(=), s);
  } else {
    long arm_count = (long)t[-AW];
    long arm_index = (long)t[+AW];
    t[+AW] = (void *)(1 + arm_index % arm_count);
    void **right_arm = t[+arm_index];
    m(o, right_arm, a, r, White(=), s);
  }
}
O(toti) {
  long arm_index = 1;
  for (; arm_index <= AW && t[arm_index]; arm_index++) {
    void **left_arm = t[-arm_index];
    left_arm[-1] = t, left_arm[+1] = (void *)1;
    void **right_arm = t[+arm_index];
    right_arm[-1] = t, right_arm[+1] = (void *)-1;
  }
  t[+AW] = (void *)1;
  t[-AW] = (void *)(arm_index - 1);
  *t = toti_heart;
  toti_heart(o, t, a, r, i, s);
}
static O(dot) {
  m(o, t, a, Yellow(==) ? Green(=) : Green(==) ? Yellow(=) : r, Black(=), s);
}
#include <stdio.h>
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
      t[R 1] = (void *)key;
    if (t[R 1]) {
      o[s++] = t[R 1];
      M(Green(=));
    } else
      M(Blue(=));
  }))
V(write_char,
  DrawTextEx(font, TextFormat("%ld", o[--s]), (Vector2){100, 100}, 45, 4,
             WHITE),
  M(r))
O(not );
O(and);
O(orand);
O(or);
O(left) {
  DrawText("left", 0, 0, 45, YELLOW);
  M(r);
}
O(right) {
  DrawText("right", 0, 0, 45, RED);
  M(r);
}
O(us) {
  t[-1] = B(T(b) T(left) T(dot)), t[+1] = B(T(b) T(right) T(dot));
  toti(o, t, a, r, i, s);
}
int main() {
  void *o[1024];
  long a = 1024;
  void **t = B(T(b)                                                   //
               T(begindrawing) T(fps)                                 //
               T(and) T(getcharpressed) T(write_char) T(us)           //
               T(orand) T(shouldclose) T(the_end) T(or) T(enddrawing) //
               T(dot));
  long r, i, s = 0;
  t[L 1] = t;
  t[R 1] = (void *)1;
  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(0);
  InitWindow(1500, 900, "aword os");
  font = LoadFont("NovaMono-Regular.ttf");
  m(o, t, a, Yellow(=), White(=), s);
  CloseWindow();
  return 0;
}
O(not ) {
  if (White(==)) {
    if (Yellow(==))
      Green(=), Black(=);
    else if (Green(==))
      Yellow(=), Black(=);
    else if (Red(==))
      Yellow(=);
  } else if (Green(==))
    White(=);
  M(r);
}
O(and) {
  if (White(==)) {
    if (Yellow(==))
      Green(=), Black(=);
    else if (Green(==))
      Yellow(=);
  } else if (Green(==))
    White(=);
  M(r);
}
O(orand) {
  if (White(==)) {
    if (Yellow(==))
      Green(=), Black(=);
    else if (Green(==))
      Yellow(=);
    else if (Blue(==))
      Yellow(=);
  } else if (Green(==))
    White(=);
  M(r);
}
O(or) {
  if (White(==)) {
    if (Yellow(==))
      Green(=), Black(=);
    else if (Green(==))
      Yellow(=), Black(=);
    else if (Blue(==))
      Yellow(=);
  } else if (Green(==))
    White(=);
  M(r);
}
