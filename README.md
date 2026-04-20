# dc3

This repository contains a simple C++ implementation of the DC3 suffix array algorithm in [`dc3.h`](/home/xding9001/dc3/dc3.h) and a small benchmark/check binary in [`dc3_test.cpp`](/home/xding9001/dc3/dc3_test.cpp).

`dc3_test` generates a random integer string, builds a suffix array with both:

- `suffix_array(...)` from `parlaylib`
- `DC3(...)` from this repository

It verifies that the two outputs match and prints timing information for both implementations.

## Requirements

- CMake 3.20 or newer
- A C++20 compiler

## Build

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

## Run

Use the default input size:

```bash
./build/dc3_test
```

Pass a custom input size:

```bash
./build/dc3_test 100000
```

The argument is the generated sequence length `n`. It must be a positive integer.

## Repository Layout

- [`dc3.h`](/home/xding9001/dc3/dc3.h): DC3 implementation
- [`dc3_test.cpp`](/home/xding9001/dc3/dc3_test.cpp): driver, correctness check, and timing output
- [`parlaylib`](/home/xding9001/dc3/parlaylib): remaining submodule dependency
