#pragma once
#include <stdio.h>
#include <unistd.h>
#ifdef NDEBUG
#define NAME(ο, zero) (void)0
#else
#define NAME(ο, zero) names[ο] = zero
#endif
#define P(color) printf("%7s %s\n", #color,names[τ]), usleep(200000)
