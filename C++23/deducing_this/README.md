# C++23 Deducing This

## What is Deducing This?

The "deducing this" feature allows to make the implicit `this` pointer explicit.
A member functions can then deduce the type and value category (const/non-const, lvalue/rvalue) of it's object.

## Key Benefits

1. **Eliminates Code Duplication**: No need for separate const/non-const overloads
2. **Perfect Forwarding**: Preserves value categories (lvalue/rvalue references)
3. **Fluent Interfaces**: Enables efficient method chaining
4. **Type Safety**: Better type deduction in CRTP-like patterns

## Examples in this Demo

### 1. DataContainer
Shows how a single function can replace 4 traditional overloads:
- `const T& get() const &`
- `T& get() &`
- `const T&& get() const &&`
- `T&& get() &&`

### 2. FluentBuilder
Demonstrates perfect forwarding in method chaining, allowing both lvalue and rvalue objects to chain efficiently.

### 3. CRTP-like Pattern
Shows how deducing this can simplify inheritance patterns that previously required CRTP.

### 4. RecursiveExample
Illustrates how value categories are preserved through recursive calls.

## Perfect Forwarding
If a function templates forward its arguments without changing its lvalue or rvalue characteristics, we call it perfect forwarding.



## References

- [P0847R7: Deducing this](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2021/p0847r7.html)
- [C++23 Features](https://en.cppreference.com/w/cpp/23)
- [lvalues, rvalues](https://www.justsoftwaresolutions.co.uk/cplusplus/core-c++-lvalues-and-rvalues.html)