//  API-ებზე მუშაობა საჭიროებს ეფექტური პარსერის ქონას რათა დავზოგოთ
//  ელექტროენერგია, დრო და მნიშვნელოვნად გავამარტივოთ მათი დამუშავეპის პროცესი.
//
//  code
//  |  string
//  |  linecomment
//  |  blockcomment
//
//  block
//  |  '{' code '}'
//
//  whitespace          whitespace
//  |  " "              |  ""
//  |  whitespace " "   |  " " whitespace
//
//
#include "tab2.h"
#include <stdio.h>
#define L printf("%ld %s\n", d, __FUNCTION__)
P(Got) { o[b + 2].c(a, b + 3, o, s, d); }
P(God) { o[b + 1].c(a, b + 3, o, s, d); }
P(Gor) { o[b + 0].c(a, b + 3, o, s, d); }
P(Tot) { o[b + 2].o[(unsigned)s[d]].c(a, b + 3, o, s, d); }
P(Tod) { o[b + 1].o[(unsigned)s[d]].c(a, b + 3, o, s, d); }
P(Tor) { o[b + 0].o[(unsigned)s[d]].c(a, b + 3, o, s, d); }
P(dpp) { God(a, b, o, s, d + 1); }

P(whitespace);
Tab(ws_tab, Gor, [' '] = God);
Tab(dig1to9_tab, Gor,
    ['1'] = God, ['2'] = God, ['3'] = God, ['4'] = God,
    ['5'] = God, ['6'] = God, ['7'] = God, ['8'] = God,
    ['9'] = God);

P(whitespace) {
  T(Got, whitespace, Gor);
  T(Got, dpp, Gor);
  T(Got, ws_tab, Gor);
  Tod(a, b, o, s, d);
}
P(code) { T(Got, dot, Gor); }
P(name) { name_tab[(unsigned)s[d]](a, b, o, s, d); }
P(definition) {

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

  long a = 0, b = 1024;
  o_t o[b];
  T(not, and, oor);
  whitespace(a, b, o, "  ", 0);
}
