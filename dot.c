#include "sophis.h"
#include <stdio.h>
static long stack_top;
S(print_Teal) {
  static char buffer[1024];
  if (ωTeal[1]) {
    int n = snprintf( buffer,
                      sizeof(buffer),
                      "\"%s (%ld)\" -> \"%s (%ld)\";\n",
                      (char *)ωTeal[1], ωTeal[2],
                      (char *)ωTeal[3], ωTeal[4]);
    fwrite(buffer, 1, n, βBlue[1]);
  }
  Teal(OS);
}
static long getid(long *ray) { return (stack_top - (long)ray) / 8*8; }
N(dot_begin   ) { stack_top = β, οNavy(Navy, τ, 0), οTeal(Green, 0), Green(OS); }
N(term);
N(dot_simbol  ) { long **pa = α[0][-1];
                  οTeal(print_Teal, ο[pa[0][1] + 2], getid(pa[0]), ο[α[0][1] + 2], getid(α[0])), Green(OS); }
N(dot_epsilon ) { οTeal(print_Teal, ο[α[0][1] + 2],  getid(α[0]),  ο[τ + 2],       ο[τ + 3]++),  Green(OS); }
N(dot_terminal) { οTeal(print_Teal, ο[α[0][1] + 2],  getid(α[0]),  ο[τ + 2],       ο[τ + 3]++),  term(OS); }

S(re_omega) { ω = βGreen[1], Green(OS); }

S(file_close) { fclose(βBlue[1]), Green(OS); }
S(write_dot_tail) {
  fwrite("}\n", 1, 2, βBlue[1]);
  Green(OS);
}
#include <stdlib.h>
S(dot_show) {
  static char buffer[1024];
  snprintf(buffer, sizeof(buffer), "dot -Tpng %s -o %s.png", (char*)βBlue[2],
                                                             (char*)βBlue[2]);
  system(buffer), printf("okular %s.png\n", (char*)βBlue[2]), Green(OS);
}
S(file_open) {
  static int i = 0;
  static char buffer[100];
  snprintf(buffer, sizeof(buffer), "parse_tree_%d.dot", i++);
  FILE *fp;
  fp = fopen(buffer, "w");
  if (fp)
    οBlue(Blue, fp, buffer), 
      οGreen(dot_show), 
        οGreen(file_close), 
          οGreen(write_dot_tail),
            Teal(OS);
  else
    Cyan(OS);
}
S(write_dot_head) {
  static char buffer[1024];
  int n = snprintf(buffer, sizeof(buffer), "digraph \"%s\" {\nrankdir=LR;\n", (char*)βBlue[2]);
  fwrite(buffer, 1, n, βBlue[1]);
  Teal(OS);
}
N(dot_end) {
  οGreen(Green, ω),
    οGreen(re_omega),
  οCyan(Blue),
    οTeal(print_Teal),
      οTeal(write_dot_head),
        οTeal(file_open);
          Teal(OS);
}
