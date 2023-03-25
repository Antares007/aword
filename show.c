#include "aword.h"
#define AWord(name, ...)                                                       \
  N(name) {                                                                    \
    if (White(==) && Green(==)) {                                              \
      __VA_ARGS__;                                                             \
    }                                                                          \
    X;                                                                         \
  }
#include <stdio.h>
AWord(print, printf("%s", ω[1].cs));
int main() {
  t_t *ω =
      1 +
      (t_t[]){T(b) Tv(print, "Tina.\n") Tv(
          shiva, ((t_t *[]){
                     1 + (t_t[]){T(shiv_arm) Tv(print, "before1") T(o)},
                     1 + (t_t[]){T(shiv_arm) Tv(print, "after1.\n") T(o)},
                     1 + (t_t[]){T(shiv_arm) Tv(print, "before2") T(o)},
                     1 + (t_t[]){T(last_arm) Tv(print, "after2.\n") T(o)},

                 })) Tv(print, " shua ")
                  Tv(shiva, ((t_t *[]){
                                1 + (t_t[]){T(shiv_arm) Tv(print, "A>") T(o)},
                                1 + (t_t[]){T(shiv_arm) Tv(print, ">A. ") T(o)},
                                1 + (t_t[]){T(shiv_arm) Tv(print, "B>")  T(o)},
                                1 + (t_t[]){T(shiv_arm) Tv(print, ">B. ") T(o)},
                                1 + (t_t[]){T(shiv_arm) Tv(print, "C>") T(o)},
                                1 + (t_t[]){T(last_arm) Tv(print, ">C. ") T(o)},

                            })) Tv(print, " bolo ") T(o)};
  t_t ο[128];
  long α = 0, ρ, δ, σ = 64;
  W(ω + 3), White(=), Yellow(=), X;
  return 0;
}
