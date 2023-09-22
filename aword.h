#pragma once

#define N(argo) void argo(long t, long a, long b, void**o, const char*s)
typedef N((*n_t));
#define T(x,y,z) (o[--b] = (void*)(x)), (o[--b] = (void*)(y)), (o[--b] = (void*)(z))
#define Printf(...) ((void (*)(const char *, ...))o[0])(__VA_ARGS__)
#define USleep(ms) ((int (*)(long))o[1])(ms)
#define W(atext) ((n_t (*)(const char*))o[2])(atext)

#define TAB_Yellow(arm) (arm+00)
#define TAB_Purple(arm) (arm+16)
#define TAB_Red(arm)    (arm+32)
#define TAB_Green(arm)  (arm+48)
#define TAB_Blue(arm)   (arm+64)
