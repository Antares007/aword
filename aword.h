#pragma once

#define N(argo) void argo(long t, long a, void*b, void**o, long s)
typedef N((*n_t));
#define T(t,a,b) (o[--s] = (void*)(t)), (o[--s] = (void*)(a)), (o[--s] = (void*)(b))
#define Printf(...) ((void (*)(const char *, ...))o[0])(__VA_ARGS__)
#define USleep(ms) ((int (*)(long))o[1])(ms)
#define P_ if(t!=1) Printf("%s", __FILE__), USleep(20000)
#define P (void)0
#define PI(n) ({for(long i = 0; i < n; i++) Printf("  ");});
