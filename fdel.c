typedef void (*n_t)(char*);
void fdel (char*ec);
#include<stdio.h>
void zero (char*ec) { printf("0\n"), fdel(ec+1); }
void one  (char*ec) { printf("1\n"), fdel(ec+3); }
void four (char*ec) { printf("4\n"); /* halt  */ }
void fdel (char*ec) { 
  static n_t book[]             = {[0] = zero,[1] = one, [4] = four };
  long fetched_opcode           = ec[0];
  n_t decoded_narative          = book[fetched_opcode];
  char*updated_executionContext = ec + 1;
  decoded_narative(updated_executionContext);
}
int main() {
  char text[] = {0,3,0,0,1,0,0,1,4,9,1};
  fdel(text);
}
