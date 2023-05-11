#define P(arse) void arse(long a, long b, struct o_t *o)
typedef struct o_t {
  union {
    long q;
    unsigned long Q;
    void *v;
    const char *cs;
    P((*c));
  };
} o_t;
typedef P((*p_t));
P(Got) { o[b + 2].c(a, b + 3, o); }
P(God) { o[b + 1].c(a, b + 3, o); }
P(Gor) { o[b + 0].c(a, b + 3, o); }

P(codepoint) {
  o[a++].q = o[0].cs[o[2].q++];
  o[b + 1].c(a, b, o);
}
P(biend) {
  unsigned long b2 = o[0].cs[o[2].q++] & 0b00111111;
  unsigned long b1 = o[--a].Q;
  o[a++].Q = b1 << 6 | b2;
  o[b + 1].c(a, b, o);
}
P(triend) {
  unsigned long b3 = o[0].cs[o[2].q++] & 0b00111111;
  unsigned long b2 = o[--a].Q;
  unsigned long b1 = o[--a].Q;
  o[a++].Q = b1 << 12 | b2 << 6 | b3;
  o[b + 1].c(a, b, o);
}
P(quadend) {
  unsigned long b4 = o[0].cs[o[2].q++] & 0b00111111;
  unsigned long b3 = o[--a].Q;
  unsigned long b2 = o[--a].Q;
  unsigned long b1 = o[--a].Q;
  o[a++].Q = b1 << 18 | b2 << 12 | b3 << 6 | b4;
  o[b + 1].c(a, b, o);
}
extern p_t next_byte_cases[];
P(drop1) { a--, Gor(a, b, o); }
P(drop2) { a--, a--, Gor(a, b, o); }
P(drop3) { a--, a--, a--, Gor(a, b, o); }
P(bichar) {
  o[--b].c = drop1, o[--b].c = biend, o[--b].c = Gor;
  o[a++].q = o[0].cs[o[2].q++] & 0b00011111;
  next_byte_cases[(unsigned char)o[0].cs[o[2].q]](a, b, o);
}
P(nextchar) {
  o[a++].q = o[0].cs[o[2].q++] & 0b00111111;
  next_byte_cases[(unsigned char)o[0].cs[o[2].q]](a, b, o);
}
P(trichar) {
  o[--b].c = drop2, o[--b].c = triend, o[--b].c = Gor;
  o[--b].c = drop1, o[--b].c = nextchar, o[--b].c = Gor;
  o[a++].q = o[0].cs[o[2].q++] & 0b00001111;
  next_byte_cases[(unsigned char)o[0].cs[o[2].q]](a, b, o);
}
P(quadchar) {
  o[--b].c = drop3, o[--b].c = quadend, o[--b].c = Gor;
  o[--b].c = drop2, o[--b].c = nextchar, o[--b].c = Gor;
  o[--b].c = drop1, o[--b].c = nextchar, o[--b].c = Gor;
  o[a++].q = o[0].cs[o[2].q++] & 0b00000111;
  next_byte_cases[(unsigned char)o[0].cs[o[2].q]](a, b, o);
}
extern p_t starting_byte_cases[];
#include <stdio.h>
#define L (void)0 // printf("%ld %ld %s\n", o[1].q, Pos, __FUNCTION__)
P(utf) { starting_byte_cases[(unsigned char)o[0].cs[o[2].q]](a, b, o); }
#define T(i, n, a) o[--b].c = i, o[--b].c = n, o[--b].c = a
#define Tab(name, nar, ...)                                                    \
  P(name);                                                                     \
  static p_t name##_tab[] = {                                                  \
      [0] = nar,   [1] = nar,   [2] = nar,   [3] = nar,   [4] = nar,           \
      [5] = nar,   [6] = nar,   [7] = nar,   [8] = nar,   [9] = nar,           \
      [10] = nar,  [11] = nar,  [12] = nar,  [13] = nar,  [14] = nar,          \
      [15] = nar,  [16] = nar,  [17] = nar,  [18] = nar,  [19] = nar,          \
      [20] = nar,  [21] = nar,  [22] = nar,  [23] = nar,  [24] = nar,          \
      [25] = nar,  [26] = nar,  [27] = nar,  [28] = nar,  [29] = nar,          \
      [30] = nar,  [31] = nar,  [32] = nar,  [33] = nar,  [34] = nar,          \
      [35] = nar,  [36] = nar,  [37] = nar,  [38] = nar,  [39] = nar,          \
      [40] = nar,  [41] = nar,  [42] = nar,  [43] = nar,  [44] = nar,          \
      [45] = nar,  [46] = nar,  [47] = nar,  [48] = nar,  [49] = nar,          \
      [50] = nar,  [51] = nar,  [52] = nar,  [53] = nar,  [54] = nar,          \
      [55] = nar,  [56] = nar,  [57] = nar,  [58] = nar,  [59] = nar,          \
      [60] = nar,  [61] = nar,  [62] = nar,  [63] = nar,  [64] = nar,          \
      [65] = nar,  [66] = nar,  [67] = nar,  [68] = nar,  [69] = nar,          \
      [70] = nar,  [71] = nar,  [72] = nar,  [73] = nar,  [74] = nar,          \
      [75] = nar,  [76] = nar,  [77] = nar,  [78] = nar,  [79] = nar,          \
      [80] = nar,  [81] = nar,  [82] = nar,  [83] = nar,  [84] = nar,          \
      [85] = nar,  [86] = nar,  [87] = nar,  [88] = nar,  [89] = nar,          \
      [90] = nar,  [91] = nar,  [92] = nar,  [93] = nar,  [94] = nar,          \
      [95] = nar,  [96] = nar,  [97] = nar,  [98] = nar,  [99] = nar,          \
      [100] = nar, [101] = nar, [102] = nar, [103] = nar, [104] = nar,         \
      [105] = nar, [106] = nar, [107] = nar, [108] = nar, [109] = nar,         \
      [110] = nar, [111] = nar, [112] = nar, [113] = nar, [114] = nar,         \
      [115] = nar, [116] = nar, [117] = nar, [118] = nar, [119] = nar,         \
      [120] = nar, [121] = nar, [122] = nar, [123] = nar, [124] = nar,         \
      [125] = nar, [126] = nar, [127] = nar, [128] = nar, [129] = nar,         \
      [130] = nar, [131] = nar, [132] = nar, [133] = nar, [134] = nar,         \
      [135] = nar, [136] = nar, [137] = nar, [138] = nar, [139] = nar,         \
      [140] = nar, [141] = nar, [142] = nar, [143] = nar, [144] = nar,         \
      [145] = nar, [146] = nar, [147] = nar, [148] = nar, [149] = nar,         \
      [150] = nar, [151] = nar, [152] = nar, [153] = nar, [154] = nar,         \
      [155] = nar, [156] = nar, [157] = nar, [158] = nar, [159] = nar,         \
      [160] = nar, [161] = nar, [162] = nar, [163] = nar, [164] = nar,         \
      [165] = nar, [166] = nar, [167] = nar, [168] = nar, [169] = nar,         \
      [170] = nar, [171] = nar, [172] = nar, [173] = nar, [174] = nar,         \
      [175] = nar, [176] = nar, [177] = nar, [178] = nar, [179] = nar,         \
      [180] = nar, [181] = nar, [182] = nar, [183] = nar, [184] = nar,         \
      [185] = nar, [186] = nar, [187] = nar, [188] = nar, [189] = nar,         \
      [190] = nar, [191] = nar, [192] = nar, [193] = nar, [194] = nar,         \
      [195] = nar, [196] = nar, [197] = nar, [198] = nar, [199] = nar,         \
      [200] = nar, [201] = nar, [202] = nar, [203] = nar, [204] = nar,         \
      [205] = nar, [206] = nar, [207] = nar, [208] = nar, [209] = nar,         \
      [210] = nar, [211] = nar, [212] = nar, [213] = nar, [214] = nar,         \
      [215] = nar, [216] = nar, [217] = nar, [218] = nar, [219] = nar,         \
      [220] = nar, [221] = nar, [222] = nar, [223] = nar, [224] = nar,         \
      [225] = nar, [226] = nar, [227] = nar, [228] = nar, [229] = nar,         \
      [230] = nar, [231] = nar, [232] = nar, [233] = nar, [234] = nar,         \
      [235] = nar, [236] = nar, [237] = nar, [238] = nar, [239] = nar,         \
      [240] = nar, [241] = nar, [242] = nar, [243] = nar, [244] = nar,         \
      [245] = nar, [246] = nar, [247] = nar, [248] = nar, [249] = nar,         \
      [250] = nar, [251] = nar, [252] = nar, [253] = nar, [254] = nar,         \
      [255] = nar, __VA_ARGS__};                                               \
  P(name)

