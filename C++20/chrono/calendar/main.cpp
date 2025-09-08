// Note: you might need if your system is too old
// export LD_LIBRARY_PATH=/opt/gcc-15/lib64:$LD_LIBRARY_PATH

#include <chrono>
#include <format>
#include <iostream>

void print_ISO_8601_timestamp() {
  // Format as ISO 8601 (YYYY-MM-DDTHH:MM:SSZ)
  auto iso_timestamp = std::format("{:%Y-%m-%dT%H:%M:%SZ}",
    std::chrono::time_point_cast<std::chrono::seconds>(std::chrono::utc_clock::now()));
  std::cout << iso_timestamp << std::endl;
}

int main() {
  // Construct a calendar date: 2025-09-03
  std::chrono::year_month_day today{
      std::chrono::year{2025}, std::chrono::September, std::chrono::day{3}};

  std::cout << std::format("Today: {:%Y-%m-%d}\n", today);

  // Convert to sys_days (days since epoch)
  std::chrono::sys_days sys_today = std::chrono::sys_days{today};

  // Add 10 days
  std::chrono::sys_days future = sys_today + std::chrono::days{10};
  std::chrono::year_month_day future_date{future};
  std::cout << std::format("10 days later: {:%Y-%m-%d}\n", future_date);

  // Subtract 1 month
  std::chrono::year_month_day past_date = today - std::chrono::months{1};
  std::cout << std::format("1 month earlier: {:%Y-%m-%d}\n", past_date);

  // Get weekday
  std::chrono::weekday wd{sys_today};
  std::cout << std::format("Weekday today (0=Sun): {}\n", wd.c_encoding());

  print_ISO_8601_timestamp();

  return 0;
}
