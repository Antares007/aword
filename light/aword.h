#pragma once
#define TW 5
#define White(  op) (o[s + 0].q op + TW)
#define Black(  op) (o[s + 0].q op - TW)
#define Yellow( op) (o[s + 1].q op 3)
#define Red(    op) (o[s + 1].q op 2)
#define Green(  op) (o[s + 1].q op 1)
#define Blue(   op) (o[s + 1].q op 0)
#define aword long a, long w, struct o_t *o, long r, long d, long s
#define N(argo) void argo(aword)
#define T(aw)       r++, r++, o[r++].c = aw, r++                   , o[r++].cs = #aw
#define Ta(aw, arg) r++, r++, o[r++].c = aw, o[r++].v = (void *)arg, o[r++].cs = #aw
typedef struct o_t {
  union {
    void *v;
    long q;
    float f;
    N((*c));
    struct o_t *o;
    const char *cs;
  };
} o_t;
typedef N((*aword_t));
N(m);