#define So (unsigned char)o[0].cs
#define Pos o[2].q

P(string);
P(string_ws) { L, Pos++, string(a, b, o); }
P(string_heart);
Tab(string, Gor, //
    ['"'] = string_heart, [0x09] = string_ws, [0x0A] = string_ws,
    [0x0D] = string_ws, [0x20] = string_ws) {
  L, string_tab[So[Pos]](a, b, o);
}
P(hex_end) { L, string_heart(a, b, o); }
P(bi_hex_end) { L, string_heart(a, b, o); }
P(tri_hex_end) { L, string_heart(a, b, o); }
P(quad_hex_end) { L, string_heart(a, b, o); }

Tab(hex, tri_hex_end, //
    ['0'] = quad_hex_end, ['1'] = quad_hex_end, ['2'] = quad_hex_end,
    ['3'] = quad_hex_end, ['4'] = quad_hex_end, ['5'] = quad_hex_end,
    ['6'] = quad_hex_end, ['7'] = quad_hex_end, ['8'] = quad_hex_end,
    ['9'] = quad_hex_end, ['A'] = quad_hex_end, ['B'] = quad_hex_end,
    ['C'] = quad_hex_end, ['D'] = quad_hex_end, ['E'] = quad_hex_end,
    ['F'] = quad_hex_end, ['a'] = quad_hex_end, ['b'] = quad_hex_end,
    ['c'] = quad_hex_end, ['d'] = quad_hex_end, ['e'] = quad_hex_end,
    ['f'] = quad_hex_end) {
  L, Pos++, hex_tab[So[Pos]](a, b, o);
}
Tab(bi_hex, bi_hex_end, //
    ['0'] = hex, ['1'] = hex, ['2'] = hex, ['3'] = hex, ['4'] = hex,
    ['5'] = hex, ['6'] = hex, ['7'] = hex, ['8'] = hex, ['9'] = hex,
    ['A'] = hex, ['B'] = hex, ['C'] = hex, ['D'] = hex, ['E'] = hex,
    ['F'] = hex, ['a'] = hex, ['b'] = hex, ['c'] = hex, ['d'] = hex,
    ['e'] = hex, ['f'] = hex) {
  L, Pos++, bi_hex_tab[So[Pos]](a, b, o);
}
Tab(tri_hex, hex_end, //
    ['0'] = bi_hex, ['1'] = bi_hex, ['2'] = bi_hex, ['3'] = bi_hex,
    ['4'] = bi_hex, ['5'] = bi_hex, ['6'] = bi_hex, ['7'] = bi_hex,
    ['8'] = bi_hex, ['9'] = bi_hex, ['A'] = bi_hex, ['B'] = bi_hex,
    ['C'] = bi_hex, ['D'] = bi_hex, ['E'] = bi_hex, ['F'] = bi_hex,
    ['a'] = bi_hex, ['b'] = bi_hex, ['c'] = bi_hex, ['d'] = bi_hex,
    ['e'] = bi_hex, ['f'] = bi_hex) {
  L, Pos++, tri_hex_tab[So[Pos]](a, b, o);
}
Tab(escape_quad_hex, Got, //
    ['0'] = tri_hex, ['1'] = tri_hex, ['2'] = tri_hex, ['3'] = tri_hex,
    ['4'] = tri_hex, ['5'] = tri_hex, ['6'] = tri_hex, ['7'] = tri_hex,
    ['8'] = tri_hex, ['9'] = tri_hex, ['A'] = tri_hex, ['B'] = tri_hex,
    ['C'] = tri_hex, ['D'] = tri_hex, ['E'] = tri_hex, ['F'] = tri_hex,
    ['a'] = tri_hex, ['b'] = tri_hex, ['c'] = tri_hex, ['d'] = tri_hex,
    ['e'] = tri_hex, ['f'] = tri_hex) {
  L, Pos++, escape_quad_hex_tab[So[Pos]](a, b, o);
}
P(escape_quot /*            */) { L, string_heart(a, b, o); }
P(escape_reverse_solidus /* */) { L, string_heart(a, b, o); }
P(escape_solidus /*         */) { L, string_heart(a, b, o); }
P(escape_backspace /*       */) { L, string_heart(a, b, o); }
P(escape_formfeed /*        */) { L, string_heart(a, b, o); }
P(escape_linefeed /*        */) { L, string_heart(a, b, o); }
P(escape_carriage_return /* */) { L, string_heart(a, b, o); }
P(escape_horizontal_tab /*  */) { L, string_heart(a, b, o); }
Tab(escape, Got, //
    ['"'] = escape_quot, ['\\'] = escape_reverse_solidus,
    ['/'] = escape_solidus, ['b'] = escape_backspace, ['f'] = escape_formfeed,
    ['n'] = escape_linefeed, ['r'] = escape_carriage_return,
    ['t'] = escape_horizontal_tab, ['u'] = escape_quad_hex, ) {
  L, Pos++, escape_tab[So[Pos]](a, b, o);
}
P(string_end) { L, Pos++, God(a, b, o); }
Tab(string_heart, string_heart, ['"'] = string_end, ['\\'] = escape) {
  L, Pos++, string_heart_tab[So[Pos]](a, b, o);
}
Tab(number_digits, God,
    ['0'] = number_digits, //
    ['1'] = number_digits, //
    ['2'] = number_digits, //
    ['3'] = number_digits, //
    ['4'] = number_digits, //
    ['5'] = number_digits, //
    ['6'] = number_digits, //
    ['7'] = number_digits, //
    ['8'] = number_digits, //
    ['9'] = number_digits) {
  L, Pos++, number_digits_tab[So[Pos]](a, b, o);
}
Tab(number_exponent_sign, Got,
    ['0'] = number_digits, //
    ['1'] = number_digits, //
    ['2'] = number_digits, //
    ['3'] = number_digits, //
    ['4'] = number_digits, //
    ['5'] = number_digits, //
    ['6'] = number_digits, //
    ['7'] = number_digits, //
    ['8'] = number_digits, //
    ['9'] = number_digits) {
  L, Pos++, number_exponent_sign_tab[So[Pos]](a, b, o);
}
Tab(number_exponent, Got,         //
    ['+'] = number_exponent_sign, //
    ['-'] = number_exponent_sign, //
    ['0'] = number_digits, ['1'] = number_digits, ['2'] = number_digits,
    ['3'] = number_digits, ['4'] = number_digits, ['5'] = number_digits,
    ['6'] = number_digits, ['7'] = number_digits, ['8'] = number_digits,
    ['9'] = number_digits) {
  L, Pos++, number_exponent_tab[So[Pos]](a, b, o);
}

