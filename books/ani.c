#include "../main.h"
N(dive);
N(rise);

S(cr) { τ = ((τ >> Σ) << Σ), Go(OS); }
S(nearch) { τ = β[3][1], οYellow(rise), cr(OS); }
S(search) {
  οBlue(Go, o[τ + 1]);

  οYellow(Go, τ);
  οYellow(nearch, Go, Go), οYellow(NotAndOr);
  οYellow(dive);
  cr(OS);
}

N(ani);
N(bani);
S(bani_name) { οYellow(ani), go_s(OS); }
S(bani_w) { οYellow(bani), go_w(OS); }
N(bani) {
  is_a_book_of(           //
      [name] = bani_name, //
      [dot] = bani_w, //
      [put] = bani_w, //
      [print] = bani_w, //
      [tword] = bani_w, //
      [nop] = bani_w, //
      [tab] = God, //
  );
}
S(ani_e) { οYellow(ani), go_e(OS); }
S(ani_nl) { οYellow(bani), go_w(OS); }

S(sta) { τ = β[3][1], Go(OS); }
S(ani_tword) {
  οYellow(Go, ani_e, Go), οYellow(NotAndOr);
  οYellow(Go, τ);
  οYellow(Go, sta, Go), οYellow(NotAndOr);
  οYellow(Go, ani, Go), οYellow(NotAndOr);
  search(OS);
}
N(ani) {
  is_a_book_of(            //
      [name] = ani_e,      //
      [nl] = ani_nl,       //
      [tab] = ani_e,       //
      [nop] = ani_e,       //
      [tword] = ani_tword, //
      [put] = ani_e,       //
      [print] = ani_e,     //
      [dot] = ani_e,       //
                           //
  );
}
