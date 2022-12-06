#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

string expected = "168";

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

string handleFile(const string &path){
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
        if(val1 >= val2 && val2 <= val3) return to_string(val2);
        if (val1 < val2) high = mid;
        else low = mid;
    }
    return "";
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}