#include "../main.h"
N(dive);
N(rise);

S(cr      ) { τ = ((τ >> Σ) << Σ), Go(OS); }

S(nearch  ) { τ = β[1][1], οGreen(rise), οGreen(cr), Go(OS); }

S(search  ) { οBlue(Go, o[τ + 1]),
              οGreen(Go, τ), οGreen(nearch), οGreen(Or),
              οYellow(dive), οYellow(cr), Go(OS); }

S(bo_ani);
S(ani_pass) { οYellow(bo_ani), pass(OS); }
N(ani     ) { οYellow(ani_pass), go_Yellow(OS); }

S(ani_term) {
  const char *t = o[τ + 1];
  const char *s = β[0][1];
  long length = β[0][2];
  long pos = β[0][3];
  if (pos < length && s[pos] == t[0])
    οRed(Go, o[τ + 1]), οBlue(Go, s, length, pos + 1), οYellow(bo_ani), go_Yellow(OS);
  else
    Gor(OS);
}

S(ani_put     ) { οRed(Go, o[τ + 1]), ani_pass(OS); }

S(ani_print   ) { long **b = β;
                  printf("%7s(", ν == 2 ? "Red" : ν ? "Green" : "Blue");
                  while (b[3][-1])
                    printf("%s ", (char *)b[3][1]), b = b[3][-1];
                  printf(")\n");
                  ani_pass(OS);
                }
S(ani_dot     ) { οYellow(Twist), Go(OS); }

S(ani_twist   ) { οOlive(bo_ani), οOlive(pass), οYellow(Twist), Go(OS); }

S(ani_go_in   ) { οYellow(bo_ani), οYellow(And), 
                    οGreen(go_Yellow), οGreen(And), 
                      οGreen(pass),     Go(OS); }
S(set_tau     ) { τ = β[2][1], Go(OS); }
S(ani_tword   ) { οOlive(ani_twist), οOlive(Go, τ), οOlive(set_tau);

                  οGreen(ani_go_in), οGreen(And), 
                    οRed(go_Green), οRed(And),
                      οYellow(search), Go(OS);
                }
S(ani_set_next) { τ = β[2][1], α = β[2][2], God(OS); }
S(ani_tab     ) { οYellow(bo_ani), οYellow(Go, τ + (1 << Σ), α), οYellow(ani_set_next);
                  οYellow(bo_ani), οYellow(pass), Go(OS); }
S(bo_ani) {
  is_a_book_of(             //
      [tab  ] = ani_tab,    //
      [put  ] = ani_put,    //
      [term ] = ani_term,   //
      [nop  ] = ani_pass,   //
      [print] = ani_print,  //
      [tword] = ani_tword,  //
      [dot  ] = ani_dot,      //
      [end  ] = Go,         //
      [name ] = Go,         //
      [halt ] = Go,         //
  );
}
