#include <iostream>
#include <fstream> //  для работы с файлами
#include <list>
#include <string>
#include <map>
#include <cctype>

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

       std::list<std::string> lines; //указываем тип данных, которые будут храниться внутри этого контейнера
       std::string curLine;

       while (std::getline(inputFile, curLine)) {
              lines.push_back(curLine);
       }

       std::map<std::string, int> wordsCounter; //Создаем счетчик под слова

       for (const std::string& line : lines) { //поочередно считываем строки

              std::string curWord = "";
              for (int i = 0; i < line.length(); i++) {// посимвольно считываем текущую строку


                     char c = line[i];

                     if (std::isalnum(c))
                            curWord += std::tolower(static_cast<unsigned char>(c)); // прикол с русскими буквами или другими символами уменьшаем символы в маленькие буквы.

                     else
                            if (!curWord.empty()) {

                                   wordsCounter[curWord]++;
                                   curWord = "";
                            }
              }

              if (!curWord.empty()) {
                     wordsCounter[curWord]++;
              }


       }

       // тут чтение и какие-то действия


       inputFile.close();






       std::ofstream outputFile(outputFilePath);
       if (!outputFile.is_open()) {
              std::cout << "Error opening output file" << std::endl;
              return 1;
       }

       // запись в файл

       outputFile.close();









       return 0;
}