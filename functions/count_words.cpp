#include "word_count.h"
#include <cctype>

void CountWords(const std::list<std::string>& lines, std::map<std::string, int>& countedWords, int& totalWordsCnt) {

    for (const std::string& line : lines) {

        std::string curWord;
        for (const char c: line) {

            if (std::isalnum(static_cast<unsigned char>(c)))
                curWord += static_cast<char>(std::tolower(static_cast<unsigned char>(c)));

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
