#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NexT T = strtok(NULL, " \n\t"), S = strlen(T)
#define Write(Y)                                                               \
  if (colors[Y])                                                               \
  S = snprintf(str, 70, "\nG(%s) { %s(o, a); }", colors[Y], colors[Y]),        \
  fwrite(str, 1, S, o)
void compile(const char *c) {
  char std[70];
  snprintf(std, 70, "gcc -std=gnu99 -Wall -ffreestanding -O3 -c %s.c -o %s.o", c, c),       system(std);
  snprintf(std, 70, "ld -T rainbow.ld %s.o -o %s.elf >/dev/null 2>&1", c, c),               system(std);
  snprintf(std, 70, "objcopy -O binary -j .text -j .data %s.elf %s.bin", c, c),             system(std);
  snprintf(std, 70, "tail --bytes=+81 %s.bin | head --bytes=-84 > %s", c, c),               system(std);
  snprintf(std, 70, "rm %s.elf %s.o %s.bin", c, c, c),                                      system(std);
}
int main(int argc, char**argv) {
  char s[2048];
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL)
    return printf("Error: could not open file\n"), 1;
  long length = fread(s, sizeof(char), sizeof(s) / sizeof(*s), fp);
  s[length] = 0;
  fclose(fp);
  const char *T = strtok(s, " \n\t");
  long S = strlen(T);
  char str[70];
  while (T != NULL) {
    char cname[70];
    snprintf(cname, 70, "%s.c", T);
    printf("%s\n", cname);
    FILE *o = fopen(cname, "w");
    S = snprintf(str, 70, "#include \"aw.h\"\n");
    fwrite(str, 1, S, o);

    NexT;
    if ('{' == T[0]) {
      const char *colors['Z'] = {['Y'] = "Yellow",  //
                                 ['P'] = "Purple",  //
                                 ['R'] = "Red",     //
                                 ['G'] = "Green",   //
                                 ['B'] = "Blue",    //
                                 ['N'] = "Navy",    //
                                 ['L'] = "Lime",    //
                                 ['M'] = "Maroon",  //
                                 ['F'] = "Fuchsia", //
                                 ['O'] = "Olive"};
      T++, S--;
      while (1) {
        if ('.' == T[S - 1]) {
          fwrite(T, 1, S - 2, o);
          break;
        } else {
          if (T[0] == 'G' && T[1] == '(')
            fwrite("\n", 1, 1, o), colors[(long)T[2]] = 0;
          fwrite(T, 1, S, o), NexT;
          fwrite(" ", 1, 1, o);
        }
      }
      Write('Y');
      Write('P');
      Write('R');
      Write('G');
      Write('B');
      Write('N');
      Write('L');
      Write('M');
      Write('F');
      Write('O');
    } else
      while(1) {
        printf("%s\n", T);
      }
    fclose(o);
    cname[strlen(cname) - 2] = 0;
    compile(cname);
    NexT;
  }
  return 0;
}
