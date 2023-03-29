#define R(ay)                                                                  \
  void ay(void **o, long a) __attribute__((section(".text." #ay)))             \
  __attribute__((noinline));                                                   \
  void ay(void **o, long a)

R(b0) { asm("nop" : : "a"(o + a)); };
R(b1) { asm("nop" : : "a"(o + a)); };
R(b2) { asm("nop" : : "a"(o + a)); };
R(b3) { asm("nop" : : "a"(o + a)); };
R(b4) { asm("nop" : : "a"(o + a)); };

R(o4) { asm("nop" : : "a"(o + a)); };
R(o3) { asm("nop" : : "a"(o + a)); };
R(o2) { asm("nop" : : "a"(o + a)); };
R(o1) { asm("nop" : : "a"(o + a)); };
R(o0) { asm("nop" : : "a"(o + a)); };
void(*load_tree)(const char*hash);
R(bor0) { b0(o, a); }
R(bor1) { b1(o, a); }
R(bor2) { b2(o, a); }
R(bor3) { b3(o, a); }
R(bor4) { b4(o, a); }

R(obr4) { o4(o, a); }
R(obr3) { o3(o, a); }
R(obr2) { o2(o, a); }
R(obr1) { o1(o, a); }
R(obr0) { o0(o, a); }

