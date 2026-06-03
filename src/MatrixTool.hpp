#pragma once

#include <vector>

using Matrix = std::vector<std::vector<double>>;

void printMatrix(const Matrix& matrix);

bool sameDimensions(const Matrix& a, const Matrix& b);

bool canMultiply(const Matrix& a, const Matrix& b);