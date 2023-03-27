#include <stdio.h>
#include <unistd.h>
#define aword long a, long w, void **o, long r, long d
void b(aword);
void m(aword);
void hands(aword);
void sleepw(aword) { usleep(20000), m(a, w, o, r, d); }
void print(aword) { if (r == 1 && d == 3) puts(o[w + 1]); sleepw(a, w, o, r, d); }
void dot(aword) { m(a, w, o, r == 3 ? 1 : r, 3); }
int main() {
  long a = 512, w;
  void *o[a];
  long r = 3, d = 3;
  o[--a] = 0, o[--a] = b, o[--a] = 0;
  o[--a] = "a", o[--a] = print, o[--a] = 0;
  o[--a] = "b", o[--a] = print, o[--a] = 0;
  o[--a] = "o", o[--a] = print, o[--a] = 0;
  o[--a] = 0, o[w = --a] = dot, o[--a] = 0;
  m(a, w, o, r, d);
}
