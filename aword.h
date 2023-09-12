#pragma once

#define N(argo) void argo(long t, long a, void*b, void**o, long s)
typedef N((*n_t));

#define Printf(...) ((void (*)(const char *, ...))o[0])(__VA_ARGS__)
#define USleep(ms) ((int (*)(long))o[1])(ms)
#define P Printf("%3ld %3ld %s:%s\n", a, s, __FILE__, __FUNCTION__), USleep(200000)
