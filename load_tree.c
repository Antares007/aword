#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#define ALIGN(O, A) ((unsigned long)(((O) + ((A)-1)) / (A))) * (A)
void *load_tree(const char *hash) {
  static void *map[1024][2];
  static int length = 0;
  for (long i = 0; i < length; i++)
    if (strcmp(map[i][0], hash) == 0)
      return map[i][1];
  char str[100] = "node ./compile_tree.js ";
  if (system(strcat(str, hash)) != 0)
    return 0;
  char path[100] = "cadb/";
  path[5] = hash[0];
  path[6] = hash[1];
  path[7] = '/';
  path[8] = 0;
  strcat(path, hash + 2);

  int fd = open(path, O_RDONLY);
  struct stat sb;
  if (fd == -1 || fstat(fd, &sb) == -1)
    return 0;
  static unsigned long static_start_address = 0x0000770000000000;
  char *loaded_at_addr =
      mmap((void *)static_start_address, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  if (loaded_at_addr == MAP_FAILED) {
    printf("\nhash7 errno: %d\n", errno), getchar();
    return 0;
  }
  static_start_address += ALIGN(sb.st_size, 0x1000);
  loaded_at_addr += sb.st_size;
  map[length][0] = (void *)hash;
  map[length][1] = (void *)loaded_at_addr;
  length++;
  return (void *)loaded_at_addr;
}
