#define N(args)                                                                \
  void args(long α, struct τext *ω, struct τext *ο, long ρ, long δ)
typedef struct τext {
  union {
    void *v;
    long q;
    const char *cs;
    struct τext *t;
    N((*c));
  };
} τext;
#define T(aw) {.q = 0}, {{aw}}, {.t = 0}, {.q = 0}, {{t}}, {.t = 0},
#define D_(...) {.t = (τext[]){T(rtrn) __VA_ARGS__ T(o)}},
#define DB(...) {.t = (τext[]){T(rtrn) __VA_ARGS__ T(o)}}, {{bark}}, D_
#define B(...) DB()(__VA_ARGS__)
#define D(...) DB(__VA_ARGS__)()
N(rtrn) {}
void gut_rotate(long δ);
N(bark) {
  τext *β = ω[δ].t + 1;
  gut_rotate(-δ);
  β[3].c(α, β + 3, ο, ρ, 1);
  gut_rotate(δ);
  ω[3 * δ].c(α, ω + 3 * δ, ο, ρ, δ);
}
N(o) { ω[-3].c(α, ω - 3, ο, ρ, -1); }
N(b) { ω[3].c(α, ω + 3, ο, (ρ + 1) % 4, 1); }
void gut_line_to(long, long);
N(t) { gut_line_to(ρ, δ), ω[3 * δ].c(α, ω + 3 * δ, ο, ρ, δ); }
N(m) { ω[3 * δ].c(α, ω + 3 * δ, ο, ρ, δ); }
N(p) {
  if (δ > 0) ω[3 * δ].c(α, ω + 3 * δ, ο, ρ, δ);
  else if (ρ < 3) ω[3].c(α, ω + 3, ο, ρ + 1, 1);
  else ω[-3].c(α, ω - 3, ο, ω[-1].q++ % 4, -1);
}
void init_gut(long fps);
void clear_gut();
int main(int argc, char **argv) {
  // clang-format off
  τext ω[] = {
                                                        T(b)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
DB(T(m)T(m)T(m)T(m)T(m)T(m)T(m)T(m)T(p)T(m)T(m)T(p)T(m)T(m))(T(m)T(m)T(m)T(m)T(m)T(m)T(m)T(m)T(p)T(m)T(m)T(p)T(m)T(m))
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(m)
                                                        T(p)
                                                        T(m)
                                                        T(m)
                                                        T(p)
                                                        T(m)
                                                        T(m)
                                                        T(o)
             };
  // clang-format on
  τext ο[512];
  long α = 0;
  init_gut(0);
  ω[4].c(α, ω + 4, ο, 0, 1);
  clear_gut();
  return 0;
}
