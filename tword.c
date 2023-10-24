#include "aw.h"
#define COUNT 0
static void init() {}
long arms_count = COUNT;
n_t arms[COUNT];
const char *arm_texts[COUNT];
char fruitful[COUNT];
long ai;
n_t Tab_Yellow[6];
n_t Tab_Green[6];
n_t Tab_Red[6];
n_t Tab_Blue[6];

N(switch_arm) {
  long narm = ai + 1;
  long charge = narm / arms_count;
  ai = narm - charge * arms_count;
  if (arms[ai])
    ((n_t)o[a - charge])(t, a - 1, b, o, s);
  else
    (arms[ai] = Bark(arm_texts[ai])), (o[--b] = o[a-- - charge]),
        (o[a + 0] = (void *)__FILE__), (o[a + 1] = (void *)0),
        (arms[ai](t, a, b, o, s));
}
n_t *frontdoor, *backdoor;
n_t locked_frontdoor[4];
n_t opened_frontdoor[4];

N(opened_frontdoor_Yellow) {
  (o[--b] = Tab_Yellow), (arms[ai] + 32)(t, a, b, o, s);
}
N(opened_frontdoor_Green) {
  (o[--b] = Tab_Green), (arms[ai] + 64)(t, a, b, o, s);
}
N(opened_frontdoor_Red) { (o[--b] = Tab_Red), (arms[ai] + 96)(t, a, b, o, s); }
N(opened_frontdoor_Blue) {
  (o[--b] = Tab_Blue), (arms[ai] + 128)(t, a, b, o, s);
}

N(locked_frontdoor_Yellow) {
  (frontdoor = opened_frontdoor), opened_frontdoor_Yellow(t, a, b, o, s);
}
N(locked_frontdoor_Green) {
  (frontdoor = opened_frontdoor), opened_frontdoor_Green(t, a, b, o, s);
}
N(locked_frontdoor_Red) { Red(t, a, b, o, s); }
N(locked_frontdoor_Blue) { Blue(t, a, b, o, s); }

R(Yellow) { frontdoor[0](t, a, b, o, s); }
R(Green) { frontdoor[1](t, a, b, o, s); }
R(Red) { frontdoor[2](t, a, b, o, s); }
R(Blue) { frontdoor[3](t, a, b, o, s); }

N(Yellow_proxy) { Yellow(t, a, b, o, s); }
N(Green_proxy) { Green(t, a, b, o, s); }
N(Yellow_yellow) {
  fruitful[ai] = 1;
  (o[a++] = Yellow_proxy), (o[a] = Green_proxy), switch_arm(t, a, b, o, s);
}
N(Yellow_green) {
  fruitful[ai] = 1;
  Green(t, a, b, o, s);
}
N(Red_trim) {
  if (1 < arms_count)
    arms_count--, Unbark(arms[arms_count], ((long *)arms[arms_count])[1]),
        Red(t, a, b, o, s);
  else
    maroon(t, a, b, o, s);
}
N(Blue_trim) {
  arms_count--;
  ai--;
  Unbark(arms[ai], ((long *)arms[ai])[1]);
  for (long i = ai; i < arms_count; i++) {
    arms[i] = arms[i + 1];
    arm_texts[i] = arm_texts[i + 1];
    fruitful[i] = fruitful[i + 1];
  }
  Blue(t, a, b, o, s);
}
N(Yellow_red) {
  if (fruitful[ai])
    (o[a++] = Red), (o[a] = Blue);
  else
    (o[a++] = Red_trim), (o[a] = Blue_trim);
  switch_arm(t, a, b, o, s);
}
N(Yellow_blue) { Blue(t, a, b, o, s); }
N(Green_green) { Yellow_green(t, a, b, o, s); }
N(Green_blue) { Blue(t, a, b, o, s); }
N(Red_red) { (o[a++] = Red), (o[a] = Blue), switch_arm(t, a, b, o, s); }
N(Red_blue) { Blue(t, a, b, o, s); }
N(Blue_blue) { Blue(t, a, b, o, s); }
N(stop) { P; }

n_t yellow_proxy;
G(yellow) { yellow_proxy(t, a, b, o, s); }
n_t red_proxy;
G(red) { red_proxy(t, a, b, o, s); }

G(Purple) {
  init();
  if (CMP(o[a], __FILE__) == 0 && (long)o[a + 1] == 0) {
    ((long *)o)[a + 1]++;
    yellow_proxy = green;
    red_proxy = yellow;
    frontdoor = locked_frontdoor;
    locked_frontdoor[0] = Yellow;
    locked_frontdoor[1] = Green;
    locked_frontdoor[2] = Red;
    locked_frontdoor[3] = Blue;
  } else {
    yellow_proxy = yellow;
    red_proxy = red;
    frontdoor = locked_frontdoor;
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
  arms[0] = Bark(arm_texts[0]);
  (o[--b] = Purple);
  arms[0](t, a, b, o, s);
}
