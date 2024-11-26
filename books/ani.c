// clang-format off
#include "../sophis.h"
S(ani);
S(bani);
N(gani);
S(doni);
S(eni);
S(vini);
S(search    ) { τ = σ, vini(OS); }
S(re_alfa   ) { α = βYellow[1],       Yellow(OS); }
S(re_tau    ) { τ = αOlive[ 1],        Olive(OS); }
S(cursor    ) { τ = βYellow[1],
                α = βYellow[2],
                ω = βYellow[3], Yellow_Green(OS); }
S(vini_name ) { if (ο[τ + 1] == ο[βGreen[1] + 1])
                  οNavy(Navy,  τ), ((n_t*)ο)[τ + 1](OS);
                else
                  vini(OS); }
S(clr       ) { (ο[αNavy[ 1] + 1] == ο[τ + 1] ? Yellow_Green : Maroon     )(OS); }
S(clr_top   ) { (ο[αNavy[ 1] + 1] == ο[τ + 1] ? Yellow_Green : Yellow_Blue)(OS); }
S(clr_Red   ) { (ο[αOlive[1] + 1] == ο[τ + 1] ? Yellow_Red   : Maroon     )(OS); }
S(nbani     ) {                  οMaroon(clr    ), bani(OS); }
S(tbani     ) {                  οMaroon(clr_top), bani(OS); }
S(eni_sword ) { οOlive(gani, τ), οMaroon(clr_Red), οOlive(re_tau); οGreen(doni,  τ), search(OS); }
S(ani_sword ) { οOlive(gani, τ),                   οOlive(re_tau); οGreen(nbani, τ), search(OS); }
S(gani_tword) { οOlive(gani, τ),                   οOlive(re_tau); οGreen(tbani, τ), search(OS); }
S(ani_tword ) { οYellow(ani_sword, Yellow, Yellow),οYellow(Yellow_NAO, α), οYellow(re_alfa), Maroon(OS); }
S(eni_tword ) { οYellow(eni_sword, gani,   Yellow),οYellow(Yellow_NAO, α), οYellow(re_alfa), Maroon(OS); }
S(bani_tab  ) { οYellow(bani, τ,        α, ω), οYellow(cursor);   ani(OS); }
S(doni_tab  ) { οYellow(doni, τ,        α, ω), οYellow(cursor);   eni(OS); }
S(gani_dot  ) { οYellow(gani, τ,        α, ω), οYellow(cursor);
                οMaroon(clr_top),
                οYellow(doni, αNavy[1], α, ω), οYellow(cursor); Olive(OS); }
N(gani_aword) { οGreen(gani), οBlue(Yellow_Blue), ((n_t*)ο)[τ + 1](OS); }
S(eni) { τ += 11; ρ = 3, δ = +1, sdb(OS);
  static n_t narg[5] = {
    [3] = eni_tword,
    [2] = Yellow,
    [4] = Yellow,
  }; narg[ο[τ]](OS);
}
N(gani) { τ += 11; ρ = 1, δ = +1, sdb(OS);
  static n_t narg[5] = {
    [2] = gani_aword,
    [3] = gani_tword,
    [4] = gani_dot,
    [0] = Yellow,
  }; narg[ο[τ]](OS);
}
S(ani ) { τ += 11; ρ = 2, δ = +1, sdb(OS);
  static n_t narg[5] = {
    [2] = gani_aword,
    [3] = ani_tword,
    [4] = gani_dot,
  }; narg[ο[τ]](OS);
}
S(bani ) { τ += 1 << Σ; ρ = 2, δ = +1, sdb(OS);
  static n_t narg[5] = {
    [1] = bani_tab,
    [3] = Yellow,
    [0] = Yellow,
  }; narg[ο[τ]](OS);
}
S(doni) { τ += 1 << Σ; ρ = 3, δ = +1, sdb(OS);
  static n_t narg[5] = {
    [1] = doni_tab,
    [3] = Yellow,
    [0] = Yellow,
  }; narg[ο[τ]](OS);
}
S(vini) { τ -= 1 << Σ; ρ = 0, δ = -1, sdb(OS);
  static n_t narg[5] = {
    [0] = Blue,
    [3] = vini_name,
    [1] = vini,
  }; narg[ο[τ]](OS);
}
