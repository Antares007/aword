#pragma once
#include "aword.h"
#undef T
#undef Tv
#define T(aw) {.q = 0}, {.c = aw}, {.q = 0}, {.v = aw}, {.c = text_index}, {.cs = #aw},
#define Tv(aw, value) {.q = 0}, {.c = aw}, {.v = (void *)value}, {.v = aw}, {.c = text_index}, {.cs = #aw},
N(text_index);
void text_index_init();
