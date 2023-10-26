#include "aw.h"
#define COUNT 0
static void init() {}
long arms_count = COUNT;
const char *arm_texts[COUNT];
typedef struct c_t {
  long i;
  long count;
  char fruitful[COUNT];
  n_t arms[COUNT];
} c_t;
c_t right_arms, left_arms;
// clang-format off
n_t Tab_Yellow[4];
n_t Tab_Green [4];
n_t Tab_Red   [4];
n_t Tab_Blue  [4];

n_t *front_separator, *right_separator, *tab_or_back_separator, *back_separator;
n_t locked_leftleft_gateway [4];
n_t locked_right_gateway    [4];
n_t right_gateway           [4];
n_t locked_left_gateway     [4];
n_t forward_gateway         [4];
n_t backward_gateway        [4];
n_t left_gateway            [4];
const long Yellow_off = 32, Green_off = 64, Red_off = 96, Blue_off = 128;
#define Left_Gate(Yellow)                                                      \
  N(left_gate_##Yellow) {                                                      \
    o[--b] = tab_or_back_separator;                                                   \
    o[--b] = &left_arms;                                                       \
    o[--b] = Tab_##Yellow;                                                     \
    o[--b] = (void*)-1;                                                        \
    o[--b] = (void*)__FILE__;                                                  \
    (left_arms.arms[left_arms.i] + Yellow##_off)(t, a, b, o, s);               \
  }
Left_Gate(Yellow) Left_Gate(Green) Left_Gate(Red) Left_Gate(Blue);
N(locked_left_gate_Yellow ) { right_separator = left_gateway;
                              left_gateway[0](t, a, b, o, s); }
N(locked_left_gate_Green  ) { right_separator = left_gateway;
                              left_gateway[1](t, a, b, o, s); }
N(locked_left_gate_Red    ) { forward_gateway[2](t, a, b, o, s); }
N(locked_left_gate_Blue   ) { forward_gateway[3](t, a, b, o, s); }

#define Right_Gate(Yellow)                                                     \
  N(right_gate_##Yellow) {                                                     \
    o[--b] = right_separator;                                                  \
    o[--b] = &right_arms;                                                      \
    o[--b] = Tab_##Yellow;                                                     \
    o[--b] = (void*)+1;                                                        \
    o[--b] = (void*)__FILE__;                                                  \
    (right_arms.arms[right_arms.i] + Yellow##_off)(t, a, b, o, s);             \
  }
Right_Gate(Yellow) Right_Gate(Green) Right_Gate(Red) Right_Gate(Blue);
N(init_next_arm);
N(locked_right_gate_Yellow) { front_separator = right_gateway;
                              o[--b] = right_gateway[0];
                              o[a++] = (void *)1;
                              init_next_arm(t, a, b, o, s); }
N(locked_right_gate_Green ) { front_separator = right_gateway;
                              o[--b] = right_gateway[1];
                              o[a++] = (void *)1;
                              init_next_arm(t, a, b, o, s); }
N(locked_right_gate_Red   ) { Red(t, a, b, o, s); }
N(locked_right_gate_Blue  ) { Blue(t, a, b, o, s); }

G(Yellow) { front_separator[0](t, a, b, o, s); }
G(Green ) { front_separator[1](t, a, b, o, s); }
G(Red   ) { front_separator[2](t, a, b, o, s); }
G(Blue  ) { front_separator[3](t, a, b, o, s); }

N(locked_leftleft_gate_Yellow ) { back_separator = left_gateway;
                                  o[--b] = left_gateway[0];
                                  o[a++] = (void *)1;
                                  init_next_arm(t, a, b, o, s); }
N(locked_leftleft_gate_Green  ) { back_separator = left_gateway;
                                  o[--b] = left_gateway[1];
                                  o[a++] = (void *)1;
                                  init_next_arm(t, a, b, o, s); }
N(locked_leftleft_gate_Red    ) { Maroon(t, a, b, o, s); }
N(locked_leftleft_gate_Blue   ) { Navy(t, a, b, o, s); }

G(Olive ) { back_separator[0](t, a, b, o, s); }
G(Lime  ) { back_separator[1](t, a, b, o, s); }
G(Maroon) { back_separator[2](t, a, b, o, s); }
G(Navy  ) { back_separator[3](t, a, b, o, s); }
#define PC (void)c
//#define PC Printf("%s %ld %ld/%ld\n", __FUNCTION__, c->fruitful[c->i], c->i, c->count)
N(Yellow_Olive) { c_t *c = o[b++]; n_t *gate = o[b++]; PC;
                  c->fruitful[c->i] = 1;
                  ((c->i = (c->i + 1) % c->count) ? gate[1] : gate[0])(t, a, b, o, s); }
N(Yellow_Lime ) { c_t *c = o[b++]; n_t *gate = o[b++]; PC;
                  c->fruitful[c->i] = 1;
                  gate[1](t, a, b, o, s); }
N(Yellow_Maroon){ c_t *c = o[b++]; n_t *gate = o[b++]; PC;
                  if (c->fruitful[c->i]) {
                    ((c->i = (c->i + 1) % c->count) ? gate[3] : gate[2])(t, a, b, o, s);
                  } else if (c->count == 1) {
                    gate[2](t, a, b, o, s);
                  } else {
                    c->count--;
                    for (long i = c->i; i < c->count; i++)
                      // Unbark(c->arms[i], ((long *)c->arms[i])[1]),
                      (c->arms[i] = c->arms[i + 1]), (c->fruitful[i] = c->fruitful[i + 1]);
                    //Printf("trimed %ld %ld\n", c->i, c->count);
                    if (c->i == c->count) (c->i = 0), gate[2](t, a, b, o, s);
                    else                              gate[3](t, a, b, o, s);
                  } }
N(Yellow_Navy ) { c_t *c = o[b++]; n_t *gate = o[b++]; PC; gate[3](t, a, b, o, s); }

N(Green_Lime  ) { c_t *c = o[b++]; n_t *gate = o[b++]; PC;
                  c->fruitful[c->i] = 1;
                  gate[1](t, a, b, o, s);  }
N(Green_Navy  ) { c_t *c = o[b++]; n_t *gate = o[b++]; PC; gate[3](t, a, b, o, s); }

N(Red_Maroon  ) { c_t *c = o[b++]; n_t *gate = o[b++]; PC;
                  ((c->i = (c->i + 1) % c->count) ? gate[3] : gate[2])(t, a, b, o, s); }
N(Red_Navy    ) { c_t *c = o[b++]; n_t *gate = o[b++]; PC; gate[2](t, a, b, o, s); }
N(Blue_Navy   ) { c_t *c = o[b++]; n_t *gate = o[b++]; PC; gate[3](t, a, b, o, s); }

N(stop) { P; }
G(Purple) {
  if (b < a)
    return Printf("Halting problem...\n"), (void)0;
  init();
  locked_right_gateway[0] = locked_right_gate_Yellow;
  locked_right_gateway[1] = locked_right_gate_Green;
  locked_right_gateway[2] = locked_right_gate_Red;
  locked_right_gateway[3] = locked_right_gate_Blue;
  right_gateway[0] = right_gate_Yellow;
  right_gateway[1] = right_gate_Green;
  right_gateway[2] = right_gate_Red;
  right_gateway[3] = right_gate_Blue;

  locked_left_gateway[0] = locked_left_gate_Yellow;
  locked_left_gateway[1] = locked_left_gate_Green;
  locked_left_gateway[2] = locked_left_gate_Red;
  locked_left_gateway[3] = locked_left_gate_Blue;
  left_gateway[0] = left_gate_Yellow;
  left_gateway[1] = left_gate_Green;
  left_gateway[2] = left_gate_Red;
  left_gateway[3] = left_gate_Blue;

  forward_gateway[0] = Yellow;
  forward_gateway[1] = Green;
  forward_gateway[2] = Red;
  forward_gateway[3] = Blue;

  locked_leftleft_gateway[0] = locked_leftleft_gate_Yellow;
  locked_leftleft_gateway[1] = locked_leftleft_gate_Green;
  locked_leftleft_gateway[2] = locked_leftleft_gate_Red;
  locked_leftleft_gateway[3] = locked_leftleft_gate_Blue;
  backward_gateway[0] = Olive;
  backward_gateway[1] = Lime;
  backward_gateway[2] = Maroon;
  backward_gateway[3] = Navy;

  Tab_Yellow[0] = Yellow_Olive;
  Tab_Yellow[1] = Yellow_Lime;
  Tab_Yellow[2] = Yellow_Maroon;
  Tab_Yellow[3] = Yellow_Navy;

  Tab_Green[0] = stop;
  Tab_Green[1] = Green_Lime;
  Tab_Green[2] = stop;
  Tab_Green[3] = Green_Navy;

  Tab_Red[0] = stop;
  Tab_Red[1] = stop;
  Tab_Red[2] = Red_Maroon;
  Tab_Red[3] = Red_Navy;

  Tab_Blue[0] = stop;
  Tab_Blue[1] = stop;
  Tab_Blue[2] = stop;
  Tab_Blue[3] = Blue_Navy;

  long terminals_count    = (long)o[--a];
  long is_left_recursion  = (long)o[--a];
  const char *name = o[--a];
  if (CMP(name, __FILE__) == 0 && terminals_count == 0) {
    is_left_recursion     = 1;
    front_separator       = forward_gateway;
    back_separator        = locked_leftleft_gateway;
    tab_or_back_separator = backward_gateway;
  } else {
    back_separator        = backward_gateway;
    front_separator       = locked_right_gateway;
    right_separator       = locked_left_gateway;
    tab_or_back_separator = forward_gateway;
  }
  left_arms.arms[0] = Bark("tab o");
  left_arms.count = 1;

  right_arms.arms[0] = Bark(arm_texts[0]);
  right_arms.count = 1;

  o[--b] = __FILE__;
  o[--b] = Purple;
  o[a++] = (void *)name;
  o[a++] = (void *)is_left_recursion;
  o[a++] = (void *)terminals_count;
  right_arms.arms[0](t, a, b, o, s);
}
N(set_arm) {
  --a; // terminals_count
  long is_left_recursion = (long)o[--a];
  --a; // name
  n_t arm = o[--a];
  long i = (long)o[--a];
  if (is_left_recursion) {
    //n_t ε = left_arms.arms[left_arms.count - 1];
    //left_arms.arms[left_arms.count - 1] = arm;
    left_arms.arms[left_arms.count++] = arm;
  } else {
    right_arms.arms[right_arms.count++] = arm;
  }
  o[a++] = (void *)(i + 1);
  init_next_arm(t, a, b, o, s);
}
N(init_next_arm) {
  long i = (long)o[--a];
  if (i < arms_count) {
    n_t arm = Bark(arm_texts[i]);
    o[a++] = (void *)i;
    o[--b] = (void*)__FILE__;
    o[--b] = set_arm;
    o[a++] = arm;
    o[a++] = (void *)__FILE__;
    o[a++] = 0;
    o[a++] = 0;
    arm(t, a, b, o, s);
  } else
    ((n_t)o[b])(t, a, b + 1, o, s);
}
