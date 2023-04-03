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
#define B(...)                                                                 \
  (({                                                                          \
     void *text[] = {__VA_ARGS__};                                             \
     long i = sizeof(text) / sizeof(void *);                                   \
     while (i)                                                                 \
       o[--a] = text[--i];                                                     \
   }),                                                                         \
   o + a + AW)
#define N(tari) void tari(void**o, void **t, long a, long r, long i, long s)
#define M(r) m(o, t, a, r, i, s)
// clang-format on
typedef N((*t_t));
static N(m) {
  ((t_t *)t)[i * (2 * AW + 1)](o, t + i * (2 * AW + 1), a, r, i, s);
}
static N(b) {
  if (Green(==))
    m(o, t, a, r, White(=), s);
  else
    m(o, t[-1], a, r, (long)t[+1], s);
}
static N(dot) {
  m(o, t, a, Yellow(==) ? Green(=) : Green(==) ? Yellow(=) : r, Black(=), s);
}
N(toti_heart) {
  if (White(==)) {
    if (Yellow(==)) {
      m(o, t, a, Green(=), Black(=), s);
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
N(toti) {
  long arm_index = 1;
  for (; arm_index < AW && t[arm_index]; arm_index++) {
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
#include <raylib.h>
static Font font;
N(begindrawing) {
  if (Green(==) && White(==))
    BeginDrawing(), ClearBackground(BLACK);
  M(r);
};
N(enddrawing) {
  if (Green(==) && White(==))
    EndDrawing();
  M(r);
};
N(the_end) {
  if (Green(!=) || White(!=))
    M(r);
}
N(fps) {
  if (Green(==) && White(==))
    DrawTextEx(font, TextFormat("%d", GetFPS()), (Vector2){0, 0}, 25, 4, WHITE);
  M(r);
}
N(shouldclose) {
  if (Green(==) && White(==))
    M(!!WindowShouldClose());
  else
    M(r);
}
N(getcharpressed) {
  if (Green(==) && Black(==))
    ({
      long key = GetCharPressed();
      if (key)
        t[+1] = (void *)key;
      if (t[+1]) {
        o[s++] = t[+1];
        M(Green(=));
      } else
        M(Blue(=));
    });
  else
    M(r);
}
N(write_char) {
  if (Green(==) && White(==))
    DrawTextEx(font, TextFormat("%ld", o[--s]), (Vector2){200, 100}, 45, 4,
               WHITE),
        M(r);
  else
    M(r);
}
N(not );
N(and);
N(orand);
N(or);
N(left) {
  DrawText("left", 200, 0, 45, YELLOW);
  M(r);
}
N(right) {
  DrawText("right", 400, 0, 45, RED);
  M(r);
}
N(us) {
  t[-1] = B(T(b) T(left) T(dot)), t[+1] = B(T(b) T(right) T(dot));
  toti(o, t, a, r, i, s);
}
int main() {
  void *o[1024];
  long a = 1024;
  void **t =
      B(T(b) T(begindrawing) T(fps) T(and) T(getcharpressed) T(write_char) T(us)
            T(orand) T(shouldclose) T(the_end) T(or) T(enddrawing) T(dot));
  long r, i, s = 0;
  t[-1] = t;
  t[+1] = (void *)1;
  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(60);
  InitWindow(1500, 900, "aword os");
  font = LoadFont("NovaMono-Regular.ttf");
  m(o, t, a, Yellow(=), White(=), s);
  CloseWindow();
  return 0;
}
N(not ) {
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
N(and) {
  if (White(==)) {
    if (Yellow(==))
      Green(=), Black(=);
    else if (Green(==))
      Yellow(=);
  } else if (Green(==))
    White(=);
  M(r);
}
N(orand) {
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
N(or) {
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
