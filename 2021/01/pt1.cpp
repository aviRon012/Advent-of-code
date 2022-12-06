#include "../../aoc-utils.hpp"
#include <iostream>
using namespace std;
using namespace Aoc;

string expected = "7";

string handleFile(const string &path){
    auto file = openFile(path);
    vector<int> nums;
    int num;
    while(file >> num) nums.push_back(num);
    int count = 0;
    for(int i = 1; i < nums.size(); i++) count += (nums[i] > nums[i - 1]);
    return to_string(count);
}

int main()
{
    string result = handleFile("example.txt");
    printResult(result, expected);
    result = handleFile("input.txt");
    cout << result;
    clipboard(result);
}