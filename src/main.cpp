#include <iostream>
#include "ComplexTool.hpp"
#include "MatrixTool.hpp"
#include "RootTool.hpp"
#include "SequenceTool.hpp"
#include "ReportWriter.hpp"

using namespace std;

int main() {
    int choice;
    string lastResult = "";

    do {
        cout << "\nAdvanced Math Methods C++ Toolkit\n";
        cout << "1. Complex Number Tool\n";
        cout << "2. Matrix Tool\n";
        cout << "3. Root Approximation Tool\n";
        cout << "4. Sequence and Series Tool\n";
        cout << "5. Counting and Probability Tool\n";
        cout << "6. Numerical Calculus Tool\n";
        cout << "7. Export Session Report\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                ComplexNumber complexTool(0, 0); // Create a dummy complex number to access the menu
                complexTool.complexMenu();
                break;
            }

            case 2:
                MatrixTool matrixTool;
                matrixTool.MatrixMenu();
                break;

            case 3:
                    RootTool rootTool;
                    rootTool.rootMenu();
                    break;

            case 4:
                SequenceTool sequenceTool;
                sequenceTool.sequenceMenu();
                break;

            case 5:
                cout << "Counting and Probability Tool coming soon.\n";
                break;

            case 6:
                cout << "Numerical Calculus Tool coming soon.\n";
                break;

            case 7:
                ReportWriter reportWriter;

    if (lastResult == "") {
        cout << "No result to export yet.\n";
        break;
    }

    bool exported = reportWriter.exportReport("reports/session_report.txt", lastResult);

    if (exported) {
        cout << "Report exported to reports/session_report.txt\n";
    } else {
        cout << "Error exporting report. Make sure the reports folder exists.\n";
    }
                break;

            case 0:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != 0);

    return 0;
}