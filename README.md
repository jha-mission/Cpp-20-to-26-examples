# C++20 to C++26 Sample Code

## C++ 20
### Core Language Features
- Modules
- Ranges
- Concepts
- Coroutines
- Three-way comparison (spaceship operator)
- Designated initializers

### Library Features
- date and time library
- std::format
- std::span
- std::jthread

## C++ 23
### Core Language Features
- Deduction guides for class templates, "deducing this" (CRTP: Curiously Recurring Template Pattern)
- Explicit object parameters

### Library Features
- std::generator
- std::expected
- std::atomic smart pointers

## C++ 26
### Core Language Features
- Reflection
- Contracts


# C++20 to C++26 Study Plan (40 Hours / 1 Month)

## Weekly Overview

| Week | Focus                                      | Hours |
|------|--------------------------------------------|-------|
| 1    | C++20 Core Features                        | 10    |
| 2    | C++23 Additions                            | 10    |
| 3    | C++26 (Draft/Proposed Features) + Review   | 10    |
| 4    | Deep Dives + Projects + Final Review       | 10    |

---

## Week 1 – C++20 Deep Dive *(10h)*

**Goal**: Learn all major C++20 features and apply them.

| Day | Topic                                               | Hours |
|-----|-----------------------------------------------------|-------|
| 1   | Concepts, `requires` clauses                        | 2     |
| 2   | Ranges library (views, actions)                     | 2     |
| 3   | Coroutines (`co_await`, `co_yield`)                 | 2     |
| 4   | `consteval`, `constinit`, improved lambdas          | 2     |
| 5   | `<=>` (spaceship), modules (intro only)             | 2     |

**Practice Ideas**:
- Define custom concepts and constrain templates
- Build a range pipeline (e.g., filtering, transforming)
- Create a coroutine-based generator

---

## Week 2 – C++23 Features *(10h)*

**Goal**: Get comfortable with smaller yet powerful additions.

| Day | Topic                                                         | Hours |
|-----|---------------------------------------------------------------|-------|
| 1   | `std::expected`, `std::print`, `std::format` updates          | 2     |
| 2   | `if consteval`, `explicit(obj)`, `static operator()`          | 2     |
| 3   | `[[assume]]`, deducing `this`, more `constexpr`               | 2     |
| 4   | Ranges & span updates, `flat_map` (if supported)              | 2     |
| 5   | C++23 recap with a mini demo app                              | 2     |

**Practice Ideas**:
- Replace exceptions with `std::expected`
- Use `std::format` for structured CLI output
- Apply deducing `this` in a fluent interface

---

## Week 3 – C++26 Draft Features + Review *(10h)*

**Goal**: Explore the future of C++ and review past content.

| Day | Topic                                                      | Hours |
|-----|------------------------------------------------------------|-------|
| 1   | C++26 Overview (Papers from WG21, compiler previews)       | 2     |
| 2   | `std::embed`, `static_vector`, `is_transparent` updates    | 2     |
| 3   | Pattern Matching (if compiler supports)                    | 2     |
| 4   | Review C++20 Concepts & Ranges                             | 2     |
| 5   | Review C++23: `expected`, formatting, deducing `this`      | 2     |

**Resources**:
- [https://wg21.link](https://wg21.link)
- Compiler Explorer: [https://godbolt.org](https://godbolt.org)

---

## Week 4 – Mini Projects + Final Review *(10h)*

**Goal**: Apply knowledge through hands-on practice and review.

| Day | Topic                                                                 | Hours |
|-----|-----------------------------------------------------------------------|-------|
| 1   | Build a CLI app using `std::expected` + `std::format`                | 2     |
| 2   | Coroutine-based data pipeline using ranges & concepts                | 2     |
| 3   | Use modules in a small project                                       | 2     |
| 4   | Read & summarize 2–3 WG21 papers of interest                         | 2     |
| 5   | Final review & personal C++20–26 cheat sheet                         | 2     |

---

## 🔧 Tools & References

- **Compilers**: GCC 13+, Clang 17+, MSVC 2022+
- **Online Tools**:
  - [Compiler Explorer](https://godbolt.org)
  - [Wandbox](https://wandbox.org)
- **Reference**:
  - [cppreference.com](https://en.cppreference.com)
  - [wg21.link](https://wg21.link)
- **Blogs**:
  - [Barry Revzin](https://brevzin.github.io/)
  - [C++ Alliance](https://www.cppalliance.org/)
- **Books**:
  - *C++20: The Complete Guide* – Nicolai Josuttis
  - *Programming with C++20* – Andreas Fertig
  - *C++23 by Example* – Slobodan Dmitrović

---

📝 **Tip**: Track your learning with a simple progress checklist or journal. Want a Notion version? Let me know!


## Build gcc-15

### Install dependencies for building GCC

  sudo apt install -y build-essential git make gawk flex bison libgmp-dev libmpfr-dev libmpc-dev python3 binutils perl libisl-dev libzstd-dev tar gzip bzip2

### Download GCC source code

  mkdir ~/gcc-15
  cd ~/gcc-15
  git clone https://gcc.gnu.org/git/gcc.git gcc-15-source
  cd gcc-15-source
  git checkout releases/gcc-15.1.0
  ./contrib/download_prerequisites

### Configuring the Build

  cd ~/gcc-15
  mkdir gcc-15-build
  cd gcc-15-build
  ../gcc-15-source/configure --prefix=/opt/gcc-15 --disable-multilib --enable-languages=c,c++

### Build and Install GCC

  make -j$(nproc)
  sudo make install