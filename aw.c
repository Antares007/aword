#define N(argo) void argo(void **ο, long α, long ρ, long σ)
typedef N((*n_t));
#ifndef NDEBUG
#include <stdio.h>
#include <unistd.h>
#define L printf("%10s %4ld %4ld\n", __FUNCTION__, ρ, σ), usleep(200000)
#define Λ L, printf("\n")
#else
#define L (void)0
#define Λ (void)0
#endif
#define FW ((n_t *)ο)[ρ](ο, α, ρ + 1, σ)
#define BW ((n_t *)ο)[σ](ο, α, σ + 1, ρ)
N(o_Fuchsia);
N(o_Purple ) {Λ; (ο[--σ] = o_Fuchsia), BW; }
N(o_Green  ) {L, (ο[--ρ] = o_Purple ), BW; }
N(o_Yellow ) {L, (ο[--ρ] = o_Green  ), BW; }
N(o_Fuchsia) {L, (ο[--σ] = o_Yellow ), FW; }
N(m_Fuchsia);
N(m_Purple ) {L, (ο[--σ] = m_Fuchsia), FW; }
N(m_Olive  ) {L, (ο[--σ] = m_Purple ), FW; }
N(m_Green  ) {L, (ο[--σ] = m_Olive  ), FW; }
N(m_Lime   ) {L, (ο[--σ] = m_Green  ), FW; }
N(m_Yellow ) {L, (ο[--σ] = m_Lime   ), FW; }
N(m_Fuchsia) {L, (ο[--σ] = m_Yellow ), FW; }
N(b_Fuchsia);
N(b_Olive  ) {L, (ο[--ρ] = b_Fuchsia), BW; }
N(b_Lime   ) {L, (ο[--ρ] = b_Olive  ), BW; }
N(b_Fuchsia) {L, (ο[--ρ] = b_Lime   ), BW; }
int main() {
  void *ο[1024];
  long α = 0;
  long ρ = 512;
  long σ = 1024;
  ο[--ρ] = b_Fuchsia;
  ο[--ρ] = m_Fuchsia;
  ο[--ρ] = o_Fuchsia;
  ((n_t *)ο)[ρ](ο, α, ρ + 1, σ);
}

//  o_Fuchsia  510 1024
//  m_Fuchsia  511 1023
//  b_Fuchsia  512 1022
//   b_Yellow 1022  512
//   m_Yellow 1023  511
//   o_Yellow 1024  510
//     o_Lime  510 1024
//     m_Lime  511 1023
//     b_Lime  512 1022
//    b_Green 1022  512
//    m_Green 1023  511
//    o_Green 1024  510
//    o_Olive  510 1024
//    m_Olive  511 1023
//    b_Olive  512 1022
//   b_Purple 1022  512
//   m_Purple 1023  511
//   o_Purple 1024  510
