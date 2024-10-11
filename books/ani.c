#include "../main.h"
N(dive);
N(rise);
N(ani);
N(bani);

S(cr        ) { τ = ((τ >> Σ) << Σ), Go(OS); }
S(nearch    ) { τ = β[3][1], οYellow(rise), cr(OS); }
S(search    ) { οGreen(Go, o[τ + 1]), οYellow(Go, τ), οYellow(nearch), οYellow(Or), οYellow(dive), cr(OS); }

S(ani_e     ) { οYellow(ani), go_e(OS); }

S(ani_term  ) { const char*t = o[τ + 1];
                const char*s = β[0][1];
                long length = β[0][2];
                long pos = β[0][3];
                if (pos < length && s[pos] == t[0])
                  οRed(Go, o[τ + 1]), οBlue(Go, s, length, pos+1), οYellow(ani), go_e(OS);
                else
                  Gor(OS);
              }
S(ani_put   ) { οRed(Go, "a"), β[2][1] = β[2][3] = o[τ + 1], ani_e(OS); }
S(ani_print ) { long **b = β;
                while (b[2][-1])
                  printf("%s ", (char *)b[2][1]), b = b[2][-1];
                printf("\n");
                ani_e(OS); }

S(ani_nl    ) { οYellow(bani), go_w(OS); }

S(ani_contau) { τ = β[3][1], οOlive(ani_e), Go(OS); }
S(ani_tword ) { οOlive(Twist), οOlive(And),
                οOlive(Go, τ), οOlive(ani_contau), οOlive(And);

                οYellow(ani_e), οYellow(And), search(OS); }

S(ani_restore ) { α = β[3][1], τ = β[3][2], God(OS); }
S(ani_tab     ) { οYellow(ani), οYellow(Go, α, τ + (1 << Σ)), οYellow(ani_restore);
                  οYellow(ani), go_e(OS); }
S(ani_end     ) { οYellow(bani), go_w(OS); }
S(bani_tab    ) { Twist(OS); }

N(ani) {
  is_a_book_of(            //
      [begin] = ani_e,     //
      [tab] = ani_tab,     //
      [put] = ani_put,     //
      [term] = ani_term,     //
      [nop] = ani_e,       //
      [print] = ani_print, //
      [tword] = ani_tword, //
      [dot] = ani_e,       //
      [nl] = ani_nl,       //
      [end] = ani_end,     //
      [name] = Go,         //
      [halt] = Go,         //
  );
}

S(bani_s) { οYellow(ani), go_s(OS); }
S(bani_w) { οYellow(bani), go_w(OS); }
N(bani) {
  is_a_book_of(           //
      [name ] = bani_s,   //
      [tab  ] = bani_tab, //
      [put  ] = bani_w,   //
      [term ] = bani_w,   //
      [nop  ] = bani_w,   //
      [print] = bani_w,   //
      [tword] = bani_w,   //
      [dot  ] = bani_w,   //
      [begin] = Go,       //
  );
}
