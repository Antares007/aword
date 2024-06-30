// clang-format on
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
void goTo (struct sContext *s);
void halt (struct sContext *s) {}
void put  (struct sContext *s) {  printf("%c", (char)s->ram[s->text_index + 5]), goTo(s); }
void call (struct sContext *s) {  s->ram[--s->call_stack] = s->text_index,
                                  s->text_index = s->text_index + s->ram[s->text_index+5] * 11,
                                  goTo(s); }
void ret  (struct sContext *s) {  s->text_index = s->ram[s->call_stack++], goTo(s); }
void (*sopcodes[])(struct sContext *s) = { halt, put, call, ret };
void goTo (struct sContext *s) { (sopcodes[s->ram[s->text_index += 11]])(s); }

int main() {
  struct sContext *s = &(struct sContext){};
  s->call_stack = 512;
  s->text_index = s->space = s->call_stack + 5;
  s->ram[s->space] = 0,                           s->space += 11, // halt
  s->ram[s->space] = 2, s->ram[s->space+5] = 3,   s->space += 11, // call +3
  s->ram[s->space] = 1, s->ram[s->space+5] = 'a', s->space += 11, // put 'a'
  s->ram[s->space] = 1, s->ram[s->space+5] = 'b', s->space += 11, // put 'b'
  s->ram[s->space] = 0,                           s->space += 11, // halt
  s->ram[s->space] = 1, s->ram[s->space+5] = 't', s->space += 11, // put 't'
  s->ram[s->space] = 3,                           s->space += 11, // ret
  goTo(s);
}
