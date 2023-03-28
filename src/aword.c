#define aword long a, long w, void **o, long r, long d
void m(aword) {
  ((void (**)(long, long, void *, long, long))o)[w + d](a, w + d, o, r, d);
}
void b(aword) { m(a, w, o, r, -3); }
void dot(aword) { m(a, w, o, r == 3 ? 1 : r == 1 ? 3 : r, 3); }
void left_arm(aword) {
  if (r == 1)
    m(a, (long)o[w - 1], o, 3, (long)o[w + 1]);
  else
    m(a, w, o, r == 3 ? 1 : r, 3);
}
void right_arm(aword) {
  if (r == 1)
    o[(long)o[w - 1] + 1] = o[w + 1], m(a, (long)o[w - 1], o, 3, 3);
  else
    m(a, w, o, r == 3 ? 1 : r, 3);
}
void s(aword) {
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
