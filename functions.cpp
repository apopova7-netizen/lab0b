#include "word_count.h"
#include <cctype>
#include <algorithm>

void ReadLinesFromFile(std::ifstream& inputFile,std::list<std::string>& lines) {

    std::string curLine;
    while (std::getline(inputFile, curLine))
        lines.push_back(curLine);
}

void CountWords(const std::list<std::string>& lines, std::map<std::string, int>& countedWords, int& totalWordsCnt) {

    for (const std::string& line : lines) {

        std::string curWord;
        for (const char c: line) {

            if (std::isalnum(static_cast<unsigned char>(c)))
                curWord += static_cast<char>(std::tolower(c));

            else
                if (!curWord.empty()) {
                    countedWords[curWord]++;
                    curWord = "";
                    totalWordsCnt++;
                }
        }

        if (!curWord.empty()) {
            countedWords[curWord]++;
            totalWordsCnt++;
        }
    }
}

void SortWordsByCount(std::map<std::string, int>& countedWords,std::list<std::pair<std::string, int>>& wordsSortedByCount) {

    wordsSortedByCount.assign(countedWords.begin(),countedWords.end());
    wordsSortedByCount.sort([](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) { //зачем const // что могли бы указать в квадратных?
            if (a.second != b.second)
                return a.second > b.second;
         return a.first < b.first;
  });

}

int WriteResultsToFile(const std::string& outputFilePath, const std::list<std::pair<std::string, int>>& wordsSortedByCount, int totalWordsCnt) {

    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open())
        return 0;

    outputFile << "Word;Frequency;Frequency(%)" << std::endl;
    for (const std::pair<std::string, int>& pair : wordsSortedByCount) {

        double percentage = static_cast<double>(pair.second) / totalWordsCnt * 100.0;
        std::string percentageStr = std::to_string(percentage);
        std::replace(percentageStr.begin(), percentageStr.end(), '.', ',');
        outputFile << pair.first << ";" << pair.second << ";" << percentageStr << std::endl;

    }
    outputFile.close();
    return 1;

}