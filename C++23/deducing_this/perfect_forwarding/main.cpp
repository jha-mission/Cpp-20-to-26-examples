#include <iostream>
#include <stdexcept>
#include <utility>


void foo(int& x) { std::cout << "lvalue\n"; }
void foo(int&& x) { std::cout << "rvalue\n"; }

template <typename T>
void wrapper(T t) {
  foo(t);  // always lvalue inside!
}

// this will choose the correct overload of foo
// use a forwarding reference T&& + std::forward
template <typename T>
void wrapper_forward(T&& t) {
  foo(std::forward<T>(t));  // perfect forwarding
}

int main() {
  int x = 5;
  wrapper(x);   // prints "lvalue"
  wrapper(42);  // prints "rvalue"

  wrapper_forward(x);   // prints "lvalue"
  wrapper_forward(42);  // prints "rvalue"
}
