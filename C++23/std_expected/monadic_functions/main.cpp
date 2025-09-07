#include <expected>
#include <iostream>
#include <string>

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

int main() {
  std::string input = "42";
  auto result = parse_int(input)
                    .and_then(double_if_even)
                    .transform([](int x) { return x + 1; })
                    .or_else([](const std::string& err) {
                      std::cout << "Error: " << err << '\n';
                      return std::expected<int, std::string>(0);
                    });

  if (result) {
    std::cout << "Result: " << *result << '\n';
  }
}