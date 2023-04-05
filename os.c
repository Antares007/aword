// #define bWords

#include "awords.h"
#include <assert.h>
#include <raylib.h>
#include <stdio.h>
#include <unistd.h>
N(m) {
  ω.tin = OP(ω, +, (AW + 1 + AW) * δ.dir);
  ο[ω.tin].go(α, ω, ο, ρ, δ, σ);
}
N(go_White_Yellow) /**/ { m(α, ω, ο, Yellow, /**/ White, σ); }
N(go_White_Red) /*   */ { m(α, ω, ο, Red, /*   */ White, σ); }
N(go_White_Green) /* */ { m(α, ω, ο, Green, /* */ White, σ); }
N(go_White_Blue) /*  */ { m(α, ω, ο, Blue, /*  */ White, σ); }
N(go_Black_Blue) /*  */ { m(α, ω, ο, Blue, /*  */ Black, σ); };
N(go_Black_Green) /* */ { m(α, ω, ο, Green, /* */ Black, σ); };
N(go_Black_Red) /*   */ { m(α, ω, ο, Red, /*   */ Black, σ); };
N(go_Black_Yellow) /**/ { m(α, ω, ο, Yellow, /**/ Black, σ); };
N(aradani_heart) { ο[OP(ω, +, (1 + ρ.ray) * δ.dir)].go(α, ω, ο, ρ, δ, σ); }
N(b) { m(α, ω, ο, ρ, White, σ); }
N(o) {
  ο[OP(ω, +, +1 + 3 /* White Yellow */)].v = go_Black_Green;
  ο[OP(ω, +, +1 + 2 /* White Red    */)].v = go_Black_Red;
  ο[OP(ω, +, +1 + 1 /* White Green  */)].v = go_Black_Yellow;
  ο[OP(ω, +, +1 + 0 /* White Blue   */)].v = go_Black_Blue;
  ο[ω.tin].v = aradani_heart;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}
#define P(ω, n) ο[OP(ω, +, AW - n)]

N(toti_arm_go_White_w) {
  tin_v Tw = P(ω, 0).w;
  tin_v next_w = P(ω, 1).w;
  P(Tw, 2).w = next_w;
  m(α, Tw, ο, ρ, White, σ);
}
N(toti_arm_go_Black_w) {
  tin_v Tw = P(ω, 0).w;
  P(Tw, 2).w = P(Tw, 3).w;
  m(α, Tw, ο, ρ, δ, σ);
}
N(toti_arm_go_Nxt_arm) { m(α, P(ω, 0).w, ο, ρ, White, σ); }
N(toti_heart) { m(α, P(ω, 2).w, ο, ρ, White, σ); }
N(toti) {
  nar_t **arms = P(ω, 0).v;
  long c = P(ω, 1).q;
#define WriteArm                                                               \
  c--;                                                                         \
  while (*arms[c] != o)                                                        \
    T(*arms[c]), arms[c]++;                                                    \
  T(*arms[c]);
  tin_v r, l;
  T(toti_arm_go_Black_w, l.tin =), P(l, 0).w = ω;
  WriteArm;
  T(toti_arm_go_White_w, r.tin =), P(r, 0).w = ω, P(r, 1).w = l;
  WriteArm;
  while (c) {
    T(toti_arm_go_Nxt_arm, l.tin =), P(l, 0).w = r;
    WriteArm;
    T(toti_arm_go_White_w, r.tin =), P(r, 0).w = ω, P(r, 1).w = l;
    WriteArm;
  }
  P(ω, 2).w = r;
  P(ω, 3).w = r;
  ο[ω.tin].v = toti_heart;
  toti_heart(α, ω, ο, ρ, δ, σ);
#undef WriteArm
}
N(id1) {
  printf("id1\n");
  m(α, ω, ο, ρ, δ, σ);
}
N(id2) {
  printf("id2\n");
  m(α, ω, ο, ρ, δ, σ);
}
N(us) {
  nar_t *arms[] = {(nar_t[]){id1, o}, (nar_t[]){id2, o}};
  P(ω, 0).v = arms;
  P(ω, 1).q = sizeof(arms) / sizeof(*arms);
  toti(α, ω, ο, ρ, δ, σ);
}

N(not ) {
  ο[OP(ω, +, +1 + 3 /* White Yellow */)].v = go_Black_Green;
  ο[OP(ω, +, +1 + 2 /* White Red    */)].v = go_White_Yellow;
  ο[OP(ω, +, +1 + 1 /* White Green  */)].v = go_Black_Yellow;
  ο[OP(ω, +, +1 + 0 /* White Blue   */)].v = go_White_Blue;
  ο[ω.tin].v = aradani_heart;
  ο[OP(ω, +, -1 - 0 /* Black Blue   */)].v = go_Black_Blue;
  ο[OP(ω, +, -1 - 1 /* Black Green  */)].v = go_White_Green;
  ο[OP(ω, +, -1 - 2 /* Black Red    */)].v = go_Black_Red;
  ο[OP(ω, +, -1 - 3 /* Black Yellow */)].v = go_Black_Yellow;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}
