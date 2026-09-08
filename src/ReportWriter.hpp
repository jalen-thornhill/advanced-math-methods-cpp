#pragma once

#include <string>

using namespace std;

// I am keeping text-file export separate from the mathematical calculations.
class ReportWriter {
public:
    // I am declaring an export method that receives the file path and report text.
    bool exportReport(const string& filename, const string& content);
};
