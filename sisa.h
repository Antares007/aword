#pragma once
#define begin     o[σ] = begin,               σ += 11,
#define tword(v)  o[σ] = tword, o[σ + 1] = v, σ += 11,
#define name(v)   o[σ] = name,  o[σ + 1] = v, σ += 11,
#define put(v)    o[σ] = put,   o[σ + 1] = v, σ += 11,
#define term(v)   o[σ] = term,  o[σ + 1] = v, σ += 11,
#define print     o[σ] = print,               σ += 11,
#define tab       o[σ] = tab,                 σ += 11,
#define nop       o[σ] = nop,                 σ += 11,
#define dot       o[σ] = dot,                 σ += 11,
#define end       o[σ] = end,                 σ += 11,
#define nl        o[σ] = nl,                  σ = ((σ >> Σ) + 1) << Σ
