void m(long a, long w, void **o, long r, long d) {
  ((void (**)(long, long, void *, long, long))o)[w + d](a, w + d, o, r, d);
}
void b(long a, long w, void **o, long r, long d) { m(a, w, o, r, -3); }
void left_arm(long a, long w, void **o, long r, long d) {
  if (r == 1)
    m(a, (long)o[w - 1], o, 3, (long)o[w + 1]);
  else
    m(a, w, o, r == 3 ? 1 : r, 3);
}
void right_arm(long a, long w, void **o, long r, long d) {
  if (r == 1)
    o[(long)o[w - 1] + 1] = o[w + 1], m(a, (long)o[w - 1], o, 3, 3);
  else
    m(a, w, o, r == 3 ? 1 : r, 3);
}
void s(long a, long w, void **o, long r, long d) {
  if (d == -3)
    if (r == 1)
      m(a, (long)o[w + 1], o, 3, 3);
    else
      m(a, w, o, r == 3 ? 1 : r, 3);
  else if (r == 3)
    m(a, (long)o[w - 1], o, r, d);
  else
    m(a, w, o, r, -3);
}
void hands(long a, long w, void **o, long r, long d) {
  long R, L;
  // clang-format off
  o[--a] = 0,         o[    --a] = b,        o[--a] = 0;
  o[--a] = 0,         o[    --a] = m,        o[--a] = 0;
  o[--a] = (void*)-3, o[L = --a] = left_arm, o[--a] = (void*)w;
                            
  o[--a] = 0,         o[    --a] = b,        o[--a] = 0;
  o[--a] = 0,         o[    --a] = m,        o[--a] = 0;
  o[--a] = (void*)L,  o[R = --a] = right_arm,o[--a] = (void*)w;
                            
  o[--a] = 0,         o[    --a] = b,        o[--a] = 0;
  o[--a] = 0,         o[    --a] = m,        o[--a] = 0;
  o[--a] = (void*)3,  o[L = --a] = left_arm, o[--a] = (void*)R;
                            
  o[--a] = 0,         o[    --a] = b,        o[--a] = 0;
  o[--a] = 0,         o[    --a] = m,        o[--a] = 0;
  o[--a] = (void*)L,  o[R = --a] = right_arm,o[--a] = (void*)w;
  // clang-format on
  o[w - 1] = (void *)R;
  o[w] = s;
  s(a, w, o, r, d);
}
