#pragma once
#define N(argo) void argo(void **o, long t, long a, long r, long i)
#define Ta(nar, val) o[--a] = val, o[--a] = nar, o[--a] = #nar,
#define T(n) Ta(n, 0)
typedef N((*w_t));

