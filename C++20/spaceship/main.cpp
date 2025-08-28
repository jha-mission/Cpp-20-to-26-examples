#include <iostream>
#include <compare>

struct Point {
    int x, y;

    // Defaulted three-way comparison operator
    auto operator<=>(const Point&) const = default;
};

int main() {
    Point p1{1, 2};
    Point p2{1, 3};

    if (auto cmp = (p1 <=> p2); cmp < 0) {
        std::cout << "p1 is less than p2\n";
    } else if (cmp > 0) {
        std::cout << "p1 is greater than p2\n";
    } else {
        std::cout << "p1 is equal to p2\n";
    }

    return 0;
}