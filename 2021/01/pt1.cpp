#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "7";

string handleFile(const string &path){
    auto file = openFile(path);
    int num, prev, count = 0;
    file >> prev;
    while(file >> num){count += (num > prev); prev = num;}
    return to_string(count);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}