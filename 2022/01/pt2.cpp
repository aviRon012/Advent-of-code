#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

int expected = 45000;

int handleFile(const string &path){
    auto lines = fileToLines(path);
    auto blocks = linesToBlocks(lines);
    vector<int> sums;
    for(auto &block: blocks){
        int sum = 0;
        for(auto &line: block) sum += stoi(line);
        sums.push_back(sum);
    }
    sort(ALL(sums), greater<int>());
    return sums[0] + sums[1] + sums[2];
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