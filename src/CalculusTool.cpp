#include "CalculusTool.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

double CalculusTool::evaluateCalculusFunction(int functionChoice, double x) {
    // I am evaluating the selected formula, using radians for sine and cosine.
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
            // I am returning zero as the current fallback for an unsupported formula choice.
            return 0;
    }
}

double CalculusTool::numericalDerivative(int functionChoice, double x) {
    // I am sampling equally far on either side of x with a step of 0.00001.
    const double h = 1e-5;

    double fxPlusH = evaluateCalculusFunction(functionChoice, x + h);
    double fxMinusH = evaluateCalculusFunction(functionChoice, x - h);

    // I am estimating the slope by dividing the change in function values by the distance between samples.
    return (fxPlusH - fxMinusH) / (2 * h);
}

double CalculusTool::trapeziumRule(int functionChoice, double a, double b, int intervals) {
    // I am rejecting a nonpositive interval count by returning zero before dividing.
    if (intervals <= 0) {
        return 0;
    }

    // I am dividing the integration range into equally sized intervals.
    double h = (b - a) / intervals;

    // I am giving the endpoints half weight because each belongs to only one trapezium.
    double total = 0.5 * evaluateCalculusFunction(functionChoice, a);
    total += 0.5 * evaluateCalculusFunction(functionChoice, b);

    // I am adding the interior values, which are shared by neighbouring trapeziums.
    for (int i = 1; i < intervals; i++) {
        double x = a + (i * h);
        total += evaluateCalculusFunction(functionChoice, x);
    }

    // I am multiplying the weighted sum by the interval width to estimate the integral.
    return total * h;
}

double CalculusTool::eulerApproximation(double x0, double y0, double h, int steps) {
    // I am returning the starting value when no forward iterations are requested.
    if (steps <= 0) {
        return y0;
    }

    double currentX = x0;
    double currentY = y0;

    // I am using the current slope from dy/dx = x + y to advance y and then x by one step.
    for (int i = 0; i < steps; i++) {
        double derivative = currentX + currentY;

        currentY = currentY + (h * derivative);
        currentX = currentX + h;
    }

    return currentY;
}

void CalculusTool::calculusMenu(string& lastResult) {
    // I am repeating the calculus menu until the user chooses to return.
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

        // I am collecting only the calculation details for the next report.
        ostringstream report;

        // I am collecting the formula and numeric inputs needed for the selected calculation.
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
                if (functionChoice < 1 || functionChoice > 5) {
                    cout << "Invalid function choice.\n";
                    break;
                }

                cout << "Enter x: ";
                cin >> x;

                double result = evaluateCalculusFunction(functionChoice, x);
                report << "Function evaluation: choice=" << functionChoice << ", x=" << x << "\nResult: " << result << "\n";

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
                if (functionChoice < 1 || functionChoice > 5) {
                    cout << "Invalid function choice.\n";
                    break;
                }

                cout << "Enter x: ";
                cin >> x;

                double result = numericalDerivative(functionChoice, x);
                report << "Numerical derivative: choice=" << functionChoice << ", x=" << x << "\nResult: " << result << "\n";

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
                if (functionChoice < 1 || functionChoice > 5) {
                    cout << "Invalid function choice.\n";
                    break;
                }

                cout << "Enter a: ";
                cin >> a;

                cout << "Enter b: ";
                cin >> b;

                cout << "Enter number of intervals: ";
                cin >> intervals;

                if (intervals <= 0) {
                    // I am asking for a positive interval count before calling the integration method.
                    cout << "Intervals must be greater than 0.\n";
                    break;
                }

                double result = trapeziumRule(functionChoice, a, b, intervals);
                report << "Trapezium integral: choice=" << functionChoice << ", a=" << a << ", b=" << b << ", intervals=" << intervals << "\nResult: " << result << "\n";

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
                    // I am rejecting negative step counts while allowing zero steps to return the initial value.
                    cout << "Steps cannot be negative.\n";
                    break;
                }

                double result = eulerApproximation(x0, y0, h, steps);
                report << "Euler approximation for dy/dx = x + y: x0=" << x0 << ", y0=" << y0 << ", h=" << h << ", steps=" << steps << "\nResult: " << result << "\n";

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

        // I am replacing the saved result only after a calculation produces report text.
        if (!report.str().empty()) {
            lastResult = report.str();
        }

    } while (choice != 0);
}
