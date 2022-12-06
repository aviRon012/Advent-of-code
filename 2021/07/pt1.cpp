#include "../../aoc-utils.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
using namespace Aoc;

int expected = 37;

int handleFile(const string &path){
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
    return fule;
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