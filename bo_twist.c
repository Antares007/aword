#include "sophis2.h"
Nar(bo_grow);
Nar(twist);
S(twist_e) {
  O(twist), O(And),
  O(go_e),  O(And),
    Go(OS);
}
S(twist_tword) {
  O(twist), O(And),
  O(go_e),  O(And),
    Go(OS);
}
Book_of_(twist,
    [name ] = twist_e,
    [begin] = twist_e,
    [nop  ] = twist_e,
    [tword] = twist_tword,
)
