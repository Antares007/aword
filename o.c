#include "aword/rays.h"

void (*Purple_cb)(void **o, long a);
void (*Green_cb)(void **o, long a);

Ray(Purple_) { Purple_cb(o, a); }
Ray(Yellow_) { Lime(o, a); }
Ray(Red____) { Red(o, a); }
Ray(Green__) { Green_cb(o, a); }
Ray(Blue___) { Blue(o, a); }

Ray(Aqua___) {}
Ray(Lime___) {}
Ray(Maroon_) {}
Ray(Olive__) { Olive(o, a); }
Ray(Pink___) { Green_cb = o[--a], Purple_cb = o[--a], Pink(o, a); }
