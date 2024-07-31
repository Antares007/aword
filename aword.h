#pragma once
extern int printf(const char *, ...);
#define P printf("%s\n", __func__)
typedef struct {
  long advance;
  long back_stack;
  long text_index;
  long bSide;
  long space;
  long ray;
  long direction;
  long ram[];
} O;

