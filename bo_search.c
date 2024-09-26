// clang-format off
#include"sophis2.h"
extern int strcmp (const char *, const char *);
S(n);
S(n_n   ) { o[--β] = n, o[--β] = And, go_n(OS); }
S(n_name) { if (strcmp(o[τ + 1], o[α - 1]) == 0) α--, God(OS);
            else n_n(OS); }
Book_of_(n,
    [tab  ] = n_n,
    [name ] = n_name,
)
S(s);
S(s_s   ) { o[--β] = s, o[--β] = And, go_s(OS); }
S(s_name) { if (strcmp(o[τ + 1], o[α - 1]) == 0) α--, God(OS);
            else s_s(OS); }
Book_of_(s,
    [begin] = s_s,
    [name ] = s_name,
    [tab  ] = s_s,
)
S(w);
S(w_w   ) { o[--β] = w, o[--β] = And, go_w(OS); }
Book_of_(w,
    [tword] = w_w,
    [nop  ] = w_w,
    [begin] = s,
    [tab  ] = n,
)
Nar(bo_search) { w(OS); }
