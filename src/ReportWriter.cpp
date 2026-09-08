#include "ReportWriter.hpp"
#include <fstream>

using namespace std;

bool ReportWriter::exportReport(const string& filename, const string& content) {
    // I am opening the requested file for writing, replacing its contents if it already exists.
    ofstream file(filename);

    if (!file.is_open()) {
        // I am reporting failure when the output file cannot be opened.
        return false;
    }

    // I am writing the supplied text and closing the output file.
    file << content;

    file.close();

    // I am checking the stream after closing so that write failures are reported too.
    return !file.fail();
}
