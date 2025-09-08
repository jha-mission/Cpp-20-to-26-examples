// https://compiler-explorer.com/z/W8b9xrx5j
// https://andreasfertig.com/blog/2025/08/cpp26-reflection-at-compile-time/

#include <array>
#include <experimental/meta>
#include <print>
#include <type_traits>
#include <utility>

// #A Helper because this is interesting by itself
template <typename E>
  requires std::is_enum_v<E>
constexpr inline auto num_enumerators_of{std::meta::enumerators_of(^^E).size()};

// #B Implementation
template <typename E>
  requires std::is_enum_v<E>
consteval auto get_enum_values() {
  std::array<E, num_enumerators_of<E>> res;
  std::array<std::string, num_enumerators_of<E>> names;

  template for (size_t i{}; constexpr auto& e : std::define_static_array(
                                std::meta::enumerators_of(^^E))) {
    res[i] = [:e:];
    names[i] = std::meta::identifier_of(e);
    i++;
  }

  return std::pair{res, names};
}

enum class Color { Transparent, Red = 2, Green, Blue = 8, Yellow };

int main() {
  auto [vals, names] = get_enum_values<Color>();

  for (std::size_t i = 0; i < vals.size(); ++i) {
    std::println("{} -> {}", std::to_underlying(vals[i]), names[i]);
  }

  std::println();
}