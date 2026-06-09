#include "SequenceTool.hpp"\

#include "SequenceTool.h"

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