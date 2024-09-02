// clang-format off
#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wmathematical-notation-identifier-extension"

#include "sophis.h"

#define X(n)                      \
  S(n##_Fuchsia); S(Fuchsia_##n); \
    S(n##_Olive); S(Olive_##n);   \
   S(n##_Maroon); S(Maroon_##n);  \
     S(n##_Lime); S(Lime_##n);    \
     S(n##_Navy); S(Navy_##n);    \
     S(n##_Blue); S(Blue_##n);    \
    S(n##_Green); S(Green_##n);   \
      S(n##_Red); S(Red_##n);     \
   S(n##_Yellow); S(Yellow_##n);  \
   S(n##_Purple); S(Purple_##n);    
NAMES
#undef X

#define CAT(a,b) a##b
#define X(n) RAYS_N(n)
static Nar((*sopcodes_n[])) = {NAMES};
#undef X
#define X(n) RAYS_E(n)
static Nar((*sopcodes_e[])) = {NAMES};
#undef X
#define X(n) RAYS_S(n)
static Nar((*sopcodes_s[])) = {NAMES};
#undef X
#define X(n) RAYS_W(n)
static Nar((*sopcodes_w[])) = {NAMES};
#undef X
#undef CAT

void sti_got(long *o, long s);

S(goto_n) __attribute__((noinline));
S(goto_e) __attribute__((noinline));
S(goto_s) __attribute__((noinline));
S(goto_w) __attribute__((noinline));
S(goto_n) { τ -= 1 << 7, δ = -1, sti_got(o, 0), sopcodes_n[o[τ] * 5 + ρ](o); }
S(goto_e) { τ += 11,     δ = +1, sti_got(o, 1), sopcodes_e[o[τ] * 5 + ρ](o); }
S(goto_s) { τ += 1 << 7, δ = +1, sti_got(o, 2), sopcodes_s[o[τ] * 5 + ρ](o); }
S(goto_w) { τ -= 11,     δ = -1, sti_got(o, 3), sopcodes_w[o[τ] * 5 + ρ](o); }

S(halt_Fuchsia) {}
S(halt_Olive)   {}
S(halt_Maroon)  {}
S(halt_Lime)    {}
S(halt_Navy)    {}
S(halt_Blue)    {}
S(halt_Green)   {}
S(halt_Red)     {}
S(halt_Yellow)  {}
S(halt_Purple)  {}
S(Fuchsia_halt) {}
S(Olive_halt)   {}
S(Maroon_halt)  {}
S(Lime_halt)    {}
S(Navy_halt)    {}
S(Blue_halt)    {}
S(Green_halt)   {}
S(Red_halt)     {}
S(Yellow_halt)  {}
S(Purple_halt)  {}

S(beginning_Fuchsia){}
S(beginning_Olive)  {}
S(beginning_Maroon) {}
S(beginning_Lime)   { ρ = 3, goto_e(o); }
S(beginning_Navy)   { ρ = 3, goto_e(o); }
S(beginning_Blue)   {}
S(beginning_Green)  {}
S(beginning_Red)    {}
S(beginning_Yellow) {}
S(beginning_Purple) {}
S(Fuchsia_beginning){}
S(Olive_beginning)  {}
S(Maroon_beginning) {}
S(Lime_beginning)   {}
S(Navy_beginning)   {}
S(Blue_beginning)   {}
S(Green_beginning)  {}
S(Red_beginning)    {}
S(Yellow_beginning) {}
S(Purple_beginning) {}

S(tword_Fuchsia){}
S(tword_Olive)  { goto_w(o); }
S(tword_Maroon) { goto_w(o); }
S(tword_Lime)   { goto_w(o); }
S(tword_Navy)   { goto_w(o); }
S(tword_pith)   { o[--β] = τ, τ = o[τ+2], goto_e(o); }
S(tword_init)   { o[τ+5] = 1, o[τ+4] = ρ, ρ = 4, o[--β] = τ, τ = σ, goto_n(o); }
S(tword_locked) { goto_w(o); }
S(tword_Blue)   { tword_Red(o); }
S(tword_Green)  { tword_Yellow(o); }
S(tword_Red)    { Nar((*sc[])) = {tword_locked, tword_pith}; sc[o[τ+5]](o); }
S(tword_Yellow) { Nar((*sc[])) = {tword_init, tword_pith}; sc[o[τ+5]](o); }
S(tword_Purple) { o[σ] = o[τ], o[σ+1] = o[τ+1], σ += 11, goto_e(o); }
S(Fuchsia_tword){}
S(Olive_tword)  {}
S(Maroon_tword) {}
S(Lime_tword)   {}
S(Navy_tword)   {}
S(Blue_tword)   {}
S(Green_tword)  {}
S(Red_tword)    {}
S(Yellow_tword) {}
S(Purple_tword) {}

S(name_Fuchsia) {}
S(name_Olive)   {}
S(name_Maroon)  {}
S(name_Lime)    {}
S(name_Navy)    {}
S(name_Blue)    {}
S(name_Green)   {}
S(name_Red)     {}
S(name_Yellow)  {}
S(name_Purple)  {}
extern int strcmp (const char *, const char *);
S(Fuchsia_name) { if (strcmp(o[τ+1], o[o[β]+1]) == 0)
                    o[σ] = o[τ], o[σ+1] = o[τ+1], σ += 11, goto_e(o);
                  else
                    goto_n(o); }
S(Olive_name)   { o[o[β]+2] = o[o[β]+3], τ = o[β++], goto_e(o); }
S(Maroon_name)  { o[o[β]+2] = o[o[β]+3], τ = o[β++], goto_e(o); }
S(Lime_name)    { τ = o[β++], goto_e(o); }
S(Navy_name)    { τ = o[β++], goto_e(o); }
S(Blue_name)    {}
S(Green_name)   {}
S(Red_name)     {}
S(Yellow_name)  {}
S(Purple_name)  { ρ = o[o[β]+4], o[o[β]+2] = o[o[β]+3] = τ = σ - (1<<7), goto_e(o); }

S(tab_Fuchsia){}
S(tab_Olive)  {              o[τ+1] = 1; goto_n(o); }
S(tab_Maroon) { if (!o[τ+1]) o[τ+2] = 1; goto_n(o); }
S(tab_Lime)   {              o[τ+1] = 1; goto_n(o); }
S(tab_Navy)   {                          goto_n(o); }
S(tab_Blue)   {}
S(tab_Green)  {}
S(tab_Red)    {}
S(tab_Yellow) {}
S(tab_Purple) {}
S(Fuchsia_tab){ goto_n(o); }
S(Olive_tab)  { if(o[τ+2]) goto_n(o);
                else ρ -= 2, o[o[β]+2] = τ, τ = o[β++], goto_e(o); }
S(Maroon_tab) { if(o[τ+2]) goto_n(o);
                else ρ -= 2, o[o[β]+2] = τ, τ = o[β++], goto_e(o); }
S(Lime_tab)   { if(o[τ+2]) goto_n(o);
                else τ = o[β++], goto_e(o); }
S(Navy_tab)   { if(o[τ+2]) goto_n(o);
                else τ = o[β++], goto_e(o); }
S(Blue_tab)   {}
S(Green_tab)  {}
S(Red_tab)    {}
S(Yellow_tab) {}
S(Purple_tab) { o[σ] = o[τ], σ += 11, goto_e(o); }

S(nl_Fuchsia) {}
S(nl_Olive)   {}
S(nl_Maroon)  {}
S(nl_Lime)    {}
S(nl_Navy)    {}
S(nl_Blue)    {}
S(nl_Green)   { goto_w(o); }
S(nl_Red)     {}
S(nl_Yellow)  { goto_w(o); }
S(nl_Purple)  { o[σ] = o[τ], σ = ((σ >> 7) + 1) << 7, τ = (τ >> 7) << 7, goto_s(o); }
S(Fuchsia_nl) {}
S(Olive_nl)   {}
S(Maroon_nl)  {}
S(Lime_nl)    {}
S(Navy_nl)    {}
S(Blue_nl)    {}
S(Green_nl)   {}
S(Red_nl)     {}
S(Yellow_nl)  {}
S(Purple_nl)  {}

S(dot_Fuchsia){}
S(dot_Olive)  { goto_w(o); }
S(dot_Maroon) { goto_w(o); }
S(dot_Lime)   { goto_w(o); }
S(dot_Navy)   { goto_w(o); }
S(dot_Blue)   { goto_w(o); }
S(dot_Green)  { goto_e(o); }
S(dot_Red)    { goto_w(o); }
S(dot_Yellow) { goto_e(o); }
S(dot_Purple) { o[σ] = o[τ], σ += 11, goto_e(o); }
S(Fuchsia_dot){}
S(Olive_dot)  {}
S(Maroon_dot) {}
S(Lime_dot)   {}
S(Navy_dot)   {}
S(Blue_dot)   {}
S(Green_dot)  {}
S(Red_dot)    {}
S(Yellow_dot) {}
S(Purple_dot) {}

S(print_Fuchsia){}
S(print_Olive)  { goto_w(o); }
S(print_Maroon) { goto_w(o); }
S(print_Lime)   { goto_w(o); }
S(print_Navy)   { goto_w(o); }
S(print_Blue)   { print_Green(o); }
extern int printf(const char *, ...);
S(print_Green)  { for(long i = 0; i < α; i++)
                      if(o[i] < 100) printf("%ld ", o[i]);
                      else           printf("%s ", (char*)o[i]);
                    printf("\n");
                    α = 0;
                    goto_e(o); }
S(print_Red)    { print_Green(o); }
S(print_Yellow) { print_Green(o); }
S(print_Purple) {}
S(Fuchsia_print){}
S(Olive_print)  {}
S(Maroon_print) {}
S(Lime_print)   {}
S(Navy_print)   {}
S(Blue_print)   {}
S(Green_print)  {}
S(Red_print)    {}
S(Yellow_print) {}
S(Purple_print) {}

S(put_Fuchsia){}
S(put_Olive)  { goto_w(o); }
S(put_Maroon) { goto_w(o); }
S(put_Lime)   { goto_w(o); }
S(put_Navy)   { goto_w(o); }
S(put_Blue)   {}
S(put_Green)  { o[α++] = o[τ+1], goto_e(o); }
S(put_Red)    {}
S(put_Yellow) { o[α++] = o[τ+1], goto_e(o); }
S(put_Purple) { o[σ] = o[τ], o[σ+1] = o[τ+1], σ += 11, goto_e(o); }
S(Fuchsia_put){}
S(Olive_put)  {}
S(Maroon_put) {}
S(Lime_put)   {}
S(Navy_put)   {}
S(Blue_put)   {}
S(Green_put)  {}
S(Red_put)    {}
S(Yellow_put) {}
S(Purple_put) {}

S(term_Fuchsia) {            }
S(term_Olive)   { goto_w(o); }
S(term_Maroon)  { goto_w(o); }
S(term_Lime)    { goto_w(o); }
S(term_Navy)    { goto_w(o); }
S(term_Blue)    { goto_e(o); }
S(term_Green)   { term_Yellow(o); }
S(term_Red)     { goto_e(o); }
S(term_Yellow)  { if (o[α-1] < o[α-2] && ((char*)o[α-3])[o[α-1]] == ((char*)o[τ+1])[0])
                    o[α - 1]++;
                  else
                    ρ--;
                  goto_e(o);
                }
S(term_Purple)  { o[σ] = o[τ], o[σ+1] = o[τ+1], σ += 11, goto_e(o); }
S(Fuchsia_term) {}
S(Olive_term)   {}
S(Maroon_term)  {}
S(Lime_term)    {}
S(Navy_term)    {}
S(Blue_term)    {}
S(Green_term)   {}
S(Red_term)     {}
S(Yellow_term)  {}
S(Purple_term)  {}

#define ν(a) (o[σ++] = a, π++)
#define _ ν(0)
#define Word(s)       _,_,_,_,_, (ν(s)), _,   _,_,_,_,
#define Word_a(s, a)  _,_,_,_,_, (ν(s)), ν(a),_,_,_,_,

#define beginning Word(beginning)
#define dot       Word(dot)
#define nl        Word(nl) ({ while (π < (1 << 7)) _; π = 0; }),
#define print     Word(print)
#define tab       Word(tab)
#define put(a)    Word_a(put, a)
#define term(a)   Word_a(term, a)
#define T(a)      Word_a(tword, a)
#define N(a)      Word_a(name, a)

Nar(tritab_sample) {
  long π = 0; σ -= 5;

  beginning T("tritab") print dot nl
  N("tab") nl
  tab put("t") dot nl
  tab put("a") dot nl
  tab put("b") dot nl
  N("tritab") nl
  tab T("tab") T("tab") T("tab") dot nl

  σ += 5; goto_e(o);
}
Nar(S_sample) {
  long π = 0; σ -= 5;

  beginning T("S") print dot nl
  N("S") nl tab T("S") put("a") dot nl
  tab put("b") dot nl

  σ += 5; goto_e(o);
}
Nar(parse_sample) {
  long π = 0; σ -= 5;

  beginning put("baa") put(3) put(0) T("tritab") print dot nl
  N("tab") nl
  tab term("t") dot nl
  tab term("a") dot nl
  tab term("b") dot nl
  N("tritab") nl
  tab T("tab") T("tab") T("tab") dot nl

  σ += 5; goto_e(o);
}
static long ram[0x10000];
void sti_init();
int main () {
  (void)goto_e, (void)goto_w, (void)goto_n, (void)goto_s;
  sti_init();
  long *o = ram;
  α = 0;
  β = 507;
  τ = σ = 512;
  ρ = 3;
  δ = 1;
  parse_sample(o);
}
