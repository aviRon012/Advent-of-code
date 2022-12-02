#include "..\..\clipboard.hpp"
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int intFromBinary(const vector<bool> &digits){
    int result = 0;
    for(auto d: digits){
        result *= 2;
        result += d;
    }
    return result;
}

bool getMajority(vector<vector<bool>> &vec, int index, bool minority = false){
    int count = 0;
    for(auto &v: vec){
        if(v[index]) count++;
        else count--;
    }
    return (count >= 0) ^ minority;
}

int getNumber(vector<vector<bool>> &vec, bool minority = false){
    int len = vec[0].size(), i;
    vector<bool> majority;
    auto pred = [&i, &majority](const vector<bool> &vec){return vec[i] != majority[i];};
    for(i = 0; vec.size() > 1; i++){
        majority = {};
        for(int j = 0; j < len; j++){
            majority.push_back(getMajority(vec, i, minority));
        }
        vec.erase(remove_if(vec.begin(), vec.end(), pred), vec.end());
    }
    return intFromBinary(vec[0]);
}

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
    int oxygen = getNumber(copy);
    int co2 = getNumber(matrix, true);
    int result = oxygen * co2;
    cout << result;
    copyToClipBoard(result);
}