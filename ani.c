// clang-format off
#include "sophis.h"
#include "colours_fly.h"
S(ani);   //  ani T gani gani .
S(bani);  //      b           d eni T gani
N(gani);  //      a n i       o     d
S(doni);  //      n           n     o S gani
S(eni);   //      i           i     n
S(vini);  //                        i
extern int strcmp(const char *, const char *);
S(vini_name ) { if (strcmp(ο[ΔLime[1] + 1], ο[τ + 1]) == 0)
                  οNavy(Navy, τ), Green(OS);
                else
                  vini(OS); }
S(clr_top   ) { (strcmp(ο[ΔLime[1] + 1], ο[τ + 1]) == 0 ? Red_Green : Red_Blue )(OS); }
S(clr       ) { (strcmp(ο[ΔLime[1] + 1], ο[τ + 1]) == 0 ? Red_Green : Maroon   )(OS); }
S(clr_Red   ) { (strcmp(ο[ΔLime[1] + 1], ο[τ + 1]) == 0 ? Red_Red   : Maroon   )(OS); }
S(search    ) { τ = σ, vini(OS); }
S(re_tau    ) { τ = ΔLime[1], Lime(OS); }
S(eni_sword ) { οLime(gani, τ), οMaroon(clr_Red), οOlive(re_tau); οGreen(doni), search(OS); }
S(ani_sword ) { οLime(gani, τ), οMaroon(clr    ), οOlive(re_tau); οGreen(bani), search(OS); }
S(gani_tword) { οLime(gani, τ), οMaroon(clr_top), οOlive(re_tau); οGreen(bani), search(OS); }
S(re_alfa   ) { α = ΔRed[1], Red(OS); }
S(ani_tword ) { οRed(ani_sword, Yellow, Yellow), οRed(Red_aradani, α), οRed(re_alfa), Maroon(OS); }
S(eni_tword ) { οRed(eni_sword, gani,   Yellow), οRed(Red_aradani, α), οRed(re_alfa), Maroon(OS); }
S(cursor    ) { τ = ΔYellow[1],
                α = ΔYellow[2],
                ω = ΔYellow[3], Yellow(OS); }
S(bani_tab  ) { οYellow(bani, τ,        α, ω), οYellow(cursor);   ani(OS); }
S(doni_tab  ) { οYellow(doni, τ,        α, ω), οYellow(cursor);   eni(OS); }
S(gani_dot  ) { οYellow(gani, τ,        α, ω), οYellow(cursor);
                οMaroon(clr_top),
                οYellow(doni, ΔNavy[1], α, ω), οYellow(cursor); Olive(OS); }
N(gani_aword) { const char *t = ο[τ + 1];
                const char *s = ΔBlue[1];
                long length   = ΔBlue[2];
                long pos      = ΔBlue[3];
                if (pos < length && s[pos] == t[0])
                  οGreen(Green, t),
                  οBlue(Blue, s, length, pos + 1), gani(OS);
                else
                  Yellow(OS); }
S(ani) {
  static n_t narg[5] = {
    [2] = gani_aword,
    [3] = ani_tword,
    [4] = gani_dot,
  }; τ += 11; ρ = 2, δ = +1, sdb(OS), narg[ο[τ]](OS);
}
S(bani) {
  static n_t narg[5] = {
    [1] = bani_tab,
    [3] = Yellow,
    [0] = Yellow,
  }; τ += 1 << Σ, ρ = 2, δ = +1, sdb(OS), narg[ο[τ]](OS);
}
N(gani) {
  static n_t narg[5] = {
    [2] = gani_aword,
    [3] = gani_tword,
    [4] = gani_dot,
    [0] = Yellow,
  }; τ += 11; ρ = 1, δ = +1, sdb(OS), narg[ο[τ]](OS);
}
S(doni) {
  static n_t narg[5] = {
    [1] = doni_tab,
    [3] = Yellow,
    [0] = Yellow,
  }; τ += 1 << Σ, ρ = 3, δ = +1, sdb(OS), narg[ο[τ]](OS);
}
S(eni) {
  static n_t narg[5] = {
    [3] = eni_tword,
    [2] = Yellow,
    [4] = Yellow,
  }; τ += 11; ρ = 3, δ = +1, sdb(OS), narg[ο[τ]](OS);
}
S(vini) {
  static n_t narg[5] = {
    [0] = Navy,
    [3] = vini_name,
    [1] = vini,
  }; τ -= 1 << Σ, ρ = 0, δ = -1, sdb(OS), narg[ο[τ]](OS);
}
