#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wmathematical-notation-identifier-extension"

#define N(ame) void ame(long *o)
#define τ o[0]
#define β o[1]
#define σ o[2]
#define ρ o[3]
#define δ o[4]

enum Names {
  halt,
  beginning,
  tab,
  tword,
  put,
  dot,
  Names_count
};
static N(got) __attribute__((noinline));
extern int printf(const char *, ...);
extern int usleep(long);
static const char*rays[11] = {"Fuchsia","Olive","Maroon","Lime","Navy",0,"Blue","Green","Red","Yellow","Purple"};
#define P printf("%7s %4ld %s\n", rays[(ρ+1)*δ+5], τ, __func__), usleep(200000)


static N(_beginning) { P, δ = -δ, got(o); }
static N(_tab) {
  P;
  τ = o[β++];
  δ = -δ;
  got(o);
}
static N(_tword_pith) { P;
  o[--β] = τ, τ = o[τ + 3], got(o);
}
static N(_tword_init) {P;
  long words_count = o[τ + 2] << 8;
  long source_base = (((τ >> 8) + o[τ + 1]) << 8) - 5;
  o[τ + 5] = 1;
  o[τ + 3] = σ + 5;
  for (long i = 0; i < words_count; i++)
    o[σ + i] = o[source_base + i];
  σ += words_count;
  o[--β] = τ, τ = o[τ + 3], got(o);
}
static N(_tword) { P;
  static N((*sopcodes[])) = {_tword_init, _tword_pith};
  sopcodes[o[τ + 5]](o);
}
static N(_put) { P, printf("%c\n", (char)o[τ + 1]), got(o); }
static N(_dot) { P, δ = -δ, got(o); }
static N(_halt) { P; }

static N((*sopcodes[])) = {
  _halt,  _halt,      _halt,  _halt,  _halt,  (void*)halt,      _halt,  _halt,  _halt,  _halt,  _halt,
  0,      _beginning, 0,      0,      0,      (void*)beginning, 0,      0,      0,      0,      0,
  0,      _tab,       0,      0,      0,      (void*)tab,       0,      0,      0,      0,      0,
  0,      got,        0,      0,      0,      (void*)tword,     0,      _tword, _tword, _tword, 0,
  0,      got,        0,      0,      0,      (void*)put,       0,      0,      0,      _put,   0,
  0,      0,          0,      0,      0,      (void*)dot,       0,      0,      0,      _dot,   0,
};
static N(got  ) { sopcodes[o[τ += 11 * δ] * 11 + (ρ + 1) * δ + 5](o); }
// clang-format off
static long ram[0x10000];
int main () {
  long *o = ram;
  τ = β = σ = 512;
  σ -= 5;
  ρ = 3;
  δ = 1;
#define ν(a) (π++, o[σ++] = a)
#define _ ν(0)
#define T(s)        _,_,_,_,_,    (ν(s)),   _   ,_   ,_,_,_,
#define Ta(s, a)    _,_,_,_,_,    (ν(s)),   ν(a),_   ,_,_,_,
#define Tb(s, a, b) _,_,_,_,_,    (ν(s)),   ν(a),ν(b),_,_,_,
#define AL          ({ while (π < (1 << 8)) _; π = 0; }),
  long π = 0;

  T(beginning)  Tb(tword, 1, 3) Ta(put, '\n')                   T(dot) AL
  T(tab)        Ta(put, 't')                                    T(dot) AL
  T(tab)        Ta(put, 'a')                                    T(dot) AL
  T(tab)        Ta(put, 'b')                                    T(dot) AL
  T(tab)        Tb(tword, 1, 1) Tb(tword, 1, 1) Tb(tword, 1, 1) T(dot) AL //tritab
  T(tab)        Tb(tword, 1, 3)                                 T(dot) AL //tab
  T(tab)        Ta(put, 't')                                    T(dot) AL
  T(tab)        Ta(put, 'a')                                    T(dot) AL
  T(tab)        Ta(put, 'b')                                    T(dot) AL
  T(tab)        Tb(tword, 1, 2)                                 T(dot) AL
  T(tab)        Ta(put, 'b')                                    T(dot) AL
  T(tab)        Tb(tword,-1, 3) Ta(put, 'a')                    T(dot) AL
  T(tab)        Tb(tword,-2, 3) Ta(put, 't')                    T(dot) AL

  got(o);
}
