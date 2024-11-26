// clang-format off
#include "../sophis.h"
N(book_of_gani_e);
N(book_of_ani_s);
S(check_lr      ) { (o[αNavy[1] + 2] ==  o[τ + 2] ? Yellow_Green : Yellow_Blue)(OS); }
S(on_name       ) { οNavy(Navy, τ), οMaroon(check_lr, "gani", τ),
                    book_of_ani_s(OS); }
N(search);
N(stop);
N(Return);
S(gani_tword    ) { οOlive(book_of_gani_e, τ), οOlive(Return);
                    οGreen(on_name, τ), οBlue(stop), search(OS); }

S(gani_print    ) { long**b = β;
                    printf("Green(");
                    while(b[3][-1])
                      (b[3][1] < 1000
                       ? printf("%ld ", b[3][1])
                       : printf("%s", (char*)b[3][1])), b = b[3][-1];
                    printf(")\n");
                    //οRed(Red, ωTomato[0]);
                    //printf("ω=%ld\n", ωTomato[0]);
                    book_of_gani_e(OS); }

N(gani_aword    ) { const char *t = o[τ + 1];
                    const char *s = βBlue[1];
                    long length   = βBlue[2];
                    long pos      = βBlue[3];
                    if (pos < length && s[pos] == t[0])
                      οRed(Red, t),
                      οBlue(Blue, s, length, pos + 1),
                      book_of_gani_e(OS);
                    else
                      Yellow_Blue(OS); }

N(book_of_bani_s);
N(cursor);
N(gani_dot      ) { οYellow(book_of_gani_e, τ, α, ω), οYellow(cursor);
                    οMaroon(check_lr, "dot", τ), οYellow(book_of_bani_s, αNavy[1], α, ω), οYellow(cursor);
                    Olive(OS); }
S(gani_put      ) { οRed(Red, o[τ + 1]), οTomato(o[τ + 1]),
                    book_of_gani_e(OS); }
S(gani_rword    ) { ((n_t)o[τ + 1])(OS); }
N(book_of_gani_e) {
  τ += 11;
  ρ = 1, δ = +1, sdb(OS);
  is_a_book_of(
    [aword] = gani_aword,
    [tword] = gani_tword,
    [dot  ] = gani_dot,
    [nl   ] = Yellow,
    [end  ] = Yellow,
    [print] = gani_print,
    [put  ] = gani_put,
    [rword] = gani_rword,
  )
}
