# Design

## Modules

- ComplexTool: complex arithmetic, modulus, argument, conjugate
- MatrixTool: matrix operations, determinants, inverse, row echelon form
- RootTool: linear interpolation and Newton-Raphson methods
- SequenceTool: arithmetic/geometric sequences and partial sums
- ProbabilityTool: factorials, permutations, combinations, simple probability
- CalculusTool: derivative, trapezium rule, Euler approximation
- ReportWriter: export results to text file

## Design Principles

- Each module handles one math area.
- Main menu handles user navigation only.
- Calculation functions avoid direct input where possible.
- Output formatting is separated from core calculations where practical.