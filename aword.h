#pragma once

#define N(argo) void argo(long t, long a, long b, void**o, const char*s)
typedef N((*n_t));
#define Printf(...)         ((void (*)(const char *, ...))       o[0])(__VA_ARGS__)
#define Unbark(aword, size) ((int  (*)(void*, long))             o[4])(aword, size)
#define Bark(atext)         ((n_t  (*)(const char*))             o[2])(atext)
#define CMP(s1, s2)         ((int  (*)(const char*, const char*))o[3])(s1, s2)
