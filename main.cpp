#include "word_count.h"
#include <iostream>

int main(int argc, char **argv) {

       if (argc != 3) {
              std::cout << "Error. Wrong arguments. Use: word_count.exe <input.txt> <output.txt> \n";
              return 1;
       }

       std::string inputFilePath = argv[1];
       std::string outputFilePath = argv[2];

       std::ifstream inputFile(inputFilePath);
       if (!inputFile.is_open()) {
              std::cout << "Error opening input file" << std::endl;
              return 1;
       }

       std::list<std::string> lines;
       ReadLinesFromFile(inputFile, lines);

       int totalWordsCnt = 0;
       std::map<std::string, int> countedWords;
       CountWords(lines,countedWords,totalWordsCnt);
       if (totalWordsCnt == 0) {
              std::cout << "The input file does not contain any words." << std::endl;
              inputFile.close();
              return 0;
       }

       std::list<std::pair<std::string, int>> wordsSortedByCount;
       SortWordsByCount(countedWords,wordsSortedByCount);

       inputFile.close();

       if (!WriteResultsToFile(outputFilePath,wordsSortedByCount, totalWordsCnt)) {
              std::cout << "Error opening output file" << std::endl;
              return 1;
       }

       return 0;
}