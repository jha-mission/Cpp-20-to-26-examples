#include <compare>
#include <set>
#include <iostream>

struct Data {
  int i;
  int j;

  // with out this it won't compile, because set is ordered.
  auto operator<(const Data& other) const {
    return i < other.i || (i == other.i && j < other.j);
  }

  // but now (C++20) you can do
  // auto operator<=>(const Data& other) const = default;

};

int main() {
  std::set<Data> my_set;

  my_set.insert({1, 2});
  my_set.insert({3, 4});
  my_set.insert({1, 2}); // Duplicate, won't be added

  for (const auto& item : my_set) {
    std::cout << "{" << item.i << ", " << item.j << "}\n";
  }
}