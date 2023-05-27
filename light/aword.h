#pragma once
#define TW 5
#define White(  op) (o[s].q op + TW)
#define Black(  op) (o[s].q op - TW)
#define Yellow( op) (o[s+1].q op 3)
#define Red(    op) (o[s+1].q op 2)
#define Green(  op) (o[s+1].q op 1)
#define Blue(   op) (o[s+1].q op 0)
#define aword long a, long w, struct o_t *o, long r, const char*d, long s
#define N(argo) void argo(aword)
#define T(aw)       a++, a++, o[a++].c = aw, a++                   , o[a++].cs = #aw
#define Ta(aw, arg) a++, a++, o[a++].c = aw, o[a++].v = (void *)arg, o[a++].cs = #aw
typedef struct o_t {
  union {
    void *v;
    long q;
    N((*c));
    struct o_t *o;
    char *cs;
  };
} o_t;
typedef N((*aword_t));
N(m);
