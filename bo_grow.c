// clang-format off
#include "sophis2.h"
S(g0) { o[σ + o[α - 1] + 0] = o[τ + 0], Go(OS); }
S(g1) { o[σ + o[α - 1] + 1] = o[τ + 1], Go(OS); }
S(gs) {                        σ += 11, Go(OS); }
S(gp) {        σ = ((σ >> Σ) + 1) << Σ, Go(OS); }
S(cr) {        τ = ((τ >> Σ) + 0) << Σ, Go(OS); }
S(grow);
S(grow_     ) { 
                o[--β] = grow, o[--β] = And,
                o[--β] = go_e, o[--β] = And,
                o[--β] = gs,   o[--β] = And,
                o[--β] = g0,   o[--β] = And,
                Go(OS);
              }
S(grow_a    ) {
                o[--β] = grow, o[--β] = And,
                o[--β] = go_e, o[--β] = And,
                o[--β] = gs,   o[--β] = And,
                o[--β] = g1,   o[--β] = And,
                o[--β] = g0,   o[--β] = And,
                Go(OS);
              }
S(grow_nl   ) {
                o[--β] = grow, o[--β] = And,
                o[--β] = go_s, o[--β] = And,
                o[--β] = cr,   o[--β] = And,
                o[--β] = gp,   o[--β] = And,
                o[--β] = g0,   o[--β] = And,
                Go(OS);
              }
Nar(bo_grow ) { long offset = o[--α] - (τ % (1 << Σ));
                o[α++] = σ + offset;
                o[α++] = offset;
                grow_a(OS); }
Nar(grow    ) {
  static n_t sopcodes[] = {
      [tab  ] = grow_,
      [put  ] = grow_a,
      [tword] = grow_a,
      [dot  ] = grow_,
      [nl   ] = grow_nl,
      [name ] = drop_α,
      [halt ] = drop_α,
  };
  static const char *name = "grow";
  if (lastbookid != (long)name)
    printf("Book of %s(%s)\n", name, sopcode_names[o[τ]]),
        lastbookid = (long)name;
  sopcodes[o[τ]](o, regs, τ, α, β, ν);
}

