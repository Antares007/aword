// \A/ord.
extern int printf(const char *__restrict __format, ...);
struct sContext {
  long ram[2048];
  long call_stack;
  long advance;
  long text_index;
  long space;
  long ray;
  long direction;
};
void goTo(struct sContext *s);
void halt(struct sContext *s) {}
void put(struct sContext *s) {
  printf("%c", (char)s->ram[s->text_index + 5]), goTo(s);
}
void call(struct sContext *s) {
  s->ram[--s->call_stack] = s->text_index,
  s->text_index = s->text_index + s->ram[s->text_index + 5] * 11, goTo(s);
}
void ret(struct sContext *s) {
  s->text_index = s->ram[s->call_stack++], goTo(s);
}
void *h[2];
void push(struct sContext *s) {
  void **pushed = (void *)&s->ram[s->ram[s->advance] = s->advance + 1];
  pushed[0] = h;
  pushed[1] = h[1];
  ((void **)h[1])[0] = pushed;
  h[1] = pushed;
}
struct sContext *unshift() {
  void **unshed = h[0];
  ((void **)unshed[0])[1] = unshed[1];
  ((void **)unshed[1])[0] = unshed[0];
  return (struct sContext *)(unshed - (long)unshed[-1]);
}
void fork(struct sContext *s) {
  push(s);
  struct sContext sn = *s;
  goTo(&sn);
}
void (*sopcodes[])(struct sContext *s) = {halt, put, call, ret, fork};
// clang-format off
#define Halt    s->ram[s->space] = 0,                             s->space += 11,
#define Put(c)  s->ram[s->space] = 1, s->ram[s->space + 5] = (c), s->space += 11,
#define Call(a) s->ram[s->space] = 2, s->ram[s->space + 5] = (a), s->space += 11,
#define Ret     s->ram[s->space] = 3,                             s->space += 11,
#define Fork    s->ram[s->space] = 4,                             s->space += 11,
// clang-format on
void goTo(struct sContext *s) {
  push(s);
  s = unshift();
  (sopcodes[s->ram[s->text_index += 11]])(s);
}
int main() {
  h[1] = h[0] = h;
  struct sContext *s = &(struct sContext){};
  s->advance = 0;
  s->call_stack = 512;
  s->text_index = s->space = s->call_stack + 5;
  Halt Fork Fork Call(3) Put('a') Put('b') Halt Put('t') Ret goTo(s);
}
