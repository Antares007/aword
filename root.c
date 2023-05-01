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
  static_start_address +=
      ALIGN(sb.st_size, 0x1000); // goto next page for future loads
  //  ((unsigned long *)loaded_at_addr)[31] = sb.st_size;
  return loaded_at_addr;
}

int main() {}
