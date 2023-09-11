#ifndef NDEBUG
#include <stdio.h>
#include <unistd.h>
#define L printf("%10s %4ld %4ld\n", __FUNCTION__, a, s), usleep(20000)
#define Λ L, printf("\n")
#else
#define L (void)0
#define Λ (void)0
#endif

#define N(argo) void argo(long a, void**o, long s)
typedef N((*n_t));
N(Got) { L; ((n_t*)o)[s+2](a, o, s+3); }
N(God) { L; ((n_t*)o)[s+1](a, o, s+3); }
N(Gor) { L; ((n_t*)o)[s+0](a, o, s+3); }
N(Maroon_end) { L; }
N(Olive_end ) { L; }
N(Navy_end  ) { L; }

#define ALIGN(O, A) ((((O) + ((A) - 1)) / (A)) * (A))
N(stop    ) { L; }
N(space   ) { L; ((n_t*)o)[a-1](a-1, o, s); }
N(newline ) { L; ((n_t*)o)[a-1](a-1, o, s); }
N(dot     ) { L; ((n_t*)o)[a-1](a-1, o, s); }
N(name    ) { L;
  long wc = (long)o[--a];
  printf("%s\n", (char*)&o[a -= wc]);
  ((n_t*)o)[a-1](a-1, o, s);
}
N(Main    ) { L;
  const char *in = o[--a];
  long len = 0;
  while (in[len]) {
    if (       ' '  == in[len]) { o[a++] = space;   len++;
    } else if ('\n' == in[len]) { o[a++] = newline; len++;
    } else if ('.'  == in[len]) { o[a++] = dot;     len++;
    } else {
      long start = len;
      char*out = (char*)&o[a];
      while (in[len] && in[len] != ' ' && in[len] != '\n' && in[len] != '.') *out++ = in[len++];
      *out++ = '\0';
      long name_len = len - start;
      long wc       = ALIGN(name_len + 1, sizeof(void*)) / sizeof(void*);
      a            += wc;
      o[a++] = (void*)wc;
      o[a++] = name;
    }
  }
  ((n_t*)o)[s + 1](a, o, s + 3);
}
int main(int argc, const char **argv) {
  long a = 0;
  void *o[512];
  long s = sizeof(o) / sizeof(*o);

  o[--s] = Maroon_end;  o[--s] = Olive_end; o[--s] = Navy_end;
  o[--s] = Got;         o[--s] = dot;       o[--s] = Gor;
  o[a++] = stop;
  o[a++] = "Name as sentence\n"
           "First definition as sentence. Second definition as sentence.\n"
           "\n"
           "Name1\n"
           "Word1 word2 word3.";
  Main(a, o, s);
  return 0;
}
