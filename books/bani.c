// clang-format off
#include "../main.h"
N(book_of_bani);

S(bani_e      ) { οGreen(book_of_bani), Green_e(OS); }

S(cursor      ) { τ = β[ρGreen][1],
                  α = β[ρGreen][2], Green_God(OS); }

S(bani_tab    ) { οGreen(book_of_bani, τ + (1 << Σ), α),
                  οGreen(cursor);
                  bani_e(OS); }

N(search);
N(ani);

S(set_tau     ) { τ = α[ρYellow][1], Olive(OS); }

S(goin_tab    ) { οGreen(book_of_bani),
                  οGreen(Green_s), Green(OS); }

S(goin_sword  ) { οOlive(ani, τ),
                  οOlive(set_tau);

                  οYellow(Green, goin_tab, Yellow),
                  οYellow(Yellow_NAO),
                  οBlue(  Blue, o[τ + 1]),
                  οYellow(search), Yellow(OS); }

extern int strcmp(const char *, const char *);
S(bani_sword  ) { if(strcmp(o[α[0][1]+1], o[τ+1]) == 0)
                    οYellow(Green), ani(OS);
                  else
                    goin_sword(OS); }

N(book_of_bani) {
  is_a_book_of(
    [tab  ] = bani_tab,
    [put  ] = bani_e,
    [sword] = bani_sword,
    [name ] = Yellow,
    [halt ] = Yellow,
    [tword] = Green,
    [dot  ] = Green,
  );
}
