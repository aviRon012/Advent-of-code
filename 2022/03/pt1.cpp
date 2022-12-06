#include "..\..\aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "157";

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

string handleFile(const string &path){
    auto file = openFile(path);
    int sum = 0;
    string line;
    while(getline(file, line)){
        sum += getIntersection(line.substr(0, line.length()/2), line.substr(line.length()/2));
    }
    return to_string(sum);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}