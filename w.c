#include <assert.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
void *map_ram(const char *file) {
  int fd = open(file, O_RDONLY);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return 0;
  char *loaded_at_addr =
      mmap((void *)0x0000770000000000, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  if (loaded_at_addr == MAP_FAILED)
    return 0;
  *(long *)loaded_at_addr = sb.st_size / sizeof(void *);
  return loaded_at_addr;
}

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
unsigned long w(const char *aword, void **o) {
  char cmd[70];
  sprintf(cmd, "gcc -std=gnu17 -Wall -ffreestanding -O3 -c %s.c -o %s", aword,
          aword);
  assert(!system(cmd));
  sprintf(cmd, "ld -T b5o5.ld %s -o %s.elf", aword, aword);
  assert(!system(cmd));
  sprintf(cmd, "objcopy -O binary -j .text.* -j .text -j .data %s.elf %s",
          aword, aword);
  assert(!system(cmd));
  sprintf(cmd, "rm %s.elf", aword);
  assert(!system(cmd));

  FILE *bin = fopen(aword, "r");
  assert(bin);
  fseek(bin, 0, SEEK_END);
  long size = ftell(bin);
  fseek(bin, 5 * 16, SEEK_SET);
  long wc = (size -= 5 * 16 + 5 * 16 + 4) / sizeof(void *);
  assert(fread(o - wc, 1, size, bin) == size);
  fclose(bin);
  return wc;
}
