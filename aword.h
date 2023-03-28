#pragma once
// clang-format off
#define word long a, long w, void **o, long r, long d
#define Tab(aw, _a, _b)                                                        \
  o[--a] = (void *)(_a), o[--a] = (aw), o[--a] = (void *)(_b),
#define Ta(aw, _a) Tab(aw, _a, 0)
#define T(aw) Ta(aw, 0)
