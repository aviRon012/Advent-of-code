#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

string expected = "37";

string handleFile(const string &path){
    auto file = openFile(path);
    istringstream line;
    lineStreamNoPunctuation(file, line);
    vector<int> nums;
    int num;
    while(line >> num) nums.push_back(num);
    int half = nums.size()/2;
    nth_element(nums.begin(), nums.begin() + half, nums.end());
    int fule = 0, median = nums[half];
    for(int i = 0; i < half; i++) fule += (median - nums[i]);
    for(int i = half; i < nums.size(); i++) fule += (nums[i] - median);
    return to_string(fule);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}