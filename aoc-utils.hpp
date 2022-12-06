#ifndef AOC_UTILS_HPP
#define AOC_UTILS_HPP
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#define ALL(x) (x).begin(), (x).end()

namespace Aoc{

void clipboard(const std::string &str);

std::fstream openFile(const std::string &path);

void printResult(std::string result, std::string expected);

std::istringstream &lineStream(std::fstream &file, std::istringstream &line);

std::istringstream &lineStreamNoPunctuation(std::fstream &file, std::istringstream &line);

std::vector<std::string> fileToLines(const std::string &path);

std::vector<std::vector<std::string>> linesToBlocks(const std::vector<std::string> &lines);

std::vector<std::string> splitByDelimiter(std::string str, const std::string &delimiter);

std::vector<std::string> splitByDelimiters(std::string str, const std::vector<std::string> &delimiters);
}; //Aoc
#endif //AOC_UTILS_HPP