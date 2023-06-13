#pragma once
#define N(argo) void   argo(void**o, long s, long a)
typedef         void (*n_t)(void**o, long s, long a);
#define Usleep(v) (void)0
//((void (*)(long))o[1])(v)
#define Printf(...) ((void (*)(const char *, ...))o[0])(__VA_ARGS__)
#define P Printf("%3ld %3ld %s %s\n", a, s, __FILE__, __FUNCTION__), Usleep(20000)

