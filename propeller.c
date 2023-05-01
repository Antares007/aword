#define N(argo) void argo(long t, long a, void **o, long s)
typedef N((*n_t));
#include <stdio.h>
#include <unistd.h>
#define P printf("%s %s\n", __FUNCTION__, (char *)o[t]), usleep(200000)
char *names[1024];
void ti_left();
void ti_right();
void ti_ret();
void ti_init();
void ti(long t, long ray, long delta);
// clang-format off
N(Yellow  ) { ti(t+15,+5,+1), ((n_t*)o)[t + 8](t + 15, a, o, s); }
N(Purple  ) { ti(t+15,+4,+1), ((n_t*)o)[t + 9](t + 15, a, o, s); }
N(Red     ) { ti(t+15,+3,+1), ((n_t*)o)[t +10](t + 15, a, o, s); }
N(Green   ) { ti(t+15,+2,+1), ((n_t*)o)[t +11](t + 15, a, o, s); }
N(Blue    ) { ti(t+15,+1,+1), ((n_t*)o)[t +12](t + 15, a, o, s); }





N(Navy    ) { ti(t-15,-1,-1), ((n_t*)o)[t -12](t - 15, a, o, s); }
N(Lime    ) { ti(t-15,-2,-1), ((n_t*)o)[t -11](t - 15, a, o, s); }
N(Maroon  ) { ti(t-15,-3,-1), ((n_t*)o)[t -10](t - 15, a, o, s); }
N(Fuchsia ) { ti(t-15,-4,-1), ((n_t*)o)[t - 9](t - 15, a, o, s); }
N(Olive   ) { ti(t-15,-5,-1), ((n_t*)o)[t - 8](t - 15, a, o, s); }
// clang-format on
#define T(W, O, R, L, D)                                                       \
  o[a++] = (void *)W, o[a++] = (void *)O, names[a] = #R, o[a++] = (void *)R,   \
  o[a++] = (void *)L, o[a++] = (void *)D
N(l_Fuchsia) { o[--s] = (void *)t, ti_left(), Fuchsia((long)o[t - 1], a, o, s); }
N(r_Fuchsia) { o[--s] = (void *)t, ti_right(), Fuchsia((long)o[t + 1], a, o, s); }
N(s_Lime) { ti_ret(), Lime((long)o[s], a, o, s + 1); }
N(s_Green) { ti_ret(), Green((long)o[s], a, o, s + 1); }
#define Tw(text)                                                           \
  T(Yellow, Purple, Red, Green, Blue), T(0, 0, text, 0, 0),                    \
      T(Navy, Lime, Maroon, Fuchsia, Olive)
#define Toti(left, right)                                                      \
  T(Yellow, Purple, Red, r_Fuchsia, Blue), T(0, left, "t", right, 0),          \
      T(Navy, l_Fuchsia, Maroon, Fuchsia, Olive)
#define Tdot T(Lime, Fuchsia, Maroon, Olive, Navy), T(0, 0, "o", 0, 0)
#define Tab T(0, 0, "b", 0, 0), T(Blue, Green, Red, Yellow, Purple)
#define Ts_Lime T(Lime, s_Lime, Maroon, Olive, Navy), T(0, 0, "o", 0, 0)
#define Ts_Green T(Lime, s_Green, Maroon, Olive, Navy), T(0, 0, "o", 0, 0)
#define Tand                                                                   \
  T(Lime, Purple, Red, Yellow, Blue), T(0, 0, "and", 0, 0),                    \
      T(Navy, Green, Maroon, Fuchsia, Olive)
