#pragma once
#define begin     text[σ].sc = begin,                 σ++,
#define tword(v)  text[σ].sc = tword, text[σ].a = v,  σ++,
#define put(v)    text[σ].sc = put,   text[σ].a = v,  σ++,
#define term(v)   text[σ].sc = term,  text[σ].a = v,  σ++,
#define print     text[σ].sc = print,                 σ++,
#define name(v)   text[σ].sc = name,  text[σ].a = v,  σ++,
#define tab       text[σ].sc = tab,                   σ++,
#define dot       text[σ].sc = dot,                   σ++,
#define nop       text[σ].sc = nop,                   σ++,
#define nl        text[σ].sc = nl,                    σ = ((σ >> 4) + 1) << 4,
#define end       text[σ].sc = end,

