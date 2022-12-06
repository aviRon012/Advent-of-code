#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

int expected = 168;

int cost(int pos, int guess){
    int diff = pos - guess;
    if(diff < 0) diff = -diff;
    return diff * (diff + 1) / 2;
}

int totalCost(vector<int> &nums, int guess){
    int fule = 0;
    for(auto &num: nums) fule += cost(num, guess);
    return fule;
}

int handleFile(const string &path){
    auto file = openFile(path);
    istringstream line;
    lineStreamNoPunctuation(file, line);
    vector<int> nums;
    int num;
    while(line >> num) nums.push_back(num);
    int low = *min_element(ALL(nums)), high = *max_element(ALL(nums)), mid;
    while(low < high){
        mid = (low + high)/2;
        int val1 = totalCost(nums, mid - 1), val2 = totalCost(nums, mid), val3 = totalCost(nums, mid + 1);
        if(val1 >= val2 && val2 <= val3) return val2;
        if (val1 < val2) high = mid;
        else low = mid;
    }
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