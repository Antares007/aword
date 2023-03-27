#include <stdio.h>
#include <unistd.h>
#define aword long a, long w, void **o, long r, long d
void m(aword) {
  ((void (**)(long, long, void *, long, long))o)[w + d](a, w + d, o, r, d);
}
void b(aword) { m(a, w, o, r, -3); }
void hands(aword);
void print(aword) {
  printf("%2ld %2ld %5s\n", r, d, (char *)o[w + 1]);
  usleep(20000);
  m(a, w, o, r, d);
}
void dot(aword) { m(a, w, o, r == 3 ? 1 : r, 3); }
int main() {
  long a = 512, w;
  void *o[a];
  long r = 3, d = 3;
  o[--a] = 0, o[--a] = b, o[--a] = 0;
  o[--a] = "a", o[--a] = print, o[--a] = 0;
  o[--a] = "w", o[--a] = print, o[--a] = 0;
  o[--a] = "o", o[--a] = print, o[--a] = 0;
  o[--a] = "r", o[--a] = print, o[--a] = 0;
  o[--a] = "d", o[--a] = print, o[--a] = 0;
  o[--a] = 0, o[w = --a] = dot, o[--a] = 0;
  m(a, w, o, r, d);
}
