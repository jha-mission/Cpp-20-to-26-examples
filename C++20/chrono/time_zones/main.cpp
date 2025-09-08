// Note: you might need if your system is too old
// export LD_LIBRARY_PATH=/opt/gcc-15/lib64:$LD_LIBRARY_PATH

#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string_view>

int main() {
  constexpr std::string_view locations[] = {
      "Africa/Casablanca",   "America/Argentina/Buenos_Aires",
      "America/Barbados",    "America/Indiana/Petersburg",
      "America/Tarasco_Bar", "Antarctica/Casey",
      "Antarctica/Vostok",   "Asia/Magadan",
      "Asia/Manila",         "Asia/Shanghai",
      "Asia/Tokyo",          "Atlantic/Bermuda",
      "Australia/Darwin",    "Europe/Isle_of_Man",
      "Europe/Laputa",       "Indian/Christmas",
      "Indian/Cocos",        "Pacific/Galapagos",
  };

  constexpr auto width =
      std::ranges::max_element(locations, {}, [](const auto& s) {
        return s.length();
      })->length();

  for (const auto location : locations) try {
      // may throw if 'location' is not in the time zone database
      const std::chrono::zoned_time zt{location,
                                       std::chrono::system_clock::now()};
      std::cout << std::format("{}, Zoned Time: {}\n", location, zt);
    } catch (std::runtime_error& ex) {
      std::cout << "Error: " << ex.what() << '\n';
    }
}
