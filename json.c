#include "tab.h"
#define So (unsigned char)s
#define Pos d

P(string);
P(string_ws) { Pos++, string(a, b, o, s, d); }
P(string_heart);
Tp(string, Gor, //
   ['"'] = string_heart, [0x09] = string_ws, [0x0A] = string_ws,
   [0x0D] = string_ws, [0x20] = string_ws) {
  string_tab[So[Pos]](a, b, o, s, d);
}
P(hex_end) { string_heart(a, b, o, s, d); }
P(bi_hex_end) { string_heart(a, b, o, s, d); }
P(tri_hex_end) { string_heart(a, b, o, s, d); }
P(quad_hex_end) { string_heart(a, b, o, s, d); }

Tab(hex_tab, tri_hex_end, //
    ['0'] = quad_hex_end, ['1'] = quad_hex_end, ['2'] = quad_hex_end,
    ['3'] = quad_hex_end, ['4'] = quad_hex_end, ['5'] = quad_hex_end,
    ['6'] = quad_hex_end, ['7'] = quad_hex_end, ['8'] = quad_hex_end,
    ['9'] = quad_hex_end, ['A'] = quad_hex_end, ['B'] = quad_hex_end,
    ['C'] = quad_hex_end, ['D'] = quad_hex_end, ['E'] = quad_hex_end,
    ['F'] = quad_hex_end, ['a'] = quad_hex_end, ['b'] = quad_hex_end,
    ['c'] = quad_hex_end, ['d'] = quad_hex_end, ['e'] = quad_hex_end,
    ['f'] = quad_hex_end);
P(hex) { Pos++, hex_tab[So[Pos]](a, b, o, s, d); }
Tab(bi_hex_tab, bi_hex_end, //
    ['0'] = hex, ['1'] = hex, ['2'] = hex, ['3'] = hex, ['4'] = hex,
    ['5'] = hex, ['6'] = hex, ['7'] = hex, ['8'] = hex, ['9'] = hex,
    ['A'] = hex, ['B'] = hex, ['C'] = hex, ['D'] = hex, ['E'] = hex,
    ['F'] = hex, ['a'] = hex, ['b'] = hex, ['c'] = hex, ['d'] = hex,
    ['e'] = hex, ['f'] = hex);
P(bi_hex) { Pos++, bi_hex_tab[So[Pos]](a, b, o, s, d); }
Tab(tri_hex_tab, hex_end, //
    ['0'] = bi_hex, ['1'] = bi_hex, ['2'] = bi_hex, ['3'] = bi_hex,
    ['4'] = bi_hex, ['5'] = bi_hex, ['6'] = bi_hex, ['7'] = bi_hex,
    ['8'] = bi_hex, ['9'] = bi_hex, ['A'] = bi_hex, ['B'] = bi_hex,
    ['C'] = bi_hex, ['D'] = bi_hex, ['E'] = bi_hex, ['F'] = bi_hex,
    ['a'] = bi_hex, ['b'] = bi_hex, ['c'] = bi_hex, ['d'] = bi_hex,
    ['e'] = bi_hex, ['f'] = bi_hex);
P(tri_hex) { Pos++, tri_hex_tab[So[Pos]](a, b, o, s, d); }
Tab(escape_quad_hex_tab, Got, //
    ['0'] = tri_hex, ['1'] = tri_hex, ['2'] = tri_hex, ['3'] = tri_hex,
    ['4'] = tri_hex, ['5'] = tri_hex, ['6'] = tri_hex, ['7'] = tri_hex,
    ['8'] = tri_hex, ['9'] = tri_hex, ['A'] = tri_hex, ['B'] = tri_hex,
    ['C'] = tri_hex, ['D'] = tri_hex, ['E'] = tri_hex, ['F'] = tri_hex,
    ['a'] = tri_hex, ['b'] = tri_hex, ['c'] = tri_hex, ['d'] = tri_hex,
    ['e'] = tri_hex, ['f'] = tri_hex);
