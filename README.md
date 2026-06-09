# Advanced Math Methods C++ Toolkit

A C++ console application that demonstrates advanced mathematical methods through modular tools for complex numbers, matrices, root approximation, sequences, probability, numerical calculus, and report export.

This project was built as an employer-facing portfolio project to show C++ fundamentals, modular design, mathematical algorithms, input validation, and clean command-line interaction.

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

* Probability tools

  * Factorials
  * Permutations
  * Combinations
  * Basic probability calculations

* Numerical calculus tools

  * Numerical derivative approximation
  * Trapezium rule integration
  * Euler approximation

* Report export

  * Exports session results to `reports/session_report.txt`

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
* Counting and probability
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
    ComplexTool.h
    ComplexTool.cpp
    MatrixTool.h
    MatrixTool.cpp
    RootTool.h
    RootTool.cpp
    SequenceTool.h
    SequenceTool.cpp
    ProbabilityTool.h
    ProbabilityTool.cpp
    CalculusTool.h
    CalculusTool.cpp
    ReportWriter.h
    ReportWriter.cpp

  docs/
    REQUIREMENTS.md
    DESIGN.md
    TEST_PLAN.md
    TEST_REPORT.md

  reports/
    .gitkeep
    session_report.txt

  screenshots/

  README.md
  .gitignore
  LICENSE
```

---

## Build Instructions

From the project root, compile with:

```bash
g++ src/main.cpp src/ComplexTool.cpp src/MatrixTool.cpp src/RootTool.cpp src/SequenceTool.cpp src/ProbabilityTool.cpp src/CalculusTool.cpp src/ReportWriter.cpp -o math_toolkit.exe
```

---

## Run Instructions

On Windows:

```bash
.\math_toolkit.exe
```

On Linux/macOS:

```bash
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
5. Counting and Probability Tool
6. Numerical Calculus Tool
7. Export Session Report
0. Exit
```

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

Testing documentation is included in:

```text
docs/TEST_PLAN.md
docs/TEST_REPORT.md
```

The project was tested for:

* Complex arithmetic
* Complex modulus and argument
* Matrix multiplication
* 2x2 inverse
* Row echelon form
* Linear interpolation
* Newton-Raphson approximation
* Sequence partial sums
* Combination calculation
* Trapezium rule integration
* Report export

---

## Screenshots

Runtime screenshots can be added to the `screenshots/` folder to show:

* Main menu
* Complex number tool
* Matrix tool
* Root approximation tool
* Calculus tool
* Report export confirmation

---

## Future Work

* Add unit tests with a C++ testing framework
* Add stronger input validation for all menu options
* Add support for larger matrix operations
* Add reduced row echelon form
* Add graph output for function approximation results
* Add persistent session history
* Add a GUI version

---

## License

This project is licensed under the MIT License.
