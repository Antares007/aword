#include "sword.h"
#include <stdio.h>
#include <unistd.h>
void m(long a, long w, void **o, long r, long d) {
  ((void (**)(long, long, void *, long, long))o)[w + d](a, w + d, o, r, d);
}
void b(long a, long w, void **o, long r, long d) { m(a, w, o, r, -3); }
static void dot(word) { m(a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, 3); }
void left_arm(word) {
  if (r == 1)
    m(a, (long)o[w - 1], o, 3, (long)o[w + 1]);
  else
    m(a, w, o, r == 3 ? 1 : r, 3);
}
void right_arm(word) {
  if (r == 1)
    o[(long)o[w - 1] + 1] = o[w + 1], m(a, (long)o[w - 1], o, 3, 3);
  else
    m(a, w, o, r == 3 ? 1 : r, 3);
}
void s(word) {
  if (d == -3)
    if (r == 1)
      m(a, (long)o[w + 1], o, 3, 3);
    else
      m(a, w, o, r == 3 ? 1 : r, 3);
  else if (r == 3)
    m(a, (long)o[w - 1], o, r, d);
  else
    m(a, w, o, r, -3);
}
void print(word) {
  if (r == 1 && d == -3)
    printf("%s", (char *)o[w + 1]), usleep(20000);
  m(a, w, o, r, d);
}
#include <assert.h>
S(toti, {
  T(b) Ta(print, "word")  T(toti) LastArm;
  T(b) Ta(print, "hello")         RightArm;
});

int main() {
  long a = 512;
  void *o[a];
  long r = 3, d = 3;
  T(b)                  //
    Ta(print, "7")      //
    T(toti)             //
    Ta(print, "\n")     //
  T(dot)                //
  m(a, a + 1, o, r, d); //
  return 0;
}
