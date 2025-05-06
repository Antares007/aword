#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *s, *current_char;

void skip_ws() {
  while (*current_char == ' ')
    current_char++;
}

bool id() {
  if (isalpha(*current_char) || *current_char == '_') {
    current_char++;
    while (isalpha(*current_char) || isdigit(*current_char) ||
           *current_char == '_')
      current_char++;
    return true;
  }
  return false;
}

// ws → ' '
//    | ws ' '
bool ws() {
  if (*current_char != ' ')
    return false;
  current_char++;
  while (*current_char == ' ')
    current_char++;
  return true;
}

// ids          → id
//              | ids ws id
bool ids() {
  if (!id())
    return false;
  do {
    if (!ws())
      return true;
  } while (id());
  return false;
}

// name         → id
bool name() { return id(); }

// definition   → name '\n'
//              | name ws ids '\n'
bool definition() {
  if (!name())
    return false;
  if (*current_char == '\n') {
    current_char++;
    return true;
  }
  if (!ws())
    return false;
  if (!ids())
    return false;
  if (*current_char == '\n') {
    current_char++;
    return true;
  }
  return false;
}
// definitions  → definition
//              | definitions definition
bool definitions() {
  if (!definition())
    return false;
  while (definition())
    ;
  return true;
}
// grammer       → definitions EOF
bool grammer() { return definitions() && *current_char == '\0'; }
int main(int argc, char **argv) {
  char buffer[0x10000];
  int len;
  if (argc == 2) {
    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
      perror("fopen");
      return 1;
    }
    len = fread(buffer, 1, sizeof(buffer), fp);
    fclose(fp);
  } else {
    len = fread(buffer, 1, sizeof(buffer), stdin);
  }

  s = current_char = buffer;
  printf("\"%s\"\n", current_char);
  if (grammer())
    printf("accept\n");
  else
    printf("reject\n");
  return 0;
}
