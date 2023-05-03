#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define ALIGN(O, A) ((unsigned long)(((O) + ((A)-1)) / (A))) * (A)
void *map_pith(const char *file_name) {
  int fd = open(file_name, O_RDONLY);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return 0;
  static unsigned long static_start_address = 0x0000770000000000;
  char *loaded_at_addr =
      mmap((void *)static_start_address, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  if (loaded_at_addr == MAP_FAILED)
    return 0;
  static_start_address += ALIGN(sb.st_size, 16);
  return loaded_at_addr;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
typedef void (*n_t)(void**o, long a);
void compile(const char *c) {
  char std[70];
  snprintf(std, 70, "gcc -std=gnu99 -Wall -ffreestanding -O3 -c %s.c -o %s.o", c, c),       system(std);
  snprintf(std, 70, "ld -T rainbow.ld %s.o -o %s.elf", c, c),                               system(std);
  snprintf(std, 70, "objcopy -O binary -j .text.* -j .text -j .data %s.elf %s.bin", c, c),  system(std);
  snprintf(std, 70, "tail --bytes=+81 %s.bin | head --bytes=-84 > %s", c, c),               system(std);
  snprintf(std, 70, "rm %s.elf %s.o %s.bin", c, c, c),                                      system(std);
}
#include <string.h>
n_t compose(int n, char**words) {
  char sentence[1024] = {};
  for(long i = 0; i < n; i++){
    compile(words[i]);
    strcat(sentence, words[i]);
    if (i+1<n) strcat(sentence, " ");
  }
  char cmd[4096];
  snprintf(cmd, 4096, "cat b %s o > %s.s\n", sentence, sentence), system(cmd);
  snprintf(cmd, 4096, "%s.s", sentence);
  return map_pith(cmd);
}

int main(int argc, char**argv) {
  void*o[1024];
  long a  = 0;
  o[a++]  = printf;
  o[a++]  = usleep;
  o[a++]  = compose;
  compose(argc - 1, argv + 1)(o, a);
}
// 
