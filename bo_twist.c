// clang-format off
#include "sophis2.h"
Nar(bo_grow);
Nar(bo_twist);
S(_begin           ) {             o[--β] = bo_twist, o[--β] = And, go_e(OS); }
S(_tword_goin      ) { o[--β] = τ, o[--β] = G1,       o[--β] = And;
                                                                    τ = o[τ + 2] + τ, bo_twist(OS); }
S(_tword_grow_end  ) { τ = o[β++];
                       o[τ + 2] = o[--α] - τ;
                       o[τ + 5] = 1;
                       Go(OS); }
S(_tword_grow_start) { o[α++] = o[β++], bo_grow(OS); }
Nar(bo_search);
S(_tword_grow      ) {                         o[--β] = bo_twist,           o[--β] = And;
                       o[--β] = τ,             o[--β] = _tword_grow_end,    o[--β] = And;
                       o[--β] = τ % (1 << Σ),  o[--β] = _tword_grow_start,  o[--β] = And;
                       o[α++] = o[τ + 1], bo_search(OS); }
S(_tword           ) { static n_t nars[] = {_tword_grow, _tword_goin};
                       nars[o[τ + 5]](OS); }
S(_name            ) { o[--β] = bo_twist, o[--β] = And, go_e(OS); }
Book_of_(bo_twist, 
      [begin] = _begin,
      [tword] = _tword,
      [name ] = _name,
      [tab  ] = _begin,
    )
