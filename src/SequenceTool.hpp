#pragma once

#include <vector>
#include <string>

using namespace std;
// I am grouping sequence generation, summation, and console interaction in this class.
class SequenceTool {
public:
    // I am declaring the menu that collects the user's sequence parameters.
    void sequenceMenu(std::string& lastResult);
// I am declaring generators for arithmetic, geometric, and first-order recurrence sequences.
vector<double> arithmeticSequence(double firstTerm, double difference, int terms);
vector<double> geometricSequence(double firstTerm, double ratio, int terms);
vector<double> recurrenceSequence(double start, double multiplier, double constant, int terms);

    // I am declaring a method that totals the terms without modifying the supplied sequence.
    double sumSequence(const vector<double>& sequence);


    private:
    // I am keeping the display helper private because it is used within the sequence menu.
    void printSequence(const vector<double>& sequence);
};
