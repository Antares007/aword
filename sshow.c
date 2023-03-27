#include "sword.h"
#include <stdio.h>
#include <unistd.h>
void print(word) {
  if (r == 1 && d == -3)
    printf("%s", (char *)o[w + 1]), usleep(200);
  m(a, w, o, r, d);
}
S(abos,                                                        //
  T(b) Ta(print, "}")       LastArm;  //
  T(b) Ta(print, "{\"a\":") RightArm;
  T(b) Ta(print, "},")      LeftArm;  //
  T(b) Ta(print, "{\"b\":") RightArm;
                                      T(b) Ta(print, "},")      LeftArm;
  T(b) Ta(print, "{\"t\":") RightArm;  //
)
S(abos0,                                                      //
  T(b) Ta(print, "}") LastArm;  //
  T(b) Ta(print, "{\"o\":") RightArm;
)
int main() {
  long a = 512;
  void *o[a];
  long r = 3, d = 3;
  T(b)
  Ta(print, "7") T(abos)  T(abos0)
      Ta(print, "\n") T(dot)

          m(a, a + 1, o, r, d);
  return 0;
}
