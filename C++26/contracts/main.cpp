#include <iostream>

int fun(int i)
  pre(i >= 0)
  post(r : r > 0) {
  contract_assert(i >= 0);
  return i + 1;
}

int main() {
  fun(-1);
}