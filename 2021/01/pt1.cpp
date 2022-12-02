#include "..\..\clipboard.hpp"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main(){
    vector<int> nums;
    string line;
    while(getline(cin, line)){
        nums.push_back(stoi(line));
    }
    int len = nums.size() - 1;
    int count = 0;
    for(int i = 0; i < len; i++){
        count += (nums[i] < nums[i + 1]);
    }
    cout << count;
    copyToClipBoard(count);
}