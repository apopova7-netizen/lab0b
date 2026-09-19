#include "word_count.h"
#include <algorithm>


int WriteResultsToFile(const std::string& outputFilePath, const std::list<std::pair<std::string, int>>& wordsSortedByCount, const int totalWordsCnt) {

    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open())
        return 0;

    outputFile << "Word;Frequency;Frequency(%)" << std::endl;
    for (const std::pair<std::string, int>& pair : wordsSortedByCount) {

        double percentage = static_cast<double>(pair.second) / totalWordsCnt * 100.0;
        std::string percentageStr = std::to_string(percentage);
        std::ranges::replace(percentageStr, '.', ',');
        outputFile << pair.first << ";" << pair.second << ";" << percentageStr << std::endl;

    }
    outputFile.close();
    return 1;

}