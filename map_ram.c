#include <assert.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
void *map_ram(const char *file) {
  int fd = open(file, O_RDONLY);
  struct stat sb;
  assert(fd != -1 && fstat(fd, &sb) != -1);
  char *loaded_at_addr =
      mmap((void *)0x0000770000000000, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  assert(loaded_at_addr != MAP_FAILED);
  *(long *)loaded_at_addr = sb.st_size / sizeof(void *);
  return loaded_at_addr;
}
