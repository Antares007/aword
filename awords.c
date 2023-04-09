#include "aword.h"

N(go) /*           */ { m(τ, ρ, δ); }
N(go_Yellow) /*    */ { m(τ, 3, +1); }
N(go_Red) /*       */ { m(τ, 2, +1); }
N(go_Green) /*     */ { m(τ, 1, +1); }
N(go_Blue) /*      */ { m(τ, 0, +1); }
N(go_DarkBlue) /*  */ { m(τ, 0, -1); }
N(go_DarkGreen) /* */ { m(τ, 1, -1); }
N(go_DarkRed) /*   */ { m(τ, 2, -1); }
N(go_DarkYellow) /**/ { m(τ, 3, -1); }
N(aradani_pith) { ((N((**)))τ)[(ρ + 1) * δ](τ, ρ, δ); }
N(not ) {
  τ[+3 + 1] = /*Yellow*/ go_DarkGreen;
  τ[+2 + 1] = /*Red   */ go_Yellow;
  τ[+1 + 1] = /*Green */ go_DarkYellow;
  τ[+0 + 1] = /*Blue  */ go_DarkBlue;
  τ[0] = aradani_pith;
  τ[-0 - 1] = /*DarkBlue  */ go_DarkBlue;
  τ[-1 - 1] = /*DarkGreen */ go_Green;
  τ[-2 - 1] = /*DarkRed   */ go_DarkRed;
  τ[-3 - 1] = /*DarkYellow*/ go_DarkYellow;
  aradani_pith(τ, ρ, δ);
}
N(and) {
  τ[+4] = /*Yellow*/ go_DarkGreen;
  τ[+3] = /*Red   */ go_Red;
  τ[+2] = /*Green */ go_Yellow;
  τ[+1] = /*Blue  */ go_Blue;
  τ[0] = aradani_pith;
  τ[-1] = /*DarkBlue  */ go_DarkBlue;
  τ[-2] = /*DarkGreen */ go_Green;
  τ[-3] = /*DarkRed   */ go_DarkRed;
  τ[-4] = /*DarkYellow*/ go_DarkYellow;
  aradani_pith(τ, ρ, δ);
}
N(or) {
  τ[+3 + 1] = /*Yellow*/ go_DarkGreen;
  τ[+2 + 1] = /*Red   */ go_Red;
  τ[+1 + 1] = /*Green */ go_DarkYellow;
  τ[+0 + 1] = /*Blue  */ go_Yellow;
  τ[0] = aradani_pith;
  τ[-0 - 1] = /*DarkBlue  */ go_DarkBlue;
  τ[-1 - 1] = /*DarkGreen */ go_Green;
  τ[-2 - 1] = /*DarkRed   */ go_DarkRed;
  τ[-3 - 1] = /*DarkYellow*/ go_DarkYellow;
  aradani_pith(τ, ρ, δ);
}
N(orand) {
  τ[+3 + 1] = /*Yellow*/ go_DarkGreen;
  τ[+2 + 1] = /*Red   */ go_Red;
  τ[+1 + 1] = /*Green */ go_Yellow;
  τ[+0 + 1] = /*Blue  */ go_Yellow;
  τ[0] = aradani_pith;
  τ[-0 - 1] = /*DarkBlue  */ go_DarkBlue;
  τ[-1 - 1] = /*DarkGreen */ go_Green;
  τ[-2 - 1] = /*DarkRed   */ go_DarkRed;
  τ[-3 - 1] = /*DarkYellow*/ go_DarkYellow;
  aradani_pith(τ, ρ, δ);
}
