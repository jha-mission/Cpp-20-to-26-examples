#include <compare>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

struct Person {
    std::string name;
    int age;

    // Order by age, then name
    auto operator<=>(const Person& other) const {
        return age <=> other.age;
    }

    bool operator==(const Person& other) const = default;
};

int main() {

    std::vector<Person> people = {
        {"Alice", 30},
        {"Bob", 25},
        {"Charlie", 40}
    };

    if (people[0] > people[1]) {
        std::cout << people[0].name << " is older than " << people[1].name << "\n";
    }

    std::sort(people.begin(), people.end());

    for (auto& p : people) {
        std::cout << p.name << " (" << p.age << ")\n";
    }
}