P(escape_quad_hex /*        */) { Pos++, escape_quad_hex_tab[So[Pos]](a, b, o, s, d); }
P(escape_quot /*            */) { string_heart(a, b, o, s, d); }
P(escape_reverse_solidus /* */) { string_heart(a, b, o, s, d); }
P(escape_solidus /*         */) { string_heart(a, b, o, s, d); }
P(escape_backspace /*       */) { string_heart(a, b, o, s, d); }
P(escape_formfeed /*        */) { string_heart(a, b, o, s, d); }
P(escape_linefeed /*        */) { string_heart(a, b, o, s, d); }
P(escape_carriage_return /* */) { string_heart(a, b, o, s, d); }
P(escape_horizontal_tab /*  */) { string_heart(a, b, o, s, d); }

Tab(escape_tab, Got, //
    ['"'] = escape_quot, ['\\'] = escape_reverse_solidus,
    ['/'] = escape_solidus, ['b'] = escape_backspace, ['f'] = escape_formfeed,
    ['n'] = escape_linefeed, ['r'] = escape_carriage_return,
    ['t'] = escape_horizontal_tab, ['u'] = escape_quad_hex, );
P(escape) { Pos++, escape_tab[So[Pos]](a, b, o, s, d); }
P(string_end) { Pos++, God(a, b, o, s, d); }
Tab(string_heart_tab, string_heart, ['"'] = string_end, ['\\'] = escape);
P(string_heart) {
  Pos++;
  const char *str = o[--a].cs;
  // str
  string_heart_tab[So[Pos]](a, b, o, s, d);
}

P(number_digits);
Tab(number_digits_tab, God,
    ['0'] = number_digits, //
    ['1'] = number_digits, //
    ['2'] = number_digits, //
    ['3'] = number_digits, //
    ['4'] = number_digits, //
    ['5'] = number_digits, //
    ['6'] = number_digits, //
    ['7'] = number_digits, //
    ['8'] = number_digits, //
    ['9'] = number_digits);
P(number_digits) { Pos++, number_digits_tab[So[Pos]](a, b, o, s, d); }
Tab(number_exponent_sign_tab, Got,
    ['0'] = number_digits, //
    ['1'] = number_digits, //
    ['2'] = number_digits, //
    ['3'] = number_digits, //
    ['4'] = number_digits, //
    ['5'] = number_digits, //
    ['6'] = number_digits, //
    ['7'] = number_digits, //
    ['8'] = number_digits, //
    ['9'] = number_digits);
P(number_exponent_sign) {
  Pos++, number_exponent_sign_tab[So[Pos]](a, b, o, s, d);
}
Tab(number_exponent_tab, Got,     //
    ['+'] = number_exponent_sign, //
    ['-'] = number_exponent_sign, //
    ['0'] = number_digits, ['1'] = number_digits, ['2'] = number_digits,
    ['3'] = number_digits, ['4'] = number_digits, ['5'] = number_digits,
    ['6'] = number_digits, ['7'] = number_digits, ['8'] = number_digits,
    ['9'] = number_digits);
P(number_exponent) { Pos++, number_exponent_tab[So[Pos]](a, b, o, s, d); }

Tab(number_dot_tab, Got,     //
    ['E'] = number_exponent, //
    ['e'] = number_exponent, //
    ['0'] = number_digits, ['1'] = number_digits, ['2'] = number_digits,
    ['3'] = number_digits, ['4'] = number_digits, ['5'] = number_digits,
    ['6'] = number_digits, ['7'] = number_digits, ['8'] = number_digits,
    ['9'] = number_digits);
P(number_dot) { Pos++, number_dot_tab[So[Pos]](a, b, o, s, d); }
P(number_zero_start);
Tab(number_zero_start_tab, God, ['.'] = number_dot);
P(number_zero_start) { Pos++, number_zero_start_tab[So[Pos]](a, b, o, s, d); }
P(number_1to9_start);
Tab(number_1to9_start_tab, God, //
    ['.'] = number_dot,         //
    ['0'] = number_1to9_start, ['1'] = number_1to9_start,
    ['2'] = number_1to9_start, ['3'] = number_1to9_start,
    ['4'] = number_1to9_start, ['5'] = number_1to9_start,
    ['6'] = number_1to9_start, ['7'] = number_1to9_start,
    ['8'] = number_1to9_start, ['9'] = number_1to9_start);
