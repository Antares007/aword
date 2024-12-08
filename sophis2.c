#pragma GCC diagnostic ignored "-Wint-conversion"
#define N(args) void args(long*ο, long β, long α, long τ, long σ, long ρ, long δ)
#define EE ο, β, α, τ, σ, ρ, δ
typedef N((*n_t));

#define ob0(β)  ο[--ρ] = β,      \
                ο[ρ-1] = ο[β+3], \
                ο[ρ-2] = ο[β+2], \
                ο[ρ-3] = ο[β+1], \
                ο[ρ-4] = ρ+1,    \
                β = (ρ -= 4)
#define ob1(β)  ο[--ρ] = β,      \
                ο[ρ-1] = ο[β+3], \
                ο[ρ-2] = ο[β+2], \
                ο[ρ-3] = ρ+1,    \
                ο[ρ-4] = ο[β+0], \
                β = (ρ -= 4)
#define ob2(β)  ο[--ρ] = β,      \
                ο[ρ-1] = ο[β+3], \
                ο[ρ-2] = ρ+1,    \
                ο[ρ-3] = ο[β+1], \
                ο[ρ-4] = ο[β+0], \
                β = (ρ -= 4)
#define ob3(β)  ο[--ρ] = β,      \
                ο[ρ-1] = ρ+1,    \
                ο[ρ-2] = ο[β+2], \
                ο[ρ-3] = ο[β+1], \
                ο[ρ-4] = ο[β+0], \
                β = (ρ -= 4)
#define bo(...) ({  long v[] = {__VA_ARGS__}, len = sizeof(v) / sizeof(*v); while (len) ο[--ρ] = v[--len]; })
#define οRed(...)   bo(__VA_ARGS__), ob3(β)
#define οYellow(...)bo(__VA_ARGS__), ob2(β)
#define οGreen(...) bo(__VA_ARGS__), ob1(β)
#define οBlue(...)  bo(__VA_ARGS__), ob0(β)

#define οMaroon(...)bo(__VA_ARGS__), ob3(α)
#define οOlive(...) bo(__VA_ARGS__), ob2(α)
#define οLime(...)  bo(__VA_ARGS__), ob1(α)
#define οNavy(...)  bo(__VA_ARGS__), ob0(α)

#define ΔRed(n)    ο[ο[β+3]+n]
#define ΔYellow(n) ο[ο[β+2]+n]
#define ΔGreen(n)  ο[ο[β+1]+n]
#define ΔBlue(n)   ο[ο[β+0]+n]

#define ΔMaroon(n) ο[ο[α+3]+n]
#define ΔOlive(n)  ο[ο[α+2]+n]
#define ΔLime(n)   ο[ο[α+1]+n]
#define ΔNavy(n)   ο[ο[α+0]+n]

N(Red         ) { n_t n = ΔRed(0);    β = ΔRed(-1);    n(EE); }
N(Yellow      ) { n_t n = ΔYellow(0); β = ΔYellow(-1); n(EE); }
N(Green       ) { n_t n = ΔGreen(0);  β = ΔGreen(-1);  n(EE); }
N(Blue        ) { n_t n = ΔBlue(0);   β = ΔBlue(-1);   n(EE); }
                                                     
N(Maroon      ) { n_t n = ΔMaroon(0); α = ΔMaroon(-1); n(EE); }
N(Olive       ) { n_t n = ΔOlive(0);  α = ΔOlive(-1);  n(EE); }
N(Lime        ) { n_t n = ΔLime(0);   α = ΔLime(-1);   n(EE); }
N(Navy        ) { n_t n = ΔNavy(0);   α = ΔNavy(-1);   n(EE); }

N(Red_aradani ) { n_t n = ΔRed(δ); β = ΔRed(-1); n(EE); }
N(Red_Red     ) { δ = 2, Red(EE); }
N(Red_Green   ) { δ = 1, Red(EE); }
N(Red_Blue    ) { δ = 0, Red(EE); }

#define one       ο[σ] = 1,               σ += 11,
#define two(a)    ο[σ] = 2, ο[σ + 1] = a, σ += 11,
#define three(a)  ο[σ] = 3, ο[σ + 1] = a, σ += 11,
#define four      ο[σ] = 4,               σ += 11,
#define five      ο[σ] = 5,               σ += 11,
#define align                             σ  = ((σ >> 8) + 1) << 8

#define P printf("%s\n", __func__)
#include<stdio.h>

N(Green_book);
enum names {S = 9, Ss};
N(programS) {

  one three(Ss) five align;


  three(S) align;
  one two("b") four align;
  one three(S) two("a") four align;
  one three(S) two("t") four align;

  three(Ss) align;
  one two("s") four align;
  one three(Ss) two("a") four align;
  one three(Ss) two("t") four align;

  Green_book(EE);
}

N(programE) {
  one three(S) five align;
  three(S) align;
  one three(S) two("+") three(S) four align;
  one three(S) two("-") three(S) four align;
  one three(S) two("*") three(S) four align;
  one three(S) two("/") three(S) four align;
  one two("(") three(S) two(")") four align;
  one two("2") four align;
  one two("3") four align;
  Green_book(EE);
}

