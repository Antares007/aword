#include "tab.h"
#include <stdio.h>
#include <string.h>
#define L printf("%4ld %4ld %3ld %s\n", a, b, d, __FUNCTION__)
#define Tab2(name, default_nar, ...)                                           \
  P(name);                                                                     \
  P(name##_next);                                                              \
  Tab(name##_tab, default_nar, __VA_ARGS__);                                   \
  P(name##_next) { name##_tab[(unsigned)s[d + 1]](a, b, o, s, d + 1); }        \
  P(name) { name##_tab[(unsigned)s[d]](a, b, o, s, d); }
P(code) {
  L;
  o[a++].q = d;
  if (s[d] == '{') {
    long ob = 1;
    d++;
    while (ob) {
      if (s[d] == '{')
        ob++;
      else if (s[d] == '}')
        ob--;
      else if (s[d] == '"')
        do
          d++;
        while (s[d - 1] == '\\' || s[d] != '"');
      else if (s[d] == '/' && s[d + 1] == '*')
        do
          d++;
        while (s[d - 1] != '*' || s[d] != '/');
      else if (s[d] == '/' && s[d + 1] == '/')
        do
          d++;
        while (s[d] != '\n');
      d++;
    }
    o[a++].q = d;
    God(a, b, o, s, d);
  } else
    Gor(a, b, o, s, d);
}
Tab2(whitespace, God, //
     [0x09] = whitespace_next, [0x0A] = whitespace_next,
     [0x0D] = whitespace_next, [0x20] = whitespace_next);
P(name) {
  L;
  if (s[d] < 0x21)
    Gor(a, b, o, s, d);
  else {
    o[a++].q = d;
    while (0x20 < s[d])
      d++;
    o[a++].q = d;
    God(a, b, o, s, d);
  }
}
P(dot) {
  if (s[d] == '.')
    (o[a++].q = d), (o[a++].q = d + 1), God(a, b, o, s, d + 1);
  else
    Gor(a, b, o, s, d);
}
P(write_definition) {
  L;
  long p5 = o[--a].q;
  long p4 = o[--a].q;
  long p3 = o[--a].q;
  long p2 = o[--a].q;
  long p1 = o[--a].q;
  long p0 = o[--a].q;
  printf("%ld-%ld %ld-%ld %ld-%ld\n", p0, p1, p2, p3, p4, p5);
  char buf[1000];
  snprintf(buf, p1 - p0 + 1, "%s", s + p0), printf("%s\n", buf);
  snprintf(buf, p3 - p2 + 1, "%s", s + p2), printf("%s\n", buf);
  God(a, b, o, s, d);
}
P(definition) {
  T(Got,  definition,        Gor);
  T(Got,  write_definition,  Gor);
  T(Got,  dot,               Gor);
  T(Got,  code,              Gor);
  T(Got,  whitespace,        Gor);
  T(Got,  name,              Gor);
  whitespace(a, b, o, s, d);
}
P(run) {
  L;
  definition(a, b, o, s, d);
}
P(not ) { L; }
P(and) { L; }
P(oor) { L; }
int main() {
  char str[1 * 1024 * 1024];
  FILE *fp = fopen("../input.tab", "rb");
  long length = fread(str, 1, sizeof(str) / sizeof(*str), fp);
  str[length] = 0;
  fclose(fp);
  printf("%ld\n", length);

  o_t o[1024];
  long a = 0, b = 1024;
  o[--b].c = not, o[--b].c = and, o[--b].c = oor;
  run(a, b, o, str, 0);
}
