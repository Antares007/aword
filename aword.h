#pragma once
#define N(argo) void argo(void **o, long t, long a, long r, long i)
#define Ta(n, a) o[--t] = a, o[--t] = (void *)n, o[--t] = #n,
#define T(n) Ta(n, 0)
typedef N((*w_t));

