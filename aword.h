#pragma once

#define N(argo) void argo(long t, long a, long b, void**o, const char*s)
typedef N((*n_t));
#define T(x,y,z) (o[--b] = (void*)(x)), (o[--b] = (void*)(y)), (o[--b] = (void*)(z))
#define Printf(...) ((void (*)(const char *, ...))o[0])(__VA_ARGS__)
#define USleep(ms) ((int (*)(long))o[1])(ms)
#define P_ Printf("%ld %3ld %3ld %s:%s\n", t, a, b, __FILE__, __FUNCTION__), USleep(2000)
//#define P P_
#define P (void)0
#define W(atext) ((n_t (*)(const char*))o[2])(atext)