N(and) {
  ο[OP(ω, +, +1 + 3 /* White Yellow */)].v = go_Black_Green;
  ο[OP(ω, +, +1 + 2 /* White Red    */)].v = go_White_Red;
  ο[OP(ω, +, +1 + 1 /* White Green  */)].v = go_White_Yellow;
  ο[OP(ω, +, +1 + 0 /* White Blue   */)].v = go_White_Blue;
  ο[ω.tin].v = aradani_heart;
  ο[OP(ω, +, -1 - 0 /* Black Blue   */)].v = go_Black_Blue;
  ο[OP(ω, +, -1 - 1 /* Black Green  */)].v = go_White_Green;
  ο[OP(ω, +, -1 - 2 /* Black Red    */)].v = go_Black_Red;
  ο[OP(ω, +, -1 - 3 /* Black Yellow */)].v = go_Black_Yellow;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}
N(or) {
  ο[OP(ω, +, +1 + 3 /* White Yellow */)].v = go_Black_Green;
  ο[OP(ω, +, +1 + 2 /* White Red    */)].v = go_White_Red;
  ο[OP(ω, +, +1 + 1 /* White Green  */)].v = go_Black_Yellow;
  ο[OP(ω, +, +1 + 0 /* White Blue   */)].v = go_White_Yellow;
  ο[ω.tin].v = aradani_heart;
  ο[OP(ω, +, -1 - 0 /* Black Blue   */)].v = go_Black_Blue;
  ο[OP(ω, +, -1 - 1 /* Black Green  */)].v = go_White_Green;
  ο[OP(ω, +, -1 - 2 /* Black Red    */)].v = go_Black_Red;
  ο[OP(ω, +, -1 - 3 /* Black Yellow */)].v = go_Black_Yellow;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}
N(orand) {
  ο[OP(ω, +, +1 + 3 /* White Yellow */)].v = go_Black_Green;
  ο[OP(ω, +, +1 + 2 /* White Red    */)].v = go_White_Red;
  ο[OP(ω, +, +1 + 1 /* White Green  */)].v = go_White_Yellow;
  ο[OP(ω, +, +1 + 0 /* White Blue   */)].v = go_White_Yellow;
  ο[ω.tin].v = aradani_heart;
  ο[OP(ω, +, -1 - 0 /* Black Blue   */)].v = go_Black_Blue;
  ο[OP(ω, +, -1 - 1 /* Black Green  */)].v = go_White_Green;
  ο[OP(ω, +, -1 - 2 /* Black Red    */)].v = go_Black_Red;
  ο[OP(ω, +, -1 - 3 /* Black Yellow */)].v = go_Black_Yellow;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}

static Font font;
N(begindrawing) {
  if (ρ.ray == Green.ray && δ.dir == White.dir)
    BeginDrawing(), ClearBackground(BLACK);
  m(α, ω, ο, ρ, δ, σ);
};
N(enddrawing) {
  if (ρ.ray == Green.ray && δ.dir == White.dir)
    EndDrawing();
  m(α, ω, ο, ρ, δ, σ);
};
N(the_end) {
  if (ρ.ray != Green.ray || δ.dir != White.dir)
    m(α, ω, ο, ρ, δ, σ);
}
N(fps) {
  if (ρ.ray == Green.ray && δ.dir == White.dir)
    DrawTextEx(font, TextFormat("%d", GetFPS()), (Vector2){0, 0}, 25, 4, WHITE);
  m(α, ω, ο, ρ, δ, σ);
}
N(shouldclose) {
  if (ρ.ray == Green.ray && δ.dir == White.dir)
    m(α, ω, ο, (ray_v){!!WindowShouldClose()}, δ, σ);
  else
    m(α, ω, ο, ρ, δ, σ);
}
N(getcharpressed) {
  if (ρ.ray == Green.ray && δ.dir == White.dir) {
    long key = GetCharPressed();
    if (key)
      ο[OP(ω, +, 1)].q = key;
    if (ο[OP(ω, +, 1)].q) {
      ο[Push(σ)] = ο[OP(ω, +, 1)];
      m(α, ω, ο, Green, δ, σ);
    } else
      m(α, ω, ο, Blue, δ, σ);
  } else
    m(α, ω, ο, ρ, δ, σ);
}
N(write_char) {
  if (ρ.ray == Green.ray && δ.dir == White.dir)
    DrawTextEx(font, TextFormat("%ld", ο[Pull(σ)]), (Vector2){200, 100}, 45, 4,
               WHITE);
  m(α, ω, ο, ρ, δ, σ);
}
N(left) {
  DrawText("left", 200, 0, 45, YELLOW);
  m(α, ω, ο, ρ, δ, σ);
}
N(right) {
  DrawText("right", 400, 0, 45, RED);
  m(α, ω, ο, ρ, δ, σ);
}
N(print) {
  DrawText("heyy", 200, 200, 45, RED);
  m(α, ω, ο, ρ, δ, σ);
}
int main() {
  tin_v α = {1024}, ω;
  txt_t β[α.tin + 1 + α.tin];
  txt_t *ο = β + α.tin;
  // α.tin = 0 - α.tin;
  ray_v ρ = Yellow;
  dir_v δ = White;
  tin_v σ = {0};
  T(b, ω.tin =);
  T(begindrawing);
  T(fps), T(print);
  T(and), T(us);
  T(orand), T(shouldclose), T(the_end), T(or), T(enddrawing);
  T(o);
  assert(ο[OP(ω, +, 0)].v == b);
  assert(ο[OP(ω, +, 17)].v == begindrawing);

  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(60);
  InitWindow(1500, 900, "aword os");
  font = LoadFont("NovaMono-Regular.ttf");
  m(α, ω, ο, ρ, δ, σ);
  CloseWindow();
  return 0;
}
