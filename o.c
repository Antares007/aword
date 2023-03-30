#include "aword/rays.h"

void (*Purple_cb)(void **o, long a);
void (*Green_cb)(void **o, long a);

Ray(Purple_) {P, Purple_cb(o, a); }
Ray(Yellow_) {P, Lime(o, a); }
Ray(Red____) {P, Red(o, a); }
Ray(Green__) {P, Green_cb(o, a); }
Ray(Blue___) {P, Blue(o, a); }

Ray(Aqua___) {}
Ray(Lime___) {}
Ray(Maroon_) {}
Ray(Olive__) {P, Olive(o, a); }
Ray(Pink___) {P, Green_cb = o[--a], Purple_cb = o[--a], Pink(o, a); }