P(number_1to9_start) { Pos++, number_1to9_start_tab[So[Pos]](a, b, o, s, d); }
Tab(number_minus_sign_start_tab, Got, //
    ['0'] = number_zero_start,        //
    ['1'] = number_1to9_start, ['2'] = number_1to9_start,
    ['3'] = number_1to9_start, ['4'] = number_1to9_start,
    ['5'] = number_1to9_start, ['6'] = number_1to9_start,
    ['7'] = number_1to9_start, ['8'] = number_1to9_start,
    ['9'] = number_1to9_start);
P(number_minus_sign_start) {
  Pos++, number_minus_sign_start_tab[So[Pos]](a, b, o, s, d);
}
P(whitespace);
P(whitespace_next) { Pos++, whitespace(a, b, o, s, d); }
Tab(whitespace_tab, God, [0x09] = whitespace_next, [0x0A] = whitespace_next,
    [0x0D] = whitespace_next, [0x20] = whitespace_next);
P(whitespace) { whitespace_tab[So[Pos]](a, b, o, s, d); }
P(value);
P(colon);
P(colon_end) { Pos++, God(a, b, o, s, d); }
P(colon_ws) { Pos++, colon(a, b, o, s, d); }
Tab(colon_tab, Got, //
    [':'] = colon_end, [0x09] = colon_ws, [0x0A] = colon_ws, [0x0D] = colon_ws,
    [0x20] = colon_ws);
P(colon) { colon_tab[So[Pos]](a, b, o, s, d); }
P(object_end) { Pos++, God(a, b, o, s, d); }
P(object_member);
P(object_comma) { Pos++, object_member(a, b, o, s, d); }
Tab(object_cross_tab, Got, [','] = object_comma, ['}'] = object_end);
P(object_cross) { object_cross_tab[So[Pos]](a, b, o, s, d); }
P(object_member) {
  T(Got,  object_cross,  Gor);
  T(Got,  value,         Gor);
  T(Got,  colon,         Gor);
  T(Got,  whitespace,    Gor);
  string(a, b, o, s, d);
}
P(object_heart);
Tab(object_heart_tab, object_member, //
    [ '}'] = object_end,             //
    [0x09] = object_heart,           //
    [0x0A] = object_heart,           //
    [0x0D] = object_heart,           //
    [0x20] = object_heart);
P(object_heart) { Pos++, object_heart_tab[So[Pos]](a, b, o, s, d); }
P(array_end) { Pos++, God(a, b, o, s, d); }
P(array_member);
P(array_comma) { Pos++, array_member(a, b, o, s, d); }
Tab(array_cross_tab, Got, [','] = array_comma, [']'] = array_end);
P(array_cross) { array_cross_tab[So[Pos]](a, b, o, s, d); }
P(array_member) {
  T(Got, array_cross, Gor);
  value(a, b, o, s, d);
}
P(array_heart);
Tab(array_heart_tab, array_member, //
    [']'] = array_end,             //
    [0x09] = array_heart,          //
    [0x0A] = array_heart,          //
    [0x0D] = array_heart,          //
    [0x20] = array_heart);
P(array_heart) { Pos++, array_heart_tab[So[Pos]](a, b, o, s, d); }
P(false) { Pos += 5, God(a, b, o, s, d); }
P(null) { Pos += 4, God(a, b, o, s, d); }
P(true) { Pos += 4, God(a, b, o, s, d); }
P(value_ws) { Pos++, value(a, b, o, s, d); }
Tab(value_tab, Got,                  //
    ['"'] = string_heart,            //
    ['-'] = number_minus_sign_start, //
    ['0'] = number_zero_start,       //
    ['1'] = number_1to9_start, ['2'] = number_1to9_start,
    ['3'] = number_1to9_start, ['4'] = number_1to9_start,
    ['5'] = number_1to9_start, ['6'] = number_1to9_start,
    ['7'] = number_1to9_start, ['8'] = number_1to9_start,
    ['9'] = number_1to9_start, //
    ['['] = array_heart,       //
    ['f'] = false,             //
    ['n'] = null,              //
    ['t'] = true,              //
    ['{'] = object_heart,      //
    [0x09] = value_ws, [0x0A] = value_ws, [0x0D] = value_ws, [0x20] = value_ws);
P(value) {
  T(Got, whitespace, Gor);
  T(Got, whitespace, Gor);
  T(Got, whitespace, Gor);
  value_tab[So[Pos]](a, b, o, s, d);
}
