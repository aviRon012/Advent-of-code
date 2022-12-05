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
    auto file = openFile(path);
    int sum = 0;
    string line1, line2, line3;
    while(getline(file, line1) && getline(file, line2) && getline(file, line3)){
        sum += getIntersection(line1, line2, line3);
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