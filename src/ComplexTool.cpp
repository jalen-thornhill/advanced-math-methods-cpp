#include "ComplexTool.hpp"
#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

// I am storing the real and imaginary parts when creating a complex number.
ComplexNumber::ComplexNumber(double r, double i) : real(r), imag(i) {}

// I am providing access to each component without changing the stored number.
double ComplexNumber::getReal() const {
    return real;
}

double ComplexNumber::getImag() const {
    return imag;
}

double ComplexNumber::modulus() const {
    // I am calculating the distance from the origin using the two components.
    return sqrt(real * real + imag * imag);
}

double ComplexNumber::argumentRadians() const {
    // I am finding the angle in radians with atan2 so that the quadrant is taken into account.
    return atan2(imag, real);
}

ComplexNumber ComplexNumber::conjugate() const {
    // I am reversing the imaginary part's sign to form the complex conjugate.
    return ComplexNumber(real, -imag);
}

void ComplexNumber::printPolarForm() const {
    // I am combining the magnitude and angle to display the number in polar form.
    double r = modulus();
    double theta = argumentRadians();

    cout << r << "(cos(" << theta << ") + i sin(" << theta << "))\n";
}

ComplexNumber ComplexNumber::add(const ComplexNumber& a, const ComplexNumber& b) {
    // I am adding the real parts and imaginary parts separately.
    return ComplexNumber(a.real + b.real, a.imag + b.imag);
}

ComplexNumber ComplexNumber::subtract(const ComplexNumber& a, const ComplexNumber& b) {
    // I am subtracting the second number's components from the first number's components.
    return ComplexNumber(a.real - b.real, a.imag - b.imag);
}

ComplexNumber ComplexNumber::multiply(const ComplexNumber& a, const ComplexNumber& b) {
    // I am expanding the product and using i squared equals -1 to separate its components.
    double realPart = a.real * b.real - a.imag * b.imag;
    double imagPart = a.real * b.imag + a.imag * b.real;

    return ComplexNumber(realPart, imagPart);
}

ComplexNumber ComplexNumber::divide(const ComplexNumber& a, const ComplexNumber& b) {
    // I am using the divisor's conjugate to obtain a real denominator equal to its squared magnitude.
    double denominator = b.real * b.real + b.imag * b.imag;

    if (denominator == 0) {
        // I am reporting division by zero and returning a zero-valued result as the current error fallback.
        cout << "Error: Cannot divide by 0 + 0i.\n";
        return ComplexNumber(0, 0);
    }

    double realPart = (a.real * b.real + a.imag * b.imag) / denominator;
    double imagPart = (a.imag * b.real - a.real * b.imag) / denominator;

    return ComplexNumber(realPart, imagPart);
}

static ComplexNumber inputComplexNumber() {
    // I am reading the two components separately to construct the user's complex number.
    double real;
    double imag;

    cout << "Enter real part: ";
    cin >> real;

    cout << "Enter imaginary part: ";
    cin >> imag;

    return ComplexNumber(real, imag);
}

static void printComplexNumber(const ComplexNumber& number) {
    // I am selecting a plus or minus sign so that the imaginary component is easy to read.
    cout << number.getReal();

    if (number.getImag() >= 0) {
        cout << " + " << number.getImag() << "i";
    } else {
        cout << " - " << -number.getImag() << "i";
    }

    cout << "\n";
}

void ComplexNumber::complexMenu(string& lastResult) {
    // I am repeating this menu until the user chooses to return to the main menu.
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

        // I am collecting the calculation details separately from the menu prompts.
        ostringstream report;

        // I am collecting the required numbers, calling the selected operation, and displaying its result.
        switch (choice) {
            case 1: {
                ComplexNumber a = inputComplexNumber();
                ComplexNumber b = inputComplexNumber();

                ComplexNumber result = add(a, b);
                report << "Complex Addition\n"
                       << "A (real, imaginary): " << a.getReal() << ", " << a.getImag() << "\n"
                       << "B (real, imaginary): " << b.getReal() << ", " << b.getImag() << "\n"
                       << "Result (real, imaginary): " << result.getReal() << ", " << result.getImag() << "\n";

                cout << "Result: ";
                printComplexNumber(result);
                break;
            }

            case 2: {
                ComplexNumber a = inputComplexNumber();
                ComplexNumber b = inputComplexNumber();

                ComplexNumber result = subtract(a, b);
                report << "Complex Subtraction\n"
                       << "A (real, imaginary): " << a.getReal() << ", " << a.getImag() << "\n"
                       << "B (real, imaginary): " << b.getReal() << ", " << b.getImag() << "\n"
                       << "Result (real, imaginary): " << result.getReal() << ", " << result.getImag() << "\n";

                cout << "Result: ";
                printComplexNumber(result);
                break;
            }

            case 3: {
                ComplexNumber a = inputComplexNumber();
                ComplexNumber b = inputComplexNumber();

                ComplexNumber result = multiply(a, b);
                report << "Complex Multiplication\n"
                       << "A (real, imaginary): " << a.getReal() << ", " << a.getImag() << "\n"
                       << "B (real, imaginary): " << b.getReal() << ", " << b.getImag() << "\n"
                       << "Result (real, imaginary): " << result.getReal() << ", " << result.getImag() << "\n";

                cout << "Result: ";
                printComplexNumber(result);
                break;
            }

            case 4: {
                ComplexNumber a = inputComplexNumber();
                ComplexNumber b = inputComplexNumber();

                if (b.getReal() == 0 && b.getImag() == 0) {
                    cout << "Error: Cannot divide by 0 + 0i.\n";
                    break;
                }

                ComplexNumber result = divide(a, b);
                report << "Complex Division\n"
                       << "A (real, imaginary): " << a.getReal() << ", " << a.getImag() << "\n"
                       << "B (real, imaginary): " << b.getReal() << ", " << b.getImag() << "\n"
                       << "Result (real, imaginary): " << result.getReal() << ", " << result.getImag() << "\n";

                cout << "Result: ";
                printComplexNumber(result);
                break;
            }

            case 5: {
                ComplexNumber a = inputComplexNumber();

                cout << "Modulus: " << a.modulus() << "\n";
                report << "Complex Modulus: input (real, imaginary)=" << a.getReal() << ", " << a.getImag()
                       << "\nResult: " << a.modulus() << "\n";
                break;
            }

            case 6: {
                ComplexNumber a = inputComplexNumber();

                cout << "Argument in radians: " << a.argumentRadians() << "\n";
                report << "Complex Argument in radians: input (real, imaginary)=" << a.getReal() << ", " << a.getImag()
                       << "\nResult: " << a.argumentRadians() << "\n";
                break;
            }

            case 7: {
                ComplexNumber a = inputComplexNumber();

                ComplexNumber result = a.conjugate();
                report << "Complex conjugate: input (real, imaginary)=" << a.getReal() << ", " << a.getImag()
                       << "\nResult (real, imaginary): " << result.getReal() << ", " << result.getImag() << "\n";

                cout << "Conjugate: ";
                printComplexNumber(result);
                break;
            }

            case 8: {
                ComplexNumber a = inputComplexNumber();

                cout << "Polar form: ";
                a.printPolarForm();
                report << "Complex polar form: input (real, imaginary)=" << a.getReal() << ", " << a.getImag()
                       << "\nMagnitude: " << a.modulus() << "\nAngle in radians: " << a.argumentRadians() << "\n";
                break;
            }

            case 0:
                cout << "Returning to main menu.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        // I am keeping the last successful calculation when the user goes back or enters an invalid choice.
        if (!report.str().empty()) {
            lastResult = report.str();
        }

    } while (choice != 0);
}
