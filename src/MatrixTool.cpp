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