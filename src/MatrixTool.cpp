#include <iostream>
#include "MatrixTool.hpp"
#include <iomanip>

using namespace std;

void MatrixTool::printMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (const auto& value : row) {
            cout << setw(10) << value << " ";
        }
        cout << endl;
    }
}

bool MatrixTool::sameDimensions(const Matrix& a, const Matrix& b) {
    return (a.size() == b.size()) && (a.empty() || a[0].size() == b[0].size());
}

bool MatrixTool::canMultiply(const Matrix& a, const Matrix& b) {
    return !a.empty() && !b.empty() && a[0].size() == b.size();
}

Matrix MatrixTool::addMatrices(const Matrix& a, const Matrix& b) {
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

Matrix MatrixTool::subtractMatrices(const Matrix& a, const Matrix& b) {
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


Matrix MatrixTool::multiplyMatrices(const Matrix& a, const Matrix& b) {
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


Matrix MatrixTool::transpose(const Matrix& matrix) {
    if (matrix.empty()) return {};
    Matrix result(matrix[0].size(), vector<double>(matrix.size()));
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

double MatrixTool::determinant2x2(const Matrix& matrix) {
    if (matrix.size() != 2 || matrix[0].size() != 2 || matrix[1].size() != 2) {
        return 0;
    }

    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

double MatrixTool::determinant3x3(const Matrix& matrix) {
    if (matrix.size() != 3 ||
        matrix[0].size() != 3 ||
        matrix[1].size() != 3 ||
        matrix[2].size() != 3) {
        return 0;
    }

    return
        matrix[0][0] * (
            matrix[1][1] * matrix[2][2] -
            matrix[1][2] * matrix[2][1]
        )
        -
        matrix[0][1] * (
            matrix[1][0] * matrix[2][2] -
            matrix[1][2] * matrix[2][0]
        )
        +
        matrix[0][2] * (
            matrix[1][0] * matrix[2][1] -
            matrix[1][1] * matrix[2][0]
        );
}

Matrix MatrixTool::inverse2x2(const Matrix& matrix) {
    if (matrix.size() != 2 || matrix[0].size() != 2 || matrix[1].size() != 2) {
        return Matrix{};
    }

    double det = determinant2x2(matrix);

    if (det == 0) {
        return Matrix{};
    }

    Matrix inverse = {
        { matrix[1][1] / det, -matrix[0][1] / det },
        { -matrix[1][0] / det, matrix[0][0] / det }
    };

    return inverse;
}