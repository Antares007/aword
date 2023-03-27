#pragma once
#define word long a, long w, void **o, long r, long d
static void m(long a, long w, void **o, long r, long d) {
  ((void (**)(long, long, void *, long, long))o)[w + d](a, w + d, o, r, d);
}
#define White(op) d op - 3
#define Black(op) d op 3
#define Yellow(op) r op 3
#define Purple(op) r op 2
#define Green(op) r op 1
#define Blue(op) r op 0
