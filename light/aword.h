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
#define Tab(aw, arg1, arg2) o[r++].cs = #aw,          r++,                    \
                            o[r++].c  = aw,                                   \
                            o[r++].v  = (void *)arg1, o[r++].v = (void *)arg2
#define Ta(aw, arg1)  Tab(aw, arg1, 0)
#define T(aw)         Tab(aw, 0,    0)
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
