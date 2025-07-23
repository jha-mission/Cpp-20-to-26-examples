#include <iostream>

constexpr int constexprVal = 1000;  // compile time -> const
constinit int constinitVal = 1000;  // compile time -> not const

int incrementMe(int val){
  return ++val;
}

int main() {
  auto val = 1000;
  const auto res = incrementMe(val);                                      // runtime
  std::cout << "res: " << res << std::endl;

  // std::cout << "++constexprVal++: " << ++constexprVal << std::endl;    // ERROR, constexpr is immutable
  std::cout << "++constinitVal++: " << ++constinitVal << std::endl;       // OK, constinit is mutable

  constexpr auto localConstexpr = 1000;                                   // local constexpr is ok
  // constinit auto localConstinit = 1000;                                // ERROR, constinit cannot be used for local variables
}