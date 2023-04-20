#pragma once
#define Args long τ, long α, long β, void **ο, long σ
#define N(argo) void argo(Args)
typedef N((*n_t));
