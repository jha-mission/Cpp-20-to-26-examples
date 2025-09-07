#include <iostream>
#include <format>
#include <string>
#include <iomanip>

int main() {
  int year = 2024;
  std::string language = "C++";
  double pi = 3.14159;

  std::string message = std::format("Welcome to {} {}!\nPi is approximately {:.2f}", language, year, pi);
  std::cout << message << std::endl;

  // Formatting numbers with padding and alignment
  std::cout << std::format("Number: {:>10}\n", 42);      // Right aligned
  // compare with std::setw and std::setfill
  std::cout << "Number: " << std::setw(10) << std::setfill(' ') << 42 << '\n'; // Right aligned
  std::printf("Number: %10d\n", 42); // Right aligned

  std::cout << std::format("Number: {:0>10}\n", 42);     // Zero padded
  std::cout << std::format("Hex: {:#08x}\n", 255);       // Hex with 0x and zero padded

  return 0;
}