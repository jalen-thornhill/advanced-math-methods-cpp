#include "RootTool.hpp"
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>    

using namespace std;

double RootTool::evaluateFunction(int choice, double x){
    // I am selecting a preset formula and evaluating it at the supplied value of x.
    switch (choice){
        case 1:
            return pow(x,2) - 2;
            break;
        case 2:
            return pow(x,3) -  x -2;
            break;
        case 3:
            return cos(x) - x;
            break;
        case 4:
            return exp(x) - 3;
            break;
        default:
            // I am returning zero as the current fallback for an unsupported function choice.
            return 0.0;
    }
}

double RootTool::evaluateDerivative(int choice, double x) {
    // I am selecting the stored derivative formula used by the root approximation method.
    switch (choice) {
        case 1:
            return 2 * x;
            break;

        case 2:
            return 3 * pow(x, 2) - 1;
            break;

        case 3:
            return -sin(x) - 1;
            break;

        case 4:
            // I am differentiating exp(x) - 3; the constant contributes zero.
            return exp(x);
            break;

        default:
        cerr << "Invalid choice for derivative evaluation." << endl;
        return 0.0;
            break;
    }
}

double RootTool::linearInterpolation(int functionChoice, double a, double b){
    // I am evaluating the two endpoints to find where the straight line between them crosses the x-axis.

    double fa = evaluateFunction(functionChoice, a);
     double fb = evaluateFunction(functionChoice, b);


     double epsilon = 1e-9;

     // I am avoiding division by a nearly zero difference by returning the first endpoint as a fallback.
     if (abs(fb -fa) < epsilon) return a;


     return a - fa * (b-a) / (fb  - fa);
}

double RootTool::newtonRaphson(int functionChoice, double startX, int iterations) {
    // I am starting from the supplied estimate and applying a fixed number of Newton updates.
    const double EPSILON = 1e-9;

    double currentX = startX;

    cout << fixed << setprecision(4);

    cout << "Iteration   x           f(x)        f'(x)\n";

    for (int i = 1; i <= iterations; i++) {
        double fx = evaluateFunction(functionChoice, currentX);
        double derivative = evaluateDerivative(functionChoice, currentX);

        if (abs(derivative) < EPSILON) {
            // I am stopping early when the derivative is too small to use safely as a divisor.
            cout << "Derivative too close to zero. Stopping early.\n";
            return currentX;
        }

        // I am displaying the current estimate, function value, and derivative before each update.
        cout << left << setw(12) << i
             << setw(12) << currentX
             << setw(12) << fx
             << setw(12) << derivative
             << "\n";

        // I am following the tangent to its x-axis intercept using x - f(x) / f'(x).
        double nextX = currentX - fx / derivative;
        currentX = nextX;
    }

    return currentX;
}

void RootTool::rootMenu(string& lastResult) {
    // I am repeating the root menu until the user chooses to return to the main menu.
    int choice;

    do {
        cout << "\nRoot Approximation Tool\n";
        cout << "1. Show Preset Functions\n";
        cout << "2. Evaluate f(x)\n";
        cout << "3. Evaluate f'(x)\n";
        cout << "4. Linear Interpolation\n";
        cout << "5. Newton-Raphson\n";
        cout << "0. Return to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;

        // I am collecting only the calculation details for the next report.
        ostringstream report;

        // I am collecting the inputs needed for the selected evaluation or approximation.
        switch (choice) {
            case 1:
                cout << "\nPreset Functions\n";
                cout << "1. f(x) = x^2 - 2\n";
                cout << "2. f(x) = x^3 - x - 2\n";
                cout << "3. f(x) = cos(x) - x\n";
                cout << "4. f(x) = e^x - 3\n";
                break;

            case 2: {
                int functionChoice;
                double x;

                cout << "Enter function choice: ";
                cin >> functionChoice;
                if (functionChoice < 1 || functionChoice > 4) {
                    cout << "Invalid function choice.\n";
                    break;
                }

                cout << "Enter x: ";
                cin >> x;

                double result = evaluateFunction(functionChoice, x);
                report << "Function evaluation\n" << "Function choice: " << functionChoice << ", x: " << x
                       << "\nResult: " << result << "\n";

                cout << "f(" << x << ") = " << result << "\n";
                break;
            }

            case 3: {
                int functionChoice;
                double x;

                cout << "Enter function choice: ";
                cin >> functionChoice;
                if (functionChoice < 1 || functionChoice > 4) {
                    cout << "Invalid function choice.\n";
                    break;
                }

                cout << "Enter x: ";
                cin >> x;

                double result = evaluateDerivative(functionChoice, x);
                report << "Derivative evaluation\n" << "Function choice: " << functionChoice << ", x: " << x
                       << "\nResult: " << result << "\n";

                cout << "f'(" << x << ") = " << result << "\n";
                break;
            }

            case 4: {
                int functionChoice;
                double a;
                double b;

                cout << "Enter function choice: ";
                cin >> functionChoice;
                if (functionChoice < 1 || functionChoice > 4) {
                    cout << "Invalid function choice.\n";
                    break;
                }

                cout << "Enter a: ";
                cin >> a;

                cout << "Enter b: ";
                cin >> b;

                double approximation = linearInterpolation(functionChoice, a, b);
                report << "Linear interpolation\n" << "Function choice: " << functionChoice << ", a: " << a << ", b: " << b
                       << "\nResult: " << approximation << "\n";

                cout << "Root approximation: " << approximation << "\n";
                break;
            }

            case 5: {
                int functionChoice;
                double startX;
                int iterations;

                cout << "Enter function choice: ";
                cin >> functionChoice;
                if (functionChoice < 1 || functionChoice > 4) {
                    cout << "Invalid function choice.\n";
                    break;
                }

                cout << "Enter starting x: ";
                cin >> startX;

                cout << "Enter number of iterations: ";
                cin >> iterations;

                if (iterations < 0) {
                    // I am rejecting a negative iteration count before starting the approximation.
                    cout << "Iterations cannot be negative.\n";
                    break;
                }

                double approximation = newtonRaphson(functionChoice, startX, iterations);
                report << "Newton-Raphson\n" << "Function choice: " << functionChoice << ", start: " << startX << ", iterations: " << iterations
                       << "\nResult: " << approximation << "\n";

                cout << "Final approximation: " << approximation << "\n";
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
