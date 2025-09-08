// Example from Deducing this P0847R7 - open-std.org/jtc1/sc22/wg21/docs/papers/2021/p0847r7.html#motivation

#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class my_optional {
  T m_value;

 public:
  my_optional() = default;
  my_optional(T v) : m_value(std::move(v)) {}

  // // 1. lvalue, non-const
  // constexpr T& value() & {
  //   return m_value;
  // }

  // // 2. lvalue, const
  // constexpr const T& value() const& {
  //   return m_value;
  // }

  // // 3. rvalue, non-const
  // constexpr T&& value() && {
  //   return std::move(m_value);
  // }

  // // 4. rvalue, const
  // constexpr const T&& value() const&& {
  //   return std::move(m_value);
  // }

  // Single function replaces all 4 overloads
  template <typename Self>
  constexpr auto&& value(this Self&& self) {
    return std::forward<Self>(self).m_value;
  }
};

int main() {
  my_optional<int> o1(42);
  const my_optional<int> o2(7);

  std::cout << o1.value() << "\n";                   // lvalue, non-const
  std::cout << o2.value() << "\n";                   // lvalue, const
  std::cout << my_optional<int>(9).value() << "\n";  // rvalue
}
