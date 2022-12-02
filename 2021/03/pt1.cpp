#include "..\..\clipboard.hpp"
#include <string.h>
#include <iostream>
#include <vector>
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
    return count > 0;
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
    int len = matrix[0].size();
    vector<bool> majorityVec;
    for(int i = 0; i < len; i++){
        majorityVec.push_back(getMajority(matrix, i));
    }
    int gamma = intFromBinary(majorityVec);
    int epsilon = intFromBinary(majorityVec, true);
    int result = gamma * epsilon;
    cout << result;
    copyToClipBoard(result);
}