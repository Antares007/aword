// clang-format off
extern int printf(const char *__restrict __format, ...);
typedef struct {
  long text_index;
  long back_stack;
  long space;
  long ram[];
} O;
void goTo (O *o);
void halt (O *o) {}
void id   (O *o) {
  goTo(o);
}
void jmp  (O* o) {
  o->text_index = o->ram[o->text_index + 5];
  goTo(o);
}
void put  (O *o) {
  printf("%c", (char)o->ram[o->text_index + 5]);
  goTo(o);
}
void call(O *o) {
  o->ram[--o->back_stack] = o->text_index;
  o->text_index = o->text_index + o->ram[o->text_index + 5] * 11;
  goTo(o);
}
void ret(O *o) {
  o->text_index = o->ram[o->back_stack++];
  goTo(o);
}
void (*sopcodes[])(O *) = { halt, put, call, ret, };
const char*names[] = { "halt", "put", "call", "ret" };
#define Halt    o->ram[o->space] = 0,                             o->space += 11,
#define Put(a)  o->ram[o->space] = 1, o->ram[o->space + 5] = (a), o->space += 11,
#define Call(a) o->ram[o->space] = 2, o->ram[o->space + 5] = (a), o->space += 11,
#define Ret     o->ram[o->space] = 3,                             o->space += 11,
void goTo(O *o) __attribute__((noinline));
void goTo(O *o) { (sopcodes[o->ram[o->text_index += 11]])(o); }
O ram[1024];
int main() {
  O *o          = ram;
  o->back_stack = 255;
  o->text_index = o->space = o->back_stack + 5;

  o->ram[o->space] = 0,                             o->space += 11,
  o->ram[o->space] = 2, o->ram[o->space + 5] = 3,   o->space += 11,
  o->ram[o->space] = 1, o->ram[o->space + 5] = 'a', o->space += 11,
  o->ram[o->space] = 1, o->ram[o->space + 5] = 'b', o->space += 11,
  o->ram[o->space] = 0,                             o->space += 11,
  o->ram[o->space] = 1, o->ram[o->space + 5] = 't', o->space += 11,
  o->ram[o->space] = 3,                             o->space += 11,
  o->ram[o->space] = 0,                             o->space += 11,
  goTo(o);
}
