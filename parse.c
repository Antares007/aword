#include "tab.h"
#include <stdio.h>
#include <string.h>
#define L printf("%ld %s\n", o[a - 1].q, __FUNCTION__)
#define So (unsigned char)o[0].cs
#define Pos o[a - 1].q

P(code) {
  L;
  const char *s = o[0].cs;
  long p = o[a - 1].q;
  if (s[p] == '{') {
    long ob = 1;
    p++;
    while (ob) {
      if (s[p] == '{')
        ob++;
      else if (s[p] == '}')
        ob--;
      else if (s[p] == '"')
        do
          p++;
        while (s[p - 1] == '\\' || s[p] != '"');
      else if (s[p] == '/' && s[p + 1] == '*')
        do
          p++;
        while (s[p - 1] != '*' || s[p] != '/');
      else if (s[p] == '/' && s[p + 1] == '/')
        do
          p++;
        while (s[p] != '\n');
      p++;
    }
    p++;
    o[a++].q = p;
    God(a, b, o);
  } else
    Gor(a, b, o);
}
P(whitespace) {
  L;
  const char *s = o[0].cs;
  long p = o[a - 1].q;
  while (s[p] == 0x20 || s[p] == 0xA || s[p] == 0xD || s[p] == 0x9)
    p++;
  o[a++].q = p;
  God(a, b, o);
}
P(name) {
  L;
  const char *s = o[0].cs;
  long p = o[a - 1].q;
  if (s[p] < 0x21)
    Gor(a, b, o);
  else {
    while (0x20 < s[p])
      p++;
    o[a++].q = p;
    God(a, b, o);
  }
}
P(dot) {
  const char *s = o[0].cs;
  long p = o[a - 1].q;
  if (s[p] == '.')
    (o[a++].q = ++p), God(a, b, o);
  else
    Gor(a, b, o);
}
P(definition) {
  T(Got, dot, Gor);
  T(Got, code, Gor);
  T(Got, whitespace, Gor);
  T(Got, name, Gor);
  whitespace(a, b, o);
}
P(run) {
  L;
  definition(a, b, o);
}
P(not ) { L, printf("not\n"); }
P(and) { L, printf("and %ld\n", o[a - 1].q); }
P(oor) { L, printf("oor %ld\n", o[a - 1].q); }
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
  o[a++].v = str;
  o[a++].q = 0;
  run(a, b, o);
}
