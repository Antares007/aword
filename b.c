// clang-format off
#pragma GCC diagnostic ignored "-Wint-conversion"
#include <stdint.h>
#define Go ο,β,α,τ,σ,ρ,δ
#define N(argo) void argo(void**ο, void**β, void**α, void**τ, void**σ, void**ρ, void**δ)

static void*ram[0x10000], **orgn = ram + sizeof(ram) / sizeof(*ram) / 2;

#ifndef NDEBUG
#include <stdio.h>
#include <unistd.h>
#define P printf("%9s %6ld%6ld%6ld%6ld%6ld%6ld%6ld\n", __func__, ο-orgn, β-orgn, α-orgn, τ-orgn, σ-orgn, ρ-orgn, δ-orgn), usleep(200000)
#else
#define P (void)0
#endif

typedef N((*n_t));

#define QuattrO3(β) (ο[0] = β[0], ο[1] = β[1], ο[2] = β[2], ο[3] = ο,    ο[4] = β, β = ο, ο += 5)
#define QuattrO2(β) (ο[0] = β[0], ο[1] = β[1], ο[2] = ο,    ο[3] = β[3], ο[4] = β, β = ο, ο += 5)
#define QuattrO1(β) (ο[0] = β[0], ο[1] = ο,    ο[2] = β[2], ο[3] = β[3], ο[4] = β, β = ο, ο += 5)
#define QuattrO0(β) (ο[0] = ο,    ο[1] = β[1], ο[2] = β[2], ο[3] = β[3], ο[4] = β, β = ο, ο += 5)
#define QuattRo3(σ) (ρ -= 5, ρ[4] = σ, ρ[3] = ρ,    ρ[2] = σ[2], ρ[1] = σ[1], ρ[0] = σ[0], σ = ρ)
#define QuattRo2(σ) (ρ -= 5, ρ[4] = σ, ρ[3] = σ[3], ρ[2] = ρ,    ρ[1] = σ[1], ρ[0] = σ[0], σ = ρ)
#define QuattRo1(σ) (ρ -= 5, ρ[4] = σ, ρ[3] = σ[3], ρ[2] = σ[2], ρ[1] = ρ,    ρ[0] = σ[0], σ = ρ)
#define QuattRo0(σ) (ρ -= 5, ρ[4] = σ, ρ[3] = σ[3], ρ[2] = σ[2], ρ[1] = σ[1], ρ[0] = ρ,    σ = ρ)
#define o_Red       QuattrO3(β)
#define o_Yellow    QuattrO2(β)
#define o_Green     QuattrO1(β)
#define o_Blue      QuattrO0(β)
#define o_Maroon    QuattrO3(α)
#define o_Olive     QuattrO2(α)
#define o_Lime      QuattrO1(α)
#define o_Navy      QuattrO0(α)
#define Red_r       QuattRo3(σ)
#define Yellow_r    QuattRo2(σ)
#define Green_r     QuattRo1(σ)
#define Blue_r      QuattRo0(σ)
#define Maroon_r    QuattRo3(δ)
#define Olive_r     QuattRo2(δ)
#define Lime_r      QuattRo1(δ)
#define Navy_r      QuattRo0(δ)

#define S(Red, σ, ι)                            \
  __attribute__((noinline))                     \
  N(Red) {                                      \
    P;                                          \
    n_t nar = ((void***)σ)[ι][5];               \
    σ = ((void***)σ)[ι][4];                     \
    nar(Go);                                    \
  } 

#define QuattroS(σ, Red, Yellow, Green, Blue)   \
  S(Red,    σ, 3)                               \
  S(Yellow, σ, 2)                               \
  S(Green,  σ, 1)                               \
  S(Blue,   σ, 0)

QuattroS(σ, Red_s,     Yellow_s,  Green_s, Blue_s)
QuattroS(δ, Maroon_d,  Olive_d,   Lime_d,  Navy_d)
QuattroS(β, b_Red,     b_Yellow,  b_Green, b_Blue)
QuattroS(α, a_Maroon,  a_Olive,   a_Lime,  a_Navy)

#undef S
#undef QuattroS

N(dodo3) {P, *--ρ = Red_s, Red_r, Red_s(Go); }
N(dodo4) {P, o_Red, *ο++ = b_Red, b_Red(Go); }

N(capstone) { P; }

int main() {
  void**ο = orgn, **β, **α, **τ=ο, **σ, **ρ = ο, **δ;

  ο[0] = ο, ο[1] = ο, ο[2] = ο, ο[3] = ο, ο[4] = ο,
  β = α = ο,
  ο += 5,
  *ο++ = *--ρ = capstone,
  ρ -= 5,
  δ = σ = ρ, 
  ρ[4] = ρ, ρ[3] = ρ, ρ[2] = ρ, ρ[1] = ρ, ρ[0] = ρ;

  for(long i = 0; i < 3; i++)
    o_Red,    *ο++ = Yellow_s, *--ρ = b_Red,      Navy_r,
    o_Lime,   *ο++ = Navy_d,   *--ρ = a_Lime,    Olive_r,
    o_Maroon, *ο++ = Olive_d,  *--ρ = a_Maroon,   Blue_r,
    o_Green,  *ο++ = Blue_s,   *--ρ = b_Green,  Yellow_r,
    o_Navy,   *ο++ = Yellow_s, *--ρ = a_Navy,     Lime_r,
    o_Olive,  *ο++ = Lime_d,   *--ρ = a_Olive,  Maroon_r,
    o_Blue,   *ο++ = Maroon_d, *--ρ = b_Blue,    Green_r,
    o_Yellow, *ο++ = Green_s,  *--ρ = b_Yellow,    Red_r;

  Red_s(Go);
}
