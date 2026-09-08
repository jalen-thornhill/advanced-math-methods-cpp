# Test Plan

## Project

Advanced Math Methods C++ Toolkit

## Purpose

Check the implemented mathematical tools against known results and verify that report export saves calculation details.

## Test Environment and Method

Build all seven current source files with C++17 using the [README instructions](../README.md). The verified environment is Windows with MSYS2 UCRT64 GCC 14.2.0.

Run tests in a disposable working directory such as `build/`. Export overwrites `reports/session_report.txt` relative to that directory. Enter the menu numbers and input values separately at each prompt; select `0` to leave a tool and again to exit the application.

Results may be checked directly through class methods or through the menus. Record which method was used; compilation alone is not a passing runtime test.

## Test Cases

- T1 - Complex addition: `(3 + 2i) + (1 + 4i)` should give `4 + 6i`.
- T2 - Complex multiplication: the same operands should give `-5 + 14i`.
- T3 - Complex modulus: `3 + 4i` should give `5`.
- T4 - Complex argument: `3 + 4i` should give approximately `0.927295218` radians.
- T5 - Matrix multiplication: `[[1,2],[3,4]] * [[5,6],[7,8]]` should give `[[19,22],[43,50]]`.
- T6 - 2x2 determinant: `[[1,2],[3,4]]` should give `-2`.
- T7 - 2x2 inverse: `[[4,7],[2,6]]` should give approximately `[[0.6,-0.7],[-0.2,0.4]]`.
- T8 - Row echelon form: `[[1,2,3],[2,4,6],[1,1,1]]` should produce `[[1,2,3],[0,1,2],[0,0,0]]` with the current pivot selection.
- T9 - Linear interpolation: preset 1, `x^2 - 2`, with endpoints `1` and `2` should give `4/3`, approximately `1.33333`.
- T10 - Newton-Raphson: preset 1, starting at `1`, with `5` iterations should approach `sqrt(2)`, approximately `1.41421`.
- T11 - Arithmetic partial sum: first term `2`, difference `3`, and `3` terms should generate `2, 5, 8` and sum to `15`.
- T12 - Combinations: `n=5, r=2` would give `10`. Blocked until the probability tool is implemented; the placeholder is not a passing calculation.
- T13 - Trapezium integration: `x^2` on `[0,2]` with `100` intervals should give `2.6668`. The exact integral is `8/3`; allow absolute approximation error up to `0.0002`.
- T14 - Report export: perform a calculation, return to main, and select `7`. Expect a readable report with the operation, supplied inputs, and result, without menu prompts.

For direct-method checks, use an absolute tolerance of `0.00000001` for the values above unless the case states otherwise. For rounded console output, allow half a unit in the last displayed decimal place. Numerical approximation error and display rounding are separate concerns.

## Regression Checks

- Exponential derivative: root preset 4 at `x=0` must return `1`, not `-2`.
- Root menu: preset 3 must say `cos(x) - x`; preset 4 must say `e^x - 3`.
- Calculus menu: main option 6 must open the working calculus menu.
- Latest-result export: check exports from complex, matrix, root, sequence, and calculus tools.
- Result preservation: leaving a menu, selecting probability, rejecting an invalid formula, or rejecting division by zero must not replace an existing saved result.
- Report replacement: export two different calculations in succession; the final report must contain the second calculation.
- Empty export: option 7 before any calculation must report that no result is available and must not create a report.
- Export failure: create a directory named `reports/session_report.txt` in a disposable test folder. Export must report failure rather than success.

## Reproducible Console Example

After building, run this from the repository root in PowerShell:

```powershell
Push-Location build
try {
    $testInput = @(6,2,1,3,0,7,0) -join "`n"
    $testInput | & .\math_toolkit.exe
    "Runtime status: $LASTEXITCODE"
    Get-Content reports/session_report.txt
} finally {
    Pop-Location
}
```

Expect normal exit and a report containing `Numerical derivative: choice=1, x=3` and `Result: 6`. This example overwrites a previous report.

## Pass Criteria and Remaining Coverage

A passing case must build, complete normally, and match its expected output within the stated tolerance. Error tests must report the expected failure without replacing a valid saved result where applicable.

The [test report](TEST_PART.md) records actual results. Do not infer that untested cases passed. Nonnumeric input, ragged matrices, all determinant and inverse cases, convergence failures, large inputs, and all file-output failure modes need broader coverage.
