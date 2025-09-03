
// count with (213) and without modules (1118756)
// preprocessing only: -E
// g++ -I. -std=c++20 -E main.cpp | wc -c

// Note: With g++ you have to compile the iostream module separately:
// g++ -std=c++20 -fmodules -xc++-system-header iostream

// #include <iostream>
import <iostream>;

int main() {
    std::cout << "Hello Modular World!\n";
}