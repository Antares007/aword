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

void wait();
N(m) { wait(), ω[3 * δ].c(α, ω + 3 * δ, ο, ρ, δ); }
N(p) {
  if (δ > 0)
    ω[3 * δ].c(α, ω + 3 * δ, ο, 1, δ);
  else if (ρ < 3)
    ω[3].c(α, ω + 3, ο, ρ + 1, 1);
  else
    ω[-3].c(α, ω - 3, ο, ω[-1].q++ % 4, -1);
}
N(o) { ω[-3].c(α, ω - 3, ο, ρ, -1); }
N(b) { ω[3].c(α, ω + 3, ο, (ρ + 1) % 4, 1); }
void gut_line_to(long, long);
void gut_rotate(long);
N(trace) { gut_line_to((ρ + 1) * δ, δ), ω[3 * δ].c(α, ω + 3 * δ, ο, ρ, δ); }
N(rotate) { gut_rotate(δ), ω[3 * δ].c(α, ω + 3 * δ, ο, ρ, δ); }
#define T(aw) {.q = 0}, {{aw}}, {.t = 0}, {.q = 0}, {{trace}}, {.t = 0},
#define D_(...) {.t = (τext[]){T(p_return) __VA_ARGS__}},
#define DB(...) {.t = (τext[]){T(m_return) T(o)}}, {{bark}}, D_
#define B(...) {.t = (τext[]){T(m_return) T(o)}}, {{bark}}, {.t = (τext[]){T(p_return) __VA_ARGS__}},
N(p_return) { ω[1].t[3].c(α, ω[1].t + 3, ο, ρ, 1); }
N(m_return) { ω[1].t[-3].c(α, ω[1].t - 3, ο, ρ, -1); }
N(bark) {
  τext *β = ω[δ].t + 1;
  β[1].t = ω, β[3].c(α, β + 3, ο, ρ, 1);
}

void init_gut();
void clear_gut();
int main(int argc, char **argv) {
  init_gut();
  // clang-format off
  τext ω[] = {
               T(b)
               T(m)
        DB(T(m)T(o))(T(m)T(o))
               T(m)
               T(o)
             };
  // clang-format on
  τext ο[512];
  ω[4].c(0, ω + 4, ο, 0, 1);
  clear_gut();
  return 0;
}
