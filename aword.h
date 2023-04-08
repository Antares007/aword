#pragma once
#define W(name, r, d)                                                          \
  N(name##_pith);                                                              \
  N(name) {                                                                    \
    τ[+4] = go, τ[+3] = go, τ[+2] = go, τ[+1] = go;                            \
    τ[0] = aradani_pith;                                                       \
    τ[-1] = go, τ[-2] = go, τ[-3] = go, τ[-4] = go;                            \
    τ[(r + 1) * d] = name##_pith;                                              \
    aradani_pith(τ, ρ, δ);                                                     \
  }                                                                            \
  N(name##_pith)
#define N(arg) void arg(Args)
#define Args void **τ, long ρ, long δ
#define T(ina) 0, 0, 0, 0, 0, ina, 0, 0, 0, 0, 0

static N(m) { ((N((**)))τ)[11 * δ](τ + 11 * δ, ρ, δ); }
static N(b) { m(τ, ρ, δ * -1); }
static N(o) { m(τ, ρ == 3 ? 1 : ρ == 1 ? 3 : ρ, δ * -1); }

static N(go) /*           */ { m(τ, ρ, δ); }
static N(go_Yellow) /*    */ { m(τ, 3, +1); }
static N(go_Red) /*       */ { m(τ, 2, +1); }
static N(go_Green) /*     */ { m(τ, 1, +1); }
static N(go_Blue) /*      */ { m(τ, 0, +1); }
static N(go_DarkBlue) /*  */ { m(τ, 0, -1); }
static N(go_DarkGreen) /* */ { m(τ, 1, -1); }
static N(go_DarkRed) /*   */ { m(τ, 2, -1); }
static N(go_DarkYellow) /**/ { m(τ, 3, -1); }
static N(aradani_pith) { ((N((**)))τ)[(ρ + 1) * δ](τ, ρ, δ); }
static N(not ) {
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
static N(and) {
  τ[+3 + 1] = /*Yellow*/ go_DarkGreen;
  τ[+2 + 1] = /*Red   */ go_Red;
  τ[+1 + 1] = /*Green */ go_Yellow;
  τ[+0 + 1] = /*Blue  */ go_Blue;
  τ[0] = aradani_pith;
  τ[-0 - 1] = /*DarkBlue  */ go_DarkBlue;
  τ[-1 - 1] = /*DarkGreen */ go_Green;
  τ[-2 - 1] = /*DarkRed   */ go_DarkRed;
  τ[-3 - 1] = /*DarkYellow*/ go_DarkYellow;
  aradani_pith(τ, ρ, δ);
}
static N(or) {
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
static N(orand) {
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
