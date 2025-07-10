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

// template<HasPushBack Collection, typename T>
// void add(Collection& collection, T value) {
//   collection.push_back(value);
// }

// template<typename Collection, typename T>
// void add(Collection& collection, T value) {
//   collection.insert(value);
// }

void add(HasPushBack auto& collection, auto value) {
  collection.push_back(value);
}

void add(auto& collection, auto value) {
  collection.insert(value);
}

// old school (SFINAE)
// Helper trait to detect push_back
// template<typename C, typename T>
// class has_push_back {
// private:
//     template<typename U>
//     static auto test(int) -> decltype(std::declval<U>().push_back(std::declval<T>()), std::true_type());

//     template<typename>
//     static std::false_type test(...);
// public:
//     static constexpr bool value = decltype(test<C>(0))::value;
// };

// // Enable only if Collection has push_back(T)
// template<typename Collection, typename T>
// typename std::enable_if<has_push_back<Collection, T>::value, void>::type
// add(Collection& collection, T value) {
//     collection.push_back(value);
// }
// template<typename Collection, typename T>
// typename std::enable_if<
//     !has_push_back<Collection, T>::value,
//     void>::type
// add(Collection& collection, T value) {
//     collection.insert(value);
// }


//-------------------------------------------------------------------------------
int main() {
  std::vector<int> vec;
  std::set<int> s;

  add(vec, 10);
  add(s, 20);

  return 0;
}
