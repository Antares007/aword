#include <stdio.h>
void Purple_cb(void **o, long a) { printf("%s\n", __FUNCTION__); }
void Green_cb(void **o, long a) { printf("%s\n", __FUNCTION__); }
typedef void (*aword_t)(void **o, long a);
aword_t w(const char *aword, void**o) {
}
void *map_ram(const char *file);

int main() {
  void **o = map_ram("ram.ram");
  long a = (long)o[0] / 8;
  w("b", o), w("m", o), w("o", o);

  printf("%ld\n", a);

  return 0;
}
