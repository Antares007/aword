// clang-format off
#include "../main.h"
S(book_of_gani);
N(gani_e      ) { οGreen(book_of_gani), Green_e(OS); }

extern int strcmp(const char *, const char *);
N(ani_s);
S(check_lr    ) { (strcmp(o[α[0][1] + 1], o[τ + 1]) == 0 ? Yellow_God : Yellow_Gor)(OS); }
S(on_name     ) { οNavy(Navy, τ), οMaroon(check_lr), ani_s(OS); }

N(search);
N(stop);
N(Return);
S(gani_sword  ) { οOlive(gani_e, τ), οOlive(Return);

                  οYellow(stop, on_name, stop),
                  οYellow(Yellow_NAO),
                  οBlue(  Blue, o[τ + 1]), search(OS); }

N(gani_tword  ) { const char *t = o[τ + 1];
                  const char *s = β[ρBlue][1];
                  long length   = β[ρBlue][2];
                  long pos      = β[ρBlue][3];
                  if (pos < length && s[pos] == t[0])
                    οGreen(Green, o[τ + 1]),
                    οBlue(Blue, s, length, pos + 1),
                    gani_e(OS);
                  else
                    Yellow_Gor(OS);
                }

S(grow_check  ) { (strcmp(o[α[0][1] + 1], o[τ + 1]) == 0 ? Yellow_God : Yellow_Gor)(OS); }

N(bani_s);
N(cursor);
S(gani_dot    ) { οMaroon(grow_check), οYellow(bani_s, α[0][1], α), οYellow(cursor);
                  Olive(OS); }
S(book_of_gani) {
  is_a_book_of(
    [tword] = gani_tword,
    [sword] = gani_sword,
    [dot  ] = gani_dot,
    [end  ] = Yellow,
  )
}
