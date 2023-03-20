// clang-format off
#define N(args)                                                                \
  void args(long α, long β, struct text_t *ω, struct text_t *ο, long ρ,        \
            long δ, long σ)
#define T(aw) {.q = -3}, {{aw}}, {.q = +3},                                    \
              {.q = -3}, {{t }}, {.q = +3},
#define White(sopos)  (δ sopos + 1)
#define Black(sopos)  (δ sopos - 1)
#define Yellow(sopos) (ρ sopos + 3)
#define Red(sopos)    (ρ sopos + 2)
#define Green(sopos)  (ρ sopos + 1)
#define Blue(sopos)   (ρ sopos + 0)
#define X                                                                      \
  (Green(==) ? ω[ω[δ].q].c(α, β, ω + ω[δ].q, ο, ρ, δ, σ)                       \
             : ω[3 *  δ].c(α, β, ω + 3 * δ,  ο, ρ, δ, σ))
typedef struct text_t {
  union {
    void *v;
    long q;
    const char *cs;
    struct text_t *t;
    N((*c));
  };
} text_t;
int gut_close_requested();
void gut_line_to(long, long, const char *);
N(t) {
  if (gut_close_requested())
    return;
  gut_line_to(ρ, δ, ""), X;
}
N(b) {
  White(=);
  Green(=);
  X;
}
N(enter) {
  if (White(==)) {
    if (Yellow(==)) {
      ο[σ++].t = ω;
    }
  } else if (Yellow(==)) {
    σ--;
    ω[-1].t = ω - 3;
  }
  X;
}
N(o) {
  if (Yellow(==)) {
    ο[σ++].t = ω;
    ω[1].t = ω + 3;
  }
  Black(=), X;
}
N(da) {
  if (White(==)) {
    if (Yellow(==))
      ο[σ++].t = ω;
  }
  X;
}
N(an) {
  if (White(==)) {
    if (Yellow(==))
      ο[σ++].t = ω;
    else if (Green(==))
      Black(=);
    else if (Blue(==))
      Green(=);
  }
  X;
}
N(ara) {
  if (White(==)) {
    if (Yellow(==))     ο[σ++].t = ω;
    else if (Green(==)) Black(=);
    else if (Red(==))   Green(=);
  }
  X;
}
#define AWname(argo, Mn)                                                       \
  N(argo) {                                                                    \
    if (White(==) && Yellow(==))                                               \
      ο[Mn++].t = ω;                                                           \
    X;                                                                         \
  }
#define AWverb3(argo, M1, M2, M3)                                              \
  N(argo) {                                                                    \
    if (White(==)) {                                                           \
    } else {                                                                   \
      if (Yellow(==)) {                                                        \
        text_t *exit  = ο[--σ].t;                                              \
        text_t *m1    = ο[--M1].t;                                             \
        text_t *m2    = ο[--M2].t;                                             \
        text_t *m3    = ο[--M3].t;                                             \
        text_t *enter = ο[--σ].t;                                              \
        enter[1].t    = m1;                                                    \
        m1[-1].t      = enter,  m1[1].t = m2;                                  \
        m2[-1].t      = m1,     m2[1].t = m3;                                  \
        m3[-1].t      = m2,     m3[1].t = exit;                                \
        ο[σ++].t      = enter;                                                 \
      }                                                                        \
    }                                                                          \
    X;                                                                         \
  }
#define AWgoto(color)                                                          \
  N(goto_##color) {                                                            \
    if (White(==) && Yellow(!=))                                               \
      Blue(=);                                                                 \
    X;                                                                         \
  }
AWname(mamam,β) AWname(shvils,α) AWname(sakhli,σ) AWverb3(aushena,β,α,σ);
AWname(dedam,β) AWname(gemrieli,α) AWname(namckhvari,σ) AWverb3(gamoackho,β,α,σ);
AWgoto(Blue) AWgoto(Red);
void gut_init(long fps);void gut_clear();
int main(int argc, char **argv) {
  // clang-format off
  text_t*ω = 1 + (text_t[]) {
    T(b)
      T(enter)
      T(mamam)T(shvils)T(aushena)T(sakhli)
      T(da)
      T(dedam)T(gamoackho)T(gemrieli)T(namckhvari)
    T(o)
  };
  // clang-format on
  text_t ο[170 * 3];
  long α = 0, β = 170, ρ = 3, δ = 1, σ = 340;
  gut_init(20), X, gut_clear();
  return 0;
}
