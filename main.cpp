#include <iostream>
#include <fstream> //  для работы с файлами
#include <list> // для работы с двусвязным списком (в него считываем предложения)
#include <string>
#include <map> // для словаря с подсчетом слов
#include <cctype> // для того, чтобы отделить цифры и буквы от остальных символов


int main(int argc, char** argv) {

       if (argc != 3) {
              std::cout << "Error. Wrong arguments. Use: word_count.exe <input.txt> <output.txt> \n";
              return 1;
       }

       std::string inputFilePath = argv[1];
       std::string outputFilePath = argv[2];

       std::ifstream inputFile(inputFilePath);                 // объединили 2 шага: std::ifstream inputFile;  и inputFile.open(inputPath);
       if (!inputFile.is_open()) {
              std::cout << "Error opening input file" << std::endl;
              return 1;
       }

       std::list<std::string> lines; //указываем тип данных, которые будут храниться внутри этого контейнера (двусвязного списка)
       std::string curLine;

       while (std::getline(inputFile, curLine)) {
              lines.push_back(curLine);
       }

       std::map<std::string, int> wordsCounter; //Создаем счетчик под слова в виде словаря
       int totalWordsCounter = 0;

       for (const std::string& line : lines) { //поочередно считываем строки

              std::string curWord;
              for (int i = 0; i < line.length(); i++) {// посимвольно считываем текущую строку


                     unsigned char c = line[i];

                     if (std::isalnum(c))
                            curWord += static_cast<char>(std::tolower(c));

                     else
                            if (!curWord.empty()) {

                                   wordsCounter[curWord]++;
                                   curWord = "";
                                   totalWordsCounter++;
                            }
              }

              if (!curWord.empty()) {
                     wordsCounter[curWord]++;
                     totalWordsCounter++;
              }


       }

       std::list<std::pair<std::string, int>> wordsSortedByCount(wordsCounter.begin(), wordsCounter.end());
       wordsSortedByCount.sort([](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
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

              double percentage = static_cast<double>(pair.second) / totalWordsCounter * 100.0;
              outputFile << pair.first << ";" << pair.second << ";" << percentage << std::endl;

       }



       outputFile.close();

       return 0;
}
