extern int puts(const char *__s);
void goTo(unsigned char *rdi, long rsi);
void sophi_o(unsigned char *rdi, long rsi) {
  puts("o");
  goTo(rdi, rsi);
}
void sophi_s(unsigned char *rdi, long rsi) {
  puts("s");
  goTo(rdi, rsi);
}
void halt(unsigned char *rdi, long rsi) {}
void (*sopcodes[])(unsigned char *rdi, long rsi) = {halt, sophi_o, sophi_s};
void goTo(unsigned char *rdi, long rsi) {
  (sopcodes[rdi[rsi + 1]])(rdi, rsi + 1);
}
int main() {
  unsigned char rdi[512] = {0, 1, 2, 1, 2, 1, 2, 0};
  long rsi = 0;
  goTo(rdi, rsi);
}
