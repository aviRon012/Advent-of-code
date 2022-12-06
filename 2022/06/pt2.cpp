#include "../../aoc-utils.hpp"
#include <iostream>
#include <set>
using namespace std;
using namespace Aoc;

int expected = 19;

int handleFile(const string &path){
    auto file = openFile(path);
    string line;
    getline(file, line);
    int buffLen = 14;
    for(int i = buffLen; i < line.size(); i++){
        string buff = line.substr(i-buffLen, buffLen);
        set<char> chars{ALL(buff)};
        if (chars.size() == buffLen) return i;
    }
    return 0;
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