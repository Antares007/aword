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
N(b) {
  White(=);
  ρ = (ρ + 1) % 4;
  X;
}
N(o) { Black(=), X; }
N(da) { X; }
N(an) {
  if (White(==)) {
    if (Green(==))
      Black(=);
    else if (Blue(==))
      Green(=);
  }
  X;
}
N(ara) {
  if (White(==)) {
    if (Green(==))
      Black(=);
    else if (Red(==))
      Green(=);
  }
  X;
}
#define AWgoto(color)                                                          \
  N(goto_##color) {                                                            \
    if (White(==) && Yellow(!=))                                               \
      Blue(=);                                                                 \
    X;                                                                         \
  }
AWgoto(Blue) AWgoto(Red);
N(id) { X; }
N(deda) { X; }
N(mama) { X; }
N(gemriel) { X; }
N(shvils) { X; }
N(namckhvars) { X; }
N(sakhls) { X; }
N(ackhobs) { X; }
N(ushenebs) { X; }
AWord(                                      //
    b3,                                     //
    DB(T(mama)T(deda)T(shvils))             //
      (T(shvils)      T(deda)    T(mama)  ) //
    DB(T(mama)      T(deda)      T(shvils)) //
      (T(shvils)      T(deda)    T(mama)  ) //
    DB(T(mama)      T(deda)      T(shvils)) //
      (T(shvils)      T(deda)    T(mama)  ) //
);
AWord(                                                                   
    borjgal1,                                                            
    DB(T(mama) T(mama) T(mama) T(mama))(T(deda) T(deda) T(deda) T(deda)) 
);                                                                       
void gut_init(long fps);
void gut_clear();
AWord(borjgal,
  DB(T(mama)T(shvils)T(sakhls)T(ushenebs)T(deda)T(gemriel)T(namckhvars)T(ackhobs)T(b3))
    (T(mama)T(shvils)T(sakhls)T(ushenebs)T(deda)T(gemriel)T(namckhvars)T(ackhobs)T(b3))
  DB(T(deda)T(gemriel)T(namckhvars)T(ackhobs)T(deda)T(gemriel)T(namckhvars)T(ackhobs)T(b3))
    (T(deda)T(gemriel)T(namckhvars)T(ackhobs)T(mama) T(shvils) T(sakhls) T(ushenebs)T(b3))
  DB(T(mama) T(shvils) T(sakhls) T(ushenebs)T(deda)T(gemriel)T(namckhvars)T(ackhobs)T(b3))
    (T(deda)T(gemriel)T(namckhvars)T(ackhobs)T(mama) T(shvils) T(sakhls) T(ushenebs)T(b3))
)
int main(int argc, char **argv) {
  // clang-format off
  text_t*ω = 1 + (text_t[]) {
    T(b)
    T(mama)   T(shvils) T(sakhls)     T(ushenebs)
    T(deda)   T(gemriel)T(namckhvars) T(ackhobs)
    T(borjgal)
    T(deda)   T(gemriel)T(namckhvars) T(ackhobs)
    T(mama)   T(shvils) T(sakhls)     T(ushenebs)
    T(mama)   T(shvils)
    T(borjgal1)
    T(sakhls) T(ushenebs)
    T(deda)   T(gemriel)T(namckhvars) T(ackhobs)
    T(mama)   T(shvils) T(sakhls)     T(ushenebs)
    T(borjgal)
    T(deda)   T(gemriel)T(namckhvars) T(ackhobs)
    T(mama)   T(shvils) T(sakhls)     T(ushenebs)
    T(o)
  };
  // clang-format on
  text_t ο[128 * 4];
  long τ = 0, α = 128, β = 256, ρ = 3, δ = 1, σ = 384;
  ο[α++].cs = "baaaa";
  ο[α++].q = 5;
  ο[α++].q = 0;
  gut_init(0), X, gut_clear();
  return 0;
}
