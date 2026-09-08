#pragma once
#include <string>

// I am grouping formula evaluation and numerical calculus methods in this class.
class CalculusTool {
public:
    // I am declaring the menu that collects inputs and displays approximations.
    void calculusMenu(std::string& lastResult);

    // I am declaring evaluation of one of the five preset formulas.
    double evaluateCalculusFunction(int functionChoice, double x);

    // I am declaring a central-difference derivative estimate at a supplied point.
    double numericalDerivative(int functionChoice, double x);

    // I am declaring a definite-integral estimate using equally spaced trapeziums.
    double trapeziumRule(int functionChoice, double a, double b, int intervals);

    // I am declaring Euler steps for dy/dx = x + y from the supplied initial values.
    double eulerApproximation(double x0, double y0, double h, int steps);
};
