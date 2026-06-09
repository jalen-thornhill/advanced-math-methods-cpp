#include "ReportWriter.hpp"
#include <fstream>

using namespace std;

bool ReportWriter::exportReport(const string& filename, const string& content) {
    ofstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    file << content;

    file.close();

    return true;
}