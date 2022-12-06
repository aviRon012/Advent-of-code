#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

int expected = 7;

bool isUniqe(string &str)
{
    sort(ALL(str));
    for(int j = 1; j < 4; j++) if(str[j] != str[j-1]) return false;
    return true;
}

int handleFile(const string &path){
    auto file = openFile(path);
    string line;
    getline(file, line);
    for(int i = 4; i < line.size(); i++){
        string sub = line.substr(i-4, i);
        if(isUniqe(sub)) return i;
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