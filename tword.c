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
n_t Tab_Yellow[4];
n_t Tab_Green [4];
n_t Tab_Red   [4];
n_t Tab_Blue  [4];

n_t *frontdoor, *backdoor;
n_t locked_frontdoor[4];
n_t opened_frontdoor[4];
const long Yellow_off = 32, Green_off = 64, Red_off = 96, Blue_off = 128;
N(opened_frontdoor_Yellow ) { c_t*c = &right_arms; (o[--b] = Purple), (o[--b] = c), (o[--b] = Tab_Yellow),  (c->arms[c->i] + Yellow_off)(t, a, b, o, s); }
N(opened_frontdoor_Green  ) { c_t*c = &right_arms; (o[--b] = Purple), (o[--b] = c), (o[--b] = Tab_Green),   (c->arms[c->i] + Green_off)(t, a, b, o, s); }
N(opened_frontdoor_Red    ) { c_t*c = &right_arms; (o[--b] = Purple), (o[--b] = c), (o[--b] = Tab_Red),     (c->arms[c->i] + Red_off)(t, a, b, o, s); }
N(opened_frontdoor_Blue   ) { c_t*c = &right_arms; (o[--b] = Purple), (o[--b] = c), (o[--b] = Tab_Blue),    (c->arms[c->i] + Blue_off)(t, a, b, o, s); }

N(open_frontdoor) { 
  frontdoor = opened_frontdoor;
  for(long i = 0; i < arms_count; i++) {
    n_t arm = Bark(arm_texts[i]);
    (o[a + 0] = (void*)__FILE__), (o[a + 1] = 0), (o[a + 2] = 0), arm(t, a, b, o, s);
    if (o[a + 2]) {
      left_arms.arms[left_arms.count++] = arm;
    } else {
      right_arms.arms[right_arms.count++] = arm;
    }
  }
  ((n_t)o[b])(t, a, b + 1, o, s);
}
N(locked_frontdoor_Yellow ) { (o[--b] = opened_frontdoor_Yellow), open_frontdoor(t, a, b, o, s); }
N(locked_frontdoor_Green  ) { (o[--b] = opened_frontdoor_Green),  open_frontdoor(t, a, b, o, s); }
N(locked_frontdoor_Red    ) { Red(t, a, b, o, s); }
N(locked_frontdoor_Blue   ) { Blue(t, a, b, o, s); }

G(Yellow) { frontdoor[0](t, a, b, o, s); }
G(Green ) { frontdoor[1](t, a, b, o, s); }
G(Red   ) { frontdoor[2](t, a, b, o, s); }
G(Blue  ) { frontdoor[3](t, a, b, o, s); }

N(Yellow_yellow ) { c_t*c = o[b++]; n_t aw = o[b++]; c->fruitful[c->i] = 1;
                    ((c->i = (c->i + 1) % c->count) ? aw + Green_off : aw + Yellow_off)(t, a, b, o, s); }
N(Yellow_green  ) { c_t*c = o[b++]; n_t aw = o[b++]; c->fruitful[c->i] = 1; (aw + Green_off)(t, a, b, o, s); }
N(Yellow_red    ) { c_t*c = o[b++]; n_t aw = o[b++];
                    if(c->fruitful[c->i]) {
                      ((c->i = (c->i + 1) % c->count) ? (aw + Blue_off) : (aw + Red_off))(t, a, b, o, s);
                    } else if (c->count == 1) {
                      maroon(t, a, b, o, s);
                    } else {
                      c->count--;
                      for (long i       = c->i; i < c->count; i++)
                        Unbark(c->arms[i], ((long *)c->arms[i])[1]),
                        (c->arms[i]     = c->arms[i + 1]),
                        (c->fruitful[i] = c->fruitful[i + 1]);
                      // Printf("trimed %ld %ld ", c->i, c->count);
                      ((c->i = (c->i + 0) % c->count) ? (aw + Blue_off) : (aw + Red_off))(t, a, b, o, s);
                    }
                  }
N(Yellow_blue   ) { Blue(t, a, b + 2, o, s); }

N(Green_green   ) { Yellow_green(t, a, b, o, s); }
N(Green_blue    ) { Blue(t, a, b + 2, o, s); }

N(Red_red       ) { c_t*c = o[b++]; n_t aw = o[b++];
                    ((c->i = (c->i + 1) % c->count) ? (aw + Blue_off) : (aw + Red_off))(t, a, b, o, s); }
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
    frontdoor           = locked_frontdoor;
    locked_frontdoor[0] = locked_frontdoor_Yellow;
    locked_frontdoor[1] = locked_frontdoor_Green;
    locked_frontdoor[2] = locked_frontdoor_Red;
    locked_frontdoor[3] = locked_frontdoor_Blue;

    opened_frontdoor[0] = opened_frontdoor_Yellow;
    opened_frontdoor[1] = opened_frontdoor_Green;
    opened_frontdoor[2] = opened_frontdoor_Red;
    opened_frontdoor[3] = opened_frontdoor_Blue;

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
