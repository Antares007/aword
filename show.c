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
N(E) { X; }
int main() {
  t_t *ω =
      1 + (t_t[]){
              T(b) //
              T(A) //
              T(A) //
              T(A) //
              Tv(shiva, ((t_t *[]){
                  //
                  1 + (t_t[]){T(right_arm) T(B) T(B) T(B)
                        Tv(shiva, ((t_t *[]){ //
                            1 + (t_t[]){T(right_arm) T(B) T(B) T(B) T(o)}, //
                            1 + (t_t[]){T(left_arm) T(C) T(C) T(C) T(o)},  //
                            1 + (t_t[]){T(right_arm) T(B) T(B) T(B) T(o)}, //
                            1 + (t_t[]){T(last_arm) T(C) T(C) T(C) T(o)},  //
                        }))
                      T(o)}, //
                  1 + (t_t[]){T(left_arm) T(C) T(C) T(C)
                        Tv(shiva, ((t_t *[]){ //
                            1 + (t_t[]){T(right_arm) T(B) T(B) T(B) T(o)}, //
                            1 + (t_t[]){T(left_arm) T(C) T(C) T(C) T(o)},  //
                            1 + (t_t[]){T(right_arm) T(B) T(B) T(B) T(o)}, //
                            1 + (t_t[]){T(last_arm) T(C) T(C) T(C) T(o)},  //
                        }))
                      T(o)},  //
                  1 + (t_t[]){T(right_arm) T(B) T(B) T(B) T(o)}, //
                  1 + (t_t[]){T(last_arm) T(C) T(C) T(C) T(o)},  //
              }))                                                //
              T(A) //
              T(A) //
              T(A) //
Tv(shiva, ((t_t *[]){
                  //
                  1 + (t_t[]){T(right_arm) T(B) T(B) T(B)
                        Tv(shiva, ((t_t *[]){ //
                            1 + (t_t[]){T(right_arm) T(B) T(B) T(B) T(o)}, //
                            1 + (t_t[]){T(left_arm) T(C) T(C) T(C) T(o)},  //
                            1 + (t_t[]){T(right_arm) T(B) T(B) T(B) T(o)}, //
                            1 + (t_t[]){T(last_arm) T(C) T(C) T(C) T(o)},  //
                        }))
                      T(o)}, //
                  1 + (t_t[]){T(left_arm) T(C) T(C) T(C)
                        Tv(shiva, ((t_t *[]){ //
                            1 + (t_t[]){T(right_arm) T(B) T(B) T(B) T(o)}, //
                            1 + (t_t[]){T(left_arm) T(C) T(C) T(C) T(o)},  //
                            1 + (t_t[]){T(right_arm) T(B) T(B) T(B) T(o)}, //
                            1 + (t_t[]){T(last_arm) T(C) T(C) T(C) T(o)},  //
                        }))
                      T(o)},  //
                  1 + (t_t[]){T(right_arm) T(B) T(B) T(B) T(o)}, //
                  1 + (t_t[]){T(last_arm) T(C) T(C) T(C) T(o)},  //
              }))
              T(D)
              T(D)
              T(D)
              T(o)                                                         //
          };
  t_t ο[128];
  long α = 0, ρ, δ, σ = 64;
  text_index_init();
  W(ω), White(=), Yellow(=), X;
  return 0;
}
