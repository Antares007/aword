#pragma once
// clang-format off
#ifndef bWords
#define Plus(a, b) a.win - (b) 
#define Push(s) --s.win
#define Pull(s) s.win++
#else
#define Plus(a, b) a.win + (b)
#define Push(s) s.win++
#define Pull(s) --s.win
#endif
#define T(ina, ...) ο[Push(α)].q=0, \
                    ο[Push(α)].q=0,ο[Push(α)].q=0,ο[Push(α)].q=0, \
                    ο[__VA_ARGS__ Push(α)].v=ina, \
                    ο[Push(α)].q=0,ο[Push(α)].q=0,ο[Push(α)].q=0, \
                    ο[Push(α)].q=0
#define Twin(nar) (T(nar, ο[Push(σ)].w.win =), ο[Pull(σ)].w)
#define Args win_v α, win_v ω, struct txt_t *ο, ray_v ρ, dir_v δ, win_v σ
#define N(argo) void argo(Args)
typedef struct ray_v { long ray; } ray_v;
typedef struct win_v { long win; } win_v;
typedef struct dir_v { long dir; } dir_v;
typedef struct txt_t {
  union { long q; void *v; const char *cs; struct txt_t *t; win_v w; N((*go)); };
} txt_t;
typedef N((*nar_t));
//           p p p pw p p p p p p p pw p p p p
// -b...o...-4-3-2-10+1+2+3+4-4-3-2-10+1+2+3+4...+b
//          |___4___1___4___||___4___1___4___|
#define P_Yellow(w)     ο[Plus(w, +4)]
#define P_Red(w)        ο[Plus(w, +3)]
#define P_Green(w)      ο[Plus(w, +2)]
#define P_Blue(w)       ο[Plus(w, +1)]
#define P_DarkBlue(w)   ο[Plus(w, -1)]
#define P_DarkGreen(w)  ο[Plus(w, -2)]
#define P_DarkRed(w)    ο[Plus(w, -3)]
#define P_DarkYellow(w) ο[Plus(w, -4)]