Tab(number_dot, Got,         //
    ['E'] = number_exponent, //
    ['e'] = number_exponent, //
    ['0'] = number_digits, ['1'] = number_digits, ['2'] = number_digits,
    ['3'] = number_digits, ['4'] = number_digits, ['5'] = number_digits,
    ['6'] = number_digits, ['7'] = number_digits, ['8'] = number_digits,
    ['9'] = number_digits, ) {
  L, Pos++, number_dot_tab[So[Pos]](a, b, o);
}
Tab(number_zero_start, God, ['.'] = number_dot) {
  L, Pos++, number_zero_start_tab[So[Pos]](a, b, o);
}
Tab(number_1to9_start, God, //
    ['.'] = number_dot,     //
    ['0'] = number_1to9_start, ['1'] = number_1to9_start,
    ['2'] = number_1to9_start, ['3'] = number_1to9_start,
    ['4'] = number_1to9_start, ['5'] = number_1to9_start,
    ['6'] = number_1to9_start, ['7'] = number_1to9_start,
    ['8'] = number_1to9_start, ['9'] = number_1to9_start) {
  L, Pos++, number_1to9_start_tab[So[Pos]](a, b, o);
}
Tab(number_minus_sign_start, Got, //
    ['0'] = number_zero_start,    //
    ['1'] = number_1to9_start, ['2'] = number_1to9_start,
    ['3'] = number_1to9_start, ['4'] = number_1to9_start,
    ['5'] = number_1to9_start, ['6'] = number_1to9_start,
    ['7'] = number_1to9_start, ['8'] = number_1to9_start,
    ['9'] = number_1to9_start) {
  L, Pos++, number_minus_sign_start_tab[So[Pos]](a, b, o);
}

