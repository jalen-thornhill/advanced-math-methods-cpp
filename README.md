# Advanced Math Methods C++ Toolkit

A C++ console application that demonstrates advanced mathematical for complex numbers, matrices, root approximation, sequences, numerical calculus, and report export.
---

## Features

* Complex number operations

  * Addition
  * Subtraction
  * Multiplication
  * Division
  * Modulus
  * & more


* Matrix operations

  * 2x2 determinant
  * 3x3 determinant
  * 2x2 inverse
  * & more

* Root approximation

* Sequence and series tools

  * Arithmetic sequences
  * Geometric sequences


* Probability tools (planned, not implemented)

  * Factorials
  * Permutations
  * Combinations
  * Basic probability calculations

* Numerical calculus tools

  * Numerical derivative approximation
  * Trapezium rule integration
  * Euler approximation

* Report export

  * Exports the latest calculation's inputs and result to `reports/session_report.txt`
  * Creates the `reports/` directory when needed and reports file-output errors
  * Replaces an existing report; complete session history is not saved

---




## Build Instructions

Requires a C++17 compiler. The Windows build has been verified with MSYS2 UCRT64 GCC 14.2.0.



```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -Wpedantic src/*.cpp -o build/math_toolkit
```

---

## Run Instructions

On Windows:

```powershell
.\math_toolkit.exe
```

On Linux/macOS:

```bash
cd build
./math_toolkit
```
---

## Example Usage

Main menu:

```text
Advanced Math Methods C++ Toolkit

1. Complex Number Tool
2. Matrix Tool
3. Root Approximation Tool
4. Sequence and Series Tool
5. Counting and Probability Tool (coming soon)
6. Numerical Calculus Tool
7. Export Latest Result
0. Exit
```

After completing a calculation, return to the main menu and select `7` to export it. Entering an unused menu or choosing probability does not replace the saved result. Exporting before a calculation displays “No result to export yet.”

## License

This project is licensed under the [MIT License](LICENSE).

Copyright (c) 2026 Jalen Thornhill.
