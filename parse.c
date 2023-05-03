#include "evalmap.h"
#include <stdio.h>
#include <string.h>

#define NexT T = strtok(NULL, " \n\t"), S = strlen(T)
#define Write(Y)                                                               \
  if (colors[Y])                                                               \
  S = snprintf(str, 70, "\nG(%s) { %s(o, a); }", colors[Y], colors[Y]),        \
  fwrite(str, 1, S, o)
int main() {
  char s[2048];
  FILE *fp = fopen("input.tab", "r");
  if (fp == NULL)
    return printf("Error: could not open file\n"), 1;
  long length = fread(s, sizeof(char), sizeof(s) / sizeof(*s), fp);
  s[length] = 0;
  fclose(fp);
  const char *T = strtok(s, " \n\t");
  long S = strlen(T);
  char str[70];
  while (T != NULL) {
    snprintf(str, 70, "%s.c", T);
    FILE *o = fopen(str, "w");
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
      printf("wtf\n");
    fclose(o);
    NexT;
  }
  return 0;
}
