#include <iostream>

struct Point {
  int x, y;

  // Deducing this: 'auto' makes this a template on cv/ref qualifiers
  auto operator+=(this Point& self, const Point& other) {
    self.x += other.x;
    self.y += other.y;
    return self;
  }

  void print(this const Point& self) {
    std::cout << "(" << self.x << ", " << self.y << ")\n";
  }
};

int main() {
  Point p1{1, 2};
  Point p2{3, 4};

  p1 += p2;
  p1.print();  // Output: (4, 6)
}