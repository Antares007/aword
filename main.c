#include "aword.h"
#include <stdio.h>
#include <stdlib.h>

N(read_file) {
  const char *file_name = o[--a];
  FILE*file = fopen(file_name, "r");
  if (!file)
    return ((n_t *)o)[s + 2](t, a, b, o, s + 3);
  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  if ((s - a) * sizeof(void *) < size)
    return ((n_t *)o)[s + 2](t, a, b, o, s + 3);
  fseek(file, 0, SEEK_SET);
  long r = fread(o + a, 1, size, file);
  fclose(file);
  if (size != r)
    return ((n_t *)o)[s + 2](t, a, b, o, s + 3);
  a += (size + sizeof(void*) - 1) / sizeof(void*);
  ((n_t *)o)[s + 1](t, a, b, o, s + 3);
}

int main() {
  FILE *file = fopen("g.tab", "r");

  if (file == NULL) {
    perror("Error opening the file");
    return 1;
  }

  char buffer[1024];
  fread(buffer, 1, sizeof(buffer), file);
  fclose(file);
  printf("%s", buffer);
}
