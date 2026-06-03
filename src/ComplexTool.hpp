#pragma once

class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber(double real, double imag);

    double getReal() const;
    double getImag() const;
    double modulus() const;
    double argumentRadians() const;

    void printPolarForm() const;



    ComplexNumber add(const ComplexNumber& a, const ComplexNumber& b);
    ComplexNumber subtract(const ComplexNumber& a, const ComplexNumber& b);
    ComplexNumber multiply(const ComplexNumber& a, const ComplexNumber& b);
    ComplexNumber divide(const ComplexNumber& a, const ComplexNumber& b);
    ComplexNumber conjugate() const;
};