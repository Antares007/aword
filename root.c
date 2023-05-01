#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

void *map_file(const char *file_name) {
  int fd = open(file_name, O_RDONLY);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return 0;
  char *loaded_at_addr =
      mmap((void *)0x0000770000000000, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  if (loaded_at_addr == MAP_FAILED)
    return 0;
  return loaded_at_addr;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
long w(void*o, const char*c) {
  char std[70];
  snprintf(std, 70, "gcc -std=gnu99 -Wall -ffreestanding -O3 -c %s.c -o %s.o", c, c),   system(std);
  snprintf(std, 70, "ld -T rainbow.ld %s.o -o %s.elf", c, c),                           system(std);
  snprintf(std, 70, "objcopy -O binary -j .text.* -j .text -j .data %s.elf %s", c, c),  system(std);
  snprintf(std, 70, "rm %s.elf %s.o", c, c),                                            system(std);
  FILE*f = fopen(c, "r");
  fseek(f, 0, SEEK_END);
  long s = ftell(f);
  fseek(f, 80, SEEK_SET);
  long r = fread(o, 1, s - 164, f);
  fclose(f);
  return r / sizeof(void*);
}
typedef void (*n_t)(void**o, long a);
int main() {
  void**o = map_file("ram.ram");
  long a  = 0;
  o[a++]  = printf;
  o[a++]  = usleep;
  a      += w(o + a, "b");
  a      += w(o + a, "m");
  a      += w(o + a, "o");
  
  ((n_t)(o + a - 2))(o, a);
}
