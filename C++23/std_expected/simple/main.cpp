#include <expected>
#include <iostream>
#include <string>

// Function that returns std::expected
std::expected<int, std::string> divide(int a, int b) {
  if (b == 0) {
    return std::unexpected("Division by zero");
  }
  return a / b;
}

int main() {
  auto result = divide(10, 2);

  if (result) {
    std::cout << "Result: " << *result << '\n';
  } else {
    std::cout << "Error: " << result.error() << '\n';
  }

  auto error_result = divide(10, 0);
  if (error_result) {
    std::cout << "Result: " << *error_result << '\n';
  } else {
    std::cout << "Error: " << error_result.error() << '\n';
  }

  return 0;
}