#pragma once

#ifndef WORD_COUNT_WORD_COUNT_H
#define WORD_COUNT_WORD_COUNT_H

#include <fstream>
#include <list>
#include <map>
#include <string>

void ReadLinesFromFile(std::ifstream&,  std::list<std::string>&);
void CountWords(const std::list<std::string>&,  std::map<std::string, int>&,  int&);
void SortWordsByCount(std::map<std::string, int>&,  std::list<std::pair<std::string, int>>&);
int WriteResultsToFile(const std::string&, const  std::list<std::pair<std::string, int>>&, int);

#endif //WORD_COUNT_WORD_COUNT_H


