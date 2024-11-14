// clang-format off
#include "../main.h"
N(book_of_bani);

S(bani_e      ) { οRed(book_of_bani), Red_e(OS); }

S(cursor      ) { τ = β[ρRed][1],
                  α = β[ρRed][2], Red_God(OS); }

S(bani_tab    ) { οRed(book_of_bani, τ + (1 << Σ), α),
                  οRed(cursor);
                  bani_e(OS); }

N(search);
N(ani);

S(set_tau     ) { τ = α[ρYellow][1], Olive(OS); }

S(goin_tab    ) { οRed(book_of_bani),
                  οRed(Red_s), Red(OS); }

S(goin_sword  ) { οOlive(ani, τ),
                  οOlive(set_tau);

                  οYellow(Red, goin_tab, Yellow),
                  οYellow(Yellow_NAO),
                  οBlue(  Blue, o[τ + 1]),
                  οYellow(search), Yellow(OS); }

extern int strcmp(const char *, const char *);
S(bani_sword  ) { if(strcmp(o[α[0][1]+1], o[τ+1]) == 0)
                    οYellow(Red), ani(OS);
                  else
                    goin_sword(OS); }

N(book_of_bani) {
  is_a_book_of(
    [tab  ] = bani_tab,
    [put  ] = bani_e,
    [sword] = bani_sword,
    [name ] = Yellow,
    [halt ] = Yellow,
    [tword] = Red,
    [dot  ] = Red,
  );
}
