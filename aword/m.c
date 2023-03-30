#include "rays.h"

Ray(Blue___) { P, Blue(o, a); }
Ray(Green__) { P, Green(o, a); }
Ray(Red____) { P, Red(o, a); }
Ray(Yellow_) { P, Yellow(o, a); }
Ray(Purple_) { P, Purple(o, a); }

Ray(Aqua___) { P, Aqua(o, a); }
Ray(Lime___) { P, Lime(o, a); }
Ray(Maroon_) { P, Maroon(o, a); }
typedef void (*t_t)(void **, long);
t_t (*load_tree)(const char *hash);
t_t t0;
Ray(Olive__) { P, (t0 - 16 * 4)(o, a); }
Ray(Pink___) {
  print = o[0];
  load_tree = o[2];
  o[a++] = Pink;
  o[a++] = Olive;
  t0 = load_tree("35b7fa6222f1b8e506ec9703beafa315fdad8cfa");
  print("\n%p\n", t0);
  o[a++] = (t0 - 16 * 5);
  o[a++] = (t0 - 16 * 4);
  t0 = load_tree("22fa3e345e89c33293ba9dfcd489d0f49f3e16d4");
  print("\n%p\n", t0);
  o[a++] = (t0 - 16 * 5);
  o[a++] = (t0 - 16 * 4);
  t0 = load_tree("883875c8562a9af5504de75d60712e706197364a");
  print("\n%p\n", t0);
  P, (t0 - 16 * 5)(o, a); // Pink(o, a);
}
