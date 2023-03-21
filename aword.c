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
#define D_(...) ((text_t[]){T(ret) __VA_ARGS__ T(o)} + 1),
#define DB(...) ((text_t[]){T(ret) __VA_ARGS__ T(o)} + 1), 0, D_
void gut_rotate(float theta);
N(ret) { δ = ο[σ++].q, ω = ο[σ++].t, gut_rotate(-ο[σ++].f), X; }
#define AWord(name, ...)                                                       \
  N(name);                                                                     \
  text_t *name##_texts[] = {__VA_ARGS__};                                      \
  N(name) {                                                                    \
    long hands = sizeof(name##_texts) / sizeof(void *) / 3;                    \
    long hand_index = ω[1].q;                                                  \
    text_t *hand = name##_texts[1 + hand_index * 3 + δ];                       \
    ο[--σ].f = δ * (hand_index + 1) * 3.1416 / (hands + 1);                    \
    gut_rotate(ο[σ].f);                                                        \
    if (White(==)) {                                                           \
      ο[--σ].t = ω;                                                            \
      ο[--σ].q = 1;                                                            \
    } else if (hand_index + 1 < hands) {                                       \
      ο[--σ].t = ω - 3;                                                        \
      ο[--σ].q = 1;                                                            \
      ω[1].q++;                                                                \
    } else {                                                                   \
      ο[--σ].t = ω;                                                            \
      ο[--σ].q = -1;                                                           \
      ω[1].q = 0;                                                              \
    }                                                                          \
    White(=);                                                                  \
    ω = hand, X;                                                               \
  }
int gut_close_requested();
void gut_line_to(long, long, const char *);
N(t) {
  if (gut_close_requested())
    return;
  gut_line_to(ρ, δ, ω[1].cs);
  X;
}
#define AWgoto(color)                                                          \
  N(goto_##color) {                                                            \
    if (White(==) && Yellow(!=))                                               \
      Blue(=);                                                                 \
    X;                                                                         \
  }
AWgoto(Blue) AWgoto(Red) AWgoto(Green) AWgoto(Yellow);
N(b) {
  if (Yellow(==))
    White(=), Green(=), X;
}
N(o) { Black(=), X; }
// clang-format off
N(an) {
  if (White(==)) {
    if (Blue(==)) Green(=);
    else if (Green(==)) Black(=); } X; }
N(da) { X; }
N(ara) {
  if (White(==)) {
    if (Red(==)) Green(=);
    else if (Green(==)) Black(=); } X; }
// clang-format on
void gut_init(long);
void gut_clear();
N(one) {
  if (White(==) && Yellow(==))
    ο[α++].q = 1;
  X;
}
N(add) {
  if (White(==) && Green(==)) {
    long sum = 0;
    while (128 < α)
      sum += ο[--α].q;
    ο[α++].q = sum;
  }
  X;
}
#include <stdio.h>
N(print) {
  if (Black(==) && Green(==)) {
    for (long i = 128; i < α; i++)
      printf("%ld ", ο[i].q);
    printf("\nα:%ld\n", α);
    α = 128;
  }
  X;
}
text_t ct[] = {T(b) T(print) T(one) T(one) T(one) T(add) T(one) T(o)};
int main(int argc, char **argv) {
  // clang-format off
  text_t*ω = 1 + ct;
  // clang-format on
  text_t ο[128 * 4];
  long τ = 0, α = 128, β = 256, ρ = 3, δ = 1, σ = 384;
  gut_init(4), X, gut_clear();
  return 0;
}
