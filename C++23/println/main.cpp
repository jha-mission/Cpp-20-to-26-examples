#include <iostream>
#include <print>
#include <string>

int main() {
  std::print("{2} {1}{0}!\n", 23, "C++", "Hello");
  std::println("Pi is approximately {:.2f}.", 3.14159);

  return 0;
}

struct Point {
  int x;
  int y;
};

// Specialization for Point
template <>
struct std::formatter<Point> {
  // ignore format specifiers for now
  constexpr auto parse(std::format_parse_context& ctx) {
    return ctx.begin();  // just stop immediately
  }

  // how to format Point
  auto format(const Point& p, std::format_context& ctx) const {
    return std::format_to(ctx.out(), "({}, {})", p.x, p.y);
  }
};