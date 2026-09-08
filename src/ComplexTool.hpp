#pragma once
#include <string>

// I am grouping a complex number's components and operations in this class.
class ComplexNumber {
private:
    // I am keeping the real and imaginary components private.
    double real;
    double imag;

public:
    // I am declaring how a complex number is constructed from its two components.
    ComplexNumber(double real, double imag);

    // I am declaring read-only access to the components, magnitude, and angle.
    double getReal() const;
    double getImag() const;
    double modulus() const;
    double argumentRadians() const;

    // I am declaring the polar display and interactive menu.
    void printPolarForm() const;
    void complexMenu(std::string& lastResult);


    // I am declaring arithmetic methods that return a new number from two supplied operands.
    ComplexNumber add(const ComplexNumber& a, const ComplexNumber& b);
    ComplexNumber subtract(const ComplexNumber& a, const ComplexNumber& b);
    ComplexNumber multiply(const ComplexNumber& a, const ComplexNumber& b);
    ComplexNumber divide(const ComplexNumber& a, const ComplexNumber& b);
    // I am declaring a method that returns the stored number's conjugate without changing it.
    ComplexNumber conjugate() const;
};
