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

P(utf_cp1) {
  o[a++].q = o[0].cs[o[2].q++];
  o[b + 1].c(a, b, o);
}
P(utf_cp2) {
  unsigned long b2 = o[0].cs[o[2].q++] & 0b00111111;
  unsigned long b1 = o[--a].Q;
  o[a++].Q = b1 << 6 | b2;
  o[b + 1].c(a, b, o);
}
P(utf_cp3) {
  unsigned long b3 = o[0].cs[o[2].q++] & 0b00111111;
  unsigned long b2 = o[--a].Q;
  unsigned long b1 = o[--a].Q;
  o[a++].Q = b1 << 12 | b2 << 6 | b3;
  o[b + 1].c(a, b, o);
}
P(utf_cp4) {
  unsigned long b4 = o[0].cs[o[2].q++] & 0b00111111;
  unsigned long b3 = o[--a].Q;
  unsigned long b2 = o[--a].Q;
  unsigned long b1 = o[--a].Q;
  o[a++].Q = b1 << 18 | b2 << 12 | b3 << 6 | b4;
  o[b + 1].c(a, b, o);
}
p_t middle_byte[256];
P(utf_b2_1) {
  o[--b].c = Got, o[--b].c = utf_cp2, o[--b].c = Gor;
  o[a++].q = o[0].cs[o[2].q++] & 0b00011111;
  middle_byte[(unsigned char)o[0].cs[o[2].q]](a, b, o);
}
P(utf_bmo) {
  o[a++].q = o[0].cs[o[2].q++] & 0b00111111;
  middle_byte[(unsigned char)o[0].cs[o[2].q]](a, b, o);
}
P(utf_b3_1) {
  o[--b].c = Got, o[--b].c = utf_cp3, o[--b].c = Gor;
  o[--b].c = Got, o[--b].c = utf_bmo, o[--b].c = Gor;
  o[a++].q = o[0].cs[o[2].q++] & 0b00001111;
  middle_byte[(unsigned char)o[0].cs[o[2].q]](a, b, o);
}
P(utf_b4_1) {
  o[--b].c = Got, o[--b].c = utf_cp4, o[--b].c = Gor;
  o[--b].c = Got, o[--b].c = utf_bmo, o[--b].c = Gor;
  o[--b].c = Got, o[--b].c = utf_bmo, o[--b].c = Gor;
  o[a++].q = o[0].cs[o[2].q++] & 0b00000111;
  middle_byte[(unsigned char)o[0].cs[o[2].q]](a, b, o);
}
p_t starting_byte[256];
void utf_init() {
  for (long i = 0; i < 256; i++) {
    starting_byte[i] = (i & 0b10000000) == 0b00000000   ? utf_cp1
                       : (i & 0b11100000) == 0b11000000 ? utf_b2_1
                       : (i & 0b11110000) == 0b11100000 ? utf_b3_1
                       : (i & 0b11111000) == 0b11110000 ? utf_b4_1
                                                        : Gor;
    middle_byte[i] = (i & 0b11000000) == 0b10000000 ? God : Gor;
  }
}
P(utf) { starting_byte[(unsigned char)o[0].cs[o[2].q]](a, b, o); }
#include <stdio.h>
#include <string.h>
P(not ) { printf("not\n"); }
P(and) { printf("and %lx %ld\n", o[a - 1].q, o[a - 1].q); }
P(oor) { printf("oor\n"); }
int main() {
  o_t o[1024];
  long a = 0, b = 1024;
  const char *str = "ლ";
  o[--b].c = not ;
  o[--b].c = and;
  o[--b].c = oor;
  o[a++].cs = str;
  o[a++].q = strlen(str);
  o[a++].q = 0;
  utf_init();
  utf(a, b, o);
}
