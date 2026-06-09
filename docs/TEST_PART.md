# Test Report

## Project

Advanced Math Methods C++ Toolkit

## Test Environment

* Language: C++
* Interface: Console application
* Compiler: g++
* Operating System: Windows

## Build Command

```bash
g++ src/main.cpp src/ComplexTool.cpp src/MatrixTool.cpp src/RootTool.cpp src/SequenceTool.cpp src/ProbabilityTool.cpp src/CalculusTool.cpp src/ReportWriter.cpp -o math_toolkit.exe
```

## Run Command

```bash
.\math_toolkit.exe
```

## Test Results

| Test ID | Feature                 | Expected Result                         | Actual Result | Status  |
| ------- | ----------------------- | --------------------------------------- | ------------- | ------- |
| T1      | Complex addition        | `4 + 6i`                                |               | Not Run |
| T2      | Complex multiplication  | `-5 + 14i`                              |               | Not Run |
| T3      | Complex modulus         | `5`                                     |               | Not Run |
| T4      | Complex argument        | Approximately `0.927` radians           |               | Not Run |
| T5      | Matrix multiplication   | `[[19,22],[43,50]]`                     |               | Not Run |
| T6      | 2x2 determinant         | `-2`                                    |               | Not Run |
| T7      | 2x2 inverse             | Approximately `[[0.6,-0.7],[-0.2,0.4]]` |               | Not Run |
| T8      | Row echelon form        | Values below pivots become `0`          |               | Not Run |
| T9      | Linear interpolation    | Approximately `1.3333`                  |               | Not Run |
| T10     | Newton-Raphson          | Approaches `1.4142`                     |               | Not Run |
| T11     | Sequence partial sum    | `15`                                    |               | Not Run |
| T12     | Combination calculation | `10`                                    |               | Not Run |
| T13     | Trapezium rule          | Approximately `2.6667`                  |               | Not Run |
| T14     | Report export           | Report file created successfully        |               | Not Run |

## Issues Found

| Issue ID | Description | Status |
| -------- | ----------- | ------ |
| I1       |             |        |
| I2       |             |        |

## Summary

Testing is complete when all implemented features have been run and the `Actual Result` and `Status` columns are filled in.

Final status: Pending
