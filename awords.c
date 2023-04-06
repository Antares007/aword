#include "awords.h"
N(go) {
  ω.tin = Plus(ω, (1 + 4 + 4) * δ.dir);
  ο[ω.tin].go(α, ω, ο, ρ, δ, σ);
}
N(go_White) { go(α, ω, ο, ρ, (dir_v){+1}, σ); }
N(go_Black) { go(α, ω, ο, ρ, (dir_v){-1}, σ); }
N(go_Yellow) /*    */ { go_White(α, ω, ο, (ray_v){3}, δ, σ); }
N(go_Red) /*       */ { go_White(α, ω, ο, (ray_v){2}, δ, σ); }
N(go_Green) /*     */ { go_White(α, ω, ο, (ray_v){1}, δ, σ); }
N(go_Blue) /*      */ { go_White(α, ω, ο, (ray_v){0}, δ, σ); }
N(go_DarkBlue) /*  */ { go_Black(α, ω, ο, (ray_v){0}, δ, σ); };
N(go_DarkGreen) /* */ { go_Black(α, ω, ο, (ray_v){1}, δ, σ); };
N(go_DarkRed) /*   */ { go_Black(α, ω, ο, (ray_v){2}, δ, σ); };
N(go_DarkYellow) /**/ { go_Black(α, ω, ο, (ray_v){3}, δ, σ); };
N(aradani_heart) { ο[Plus(ω, (1 + ρ.ray) * δ.dir)].go(α, ω, ο, ρ, δ, σ); }
N(b) { go_White(α, ω, ο, ρ, δ, σ); }
N(o) {
  P_Yellow /**/ (ω).v = go_DarkGreen;
  P_Red /*   */ (ω).v = go_DarkRed;
  P_Green /* */ (ω).v = go_DarkYellow;
  P_Blue /*  */ (ω).v = go_DarkBlue;
  ο[ω.tin].v = aradani_heart;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}

N(toti_arm_go_White_w) {
  win_v Tw = P_Yellow(ω).w;
  win_v next_w = P_DarkYellow(ω).w;
  P_Red(Tw).w = next_w;
  go_White(α, Tw, ο, ρ, δ, σ);
}
N(toti_arm_go_Black_w) {
  win_v Tw = P_Yellow(ω).w;
  P_Red(Tw).w = P_DarkRed(Tw).w;
  go(α, Tw, ο, ρ, δ, σ);
}
N(toti_arm_go_Nxt_arm) { go_White(α, P_Yellow(ω).w, ο, ρ, δ, σ); }

N(toti_heart) { go_White(α, P_Red(ω).w, ο, ρ, δ, σ); }
N(toti) {
#define WriteArm                                                               \
  c--;                                                                         \
  while (*arms[c] != o)                                                        \
    T(*arms[c]), arms[c]++;                                                    \
  T(*arms[c]);
  nar_t **arms = P_Blue(ω).v;
  long c = P_DarkBlue(ω).q;
  win_v r, l;
  l = Twin(toti_arm_go_Black_w), P_Yellow(l).w = ω;
  WriteArm;
  r = Twin(toti_arm_go_White_w), P_Yellow(r).w = ω, P_DarkYellow(r).w = l;
  WriteArm;
  while (c) {
    l = Twin(toti_arm_go_Nxt_arm), P_Yellow(l).w = r;
    WriteArm;
    r = Twin(toti_arm_go_White_w), P_Yellow(r).w = ω, P_DarkYellow(r).w = l;
    WriteArm;
  }
  P_Red(ω).w = r;
  P_DarkRed(ω).w = r;
  ο[ω.tin].v = toti_heart;
  toti_heart(α, ω, ο, ρ, δ, σ);
#undef WriteArm
}
N(not ) {
  P_Yellow /*     */ (ω).v = go_DarkGreen;
  P_Red /*        */ (ω).v = go_Yellow;
  P_Green /*      */ (ω).v = go_DarkYellow;
  P_Blue /*       */ (ω).v = go_Blue;
  ο[ω.tin].v = aradani_heart;
  P_DarkBlue /*   */ (ω).v = go_DarkBlue;
  P_DarkGreen /*  */ (ω).v = go_Green;
  P_DarkRed /*    */ (ω).v = go_DarkRed;
  P_DarkYellow /* */ (ω).v = go_DarkYellow;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}
N(and) {
  P_Yellow /*     */ (ω).v = go_DarkGreen;
  P_Red /*        */ (ω).v = go_Red;
  P_Green /*      */ (ω).v = go_Yellow;
  P_Blue /*       */ (ω).v = go_Blue;
  ο[ω.tin].v = aradani_heart;
  P_DarkBlue /*   */ (ω).v = go_DarkBlue;
  P_DarkGreen /*  */ (ω).v = go_Green;
  P_DarkRed /*    */ (ω).v = go_DarkRed;
  P_DarkYellow /* */ (ω).v = go_DarkYellow;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}
N(or) {
  P_Yellow /*     */ (ω).v = go_DarkGreen;
  P_Red /*        */ (ω).v = go_Red;
  P_Green /*      */ (ω).v = go_DarkYellow;
  P_Blue /*       */ (ω).v = go_Yellow;
  ο[ω.tin].v = aradani_heart;
  P_DarkBlue /*   */ (ω).v = go_DarkBlue;
  P_DarkGreen /*  */ (ω).v = go_Green;
  P_DarkRed /*    */ (ω).v = go_DarkRed;
  P_DarkYellow /* */ (ω).v = go_DarkYellow;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}
N(orand) {
  P_Yellow /*     */ (ω).v = go_DarkGreen;
  P_Red /*        */ (ω).v = go_Red;
  P_Green /*      */ (ω).v = go_Yellow;
  P_Blue /*       */ (ω).v = go_Yellow;
  ο[ω.tin].v = aradani_heart;
  P_DarkBlue /*   */ (ω).v = go_DarkBlue;
  P_DarkGreen /*  */ (ω).v = go_Green;
  P_DarkRed /*    */ (ω).v = go_DarkRed;
  P_DarkYellow /* */ (ω).v = go_DarkYellow;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}
