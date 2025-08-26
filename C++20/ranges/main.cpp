#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

int main() {
    std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Filter even numbers and square them using ranges
    auto even_squares = numbers
        | std::views::filter([](int n) { return n % 2 == 0; })
        | std::views::transform([](int n) { return n * n; });

    std::cout << "Even squares: ";
    for (int n : even_squares) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Take first 3 elements
    auto first_three = numbers | std::views::take(3);
    std::cout << "First three numbers: ";
    for (int n : first_three) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}