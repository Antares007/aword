#include <iostream>

namespace o {
template <class... Ts> struct rays : Ts... {
  using Ts::operator()...;
};
template <class... Ts> rays(Ts...) -> rays<Ts...>;
template <typename O> struct rec {
  O o;
  void operator()(auto &&...args) const {
    o(*this, static_cast<decltype(args) &&>(args)...);
  }
};
template <typename O> rec(O) -> rec<O>;
} // namespace o
struct error_ray;
constexpr inline error_ray *error_ray_v = nullptr;
template <typename...> struct curry;
template <typename... Args> curry(Args...) -> curry<Args...>;
template <typename B, typename A> struct curry<B, A> {
  B b;
  A a;
  constexpr curry(auto &&b, auto &&a)
      : b(static_cast<decltype(b) &&>(b)), a(static_cast<decltype(a) &&>(a)) {}
  void operator()(const auto &o, auto &&...rest) const {
    b(o, a, static_cast<decltype(rest) &&>(rest)...);
  }
};
template <typename B, typename A, typename... Tail>
struct curry<B, A, Tail...> : curry<curry<B, A>, Tail...> {
  using curry<curry<B, A>, Tail...>::operator();
  constexpr curry(auto &&b, auto &&a, auto &&...tail)
      : curry<curry<B, A>, Tail...>(curry<B, A>(static_cast<decltype(b) &&>(b),
                                                static_cast<decltype(a) &&>(a)),
                                    static_cast<decltype(tail) &&>(tail)...) {}
};
template <typename...> struct purry;
template <typename... Args> purry(Args...) -> purry<Args...>;
template <typename B, typename A> struct purry<B, A> {
  B b;
  A a;
  constexpr purry(auto &&b, auto &&a)
      : b(static_cast<decltype(b) &&>(b)), a(static_cast<decltype(a) &&>(a)) {}
  void operator()(const auto &o, auto &&...rest) const {
    a(o::rays{[&o](error_ray *l, auto &&...rest) {
                o(l, static_cast<decltype(rest) &&>(rest)...);
              },
              [&o, this,
               ... rest = static_cast<decltype(rest) &&>(rest)](auto &&...a) {
                this->b(o, static_cast<decltype(a) &&>(a)..., rest...);
              }});
  }
};
template <typename B, typename A, typename... Tail>
struct purry<B, A, Tail...> : purry<purry<B, A>, Tail...> {
  using purry<purry<B, A>, Tail...>::operator();
  constexpr purry(auto &&b, auto &&a, auto &&...tail)
      : purry<purry<B, A>, Tail...>(purry<B, A>(static_cast<decltype(b) &&>(b),
                                                static_cast<decltype(a) &&>(a)),
                                    static_cast<decltype(tail) &&>(tail)...) {}
};
struct A {};
struct B {};
struct C {};
void show0() {
  auto f = [](A) { return B{}; };
  auto g = [](B) { return C{}; };
  auto compose = [](auto f, auto g) { return [=](auto a) { return g(f(a)); }; };
  auto gof = compose(f, g);
  g(f(A{}));
  gof(A{});
}
void show1() {
  auto f = [](auto o, A) { o(B{}); };
  auto g = [](auto o, B) { o(C{}); };
  auto compose = [](auto f, auto g) {
    return [=](auto o, auto a) { purry{g, curry{f, a}}(o); };
  };
  auto gof = compose(f, g);
  curry{gof, A{}}(o::rays{[](error_ray *) {}, [](C) {}});
}

int main() {
  show0();
  show1();

  constexpr auto out =
      o::rays{[](error_ray *, auto...) { std::cerr << "error\n"; },
              [](auto cstr) { std::cout << cstr << '\n'; },
              [](auto a, auto b) { std::cout << a << " AND " << b << '\n'; }};
  purry{[](auto o, auto a, auto b, auto c) {
          o("abc");
          o(a * b + c * 1.99f);
          o(a + b * c);
          o((a + b) * c);
          o("t", "a");
        },
        [](auto o) { o(1, 2, 3); }}(out);
  return 0;
}
