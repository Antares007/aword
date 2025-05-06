#define N(argo) void argo(void **o, long s, long t)
#define S(argo) static N(argo)

#include <stdio.h>

// clang-format off
S((*book_of_print[]));

S(zero      ) { printf("zero\n"); }
S(one       ) { printf("{1}"); t++,             book_of_print[(long)o[t]](o,s,t+1); }
S(two       ) { printf("%s  ", (char*)o[t++]);  book_of_print[(long)o[t]](o,s,t+1); }
S(three     ) { printf("\n"); t++,              book_of_print[(long)o[t]](o,s,t+1); }
S(four      ) { printf("\n%s ", (char*)o[t++]); book_of_print[(long)o[t]](o,s,t+1); }
S(five      ) { printf("."); t++,               book_of_print[(long)o[t]](o,s,t+1); }
S(six       ) { printf("{6}"); t++,             book_of_print[(long)o[t]](o,s,t+1); }

S((*book_of_print[])) = {
    zero, one, two, three, four, five, six,
};

void run(void **o, long s) {
  //
  long t = 0;
  book_of_print[(long)o[t]](o, s, t + 1);
}
