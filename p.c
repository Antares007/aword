#include "tab.h"
P(codepoint) {
  o[a++].q = o[0].cs[o[2].q++];
  o[b + 1].c(a, b, o, s, d);
}
P(biend) {
  unsigned long b2 = o[0].cs[o[2].q++] & 0b00111111;
  unsigned long b1 = o[--a].Q;
  o[a++].Q = b1 << 6 | b2;
  o[b + 1].c(a, b, o, s, d);
}
P(triend) {
  unsigned long b3 = o[0].cs[o[2].q++] & 0b00111111;
  unsigned long b2 = o[--a].Q;
  unsigned long b1 = o[--a].Q;
  o[a++].Q = b1 << 12 | b2 << 6 | b3;
  o[b + 1].c(a, b, o, s, d);
}
P(quadend) {
  unsigned long b4 = o[0].cs[o[2].q++] & 0b00111111;
  unsigned long b3 = o[--a].Q;
  unsigned long b2 = o[--a].Q;
  unsigned long b1 = o[--a].Q;
  o[a++].Q = b1 << 18 | b2 << 12 | b3 << 6 | b4;
  o[b + 1].c(a, b, o, s, d);
}
extern p_t next_byte_cases[];
P(drop1) { a--, Gor(a, b, o, s, d); }
P(drop2) { a--, a--, Gor(a, b, o, s, d); }
P(drop3) { a--, a--, a--, Gor(a, b, o, s, d); }
P(bichar) {
  o[--b].c = drop1, o[--b].c = biend, o[--b].c = Gor;
  o[a++].q = o[0].cs[o[2].q++] & 0b00011111;
  next_byte_cases[(unsigned char)o[0].cs[o[2].q]](a, b, o, s, d);
}
P(nextchar) {
  o[a++].q = o[0].cs[o[2].q++] & 0b00111111;
  next_byte_cases[(unsigned char)o[0].cs[o[2].q]](a, b, o, s, d);
}
P(trichar) {
  o[--b].c = drop2, o[--b].c = triend, o[--b].c = Gor;
  o[--b].c = drop1, o[--b].c = nextchar, o[--b].c = Gor;
  o[a++].q = o[0].cs[o[2].q++] & 0b00001111;
  next_byte_cases[(unsigned char)o[0].cs[o[2].q]](a, b, o, s, d);
}
P(quadchar) {
  o[--b].c = drop3, o[--b].c = quadend, o[--b].c = Gor;
  o[--b].c = drop2, o[--b].c = nextchar, o[--b].c = Gor;
  o[--b].c = drop1, o[--b].c = nextchar, o[--b].c = Gor;
  o[a++].q = o[0].cs[o[2].q++] & 0b00000111;
  next_byte_cases[(unsigned char)o[0].cs[o[2].q]](a, b, o, s, d);
}
extern p_t starting_byte_cases[];
#include <stdio.h>
#define L (void)0 // printf("%ld %ld %s\n", o[1].q, Pos, __FUNCTION__)
P(utf) { starting_byte_cases[(unsigned char)o[0].cs[o[2].q]](a, b, o, s, d); }

static P(Tot) { o[b + 2].o[0].c(a, b + 3, o, s, d); }
static P(Tod) { o[b + 1].o[0].c(a, b + 3, o, s, d); }
static P(Tor) { o[b + 0].o[0].c(a, b + 3, o, s, d); }
Tab(tab, Gor,
    [0x20] = God,
    [ 0xA] = God,
    [ 0xD] = God,
    [ 0x9] = God);

P(nar) {
  T(tab, tab, tab);
  T(tab, tab, tab);
  T(tab, tab, tab);
  T(tab, tab, tab);
  T(tab, tab, tab);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
double getTime();
P(value);
P(not ) { printf("not\n"); }
P(and) { printf("and %ld %ld\n", o[1].q, o[2].q); }
P(oor) { printf("oor\n"); }
P(Main) {
  double startTime = getTime();
  value(a, b, o, s, d);
  double endTime = getTime();
  double executionTime = endTime - startTime;
  printf("Execution time: %f seconds\n", executionTime);
}

int main() {
  char s[1 * 1024 * 1024];
  FILE *fp = fopen("../twitter.json", "rb");
  long length = fread(s, 1, sizeof(s) / sizeof(*s), fp);
  s[length] = 0;
  fclose(fp);
  printf("%ld\n", length);

  o_t o[1024];
  long a = 0, b = 1024, d = 0;
  o[--b].c = not ;
  o[--b].c = and;
  o[--b].c = oor;
  o[a++].cs = s;
  o[a++].q = strlen(s);
  o[a++].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
  o[2].q = 0, Main(a, b, o, s, d);
}
double getTime() {
  struct timespec time;
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
