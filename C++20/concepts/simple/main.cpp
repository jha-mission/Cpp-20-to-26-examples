#include <iostream>
#include <string.h>
#include <concepts>
#include <type_traits>

// Define a concept that checks if T is an integral type
template<typename T>
concept Integral = std::is_integral_v<T>;

// Use the concept to constrain a template function
template <Integral T>
T Add(T a, T b) {
    return a + b;
}

//-------------------------------------------------------------------------------
int main() {
    int x = 5, y = 10;
    std::cout << "Sum: " << Add(x, y) << std::endl;
    // Uncommenting the next lines will cause a compile error, as double is not Integral
    // double a = 1.1, b = 2.2;
    // std::cout << add(a, b) << std::endl;
    return 0;
}
