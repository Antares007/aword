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
c_t bottom_arms, top_arms;
n_t Tab_Yellow[4];
n_t Tab_Green [4];
n_t Tab_Red   [4];
n_t Tab_Blue  [4];

n_t *frontdoor, *backdoor;
n_t locked_bottom_gate[4];
n_t bottom_gate[4];
n_t right_gate[4];
n_t top_gate[4];
n_t back_gate[4];
const long Yellow_off = 32, Green_off = 64, Red_off = 96, Blue_off = 128;
N(bottom_gate_Yellow) { c_t*c=&bottom_arms;(o[--b]=right_gate),(o[--b]=c),(o[--b]=Tab_Yellow),(c->arms[c->i] + Yellow_off)(t, a, b, o, s); }
N(bottom_gate_Green ) { c_t*c=&bottom_arms;(o[--b]=right_gate),(o[--b]=c),(o[--b]=Tab_Green),(c->arms[c->i] + Green_off)(t, a, b, o, s); }
N(bottom_gate_Red   ) { c_t*c=&bottom_arms;(o[--b]=right_gate),(o[--b]=c),(o[--b]=Tab_Red),(c->arms[c->i] + Red_off)(t, a, b, o, s); }
N(bottom_gate_Blue  ) { c_t*c=&bottom_arms;(o[--b]=right_gate),(o[--b]=c),(o[--b]=Tab_Blue),(c->arms[c->i] + Blue_off)(t, a, b, o, s); }

N(top_gate_Yellow) { c_t*c=&top_arms;(o[--b]=right_gate),(o[--b]=c),(o[--b]=Tab_Yellow),(c->arms[c->i] + Yellow_off)(t, a, b, o, s); }
N(top_gate_Green ) { c_t*c=&top_arms;(o[--b]=right_gate),(o[--b]=c),(o[--b]=Tab_Green),(c->arms[c->i] + Green_off)(t, a, b, o, s); }
N(top_gate_Red   ) { c_t*c=&top_arms;(o[--b]=right_gate),(o[--b]=c),(o[--b]=Tab_Red),(c->arms[c->i] + Red_off)(t, a, b, o, s); }
N(top_gate_Blue  ) { c_t*c=&top_arms;(o[--b]=right_gate),(o[--b]=c),(o[--b]=Tab_Blue),(c->arms[c->i] + Blue_off)(t, a, b, o, s); }


N(open_frontdoor) { 
  frontdoor = bottom_gate;
  for(long i = 0; i < arms_count; i++) {
    n_t arm = Bark(arm_texts[i]);
    (o[a + 0] = (void*)__FILE__), (o[a + 1] = 0), (o[a + 2] = 0), arm(t, a, b, o, s);
    if (o[a + 2]) {
      top_arms.arms[top_arms.count++] = arm;
    } else {
      bottom_arms.arms[bottom_arms.count++] = arm;
    }
  }
  ((n_t)o[b])(t, a, b + 1, o, s);
}
N(locked_bottom_gate_Yellow ) { (o[--b] = bottom_gate_Yellow), open_frontdoor(t, a, b, o, s); }
N(locked_bottom_gate_Green  ) { (o[--b] = bottom_gate_Green),  open_frontdoor(t, a, b, o, s); }
N(locked_bottom_gate_Red    ) { Red(t, a, b, o, s); }
N(locked_bottom_gate_Blue   ) { Blue(t, a, b, o, s); }

G(Yellow) { frontdoor[0](t, a, b, o, s); }
G(Green ) { frontdoor[1](t, a, b, o, s); }
G(Red   ) { frontdoor[2](t, a, b, o, s); }
G(Blue  ) { frontdoor[3](t, a, b, o, s); }

N(Yellow_yellow ) { c_t*c = o[b++]; n_t* aw = o[b++]; c->fruitful[c->i] = 1;
                    ((c->i = (c->i + 1) % c->count) ? aw[1] : aw[0])(t, a, b, o, s); }
N(Yellow_green  ) { c_t*c = o[b++]; n_t* aw = o[b++]; c->fruitful[c->i] = 1; (aw[1])(t, a, b, o, s); }
N(Yellow_red    ) { c_t*c = o[b++]; n_t* aw = o[b++];
                    if(c->fruitful[c->i]) {
                      ((c->i = (c->i + 1) % c->count) ? (aw[3]) : (aw[2]))(t, a, b, o, s);
                    } else if (c->count == 1) {
                      maroon(t, a, b, o, s);
                    } else {
                      c->count--;
                      for (long i       = c->i; i < c->count; i++)
                        Unbark(c->arms[i], ((long *)c->arms[i])[1]),
                        (c->arms[i]     = c->arms[i + 1]),
                        (c->fruitful[i] = c->fruitful[i + 1]);
                      // Printf("trimed %ld %ld ", c->i, c->count);
                      ((c->i = (c->i + 0) % c->count) ? (aw[3]) : (aw[2]))(t, a, b, o, s);
                    }
                  }
N(Yellow_blue   ) { Blue(t, a, b + 2, o, s); }

N(Green_green   ) { Yellow_green(t, a, b, o, s); }
N(Green_blue    ) { Blue(t, a, b + 2, o, s); }

N(Red_red       ) { c_t*c = o[b++]; n_t*aw = o[b++];
                    ((c->i = (c->i + 1) % c->count) ? (aw[3]) : (aw[2]))(t, a, b, o, s); }
N(Red_blue      ) { Blue(t, a, b + 2, o, s); }
N(Blue_blue     ) { Blue(t, a, b + 2, o, s); }

N(stop) { P; }
G(Purple) {
  init();
  if (CMP(o[a + 0], __FILE__) == 0 && (long)o[a + 1] == 0) {
    o[a + 2]            = (void*)1;
    Printf("left recursion\n");
    return;
  } else {
    o[a + 2]            = (void*)0;
    frontdoor           = locked_bottom_gate;
    locked_bottom_gate[0] = locked_bottom_gate_Yellow;
    locked_bottom_gate[1] = locked_bottom_gate_Green;
    locked_bottom_gate[2] = locked_bottom_gate_Red;
    locked_bottom_gate[3] = locked_bottom_gate_Blue;

    bottom_gate[0] = bottom_gate_Yellow;
    bottom_gate[1] = bottom_gate_Green;
    bottom_gate[2] = bottom_gate_Red;
    bottom_gate[3] = bottom_gate_Blue;
    top_gate[0] = top_gate_Yellow;
    top_gate[1] = top_gate_Green;
    top_gate[2] = top_gate_Red;
    top_gate[3] = top_gate_Blue;

    right_gate[0] = Yellow;
    right_gate[1] = Green;
    right_gate[2] = Red;
    right_gate[3] = Blue;

    Tab_Yellow[0] = Yellow_yellow;
    Tab_Yellow[1] = Yellow_green;
    Tab_Yellow[2] = Yellow_red;
    Tab_Yellow[3] = Yellow_blue;

    Tab_Green[0] = stop;
    Tab_Green[1] = Green_green;
    Tab_Green[2] = stop;
    Tab_Green[3] = Green_blue;

    Tab_Red[0] = stop;
    Tab_Red[1] = stop;
    Tab_Red[2] = Red_red;
    Tab_Red[3] = Red_blue;

    Tab_Blue[0] = stop;
    Tab_Blue[1] = stop;
    Tab_Blue[2] = stop;
    Tab_Blue[3] = Blue_blue;
  }
  Purple(t, a, b, o, s);
}
