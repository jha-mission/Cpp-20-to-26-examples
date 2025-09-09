#include <iostream>
#include <ranges>

int main() {
  // Infinite sequence: all natural numbers starting from 0
  auto naturals = std::views::iota(0);

  // Take the first 20 numbers and print them
  for (int n : naturals | std::views::take(20)) {
    std::cout << n << " ";
  }
  std::cout << "\n";

  // Example: infinite sequence of squares
  auto squares =
      std::views::iota(1) | std::views::transform([](int x) { return x * x; });

  // Print first 10 squares
  for (int s : squares | std::views::take(10)) {
    std::cout << s << " ";
  }
  std::cout << "\n";
}
