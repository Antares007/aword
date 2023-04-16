#pragma once
#define Args long τ, long α, long β, void**ο, void**σ, const char*δ
#define N(argo) void argo(Args)
typedef N((*n_t));
