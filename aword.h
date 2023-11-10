#pragma once

#define N(argo) void argo(long t, long a, long b, void**o, const char*s)
typedef N((*n_t));
#define Printf(...)         ((void (*)(const char *, ...))       o[0])(__VA_ARGS__)
#define Unbark(aword, size) ((int  (*)(void*, long))             o[4])(aword, size)
#define Bark(atext)         ((n_t  (*)(const char*))             o[2])(atext)
#define Uname(a)            ((n_t  (*)(long))                    o[4])(a)
#define W(atext)            Bark(atext)
#define TI(a1,a2,a3)        ((void (*)(const char*,const char*,long))o[3])(a1,a2,a3)
#define CMP(s1, s2)         ((int (*)(const char*, const char*))o[1])((s1), (s2))
#define P                   (void)0
//#define P                   Printf("%3ld %3ld %s %s\n", a, b, __FILE__, __FUNCTION__), Usleep(20000)
