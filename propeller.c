#define N(argo) void argo(long t, long a, void **o, long s)
typedef N((*n_t));
#include <stdio.h>
#include <unistd.h>
#define P printf("%s %s\n", __FUNCTION__, (char *)o[t]), usleep(200000)
char *names[1024];
void ti_left();
void ti_right();
void ti_ret();
void ti_init();
void ti(long t, long ray, long delta);
// clang-format off
N(Yellow  ) { ti(t+15,+5,+1),((n_t*)o)[t + 8](t + 15, a, o, s); }
N(Purple  ) { ti(t+15,+4,+1),((n_t*)o)[t + 9](t + 15, a, o, s); }
N(Red     ) { ti(t+15,+3,+1),((n_t*)o)[t +10](t + 15, a, o, s); }
N(Green   ) { ti(t+15,+2,+1),((n_t*)o)[t +11](t + 15, a, o, s); }
N(Blue    ) { ti(t+15,+1,+1),((n_t*)o)[t +12](t + 15, a, o, s); }
N(Navy    ) { ti(t-15,-1,-1),((n_t*)o)[t -12](t - 15, a, o, s); }
N(Lime    ) { ti(t-15,-2,-1),((n_t*)o)[t -11](t - 15, a, o, s); }
N(Maroon  ) { ti(t-15,-3,-1),((n_t*)o)[t -10](t - 15, a, o, s); }
N(Fuchsia ) { ti(t-15,-4,-1),((n_t*)o)[t - 9](t - 15, a, o, s); }
N(Olive   ) { ti(t-15,-5,-1),((n_t*)o)[t - 8](t - 15, a, o, s); }
// clang-format on
#define T(W, O, R, L, D)                                                       \
  o[a++] = (void *)W, o[a++] = (void *)O, names[a] = #R, o[a++] = (void *)R,   \
  o[a++] = (void *)L, o[a++] = (void *)D
N(l_Fuchsia) {
  o[--s] = (void *)t, ti_left(), Fuchsia((long)o[t - 1], a, o, s);
}
N(r_Fuchsia) {
  o[--s] = (void *)t, ti_right(), Fuchsia((long)o[t + 1], a, o, s);
}
N(s_Lime) { ti_ret(), Lime((long)o[s], a, o, s + 1); }
N(s_Green) { ti_ret(), Green((long)o[s], a, o, s + 1); }
#define Tlabel(text)                                                           \
  T(Yellow, Purple, Red, Green, Blue), T(0, 0, text, 0, 0),                    \
      T(Navy, Lime, Maroon, Fuchsia, Olive)
#define Toti(left, right)                                                      \
  T(Yellow, Purple, Red, r_Fuchsia, Blue), T(0, left, "t", right, 0),          \
      T(Navy, l_Fuchsia, Maroon, Fuchsia, Olive)
#define Tdot T(Lime, Fuchsia, Maroon, Olive, Navy), T(0, 0, "o", 0, 0)
#define Tb T(0, 0, "b", 0, 0), T(Blue, Green, Red, Yellow, Purple)
#define Ts_Lime T(Lime, s_Lime, Maroon, Olive, Navy), T(0, 0, "o", 0, 0)
#define Ts_Green T(Lime, s_Green, Maroon, Olive, Navy), T(0, 0, "o", 0, 0)
#define Tadd T(Lime,Purple,Red,Yellow,Blue),T(0,0,"and",0,0),T(Navy,Green,Maroon,Fuchsia,Olive)
#define Tnoun(value)                                                           \
  T(Yellow, Purple, Red, Green, Blue), T(0, 0, #value, value, 0),              \
      T(Navy, noun_heart, Maroon, Fuchsia, Olive)
N(noun_heart) {
  o[--s] = o[t+1];
  Lime(t, a, o, s);
}
#define Tverb(nar)                                                             \
  T(Yellow, Purple, Red, nar, Blue), T(0, 0, #nar, 0, 0),                      \
      T(Navy, Lime, Maroon, Fuchsia, Olive)
N(add) {
  long r = (long)o[s++];
  long l = (long)o[s++];
  o[--s] = (void *)(l + r);
  Green(t, a, o, s);
}
N(print) {
  printf("%ld\n", (long)o[s++]);
  Green(t, a, o, s);
}
int main() {
  long t = 0;
  long a = t;
  void *o[ 1024];
  long s = 1024;
  Tb, Tlabel("left"),   Tlabel("left"),   Tlabel("left"),   Tlabel("left"),   Ts_Lime;  long l0 = (long)(a - 3);
  Tb, Tlabel("right"),  Tlabel("right"),  Tlabel("right"),  Tlabel("right"),  Ts_Green; long r0 = (long)(a - 3);
  Tb, Tlabel("left"),   Tlabel("left"),   Tlabel("left"),   Ts_Lime;  long l1 = (long)(a - 3);
  Tb, Tlabel("right"),  Tlabel("right"),  Tlabel("right"),  Ts_Green; long r1 = (long)(a - 3);
  Tb, Tlabel("left"),   Tlabel("left"),   Ts_Lime;  long l2 = (long)(a - 3);
  Tb, Tlabel("right"),  Tlabel("right"),  Ts_Green; long r2 = (long)(a - 3);
  Tb, Toti(l0, r0),     Tlabel("w"),      Toti(l1, r1),     Tlabel("w"),      Toti(l2, r2),
      Tlabel("w"),      Tdot;
  ti_init();
//  Tb, Tnoun(1), Tverb(add), Tnoun(1), Tadd, Tverb(print), Tdot;
  Fuchsia(a - 3, a, o, s);
}
