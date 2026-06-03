#include "ComplexTool.hpp"
#include <cmath>
#include <iostream>

using namespace std;

ComplexNumber::ComplexNumber(double r, double i) : real(r), imag(i) {}

double ComplexNumber::getReal() const {
    return real;
}

double ComplexNumber::getImag() const {
    return imag;
}

double ComplexNumber::modulus() const {
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::argumentRadians() const {
    return atan2(imag, real);
}

ComplexNumber ComplexNumber::conjugate() const {
    return ComplexNumber(real, -imag);
}

void ComplexNumber::printPolarForm() const {
    double r = modulus();
    double theta = argumentRadians();

    cout << r << "(cos(" << theta << ") + i sin(" << theta << "))\n";
}

ComplexNumber ComplexNumber::add(const ComplexNumber& a, const ComplexNumber& b) {
    return ComplexNumber(a.real + b.real, a.imag + b.imag);
}

ComplexNumber ComplexNumber::subtract(const ComplexNumber& a, const ComplexNumber& b) {
    return ComplexNumber(a.real - b.real, a.imag - b.imag);
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& a, const ComplexNumber& b) {
    double realPart = a.real * b.real - a.imag * b.imag;
    double imagPart = a.real * b.imag + a.imag * b.real;

    return ComplexNumber(realPart, imagPart);
}

ComplexNumber ComplexNumber::divide(const ComplexNumber& a, const ComplexNumber& b) {
    double denominator = b.real * b.real + b.imag * b.imag;

    if (denominator == 0) {
        cout << "Error: Cannot divide by 0 + 0i.\n";
        return ComplexNumber(0, 0);
    }

    double realPart = (a.real * b.real + a.imag * b.imag) / denominator;
    double imagPart = (a.imag * b.real - a.real * b.imag) / denominator;

    return ComplexNumber(realPart, imagPart);
}

static ComplexNumber inputComplexNumber() {
    double real;
    double imag;

    cout << "Enter real part: ";
    cin >> real;

    cout << "Enter imaginary part: ";
    cin >> imag;

    return ComplexNumber(real, imag);
}

static void printComplexNumber(const ComplexNumber& number) {
    cout << number.getReal();

    if (number.getImag() >= 0) {
        cout << " + " << number.getImag() << "i";
    } else {
        cout << " - " << -number.getImag() << "i";
    }

    cout << "\n";
}

void ComplexNumber::complexMenu() {
    int choice;

    do {
        cout << "\nComplex Number Operations Menu\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Modulus\n";
        cout << "6. Argument\n";
        cout << "7. Conjugate\n";
        cout << "8. Polar form\n";
        cout << "0. Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                ComplexNumber a = inputComplexNumber();
                ComplexNumber b = inputComplexNumber();

                ComplexNumber result = add(a, b);

                cout << "Result: ";
                printComplexNumber(result);
                break;
            }

            case 2: {
                ComplexNumber a = inputComplexNumber();
                ComplexNumber b = inputComplexNumber();

                ComplexNumber result = subtract(a, b);

                cout << "Result: ";
                printComplexNumber(result);
                break;
            }

            case 3: {
                ComplexNumber a = inputComplexNumber();
                ComplexNumber b = inputComplexNumber();

                ComplexNumber result = multiply(a, b);

                cout << "Result: ";
                printComplexNumber(result);
                break;
            }

            case 4: {
                ComplexNumber a = inputComplexNumber();
                ComplexNumber b = inputComplexNumber();

                ComplexNumber result = divide(a, b);

                cout << "Result: ";
                printComplexNumber(result);
                break;
            }

            case 5: {
                ComplexNumber a = inputComplexNumber();

                cout << "Modulus: " << a.modulus() << "\n";
                break;
            }

            case 6: {
                ComplexNumber a = inputComplexNumber();

                cout << "Argument in radians: " << a.argumentRadians() << "\n";
                break;
            }

            case 7: {
                ComplexNumber a = inputComplexNumber();

                ComplexNumber result = a.conjugate();

                cout << "Conjugate: ";
                printComplexNumber(result);
                break;
            }

            case 8: {
                ComplexNumber a = inputComplexNumber();

                cout << "Polar form: ";
                a.printPolarForm();
                break;
            }

            case 0:
                cout << "Returning to main menu.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 0);
}