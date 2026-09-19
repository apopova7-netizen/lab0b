#pragma once

#include <fstream>
#include <list>
#include <map>
#include <string>
#include <utility>

void ReadLinesFromFile(std::ifstream&,  std::list<std::string>&);
void CountWords(const std::list<std::string>&,  std::map<std::string, int>&,  int&);
void SortWordsByCount(const std::map<std::string, int>&,  std::list<std::pair<std::string, int>>&);
int WriteResultsToFile(const std::string&, const  std::list<std::pair<std::string, int>>&, int);




