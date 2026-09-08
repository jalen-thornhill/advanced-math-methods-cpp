# Test Report

## Project

Advanced Math Methods C++ Toolkit

## Test Environment

- Run date: 2026-09-07.
- Source: local working tree based on `3294f51`, including Milestone 4 fixes.
- Language: C++17.
- Compiler: MSYS2 UCRT64 GCC 14.2.0.
- Operating system: Windows.
- Build flags: `-std=c++17 -Wall -Wextra -Wpedantic`.
- Full application build: passed, exit status zero.
- Warnings: two signed/unsigned comparisons in `SequenceTool.cpp`.

See the [README](../README.md) for build and run commands. The obsolete command referencing ProbabilityTool.cpp was not used.

## Test Results

Against the cases defined in the [test plan](TEST_PLAN.md):

- T1 - Passed: complex addition returned `4 + 6i`.
- T2 - Passed: complex multiplication returned `-5 + 14i`.
- T3 - Passed: modulus returned `5`.
- T4 - Passed: argument matched `0.9272952180016122` radians within the direct-method tolerance.
- T5 - Passed: the console calculation and exported matrix contained `[[19,22],[43,50]]`.
- T6 - Not run: the 2x2 determinant case has not been verified in this refresh.
- T7 - Not run: the inverse case has not been verified in this refresh.
- T8 - Not run: the row-echelon case has not been verified in this refresh.
- T9 - Passed: interpolation matched `4/3`.
- T10 - Passed: five Newton updates matched `sqrt(2)`.
- T11 - Passed: arithmetic terms were `2, 5, 8`, with sum `15`.
- T12 - Blocked: probability is not implemented.
- T13 - Passed: the trapezium approximation matched `2.6668`.
- T14 - Passed: report export contained actual calculation details.

Plan-case total: 10 passed, 3 not run, 1 blocked.

## Additional Verification

A separate test driver exercised 21 direct-method checks. All passed after the fixes:

- Seven complex-number checks: addition, subtraction, multiplication, division, modulus, argument, and conjugate.
- Three root checks: interpolation, Newton iteration for `x^2 - 2`, and the derivative of `exp(x) - 3` at zero.
- Five sequence checks: arithmetic, sum, geometric, recurrence, and zero-term behaviour.
- Four calculus checks: derivative of `x^2` at 3, trapezium integration, two Euler steps, and zero-interval fallback.
- Two report-writer checks: writing the supplied text and rejecting a missing parent directory.

Eleven full-application console scenarios also passed:

- Exports from the complex, matrix, root, sequence, and calculus tools.
- Preserving the result after entering and leaving an unused tool and selecting probability.
- Replacing an earlier report with a later calculation.
- Preserving the result after an invalid formula choice.
- Preserving the result after division by zero.
- Rejecting export when no result exists.
- Reporting failure when the output file path is a directory.

The root preset labels were checked in the root console scenario. All console scenarios exited with status zero. These counts overlap the plan cases above; they are not 42 distinct plan tests.

The test driver and temporary executables were run outside the repository. They are not a committed automated test suite. The plan includes instructions for repeating selected checks through the console.

## Issues Found

Resolved in Milestone 4:

- Duplicate matrix-method declaration prevented compilation.
- A report-menu variable crossed switch-case labels, preventing compilation.
- The exponential derivative incorrectly subtracted 3.
- Root preset labels did not match the implemented formulas.
- Calculus was implemented but disconnected from the main menu.
- Report export never received a calculation result.

Still open:

- Probability is unfinished.
- Two compiler warnings remain.
- Input recovery, matrix validation, menu exception handling, and numerical edge cases need further work.
- Reports hold only the latest result and overwrite the previous report.

## Summary

The full application now builds, and the selected regression checks pass. Testing is not exhaustive: the unrun and blocked cases above remain explicit. Milestone 5 updates documentation and licensing only; these results describe the Milestone 4 verification, not a claim that every documented feature was tested.
