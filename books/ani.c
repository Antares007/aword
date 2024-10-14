#include "../main.h"
N(dive);
N(rise);
N(ani);

S(cr) { τ = ((τ >> Σ) << Σ), Go(OS); }
S(nearch) { τ = β[1][1], οGreen(rise), cr(OS); }
S(search) {
  οBlue(Go, o[τ + 1]),
  οGreen(Go, τ),
  οGreen(nearch),
  οGreen(Or),
  οYellow(dive),
  cr(OS);
}

S(ani_e) { οYellow(ani), go_Yellow(OS); }

S(ani_term) {
  const char *t = o[τ + 1];
  const char *s = β[0][1];
  long length = β[0][2];
  long pos = β[0][3];
  if (pos < length && s[pos] == t[0])
    οRed(Go, o[τ + 1]), οBlue(Go, s, length, pos + 1), οYellow(ani), go_Yellow(OS);
  else
    Gor(OS);
}

S(ani_put) { οRed(Go, o[τ + 1]), ani_e(OS); }

S(ani_print) {
  long **b = β;
  printf("%7s(", ν == 2 ? "Red" : ν ? "Green" : "Blue");
  while (b[3][-1])
    printf("%s ", (char *)b[3][1]), b = b[3][-1];
  printf(")\n");
  ani_e(OS);
}

S(ani_jump    ) { τ = β[2][1], Go(OS); }
S(ani_restore ) { α = β[2][1], τ = β[2][2], Go(OS); }

S(ani_twist   ) { οOlive(ani), οOlive(go_Yellow), Twist(OS); }

S(ani_on_name ) { οGreen(ani), οGreen(And), go_Green(OS); }

S(ani_tword   ) { οOlive(ani_twist), οOlive(Go, τ), οOlive(ani_jump);
                  οGreen(ani_on_name), οRed(ani_on_name), search(OS); }

S(ani_tab     ) { οYellow(ani), οYellow(Go, α, τ + (1 << Σ)), οYellow(ani_restore),
                  οYellow(ani), go_Yellow(OS); }

S(untwist) {
  long *ray = R(0, "nar");
  β = (long *[]){ray, ray, ray, ray};
  β = (long *[]){β[0], β[1], β[2], β[3]};
}

S(twist_α) {
  α = (long *[]){α[3], α[0], α[1], α[2]};
  long *ray = R(α, untwist);
  α = (long *[]){ray, ray, ray, ray};
  Go(OS);
}

N(ani) {
  is_a_book_of(             //
      [begin] = ani_e,      //
      [tab  ] = ani_tab,    //
      [put  ] = ani_put,    //
      [term ] = ani_term,   //
      [nop  ] = ani_e,      //
      [print] = ani_print,  //
      [tword] = ani_tword,  //
      [dot  ] = Twist,      //
      [end  ] = Go,         //
      [name ] = Go,         //
      [halt ] = Go,         //
  );
}
