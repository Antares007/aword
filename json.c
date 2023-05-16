#include "tab.h"
P(string_next);
P(quad_hex_end_n) { (o[b].cs[0] = (s[d] - '0' + 0x0)), o[b].cs++, string_next(a, b, o, s, d); }
P(quad_hex_end_A) { (o[b].cs[0] = (s[d] - 'A' + 0xA)), o[b].cs++, string_next(a, b, o, s, d); }
P(quad_hex_end_a) { (o[b].cs[0] = (s[d] - 'a' + 0xa)), o[b].cs++, string_next(a, b, o, s, d); }
Tab(hex_tab, Got, //
    ['0'] = quad_hex_end_n, ['1'] = quad_hex_end_n, ['2'] = quad_hex_end_n,
    ['3'] = quad_hex_end_n, ['4'] = quad_hex_end_n, ['5'] = quad_hex_end_n,
    ['6'] = quad_hex_end_n, ['7'] = quad_hex_end_n, ['8'] = quad_hex_end_n,
    ['9'] = quad_hex_end_n, ['A'] = quad_hex_end_A, ['B'] = quad_hex_end_A,
    ['C'] = quad_hex_end_A, ['D'] = quad_hex_end_A, ['E'] = quad_hex_end_A,
    ['F'] = quad_hex_end_A, ['a'] = quad_hex_end_a, ['b'] = quad_hex_end_a,
    ['c'] = quad_hex_end_a, ['d'] = quad_hex_end_a, ['e'] = quad_hex_end_a,
    ['f'] = quad_hex_end_a);
