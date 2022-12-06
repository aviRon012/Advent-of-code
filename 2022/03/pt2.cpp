#include "..\..\aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "70";

int getIntersection(string str1, string str2, string str3){
    for(char c = 'a'; c <= 'z'; c++){
        if(str1.find(c) != string::npos &&
           str2.find(c) != string::npos &&
           str3.find(c) != string::npos)
            return c - 'a' + 1;
    }
    for(char c = 'A'; c <= 'Z'; c++){
        if(str1.find(c) != string::npos &&
           str2.find(c) != string::npos &&
           str3.find(c) != string::npos)
            return c - 'A' + 27;
    }
    return -1;
}

string handleFile(const string &path){
    auto file = openFile(path);
    int sum = 0;
    string line1, line2, line3;
    while(getline(file, line1) && getline(file, line2) && getline(file, line3)){
        sum += getIntersection(line1, line2, line3);
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