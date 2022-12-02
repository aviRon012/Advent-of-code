#include "..\..\clipboard.hpp"
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

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

int main(){
    vector<string> lines;
    string line;
    while(getline(cin, line)){
        lines.push_back(line);
    }
    int len = lines[0].length();
    string majorityVec;
    for(int i = 0; i < len; i++){
        majorityVec.push_back(getMajority(lines, i));
    }
    int gamma = intFromBinary(majorityVec);
    int epsilon = intFromBinary(majorityVec, true);
    int result = gamma * epsilon;
    cout << result;
    copyToClipBoard(result);
}