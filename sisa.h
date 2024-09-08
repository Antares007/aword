#pragma once
#define begin     T[σ].sc = begin,              σ++,
#define tword(v)  T[σ].sc = tword, T[σ].a = v,  σ++,
#define put(v)    T[σ].sc = put,   T[σ].a = v,  σ++,
#define term(v)   T[σ].sc = term,  T[σ].a = v,  σ++,
#define print     T[σ].sc = print,              σ++,
#define name(v)   T[σ].sc = name,  T[σ].a = v,  σ++,
#define tab       T[σ].sc = tab,                σ++,
#define dot       T[σ].sc = dot,                σ++,
#define nop       T[σ].sc = nop,                σ++,
#define nl        T[σ].sc = nl,                 σ = ((σ >> 4) + 1) << 4,
#define end       T[σ].sc = end,

