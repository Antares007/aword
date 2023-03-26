#pragma once
// clang-format off
#define N(args)                                                                \
  void args(long α, struct t_t *ω, struct t_t *ο, long ρ, long δ, long σ)
#define T(aw) {.q = 0}, {.c = aw}, {.q = 0},
#define Tv(aw, value) {.q = 0}, {.c = aw}, {.v = (void *)value},
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
N(b);N(o);N(shiva);N(right_arm);N(left_arm);N(last_arm);N(ara);N(da);N(ni);