P(hex_n) { (o[b].cs[0] = (s[d] - '0' + 0x0)), o[b].cs++; d++, hex_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(hex_A) { (o[b].cs[0] = (s[d] - 'A' + 0xA)), o[b].cs++; d++, hex_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(hex_a) { (o[b].cs[0] = (s[d] - 'a' + 0xa)), o[b].cs++; d++, hex_tab[(unsigned char)s[d]](a, b, o, s, d); }
Tab(bi_hex_tab, Got, //
    ['0'] = hex_n, ['1'] = hex_n, ['2'] = hex_n, ['3'] = hex_n, ['4'] = hex_n,
    ['5'] = hex_n, ['6'] = hex_n, ['7'] = hex_n, ['8'] = hex_n, ['9'] = hex_n,
    ['A'] = hex_A, ['B'] = hex_A, ['C'] = hex_A, ['D'] = hex_A, ['E'] = hex_A,
    ['F'] = hex_A, ['a'] = hex_a, ['b'] = hex_a, ['c'] = hex_a, ['d'] = hex_a,
    ['e'] = hex_a, ['f'] = hex_a);
P(bi_hex_n) { (o[b].cs[0] = (s[d] - '0' + 0x0)), o[b].cs++; d++, bi_hex_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(bi_hex_A) { (o[b].cs[0] = (s[d] - 'A' + 0xA)), o[b].cs++; d++, bi_hex_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(bi_hex_a) { (o[b].cs[0] = (s[d] - 'a' + 0xa)), o[b].cs++; d++, bi_hex_tab[(unsigned char)s[d]](a, b, o, s, d); }
Tab(tri_hex_tab, Got, //
    ['0'] = bi_hex_n, ['1'] = bi_hex_n, ['2'] = bi_hex_n, ['3'] = bi_hex_n,
    ['4'] = bi_hex_n, ['5'] = bi_hex_n, ['6'] = bi_hex_n, ['7'] = bi_hex_n,
    ['8'] = bi_hex_n, ['9'] = bi_hex_n, ['A'] = bi_hex_A, ['B'] = bi_hex_A,
    ['C'] = bi_hex_A, ['D'] = bi_hex_A, ['E'] = bi_hex_A, ['F'] = bi_hex_A,
    ['a'] = bi_hex_a, ['b'] = bi_hex_a, ['c'] = bi_hex_a, ['d'] = bi_hex_a,
    ['e'] = bi_hex_a, ['f'] = bi_hex_a);
P(tri_hex_n) {
  (o[b].cs[0] = (s[d] - '0' + 0x0));
  o[b].cs++;
  d++;
  tri_hex_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(tri_hex_A) {
  (o[b].cs[0] = (s[d] - 'A' + 0xA));
  o[b].cs++;
  d++;
  tri_hex_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(tri_hex_a) {
  (o[b].cs[0] = (s[d] - 'a' + 0xa));
  o[b].cs++;
  d++;
  tri_hex_tab[(unsigned char)s[d]](a, b, o, s, d);
}
Tab(escape_quad_hex_tab, Got, //
    ['0'] = tri_hex_n, ['1'] = tri_hex_n, ['2'] = tri_hex_n, ['3'] = tri_hex_n,
    ['4'] = tri_hex_n, ['5'] = tri_hex_n, ['6'] = tri_hex_n, ['7'] = tri_hex_n,
    ['8'] = tri_hex_n, ['9'] = tri_hex_n, ['A'] = tri_hex_A, ['B'] = tri_hex_A,
    ['C'] = tri_hex_A, ['D'] = tri_hex_A, ['E'] = tri_hex_A, ['F'] = tri_hex_A,
    ['a'] = tri_hex_a, ['b'] = tri_hex_a, ['c'] = tri_hex_a, ['d'] = tri_hex_a,
    ['e'] = tri_hex_a, ['f'] = tri_hex_a);
P(escape_quad_hex       ) { d++, escape_quad_hex_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(string_heart          );
P(escape_quot           ) { (o[b].cs[0] = '"' ), o[b].cs++, string_heart(a, b, o, s, d); }
P(escape_reverse_solidus) { (o[b].cs[0] = '\\'), o[b].cs++, string_heart(a, b, o, s, d); }
P(escape_solidus        ) { (o[b].cs[0] = '/' ), o[b].cs++, string_heart(a, b, o, s, d); }
P(escape_backspace      ) { (o[b].cs[0] = '\b'), o[b].cs++, string_heart(a, b, o, s, d); }
P(escape_formfeed       ) { (o[b].cs[0] = '\f'), o[b].cs++, string_heart(a, b, o, s, d); }
P(escape_linefeed       ) { (o[b].cs[0] = '\n'), o[b].cs++, string_heart(a, b, o, s, d); }
P(escape_carriage_return) { (o[b].cs[0] = '\r'), o[b].cs++, string_heart(a, b, o, s, d); }
P(escape_horizontal_tab ) { (o[b].cs[0] = '\t'), o[b].cs++, string_heart(a, b, o, s, d); }
Tab(escape_tab, Got,                 //
    ['"'] = escape_quot,             //
    ['\\'] = escape_reverse_solidus, //
    ['/'] = escape_solidus,          //
    ['b'] = escape_backspace,        //
    ['f'] = escape_formfeed,         //
    ['n'] = escape_linefeed,         //
    ['r'] = escape_carriage_return,  //
    ['t'] = escape_horizontal_tab,   //
    ['u'] = escape_quad_hex);
P(escape) { d++, escape_tab[(unsigned char)s[d]](a, b, o, s, d); }
#define ALIGN(O, A) ((unsigned long)(((O) + ((A)-1)) / (A))) * (A)
P(string_end) {
  o[b].cs[0] = 0;
  long length = o[b++].cs - (char *)&o[a] - 1;
  a += length / sizeof(void *) + 1;
  o[a++].q = length;
  o[a++].q = 5;
  God(a, b, o, s, d + 1);
}
Tab(string_heart_tab, string_heart, //
    ['"'] = string_end, ['\\'] = escape);

P(string_next ) { d++, string_heart_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(string_heart) { (o[b].cs[0] = s[d]), o[b].cs++, string_next(a, b, o, s, d); }
P(string      );
P(string_ws   ) { d++, string(a, b, o, s, d); }
Tab(string_tab, Gor, ['"'] = string_heart, [0x09] = string_ws,
    [0x0A] = string_ws, [0x0D] = string_ws, [0x20] = string_ws);
P(string) { string_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(string_start) {
  o[--b].cs = (void *)&o[a];
  string_heart(a, b, o, s, d);
}
P(number_fraction_exp_end) {
  long exp = o[--a].q;
  double multiplier = o[--a].n;
  double whole = o[--a].n;
  while (exp)
    (whole = whole * multiplier), exp--;
  o[a++].n = whole;
  God(a, b, o, s, d);
}
P(number_fraction_exp_next);
Tab(number_fraction_exp_next_tab, number_fraction_exp_end, //
    ['0'] = number_fraction_exp_next, ['1'] = number_fraction_exp_next,
    ['2'] = number_fraction_exp_next, ['3'] = number_fraction_exp_next,
    ['4'] = number_fraction_exp_next, ['5'] = number_fraction_exp_next,
    ['6'] = number_fraction_exp_next, ['7'] = number_fraction_exp_next,
    ['8'] = number_fraction_exp_next, ['9'] = number_fraction_exp_next);
P(number_fraction_exp_next) {
  o[a - 1].q = o[a - 1].q * 10 + ((unsigned char)s[d] - '0');
  d++, number_fraction_exp_next_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(number_fraction_exp_minus_sign) {
  o[a - 2].n = 0.1;
  d++, number_fraction_exp_next_tab[(unsigned char)s[d]](a, b, o, s, d);
}
Tab(number_fraction_exp_tab, Got,           //
    ['+'] = number_fraction_exp_next,       //
    ['-'] = number_fraction_exp_minus_sign, //
    ['0'] = number_fraction_exp_next, ['1'] = number_fraction_exp_next,
    ['2'] = number_fraction_exp_next, ['3'] = number_fraction_exp_next,
    ['4'] = number_fraction_exp_next, ['5'] = number_fraction_exp_next,
    ['6'] = number_fraction_exp_next, ['7'] = number_fraction_exp_next,
    ['8'] = number_fraction_exp_next, ['9'] = number_fraction_exp_next);
P(number_fraction_exp) {
  o[a++].n = 10;
  o[a++].q = 0;
  d++, number_fraction_exp_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(number_whole_end);
P(number_fraction_end) {
  a--;
  number_whole_end(a, b, o, s, d);
}
P(number_fraction_end_exp) {
  T(Got, number_fraction_exp, Gor);
  number_fraction_end(a, b, o, s, d);
}
P(number_fraction_next);
Tab(number_fraction_tab, number_fraction_end, //
    ['E'] = number_fraction_end_exp,          //
    ['e'] = number_fraction_end_exp,          //
    ['0'] = number_fraction_next, ['1'] = number_fraction_next,
    ['2'] = number_fraction_next, ['3'] = number_fraction_next,
    ['4'] = number_fraction_next, ['5'] = number_fraction_next,
    ['6'] = number_fraction_next, ['7'] = number_fraction_next,
    ['8'] = number_fraction_next, ['9'] = number_fraction_next);
P(number_fraction) {
  o[a++].n = 0.1;
  d++, number_fraction_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(number_fraction_next) {
  o[a - 2].n = o[a - 2].n + ((unsigned char)s[d] - '0') * o[a - 1].n;
  o[a - 1].n *= 0.1;
  d++, number_fraction_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(number_whole_end) {
  double whole = o[--a].n;
  double sign = o[--a].n;
  o[a++].n = whole * sign;
  God(a, b, o, s, d);
}
Tab(number_zero_tab, number_whole_end, //
    ['.'] = number_fraction,           //
    ['0'] = Got, ['1'] = Got, ['2'] = Got, ['3'] = Got, ['4'] = Got,
    ['5'] = Got, ['6'] = Got, ['7'] = Got, ['8'] = Got, ['9'] = Got);
P(number_0) {
  o[a++].n = +1;
  o[a++].n = 0;
  d++, number_zero_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(number_zero_next) {
  d++, number_zero_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(number_whole_end_fraction) {
  T(Got, number_fraction_exp, Gor);
  number_whole_end(a, b, o, s, d);
}
P(number_whole_next);
Tab(number_whole_tab, number_whole_end, //
    ['.'] = number_fraction,            //
    ['E'] = number_whole_end_fraction,  //
    ['e'] = number_whole_end_fraction,  //
    ['0'] = number_zero_next,           //
    ['1'] = number_whole_next, ['2'] = number_whole_next,
    ['3'] = number_whole_next, ['4'] = number_whole_next,
    ['5'] = number_whole_next, ['6'] = number_whole_next,
    ['7'] = number_whole_next, ['8'] = number_whole_next,
    ['9'] = number_whole_next);
P(number_minus_sign) {
  o[a++].n = -1;
  o[a++].n = 0;
  d++, number_whole_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(number_19) {
  o[a++].n = +1;
  o[a++].n = (unsigned char)s[d] - '0';
  d++, number_whole_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(number_whole_next) {
  o[a - 1].n = o[a - 1].n * 10.0 + ((unsigned char)s[d] - '0');
  d++, number_whole_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(whitespace);
P(whitespace_next) { d++, whitespace(a, b, o, s, d); }
Tab(whitespace_tab, God, //
    [0x09] = whitespace_next, [0x0A] = whitespace_next,
    [0x0D] = whitespace_next, [0x20] = whitespace_next);
P(whitespace) { whitespace_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(value);
P(colon);
P(colon_end) { d++, God(a, b, o, s, d); }
P(colon_ws) { d++, colon(a, b, o, s, d); }
Tab(colon_tab, Got,    //
    [':'] = colon_end, //
    [0x09] = colon_ws, [0x0A] = colon_ws, [0x0D] = colon_ws, [0x20] = colon_ws);
P(colon) { colon_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(object_end) { d++, God(a, b, o, s, d); }
P(object_member);
P(object_comma) { d++, object_member(a, b, o, s, d); }
Tab(object_cross_tab, Got, //
    [','] = object_comma, ['}'] = object_end);
P(object_cross) { object_cross_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(object_member) {
  T(Got, object_cross, Gor);
  T(Got, value, Gor);
  T(Got, colon, Gor);
  T(Got, whitespace, Gor);
  string(a, b, o, s, d);
}
P(object_heart);
Tab(object_heart_tab, object_member, //
    ['}'] = object_end,              //
    [0x09] = object_heart, [0x0A] = object_heart, [0x0D] = object_heart,
    [0x20] = object_heart);
P(object_heart) { d++, object_heart_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(array_end) { d++, God(a, b, o, s, d); }
P(array_member);
P(array_comma) { d++, array_member(a, b, o, s, d); }
Tab(array_cross_tab, Got, //
    [','] = array_comma, [']'] = array_end);
P(array_cross) { array_cross_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(array_member) {
  T(Got, array_cross, Gor);
  value(a, b, o, s, d);
}
P(array_heart);
Tab(array_heart_tab, array_member, //
    [']'] = array_end, [0x09] = array_heart, [0x0A] = array_heart,
    [0x0D] = array_heart, [0x20] = array_heart);
P(array_heart) { d++, array_heart_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(false) { d += 5, God(a, b, o, s, d); }
P(null) { d += 4, God(a, b, o, s, d); }
P(true) { d += 4, God(a, b, o, s, d); }
P(value_ws) { d++, value(a, b, o, s, d); }
Tab(value_tab, Got,            //
    ['"'] = string_start,      //
    ['-'] = number_minus_sign, //
    ['0'] = number_0,          //
    ['1'] = number_19, ['2'] = number_19, ['3'] = number_19, ['4'] = number_19,
    ['5'] = number_19, ['6'] = number_19, ['7'] = number_19, ['8'] = number_19,
    ['9'] = number_19,    //
    ['['] = array_heart,  //
    ['f'] = false,        //
    ['n'] = null,         //
    ['t'] = true,         //
    ['{'] = object_heart, //
    [0x09] = value_ws, [0x0A] = value_ws, [0x0D] = value_ws, [0x20] = value_ws);
P(value) {
  T(Got, whitespace, Gor);
  value_tab[(unsigned char)s[d]](a, b, o, s, d);
}
