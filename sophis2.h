#pragma once
#define τ regs[0]
#define α regs[1]
#define β regs[2]
#define σ regs[3]
#define ρ regs[4]
#define δ regs[5]

#define Nar(go) void go(long *o, member_t *text, long *regs)
#define S(go) static Nar(go)
#define OS o,text,regs


enum Names {
  halt,
  begin,
  put,
  print,
  dot,
  name,
  tab,
  end,
};
typedef struct member_s {
  long sc, a, b, c, d;
  const char*name;
} member_t;
