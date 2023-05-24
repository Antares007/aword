#include "aword.h"
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
N(m);
N(b) { (o[0].q = 1), m(t, a, w, o, r, +TW, s); }
N(dot) { m(t, a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, Black(=), s); }
N(tina  ) { if (Green(==) && Black(==)) o[t++].cs = "თინა";  m(t, a, w, o, r, d, s); }
N(kargi ) { if (Green(==) && Black(==)) o[t++].cs = "კარგი"; m(t, a, w, o, r, d, s); }
N(gogoa ) { if (Green(==) && Black(==)) o[t++].cs = "გოგოა"; m(t, a, w, o, r, d, s); }

N(print) {
  if (Green(==) && White(==))
    printf("%s", o[w + 1].cs);
  m(t, a, w, o, r, d, s);
}
N(tab);
N(tab) {
  if (Yellow(==))
    m(t, a, o[s + 0].q, o, o[s + 2].q, o[s + 1].q, s + 3);
  else
    m(t, a, w, o, r, White(=), s);
}
N(var_heart) {
  if (Green(==) && Black(==)) {
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
N(S) {
  long p0 = (a + 2); T(tab), T(tina), T(dot);
  long p1 = (a + 2); T(tab), T(kargi), T(dot);
  long p2 = (a + 2); T(tab), T(gogoa), T(dot);
  o[w - 1].v = (long[]){3, 0, p0, p1, p2} + 2;
  o[w].c = var_heart;
  var_heart(t, a, w, o, r, d, s);
}
N(print_sss) {
  if (Green(==) && White(==)) {
    const char*s1 = o[--t].cs;
    const char*s2 = o[--t].cs;
    const char*s3 = o[--t].cs;
    printf("%s %s %s\n", s1, s2, s3);
  }
  m(t, a, w, o, r, d, s);
}
void text_index_init();
N(one) {
  if (Green(==) && Black(==))
    o[t++].q = 1;
  m(t, a, w, o, r, d, s);
}
N(plus) {
  if (Green(==) && White(==)) {
    long r = o[--t].q;
    long l = o[--t].q;
    o[t++].q = l + r;
  }
  m(t, a, w, o, r, d, s);
}
N(and);
N(two) {
  long p0 = (a + 2); T(tab), T(one), T(one), T(plus), T(dot);
  long p1 = (a + 2); T(tab), T(one), T(one), T(plus), T(and), T(one), T(plus), T(dot);
  o[w - 1].v = (long[]){2, 0, p0, p1} + 2;
  o[w].c = var_heart;
  var_heart(t, a, w, o, r, d, s);
}
N(print_l) {
  if (Green(==) && White(==)) {
    long l = o[--t].q;
    printf("%ld\n", l);
  }
  m(t, a, w, o, r, d, s);
}
N(Show) {
  T(b), T(S), T(S), T(S), T(print_sss), T(dot), m(t, a, w, o, r, d, s);
  //T(b), T(plus), T(two), T(two), T(and), T(print_l), T(dot), m(t, a, w, o, r, d, s);
}

int main() {
  long a = 0;
  o_t o[4096];
  o[a++].q = 1;
  long r = Yellow(=), d = White(=), s = 4096;
  long w = a + 2;
  long t = 2048;
  text_index_init();
  Show(t, a, w, o, r, d, s);
  return 0;
}
