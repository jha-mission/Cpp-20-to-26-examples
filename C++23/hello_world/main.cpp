// you need to use -fmodules and you need to compile the std module first:
// g++ -std=c++23 -O2 -fmodules -fsearch-include-path -fmodule-only -c bits/std.cc

import std;

// #include <string> -> compile error !

int main() {
  std::print("Hello, World!\n");
  return 0;
}
