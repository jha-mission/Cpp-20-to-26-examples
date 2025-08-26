#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;

    // Classic member function syntax
    void print_info() const {
        std::cout << "Name: " << name << ", Age: " << age << '\n';
    }

    void set_name(std::string new_name) {
        name = std::move(new_name);
    }
};

int main() {
    Person p{"Alice", 30};
    p.print_info();

    p.set_name("Bob");
    p.print_info();

    return 0;
}