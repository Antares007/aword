#define N(argo) void argo(long t, long a, void **o, long s)
typedef N((*n_t));
#include <stdio.h>
#include <unistd.h>
#define P printf("%s %s\n", __FUNCTION__, (char *)o[t]), usleep(200000)
// clang-format off
N(Yellow  ) { P, ((n_t*)o)[t + 8](t + 15, a, o, s); }
N(Purple  ) { P, ((n_t*)o)[t + 9](t + 15, a, o, s); }
N(Red     ) { P, ((n_t*)o)[t +10](t + 15, a, o, s); }
N(Green   ) { P, ((n_t*)o)[t +11](t + 15, a, o, s); }
N(Blue    ) { P, ((n_t*)o)[t +12](t + 15, a, o, s); }
N(Navy    ) { P, ((n_t*)o)[t -12](t - 15, a, o, s); }
N(Lime    ) { P, ((n_t*)o)[t -11](t - 15, a, o, s); }
N(Maroon  ) { P, ((n_t*)o)[t -10](t - 15, a, o, s); }
N(Fuchsia ) { P, ((n_t*)o)[t - 9](t - 15, a, o, s); }
N(Olive   ) { P, ((n_t*)o)[t - 8](t - 15, a, o, s); }
// clang-format on
#define T(W, O, R, L, D)                                                  \
  o[a++] = (void *)W, o[a++] = (void *)O, o[a++] = (void *)R,             \
  o[a++] = (void *)L, o[a++] = (void *)D
N(l_Fuchsia) { o[--s] = (void*)t, Fuchsia((long)o[t - 1], a, o, s); }
N(r_Fuchsia) { o[--s] = (void*)t, Fuchsia((long)o[t + 1], a, o, s); }
N(s_Fuchsia) { Fuchsia((long)o[s], a, o, s + 1); }
N(s_Purple ) { Purple ((long)o[s], a, o, s + 1); }
int main( ) {
  long t = 0;
  long a = t;
  void *o[512];
  long s = 512;
                                              T(0, 0, "b", 0, 0), T(Blue, Green, Red,    Yellow,    Purple),
  T(Yellow, Purple,     Red,    Green, Blue), T(0, 0, "l", 0, 0), T(Navy, Lime,  Maroon, Fuchsia,   Olive),
  T(Lime,   s_Fuchsia,  Maroon, Olive, Navy), T(0, 0, "o", 0, 0);
  long l = (long)(a - 3);
                                              T(0, 0, "b", 0, 0), T(Blue, Green, Red,    Yellow,    Purple),
  T(Yellow, Purple,     Red,    Green, Blue), T(0, 0, "r", 0, 0), T(Navy, Lime,  Maroon, Fuchsia,   Olive),
  T(Lime,   s_Purple,   Maroon, Olive, Navy), T(0, 0, "o", 0, 0);
  long r = (long)(a - 3);
                                              T(0, 0, "b", 0, 0), T(Blue, Green, Red,    Yellow,    Purple);
  T(Yellow, r_Fuchsia,  Red,    Green, Blue), T(0, l, "t", r, 0), T(Navy, Lime,  Maroon, l_Fuchsia, Olive);
  T(Yellow, Purple,     Red,    Green, Blue), T(0, 0, "w", 0, 0), T(Navy, Lime,  Maroon, Fuchsia,   Olive);
  T(Yellow, Purple,     Red,    Green, Blue), T(0, 0, "w", 0, 0), T(Navy, Lime,  Maroon, Fuchsia,   Olive);
  T(Lime,   Fuchsia,    Maroon, Olive, Navy), T(0, 0, "o", 0, 0);
  Fuchsia(a - 3, a, o, s);
}
