#include "SequenceTool.hpp"
#include <iostream>
#include <sstream>


vector<double> SequenceTool::arithmeticSequence(double firstTerm, double difference, int terms) {
    // I am generating equally spaced terms using the first term plus its zero-based position times the difference.
    // I am returning an empty sequence when the requested term count is not positive.
    vector<double> sequence;

    if (terms <= 0) {
        return sequence;
    }

    for (int i = 0; i < terms; i++) {
        double currentTerm = firstTerm + (i * difference);
        sequence.push_back(currentTerm);
    }

    return sequence;
}

vector<double> SequenceTool::geometricSequence(double firstTerm, double ratio, int terms) {
    // I am multiplying each term by the common ratio to obtain the next term.
    // I am returning an empty sequence when the requested term count is not positive.
    vector<double> sequence;

    if (terms <= 0) {
        return sequence;
    }

    double currentTerm = firstTerm;

    for (int i = 0; i < terms; i++) {
        sequence.push_back(currentTerm);
        currentTerm *= ratio;
    }

    return sequence;
}


double SequenceTool::sumSequence(const vector<double>& sequence) {
    // I am adding the supplied terms to calculate their partial sum without changing the sequence.
    double total = 0;

    for (double value : sequence) {
        total += value;
    }

    return total;
}

vector<double> SequenceTool::recurrenceSequence(double start, double multiplier, double constant, int terms) {
    // I am starting with the supplied value and applying next = multiplier * current + constant.
    // I am returning an empty sequence when the requested term count is not positive.
    vector<double> sequence;

    if (terms <= 0) {
        return sequence;
    }

    double currentTerm = start;

    for (int i = 0; i < terms; i++) {
        sequence.push_back(currentTerm);
        currentTerm = (multiplier * currentTerm) + constant;
    }

    return sequence;
}

void SequenceTool::printSequence(const vector<double>& sequence) {
    // I am separating displayed terms with commas while leaving no trailing comma.
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i];

        if (i < sequence.size() - 1) {
            cout << ", ";
        }
    }

    cout << "\n";
}

void SequenceTool::sequenceMenu(string& lastResult) {
    // I am repeating the sequence menu until the user chooses to return to the main menu.
    int choice;

    do {
        cout << "\nSequence and Series Tool\n";
        cout << "1. Arithmetic Sequence\n";
        cout << "2. Geometric Sequence\n";
        cout << "3. Partial Sum\n";
        cout << "4. Recurrence Sequence\n";
        cout << "0. Back\n";
        cout << "Enter choice: ";
        cin >> choice;

        // I am collecting only the calculation details for the next report.
        ostringstream report;

        // I am reading the parameters for the chosen sequence and displaying the generated terms.
        switch (choice) {
            case 1: {
                double firstTerm;
                double difference;
                int terms;

                cout << "Enter first term: ";
                cin >> firstTerm;

                cout << "Enter difference: ";
                cin >> difference;

                cout << "Enter number of terms: ";
                cin >> terms;

                vector<double> sequence = arithmeticSequence(firstTerm, difference, terms);

                report << "Arithmetic sequence: first=" << firstTerm << ", difference=" << difference << ", terms=" << terms << "\n";
                for (double value : sequence) report << value << " ";
                report << "\n";
                cout << "Arithmetic sequence: ";
                printSequence(sequence);

                break;
            }

            case 2: {
                double firstTerm;
                double ratio;
                int terms;

                cout << "Enter first term: ";
                cin >> firstTerm;

                cout << "Enter ratio: ";
                cin >> ratio;

                cout << "Enter number of terms: ";
                cin >> terms;

                vector<double> sequence = geometricSequence(firstTerm, ratio, terms);

                report << "Geometric sequence: first=" << firstTerm << ", ratio=" << ratio << ", terms=" << terms << "\n";
                for (double value : sequence) report << value << " ";
                report << "\n";
                cout << "Geometric sequence: ";
                printSequence(sequence);

                break;
            }

            case 3: {
                double firstTerm;
                double difference;
                int terms;

                cout << "Enter first term: ";
                cin >> firstTerm;

                cout << "Enter difference: ";
                cin >> difference;

                cout << "Enter number of terms: ";
                cin >> terms;

                vector<double> sequence = arithmeticSequence(firstTerm, difference, terms);
                // I am calculating the partial sum of the arithmetic sequence just generated.
                double total = sumSequence(sequence);

                cout << "Sequence: ";
                printSequence(sequence);

                cout << "Partial sum: " << total << "\n";
                report << "Arithmetic partial sum: first=" << firstTerm << ", difference=" << difference << ", terms=" << terms << "\nResult: " << total << "\n";

                break;
            }

            case 4: {
                double start;
                double multiplier;
                double constant;
                int terms;

                cout << "Enter starting term: ";
                cin >> start;

                cout << "Enter multiplier: ";
                cin >> multiplier;

                cout << "Enter constant: ";
                cin >> constant;

                cout << "Enter number of terms: ";
                cin >> terms;

                vector<double> sequence = recurrenceSequence(start, multiplier, constant, terms);

                report << "Recurrence sequence: start=" << start << ", multiplier=" << multiplier << ", constant=" << constant << ", terms=" << terms << "\n";
                for (double value : sequence) report << value << " ";
                report << "\n";
                cout << "Recurrence sequence: ";
                printSequence(sequence);

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
