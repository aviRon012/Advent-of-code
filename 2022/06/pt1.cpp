#include "../../aoc-utils.hpp"
#include <iostream>
#include <set>
using namespace std;
using namespace Aoc;

string expected = "7";

string handleFile(const string &path){
    auto file = openFile(path);
    string line;
    getline(file, line);
    int buffLen = 4;
    for(int i = buffLen; i < line.size(); i++){
        string buff = line.substr(i-buffLen, buffLen);
        set<char> chars{ALL(buff)};
        if (chars.size() == buffLen) return to_string(i);
    }
    return "";
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}