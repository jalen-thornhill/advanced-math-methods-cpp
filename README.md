# Advanced Math Methods C++ Toolkit

A C++ console application that demonstrates advanced mathematical methods through modular tools for complex numbers, matrices, root approximation, sequences, numerical calculus, and report export. Counting and probability remain planned features.

This project was built as an employer-facing portfolio project to show C++ fundamentals, modular design, mathematical algorithms, basic input checks, and command-line interaction. Input validation is not yet comprehensive.

---

## Features

* Complex number operations

  * Addition
  * Subtraction
  * Multiplication
  * Division
  * Modulus
  * Argument in radians
  * Conjugate
  * Polar form

* Matrix operations

  * Matrix display
  * Dimension checks
  * Matrix addition and subtraction
  * Matrix multiplication
  * Transpose
  * 2x2 determinant
  * 3x3 determinant
  * 2x2 inverse
  * Row echelon form

* Root approximation

  * Preset function evaluation
  * Derivative evaluation
  * Linear interpolation
  * Newton-Raphson approximation

* Sequence and series tools

  * Arithmetic sequences
  * Geometric sequences
  * Partial sums
  * Recurrence sequences

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

## Course Concepts Demonstrated

* Complex numbers
* Matrices and determinants
* Matrix inverses
* Row echelon form
* Systems of equations
* Numerical root approximation
* Linear interpolation
* Newton-Raphson method
* Sequences and series
* Numerical differentiation
* Numerical integration
* Euler approximation
* Modular C++ programming
* File input/output
* Console-based user interaction

---

## Project Structure

```text
advanced-math-methods-cpp/
  src/
    main.cpp
    ComplexTool.hpp
    ComplexTool.cpp
    MatrixTool.hpp
    MatrixTool.cpp
    RootTool.hpp
    RootTool.cpp
    SequenceTool.hpp
    SequenceTool.cpp
    CalculusTool.hpp
    CalculusTool.cpp
    ReportWriter.hpp
    ReportWriter.cpp

  docs/
    DESIGN.md
    TEST_PLAN.md
    TEST_PART.md

  reports/
    .gitkeep
    session_report.txt  (generated when exporting)

  README.md
  .gitignore
  LICENSE
```

---

## Build Instructions

Requires a C++17 compiler. The Windows build has been verified with MSYS2 UCRT64 GCC 14.2.0.

From the project root in PowerShell:

```powershell
$env:PATH = 'C:\msys64\ucrt64\bin;' + $env:PATH
New-Item -ItemType Directory -Force -Path build | Out-Null
$sourceFiles = @(Get-ChildItem -LiteralPath src -Filter '*.cpp' | ForEach-Object { $_.FullName })
g++ -std=c++17 -Wall -Wextra -Wpedantic @sourceFiles -o build/math_toolkit.exe
```

Adjust the compiler path for your installation. Continue only if compilation succeeds. Two signed/unsigned comparison warnings remain in `SequenceTool.cpp`.

For Linux/macOS, the equivalent build commands are below; those platforms have not been verified in this refresh:

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra -Wpedantic src/*.cpp -o build/math_toolkit
```

---

## Run Instructions

On Windows:

```powershell
Push-Location build
try {
    .\math_toolkit.exe
} finally {
    Pop-Location
}
```

On Linux/macOS:

```bash
cd build
./math_toolkit
```

Running from `build/` keeps generated reports under `build/reports/`, which is ignored by Git. Reports are always written relative to the program's current working directory.

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

Example complex number operation:

```text
Input:
(3 + 2i) + (1 + 4i)

Output:
4 + 6i
```

Example Newton-Raphson operation:

```text
Function: f(x) = x^2 - 2
Starting x: 1
Iterations: 5

Result approaches:
1.4142
```

Example matrix multiplication:

```text
A = [[1, 2], [3, 4]]
B = [[5, 6], [7, 8]]

A * B = [[19, 22], [43, 50]]
```

---

## Testing

Testing documentation is included in the [test plan](docs/TEST_PLAN.md) and [test report](docs/TEST_PART.md).

The project was tested for:

* Complex arithmetic
* Complex modulus and argument
* Matrix multiplication
* Linear interpolation
* Newton-Raphson approximation
* Sequence partial sums
* Trapezium rule integration
* Report export

The verification run passed 21 direct-method checks and 11 console scenarios. This is selected coverage, not an exhaustive regression suite. The 2x2 determinant, inverse, and row-echelon test cases are still marked as not run; combinations are blocked because probability is unimplemented.

---

## Screenshots

A `screenshots/` folder can be created later to show:

* Main menu
* Complex number tool
* Matrix tool
* Root approximation tool
* Calculus tool
* Report export confirmation

---

## Future Work

* Implement the counting and probability tool
* Resolve the remaining compiler warnings
* Add unit tests with a C++ testing framework
* Add stronger input validation for all menu options, including recovery from nonnumeric input
* Validate rectangular matrix data and handle matrix-operation errors in the menus
* Add support for larger matrix operations
* Add reduced row echelon form
* Add graph output for function approximation results
* Add persistent session history
* Add a GUI version

---

## License

This project is licensed under the [MIT License](LICENSE).

Copyright (c) 2026 Jalen Thornhill.