N(dodo) { P; }
N(halted) { Yellow(EE); }
int main() {
  long ο[3100];
  long β = 0;
  long α = 0;
  long τ = 0;
  long σ = 0;
  long ρ = sizeof(ο) / sizeof(*ο);
  long δ = 1;

  ο[--ρ] = 0;   ο[--ρ] = dodo; long ray = ρ; ο[--ρ] = 0;
  ο[--ρ] = ray; ο[--ρ] = ray;  ο[--ρ] = ray; ο[--ρ] = ray;
  β = α = ρ;
  οNavy(halted), programS(EE);
}

// clang-format off
N(Yellow_book);
N(Blue_book);
N(Green_book);
N(Red_book);
N(Purple_book);
N(Navy_book);
#define CM(nar) (σ + (1 << 8) < ρ ? (nar) : Navy)
N(Navy_3      ) { (ΔLime(1) == ο[τ + 1] ? Green     : Navy_book)(EE); }
N(clr_top     ) { (ΔLime(1) == ο[τ + 1] ? Red_Green : Red_Blue )(EE); }
N(clr         ) { (ΔLime(1) == ο[τ + 1] ? Red_Green : Maroon   )(EE); }
N(clr_top_Red ) { (ΔLime(1) == ο[τ + 1] ? Red_Green : Red_Blue )(EE); }
N(clr_Red     ) { (ΔLime(1) == ο[τ + 1] ? Red_Red   : Maroon   )(EE); }
N(search      ) { τ = σ, Navy_book(EE); }
N(re_tau      ) { τ = ΔLime(2), Lime(EE); }
N(Navy_name   ) { οNavy(Navy, τ), Blue_book(EE); }
N(Purple_31   ) { οLime(Green_book, ο[τ+1],τ), οMaroon(clr_Red), οOlive(re_tau); οGreen(Red_book),  CM(search)(EE); }
N(Yellow_31   ) { οLime(Green_book, ο[τ+1],τ), οMaroon(clr    ), οOlive(re_tau); οGreen(Navy_name), CM(search)(EE); }
N(Green_3     ) { οLime(Green_book, ο[τ+1],τ), οMaroon(clr_top), οOlive(re_tau); οGreen(Navy_name), CM(search)(EE); }
N(re_alfa     ) { α = ΔRed(1), Red(EE); }
N(Yellow_3    ) { οRed(Yellow_31, Yellow,       Yellow), οRed(Red_aradani, α), οRed(re_alfa), CM(Maroon)(EE); }
N(Purple_3    ) { οRed(Purple_31, Green_book,   Yellow), οRed(Red_aradani, α), οRed(re_alfa), CM(Maroon)(EE); }

N(cursor      ) { τ = ΔGreen(1),
                  α = ΔGreen(2),
                  ρ = ΔGreen(3), Green(EE); }
N(Blue_1      ) { οGreen(Blue_book,  τ,         α, ρ), οYellow(cursor); CM(Yellow_book)(EE); }
N(Red_1       ) { οGreen(Red_book,   τ,         α, ρ), οYellow(cursor); CM(Purple_book)(EE); }
N(Green_4     ) { οGreen(Green_book, τ,         α, ρ), οYellow(cursor);
                  οMaroon(clr_top_Red);
                  οGreen(Red_book,   ΔNavy(1),  α, ρ), οYellow(cursor); CM(Olive)(EE); }

N(Green_2     ) { οRed(Red, ο[τ+1]), CM(Green_book)(EE); }
N(Green_5     ) { long bo = β;
                  while(ΔRed(1)) printf("%s", (char*)ΔRed(1)), β = ΔRed(-1);
                  printf("\n"), β = bo, Green_book(EE); }

//N(Green_2) { const char *t = ο[τ + 1];
//                const char *s = ΔBlue(1);
//                long length   = ΔBlue(2);
//                long pos      = ΔBlue(3);
//                if (pos < length && s[pos] == t[0])
//                  οRed(Red, t),
//                  οBlue(Blue, s, length, pos + 1), Green_book(EE);
//                else
//                  Yellow(EE); }
N(Yellow_book) {
  static n_t narg[5] = {
    [2] = Green_2,
    [3] = Yellow_3,
    [4] = Green_4,
  }; τ += 11, narg[ο[τ]](EE);
}
N(Blue_book) {
  static n_t narg[5] = {
    [1] = Blue_1,
    [3] = Yellow,
    [0] = Yellow,
  }; τ += 1 << 8, narg[ο[τ]](EE);
}
N(Green_book) {
  static n_t narg[6] = {
    [2] = Green_2,
    [4] = Green_4,
    [3] = Green_3,
    [5] = Green_5,
    [0] = Yellow,
  }; τ += 11, narg[ο[τ]](EE);
}
N(Red_book) {
  static n_t narg[5] = {
    [1] = Red_1,
    [3] = Yellow,
    [0] = Yellow,
  }; τ += 1 << 8, narg[ο[τ]](EE);
}
N(Purple_book) {
  static n_t narg[5] = {
    [3] = Purple_3,
    [2] = Yellow,
    [4] = Yellow,
  }; τ += 11, narg[ο[τ]](EE);
}
N(Navy_book) {
  static n_t narg[5] = {
    [0] = Navy,
    [3] = Navy_3,
    [1] = Navy_book,
  }; τ -= 1 << 8, narg[ο[τ]](EE);
}
