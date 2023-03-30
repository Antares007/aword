#include "aword.h"
#include <stdio.h>
N(Purple_cb) { printf("%s\n", __FUNCTION__); }
N(Green_cb) { printf("%s\n", __FUNCTION__); }
typedef N((*aword_t));

void *map_ram(const char *file);

unsigned long w(const char *aword, void **o);
#define T(...)
#include <unistd.h>
int main() {
  void **o = map_ram("ram.ram");
  long a = (long)o[0];
  long t = 0;
  o[t++] = printf;
  o[t++] = usleep;
  o[t++] = Purple_cb;
  o[t++] = Green_cb;

  a -= w("b", o + a), a -= w("m", o + a), a -= w("o", o + a);

  ((aword_t)(o + a + 2 * 0))(o, t, a);
  //((aword_t)(o + a + 2*1))(o, a);
  //((aword_t)(o + a + 2*2))(o, a);
  //((aword_t)(o + a + 2*3))(o, a);
  //((aword_t)(o + a + 2*4))(o, a);
  return 0;
}
