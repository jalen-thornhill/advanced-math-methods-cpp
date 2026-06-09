#include "RootTool.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>    

using namespace std;

double RootTool::evaluateFunction(int choice, double x){
    switch (choice){
        case 1:
            return pow(x,2) - 2; // Example: f(x) = x^2 - 2
            break;
        case 2:
            return pow(x,3) -  x -2; // Example: f(x) = x^3 - x - 2
            break;
        case 3:
            return cos(x) - x; // Example: f(x) = cos(x) - x
            break;
        case 4:
            return exp(x) - 3; // Example: f(x) = e^x - 3
            break;
        default:
            return 0.0; // Default case
    }
}

double RootTool::evaluateDerivative(int choice, double x) {
    switch (choice) {
        case 1:
            return 2 * x; // 2x
            break;

        case 2:
            return 3 * pow(x, 2) - 1; // 3x^2 - 1
            break;

        case 3:
            return -sin(x) - 1; // -sin(x) - 1
            break;

        case 4:
            return exp(x) - 3; // e^x - 3
            break;

        default:
        cerr << "Invalid choice for derivative evaluation." << endl;
        return 0.0;
            break;
    }
}

double RootTool::linearInterpolation(int functionChoice, double a, double b){

    double fa = evaluateFunction(functionChoice, a);
     double fb = evaluateFunction(functionChoice, b);


     double epsilon = 1e-9;

     if (abs(fb -fa) < epsilon) return a;


     return a - fa * (b-a) / (fb  - fa);
}

double RootTool::newtonRaphson(int functionChoice, double startX, int iterations) {
    const double EPSILON = 1e-9;

    double currentX = startX;

    cout << fixed << setprecision(4);

    cout << "Iteration   x           f(x)        f'(x)\n";

    for (int i = 1; i <= iterations; i++) {
        double fx = evaluateFunction(functionChoice, currentX);
        double derivative = evaluateDerivative(functionChoice, currentX);

        if (abs(derivative) < EPSILON) {
            cout << "Derivative too close to zero. Stopping early.\n";
            return currentX;
        }

        cout << left << setw(12) << i
             << setw(12) << currentX
             << setw(12) << fx
             << setw(12) << derivative
             << "\n";

        double nextX = currentX - fx / derivative;
        currentX = nextX;
    }

    return currentX;
}

void RootTool::rootMenu() {
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

        switch (choice) {
            case 1:
                cout << "\nPreset Functions\n";
                cout << "1. f(x) = x^2 - 2\n";
                cout << "2. f(x) = x^3 - x - 2\n";
                cout << "3. f(x) = x^2 + x - 6\n";
                break;

            case 2: {
                int functionChoice;
                double x;

                cout << "Enter function choice: ";
                cin >> functionChoice;

                cout << "Enter x: ";
                cin >> x;

                double result = evaluateFunction(functionChoice, x);

                cout << "f(" << x << ") = " << result << "\n";
                break;
            }

            case 3: {
                int functionChoice;
                double x;

                cout << "Enter function choice: ";
                cin >> functionChoice;

                cout << "Enter x: ";
                cin >> x;

                double result = evaluateDerivative(functionChoice, x);

                cout << "f'(" << x << ") = " << result << "\n";
                break;
            }

            case 4: {
                int functionChoice;
                double a;
                double b;

                cout << "Enter function choice: ";
                cin >> functionChoice;

                cout << "Enter a: ";
                cin >> a;

                cout << "Enter b: ";
                cin >> b;

                double approximation = linearInterpolation(functionChoice, a, b);

                cout << "Root approximation: " << approximation << "\n";
                break;
            }

            case 5: {
                int functionChoice;
                double startX;
                int iterations;

                cout << "Enter function choice: ";
                cin >> functionChoice;

                cout << "Enter starting x: ";
                cin >> startX;

                cout << "Enter number of iterations: ";
                cin >> iterations;

                if (iterations < 0) {
                    cout << "Iterations cannot be negative.\n";
                    break;
                }

                double approximation = newtonRaphson(functionChoice, startX, iterations);

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

    } while (choice != 0);
}