#pragma once
#define Args long τ, long α, long β, struct base_t *ο, struct base_t *σ
#define N(argo) void argo(Args)
typedef struct base_t {
  union {
    long q;
    void *v;
    N((*c));
  };
} base_t;
typedef N((*n_t));
