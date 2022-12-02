#include "..\..\clipboard.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(){
    vector<int> nums;
    vector<int> sums;
    string line;
    while(getline(cin, line)){
        nums.push_back(stoi(line));
    }
    int len = nums.size() - 2;
    for(int i = 0; i < len; i++){
        sums.push_back(nums[i] + nums[i + 1] + nums[i + 2]);
    }
    len--;
    int count = 0;
    for(int i = 0; i < len; i++){
        count += (sums[i] < sums[i + 1]);
    }
    cout << count;
    copyToClipBoard(count);
}