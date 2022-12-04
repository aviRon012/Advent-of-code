#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

int expected = 230;

int intFromBinary(string str){
    int result = 0;
    for(auto d: str){
        result *= 2;
        result += (d =='1');
    }
    return result;
}

char getMajority(vector<string> &lines, int index, bool minority = false){
    int count = 0;
    for(auto &line: lines){
        if(line[index] == '1') count++;
        else count--;
    }
    return (count >= 0) ^ minority ? '1' : '0';
}

int getNumber(vector<string> &lines, bool minority = false){
    int i;
    string majority;
    auto pred = [&i, &majority](string &line){return (line[i]) != majority[i];};
    for(i = 0; lines.size() > 1; i++){
        majority = {};
        for(int j = 0; j < lines[0].size(); j++){
            majority.push_back(getMajority(lines, i, minority));
        }
        lines.erase(remove_if(ALL(lines), pred), lines.end());
    }
    return intFromBinary(lines[0]);
}

int handleFile(const string &path){
    auto lines = fileToLines(path);
    auto copy = lines;
    int oxygen = getNumber(lines);
    int co2 = getNumber(copy, true);
    return oxygen * co2;
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