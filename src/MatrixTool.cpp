#include <iostream>
#include "MatrixTool.hpp"
#include <iomanip>

using namespace std;

void printMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& value : row) {
            cout << setw(10) << value << " ";
        }
        cout << endl;
    }
}

bool sameDimensions(const Matrix& a, const Matrix& b) {
    return (a.size() == b.size()) && (a.empty() || a[0].size() == b[0].size());
}

bool canMultiply(const Matrix& a, const Matrix& b) {
    return !a.empty() && !b.empty() && a[0].size() == b.size();
}

Matrix addMatrices(const Matrix& a, const Matrix& b) {
    if (!sameDimensions(a, b)) {
        throw invalid_argument("Matrices must have the same dimensions for addition.");
    }
    Matrix result = a;
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[0].size(); ++j) {
            result[i][j] += b[i][j];
        }
    }
    return result;
}

Matrix subtractMatrices(const Matrix& a, const Matrix& b) {
    if (!sameDimensions(a, b)) {
        throw invalid_argument("Matrices must have the same dimensions for subtraction.");
    }
    Matrix result = a;
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < a[0].size(); ++j) {
            result[i][j] -= b[i][j];
        }
    }
    return result;
}


Matrix multiplyMatrices(const Matrix& a, const Matrix& b) {
    if (!canMultiply(a, b)) {
        throw invalid_argument("Number of columns in the first matrix must equal the number of rows in the second matrix for multiplication.");
    }
    Matrix result(a.size(), vector<double>(b[0].size(), 0.0));
    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < b[0].size(); ++j) {
            for (size_t k = 0; k < a[0].size(); ++k) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}


Matrix transpose(const Matrix& matrix) {
    if (matrix.empty()) return {};
    Matrix result(matrix[0].size(), vector<double>(matrix.size()));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}