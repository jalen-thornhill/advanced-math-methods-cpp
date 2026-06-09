#include "SequenceTool.hpp"
#include <iostream>


vector<double> SequenceTool::arithmeticSequence(double firstTerm, double difference, int terms) {
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
    double total = 0;

    for (double value : sequence) {
        total += value;
    }

    return total;
}

vector<double> SequenceTool::recurrenceSequence(double start, double multiplier, double constant, int terms) {
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
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i];

        if (i < sequence.size() - 1) {
            cout << ", ";
        }
    }

    cout << "\n";
}

void SequenceTool::sequenceMenu() {
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
                double total = sumSequence(sequence);

                cout << "Sequence: ";
                printSequence(sequence);

                cout << "Partial sum: " << total << "\n";

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

    } while (choice != 0);
}