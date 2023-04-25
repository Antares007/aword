#define N(argo) void argo(long t, long a, void **o, long s)
typedef N((*n_t));
#include <stdio.h>
#include <unistd.h>
#define P printf("%s %s", __FUNCTION__, (char *)o[t]), usleep(200000)
// clang-format off
N(Yellow  ) { ((n_t*)o)[t + 8](t + 15, a, o, s); }
N(Purple  ) { ((n_t*)o)[t + 9](t + 15, a, o, s); }
N(Red     ) { ((n_t*)o)[t +10](t + 15, a, o, s); }
N(Green   ) { ((n_t*)o)[t +11](t + 15, a, o, s); }
N(Blue    ) { ((n_t*)o)[t +12](t + 15, a, o, s); }





N(Navy    ) { ((n_t*)o)[t -12](t - 15, a, o, s); }
N(Lime    ) { ((n_t*)o)[t -11](t - 15, a, o, s); }
N(Maroon  ) { ((n_t*)o)[t -10](t - 15, a, o, s); }
N(Fuchsia ) { ((n_t*)o)[t - 9](t - 15, a, o, s); }
N(Olive   ) { ((n_t*)o)[t - 8](t - 15, a, o, s); }
// clang-format on

#define Tworld(W, O, R, L, D)                                                  \
  o[a++] = (void *)W, o[a++] = (void *)O, o[a++] = (void *)R,                  \
  o[a++] = (void *)L, o[a++] = (void *)D
#define Tb                                                                     \
  Tworld(0, 0, "b", 0, 0),                                                     \
  Tworld(Blue, Green, Red, Yellow, Purple)
#define Tw(text)                                                               \
  Tworld(Yellow, Purple, Red,    word,    Blue),                               \
  Tworld(0, 0, text, 0, 0),                                                    \
  Tworld(Navy,   Lime,   Maroon, Fuchsia, Olive)
#define Tob(i)                                                                 \
  Tworld(Lime, Purple, Maroon, Olive, Navy),                                   \
  Tworld(0, 0, "ob", i, 0),                                                    \
  Tworld(Blue, Green,  Red,    prop,  Fuchsia)
#define To                                                                     \
  Tworld(Lime, join, Maroon, Olive, Navy),                                     \
  Tworld(0, 0, "o", 0, 0),                                                     \
  Tworld(0, 0, 0, 0, Fuchsia)
N(join) { Fuchsia((long)o[t + 1], a, o, s); }
N(prop) {
  long i = (long)o[t + 1];
  o[t + 1] = (void *)((i + 1) % 4);
  if (i)
    Yellow(t, a, o, s);
  else
    Fuchsia(t, a, o, s);
}
N(word) {printf("%s", (char*)o[t]), usleep(20000),Green(t,a,o,s);}
int main() {
  long t = 0;
  long a = 0;
  void *o[512];
  long s = 0;
  Tb, Tw("\nA"), Tob(0), Tw("1"), Tob(0), To; long s0 = a - 8;
  Tb, Tw(  "B"), Tob(1), Tw("2"), Tob(1), To; long s1 = a - 8;
  //  Tb, Tw(  "C"), Tob(2), Tw("3"), Tob(2), To; long s2 = a - 8;
  //  Tb, Tw(  "D"), Tob(3), Tw("4"), Tob(3), To; long s3 = a - 8;
  o[s0 + 1] = (void *)s1;
  o[s1 + 1] = (void *)s0;
  //  o[s2 + 1] = (void *)s3;
  //  o[s3 + 1] = (void *)s0;
  // convolution 
  Fuchsia(s0, a, o, s);
}
