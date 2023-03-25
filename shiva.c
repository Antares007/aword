// clang-format off
#define N(args)                                                                \
  void args(long α, struct t_t *ω, struct t_t *ο, long ρ, long δ, long σ)
#define T(aw) {.q = 0}, {.c = aw}, {.q = 0},
#define X ω[δ].c(α, ω + δ, ο, ρ, δ, σ)
#define W(         aw) (ω = (aw))
#define White(  sopos) δ sopos +3
#define Black(  sopos) δ sopos -3
#define Yellow( sopos) ρ sopos +3
#define Red(    sopos) ρ sopos +2
#define Green(  sopos) ρ sopos +1
#define Blue(   sopos) ρ sopos +0
typedef struct t_t {
  union {
    void *v;
    float f;
    long q;
    const char *cs;
    struct t_t *t;
    N((*c));
  };
} t_t;
#define Tv(aw, value) {.q = 0}, {.c = aw}, {.v = (void *)value},
// clang-format on
static N(shiv_arm) {
  White(=);
  if (Yellow(==)) {
    t_t *shiva_or_right_arm = ο[--σ].t;
    W(shiva_or_right_arm), X;
  } else
    X;
}
static N(last_arm) {
  if (Yellow(==)) {
    t_t *invalid_next_right_arm = ο[--σ].v;
    t_t *shiva = ο[--σ].t;
    long invalid_next_right_arm_index = ο[--σ].q;
    (void)invalid_next_right_arm, (void)invalid_next_right_arm_index;
    Black(=), W(shiva), X;
  } else
    White(=), X;
}

N(shiva) {
  if (White(==)) {
    if (Green(==)) {
      const long first_right_arm_index = 0;
      t_t *first_right_arm = ω[1].t[first_right_arm_index].t;
      ο[σ++].q = first_right_arm_index;
      ο[σ++].t = ω;
      Yellow(=), W(first_right_arm), X;
    } else {
      if (Yellow(==))
        Green(=);
      Black(=), X;
    }
  } else if (Yellow(==)) {
    long last_right_arm_index = ο[--σ].q;
    long next_right_arm_index = last_right_arm_index + 2;
    t_t *next_right_arm = ω[1].t[last_right_arm_index + 2].t;
    t_t *next_left_arm = ω[1].t[last_right_arm_index + 1].t;
    ο[σ++].q = next_right_arm_index;
    ο[σ++].t = ω;
    ο[σ++].t = next_right_arm;
    W(next_left_arm), White(=), X;
  } else {
    White(=), X;
  }
}
#define AWord(name, ...)                                                       \
  N(name) {                                                                    \
    if (White(==) && Green(==)) {                                              \
      __VA_ARGS__;                                                             \
    }                                                                          \
    X;                                                                         \
  }
#include <stdio.h>
AWord(print, printf("%s", ω[1].cs));
N(b) { White(=), X; }
N(o) {
  if (Yellow(==)) {
    Green(=);
  } else if (Green(==)) {
    Yellow(=);
  }
  Black(=), X;
}
int main() {
  t_t *t =
      1 + (t_t[]){T(b) Tv(print, "Tina.\n") Tv(
              shiva, ((t_t *[]){
                         1 + (t_t[]){T(shiv_arm) Tv(print, "before1") T(o)},
                         1 + (t_t[]){T(shiv_arm) Tv(print, "after1.\n") T(o)},
                         1 + (t_t[]){T(shiv_arm) Tv(print, "before2") T(o)},
                         1 + (t_t[]){T(shiv_arm) Tv(print, "after2.\n") T(o)},
                         1 + (t_t[]){T(shiv_arm) Tv(print, "before3") T(o)},
                         1 + (t_t[]){T(shiv_arm) Tv(print, "after3.\n") T(o)},
                         1 + (t_t[]){T(shiv_arm) Tv(print, "before4") T(o)},
                         1 + (t_t[]){T(shiv_arm) Tv(print, "after4.\n") T(o)},
                         1 + (t_t[]){T(shiv_arm) Tv(print, "before5") T(o)},
                         1 + (t_t[]){T(shiv_arm) Tv(print, "after5.\n") T(o)},
                         1 + (t_t[]){T(shiv_arm) Tv(print, "before6") T(o)},
                         1 + (t_t[]){T(last_arm) Tv(print, "after6.\n") T(o)},

                     })) Tv(print, " shua ") T(o)};
  t_t o[128];
  t[3].c(0, t + 3, o, 3, 3, 64);
  return 0;
}
