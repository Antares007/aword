#define N(argo) void argo(void **o, long a)
#define G(Olive)                                                               \
  N(Olive)                                                                     \
  __attribute__((section(".text." #Olive))) __attribute__((noinline));         \
  N(Olive) { asm("nop" : : "a"(o + a)); };                                     \
  N(Olive##_nar) __attribute__((noinline));                                    \
  N(Olive##_ray) __attribute__((section(".text." #Olive "_ray")));             \
  N(Olive##_ray) { Olive##_nar(o, a); }                                        \
  N(Olive##_nar)

G(Yellow  ) { Yellow(o, a); }
G(Purple  ) { Purple(o, a); }
G(Red     ) { Red(o, a); }
G(Green   ) { Green(o, a); }
G(Blue    ) { Blue(o, a); }

G(Navy    ) { Navy(o, a); }
G(Lime    ) { Lime(o, a); }
G(Maroon  ) { Maroon(o, a); }
G(Fuchsia ) { Fuchsia(o, a); }
G(Olive   ) { Olive(o, a); }
