/*
  Paper
  In modern computing, "paper" refers to a continuous space in RAM, essentially
  functioning as a C array.
  In C programming, you can declare it like this:
  void* paper[] = {};

  Arm
  An "arm" is defined as a written sequence of 5 CPU words on the paper, each
  capable of holding arbitrary data.

  Actionable Word
  An "actionable word" is a written sequence of CPU words on the paper.
  To create it, one first writes the left arm, then the address of the
  narrative, and finally the right arm. In total, a written actionable word
  requires 11 CPU words on the paper. Here's a C example: void* paper[] = {....,
  l5, l4, l3, l2, l1, address_of_narrative, r1, r2, r3, r4, r5, ....};

  Narrative
  A "narrative" is defined as a C function with a return type of "void" and
  7 fixed parameters.
  C example:
  void nargo(void **ο, long β, long α, void **τ, long σ, long ρ, long δ) {
    // Omicron (ο):
    // Omicron represents "paper" in this context and is utilized by two
    // other parameters, beta (β) and alpha (α).
    // In C, it can be declared as follows:
    // void* ο[512];
    // Supporting parameters: long α = 0; and long β = sizeof(ο) / sizeof(*ο);
    //
    // Beta (β):
    // Beta is employed as the back stack pointer.
    // C Example: ο[--β] = push_value; pop_value = ο[β++];
    //
    // Alpha (α):
    // Alpha serves as another advance stack pointer.
    // C Example: ο[α++] = push_value; pop_value = ο[--α];
    // Note the symmetry of the unary "++" and "--" operators.
    //
    // Tau (τ):
    // Tau points to the central CPU word on the paper that holds the address of
    // the actionable words narrative.
    // C Example:
    // void nargo(void **ο, long β, long α, void **τ, long σ, long ρ, long δ)
  {...;}
    // void* paper[] = { l5, l4, l3, l2, l1, nargo, r1, r2, r3, r4, r5, ... };
    // void** τ = &paper[5]; // i.e., paper + 5 (CPU words)
    //
    // Sigma (σ):
    // Sigma represents the C string.
    //
    // Rho (ρ):
    // Rho signifies the color of the execution flow, where colors are denoted
  as
    // 0-Blue, 1-Green, 2-Red, and 3-Yellow.
    //
    // Delta (δ):
    // Delta represents the direction of the execution flow, taking values of
    // either +1 or -1.
  }

  Execution Flow:
  The execution flow is the process where the CPU proceeds to the next
  actionable words narrative, and it has the flexibility to flow in either
  a positive (+) or negative (-) direction and change color of the flow.

  C Example: ...; τ[11 * δ](ο, β, α, τ + 11 * δ, σ, ρ, δ);

  Actionable Sentence
  An actionable sentence (bro, goTo, o) refers to a group of actionable words
  written on the paper.

  C Example:
  void*paper[] = { l5,l4,l3,l2,l1, bro, r1,r2,r3,r4,r5,
                   l5,l4,l3,l2,l1, goTo, r1,r2,r3,r4,r5,
                   l5,l4,l3,l2,l1, o, r1,r2,r3,r4,r5 };
*/
// clang-format off

// Make use of the N macro to easily define narratives.
#define N(argo) void argo(void **ο, long β, long α, void **τ, long σ, long ρ, long δ)

// Define the C type for narrative.
typedef N((*n_t));

//#define P (void)0
#define P printf("%ld %ld %ld %7s %s\n", σ, ρ, δ, rays[(ρ + 1) * δ + 5], __FUNCTION__), usleep(200)
#include <assert.h>
#include <stdio.h>
#include <unistd.h>

// The color of the execution flow is determined by accessing
// rays at the index [(ρ + 1) * δ + 5].
const char *rays[] = {"Fuchsia", "Olive", "Maroon", "Lime",   "Navy",  0,
                      "Blue",    "Green", "Red",    "Yellow", "Purple"};

// Apply the T macro to stamp actionable words on paper.
#define Ta(nar, a)      0, 0, 0, 0, (a), nar, (a), 0, 0, 0, 0
#define T(nar)          Ta(nar, 0)

// Use the following macros to streamline the process of passing parameters
// in call expressions.
#define oba     ο, β, α
#define obatsrd ο, β, α, τ, σ, ρ, δ
#define     srd             σ, ρ, δ

//  This is the narrative for moving either forward or backward.
//  Remember: the narrative's location is recorded at the center
//  of the definitions for actionable words on paper.
N(goTo) { ((n_t*)τ)[δ * 11](ο, β, α, ((void**)τ) + δ * 11, σ, ρ, δ); }

//  "o" signifies the end of a sentence. In other words, it is the
//  last actionable word in the sentence, and as we can see,
//  the execution flow reverses direction by 180 degrees,
//  changes sign of δ, and moves backward from this point.
N(o) { goTo(ο, β, α, τ, σ, ρ, -δ); }

