# Design

## Modules

- ComplexTool: complex arithmetic, modulus, argument, conjugate, and polar display.
- MatrixTool: matrix operations, determinants, inverse, and row echelon form.
- RootTool: preset functions and derivatives, linear interpolation, and Newton-Raphson methods.
- SequenceTool: arithmetic, geometric, and recurrence sequences, plus partial sums.
- CalculusTool: preset function evaluation, numerical derivatives, trapezium integration, and Euler approximation.
- ReportWriter: writes supplied report text and checks the file stream after closing.
- Probability: a main-menu placeholder only; there is no ProbabilityTool implementation.

## Design Principles

- Each module handles one math area.
- Calculation methods accept numeric data directly where practical.
- Each working tool has an interactive menu receiving `string& lastResult`.
- The main menu handles navigation and coordinates report export.
- Output formatting is separated from calculations where practical. Some calculation methods still print progress or errors.

## Calculation and Report Flow

1. The user selects a working tool.
2. Its menu reads the calculation inputs and calls the appropriate method.
3. A local string stream builds report text containing the operation, inputs, and result.
4. When report text is produced, it replaces the shared `lastResult`. Returning or entering a menu without calculating leaves that string unchanged.
5. Main-menu option 7 rejects empty result text, creates `reports/` if needed, and writes `reports/session_report.txt`.

The report contains the latest calculation, not the full session history. Export replaces an existing file and uses the current working directory. The report writer itself does not create parent directories; the main menu does.

## Numerical Methods

- Root presets: `x^2 - 2`, `x^3 - x - 2`, `cos(x) - x`, and `exp(x) - 3`.
- Root derivatives use explicit formulas. The derivative of `exp(x) - 3` is `exp(x)`.
- Linear interpolation takes a single straight-line root estimate from two endpoints.
- Newton-Raphson runs the requested number of updates, stopping early for a near-zero derivative; it does not guarantee convergence.
- Calculus uses central differences with `h = 0.00001`, trapezium integration, and Euler steps for `dy/dx = x + y`.
- Row echelon form uses forward elimination with exact zero comparisons and assumes rectangular input.

## Current Limits

Probability remains unfinished. Input recovery, matrix-shape validation, exception handling in matrix menus, numerical edge cases, and complete session history need further work. Two signed/unsigned warnings remain in the sequence display method.
