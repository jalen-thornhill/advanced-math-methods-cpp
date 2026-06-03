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
Matrix rowEchelonForm(const Matrix& matrix);

double determinant2x2(const Matrix& matrix);

double determinant3x3(const Matrix& matrix);
};

Matrix MatrixTool::rowEchelonForm(const Matrix& matrix) {
    if (matrix.empty()) {
        return Matrix{};
    }

    Matrix result = matrix;
    int rows = result.size();
    int cols = result[0].size();

    int pivotRow = 0;

    for (int col = 0; col < cols && pivotRow < rows; col++) {
        int pivot = -1;

        for (int row = pivotRow; row < rows; row++) {
            if (result[row][col] != 0) {
                pivot = row;
                break;
            }
        }

        if (pivot == -1) {
            continue;
        }

        swap(result[pivotRow], result[pivot]);

        double pivotValue = result[pivotRow][col];

        for (int j = col; j < cols; j++) {
            result[pivotRow][j] /= pivotValue;
        }

        for (int row = pivotRow + 1; row < rows; row++) {
            double factor = result[row][col];

            for (int j = col; j < cols; j++) {
                result[row][j] -= factor * result[pivotRow][j];
            }
        }

        pivotRow++;
    }

    return result;
}