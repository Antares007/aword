#include "tab.h"
#include <stdio.h>
#define LOG printf("%s %s %ld\n", __FUNCTION__, s, d)
P(not) { LOG; }
P(and) { LOG; }
P(oor) { LOG; }

P(aies_next);
Tab(aies_tab, God, ['a'] = aies_next);
P(aies_next) { d++, aies_tab[(unsigned char)s[d]](a, b, o, s, d); }

Tab(S_tab, Got, ['b'] = aies_next);
P(Sa) { S_tab[(unsigned char)s[d]](a, b, o, s, d); }
// #define CAT_(a, b) a##b
// #define CAT(a, b) CAT_(a, b)
// #define S(T, A, B, C, H) P(CAT(dna, H)) { \
//   o[a++].v = (void*)T;                    \
//   o[a++].v = (void*)A;                    \
//   o[a++].v = (void*)B;                    \
//   o[a++].v = (void*)C;                    \
//   o[a++].v = (void*)H;                    \
// }
// #define L __LINE__
// P(E);
//                     S(Got,
//   E,  '+',    E,  L)S(L,
//   E,  '-',    E,  L)S(L,
//   E,  '*',    E,  L)S(L,
//   E,  '/',    E,  L)S(L,
// '(',    E,  ')',  L)S(L,
// '0',  God,  God,  L)S(L,
// '1',  God,  God,  E)
/*  E + E
    E - E
    E * E
    E / E
    ( E )
    0
    1 */
P(E);
Tab(Eend_tab, E, [')'] = God);
P(Eend  ) { d++, Eend_tab[(unsigned char)s[d]](a, b, o, s, d); }
Tab(Eheart_tab, E, //
    ['+'] = Eend,
    ['-'] = Eend,
    ['*'] = Eend,
    ['/'] = Eend,
    );
P(Eheart) { d++, Eheart_tab[(unsigned char)s[d]](a, b, o, s, d); }

P(E_next) { E(a, b, o, s, d + 1); }
Tab(E_tab, Got, //
    ['('] = E_next,
    ['0'] = God,
    ['1'] = God,
    );
P(E     ) { E_tab[(unsigned char)s[d]](a, b, o, s, d); }

int main() {
  o_t o[1024];
  long a = 0, b = 1024, d = 0;
  T(not, and, oor);
  E(a, b, o, "1", d);
}
