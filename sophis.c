#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wmathematical-notation-identifier-extension"

#include "sophis.h"

#define X(n)                                                                   \
  S(n##_Fuchsia);                                                              \
  S(n##_Olive);                                                                \
  S(n##_Maroon);                                                               \
  S(n##_Lime);                                                                 \
  S(n##_Navy);                                                                 \
  S(n##_Blue);                                                                 \
  S(n##_Green);                                                                \
  S(n##_Red);                                                                  \
  S(n##_Yellow);                                                               \
  S(n##_Purple);
NAMES
#undef X

static N((*sopcodes[])) = {
#define X(n)  n##_Fuchsia,n##_Olive,n##_Maroon,n##_Lime,n##_Navy,0,n##_Blue,n##_Green,n##_Red,n##_Yellow,n##_Purple,
  NAMES
#undef X
};

extern int printf(const char *, ...);
extern int usleep(long);
void sti_got(long *o);
S(dbg) {
  sti_got(o);
  sopcodes[o[τ] * 11 + (ρ + 1) * δ + 5](o);
}

S(got) __attribute__((noinline));
S(yot) __attribute__((noinline));
S(got) { τ += 11 * δ, dbg(o); }
S(yot) { τ += (1 << 7) * δ, dbg(o); }

// clang-format off
S(halt_Fuchsia  ) {}
S(halt_Olive    ) {}
S(halt_Maroon   ) {}
S(halt_Lime     ) {}
S(halt_Navy     ) {}
S(halt_Blue     ) {}
S(halt_Green    ) {}
S(halt_Red      ) {}
S(halt_Yellow   ) {}
S(halt_Purple   ) {}

S(beginning_Fuchsia ) {}
S(beginning_Olive   ) {}
S(beginning_Maroon  ) {}
S(beginning_Lime    ) { ρ = 3; δ = -δ; got(o); }
S(beginning_Navy    ) {}
S(beginning_Blue    ) {}
S(beginning_Green   ) {}
S(beginning_Red     ) {}
S(beginning_Yellow  ) {}
S(beginning_Purple  ) {}

S(tab_Fuchsia   ) { yot(o);}
S(tab_Olive     ) { δ = -δ; yot(o); }
S(tab_Maroon    ) {}
S(tab_Lime      ) { δ = -δ; yot(o); }
S(tab_Navy      ) {}
S(tab_Blue      ) {}
S(tab_Green     ) { τ = o[β++]; β++; got(o); }
S(tab_Red       ) {}
S(tab_Yellow    ) { o[o[β]+2] = τ; τ = o[β++]; β++; ρ = 1; got(o); }
S(tab_Purple    ) { o[σ] = o[τ]; σ += 11; got(o); }

S(tword_pith    ) { o[--β] = ρ; o[--β] = τ; τ = o[τ + 2]; got(o); }
S(tword_init    ) { o[τ+5]++; o[--β] = ρ; o[--β] = τ; τ = σ; δ = -δ; ρ = 4; yot(o); }
S(tword_switch  ) { static N((*sopcodes[])) = {tword_init, tword_pith}; sopcodes[o[τ+5]](o); }
S(tword_Fuchsia ) {}
S(tword_Olive   ) { got(o); }
S(tword_Maroon  ) {}
S(tword_Lime    ) { got(o); }
S(tword_Navy    ) {}
S(tword_Blue    ) {}
S(tword_Green   ) { tword_switch(o); }
S(tword_Red     ) {}
S(tword_Yellow  ) { tword_switch(o); }
S(tword_Purple  ) { o[σ] = o[τ]; o[σ+1] = o[τ+1]; σ += 11; got(o);}

S(put_pith      ) { o[α++] = (char)o[τ+1]; got(o); }
S(put_Fuchsia   ) {}
S(put_Olive     ) { got(o); }
S(put_Maroon    ) {}
S(put_Lime      ) { got(o); }
S(put_Navy      ) {}
S(put_Blue      ) {}
S(put_Green     ) { put_pith(o); }
S(put_Red       ) {}
S(put_Yellow    ) { put_pith(o); }
S(put_Purple    ) { o[σ] = o[τ]; o[σ+1] = o[τ+1]; σ += 11; got(o); }

S(dot_Fuchsia   ) {}
S(dot_Olive     ) {}
S(dot_Maroon    ) {}
S(dot_Lime      ) {}
S(dot_Navy      ) {}
S(dot_Blue      ) {}
S(dot_Green     ) { δ = -δ; got(o); }
S(dot_Red       ) {}
S(dot_Yellow    ) { δ = -δ; got(o); }
S(dot_Purple    ) { o[σ] = o[τ]; σ = (((σ >> 7) + 1) << 7); o[σ] = name; τ = (τ >> 7) << 7; yot(o); }

#include<string.h>
S(name_Fuchsia  ) { if (strcmp(o[τ+1], o[o[β]+1]) == 0) {
                      o[σ] = o[τ];
                      o[σ+1] = o[τ+1];
                      σ += 1 << 7;
                      o[o[β]+2] = o[o[β]+3] = σ;
                      δ = -δ;
                    }
                    yot(o); }
S(name_Olive    ) {}
S(name_Maroon   ) {}
S(name_Lime     ) {}
S(name_Navy     ) {}
S(name_Blue     ) {}
S(name_Green    ) { τ = o[β++]; β++; got(o); }
S(name_Red      ) {}
S(name_Yellow   ) { o[o[β]+2] = o[o[β]+3]; τ = o[β++]; β++; got(o); }
S(name_Purple   ) { τ = o[o[β]+2]; ρ = o[β+1]; got(o); }

S(print_pith    ) { for(long i = 0; i < α; i++)
                      printf("%c", (char)o[i]);
                    α = 0;
                    printf("\n");
                    got(o); }
S(print_Fuchsia ) {}
S(print_Olive   ) { got(o); }
S(print_Maroon  ) {}
S(print_Lime    ) { got(o); }
S(print_Navy    ) {}
S(print_Blue    ) {}
S(print_Green   ) { print_pith(o); }
S(print_Red     ) {}
S(print_Yellow  ) { print_pith(o); }
S(print_Purple  ) { o[σ] = o[τ]; σ += 11; got(o); }

#define ν(a) (o[σ++] = a, π++)
#define _ ν(0)
#define T(s)        _,_,_,_,_,    (ν(s)),   _,   _   ,_,_,_,
#define Ta(s, a)    _,_,_,_,_,    (ν(s)),   ν(a),_   ,_,_,_,
#define AL          ({ while (π < (1 << 7)) _; π = 0; }),
N(tritab_sample) {
  long π = 0;
  σ -= 5;
  T(beginning) Ta(tword, "tritab") T(print)                 T(dot)AL
  Ta(name, "tab")                                                 AL
  T(tab) Ta(put, 't')                                       T(dot)AL
  T(tab) Ta(put, 'a')                                       T(dot)AL
  T(tab) Ta(put, 'b')                                       T(dot)AL
  Ta(name, "tritab")                                              AL
  T(tab) Ta(tword, "tab") Ta(tword, "tab") Ta(tword, "tab") T(dot)AL
  σ += 5;
  got(o);
}
N(S_sample) {
  long π = 0;
  σ -= 5;
  T(beginning) Ta(tword, "S") T(print)                        T(dot)AL
  Ta(name, "S")                                                     AL
  T(tab) Ta(put, 'b')                                         T(dot)AL
  T(tab) Ta(tword, "S") Ta(put, 'a')                          T(dot)AL
  σ += 5;
  got(o);
}
N(AB_sample) {
  long π = 0;
  σ -= 5;
  T(beginning) Ta(tword, "A") T(print)                        T(dot)AL
  Ta(name, "A")                                                     AL
  T(tab) Ta(put, 'o')                                         T(dot)AL
  T(tab) Ta(tword, "B") Ta(put, 'a')                          T(dot)AL
  Ta(name, "B")                                                     AL
  T(tab) Ta(put, 'y')                                         T(dot)AL
  T(tab) Ta(tword, "A") Ta(put, 'b')                          T(dot)AL
  σ += 5;
  got(o);
}
static long ram[0x10000];
void sti_init();
int main () {
  sti_init();
  long *o = ram;
  α = 0;
  τ = β = σ = 512;
  ρ = 3;
  δ = 1;
  S_sample(o);
}
