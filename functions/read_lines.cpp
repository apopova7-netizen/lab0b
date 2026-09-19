#include "word_count.h"

void ReadLinesFromFile(std::ifstream& inputFile,  std::list<std::string>& lines) {

    std::string curLine;
    while (std::getline(inputFile, curLine))
        lines.push_back(curLine);
}
