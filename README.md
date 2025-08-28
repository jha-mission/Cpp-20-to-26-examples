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

### Library Features
- std::execute


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