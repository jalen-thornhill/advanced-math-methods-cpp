#include <iostream>
#include <sstream>
#include "MatrixTool.hpp"
#include <iomanip>

using namespace std;

void MatrixTool::printMatrix(const Matrix& matrix) {
    // I am displaying each row with spaced columns to make the matrix readable.
    for (const auto& row : matrix) {
        for (const auto& value : row) {
            cout << setw(10) << value << " ";
        }
        cout << endl;
    }
}

bool MatrixTool::sameDimensions(const Matrix& a, const Matrix& b) {
    // I am comparing row counts and first-row widths, assuming that each matrix is rectangular.
    return (a.size() == b.size()) && (a.empty() || a[0].size() == b[0].size());
}

bool MatrixTool::canMultiply(const Matrix& a, const Matrix& b) {
    // I am checking for nonempty matrices and matching inner dimensions before multiplication.
    return !a.empty() && !b.empty() && a[0].size() == b.size();
}

Matrix MatrixTool::addMatrices(const Matrix& a, const Matrix& b) {
    // I am rejecting mismatched dimensions before adding corresponding elements in a copy of the first matrix.
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
    // I am rejecting mismatched dimensions before subtracting corresponding elements in a copy of the first matrix.
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
    // I am checking multiplication compatibility before creating the result matrix.
    if (!canMultiply(a, b)) {
        throw invalid_argument("Number of columns in the first matrix must equal the number of rows in the second matrix for multiplication.");
    }
    Matrix result(a.size(), vector<double>(b[0].size(), 0.0));
    // I am finding each result element by multiplying a row by a column and adding the products.
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
    // I am exchanging row and column positions, assuming that all input rows have equal lengths.
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
    // I am checking for a 2x2 matrix and returning zero if the dimensions do not match.
    if (matrix.size() != 2 || matrix[0].size() != 2 || matrix[1].size() != 2) {
        return 0;
    }

    // I am subtracting the off-diagonal product from the main-diagonal product.
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}

double MatrixTool::determinant3x3(const Matrix& matrix) {
    // I am checking for a 3x3 matrix before expanding its determinant along the first row.
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
    // I am checking the dimensions and determinant, returning an empty matrix when an inverse cannot be produced.
    if (matrix.size() != 2 || matrix[0].size() != 2 || matrix[1].size() != 2) {
        return Matrix{};
    }

    double det = determinant2x2(matrix);

    if (det == 0) {
        return Matrix{};
    }

    // I am swapping the diagonal entries, negating the other entries, and dividing by the determinant.
    Matrix inverse = {
        { matrix[1][1] / det, -matrix[0][1] / det },
        { -matrix[1][0] / det, matrix[0][0] / det }
    };

    return inverse;
}

Matrix MatrixTool::rowEchelonForm(const Matrix& matrix) {
    // I am working on a copy to preserve the input while applying forward elimination.
    // I am assuming rectangular rows and using exact zero comparisons when selecting pivots.
    if (matrix.empty()) {
        return Matrix{};
    }

    Matrix result = matrix;
    int rows = result.size();
    int cols = result[0].size();

    int pivotRow = 0;

    for (int col = 0; col < cols && pivotRow < rows; col++) {
        int pivot = -1;

        // I am searching the remaining rows for the first nonzero entry in this column.
        for (int row = pivotRow; row < rows; row++) {
            if (result[row][col] != 0) {
                pivot = row;
                break;
            }
        }

        if (pivot == -1) {
            // I am skipping a column when it has no available nonzero pivot.
            continue;
        }

        // I am moving the selected row into place and scaling it so that its pivot becomes one.
        swap(result[pivotRow], result[pivot]);

        double pivotValue = result[pivotRow][col];

        for (int j = col; j < cols; j++) {
            result[pivotRow][j] /= pivotValue;
        }

        // I am subtracting multiples of the pivot row to eliminate entries below the pivot.
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

Matrix MatrixTool::inputMatrix() {
    // I am reading the requested dimensions and then collecting the matrix values row by row.
    int rows;
    int cols;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    Matrix matrix(rows, vector<double>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter value [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    return matrix;
}


void MatrixTool::MatrixMenu(string& lastResult) {
    // I am repeating the matrix menu until the user chooses to return to the main menu.
    int choice;

    do {
        cout << "\nMatrix Tool Menu\n\n";
        cout << "1. Add Matrices\n";
        cout << "2. Subtract Matrices\n";
        cout << "3. Multiply Matrices\n";
        cout << "4. Transpose Matrix\n";
        cout << "5. Determinant of 2x2 Matrix\n";
        cout << "6. Determinant of 3x3 Matrix\n";
        cout << "7. Inverse of 2x2 Matrix\n";
        cout << "8. Row Echelon Form\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // I am collecting the calculation details separately from the menu prompts.
        ostringstream report;

        Matrix a;
        Matrix b;
        Matrix result;

        // I am collecting the matrices needed for the chosen operation and displaying its result.
        switch (choice) {
            case 1:
                a = inputMatrix();
                b = inputMatrix();
                result = addMatrices(a, b);
                report << "Matrix addition\n";
                printMatrix(result);
                break;

            case 2:
                a = inputMatrix();
                b = inputMatrix();
                result = subtractMatrices(a, b);
                report << "Matrix subtraction\n";
                printMatrix(result);
                break;

            case 3:
                a = inputMatrix();
                b = inputMatrix();
                result = multiplyMatrices(a, b);
                report << "Matrix multiplication\n";
                printMatrix(result);
                break;

            case 4:
                a = inputMatrix();
                result = transpose(a);
                report << "Matrix transpose\n";
                printMatrix(result);
                break;

            case 5:
                a = inputMatrix();
                cout << "Determinant: " << determinant2x2(a) << "\n";
                report << "2x2 determinant\nResult: " << determinant2x2(a) << "\n";
                break;

            case 6:
                a = inputMatrix();
                cout << "Determinant: " << determinant3x3(a) << "\n";
                report << "3x3 determinant\nResult: " << determinant3x3(a) << "\n";
                break;

            case 7:
                a = inputMatrix();
                result = inverse2x2(a);

                if (result.empty()) {
                    cout << "Matrix has no inverse.\n";
                } else {
                    report << "2x2 matrix inverse\n";
                    printMatrix(result);
                }
                break;

            case 8:
                a = inputMatrix();
                result = rowEchelonForm(a);
                report << "Row echelon form\n";
                printMatrix(result);
                break;

            case 0:
                cout << "Returning to Main Menu.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        // I am saving the input matrices and computed result without including menu prompts.
        if (!report.str().empty()) {
            report << "Matrix A:\n";
            for (const auto& row : a) {
                for (double value : row) report << value << " ";
                report << "\n";
            }
            if (!b.empty()) {
                report << "Matrix B:\n";
                for (const auto& row : b) {
                    for (double value : row) report << value << " ";
                    report << "\n";
                }
            }
            if (!result.empty()) {
                report << "Result matrix:\n";
                for (const auto& row : result) {
                    for (double value : row) report << value << " ";
                    report << "\n";
                }
            }
            lastResult = report.str();
        }

    } while (choice != 0);
}
