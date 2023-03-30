#include "aword/rays.h"
R(Blue___) { Blue(o, a); }
R(Green__) { Green(o, a); }
R(Red____) { Red(o, a); }
R(Yellow_) { Yellow(o, a); }
R(Purple_) { Purple(o, a); }
R(Aqua___) { Aqua(o, a); }
R(Lime___) { Lime(o, a); }
R(Maroon_) { Maroon(o, a); }
typedef void (*t_t)(void **, long);
t_t (*load_tree)(const char *hash);
t_t t0;
R(Olive__) { (t0 - 16 * 4)(o, a); }
Ray(Pink___) {
  load_tree = o[2];
  o[a++] = Pink;
  o[a++] = Olive;
  t0 = load_tree("hash1");
  o[a++] = (t0 - 16 * 5);
  o[a++] = (t0 - 16 * 4);
  t0 = load_tree("hash2");
  o[a++] = (t0 - 16 * 5);
  o[a++] = (t0 - 16 * 4);
  t0 = load_tree("hash3");
  o[a++] = (t0 - 16 * 5);
  o[a++] = (t0 - 16 * 4);
  t0 = load_tree("hash4");
  o[a++] = (t0 - 16 * 5);
  o[a++] = (t0 - 16 * 4);
  (t0 - 16 * 5)(o, a);
}
