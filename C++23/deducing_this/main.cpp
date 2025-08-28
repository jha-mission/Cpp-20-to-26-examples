#include <iostream>
#include <string>
#include <type_traits>
#include <utility>

struct Test
{
  template <typename Self>
  void explicitCall(this Self &&self, const std::string &text)
  { // (9)
    std::cout << text << ": ";
    std::forward<Self>(self).implicitCall(); // (10)
    std::cout << '\n';
  }

  void implicitCall() &
  { // (1)
    std::cout << "non const lvalue";
  }

  void implicitCall() const &
  { // (2)
    std::cout << "const lvalue";
  }

  void implicitCall() &&
  { // (3)
    std::cout << "non const rvalue";
  }

  void implicitCall() const &&
  { // (4)
    std::cout << "const rvalue";
  }
};

// Example 2: Fluent interface with perfect forwarding
class FluentBuilder
{
private:
  std::string result;

public:
  template <typename Self>
  auto &&setName(this Self &&self, const std::string &name)
  {
    std::cout << "Setting name: " << name << "\n";
    self.result += "Name: " + name + "; ";
    return std::forward<Self>(self);
  }

  template <typename Self>
  auto &&setAge(this Self &&self, int age)
  {
    std::cout << "Setting age: " << age << "\n";
    self.result += "Age: " + std::to_string(age) + "; ";
    return std::forward<Self>(self);
  }

  template <typename Self>
  auto &&setCity(this Self &&self, const std::string &city)
  {
    std::cout << "Setting city: " << city << "\n";
    self.result += "City: " + city + "; ";
    return std::forward<Self>(self);
  }

  std::string build() const
  {
    return result;
  }
};

// Example 3: CRTP-like pattern with deducing this
template <typename Derived>
class Base
{
public:
  template <typename Self>
  void doSomething(this Self &&self)
  {
    std::cout << "Base::doSomething called on ";
    if constexpr (std::is_same_v<std::decay_t<Self>, Derived>)
    {
      std::cout << "Derived object\n";
      static_cast<Derived &>(self).derivedMethod();
    }
    else
    {
      std::cout << "Base object\n";
    }
  }
};

class Derived : public Base<Derived>
{
public:
  void derivedMethod()
  {
    std::cout << "Derived::derivedMethod called\n";
  }
};

void FunctionOverloading()
{
}

void demonstrateFluentBuilder()
{
  std::cout << "=== FluentBuilder Example ===\n";

  // Chain calls on lvalue
  FluentBuilder builder;
  auto result1 = builder.setName("Alice")
                     .setAge(30)
                     .setCity("New York")
                     .build();
  std::cout << "Result 1: " << result1 << "\n";

  // Chain calls on rvalue (temporary)
  auto result2 = FluentBuilder{}
                     .setName("Bob")
                     .setAge(25)
                     .setCity("London")
                     .build();
  std::cout << "Result 2: " << result2 << "\n";

  std::cout << "\n";
}

void demonstrateCRTPLike()
{
  std::cout << "=== CRTP-like Example ===\n";

  Derived d;
  Base<Derived> b;

  d.doSomething();
  b.doSomething();

  std::cout << "\n";
}

int main()
{
  std::cout << "C++23 Deducing This Examples\n";
  std::cout << "============================\n\n";

  FunctionOverloading();
  demonstrateFluentBuilder();
  demonstrateCRTPLike();

  std::cout << "Key Benefits of Deducing This:\n";
  std::cout << "1. Eliminates code duplication for const/non-const overloads\n";
  std::cout << "2. Perfect forwarding of value categories\n";
  std::cout << "3. Simplifies fluent interfaces\n";
  std::cout << "5. Type-safe CRTP-like patterns\n";

  return 0;
}
