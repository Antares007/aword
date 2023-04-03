// clang-format off
#define White(op)   i op 1
#define Black(op)   i op -1
#define Yellow(op)  r op 3
#define Red(op)     r op 2
#define Green(op)   r op 1
#define Blue(op)    r op 0

#define Ta(nar, var)  0, 0, 0, 0, 0, 0, 0, 0, nar, \
                      (void*)var, 0, 0, 0, 0, 0, 0, 0,
#define T(nar)        0, 0, 0, 0, 0, 0, 0, 0, nar, \
                      0, 0, 0, 0, 0, 0, 0, 0,
#define AW 8
#define B(...) ((void *[]){__VA_ARGS__} + AW)
//(({}),(void**)0) 
#define O(tari) void tari(void**o, void **t, long a, long r, long i)
#define N(argo, ...) O(argo) { if (Green(==) && Black(==)) __VA_ARGS__; else M(r); }
#define V(asil, ...) O(asil) { if (Green(==) && White(==)) __VA_ARGS__; else M(r); }
#define M(r) m(o, t, a, r, i)
typedef O((*t_t));
static O(m) { ((t_t*)t)[i*(2*AW+1)](o, t+i*(2*AW+1), a, r, i); }
static O(b) {
  if (Green(==)) m(o, t, a, r, White(=));
  else m(o, t[-1], a, r, (long)t[+1]);
}
O(toti_heart) {
  if (White(==)) {
    if (Green(==))
      m(o, t, a, r, Black(=));
    else
      m(o, t[(long)t[AW]], a, (Green(==)) ? Yellow(=) : r, i);
  } else if (Green(==))
    m(o, t, a, r, White(=));
  else {
    long arm_index = (long)t[+AW];
    long arm_count = (long)t[-AW];
    t[+AW] = (void *)(1 + arm_index % arm_count);
    m(o, t[-arm_index], a, r, White(=));
  }
}
O(toti) {
  long arm_index = 1;
  for (; arm_index <= AW && t[+arm_index]; arm_index++) {
    void **R = t[+arm_index];
    R[-1] = t, R[+1] = (void *)+1;
    void **L = t[-arm_index];
    L[-1] = t, L[+1] = (void *)-1;
  }
  t[+AW] = (void *)1;
  t[-AW] = (void *)(arm_index - 1);
  *t = toti_heart;
  toti_heart(o, t, a, r, i);
}
static O(dot) { m(o, t, a, r == 3 ? 1 : r == 1 ? 3 : r, -1); }
#include<raylib.h>
#include<stdio.h>
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
    if (key) t[1] = (void *)key;
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
  void *o[1024];
  long a = 0;
  void **t = B(T(b)
               T(begindrawing)
               T(fps)
               T(and) T(getcharpressed) T(write_char)
               T(orand) T(shouldclose) T(the_end) T(or) T(enddrawing) T(dot));
  t[-1] = t;
  t[1] = (void *)1;
  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(0);
  InitWindow(1500, 900, "aword os");
  font = LoadFont("NovaMono-Regular.ttf");
  m(o, t, a, 3, 1);
  CloseWindow();
  return 0;
}
O(not) {
  if (White(==)) {
    if (Yellow(==)) Green(=), Black(=);
    else if (Green(==)) Yellow(=), Black(=);
    else if (Red(==)) Yellow(=);
  } else if (Green(==)) White(=);
  M(r);
}
O(and) {
  if (White(==)) {
    if (Yellow(==)) Green(=), Black(=);
    else if (Green(==)) Yellow(=);
  } else if (Green(==)) White(=);
  M(r);
}
O(orand) {
  if (White(==)) {
    if (Yellow(==)) Green(=), Black(=);
    else if (Green(==)) Yellow(=);
    else if (Blue(==)) Yellow(=);
  } else if (Green(==)) White(=);
  M(r);
}
O(or) {
  if (White(==)) {
    if (Yellow(==)) Green(=), Black(=);
    else if (Green(==)) Yellow(=), Black(=);
    else if (Blue(==)) Yellow(=);
  } else if (Green(==)) White(=);
  M(r);
}
