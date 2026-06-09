# Test Plan

## Project

Advanced Math Methods C++ Toolkit

## Purpose

This test plan verifies that the main mathematical tools work correctly, handle valid input, and produce readable output.

## Test Scope

The following features will be tested:

* Complex arithmetic
* Complex modulus and argument
* Matrix multiplication
* 2x2 matrix inverse
* Row echelon form
* Linear interpolation
* Newton-Raphson approximation
* Sequence partial sums
* Combination calculation
* Trapezium rule integration
* Report export

## Test Cases

| Test ID | Feature                         | Test Input                                | Expected Result                                                  |
| ------- | ------------------------------- | ----------------------------------------- | ---------------------------------------------------------------- |
| T1      | Complex addition                | `(3 + 2i) + (1 + 4i)`                     | `4 + 6i`                                                         |
| T2      | Complex multiplication          | `(3 + 2i) * (1 + 4i)`                     | `-5 + 14i`                                                       |
| T3      | Complex modulus                 | `3 + 4i`                                  | `5`                                                              |
| T4      | Complex argument                | `3 + 4i`                                  | Approximately `0.927` radians                                    |
| T5      | Matrix multiplication           | `[[1,2],[3,4]] * [[5,6],[7,8]]`           | `[[19,22],[43,50]]`                                              |
| T6      | 2x2 determinant                 | `[[1,2],[3,4]]`                           | `-2`                                                             |
| T7      | 2x2 inverse                     | `[[4,7],[2,6]]`                           | Approximately `[[0.6,-0.7],[-0.2,0.4]]`                          |
| T8      | Row echelon form                | `[[1,2,3],[2,4,6],[1,1,1]]`               | Entries below pivots become `0`                                  |
| T9      | Linear interpolation            | `f(x)=x^2-2`, `a=1`, `b=2`                | Approximately `1.3333`                                           |
| T10     | Newton-Raphson                  | `f(x)=x^2-2`, start `1`, iterations `5`   | Approaches `1.4142`                                              |
| T11     | Arithmetic sequence partial sum | `2, 5, 8`, sum                            | `15`                                                             |
| T12     | Combination calculation         | `n=5`, `r=2`                              | `10`                                                             |
| T13     | Trapezium rule                  | `f(x)=x^2`, `a=0`, `b=2`, intervals `100` | Approximately `2.6667`                                           |
| T14     | Report export                   | Export last result                        | `reports/session_report.txt` is created and contains result text |

## Pass Criteria

A test passes when:

* The program compiles.
* The feature runs without crashing.
* The output matches the expected result or is acceptably close for numerical approximations.
* Invalid inputs are handled safely where applicable.

## Notes

Numerical approximation tests may not match exact values due to floating-point rounding.
