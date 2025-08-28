#include <iostream>
#include <ranges>
#include <vector>

int main() {
  std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto results = numbers | std::views::filter([](int n){ return n % 2 == 0; })  // 2, 4, 6, 8, 10
                         | std::views::transform([](int n){ return n * 2; })    // 4, 8, 12, 16, 20
                         | std::views::drop(1)                                  // 8, 12, 16, 20
                         | std::views::reverse                                  // 20, 16, 12, 8
                         | std::views::take(2);                                 // 20 16

  for (auto v: results) std::cout << v << " ";
  for (auto n: numbers) std::cout << n << " ";                                  // original data is not affected
}