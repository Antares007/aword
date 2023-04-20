#pragma once
#ifdef NDEBUG
#define ti_left(...) (void)0
#define ti_right(...) (void)0
#define ti_ret(...) (void)0
#define ti(...) (void)0
#else
void ti_left();
void ti_right();
void ti_ret();
void ti(long t, long ray, long delta);
#endif

