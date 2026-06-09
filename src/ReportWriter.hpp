#pragma once

#include <string>

using namespace std;

class ReportWriter {
public:
    bool exportReport(const string& filename, const string& content);
};