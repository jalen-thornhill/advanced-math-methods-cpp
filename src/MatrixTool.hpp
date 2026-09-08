#pragma once

#include <vector>
#include <string>

// I am representing a matrix as a vector of rows containing numeric values.
using Matrix = std::vector<std::vector<double>>;

// I am grouping matrix input, display, dimension checks, and calculations in this class.
class MatrixTool {

public:
// I am declaring the methods that display matrices and present the interactive menu.
void printMatrix(const Matrix& matrix);
void MatrixMenu(std::string& lastResult);

// I am declaring dimension checks used before combining two matrices.
bool sameDimensions(const Matrix& a, const Matrix& b);

bool canMultiply(const Matrix& a, const Matrix& b);


// I am declaring arithmetic operations that return a separate result matrix.
Matrix addMatrices(const Matrix& a, const Matrix& b);
Matrix subtractMatrices(const Matrix& a, const Matrix& b);
Matrix multiplyMatrices(const Matrix& a, const Matrix& b);
// I am declaring transformations for transposing, inverting, and reducing a matrix to row echelon form.
Matrix transpose(const Matrix& matrix);
Matrix inverse2x2(const Matrix& matrix);
Matrix rowEchelonForm(const Matrix& matrix);
// I am declaring the method that collects a matrix from console input.
Matrix  inputMatrix();

// I am declaring determinant calculations for 2x2 and 3x3 matrices.
double determinant2x2(const Matrix& matrix);

double determinant3x3(const Matrix& matrix);


};

