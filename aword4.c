// clang-format off
#include "aword.h"
#define NAMES X(beginning) X(end) X(halt) X(put) X(call) X(ret)
#define X(n)  void n##_Fuchsia (O *o); \
              void n##_Olive   (O *o); \
              void n##_Maroon  (O *o); \
              void n##_Lime    (O *o); \
              void n##_Navy    (O *o); \
              void n##_Blue    (O *o); \
              void n##_Green   (O *o); \
              void n##_Red     (O *o); \
              void n##_Yellow  (O *o); \
              void n##_Purple  (O *o);
NAMES
#undef X
enum names {
  #define X(n) n,
  NAMES
  #undef X
};
void (*sopcodes[])(O *) = {
#define X(n)  n##_Fuchsia, \
              n##_Olive  , \
              n##_Maroon , \
              n##_Lime   , \
              n##_Navy   , \
              0          , \
              n##_Blue   , \
              n##_Green  , \
              n##_Red    , \
              n##_Yellow , \
              n##_Purple ,
  NAMES
  #undef X
};
const char*names[] = {
  #define X(n) #n,
  NAMES
  #undef X
};
void got(O *o) __attribute__((noinline));
void got(O *o) {
  long opcode = o->ram[o->text_index = o->text_index + 11 * o->direction];
  (sopcodes[opcode * 11 + (o->ray + 1) * o->direction + 5])(o);
}

void halt_Fuchsia(O *o) {}
void halt_Olive(O *o) {}
void halt_Maroon(O *o) {}
void halt_Lime(O *o) {}
void halt_Navy(O *o) {}
void halt_Blue(O *o) {}
void halt_Green(O *o) {}
void halt_Red(O *o) {}
void halt_Yellow(O *o) {}
void halt_Purple(O *o) {}

void put_Fuchsia(O *o) {P;}
void put_Olive  (O *o) {P; got(o); }
void put_Maroon (O *o) {P;}
void put_Lime   (O *o) {P;}
void put_Navy   (O *o) {P;}
void put_Blue   (O *o) {P;}
void put_Green  (O *o) {P;}
void put_Red    (O *o) {P;}
void put_Yellow (O *o) {P;
  printf("%c", (char)o->ram[o->text_index + 5]);
  got(o);
}
void put_Purple (O *o) {}

void call_Fuchsia (O *o) {}
void call_Olive   (O *o) {}
void call_Maroon  (O *o) {}
void call_Lime    (O *o) {}
void call_Navy    (O *o) {}
void call_Blue    (O *o) {}
void call_Green   (O *o) {}
void call_Red     (O *o) {}
void call_Yellow  (O *o) {
  o->ram[--o->back_stack] = o->text_index;
  o->text_index = o->text_index + o->ram[o->text_index + 5] * 11;
  got(o);
}
void call_Purple  (O *o) {}

void ret_Fuchsia(O *o) {}
void ret_Olive  (O *o) {}
void ret_Maroon (O *o) {}
void ret_Lime   (O *o) {}
void ret_Navy   (O *o) {}
void ret_Blue   (O *o) {}
void ret_Green  (O *o) {}
void ret_Red    (O *o) {}
void ret_Yellow (O *o) { o->text_index = o->ram[o->back_stack++]; got(o); }
void ret_Purple (O *o) {}


void end_Fuchsia(O *o) {P;}
void end_Olive  (O *o) {P;}
void end_Maroon (O *o) {P;}
void end_Lime   (O *o) {P;}
void end_Navy   (O *o) {P;}
void end_Blue   (O *o) {P;}
void end_Green  (O *o) {P;}
void end_Red    (O *o) {P;}
void end_Yellow (O *o) {P; o->direction = -o->direction; got(o); }
void end_Purple (O *o) {P;}

void beginning_Fuchsia(O *o) {P;}
void beginning_Olive  (O *o) {P;}
void beginning_Maroon (O *o) {P;}
void beginning_Lime   (O *o) {P;}
void beginning_Navy   (O *o) {P;}
void beginning_Blue   (O *o) {P;}
void beginning_Green  (O *o) {P;}
void beginning_Red    (O *o) {P;}
void beginning_Yellow (O *o) {P; o->direction = -o->direction; got(o); }
void beginning_Purple (O *o) {P;}

O ram[1024];
int main() {
  O *o              = ram;
  o->advance        = 0;
  o->back_stack     = 255;
  o->text_index     = o->space = o->back_stack + 5;
  o->ray            = 3;
  o->direction      = 1;


  o->ram[o->space]  = beginning,                          o->space += 11,
  o->ram[o->space]  = put,  o->ram[o->space + 5] = '\n',  o->space += 11,
  o->ram[o->space]  = end,                                o->space += 11,
  got(o);
}
