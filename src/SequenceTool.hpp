#pragma once

#include <vector>

using namespace std;
class SequenceTool {
public:

vector<double> arithmeticSequence(double firstTerm, double difference, int terms);
vector<double> geometricSequence(double firstTerm, double ratio, int terms);
vector<double> recurrenceSequence(double start, double multiplier, double constant, int terms);

    double sumSequence(const vector<double>& sequence);
};