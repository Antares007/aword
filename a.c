// clang-format off
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#define N(argo) void argo(uint8_t *o, void**b, void**a, uint8_t *t, long s, void**r)

#ifndef NDEBUG
#define P printf("%s ", __func__)
#else
#define P (void)0
#endif

extern N((*nars[]));

// how to represent 2d text on quattro stack
// which primarly includes most abstract definitions
N(nBEGINNING) { printf("beginning "),                                   nars[*t](o, b, a, t + 1, s, r); }
N(nTAB      ) { printf("  "),                                           nars[*t](o, b, a, t + 1, s, r); }
N(nEND      ) { printf("end ") ,                                        nars[*t](o, b, a, t + 1, s, r); }
N(nDOT      ) { printf(". "),                                           nars[*t](o, b, a, t + 1, s, r); }
N(nPRINT    ) { printf("print "),                                       nars[*t](o, b, a, t + 1, s, r); }
N(nNAME     ) { printf("%c ", *t++),                                    nars[*t](o, b, a, t + 1, s, r); }
N(nTWORD    ) { printf("%c ", *t++),                                    nars[*t](o, b, a, t + 1, s, r); }
N(nAWORD    ) { printf("\"%c\" ", *t++),                                nars[*t](o, b, a, t + 1, s, r); }
N(nNL       ) { printf("\n"), t = (void *)(((uintptr_t)t + 15) & -16),  nars[*t](o, b, a, t + 1, s, r); }
N(nHALT     ) {}

#define XNAMES\
  X(HALT) X(BEGINNING) X(END) X(TAB) X(NAME) X(TWORD) X(AWORD) X(PRINT) X(DOT) X(NL)

#define X(name) o##name,
typedef enum { XNAMES } Names;
#undef X

#define X(name) n##name,
N((*nars[])) = {XNAMES};
#undef X

int main() {
  uint8_t o[1024] __attribute__((aligned(16)));
  uint8_t *t = o;
  uintptr_t s = 0;
  assert((uintptr_t)o % 16 == 0);

  o[s++] = oBEGINNING, o[s++] = oTWORD, o[s++] = 's', o[s++] = oPRINT, o[s++] = oEND,               o[s++] = oNL, s = (s+15)&-16;
  o[s++] = oNAME,      o[s++] = 's',                                                                o[s++] = oNL, s = (s+15)&-16;
  o[s++] = oTAB,       o[s++] = oAWORD, o[s++] = 'b', o[s++] = oDOT,                                o[s++] = oNL, s = (s+15)&-16;
  o[s++] = oTAB,       o[s++] = oTWORD, o[s++] = 's', o[s++] = oAWORD, o[s++] = 's', o[s++] = oDOT, o[s++] = oNL, s = (s+15)&-16;
  o[s++] = oTAB,       o[s++] = oTWORD, o[s++] = 's', o[s++] = oAWORD, o[s++] = 't', o[s++] = oDOT, 
                                                      o[s++] = oAWORD, o[s++] = 'o', o[s++] = oDOT, o[s++] = oNL, s = (s+15)&-16;
  o[s  ] = oHALT;

  nars[*t](o, 0, 0, t + 1, s, 0);

}
