// clang-format off
#include "../sophis.h"
S(ani);
S(bani);
N(gani);
S(doni);
S(eni);

N(search);
S(re_alfa   ) { α = βYellow[1],       Yellow(OS); }
S(re_tau    ) { τ = αOlive[ 1],        Olive(OS); }
S(cursor    ) { τ = βYellow[1],
                α = βYellow[2],
                ω = βYellow[3], Yellow_Green(OS); }
S(clr       ) { (o[αNavy[ 1] + 2] == o[τ + 2] ? Yellow_Green : Maroon     )(OS); }
S(clr_top   ) { (o[αNavy[ 1] + 2] == o[τ + 2] ? Yellow_Green : Yellow_Blue)(OS); }
S(clr_btw   ) { (o[αOlive[1] + 2] == o[τ + 2] ? Yellow_Red   : Maroon     )(OS); }
S(nbani     ) { οNavy(Navy,  τ), οMaroon(clr    ), bani(OS); }
S(tbani     ) { οNavy(Navy,  τ), οMaroon(clr_top), bani(OS); }
S(ani_sword ) { οOlive(gani, τ),                   οOlive(re_tau); οGreen(nbani, τ), search(OS); }
S(eni_sword ) { οOlive(gani, τ), οMaroon(clr_btw), οOlive(re_tau); οGreen(doni,  τ), search(OS); }
S(gani_tword) { οOlive(gani, τ),                   οOlive(re_tau); οGreen(tbani, τ), search(OS); }
S(ani_tword ) { οYellow(ani_sword, Yellow, Yellow),οYellow(Yellow_NAO, α), οYellow(re_alfa), Maroon(OS); }
S(eni_tword ) { οYellow(eni_sword, gani,   Yellow),οYellow(Yellow_NAO, α), οYellow(re_alfa), Maroon(OS); }

S(bani_tab  ) { οYellow(bani, τ,        α, ω), οYellow(cursor);   ani(OS); }
S(doni_tab  ) { οYellow(doni, τ,        α, ω), οYellow(cursor);   eni(OS); }
S(gani_dot  ) { οYellow(gani, τ,        α, ω), οYellow(cursor);
                οMaroon(clr_top),
                οYellow(doni, αNavy[1], α, ω), οYellow(cursor); Olive(OS); }
N(gani_aword) { const char *t = o[τ + 1];
                const char *s = βBlue[1];
                long length   = βBlue[2];
                long pos      = βBlue[3];
                if (pos < length && s[pos] == t[0])
                  οRed(Red, t),
                  οBlue(Blue, s, length, pos + 1),
                  gani(OS);
                else
                  Yellow_Blue(OS); }
S(gani_end  ) { long**b = β;
                printf("Green(");
                while(b[3][-1])
                  (b[3][1] < 1000
                   ? printf("%ld ", b[3][1])
                   : printf("%s", (char*)b[3][1])), b = b[3][-1];
                printf(")\n");
                Yellow(OS); }
S(eni) { τ += 11; ρ = 3, δ = +1, sdb(OS);
  is_a_book_of(
    [tword] = eni_tword,
    [aword] = Yellow,
    [dot  ] = Yellow,
  )
}
N(gani) { τ += 11; ρ = 1, δ = +1, sdb(OS);
  is_a_book_of(
    [aword] = gani_aword,
    [tword] = gani_tword,
    [dot  ] = gani_dot,
    [end  ] = gani_end,
    [halt ] = Yellow,
  )
}
S(ani ) { τ += 11; ρ = 2, δ = +1, sdb(OS);
  is_a_book_of(
    [aword] = gani_aword,
    [dot  ] = gani_dot,
    [tword] = ani_tword,
  )
}
S(bani ) { τ += 1 << Σ; ρ = 2, δ = +1, sdb(OS);
  is_a_book_of(
    [tab  ] = bani_tab,
    [name ] = Yellow,
    [halt ] = Yellow,
  )
}
S(doni) { τ += 1 << Σ; ρ = 3, δ = +1, sdb(OS);
  is_a_book_of(
    [tab  ] = doni_tab,
    [name ] = Yellow,
    [halt ] = Yellow,
  )
}
