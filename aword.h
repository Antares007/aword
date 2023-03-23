#pragma once
#define N(args)                                                                \
  void args(long τ, long α, long β, struct text_t *ω, struct text_t *ο,        \
            long ρ, long δ, long σ)
#define T(aw) {.q = 0}, {{aw}}, {.q = 0}, {.q = 0}, {{t}}, {.cs = #aw},
#define X ω[3 * δ].c(τ, α, β, ω + 3 * δ, ο, ρ, δ, σ)
#define White(sopos) δ sopos + 1
#define Black(sopos) δ sopos - 1
#define Yellow(sopos) ρ sopos + 3
#define Red(sopos) ρ sopos + 2
#define Green(sopos) ρ sopos + 1
#define Blue(sopos) ρ sopos + 0
typedef struct text_t {
  union {
    void *v;
    float f;
    long q;
    const char *cs;
    struct text_t *t;
    N((*c));
  };
} text_t;
