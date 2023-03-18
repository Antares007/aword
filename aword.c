#define N(args)                                                                \
  void args(long α, struct τext *ω, struct τext *ο, long ρ, long δ, long σ)
#define T(aw) {.q = 0}, {{aw}}, {.t = 0},
#define B(...) DB()(__VA_ARGS__)
#define D(...) DB(__VA_ARGS__)()
#define D_(...) {.t = (τext[]){T(goto_home) __VA_ARGS__ T(o)}},
#define DB(...) {.t = (τext[]){T(goto_home) __VA_ARGS__ T(o)}}, {{bark}}, D_
#define X ω[3 * δ].c(α, ω + 3 * δ, ο, ρ, δ, σ)
typedef struct τext {
  union {
    void *v;
    long q;
    const char *cs;
    struct τext *t;
    N((*c));
  };
} τext;
void gut_rotate(long δ);

N(goto_home) {
  δ = ο[σ++].q;
  gut_rotate(δ);
  ω = ο[σ++].t;
  X;
}
N(bark) {
  ο[--σ].t = ω;
  ο[--σ].q = δ;
  gut_rotate(-δ);
  ω = ω[δ].t + 1;
  δ = 1, X;
}
N(o) { δ = -1, X; }
N(b) { ρ = (ρ + 1) % 4, δ = 1, X; }
int gut_close_requested();
void gut_line_to(long, long);
N(t) {
  if (gut_close_requested())
    return;
  gut_line_to(ρ, δ), X;
}
N(p) {
  if (δ > 0)
    X;
  else if (ρ < 3)
    ρ++, δ = 1, X;
  else
    ρ = ω[-1].q++ % 4, X;
}
void gut_clear();
void gut_init(long fps);
int main(int argc, char **argv) {
  // clang-format off
  τext*ω = 1 + (τext[]) {
                          T(b)
       DB(T(t)T(t)T(t)T(p)T(t)T(t)T(p)T(t)T(t))
         (T(t)T(t)T(t)T(p)T(t)T(t)T(p)T(t)T(t))
                          T(t)
                          T(t)
                          T(t)
                          T(t)
                          T(t)
                          T(t)
                          T(p)
                          T(t)
                          T(t)
                          T(p)
                          T(t)
                          T(t)
                          T(o)
  };
  // clang-format on
  τext ο[512];
  long α = 0, ρ = 0, δ = 1, σ = sizeof(ο) / sizeof(*ο);
  gut_init(0), X, gut_clear();
  return 0;
}
