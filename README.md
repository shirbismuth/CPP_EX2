# Square Matrix Project – `SquareMat`

##  Project Description

This project implements a `SquareMat` class in C++ that represents square matrices of real numbers.  
It supports a wide range of arithmetic and logical operations using overloaded operators, aiming to mimic native types in usability.

##  File Structure

| File                   | Description                                                                 |
|------------------------|-----------------------------------------------------------------------------|
| `SquareMat.hpp`        | Header file – contains the declaration of the `SquareMat` class             |
| `SquareMat.cpp`        | Source file – full implementation of the `SquareMat` class functions        |
| `Main.cpp`             | Demo file – showcases usage of the matrix and its operators                 |
| `SquareMat_doctest.cpp`| Unit tests written using the `doctest` framework                            |
| `doctest.h`            | Header-only unit testing library (no installation required)                 |
| `makefile`             | Automates building, testing, memory checks, and cleaning                    |

##  Usage Instructions

### Compile and Run Demo
```bash
make Main
./Main
```

### Run Unit Tests
```bash
make test
```

### Check for Memory Leaks (valgrind)
```bash
make valgrind
```

### Clean Build Files
```bash
make clean
```

##  `SquareMat` Capabilities

- Matrix addition, subtraction, multiplication
- Scalar multiplication and division
- Element-wise multiplication and modulo
- Matrix exponentiation
- Transpose
- Determinant calculation
- Compound assignments (`+=`, `-=`, `*=`, `%=` etc.)
- Access via double indexing `[][]`
- Logical comparisons (`==`, `!=`, `<`, `>=`, etc.)
- Stream output using `<<`

##  Notes

- Invalid inputs (e.g., non-square matrices, division by zero) will throw `std::invalid_argument`.
- All tests pass successfully, and memory usage is verified clean using `valgrind`.

---

© 2025 Shir Bismuth

