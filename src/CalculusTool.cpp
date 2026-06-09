#include "CalculusTool.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double CalculusTool::evaluateCalculusFunction(int functionChoice, double x) {
    switch (functionChoice) {
        case 1:
            return x * x;

        case 2:
            return x * x * x;

        case 3:
            return (2 * x) + 1;

        case 4:
            return sin(x);

        case 5:
            return cos(x);

        default:
            return 0;
    }
}

double CalculusTool::numericalDerivative(int functionChoice, double x) {
    const double h = 1e-5;

    double fxPlusH = evaluateCalculusFunction(functionChoice, x + h);
    double fxMinusH = evaluateCalculusFunction(functionChoice, x - h);

    return (fxPlusH - fxMinusH) / (2 * h);
}

double CalculusTool::trapeziumRule(int functionChoice, double a, double b, int intervals) {
    if (intervals <= 0) {
        return 0;
    }

    double h = (b - a) / intervals;

    double total = 0.5 * evaluateCalculusFunction(functionChoice, a);
    total += 0.5 * evaluateCalculusFunction(functionChoice, b);

    for (int i = 1; i < intervals; i++) {
        double x = a + (i * h);
        total += evaluateCalculusFunction(functionChoice, x);
    }

    return total * h;
}

double CalculusTool::eulerApproximation(double x0, double y0, double h, int steps) {
    if (steps <= 0) {
        return y0;
    }

    double currentX = x0;
    double currentY = y0;

    for (int i = 0; i < steps; i++) {
        double derivative = currentX + currentY;

        currentY = currentY + (h * derivative);
        currentX = currentX + h;
    }

    return currentY;
}

void CalculusTool::calculusMenu() {
    int choice;

    do {
        cout << "\nNumerical Calculus Tool\n";
        cout << "1. Evaluate Function\n";
        cout << "2. Numerical Derivative\n";
        cout << "3. Trapezium Rule Integration\n";
        cout << "4. Euler Approximation\n";
        cout << "0. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int functionChoice;
                double x;

                cout << "\nPreset Functions\n";
                cout << "1. f(x) = x^2\n";
                cout << "2. f(x) = x^3\n";
                cout << "3. f(x) = 2x + 1\n";
                cout << "4. f(x) = sin(x)\n";
                cout << "5. f(x) = cos(x)\n";

                cout << "Enter function choice: ";
                cin >> functionChoice;

                cout << "Enter x: ";
                cin >> x;

                double result = evaluateCalculusFunction(functionChoice, x);

                cout << "f(" << x << ") = " << result << "\n";
                break;
            }

            case 2: {
                int functionChoice;
                double x;

                cout << "\nPreset Functions\n";
                cout << "1. f(x) = x^2\n";
                cout << "2. f(x) = x^3\n";
                cout << "3. f(x) = 2x + 1\n";
                cout << "4. f(x) = sin(x)\n";
                cout << "5. f(x) = cos(x)\n";

                cout << "Enter function choice: ";
                cin >> functionChoice;

                cout << "Enter x: ";
                cin >> x;

                double result = numericalDerivative(functionChoice, x);

                cout << "Approximate derivative: " << result << "\n";
                break;
            }

            case 3: {
                int functionChoice;
                double a;
                double b;
                int intervals;

                cout << "\nPreset Functions\n";
                cout << "1. f(x) = x^2\n";
                cout << "2. f(x) = x^3\n";
                cout << "3. f(x) = 2x + 1\n";
                cout << "4. f(x) = sin(x)\n";
                cout << "5. f(x) = cos(x)\n";

                cout << "Enter function choice: ";
                cin >> functionChoice;

                cout << "Enter a: ";
                cin >> a;

                cout << "Enter b: ";
                cin >> b;

                cout << "Enter number of intervals: ";
                cin >> intervals;

                if (intervals <= 0) {
                    cout << "Intervals must be greater than 0.\n";
                    break;
                }

                double result = trapeziumRule(functionChoice, a, b, intervals);

                cout << "Approximate integral: " << result << "\n";
                break;
            }

            case 4: {
                double x0;
                double y0;
                double h;
                int steps;

                cout << "Using differential equation: dy/dx = x + y\n";

                cout << "Enter starting x: ";
                cin >> x0;

                cout << "Enter starting y: ";
                cin >> y0;

                cout << "Enter step size h: ";
                cin >> h;

                cout << "Enter number of steps: ";
                cin >> steps;

                if (steps < 0) {
                    cout << "Steps cannot be negative.\n";
                    break;
                }

                double result = eulerApproximation(x0, y0, h, steps);

                cout << "Euler approximation: " << result << "\n";
                break;
            }

            case 0:
                cout << "Returning to main menu...\n";
                break;

            default:
                cout << "Invalid option. Try again.\n";
                break;
        }

    } while (choice != 0);
}