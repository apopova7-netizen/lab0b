#include <iostream>
#include <fstream>
#include <list>
#include <map>
#include <cctype>
#include <string>

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
       std::string curLine;

       while (std::getline(inputFile, curLine))
              lines.push_back(curLine);

       std::map<std::string, int> wordsCounter;
       int totalWordsCnt = 0;

       for (const std::string& line : lines) { //& - чтобы без копирования, просто по ссылке (надо для тяжелых элементов)

              std::string curWord;
              for (const char c: line) {

                     if (std::isalnum(static_cast<unsigned char>(c))) // unsigned т.к. это старые функции ожидающие от 0 до 255, без отрицательных
                            curWord += static_cast<char>(std::tolower(c)); //  приводим к char т.к. вернется int

                     else
                            if (!curWord.empty()) {
                                   wordsCounter[curWord]++;
                                   curWord = "";
                                   totalWordsCnt++;
                            }
              }

              if (!curWord.empty()) {
                     wordsCounter[curWord]++;
                     totalWordsCnt++;
              }

       }

       std::list<std::pair<std::string, int>> wordsSortedByCount(wordsCounter.begin(), wordsCounter.end());

       wordsSortedByCount.sort([](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) { //зачем const // что могли бы указать в квадратных?
              if (a.second != b.second)
                     return a.second > b.second;
              return a.first < b.first;
       });

       inputFile.close();


       std::ofstream outputFile(outputFilePath);
       if (!outputFile.is_open()) {
              std::cout << "Error opening output file" << std::endl;
              return 1;
       }

       outputFile << "Word;Frequency;Frequency(%)" << std::endl;
       for (const std::pair<std::string, int>& pair : wordsSortedByCount) {

              double percentage = static_cast<double>(pair.second) / totalWordsCnt * 100.0;
              outputFile << pair.first << ";" << pair.second << ";" << percentage << std::endl;

       }

       outputFile.close();
       return 0;
}
