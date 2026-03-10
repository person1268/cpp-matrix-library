# C++ Matrix Library

A simple object-oriented matrix library written in C++ that demonstrates core data structures and object-oriented programming concepts.

This project was developed as part of coursework in computer science and showcases the implementation of a custom `Matrix` class with several mathematical operations.

---

## Features

* Dynamic 2-D matrix creation
* Matrix addition and subtraction
* Matrix multiplication
* Matrix minimum and maximum value detection
* Input and output functions for matrices
* Separation of interface and implementation using header and source files

---

## Concepts Demonstrated

This project demonstrates several fundamental C++ concepts:

* Object-oriented design
* Class implementation with encapsulation
* Header/source file separation
* Dynamic memory usage
* Algorithm implementation for matrix operations

---

## Project Structure

```
cpp-matrix-library
│
├── main.cpp       # Program entry point
├── main.h
├── matrix.cpp     # Matrix class implementation
├── matrix.h       # Matrix class definition
└── README.md
```

---

## Example

Example matrix multiplication:

```
Matrix A (2x2)
1 2
3 4

Matrix B (2x2)
5 6
7 8

Result (A * B)
19 22
43 50
```

---

## How to Compile

Compile using g++:

```
g++ main.cpp matrix.cpp -o matrix_program
```

Run:

```
./matrix_program
```

---

## Future Improvements

Potential extensions to this project:

* operator overloading (`+`, `*`)
* matrix transpose function
* determinant calculation
* unit tests
* template support for different numeric types

---

## Author

John Pleasant
Computer Science Student