//  On the other hand, "bro" represents the beginning. It is the
//  actionable word that initiates everything anew in a loop or
//  halts the execution flow based on the protocol.
N(bro) { printf("\n");
  static long δρ[] = {0,0,0};
  static long*δρc = δρ + 1;
  δρc[δ] = ρ;
  if (δρc[-δ] < 2) goTo(ο, β, α, τ, σ, 3, -δ);
  else if (δρc[δ] < 2) goTo(ο, β, α, τ, σ, 3, δ); 
  else P; }
N(tab) { goTo(ο, β + 1, α, ο[β], srd); }

#define GET_BIT(value, bit) ((value >> bit) & 1)
#define SET_BIT(value, bit) (value |= (1UL << bit))

#define OB ((unsigned long***)ο)[β][+5*δ]
#define Fruitful OB[2]
#define Trimed   OB[3]
#define Arms     OB[1]
#define I        OB[0]
N(propeller) {
  long oi = I;
  while((I = (I + 1) % Arms) && GET_BIT(Trimed, I));
  long d = (long)ο[--σ];
  goTo(ο,β,α,τ,σ, !(oi < I)*2 + d, δ);
}
N(Red_Blue_propeller    ) { (ο[σ++] = (void*)0), propeller(obatsrd); }
N(Yellow_Green_propeller) { (ο[σ++] = (void*)1), propeller(obatsrd); }
N(Yellow_Green          ) { SET_BIT(Fruitful, I),         goTo(obatsrd); }
N(Yellow_Red            ) { if (Arms == 1)                goTo(obatsrd);
                            else if(GET_BIT(Fruitful, I)) Red_Blue_propeller(obatsrd);
                            else SET_BIT(Trimed, I),      Red_Blue_propeller(obatsrd); }
