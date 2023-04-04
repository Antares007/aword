#pragma once
#define AW 8
#define T(nar) Ta(nar, 0)
#define Ta(nar, var)                                                           \
#nar, 0, 0, 0, 0, 0, 0, 0, nar, 0, 0, 0, 0, 0, 0, 0, (void *)var,
#define B(...)                                                                 \
  (({                                                                          \
     void *text[] = {__VA_ARGS__};                                             \
     long i = sizeof(text) / sizeof(void *);                                   \
     while (i)                                                                 \
       ο[--α].v = text[--i];                                                   \
   }),                                                                         \
   α + AW)
#define N(argo)                                                                \
  void argo(long α, long ω, struct text_t *ο, long ρ, long δ, long σ)
typedef struct text_t {
  union {
    long q;
    void *v;
    N((*go));
  };
} text_t;
N(m);
N(b);
N(o);
N(toti);
N(not );
N(and);
N(or);
N(orand);
