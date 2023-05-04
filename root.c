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
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE, fd, 0);
  close(fd);
  if (loaded_at_addr == MAP_FAILED)
    return 0;
  static_start_address += ALIGN(sb.st_size, 16);
  return loaded_at_addr;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef void (*n_t)(void**o, long a);
n_t compose(const char*text) {
  char cmd[4096];
  snprintf(cmd, 4096, "cat %s > '%s'\n", text, text), system(cmd);
  return map_pith(text);
}

int main(int argc, char**argv) {
  void*o[1024];
  long a  = 0;
  o[a++]  = printf;
  o[a++]  = usleep;
  o[a++]  = compose;
  n_t w = map_pith(argv[1]);
  printf("%p\n", w);w(o, a);
}
// 
