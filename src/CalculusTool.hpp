#pragma once

class CalculusTool {
public:
    void calculusMenu();

    double evaluateCalculusFunction(int functionChoice, double x);

    double numericalDerivative(int functionChoice, double x);

    double trapeziumRule(int functionChoice, double a, double b, int intervals);

    double eulerApproximation(double x0, double y0, double h, int steps);
};