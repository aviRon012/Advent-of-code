#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

int expected = 198;

int intFromBinary(string &line, bool inverse = false){
    int result = 0;
    for(auto d: line){
        result *= 2;
        result += inverse ^ (d == '1');
    }
    return result;
}

char getMajority(vector<string> &lines, int index){
    int count = 0;
    for(auto &line: lines){
        if(line[index] == '1') count++;
        else count--;
    }
    return (count > 0) ? '1' : '0';
}

int handleFile(const string &path){
    auto lines = FileToLines(path);
    string majorityBits;
    for(int i = 0; i < lines[0].size(); i++){
        majorityBits.push_back(getMajority(lines, i));
    }
    int gamma = intFromBinary(majorityBits);
    int epsilon = intFromBinary(majorityBits, true);
    return gamma * epsilon;
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