#include <cmath>
#include <format>
#include <iostream>

struct Point {
  double x;
  double y;
};

template <>
struct std::formatter<Point> {
  enum class Mode { cartesian, polar };
  Mode mode = Mode::cartesian;

  // Parse the format specifier
  constexpr auto parse(std::format_parse_context& ctx) {
    auto it = ctx.begin();
    auto end = ctx.end();

    if (it != end && *it != '}') {
      if (*it == 'p') {  // expect "polar"
        std::string spec;
        for (; it != end && *it != '}'; ++it) {
          spec.push_back(*it);
        }
        if (spec == "polar") {
          mode = Mode::polar;
        } else {
          throw std::format_error("invalid format specifier for Point");
        }
      }
    }

    // Return iterator at the closing '}'
    return it;
  }

  // Format the point depending on the mode
  auto format(const Point& p, std::format_context& ctx) const {
    switch (mode) {
      case Mode::cartesian:
        return std::format_to(ctx.out(), "({}, {})", p.x, p.y);
      case Mode::polar: {
        double r = std::hypot(p.x, p.y);
        double theta = std::atan2(p.y, p.x);
        return std::format_to(ctx.out(), "({}, {} rad)", r, theta);
      }
    }
    return ctx.out();  // should never reach
  }
};

int main() {
  Point pt{3, 4};

  std::cout << std::format("Default: {}\n", pt);
  std::cout << std::format("Polar:   {:polar}\n", pt);
}
