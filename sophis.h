#pragma once

#define N(ame) void ame(long *o)
#define S(n) static N(n)

#define τ o[100]
#define α o[101]
#define β o[102]
#define σ o[103]
#define ρ o[104]
#define δ o[105]

#define NAMES                                                                  \
  X(halt)                                                                      \
  X(beginning)                                                                 \
  X(tab)                                                                       \
  X(tword)                                                                     \
  X(put)                                                                       \
  X(dot)                                                                       \
  X(print)                                                                     \
  X(name)

enum Names {
#define X(n) n,
  NAMES
#undef X
      Names_count
};
static const char*rays[11] = {"Fuchsia", "Olive",  "Maroon", "Lime",  "Navy", 0,
                              "Blue",    "Green",  "Red",    "Yellow","Purple"};
static const char*snames[] = {
#define X(n)  #n,
  NAMES
#undef X
};
