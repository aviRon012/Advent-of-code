#include "..\..\aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 70;

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

int handleFile(const string &path){
    auto lines = FileToLines(path);
    int sum = 0;
    for(int i = 0; i < lines.size(); i += 3){
        sum += getIntersection(lines[i], lines[i + 1], lines[i + 2]);
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