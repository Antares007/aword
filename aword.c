#define N(args)                                                                \
  void args(long α, struct τext *ω, struct τext *ο, long ρ, long δ)
#define T(aw) {.q = 0}, {{aw}}, {.t = 0}, {.q = 0}, {{t}}, {.t = 0},
#define B(...) DB()(__VA_ARGS__)
#define D(...) DB(__VA_ARGS__)()
#define D_(...) {.t = (τext[]){T(rtrn) __VA_ARGS__ T(o)}},
#define DB(...) {.t = (τext[]){T(rtrn) __VA_ARGS__ T(o)}}, {{bark}}, D_
#define X ω[3 * δ].c(α, ω + 3 * δ, ο, ρ, δ)
typedef struct τext {
  union {
    void *v;
    long q;
    const char *cs;
    struct τext *t;
    N((*c));
  };
} τext;
N(rtrn) {}
void gut_rotate(long δ);
N(bark) {
  τext *β = ω[δ].t + 1;
  gut_rotate(-δ);
  β[3].c(α, β + 3, ο, ρ, 1);
  gut_rotate(δ);
  X;
}
N(o) { δ = -1, X; }
N(b) { ρ = (ρ + 1) % 4, δ = 1, X; }
void gut_line_to(long, long);
N(t) { gut_line_to(ρ, δ), X; }
N(p) {
  if (δ > 0)
    X;
  else if (ρ < 3)
    ρ++, δ = 1, X;
  else
    ρ = ω[-1].q++ % 4, X;
}
void init_gut(long fps);
void clear_gut();
int main(int argc, char **argv) {
  // clang-format off
  τext*ω = 1 + (τext[]) {
                                                        T(b)
                                 DB(T(t)T(t)T(p)T(t)T(t)T(p)T(t)T(t)T(p)T(t)T(t))
                                   (T(t)T(t)T(p)T(t)T(t)T(p)T(t)T(t)T(p)T(t)T(t))
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
                                                        T(p)
                                                        T(t)
                                                        T(t)
                                                        T(o)
  };
  // clang-format on
  τext ο[512];
  long α = 0, ρ = 0, δ = 1;
  init_gut(0), X, clear_gut();
  return 0;
}
