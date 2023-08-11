#pragma once
#define N(argo) void argo(long t, long a, void*b, void**o, long s)
typedef N((*n_t));
#define Usleep(v) ((void (*)(long))o[1])(v)
#define Printf(...) ((void (*)(const char *, ...))o[0])(__VA_ARGS__)
#define P Printf("%3ld %3ld %s %s\n", a, s, __FILE__, __FUNCTION__), Usleep(20000)

