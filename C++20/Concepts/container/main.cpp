#include <iostream>
#include <string.h>
#include <concepts>
#include <type_traits>
#include <vector>
#include <set>

template<typename Collection>
concept HasPushBack = requires(Collection c, typename Collection::value_type v) {
  c.push_back(v);
};

template<typename Collection, typename T>
requires HasPushBack<Collection>
void add(Collection& collection, T value) {
  collection.push_back(value);
}

template<typename Collection, typename T>
void add(Collection& collection, T value) {
  collection.insert(value);
}

//-------------------------------------------------------------------------------
int main() {
  std::vector<int> vec;
  std::set<int> s;

  add(vec, 10);
  add(s, 20);

  return 0;
}
