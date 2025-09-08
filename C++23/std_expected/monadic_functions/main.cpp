#include <expected>
#include <iostream>
#include <string>
#include <print>

std::expected<int, std::string> parse_int(const std::string& s) {
  try {
    return std::stoi(s);
  } catch (...) {
    return std::unexpected("Invalid integer: " + s);
  }
}

std::expected<int, std::string> double_if_even(int x) {
  if (x % 2 == 0)
    return x * 2;
  else
    return std::unexpected("Not even");
}

std::expected<int, std::string> handle_error(const std::string& error) {
  std::println("Error encountered: {}", error);
  return std::unexpected(error);
}

int main() {
  // std::string input = "42";
  // std::string input = "41";
  std::string input = "blabla";
  auto result = parse_int(input)
                    .and_then(double_if_even)                // might change the error state
                    .transform([](int x) { return x + 1; })  // change value but not the error state
                    .or_else(handle_error);                  // handle error if any

  if (result) {
    std::cout << "Result: " << *result << '\n';
  }
}