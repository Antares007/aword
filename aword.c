#include <stdio.h>
#include <unistd.h>
#define LOG (void)0//printf("%s %ld\n", __FUNCTION__, d), usleep(20000)
#define Got(o) LOG,((void (**)(long, long, void *, long, long))o)
void b(long a, long w, void **o, long r, long d) {
  Got(o)[w - 3](a, w - 3, o, r, -3);
}
void m(long a, long w, void **o, long r, long d) {
  Got(o)[w + d](a, w + d, o, r, d);
}
void dot(long a, long w, void **o, long r, long d) {
  Got(o)[w + 3](a, w + 3, o, r, 3);
}
int main() {
  long a = 0, w = 512;
  void *o[w];
  long r = 1, d = 3;
  o[--w] = 0, o[--w] = b, o[--w] = 0;
  o[--w] = 0, o[--w] = m, o[--w] = 0;
  o[--w] = 0, o[--w] = dot, o[--w] = 0;
  Got(o)[w + 4](a, w + 4, o, r, d);
}
