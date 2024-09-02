#pragma once

#define Nar(go) void go(long *o)
#define S(n) static Nar(n)

#define τ o[100]
#define α o[101]
#define β o[102]
#define σ o[103]
#define ρ o[104]
#define δ o[105]

#define NAMES                                                                  \
  X(halt)                                                                      \
  X(beginning)                                                                 \
  X(dot)                                                                       \
  X(name)                                                                      \
  X(nl)                                                                        \
  X(print)                                                                     \
  X(put)                                                                       \
  X(tab)                                                                       \
  X(term)                                                                      \
  X(tword)

#define RAYS_E(n) CAT(n,_Blue), CAT(n,_Green), CAT(n,_Red), CAT(n,_Yellow), CAT(n,_Purple),
#define RAYS_W(n) CAT(n,_Navy), CAT(n,_Lime), CAT(n,_Maroon), CAT(n,_Olive), CAT(n,_Fuchsia),
#define RAYS_N(n) CAT(Navy_,n), CAT(Lime_,n), CAT(Maroon_,n), CAT(Olive_,n),CAT(Fuchsia_,n),
#define RAYS_S(n) CAT(Blue_,n), CAT(Green_,n), CAT(Red_,n), CAT(Yellow_,n),CAT(Purple_,n),

enum Names {
#define X(n) n,
  NAMES
#undef X
      Names_count
};