P(whitespace);
P(whitespace_next) { L, Pos++, whitespace(a, b, o); }
Tab(whitespace, God, [0x09] = whitespace_next, [0x0A] = whitespace_next,
    [0x0D] = whitespace_next, [0x20] = whitespace_next) {
  L, whitespace_tab[So[Pos]](a, b, o);
}
P(value);
P(colon);
P(colon_end) { Pos++, God(a, b, o); }
P(colon_ws) { Pos++, colon(a, b, o); }
Tab(colon, Got, //
    [':'] = colon_end, [0x09] = colon_ws, [0x0A] = colon_ws, [0x0D] = colon_ws,
    [0x20] = colon_ws) {
  L, colon_tab[So[Pos]](a, b, o);
}
P(object_end) { L, Pos++, God(a, b, o); }
P(object_member);
P(object_comma) { L, Pos++, object_member(a, b, o); }
Tab(object_cross, Got, //
    [','] = object_comma, ['}'] = object_end, ) {
  L, object_cross_tab[So[Pos]](a, b, o);
}
P(object_member) {
  L;
  T(Got, object_cross, Gor);
  T(Got, value, Gor);
  T(Got, colon, Gor);
  T(Got, whitespace, Gor);
  string(a, b, o);
}
Tab(object_heart, object_member, //
    ['}'] = object_end,          //
    [0x09] = object_heart,       //
    [0x0A] = object_heart,       //
    [0x0D] = object_heart,       //
    [0x20] = object_heart) {
  L, Pos++, object_heart_tab[So[Pos]](a, b, o);
}
P(array_end) { L, Pos++, God(a, b, o); }
P(array_member);
P(array_comma) { L, Pos++, array_member(a, b, o); }
Tab(array_cross, Got, //
    [','] = array_comma, [']'] = array_end, ) {
  L, array_cross_tab[So[Pos]](a, b, o);
}
P(array_member) {
  L;
  T(Got, array_cross, Gor);
  value(a, b, o);
}
Tab(array_heart, array_member, //
    [']'] = array_end,         //
    [0x09] = array_heart,      //
    [0x0A] = array_heart,      //
    [0x0D] = array_heart,      //
    [0x20] = array_heart) {
  L, Pos++, array_heart_tab[So[Pos]](a, b, o);
}
P(false) { L, Pos += 5, God(a, b, o); }
P(null) { L, Pos += 4, God(a, b, o); }
P(true) { L, Pos += 4, God(a, b, o); }
P(ws_value) {
  L;
  Pos++, value(a, b, o);
}
Tab(value, Got,                      //
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
    [0x09] = ws_value, [0x0A] = ws_value, [0x0D] = ws_value,
    [0x20] = ws_value) {
  L;
  T(Got, whitespace, Gor);
  value_tab[(unsigned)So[Pos]](a, b, o);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
double getTime();

P(not ) { printf("not\n"); }
P(and) { printf("and %ld %ld\n", o[1].q, o[2].q); }
P(oor) { printf("oor\n"); }
P(Main) {
  double startTime = getTime();
  value(a, b, o);
  double endTime = getTime();
  double executionTime = endTime - startTime;
  printf("Execution time: %f seconds\n", executionTime);
}

int main() {
  char str[1 * 1024 * 1024];
  FILE *fp = fopen("../twitter.json", "rb");
  long length = fread(str, 1, sizeof(str) / sizeof(*str), fp);
  str[length] = 0;
  fclose(fp);
  printf("%ld\n", length);

  o_t o[1024];
  long a = 0, b = 1024;
  o[--b].c = not ;
  o[--b].c = and;
  o[--b].c = oor;
  o[a++].cs = str;
  o[a++].q = strlen(str);
  o[a++].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
  o[2].q = 0, Main(a, b, o);
}
double getTime() { struct timespec time;
  clock_gettime(CLOCK_MONOTONIC, &time);
  return (double)time.tv_sec + (double)time.tv_nsec / 1000000000.0;
}
p_t starting_byte_cases[] = {
    [0b00000000] = codepoint, [0b00000001] = codepoint,
    [0b00000010] = codepoint, [0b00000011] = codepoint,
    [0b00000100] = codepoint, [0b00000101] = codepoint,
    [0b00000110] = codepoint, [0b00000111] = codepoint,
    [0b00001000] = codepoint, [0b00001001] = codepoint,
    [0b00001010] = codepoint, [0b00001011] = codepoint,
    [0b00001100] = codepoint, [0b00001101] = codepoint,
    [0b00001110] = codepoint, [0b00001111] = codepoint,
    [0b00010000] = codepoint, [0b00010001] = codepoint,
    [0b00010010] = codepoint, [0b00010011] = codepoint,
    [0b00010100] = codepoint, [0b00010101] = codepoint,
    [0b00010110] = codepoint, [0b00010111] = codepoint,
    [0b00011000] = codepoint, [0b00011001] = codepoint,
    [0b00011010] = codepoint, [0b00011011] = codepoint,
    [0b00011100] = codepoint, [0b00011101] = codepoint,
    [0b00011110] = codepoint, [0b00011111] = codepoint,
    [0b00100000] = codepoint, [0b00100001] = codepoint,
    [0b00100010] = codepoint, [0b00100011] = codepoint,
    [0b00100100] = codepoint, [0b00100101] = codepoint,
    [0b00100110] = codepoint, [0b00100111] = codepoint,
    [0b00101000] = codepoint, [0b00101001] = codepoint,
    [0b00101010] = codepoint, [0b00101011] = codepoint,
    [0b00101100] = codepoint, [0b00101101] = codepoint,
    [0b00101110] = codepoint, [0b00101111] = codepoint,
    [0b00110000] = codepoint, [0b00110001] = codepoint,
    [0b00110010] = codepoint, [0b00110011] = codepoint,
    [0b00110100] = codepoint, [0b00110101] = codepoint,
    [0b00110110] = codepoint, [0b00110111] = codepoint,
    [0b00111000] = codepoint, [0b00111001] = codepoint,
    [0b00111010] = codepoint, [0b00111011] = codepoint,
    [0b00111100] = codepoint, [0b00111101] = codepoint,
    [0b00111110] = codepoint, [0b00111111] = codepoint,
    [0b01000000] = codepoint, [0b01000001] = codepoint,
    [0b01000010] = codepoint, [0b01000011] = codepoint,
    [0b01000100] = codepoint, [0b01000101] = codepoint,
    [0b01000110] = codepoint, [0b01000111] = codepoint,
    [0b01001000] = codepoint, [0b01001001] = codepoint,
    [0b01001010] = codepoint, [0b01001011] = codepoint,
    [0b01001100] = codepoint, [0b01001101] = codepoint,
    [0b01001110] = codepoint, [0b01001111] = codepoint,
    [0b01010000] = codepoint, [0b01010001] = codepoint,
    [0b01010010] = codepoint, [0b01010011] = codepoint,
    [0b01010100] = codepoint, [0b01010101] = codepoint,
    [0b01010110] = codepoint, [0b01010111] = codepoint,
    [0b01011000] = codepoint, [0b01011001] = codepoint,
    [0b01011010] = codepoint, [0b01011011] = codepoint,
    [0b01011100] = codepoint, [0b01011101] = codepoint,
    [0b01011110] = codepoint, [0b01011111] = codepoint,
    [0b01100000] = codepoint, [0b01100001] = codepoint,
    [0b01100010] = codepoint, [0b01100011] = codepoint,
    [0b01100100] = codepoint, [0b01100101] = codepoint,
    [0b01100110] = codepoint, [0b01100111] = codepoint,
    [0b01101000] = codepoint, [0b01101001] = codepoint,
    [0b01101010] = codepoint, [0b01101011] = codepoint,
    [0b01101100] = codepoint, [0b01101101] = codepoint,
    [0b01101110] = codepoint, [0b01101111] = codepoint,
    [0b01110000] = codepoint, [0b01110001] = codepoint,
    [0b01110010] = codepoint, [0b01110011] = codepoint,
    [0b01110100] = codepoint, [0b01110101] = codepoint,
    [0b01110110] = codepoint, [0b01110111] = codepoint,
    [0b01111000] = codepoint, [0b01111001] = codepoint,
    [0b01111010] = codepoint, [0b01111011] = codepoint,
    [0b01111100] = codepoint, [0b01111101] = codepoint,
    [0b01111110] = codepoint, [0b01111111] = codepoint,
    [0b10000000] = Gor,       [0b10000001] = Gor,
    [0b10000010] = Gor,       [0b10000011] = Gor,
    [0b10000100] = Gor,       [0b10000101] = Gor,
    [0b10000110] = Gor,       [0b10000111] = Gor,
    [0b10001000] = Gor,       [0b10001001] = Gor,
    [0b10001010] = Gor,       [0b10001011] = Gor,
    [0b10001100] = Gor,       [0b10001101] = Gor,
    [0b10001110] = Gor,       [0b10001111] = Gor,
    [0b10010000] = Gor,       [0b10010001] = Gor,
    [0b10010010] = Gor,       [0b10010011] = Gor,
    [0b10010100] = Gor,       [0b10010101] = Gor,
    [0b10010110] = Gor,       [0b10010111] = Gor,
    [0b10011000] = Gor,       [0b10011001] = Gor,
    [0b10011010] = Gor,       [0b10011011] = Gor,
    [0b10011100] = Gor,       [0b10011101] = Gor,
    [0b10011110] = Gor,       [0b10011111] = Gor,
    [0b10100000] = Gor,       [0b10100001] = Gor,
    [0b10100010] = Gor,       [0b10100011] = Gor,
    [0b10100100] = Gor,       [0b10100101] = Gor,
    [0b10100110] = Gor,       [0b10100111] = Gor,
    [0b10101000] = Gor,       [0b10101001] = Gor,
    [0b10101010] = Gor,       [0b10101011] = Gor,
    [0b10101100] = Gor,       [0b10101101] = Gor,
    [0b10101110] = Gor,       [0b10101111] = Gor,
    [0b10110000] = Gor,       [0b10110001] = Gor,
    [0b10110010] = Gor,       [0b10110011] = Gor,
    [0b10110100] = Gor,       [0b10110101] = Gor,
    [0b10110110] = Gor,       [0b10110111] = Gor,
    [0b10111000] = Gor,       [0b10111001] = Gor,
    [0b10111010] = Gor,       [0b10111011] = Gor,
    [0b10111100] = Gor,       [0b10111101] = Gor,
    [0b10111110] = Gor,       [0b10111111] = Gor,
    [0b11000000] = bichar,    [0b11000001] = bichar,
    [0b11000010] = bichar,    [0b11000011] = bichar,
    [0b11000100] = bichar,    [0b11000101] = bichar,
    [0b11000110] = bichar,    [0b11000111] = bichar,
    [0b11001000] = bichar,    [0b11001001] = bichar,
    [0b11001010] = bichar,    [0b11001011] = bichar,
    [0b11001100] = bichar,    [0b11001101] = bichar,
    [0b11001110] = bichar,    [0b11001111] = bichar,
    [0b11010000] = bichar,    [0b11010001] = bichar,
    [0b11010010] = bichar,    [0b11010011] = bichar,
    [0b11010100] = bichar,    [0b11010101] = bichar,
    [0b11010110] = bichar,    [0b11010111] = bichar,
    [0b11011000] = bichar,    [0b11011001] = bichar,
    [0b11011010] = bichar,    [0b11011011] = bichar,
    [0b11011100] = bichar,    [0b11011101] = bichar,
    [0b11011110] = bichar,    [0b11011111] = bichar,
    [0b11100000] = trichar,   [0b11100001] = trichar,
    [0b11100010] = trichar,   [0b11100011] = trichar,
    [0b11100100] = trichar,   [0b11100101] = trichar,
    [0b11100110] = trichar,   [0b11100111] = trichar,
    [0b11101000] = trichar,   [0b11101001] = trichar,
    [0b11101010] = trichar,   [0b11101011] = trichar,
    [0b11101100] = trichar,   [0b11101101] = trichar,
    [0b11101110] = trichar,   [0b11101111] = trichar,
    [0b11110000] = quadchar,  [0b11110001] = quadchar,
    [0b11110010] = quadchar,  [0b11110011] = quadchar,
    [0b11110100] = quadchar,  [0b11110101] = quadchar,
    [0b11110110] = quadchar,  [0b11110111] = quadchar,
    [0b11111000] = Gor,       [0b11111001] = Gor,
    [0b11111010] = Gor,       [0b11111011] = Gor,
    [0b11111100] = Gor,       [0b11111101] = Gor,
    [0b11111110] = Gor,       [0b11111111] = Gor,
};
p_t next_byte_cases[] = {
    [0b00000000] = Got, [0b00000001] = Got, [0b00000010] = Got,
    [0b00000011] = Got, [0b00000100] = Got, [0b00000101] = Got,
    [0b00000110] = Got, [0b00000111] = Got, [0b00001000] = Got,
    [0b00001001] = Got, [0b00001010] = Got, [0b00001011] = Got,
    [0b00001100] = Got, [0b00001101] = Got, [0b00001110] = Got,
    [0b00001111] = Got, [0b00010000] = Got, [0b00010001] = Got,
    [0b00010010] = Got, [0b00010011] = Got, [0b00010100] = Got,
    [0b00010101] = Got, [0b00010110] = Got, [0b00010111] = Got,
    [0b00011000] = Got, [0b00011001] = Got, [0b00011010] = Got,
    [0b00011011] = Got, [0b00011100] = Got, [0b00011101] = Got,
    [0b00011110] = Got, [0b00011111] = Got, [0b00100000] = Got,
    [0b00100001] = Got, [0b00100010] = Got, [0b00100011] = Got,
    [0b00100100] = Got, [0b00100101] = Got, [0b00100110] = Got,
    [0b00100111] = Got, [0b00101000] = Got, [0b00101001] = Got,
    [0b00101010] = Got, [0b00101011] = Got, [0b00101100] = Got,
    [0b00101101] = Got, [0b00101110] = Got, [0b00101111] = Got,
    [0b00110000] = Got, [0b00110001] = Got, [0b00110010] = Got,
    [0b00110011] = Got, [0b00110100] = Got, [0b00110101] = Got,
    [0b00110110] = Got, [0b00110111] = Got, [0b00111000] = Got,
    [0b00111001] = Got, [0b00111010] = Got, [0b00111011] = Got,
    [0b00111100] = Got, [0b00111101] = Got, [0b00111110] = Got,
    [0b00111111] = Got, [0b01000000] = Got, [0b01000001] = Got,
    [0b01000010] = Got, [0b01000011] = Got, [0b01000100] = Got,
    [0b01000101] = Got, [0b01000110] = Got, [0b01000111] = Got,
    [0b01001000] = Got, [0b01001001] = Got, [0b01001010] = Got,
    [0b01001011] = Got, [0b01001100] = Got, [0b01001101] = Got,
    [0b01001110] = Got, [0b01001111] = Got, [0b01010000] = Got,
    [0b01010001] = Got, [0b01010010] = Got, [0b01010011] = Got,
    [0b01010100] = Got, [0b01010101] = Got, [0b01010110] = Got,
    [0b01010111] = Got, [0b01011000] = Got, [0b01011001] = Got,
    [0b01011010] = Got, [0b01011011] = Got, [0b01011100] = Got,
    [0b01011101] = Got, [0b01011110] = Got, [0b01011111] = Got,
    [0b01100000] = Got, [0b01100001] = Got, [0b01100010] = Got,
    [0b01100011] = Got, [0b01100100] = Got, [0b01100101] = Got,
    [0b01100110] = Got, [0b01100111] = Got, [0b01101000] = Got,
    [0b01101001] = Got, [0b01101010] = Got, [0b01101011] = Got,
    [0b01101100] = Got, [0b01101101] = Got, [0b01101110] = Got,
    [0b01101111] = Got, [0b01110000] = Got, [0b01110001] = Got,
    [0b01110010] = Got, [0b01110011] = Got, [0b01110100] = Got,
    [0b01110101] = Got, [0b01110110] = Got, [0b01110111] = Got,
    [0b01111000] = Got, [0b01111001] = Got, [0b01111010] = Got,
    [0b01111011] = Got, [0b01111100] = Got, [0b01111101] = Got,
    [0b01111110] = Got, [0b01111111] = Got, [0b10000000] = God,
    [0b10000001] = God, [0b10000010] = God, [0b10000011] = God,
    [0b10000100] = God, [0b10000101] = God, [0b10000110] = God,
    [0b10000111] = God, [0b10001000] = God, [0b10001001] = God,
    [0b10001010] = God, [0b10001011] = God, [0b10001100] = God,
    [0b10001101] = God, [0b10001110] = God, [0b10001111] = God,
    [0b10010000] = God, [0b10010001] = God, [0b10010010] = God,
    [0b10010011] = God, [0b10010100] = God, [0b10010101] = God,
    [0b10010110] = God, [0b10010111] = God, [0b10011000] = God,
    [0b10011001] = God, [0b10011010] = God, [0b10011011] = God,
    [0b10011100] = God, [0b10011101] = God, [0b10011110] = God,
    [0b10011111] = God, [0b10100000] = God, [0b10100001] = God,
    [0b10100010] = God, [0b10100011] = God, [0b10100100] = God,
    [0b10100101] = God, [0b10100110] = God, [0b10100111] = God,
    [0b10101000] = God, [0b10101001] = God, [0b10101010] = God,
    [0b10101011] = God, [0b10101100] = God, [0b10101101] = God,
    [0b10101110] = God, [0b10101111] = God, [0b10110000] = God,
    [0b10110001] = God, [0b10110010] = God, [0b10110011] = God,
    [0b10110100] = God, [0b10110101] = God, [0b10110110] = God,
    [0b10110111] = God, [0b10111000] = God, [0b10111001] = God,
    [0b10111010] = God, [0b10111011] = God, [0b10111100] = God,
    [0b10111101] = God, [0b10111110] = God, [0b10111111] = God,
    [0b11000000] = Got, [0b11000001] = Got, [0b11000010] = Got,
    [0b11000011] = Got, [0b11000100] = Got, [0b11000101] = Got,
    [0b11000110] = Got, [0b11000111] = Got, [0b11001000] = Got,
    [0b11001001] = Got, [0b11001010] = Got, [0b11001011] = Got,
    [0b11001100] = Got, [0b11001101] = Got, [0b11001110] = Got,
    [0b11001111] = Got, [0b11010000] = Got, [0b11010001] = Got,
    [0b11010010] = Got, [0b11010011] = Got, [0b11010100] = Got,
    [0b11010101] = Got, [0b11010110] = Got, [0b11010111] = Got,
    [0b11011000] = Got, [0b11011001] = Got, [0b11011010] = Got,
    [0b11011011] = Got, [0b11011100] = Got, [0b11011101] = Got,
    [0b11011110] = Got, [0b11011111] = Got, [0b11100000] = Got,
    [0b11100001] = Got, [0b11100010] = Got, [0b11100011] = Got,
    [0b11100100] = Got, [0b11100101] = Got, [0b11100110] = Got,
    [0b11100111] = Got, [0b11101000] = Got, [0b11101001] = Got,
    [0b11101010] = Got, [0b11101011] = Got, [0b11101100] = Got,
    [0b11101101] = Got, [0b11101110] = Got, [0b11101111] = Got,
    [0b11110000] = Got, [0b11110001] = Got, [0b11110010] = Got,
    [0b11110011] = Got, [0b11110100] = Got, [0b11110101] = Got,
    [0b11110110] = Got, [0b11110111] = Got, [0b11111000] = Got,
    [0b11111001] = Got, [0b11111010] = Got, [0b11111011] = Got,
    [0b11111100] = Got, [0b11111101] = Got, [0b11111110] = Got,
    [0b11111111] = Got,
};
