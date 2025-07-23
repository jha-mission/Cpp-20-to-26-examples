#include <iostream>

int sqrRunTime(int n) {
  return n * n;
}

consteval int sqrCompileTime(int n) {
  return n * n;
}

constexpr int sqrRunOrCompileTime(int n) {                   // runtime or compile time, depending on the context
  return n * n;
}

int main() {

  // constexpr int value1 = sqrRunTime(100);  // ERROR (1)
  constexpr int value2 = sqrCompileTime(100);
  constexpr int value3 = sqrRunOrCompileTime(100);
  int x = 100;
  // int value5 = sqrCompileTime(x); // ERROR (2) - runtime call
  int value6 = sqrRunOrCompileTime(x);        // - runtime call

  static_assert(sqrRunOrCompileTime(10) == 100);                            // compile time assertion (since C++11)
  int array[sqrRunOrCompileTime(100)];         // compile time

  int a = 100;
  int runTime = sqrRunOrCompileTime(a);                 // run-time, a is not const

  int runTimeOrCompiletime = sqrRunOrCompileTime(100);  // run-time or compile-time, compiler decides
}