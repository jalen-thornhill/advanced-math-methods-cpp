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

void ComplexNumber::printPolarForm() const {
    double r = modulus();
    double theta = argumentRadians();
    cout << "Polar form: " << r << " * (cos(" << theta << ") + i*sin(" << theta << "))" << endl;
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
    double realPart = (a.real * b.real + a.imag * b.imag) / denominator;
    double imagPart = (a.imag * b.real - a.real * b.imag) / denominator;
    return ComplexNumber(realPart, imagPart);
}

ComplexNumber ComplexNumber::conjugate() const {
    return ComplexNumber(real, -imag);
}

