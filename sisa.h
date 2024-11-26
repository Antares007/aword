#pragma once
#define B    ο[σ] = 1,                               σ += 11,
#define T(v) ο[σ] = 2, ο[σ + 1] = v,  ο[σ + 2] = #v, σ += 11,
#define D(v) ο[σ] = 3, ο[σ + 1] = v,  ο[σ + 2] = #v, σ += 11,
#define O    ο[σ] = 4,                               σ += 11,
#define _ σ = ((σ >> Σ) + 1) << Σ

