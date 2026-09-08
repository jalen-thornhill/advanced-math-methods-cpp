#include <iostream>
#include <filesystem>
#include "CalculusTool.hpp"
#include "ComplexTool.hpp"
#include "MatrixTool.hpp"
#include "RootTool.hpp"
#include "SequenceTool.hpp"
#include "ReportWriter.hpp"

using namespace std;

// I am using the main menu to connect the separate mathematical tools.
int main() {
    int choice;
    // I am keeping the latest calculation text so that it remains available after leaving a tool.
    string lastResult = "";

    // I am repeating the menu until the user selects the exit option.
    do {
        cout << "\nAdvanced Math Methods C++ Toolkit\n";
        cout << "1. Complex Number Tool\n";
        cout << "2. Matrix Tool\n";
        cout << "3. Root Approximation Tool\n";
        cout << "4. Sequence and Series Tool\n";
        cout << "5. Counting and Probability Tool (coming soon)\n";
        cout << "6. Numerical Calculus Tool\n";
        cout << "7. Export Latest Result\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // I am opening the selected tool's menu or handling its current placeholder.
        switch (choice) {
            case 1: {
                // I am creating a zero-valued object to access the complex-number menu.
                ComplexNumber complexTool(0, 0);
                complexTool.complexMenu(lastResult);
                break;
            }

            case 2: {
                MatrixTool matrixTool;
                matrixTool.MatrixMenu(lastResult);
                break;
            }

            case 3: {
                    RootTool rootTool;
                    rootTool.rootMenu(lastResult);
                    break;
            }

            case 4: {
                SequenceTool sequenceTool;
                sequenceTool.sequenceMenu(lastResult);
                break;
            }

            case 5:
                // I am displaying a placeholder because the probability tool is not implemented.
                cout << "Counting and Probability Tool coming soon.\n";
                break;

            case 6: {
                // I am opening the existing calculus menu and sharing the result text for export.
                CalculusTool calculusTool;
                calculusTool.calculusMenu(lastResult);
                break;
            }

            case 7: {
                ReportWriter reportWriter;

    // I am checking for result text before attempting to export it.
    if (lastResult == "") {
        cout << "No result to export yet.\n";
        break;
    }

    // I am creating the report directory and checking for filesystem errors before saving.
    error_code error;
    filesystem::create_directories("reports", error);
    if (error) {
        cout << "Error creating reports folder: " << error.message() << "\n";
        break;
    }

    // I am saving the latest result and checking whether the write completed successfully.
    bool exported = reportWriter.exportReport("reports/session_report.txt", lastResult);

    if (exported) {
        cout << "Report exported to reports/session_report.txt\n";
    } else {
        cout << "Error exporting report. Check that the file is writable.\n";
    }
                break;

            }
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
