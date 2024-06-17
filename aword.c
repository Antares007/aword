// clang-format off
#pragma GCC diagnostic ignored "-Wint-conversion"
#define S(argo) void argo(long *ο, long β, long α, long τ, long σ, long ρ, long δ)
#define aContext ο, β, α, τ, σ, ρ, δ
typedef S((*n_t));
extern int printf (const char *, ...);
enum Names { ret, call, halt, print, fork };
S(goTo      );
S(ret_nar   ) {                          τ = ο[β++], goTo(aContext); }
S(call_nar  ) {           ο[--β] = τ, τ += ο[τ + 5], goTo(aContext); }
S(print_nar ) { printf("%ld %ld\n", ο[0], ο[τ + 5]), goTo(aContext); }
S(halt_nar  ) { }
static void*h[2];    // multitasking queue, double linked list, "(h)ead" 
static long pid = 0; // process id
S(fork_nar  ) { long a;
                long*s = (long[5 * 1024]) {};
                for(a = 0; a < 5 * 1024; a++) s[a] = ο[a];
                s[0] = pid++;
                // save aContext within omicrons alfa stack
                a = α, ο[a++] = ο, ο[a++] = β, ο[a++] = α, ο[a++] = τ,
                       ο[a++] = σ, ο[a++] = ρ, ο[a++] = δ;
                // queue omicron
                ο[a+0] = h, ο[a+1] = h[1], ((void**)h[1])[0] = &ο[a], h[1] = &ο[a];
                                              ο = s, goTo(aContext); }
static n_t nars[] = {ret_nar, call_nar, halt_nar, print_nar, fork_nar};
S(goTo      ) { long a;
                // save aContext within omicrons alfa stack
                a = α, ο[a++] = ο, ο[a++] = β, ο[a++] = α, ο[a++] = τ,
                       ο[a++] = σ, ο[a++] = ρ, ο[a++] = δ;
                // queue omicron (last in)
                ο[a+0] = h, ο[a+1] = h[1], ((void**)h[1])[0] = &ο[a], h[1] = &ο[a];
                // dequeue omicron (first out)
                ο = h[0], ((void**)ο[0])[1] = ο[1], ((void**)ο[1])[0] = ο[0];
                // restore aContext from alfa stack
                a = 0, δ = ο[--a], ρ = ο[--a], σ = ο[--a], τ = ο[--a],
                       α = ο[--a], β = ο[--a], ο = ο[--a];
                                      τ += 11, nars[ο[τ]](aContext); }
int main(   ) {
  long β = 1024;      // back stack (i.e. call stack)
  long ο[β * 5] = {}; // omicron (base pointer)
  long α = 0;         // alfa stack
  long τ = β;         // text index (i.e. program counter)
  long σ = τ;         // text space
  long ρ = 3;         // reserved
  long δ = 1;         // reserved
  h[0] = h[1] = h;    // init multitasking queue
  ο[α++] = pid++;     // set main process id 
  // Below we are using CPU's language to write
  // SCPU's text members, i.e., program in SCPU's language.
  // Each SCPU's text member is 11*8 ("sizeof(long)") bytes
  // in width and contains only binary data.
  // There is an extra parameter along with the call opcode
  // indicating the relative offset, in bytes, of the
  // procedure to call.
  ο[σ] = fork,                    σ += 11;
  ο[σ] = call,    ο[σ + 5] = 44,  σ += 11;
  ο[σ] = call,    ο[σ + 5] = 55,  σ += 11;
  ο[σ] = call,    ο[σ + 5] = 66,  σ += 11;
  ο[σ] = print,   ο[σ + 5] = 5,   σ += 11;
  ο[σ] = halt,                    σ += 11;
  ο[σ] = print,   ο[σ + 5] = 1,   σ += 11;
  ο[σ] = ret,                     σ += 11;
  ο[σ] = print,   ο[σ + 5] = 2,   σ += 11;
  ο[σ] = ret,                     σ += 11;
  ο[σ] = print,   ο[σ + 5] = 3,   σ += 11;
  ο[σ] = ret,                     σ += 11;
  τ -= 11, goTo(aContext);
  return 0;
}

