#pragma once
#define FIRST_(a, ...) a
#define SECOND_(a, b, ...) b
#define FIRST(...) FIRST_(__VA_ARGS__, )
#define SECOND(...) SECOND_(__VA_ARGS__, )
#define EMPTY()
#define EVAL(...) EVAL8(__VA_ARGS__)
#define EVAL8(...) EVAL4(EVAL4(__VA_ARGS__))
#define EVAL4(...) EVAL2(EVAL2(__VA_ARGS__))
#define EVAL2(...) EVAL1(EVAL1(__VA_ARGS__))
#define EVAL1(...) __VA_ARGS__
#define DEFER1(m) m EMPTY()
#define DEFER2(m) m EMPTY EMPTY()()
#define IS_PROBE(...) SECOND(__VA_ARGS__, 0)
#define PROBE() ~, 1
#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define NOT(x) IS_PROBE(CAT(_NOT_, x))
#define _NOT_0 PROBE()
#define BOOL(x) NOT(NOT(x))
#define IF_ELSE(condition) _IF_ELSE(BOOL(condition))
#define _IF_ELSE(condition) CAT(_IF_, condition)
#define _IF_1(...) __VA_ARGS__ _IF_1_ELSE
#define _IF_0(...) _IF_0_ELSE
#define _IF_1_ELSE(...)
#define _IF_0_ELSE(...) __VA_ARGS__
#define HAS_ARGS(...) BOOL(FIRST(_END_OF_ARGUMENTS_ __VA_ARGS__)())
#define _END_OF_ARGUMENTS_() 0
#define _MAP() MAP
#define MAP(m, first, ...)                                                     \
  m(first) IF_ELSE(HAS_ARGS(__VA_ARGS__))(                                     \
      DEFER2(_MAP)()(m, __VA_ARGS__))(/* Do nothing, just terminate */         \
  )
