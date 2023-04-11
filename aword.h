#pragma once
#define Args long τ, long α, struct base_t *β, long ο, long σ
#define N(argo) void argo(Args)
typedef struct base_t {
  union {
    long q;
    void *v;
    N((*c));
  };
} base_t;
typedef N((*n_t));

