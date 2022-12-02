#include "..\..\clipboard.hpp"
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    int len = lines[0].length(), i;
    string majority;
    auto pred = [&i, &majority](string &line){return (line[i]) != majority[i];};
    for(i = 0; lines.size() > 1; i++){
        majority = {};
        for(int j = 0; j < len; j++){
            majority.push_back(getMajority(lines, i, minority));
        }
        lines.erase(remove_if(lines.begin(), lines.end(), pred), lines.end());
    }
    return intFromBinary(lines[0]);
}

int main(){
    vector<string> lines;
    string line;
    while(getline(cin, line)){
        lines.push_back(line);
    }
    auto copy = lines;
    int oxygen = getNumber(lines);
    int co2 = getNumber(copy, true);
    int result = oxygen * co2;
    cout << result;
    copyToClipBoard(result);
}