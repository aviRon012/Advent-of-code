#include "..\..\clipboard.hpp"
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int intFromBinary(const vector<bool> &digits, bool inverse = false){
    int result = 0;
    for(auto d: digits){
        result *= 2;
        result += inverse ^ d;
    }
    return result;
}

bool getMajority(vector<vector<bool>> &vec, int index){
    int count = 0;
    for(auto &v: vec){
        if(v[index]) count++;
        else count--;
    }
    return count >= 0;
}

int ii;
vector<bool> maj;

int main(){
    vector<vector<bool>> matrix;
    string line;
    while(getline(cin, line)){
        vector<bool> digits;
        for(auto &c: line){
            digits.push_back(c == '1');
        }
        matrix.push_back(digits);
    }
    auto copy = matrix;
    int len = copy[0].size();
    for(ii = 0; copy.size() > 1; ii++){
        maj = {};
        for(int i = 0; i < len; i++){
            maj.push_back(getMajority(copy, i));
        }
        copy.erase(remove_if(copy.begin(), copy.end(),
                            [](const vector<bool> &vec){return vec[ii] != maj[ii];}), copy.end());
    }
    for(ii = 0; matrix.size() > 1; ii++){
        maj = {};
        for(int i = 0; i < len; i++){
            maj.push_back(!getMajority(matrix, i));
        }
        matrix.erase(remove_if(matrix.begin(), matrix.end(),
                            [](const vector<bool> &vec){return vec[ii] != maj[ii];}), matrix.end());
    }
    int oxygen = intFromBinary(copy[0]);
    int co2 = intFromBinary(matrix[0]);
    int result = oxygen * co2;
    cout << result;
    copyToClipBoard(result);
}