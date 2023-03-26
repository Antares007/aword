#include "aword.h"
#include "text_index.h"
#define AWord(name, ...)                                                       \
  N(name) {                                                                    \
    if (White(==) && Green(==)) {                                              \
      __VA_ARGS__;                                                             \
    }                                                                          \
    X;                                                                         \
  }
#include <stdio.h>
AWord(print //, printf("%s", ω[1].cs)
);
N(A) { X; }
N(B) { X; }
N(C) { X; }
N(D) { X; }
#define D(...)   (t_t*[]) { __VA_ARGS__, 1+(t_t[]) { T(right_arm) T(o) }, 1+(t_t[]) { T(last_arm) T(o) } }
#define B_(...)1+(t_t []) { T(left_arm)  __VA_ARGS__ T(o) }
#define B(...) 1+(t_t []) { T(right_arm) __VA_ARGS__ T(o) }, B_
static t_t *my_hands[] = {
    1 + (t_t[]){T(right_arm) T(B) T(B) T(B) Tv(shiva, my_hands) T(o)},
    1 + (t_t[]){T(last_arm) T(C) T(C) T(o)},
};
#include<unistd.h>
int main() {
  t_t *ω = 1 + (t_t[]){
                   T(b)                       //
    Tv(shiva, my_hands)
                   T(o)                       //
               };
  t_t ο[128];
  long α = 0, ρ, δ, σ = 64;
  text_index_init();
  W(ω), White(=), Yellow(=), X;
  return 0;
}
