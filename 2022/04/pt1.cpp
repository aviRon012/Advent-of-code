#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 2;

bool isContained(int x0, int x1, int y0, int y1)
{
    if(x0 <= y0 && y1 <= x1) return true;
    if(y0 <= x0 && x1 <= y1) return true;
    return false;
}

int handleFile(const string &path)
{
    auto lines = FileToLines(path);
    int count = 0, pos;
    for(auto &line: lines){
        auto nums = SplitByDelimiters(line, {",", "-"});
        count += isContained(stoi(nums[0]), stoi(nums[1]), stoi(nums[2]), stoi(nums[3]));
    }
    return count;
}

int main()
{
    int result;
    result = handleFile("example.txt");
    cout << result;
    if(result == expected){
        cout << " \33[32m[OK]\33[39m\n";
    }else{
        cout << " != " << expected << " \33[31m[FAIL]\33[39m\n";
    }
    result = handleFile("input.txt");
    cout << result;
    clipboard(to_string(result));
}