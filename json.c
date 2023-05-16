#include "tab.h"
P(string);
P(string_ws) { d++, string(a, b, o, s, d); }
P(string_heart);
Tab(string_tab, Gor, ['"'] = string_heart, [0x09] = string_ws,
    [0x0A] = string_ws, [0x0D] = string_ws, [0x20] = string_ws);
P(string) { string_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(hex_end) { string_heart(a, b, o, s, d); }
P(bi_hex_end) { string_heart(a, b, o, s, d); }
P(tri_hex_end) { string_heart(a, b, o, s, d); }
P(quad_hex_end) { string_heart(a, b, o, s, d); }
Tab(hex_tab, tri_hex_end, ['0'] = quad_hex_end, ['1'] = quad_hex_end,
    ['2'] = quad_hex_end, ['3'] = quad_hex_end, ['4'] = quad_hex_end,
    ['5'] = quad_hex_end, ['6'] = quad_hex_end, ['7'] = quad_hex_end,
    ['8'] = quad_hex_end, ['9'] = quad_hex_end, ['A'] = quad_hex_end,
    ['B'] = quad_hex_end, ['C'] = quad_hex_end, ['D'] = quad_hex_end,
    ['E'] = quad_hex_end, ['F'] = quad_hex_end, ['a'] = quad_hex_end,
    ['b'] = quad_hex_end, ['c'] = quad_hex_end, ['d'] = quad_hex_end,
    ['e'] = quad_hex_end, ['f'] = quad_hex_end);
P(hex) { d++, hex_tab[(unsigned char)s[d]](a, b, o, s, d); }
Tab(bi_hex_tab, bi_hex_end, ['0'] = hex, ['1'] = hex, ['2'] = hex, ['3'] = hex,
    ['4'] = hex, ['5'] = hex, ['6'] = hex, ['7'] = hex, ['8'] = hex,
    ['9'] = hex, ['A'] = hex, ['B'] = hex, ['C'] = hex, ['D'] = hex,
    ['E'] = hex, ['F'] = hex, ['a'] = hex, ['b'] = hex, ['c'] = hex,
    ['d'] = hex, ['e'] = hex, ['f'] = hex);
P(bi_hex) { d++, bi_hex_tab[(unsigned char)s[d]](a, b, o, s, d); }
Tab(tri_hex_tab, hex_end, ['0'] = bi_hex, ['1'] = bi_hex, ['2'] = bi_hex,
    ['3'] = bi_hex, ['4'] = bi_hex, ['5'] = bi_hex, ['6'] = bi_hex,
    ['7'] = bi_hex, ['8'] = bi_hex, ['9'] = bi_hex, ['A'] = bi_hex,
    ['B'] = bi_hex, ['C'] = bi_hex, ['D'] = bi_hex, ['E'] = bi_hex,
    ['F'] = bi_hex, ['a'] = bi_hex, ['b'] = bi_hex, ['c'] = bi_hex,
    ['d'] = bi_hex, ['e'] = bi_hex, ['f'] = bi_hex);
P(tri_hex) { d++, tri_hex_tab[(unsigned char)s[d]](a, b, o, s, d); }
Tab(escape_quad_hex_tab, Got, ['0'] = tri_hex, ['1'] = tri_hex, ['2'] = tri_hex,
    ['3'] = tri_hex, ['4'] = tri_hex, ['5'] = tri_hex, ['6'] = tri_hex,
    ['7'] = tri_hex, ['8'] = tri_hex, ['9'] = tri_hex, ['A'] = tri_hex,
    ['B'] = tri_hex, ['C'] = tri_hex, ['D'] = tri_hex, ['E'] = tri_hex,
    ['F'] = tri_hex, ['a'] = tri_hex, ['b'] = tri_hex, ['c'] = tri_hex,
    ['d'] = tri_hex, ['e'] = tri_hex, ['f'] = tri_hex);
P(escape_quad_hex) {
  d++, escape_quad_hex_tab[(unsigned char)s[d]](a, b, o, s, d);
}
P(escape_quot) { string_heart(a, b, o, s, d); }
P(escape_reverse_solidus) { string_heart(a, b, o, s, d); }
P(escape_solidus) { string_heart(a, b, o, s, d); }
P(escape_backspace) { string_heart(a, b, o, s, d); }
P(escape_formfeed) { string_heart(a, b, o, s, d); }
P(escape_linefeed) { string_heart(a, b, o, s, d); }
P(escape_carriage_return) { string_heart(a, b, o, s, d); }
P(escape_horizontal_tab) { string_heart(a, b, o, s, d); }
Tab(escape_tab, Got, ['"'] = escape_quot, ['\\'] = escape_reverse_solidus,
    ['/'] = escape_solidus, ['b'] = escape_backspace, ['f'] = escape_formfeed,
    ['n'] = escape_linefeed, ['r'] = escape_carriage_return,
    ['t'] = escape_horizontal_tab, ['u'] = escape_quad_hex, );
P(escape) { d++, escape_tab[(unsigned char)s[d]](a, b, o, s, d); }
P(string_end) { d++, God(a, b, o, s, d); }
Tab(string_heart_tab, string_heart, ['"'] = string_end, ['\\'] = escape);
P(string_heart) {
  d++;
  string_heart_tab[(unsigned char)s[d]](a, b, o, s, d);
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
    ['"'] = string_heart,      //
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
