#include "word_count.h"

void SortWordsByCount(const std::map<std::string, int>& countedWords,  std::list<std::pair<std::string, int>>& wordsSortedByCount) {

    wordsSortedByCount.assign(countedWords.begin(),countedWords.end());
    wordsSortedByCount.sort([](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
            if (a.second != b.second)
                return a.second > b.second;
         return a.first < b.first;
  });

}