#define Tnoun(value)                                                           \
  T(Yellow, Purple, Red, Green, Blue), T(0, 0, #value, value, 0),              \
      T(Navy, noun_heart, Maroon, Fuchsia, Olive)
N(noun_heart) {
  o[--s] = o[t + 1];
  Lime(t, a, o, s);
}
#define Tverb(nar)                                                             \
  T(Yellow, Purple, Red, nar, Blue), T(0, 0, #nar, 0, 0),                      \
      T(Navy, Lime, Maroon, Fuchsia, Olive)
N(add) {
  long r = (long)o[s++];
  long l = (long)o[s++];
  o[--s] = (void *)(l + r);
  Green(t, a, o, s);
}
N(print) {
  printf("%ld\n", (long)o[s++]);
  Green(t, a, o, s);
}
N(toti_q) {
  o[--s] = (void*)(t + 1), o[--s] = "R";
  o[--s] = (void*)(t - 1), o[--s] = "L";
  Fuchsia(t, a, o, s);
}
#include<string.h>
N(export) {
  const char*name = o[s++];
  if (strcmp(name, o[t]) == 0)
    o[(long)o[s++]] = (void*)t;
  else
    o[--s] = (void*)name;
  Yellow(t,a,o,s);
}
int main() {
  long t = 0;
  long a = t;
  void *o[1024];
  long s = 1024;
                                /*begining*/T(0, 0, "B", 0, 0),T(Blue, Green,    Red,    Yellow, Purple);

  T(export, Purple, Red,    Green,    Blue),T(0, 0, "L", 0, 0),T(Blue, Green,    Red,    Fuchsia,Purple);
  T(Yellow, Purple, Red,    Green,    Blue),T(0, 0, "l", 0, 0),T(Navy, Lime,     Maroon, Fuchsia,Olive);
  T(Lime,   s_Lime, Maroon, Olive,    Navy),T(0, 0, "o", 0, 0),T(Navy, Lime,     Maroon, Fuchsia,Olive);

  T(export, Purple, Red,    Green,    Blue),T(0, 0, "R", 0, 0),T(Blue, Green,    Red,    Fuchsia,Purple);
  T(Yellow, Purple, Red,    Green,    Blue),T(0, 0, "r", 0, 0),T(Navy, Lime,     Maroon, Fuchsia,Olive);
  T(Lime,   s_Green,Maroon, Olive,    Navy),T(0, 0, "o", 0, 0),T(Navy, Lime,     Maroon, Fuchsia,Olive);

  T(Yellow, Purple, Red,    Green,    Blue),T(0, 0, "b", 0, 0),T(Blue, Green,    Red,    Fuchsia,Purple);
  T(Yellow, Purple, Red,    r_Fuchsia,Blue),T(0, 3, "t", 6, 0),T(Navy, l_Fuchsia,Maroon, toti_q, Olive);
  T(Yellow, Purple, Red,    Green,    Blue),T(0, 0, "a", 0, 0),T(Navy, Lime,     Maroon, Fuchsia,Olive);
  T(Lime,   Fuchsia,Maroon, Olive,    Navy),T(0, 0, "o", 0, 0),T(Navy, Lime,     Maroon, Fuchsia,Olive);

  ti_init();
  o[--s] = (void*)(a - 8);
  Fuchsia(a - 8, a, o, s);
  //Tab, Tnoun(1), Tverb(add), Tnoun(1), Tand, Tverb(print), Tand, Tnoun(4), Tverb(add), Tnoun(5), Tand, Tverb(print), Tdot;
}
/*
lets describe how we will fill dependencies. we have roots represented by
aword which is threre from begining. 
We think how we solve isseues which will become visible after close aword.
Boundaries around aword will force us to think inside out.

Here's my revised version of the text:

This version of the protocol seems to be quite heavy, with each word taking up
120 bits (5 * 3 * 8). We need to consider some key factors:

Actionable words must be defined with precisely specified gates within a
membrane. These words should be capable of division. It should be easy to write
actionable sentences using the protocol. Our plan is to create the first word,
which will serve as the creator of everything. To accomplish this, we must
create a word within a membrane that has all the necessary tools to create
things.

Why do we need a membrane? It's necessary to have clearly defined boundaries and
a mechanism for information flow between words. The connections between words
must be indirectly defined so that the system can be scalable.

The "aword" is an executable file that can be loaded into memory and executed
from either the first byte or the last instruction, which must be a relative
jump to the "aword." With the protocol's words, we can flow in both directions,
with the instructions that define the "aword" indirectly sending us to the next
"aword" by using a relative jump to the byte following the current "aword," or
sending us to previous words from behind.

enter from narrow gate
what is my problem? i have experiance and know how to program but have 0 income
how to convert my experiance into income. i want to have so i need to give.
i think i have nothing to give. i think i need to make somesing to speak about
and to build community around it. i have feith that i am on narrow road and my
will is supported by God. but im already on this road more then 7 years. i have
progress i can speak more about actionable word, but i dont have that inner
satifaction that i have it i need to have that filling so i can share.
what i'm dong wrong? suggest something.
to solve problem of multitasking in super efficient way is only way we have. 



becous it is the most valuable thing we can do in short period of time we have.
what is the problem? In general, a preemptive multitasking operating system's
kernel may switch tasks hundreds or even thousands of times per second on a
typical desktop or server system. 
*/
