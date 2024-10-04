#include "../main.h"
N(ani);
N(bani);
S(bani_name) { OB(3, ani), go_s(OS); }
N(bani) {
  is_a_book_of(           //
      [name] = bani_name, //
  );
}
S(ani_e) { OB(3, ani), go_e(OS); }
S(ani_nl) { OB(3, bani), go_w(OS); }
S(ani_tword) { P; }
N(ani) {
  is_a_book_of(            //
      [name] = ani_e,      //
      [nl] = ani_nl,       //
      [tab] = ani_e,       //
      [nop] = ani_e,       //
      [tword] = ani_tword, //
                           //
  );
}

