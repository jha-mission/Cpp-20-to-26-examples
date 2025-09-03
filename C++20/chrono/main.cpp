#include <iostream>
#include <chrono>

int main() {
    // Construct a calendar date: 2025-09-03
    std::chrono::year_month_day today{std::chrono::year{2025}, std::chrono::September, std::chrono::day{3}};

    std::cout << "Today: "
              << static_cast<int>(today.year()) << "-"
              << static_cast<unsigned>(today.month()) << "-"
              << static_cast<unsigned>(today.day()) << "\n";

    // Convert to sys_days (days since epoch)
    std::chrono::sys_days sys_today = std::chrono::sys_days{today};

    // Add 10 days
    std::chrono::sys_days future = sys_today + std::chrono::days{10};
    std::chrono::year_month_day future_date{future};
    std::cout << "10 days later: "
              << static_cast<int>(future_date.year()) << "-"
              << static_cast<unsigned>(future_date.month()) << "-"
              << static_cast<unsigned>(future_date.day()) << "\n";

    // Subtract 1 month
    std::chrono::year_month_day past_date = today - std::chrono::months{1};
    std::cout << "1 month earlier: "
              << static_cast<int>(past_date.year()) << "-"
              << static_cast<unsigned>(past_date.month()) << "-"
              << static_cast<unsigned>(past_date.day()) << "\n";

    // Get weekday
    std::chrono::weekday wd{sys_today};
    std::cout << "Weekday today (0=Sun): " << wd.c_encoding() << "\n";

    return 0;
}
