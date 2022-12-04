#include "..\..\aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 157;

int getIntersection(string str1, string str2){
    for(char c = 'a';  c <= 'z'; c++){
        if(str1.find(c) != string::npos &&
           str2.find(c) != string::npos)
            return c - 'a' + 1;
    }
    for(char c = 'A';  c <= 'Z'; c++){
        if(str1.find(c) != string::npos &&
           str2.find(c) != string::npos)
            return c - 'A' + 27;
    }
    return -1;
}

int handleFile(const string &path){
    auto lines = fileToLines(path);
    int sum = 0;
    for(auto &line: lines){
        sum += getIntersection(line.substr(0, line.length()/2), line.substr(line.length()/2));
    }
    return sum;
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