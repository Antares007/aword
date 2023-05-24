#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
N(m);
N(b) { (o[0].q = 1), m(t, a, w, o, r, +TW, s); }
N(dot) { m(t, a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, Black(=), s); }
N(A ) {  m(t, a, w, o, r, d, s); }
N(B ) {  m(t, a, w, o, r, d, s); }
N(O ) {  m(t, a, w, o, r, d, s); }

N(print) {
  if (Green(==) && White(==))
    printf("%s", o[w + 1].cs);
  m(t, a, w, o, r, d, s);
}
N(tab);
N(tab) {
  if (Yellow(==))
    m(t, a, o[s + 0].q, o, o[s + 2].q, o[s + 1].q, s + 3);
  else if (Red(==) || Blue(==))
    m(t, a, o[s + 0].q, o,          r, o[s + 1].q, s + 3);
  else
    m(t, a, w, o, r, White(=), s);
}
N(var_heart) {
  if (Green(==) && White(==)) {
    o[--s].q = r;
    o[--s].q = d;
    o[--s].q = w;
    long *ps = o[w - 1].v;
    long count = ps[-2];
    long index = ps[-1];
    ps[-1] += o[0].q;
    long was_last_index = ps[-1] / count;
    o[0].q = was_last_index;
    ps[-1] = ps[-1] - was_last_index * count;
    m(t, a, ps[index], o, Yellow(=), White(=), s);
  } else
    m(t, a, w, o, r, d, s);
}
N(noun) {
  if (Green(==) && Black(==))
    o[t++].v = o[w + 1].v;
  m(t, a, w, o, r, d, s);
}
#include<string.h>
N(print_s) {
  if (Green(==) && White(==)) {
    const char*str = o[--t].cs;
    long len = strlen(str);
    printf("%s %ld\n", str, len);
    if(!len) return;  
  }
  m(t, a, w, o, r, d, s);
}
N(term) {
  if (Green(==) && White(==)) {
    if(o[t - 1].cs[0] == o[w + 1].cs[0]) {
      o[t - 1].cs++, m(t, a, w, o, r, d, s);
    } else m(t, a, w, o, 0, d, s);
  } else
    m(t, a, w, o, r, d, s);
}
N(S) {
  long p0 = (a + 2); T(tab), T(B),       Ta(term, "b"), T(dot);
  long p1 = (a + 2); T(tab), T(A), T(S), Ta(term, "a"), T(dot);
  o[w - 1].v = (long[]){2, 0, p0, p1} + 2;
  o[w].c = var_heart;
  var_heart(t, a, w, o, r, d, s);
}

void text_index_init();
int main() {
  long a = 0;
  o_t o[512];
  o[a++].q = 1;
  long r = Yellow(=), d = White(=), s = 512;
  long w = a + 2;
  long t = 256;
  text_index_init();
  T(b), Ta(noun, "baaa"), T(S), T(print_s), T(dot),
      m(t, a, w, o, r, d, s);
  return 0;
}