N(Yellow_Yellow         ) { SET_BIT(Fruitful, I),         Yellow_Green_propeller(obatsrd); }
N(Red_Red               ) {                               Red_Blue_propeller(obatsrd); }
N(Green_Green           ) { SET_BIT(Fruitful, I),         goTo(obatsrd); }
N(δρ_switch ) { ((n_t)τ[(ρ + 1) * δ])(obatsrd); }
N(Yellow) {
  τ[-4] = τ[+4] = Yellow_Yellow;
  τ[-3] = τ[+3] = Yellow_Red;
  τ[-2] = τ[+2] = Yellow_Green;
  τ[-1] = τ[+1] = goTo;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(nop) { assert(0); }
N(Red   ) {
  τ[-4] = τ[+4] = nop;
  τ[-3] = τ[+3] = Red_Red;
  τ[-2] = τ[+2] = nop;
  τ[-1] = τ[+1] = goTo;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(Green ) {
  τ[-4] = τ[+4] = nop;
  τ[-3] = τ[+3] = nop;
  τ[-2] = τ[+2] = Green_Green;
  τ[-1] = τ[+1] = goTo;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(toti) {
  long*conf       = ((void***)ο)[β][+5 * δ];
  void***arms     = (void*)(conf + 4);
  void**arm_cener = arms[conf[0]];
  long off        = (long)arm_cener[δ];
  void*arm_head   = arm_cener + off;
  (ο[--β] = τ), goTo(oba, arm_head, srd);
}
N(δρ_goTo) { (ο[--β] = τ), goTo(oba, τ[(ρ + 1) * δ], srd); }
N(true_v) {
  static void*a_Yellow[] = {T(tab), T(toti), T(Yellow), T(tab)};
  static void*a_Red   [] = {T(tab), T(toti), T(Red),    T(tab)};
  static void*a_Green [] = {T(tab), T(toti), T(Green),  T(tab)};
  static void*a_Blue  [] = {T(tab),                     T(tab)};
  static void*b_Navy  [] = {T(tab),                     T(tab)};
  static void*b_Lime  [] = {T(tab), T(Green),  T(toti), T(tab)};
  static void*b_Maroon[] = {T(tab), T(Red),    T(toti), T(tab)};
  static void*b_Olive [] = {T(tab), T(Yellow), T(toti), T(tab)};
  τ[-4] = 38 + b_Olive; 
  τ[-3] = 38 + b_Maroon;
  τ[-2] = 38 + b_Lime;
  τ[-1] = 16 + b_Navy;
  τ[+1] =  5 + a_Blue;
  τ[+2] =  5 + a_Green;
  τ[+3] =  5 + a_Red;
  τ[+4] =  5 + a_Yellow;
  ((n_t)(*τ = δρ_goTo))(obatsrd);
}
N(v) {
  τ[-4] = true_v;
  τ[-3] = goTo;
  τ[-2] = true_v;
  τ[-1] = goTo;
  τ[+1] = goTo;
  τ[+2] = true_v;
  τ[+3] = goTo;
  τ[+4] = true_v;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
#include<string.h>
N(δ_switch) { ((n_t)τ[δ])(obatsrd); }
N(in_B) {    σ--         , goTo(obatsrd); }
N(in_A) {
  char*str = τ[2];
  (ο[σ++] = (void*[]){(void*)(strlen(str) - 1), str, 0} + 1), goTo(obatsrd);
}
N(in  ) { P;
  τ[2] = τ[1];
  τ[-δ] = in_B;
  τ[+δ] = in_A;
  ((n_t)(*τ = δ_switch))(obatsrd);
}
N(out ) { P;
  τ[2] = τ[1];
  τ[+δ] = in_B;
  τ[-δ] = in_A;
  ((n_t)(*τ = δ_switch))(obatsrd);
}
N(t_parse) {
  long*s = ο[σ - 1];
  long c = (long)τ[5];
  if (s[+1] <= s[-1] &&
      c == ((char*)s[0])[s[δ]]) (s[δ] += δ),goTo(oba, τ, σ, ρ, δ);
  else                                      goTo(oba, τ, σ, ρ - 1, δ);
}
N(term        ) {
  τ[-4] = τ[+4] = t_parse;
  τ[-3] = τ[+3] = goTo;
  τ[-2] = τ[+2] = t_parse;
  τ[-1] = τ[+1] = goTo;
  ((n_t)(*τ = δρ_switch))(obatsrd);
}
N(b) { τ[5] = (void*)'b', term(obatsrd); }
N(a) { τ[5] = (void*)'a', term(obatsrd); }
N(t) { τ[5] = (void*)'t', term(obatsrd); }
N(s) { τ[5] = (void*)'s', term(obatsrd); }

// clang-format on
#define LEN(...) (sizeof((void *[]){__VA_ARGS__}) / sizeof(void *))
#define B(...)                                                                 \
  (void *[]){T(tab),                                                           \
             __VA_ARGS__,                                                      \
             0,                                                                \
             0,                                                                \
             0,                                                                \
             0,                                                                \
             (void *)(+LEN(__VA_ARGS__) + 11),                                 \
             tab,                                                              \
             (void *)(-LEN(__VA_ARGS__) - 11),                                 \
             0,                                                                \
             0,                                                                \
             0,                                                                \
             0,                                                                \
             __VA_ARGS__,                                                      \
             T(tab)} +                                                         \
      LEN(__VA_ARGS__) + 16
#define D(S, ...)                                                              \
  N(S) {                                                                       \
    τ[+5] = (void*[]){0, (void*)LEN(__VA_ARGS__), 0, 0, __VA_ARGS__};          \
    τ[-5] = (void*[]){0, (void*)LEN(__VA_ARGS__), 0, 0, __VA_ARGS__};          \
    v(obatsrd);                                                                \
  }
D(S,
  B(T(b)),
  B(T(S), T(a))
)
D(sS, 
  B(T(goTo)),
  B(T(s),T(sS),T(sS)),
)
// clang-format off
#include<assert.h>
N(print1) {P;
  if(σ) { long*s = ο[σ - 1]; printf("%ld %s %ld\n", s[-1], (char*)s[0], s[+1]); }
  goTo(obatsrd);
}
N(print2) {P;
  if(σ) { long*s = ο[σ - 1]; printf("%ld %s %ld\n", s[-1], (char*)s[0], s[+1]); }
  goTo(obatsrd);
}
N(n1) { P; goTo(obatsrd); }N(n5) { P; goTo(obatsrd); }
N(n2) { P; goTo(obatsrd); }N(n6) { P; goTo(obatsrd); }
N(n3) { P; goTo(obatsrd); }N(n7) { P; goTo(obatsrd); }
N(n4) { P; goTo(obatsrd); }N(n8) { P; goTo(obatsrd); }
D(bat,
  B(T(n1), T(b), T(n2)),
  B(T(n3), T(a), T(n4)),
  B(T(n5), T(t), T(n6)),
  //B(T(n1), T(b), T(a), T(t), T(n2)),
  //B(T(n3), T(b), T(a), T(t), T(n4)),
  //B(T(n5), T(b), T(a), T(t), T(n6)),
  //B(T(n7), T(b), T(a), T(t), T(n8)),
)
int main() {
  void *ο[512];
  long β = sizeof(ο) / sizeof(*ο), α = β / 3 * 2;
  void **τ = 5 + (void *[]) { T(bro),
                              Ta(in, "bat"),
                              T(print1),
                              T(bat),
                              T(bat),
                              T(print2),
                              Ta(out, "bat"),
                              T(bro)
                            };
  long σ = 0, ρ = 3, δ = 1;

  goTo(ο, β, α, τ, σ, ρ, δ);
}
