#include "awords.h"
N(go) {
  ω.win = Plus(ω, (1 + 4 + 4) * δ.dir);
  ο[ω.win].go(α, ω, ο, ρ, δ, σ);
}
N(go_White) { go(α, ω, ο, ρ, (dir_v){-1}, σ); }
N(go_Black) { go(α, ω, ο, ρ, (dir_v){+1}, σ); }
N(go_Yellow) /*    */ { go_White(α, ω, ο, (ray_v){3}, δ, σ); }
N(go_Red) /*       */ { go_White(α, ω, ο, (ray_v){2}, δ, σ); }
N(go_Green) /*     */ { go_White(α, ω, ο, (ray_v){1}, δ, σ); }
N(go_Blue) /*      */ { go_White(α, ω, ο, (ray_v){0}, δ, σ); }
N(go_DarkBlue) /*  */ { go_Black(α, ω, ο, (ray_v){0}, δ, σ); };
N(go_DarkGreen) /* */ { go_Black(α, ω, ο, (ray_v){1}, δ, σ); };
N(go_DarkRed) /*   */ { go_Black(α, ω, ο, (ray_v){2}, δ, σ); };
N(go_DarkYellow) /**/ { go_Black(α, ω, ο, (ray_v){3}, δ, σ); };
N(aradani_heart) { P, ο[Plus(ω, (1 + ρ.ray) * δ.dir)].go(α, ω, ο, ρ, δ, σ); }
N(b_pith) { P, go_White(α, ω, ο, ρ, δ, σ); }
#include <assert.h>
N(b) {
  α.win -= 4, ο[ω.win = --α.win].v = b_pith, α.win -= 4;
  b_pith(α, ω, ο, ρ, δ, σ);
}

N(o) {
  P;
  ο[--α.win].v /*Yellow*/ = go_DarkGreen;
  ο[--α.win].v /*Red   */ = go_DarkRed;
  ο[--α.win].v /*Green */ = go_DarkYellow;
  ο[--α.win].v /*Blue  */ = go_DarkBlue;
  ο[--α.win].v = aradani_heart;
  --α.win, --α.win, --α.win, --α.win;
  --σ.win, ο[σ.win].go(α, ω, ο, ρ, δ, σ);
}
N(not ) {
  P_Yellow /*     */ (ω).v = go_DarkGreen;
  P_Red /*        */ (ω).v = go_Yellow;
  P_Green /*      */ (ω).v = go_DarkYellow;
  P_Blue /*       */ (ω).v = go_Blue;
  ο[ω.win].v = aradani_heart;
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
  ο[ω.win].v = aradani_heart;
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
  ο[ω.win].v = aradani_heart;
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
  ο[ω.win].v = aradani_heart;
  P_DarkBlue /*   */ (ω).v = go_DarkBlue;
  P_DarkGreen /*  */ (ω).v = go_Green;
  P_DarkRed /*    */ (ω).v = go_DarkRed;
  P_DarkYellow /* */ (ω).v = go_DarkYellow;
  aradani_heart(α, ω, ο, ρ, δ, σ);
}
