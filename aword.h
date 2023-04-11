#pragma once
#define P printf("%5s %s\n", (char *)ο[τ+512].v, __FUNCTION__), usleep(100000)
#define Args long τ, long α, long β, struct base_t *ο, long σ
#define N(argo) void argo(Args)
typedef struct base_t {
  union {
    long q;
    void *v;
    N((*c));
  };
} base_t;
typedef N((*n_t));

