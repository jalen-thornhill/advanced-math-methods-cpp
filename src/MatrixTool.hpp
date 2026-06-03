#pragma once

#include <vector>

using Matrix = std::vector<std::vector<double>>;

class MatrixTool {

public:
void printMatrix(const Matrix& matrix);

bool sameDimensions(const Matrix& a, const Matrix& b);

bool canMultiply(const Matrix& a, const Matrix& b);


Matrix addMatrices(const Matrix& a, const Matrix& b);
Matrix subtractMatrices(const Matrix& a, const Matrix& b);
Matrix multiplyMatrices(const Matrix& a, const Matrix& b);
Matrix transpose(const Matrix& matrix);
Matrix inverse2x2(const Matrix& matrix);

double determinant2x2(const Matrix& matrix);

double determinant3x3(const Matrix& matrix);
};
