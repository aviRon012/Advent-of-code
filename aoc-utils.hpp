#ifndef AOC_UTILS_HPP
#define AOC_UTILS_HPP
#include <string>
#include <vector>

#define ALL(x) (x).begin(), (x).end()

namespace Aoc{

void clipboard(const std::string &str);

std::vector<std::string> FileToLines(const std::string &path);

std::vector<std::vector<std::string>> LinesToBlocks(const std::vector<std::string> &lines);

std::vector<std::vector<std::string>> LinesToElements(const std::vector<std::string> &lines);

}; //Aoc
#endif //AOC_UTILS_HPP